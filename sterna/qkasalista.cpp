#include "qKasalista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>



QKasaLista::QKasaLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_row(0)
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
//	ui.tabWidget->setGeometry(10, 10, deskRect.width() - 300, deskRect.height() - 200);
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));

    lista("%%%");
    m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
    lista_detail(m_selectedText);
	//ui.tableView->setSortingEnabled(true); 
    ui.tableView->setFocus();
}

QKasaLista::~QKasaLista()
{

}

void QKasaLista::setRow(int mrow)
{
	ui.tableView->selectRow(mrow);
}

int QKasaLista::getRow()
{
	return m_row;
}

void QKasaLista::pressEscape()
{
    emit closeW();
}

void QKasaLista::pressReturn()
{
	if (ui.tableView->hasFocus())
	{
		emit sFakturiToIzvod(ui.lineEdit_6->text(), ui.lineEdit_8->text(), ui.lineEdit_9->text(), m_selectedText);	
	}
}
void QKasaLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 6;
    int fieldNo[6];
    QString country[6];
    int colWidth[] = {0, 80, 80, 200, 200, 200};
    QString colName[] = {"id", "dok_id", "datum", "naziv", "adresa", "grad"};
    QString temp = 
        "select dokumenti.id, dok_id, datum, komintenti.naziv, komintenti.adresa, komintenti.grad "
        "from dokumenti "
        "left join komintenti on dokumenti.komintent_id = komintenti.id "
        "where dok_tip = 45 order by dok_id desc "
        ;
    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Фактура бр."));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Град"));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
	CHelperClass chc(this);
	QString tip = "45";
	chc.createStatusMap(tip);    
	while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = query.record().indexOf(colName[i]);
            QStandardItem *item = new QStandardItem(query.value(fieldNo[i]).toString());
// 			if ((i == 1))
// 			{
// 				chc.fakturaStatus(item, tip);
// 			}
			if ((i == 2))
			{

				item = new QStandardItem(query.value(fieldNo[i]).toString().left(10));
			}
			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			item->setEditable(false);
			model->setItem(row, i, item);
        }
        row++;
    } 
    QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();
}
void QKasaLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
	m_row = modelX.row();;
    m_selectedText = model->item(i, 1) ? model->item(i, 1)->text():"";
    ui.lineEdit_2->setText(model->item(i, 1)->text());
    ui.lineEdit->setText(model->item(i, 2)->text().left(10));
    ui.lineEdit_3->setText(model->item(i, 3)->text());
    ui.lineEdit_4->setText(model->item(i, 4)->text());
    ui.lineEdit_5->setText(model->item(i, 5)->text());

    lista_detail(m_selectedText);
}
void QKasaLista::lista_detail(const QString& nameSearch)
{
	QLocale loc;
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}

	int r = 0;
	int c = 12;
	int fieldNo[12];
	QString country[12];
	int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 100, 70, 100, 100, 100};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznos", "iznosddv", "vkupeniznos"};
	QString temp = 
		"select "
		"artikli.id, " 
		"sifra, "
		"artikal, "
		"ikol, "
		"edm, "
		"icena ," //prod_cena (so ddv)
		"rabat, " 
		"icena * (1 - rabat/100), " //cena + rabat
		"artikli.ddv, " //ddv
		"ikol * icena * (1 - rabat/100) / ( 1 + artikli.ddv / 100), " //износ без ддв
		"ikol * icena * (1 - rabat/100) -  ikol * icena * (1 - rabat/100) / ( 1 + artikli.ddv / 100) , " //ddv
		"ikol * icena * (1 - rabat/100) " //iznos
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 45 and magacin.dok_id=       ";
	temp += m_selectedText;
	temp += "";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат %"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Цена со Рабат"));
	model2->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ %"));
	model2->setHeaderData( 9, Qt::Horizontal, trUtf8("Износ"));
	model2->setHeaderData( 10, Qt::Horizontal, trUtf8("ДДВ Износ"));
	model2->setHeaderData( 11, Qt::Horizontal, trUtf8("Износ со ДДВ"));

	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();
			if ((i > 4)||(i == 3))
			{
				item = new QStandardItem(loc.toString(temp.toDouble(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				if (i == 11)
				{
					sumaDDV += temp.toFloat();
				}
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
	ui.lineEdit_6->setText(loc.toString(sumaDDV, 'f', 2));
	CHelperClass chc(this);
	QString tip = "45";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.lineEdit_8->setText(loc.toString(chc.getPlatenIznos(), 'f', 2));
	ui.lineEdit_9->setText(loc.toString(sumaDDV - chc.getPlatenIznos(), 'f', 2));

	ui.tableView_2->show();
}

void QKasaLista::deleteDok(int idDok)
{
    QSqlQuery query;
    query.clear();
    query.prepare(
        "delete from magacin where dok_tip = 40 and dok_id = :a"
        );
    query.bindValue(":a", idDok);	
    query.exec();
}
void QKasaLista::on_pushButton_clicked()
{
    emit procF2();
}
void QKasaLista::on_pushButton_2_clicked()
{
    emit procF3();
}

QStringList QKasaLista::geInfo()
{
    QStringList info;
    info.clear();
    info << ui.lineEdit_3->text() << ui.lineEdit_4->text() << ui.lineEdit_5->text() << ui.lineEdit->text()<< ui.lineEdit_2->text(); 
    return info;
}

void QKasaLista::setInitText(QString text)
{
    ui.tableView->setFocus();
}
