#include "qAnalitikaKomintentiwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"

QAnalitikaKomintentiWidget::QAnalitikaKomintentiWidget(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,m_selectedText("") 
    ,m_selectedTextName("")
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
    lista("%");
	lista_detail("-1");
    ui.tableView_2->hide();
}


QAnalitikaKomintentiWidget::~QAnalitikaKomintentiWidget()
{

}


void QAnalitikaKomintentiWidget::pressEscape()
{
    emit closeW();
}


void QAnalitikaKomintentiWidget::lista(const QString& nameSearch)
{
    QLocale loc;
    int r = 0;
    int c = 3;
    int fieldNo[3];
    QString country[3];
    int colWidth[] = {0, 120, 650};
    QString colName[7] = {"id", "artikal", "edm", "proizvoditel", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};

    QString temp;
    temp =
        " SELECT komintent_id, sifra, naziv "
        " FROM dokumenti "
        " LEFT JOIN komintenti ON dokumenti.komintent_id = komintenti.id "
        " GROUP BY komintent_id, naziv, sifra  "
        " HAVING (komintenti.naziv LIKE '%" + nameSearch + "%' or komintenti.sifra LIKE '%" + nameSearch + "%') ";
    
    QSqlQuery query(temp);
    QSqlError err = query.lastError();
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Коминтент"));
    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);

    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
	CHelperClass chc(this);
	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkSaldo = 0.f;
	setUpdatesEnabled(false);
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            QString temp = query.value(i).toString();
            QStandardItem *item = NULL; 
            item = new QStandardItem(temp);
            item->setTextAlignment(Qt::AlignLeft);
            item->setEditable(false);
            ui.tableView->setRowHeight(row, 18);
            ui.tableView->setColumnWidth(i, colWidth[i]);
            model->setItem(row, i, item);
        }
		row++;
    } 
	setUpdatesEnabled(true);

    QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
    this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();
}

void QAnalitikaKomintentiWidget::lista_detail(const QString& nameSearch)
{
	QLocale loc;
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}

	int r = 0;
	int c = 9;
	int fieldNo[9];
	QString country[11];
	int colWidth[] = {50, 180, 120, 200, 80, 80, 80, 80, 80};
	
	QString temp = 

    " SELECT dokumenti.dok_id, dokumenti.dok_tip, datum, artikal, ikol, icena, magacin.rabat, prod_cena, nab_cena "
	" FROM (dokumenti "
	" LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND "
    " dokumenti.dok_tip = magacin.dok_tip) "
	" LEFT JOIN artikli ON magacin.artikal_id = artikli.id "
	" WHERE dokumenti.komintent_id = " + m_selectedText + 
	" ORDER BY datum, dokumenti.id";

	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Док.Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Вид на документ"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Кол."));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена со ДДВ"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
    model2->setHeaderData( 8, Qt::Horizontal, trUtf8("Салдо"));
    ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
    float saldo = 0;
	while (query.next()) 
	{
		float mkol = 0;
        float mcena = 0;
        float mrabat = 0;
        float msaldo = 0;
		float m_prod_cena = 0;
		float m_nab_cena = 0;

		int znak = 1;
        for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
            
            if (i == 1)
			{
				if (temp == "20")
				{
					temp = trUtf8("ПРИЕМНИЦА");
                    znak = -1;
				}
				else if(temp == "21")
				{
					temp = trUtf8("ИЗЈАВА");
                    znak = -1;
				}
				else if(temp == "25")
				{
					temp = trUtf8("ПОВРАТНИЦА");
					znak = -1;
				}
				else if(temp == "40")
                {
                    temp = trUtf8("ИСПРАТНИЦА");
                    znak = 1;
                }
                else if(temp == "45")
                {
                    temp = trUtf8("СМЕТКА");
                    znak = 1;
                }

                else
				{
					temp = "";
				}

				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			else if (i == 4) // kol
			{
				
                mkol = temp.toFloat();
                item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
            else if (i == 5) // cena
            {
				if (znak < 0)
				{
					mcena = query.value(8).toFloat(); // nabavna
				} 
				else
				{
					mcena = query.value(7).toFloat(); // prodazna
				}
                item = new QStandardItem(loc.toString(mcena, 'f', 2));
                item->setTextAlignment(Qt::AlignRight);
            }
            else if (i == 6) // rabat
            {
                mrabat = temp.toFloat();
                item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
                item->setTextAlignment(Qt::AlignRight);
            }
            else if (i == 7) // saldo
            {
                m_prod_cena = temp.toFloat();
				msaldo = mkol * mcena *(100 - mrabat)/100;
                item = new QStandardItem(loc.toString(msaldo, 'f', 2));
                item->setTextAlignment(Qt::AlignRight);
            }
            else if (i == 8) // saldo
            {
                m_nab_cena = temp.toFloat();
				QBrush newBrush;
                saldo += znak * msaldo;
                item = new QStandardItem(loc.toString(saldo, 'f', 2));
                if (saldo < 0)
                {
                    newBrush.setColor(Qt::darkRed);
                    item->setForeground(newBrush);
                }
                else if (saldo == 0)
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

            else 
			{
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}

			item->setEditable(false);
			ui.tableView_2->setRowHeight(row, 18);
			ui.tableView_2->setColumnWidth(i, colWidth[i]);
			model2->setItem(row, i, item);
		}
		row++;
	} 
// 	ui.lineEdit_6->setText(loc.toString(sumaDDV, 'f', 2));
// 	CHelperClass chc(this);
// 	QString tip = "40";
// 	chc.getFakturaPlatenIznos(m_selectedText, tip);
// 	ui.lineEdit_8->setText(loc.toString(chc.getPlatenIznos(), 'f', 2));
// 	ui.lineEdit_9->setText(loc.toString(sumaDDV - chc.getPlatenIznos(), 'f', 2));

	ui.tableView_2->show();
}
void QAnalitikaKomintentiWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QAnalitikaKomintentiWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QAnalitikaKomintentiWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}


void QAnalitikaKomintentiWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sAnalitikaKomintentiToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
	}

}

void QAnalitikaKomintentiWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QAnalitikaKomintentiWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 2) ? model->item(i, 2)->text():"";
    m_selectedTextNameSaldo = model->item(i, 5) ? model->item(i, 5)->text():"";
	lista_detail(m_selectedText);
}

