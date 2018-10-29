#include "qfakturilista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>
#include <QDateTime>


QFakturaVleznaLista::QFakturaVleznaLista(QWidget *parent)
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
    connect(ui.lineEdit_7, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit7Pressed(const QString &)));

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));

	lista("%%%",QDateTime::currentDateTime(), QDateTime::currentDateTime());
    m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
    lista_detail(m_selectedText);
	//ui.tableView->setSortingEnabled(true); 
    ui.tableView->setFocus();
}


QFakturaVleznaLista::~QFakturaVleznaLista()
{

}

int QFakturaVleznaLista::getRow()
{
	return m_row;
}
void QFakturaVleznaLista::setRow(int mrow)
{
	ui.tableView->selectRow(mrow);
}
void QFakturaVleznaLista::pressEscape()
{
    emit closeW();
}

void QFakturaVleznaLista::pressReturn()
{
	if (ui.tableView->hasFocus())
	{
		emit sFakturiToIzvod(m_listDataInfo);	
	}
}

void QFakturaVleznaLista::lista(const QString& nameSearch, QDateTime date1, QDateTime date2)
{
	QLocale loc;
	if (nameSearch.length() < 0)
	{
		ui.tableView->hide();
		return;
	}
	int r = 0;
	int c = 14;
	int fieldNo[14];
	QString country[14];
	int colWidth[] = {0, 80, 80, 170, 100, 100, 100, 100, 140, 250, 0, 0, 0, 0};
	QString temp = "";
	if (date1 == date2)
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, 0, 0, 0, 0, 0, zabeleska,komintenti.adresa, komintenti.grad, rok, komintenti.id "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 20 and komintenti.naziv like '"+ nameSearch +"' order by dok_id desc "
			;
	}
	else
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, 0, 0, 0, 0, 0, zabeleska,komintenti.adresa, komintenti.grad, rok, komintenti.id "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 20 and (datum between #"+ date1.toString("yyyy/MM/dd") +"# and #"+ date2.toString("yyyy/MM/dd") +"# ) and komintenti.naziv like '"+ nameSearch +"' order by dok_id desc "
			;
	}
	QSqlQuery query(temp);
	model = new QStandardItemModel(r,c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Фактура бр."));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Коминтенти"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Износ"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("ДДВ"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Вкупно"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Платено"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Останато за плаќање"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Забелешка"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	header->show();
	int row = 0;
	CHelperClass chc(this);
	QString tip = "20";
	chc.createStatusMap(tip); 
	chc.createListaIzlezniFakturiIznosi(tip);
	chc.createListaKomintenti(tip);

	chc.getFakturaIznosiAll(tip);

	float mIznos = 0.0f;
	float mDDV = 0.0f;
	float mVkupno = 0.0f;
	float mVPlateno = 0.0f;
	float mVOstanato = 0.0f;

	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = new QStandardItem(query.value(i).toString());
			if ((i == 1))
			{
				chc.fakturaStatus(item, tip);
				item->setTextAlignment(Qt::AlignLeft);
			}

			if ((i == 2))
			{

				item = new QStandardItem(query.value(i).toString().left(10));
				item->setTextAlignment(Qt::AlignLeft);
			}

			if ((i == 4))
			{
				float tempIznos = chc.getFakturaIznos(query.value(1).toString());
				mIznos += tempIznos;
				item = new QStandardItem(loc.toString(tempIznos,'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 5))
			{
				float tempDDV = chc.getFakturaDDV(query.value(1).toString());
				mDDV += tempDDV;
				item = new QStandardItem(loc.toString(tempDDV,'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 6))
			{
				float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
				mVkupno += tempVkupen;
				item = new QStandardItem(loc.toString(tempVkupen,'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 7))
			{
				float tempPlatenIznos = chc.getFakturaOdlivIznos(query.value(1).toString());

				mVPlateno += tempPlatenIznos;
				item = new QStandardItem(loc.toString(tempPlatenIznos,'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 8))
			{
				float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
				float tempPlatenIznos = chc.getFakturaOdlivIznos(query.value(1).toString());
				mVOstanato += (tempVkupen - tempPlatenIznos); 
				item = new QStandardItem(loc.toString(tempVkupen - tempPlatenIznos, 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}

			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			item->setEditable(false);
			model->setItem(row, i, item);
		}
		row++;
	} 
	QString info =  trUtf8("       Вкупен Износ : ") + loc.toString(mIznos,'f',2) + trUtf8(" ден.") + 
		trUtf8("       Вкупен ДДВ : ") + loc.toString(mDDV,'f',2) + trUtf8(" ден.") +
		trUtf8("       Вкупен Износ со ДДВ: ") + loc.toString(mVkupno,'f',2) + trUtf8(" ден.") ;
	QString info2 = trUtf8("       Платено : ") + loc.toString(mVPlateno,'f',2) + trUtf8(" ден.") + 
		trUtf8("       Останато за плаќање : ") + loc.toString(mVOstanato,'f',2) + trUtf8(" ден.") ;

	ui.label_11->setText(info);
	ui.label_12->setText(info2);

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}
void QFakturaVleznaLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_row = modelX.row();
    m_selectedText = model->item(i, 1) ? model->item(i, 1)->text():"";
    m_fakturaBr = model->item(i, 1)->text();
    m_fakturadatum = model->item(i, 2)->text();
    m_komintent_naziv =  model->item(i, 3)->text();
//     m_komintent_adresa =  model->item(i, 8)->text();
//     m_komintent_grad =  model->item(i, 9)->text();

    lista_detail(m_selectedText);

}
// void QFakturaVleznaLista::lista_detail(const QString& nameSearch)
// {
// 	QLocale loc;
// 	if (nameSearch.length() < 0)
// 	{
// 		ui.tableView_2->hide();
// 		return;
// 	}
// 
// 	int r = 0;
// 	int c = 11;
// 	int fieldNo[11];
// 	QString country[11];
// 	int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 100, 70, 100, 100};
// 	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznosddv", "vkupeniznos"};
// 	QString temp = 
// 		"select "
// 		"artikli.id, " 
// 		"sifra, "
// 		"artikal, "
// 		"ikol, "
// 		"edm, "
// 		"icena ," //prod_cena (so ddv)
// 		"rabat, " 
// 		"icena * (1 - rabat/100), " //cena + rabat
// 		"artikli.ddv, " //ddv
// 		"ikol * icena * (1 - rabat/100) * ( artikli.ddv / 100) / (1 + artikli.ddv / 100), " //ddv
// 		"ikol * icena * (1 - rabat/100) " //iznos
// 		"from magacin                                         "
// 		"left join artikli on magacin.artikal_id = artikli.id "
// 		"where magacin.dok_tip = 20 and magacin.dok_id=       ";
// 	temp += m_selectedText;
// 	temp += "";
// 	QSqlQuery query(temp);
// 
// 	model2 = new QStandardItemModel(r,c);
// 	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
// 	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
// 	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
// 	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
// 	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
// 	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
// 	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат %"));
// 	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Цена со Рабат"));
// 	model2->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ %"));
// 	model2->setHeaderData( 9, Qt::Horizontal, trUtf8("ДДВ Износ"));
// 	model2->setHeaderData( 10, Qt::Horizontal, trUtf8("Износ со ДДВ"));
// 
// 	ui.tableView_2->setModel(model2);
// 	header2 = new QHeaderView(Qt::Horizontal, this);
// 	header2->setClickable(true);
// 	ui.tableView_2->setHorizontalHeader(header2);
// 	header2->show();
// 	int row = 0;
// 	float sumaDDV = 0.f;
// 	while (query.next()) 
// 	{
// 		for (int i = 0; i < c; i++)
// 		{
// 			fieldNo[i] = i; //query.record().indexOf(colName[i]);
// 			QStandardItem *item = NULL;
// 			QString temp = query.value(fieldNo[i]).toString();
// 			
// 			if ((i > 4)||(i == 3))
// 			{
// 				item = new QStandardItem(loc.toString(temp.toDouble(), 'f', 2));
// 				item->setTextAlignment(Qt::AlignRight);
// 				if (i == 10)
// 				{
// 					sumaDDV += temp.toFloat();
// 				}
// 			}
// 			else
// 			{
// 				item = new QStandardItem(temp);
// 				item->setTextAlignment(Qt::AlignLeft);
// 			}
// 
// 			item->setEditable(false);
// 			ui.tableView_2->setRowHeight(row, 18);
// 			ui.tableView_2->setColumnWidth(i, colWidth[i]);
// 			model2->setItem(row, i, item);
// 		}
// 		row++;
// 	} 
// 	ui.lineEdit_6->setText(loc.toString(sumaDDV, 'f', 2));
// 	CHelperClass chc(this);
// 	QString tip = "20";
// 	chc.getFakturaPlatenIznos(m_selectedText, tip);
// 	ui.lineEdit_8->setText(loc.toString(chc.getPlatenIznos(), 'f', 2));
// 	ui.lineEdit_9->setText(loc.toString(sumaDDV - chc.getPlatenIznos(), 'f', 2));
// 
// 	ui.tableView_2->show();
// }
void QFakturaVleznaLista::lista_detail(const QString& nameSearch)
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
		"where magacin.dok_tip = 20 and magacin.dok_id=       ";
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
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.lineEdit_8->setText(loc.toString(chc.getPlatenIznos(), 'f', 2));
	ui.lineEdit_9->setText(loc.toString(sumaDDV - chc.getPlatenIznos(), 'f', 2));

	ui.tableView_2->show();
}

void QFakturaVleznaLista::deleteDok(int idDok)
{
    QSqlQuery query;
    query.clear();
    query.prepare(
        "delete from magacin where dok_tip = 20 and dok_id = :a"
        );
    query.bindValue(":a", idDok);	
    query.exec();
}


void QFakturaVleznaLista::on_pushButton_clicked()
{
    emit procF2();
}
void QFakturaVleznaLista::on_pushButton_2_clicked()
{
    emit procF3();
}
QStringList QFakturaVleznaLista::geInfo()
{
    QStringList info;
    info.clear();
    info << m_fakturaBr << m_fakturadatum << m_komintent_naziv << m_komintent_adresa << m_komintent_grad;
    return info;
}

void QFakturaVleznaLista::setInitText(QString text, QDateTime &date1, QDateTime &date2)
{
	 ui.tableView->setFocus();
	 ui.tableView->setSelectionMode(QAbstractItemView::MultiSelection); 
	 ui.label_4->setText(trUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Влезни Фактури - Листа</span></p></body></html>"));
	 ui.tableView->setFocus();
	 connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(calcSelectedItems()));
	 lista(text + "%", date1, date2);
}
void QFakturaVleznaLista::lineEdit7Pressed(const QString & text)
{
	lista(text + "%", QDateTime::currentDateTime(), QDateTime::currentDateTime());
}
void QFakturaVleznaLista::calcSelectedItems()
{
	QLocale loc;
	QModelIndexList itemSelection = ui.tableView->selectionModel()->selectedRows();
	m_listDataInfo.clear();
	float mIznos = 0.f;
	for (int i = 0; i < itemSelection.count();i++)
	{
		QString itemData = "";
		for(int tempCol = 0; tempCol < 14; tempCol++)
		{
			itemData += model->item(itemSelection.at(i).row(), tempCol)->text()+ "  ::  ";
			if( tempCol == 8)
			{
				mIznos += loc.toFloat(model->item(itemSelection.at(i).row(), tempCol)->text());
			}
		}
		itemData += "20  ::  ";
		m_listDataInfo << itemData;
		int stop = 0;
	}

	QString info = trUtf8("       Вкупен Неплатен Износ во селектираните фактури е : ") + loc.toString(mIznos,'f',2) + trUtf8(" ден.");
	ui.label_13->setText(info);
}
