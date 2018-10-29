#include "qAnalitikaArtikliwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"
#include "xx.h"

QAnalitikaArtikliWidget::QAnalitikaArtikliWidget(QWidget *parent)
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
    lista("%");
    lista_detail("-1");
    ui.tableView_2->hide();
}

QAnalitikaArtikliWidget::~QAnalitikaArtikliWidget()
{

}


void QAnalitikaArtikliWidget::pressEscape()
{
    emit closeW();
}


void QAnalitikaArtikliWidget::lista(const QString& nameSearch)
{
    QLocale loc;
    int r = 0;
    int c = 4;


    int fieldNo[4];
    QString country[4];
    int colWidth[] = {0, 120, 250, 80, 200};
    QString colName[7] = {"id","sifra", "artikal", "edm", "proizvoditel"};
    QString temp ="";

    temp =
    " select distinct artikal_id ,artikli.sifra, artikli.artikal, artikli.edm "
    " from magacin "
    " left join artikli on  magacin.artikal_id = artikli.id "
    " where artikli.artikal like '%" + nameSearch + "%' or artikli.sifra like '%" + nameSearch + "%' order by artikal_id ";

    QSqlQuery query(temp);
    QSqlError err = query.lastError();
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));

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

void QAnalitikaArtikliWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QAnalitikaArtikliWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QAnalitikaArtikliWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}


void QAnalitikaArtikliWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sAnalitikaArtikliToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
	}

}

void QAnalitikaArtikliWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QAnalitikaArtikliWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 1) ? model->item(i, 1)->text():"";
    m_selectedTextName2 = model->item(i, 2) ? model->item(i, 2)->text():"";

    m_selectedTextNameSaldo = model->item(i, 5) ? model->item(i, 5)->text():"";
    lista_detail(m_selectedText);
}

void QAnalitikaArtikliWidget::lista_detail(const QString& nameSearch)
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
    int colWidth[] = {120, 100, 120, 200, 80, 80, 80, 80, 80};
    QString temp = 
        " SELECT datum, dokumenti.dok_id, datum, naziv, dokumenti.dok_tip, ikol, 0, magacin.nab_cena, magacin.prod_cena, tip_dokument "
        " FROM (dokumenti "
        " LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND "
        " dokumenti.dok_tip = magacin.dok_tip )"
        " LEFT JOIN komintenti ON dokumenti.komintent_id = komintenti.id "
        " WHERE  magacin.artikal_id = " + m_selectedText + 
        " ORDER BY datum, dokumenti.id	";

    QSqlQuery query(temp);

    model2 = new QStandardItemModel(r,c);
    nameSearch != "-1" ? model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Датум на\nкнижење")) : model2->setHeaderData( 0, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Док.Ид.\n")) : model2->setHeaderData( 1, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум на\nдокумент")) : model2->setHeaderData( 2, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Назив на \nкоминтент")) : model2->setHeaderData( 3, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Влез\n")) : model2->setHeaderData( 4, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Излез\n")) : model2->setHeaderData( 5, Qt::Horizontal, trUtf8(""));
    nameSearch != "-1" ? model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Состојба\n")) : model2->setHeaderData( 6, Qt::Horizontal, trUtf8(""));
	nameSearch != "-1" ? model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Наб.цена\nсо ДДВ")) : model2->setHeaderData( 7, Qt::Horizontal, trUtf8(""));
	nameSearch != "-1" ? model2->setHeaderData( 8, Qt::Horizontal, trUtf8("Прод.цена\n со ДДВ")) : model2->setHeaderData( 8, Qt::Horizontal, trUtf8(""));
    
	ui.tableView_2->setModel(model2);
    header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
    ui.tableView_2->setHorizontalHeader(header2);
    header2->show();
    int row = 0;
    float saldo = 0.f;

    while (query.next()) 
    {
        if((query.value(4).toInt() == 40)||(query.value(4).toInt() == 150))
		{
			continue;
		}
		
		if((query.value(4).toInt() == 48)&&(query.value(9).toString() == trUtf8("сторно фискална сметка")))
		{
			continue;
		}

		for (int i = 0; i < c; i++)
        {
            QStandardItem *item = NULL;
            QString temp = query.value(i).toString();
            if ((i == 0) || (i == 2))
            {
                temp = temp.left(10);
            }

            if (i == 1) // vnes
            {
                QString strTip = "";
                switch (query.value(4).toInt())
                {
                case 20: strTip = trUtf8("ПРИЕМН."); break;
                case 21: strTip = trUtf8("ИЗЈАВА"); break;
				case 25: strTip = trUtf8("ПОВРАТ."); break;
				case 60: strTip = trUtf8("ИСПРАТ."); break;
                case 48: strTip = trUtf8("СМЕТКА"); break;
                }

                QString temp = strTip + " (" + query.value(1).toString() + ") ";
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignLeft);
            }

            else if (i == 4) // vnes
            {
                QString temp = query.value(5).toString();
                if (query.value(4).toInt() < 39)
                {
                    temp =  loc.toString(temp.toFloat(), 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
                else if(query.value(4).toInt() > 39)
                {
                    temp = "0";
                    temp =  loc.toString(temp.toFloat(), 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
            }
            else if (i == 5)
            {
                QString temp = query.value(5).toString();
                if (query.value(4).toInt() < 39)
                {
                    temp = "0";
                    temp =  loc.toString(temp.toFloat(), 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
                else if(query.value(4).toInt() > 39)
                {
                    temp =  loc.toString(temp.toFloat(), 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
            }
            else if (i == 6)
            {
                QString temp = query.value(5).toString();
                if (query.value(4).toInt() < 39)
                {
                    saldo += temp.toFloat();
                    temp =  loc.toString(saldo, 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
                else if(query.value(4).toInt() > 39)
                {
                    saldo -= temp.toFloat();
                    temp =  loc.toString(saldo, 'f', 2);
                    item = new QStandardItem(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
            }
			else if (i == 7)
			{
				QString temp = loc.toString(query.value(7).toFloat(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 8)
			{
				QString temp = loc.toString(query.value(8).toFloat(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}

			else
            {
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignLeft);
            }
            if (item)
            {
                item->setEditable(false);
                ui.tableView_2->setRowHeight(row, 18);
                ui.tableView_2->setColumnWidth(i, colWidth[i]);
                model2->setItem(row, i, item);
            }
        }
        row++;
    } 
    ui.tableView_2->show();
}
