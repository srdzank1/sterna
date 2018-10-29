#include "qlagerwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"
#include <QClipboard>
#include "xx.h"


QLagerWidget::QLagerWidget(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,m_selectedText("") 
    ,m_selectedTextName("")
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(copyToClipBoard()));
    lista("%");
}

QLagerWidget::~QLagerWidget()
{

}


void QLagerWidget::pressEscape()
{
    emit closeW();
}



void QLagerWidget::lista(const QString& nameSearch)
{
    QLocale loc;
    int r = 0;
    int c = 12;
    int fieldNo[12];
    QString country[12];
    int colWidth[] = {0, 80, 180, 80, 100, 100, 70, 70, 100, 0, 0, 100};
    QString colName[9] = {"id", "sifra", "artikal", "edm", "ncena", "pcena", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};
	//magacin.dok_tip < 39 and
    QString temp = 
		"select artikli.ID, artikli.sifra, artikli.artikal, artikli.edm , max(nab_cena), max(prod_cena), 0,0,0,0, komintent_id "
        "from artikli "
		"left join magacin on  magacin.artikal_id = artikli.ID "
		"where  (magacin.dok_tip <> 150) and (artikli.artikal like '%" + nameSearch + 
		"%' or artikli.sifra like '" + nameSearch +"%') "
		"group by artikli.ID, artikli.sifra, artikli.artikal, artikli.edm, komintent_id order by artikli.ID";
	QSqlQuery query(temp);
    QSqlError err = query.lastError(); 
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("ID\n"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра\n"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал\n"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Един.\nмера"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Набавна Цена\nсо ДДВ"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Продажна Цена\nсо ДДВ"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Влезна\nКоличина"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Излезна\nКоличина"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Салдо\nКоличина"));
//	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Салдо Износ\nсо ДДВ"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("Ид на\nКоминтент\n"));
	model->setHeaderData( 11, Qt::Horizontal, trUtf8("Шифра на\nКоминтент\n"));
	ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);

    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
	CHelperClass chc(this);
	chc.createSaldoArtikliOdlivMapAll();
	chc.createSaldoProizvodiPrilivMapAll();

	chc.createListaKomintentiByID();

	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkIzlezKolS = 0.f;
	float vkSaldo = 0.f;
	float vkSaldoNab = 0.f;
	float vkTotalSaldoNab = 0.f;
	float vkNabavenIznosDDV = 0.f;
	float vkProdazenIznosDDV = 0.f;
	setUpdatesEnabled(false);
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            QString temp = query.value(i).toString();
            QStandardItem *item = NULL; 
			if (i == 6)
			{
				QString keyT = query.value(0).toString() + "Key" + query.value(10).toString();
				vkVlezKol = chc.getLagerListaAll(keyT , (QString)"PRILIV");
				temp =  loc.toString(vkVlezKol ,'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 7)
			{
// 				//odliv po smetki
// 				QString keyTS = query.value(0).toString() + "Key" + "0";
// 				vkIzlezKolS = chc.getLagerListaAll(keyTS , (QString)"ODLIV");

				QString keyT = query.value(0).toString() + "Key" + query.value(10).toString();
				vkIzlezKol = chc.getLagerListaAll(keyT , (QString)"ODLIV");
				temp =  loc.toString(vkIzlezKol + vkIzlezKolS ,'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 8)
			{
				vkSaldo = vkVlezKol - vkIzlezKol - vkIzlezKolS;
				temp =  loc.toString(vkSaldo ,'f',2);
				item = new QStandardItem(temp);
				QBrush newBrush;
				if (vkSaldo < 0)
				{
					newBrush.setColor(Qt::darkRed);
					item->setForeground(newBrush);
				}
				else if (vkSaldo == 0)
				{
					newBrush.setColor(Qt::black);
					item->setForeground(newBrush);
				}
				else
				{
					newBrush.setColor(Qt::darkGreen);
					item->setForeground(newBrush);
				}
				item->setTextAlignment(Qt::AlignRight);
			}

			else if (i == 10)
			{
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}

			else if (i == 11)
			{
				temp = query.value(10).toString();
				temp = chc.getSifraKomintentByID(temp);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}

			else
            {
                item = new QStandardItem(temp);
                if ((i > 3)&&(i < 6))
                {
                    QString temp =  item->text();
                    temp = loc.toString((temp.toFloat()) ,'f', 2);
                    item->setText(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
                else
                {
                    item->setTextAlignment(Qt::AlignLeft);
                }
            }
			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			model->setItem(row, i, item);
		}
		vkNabavenIznosDDV += query.value(4).toFloat() * vkSaldo;
		vkProdazenIznosDDV += query.value(5).toFloat() * vkSaldo;
		row++;
	} 
	setUpdatesEnabled(true);
	temp =  loc.toString(vkTotalSaldoNab ,'f', 2);
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	
	ui.lineEdit_2->setText(loc.toString(vkNabavenIznosDDV, 'f', 2));
	ui.lineEdit_3->setText(loc.toString(vkProdazenIznosDDV, 'f', 2));
	ui.tableView->show();
}

void QLagerWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QLagerWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QLagerWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}


void QLagerWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
		ui.tableView->selectRow(0);
    }
    else if (ui.tableView->hasFocus())
	{
		emit sLagerToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo, m_selectedKomintentId, m_selectedProdCena, m_selectedNabCena);	
	}

}

void QLagerWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QLagerWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 2) ? model->item(i, 2)->text():"";
    m_selectedTextNameSaldo = model->item(i, 8) ? model->item(i, 8)->text():"";
	m_selectedKomintentId = model->item(i, 10) ? model->item(i, 10)->text():"";
	m_selectedProdCena = model->item(i, 5) ? model->item(i, 5)->text():"";
	m_selectedNabCena = model->item(i, 4) ? model->item(i, 4)->text():"";
}

void QLagerWidget::copyToClipBoard()
{
    QString m_copyedString = "";
    setUpdatesEnabled(false);	
    for(int c_row = 0; c_row < model->rowCount(); c_row++)
    {
        QStringList c;
        c.clear();
        for(int c_col = 0; c_col < model->columnCount(); c_col++)
        {
            QString temp = model->item(c_row,c_col)->text().trimmed();
            if(temp.contains('\n'))
            {
                int stop = 0;
            }
                c << temp;
        }
        m_copyedString = m_copyedString + c.join("\t");
        c.clear();
        m_copyedString = m_copyedString + "\n";
    }
    setUpdatesEnabled(true);

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_copyedString);
}


void QLagerWidget::refresh()
{
	lista(ui.lineEdit->text() + "%");
}
