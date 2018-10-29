#include "qKalkulacijalista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>
#include <QClipboard>
#include "xx.h"


QKalkulacijaLista::QKalkulacijaLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	getTableColumnWidths(14, 17);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));

	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(copyToClipBoard()));

	lista("%%%", QDateTime::currentDateTime(), QDateTime::currentDateTime() );
	m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
	lista_detail(m_selectedText);
	ui.tableView->setFocus();
}



QKalkulacijaLista::~QKalkulacijaLista()
{
	setTableColumnWidths(14, 17);
}

void QKalkulacijaLista::lista(const QString& nameSearch, QDateTime date1, QDateTime date2)
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
	//int colWidth[] = {0, 80, 80, 150, 100, 100, 80, 80, 80, 80, 0, 0, 100, 100};


	QString temp = "";
	if (date1 == date2)
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, iznos_faktura, 0, 0, faktura_br, tip_dokument, datum_f_ra, komintenti.id, komintenti.sifra, valuta_datum, dok_opis "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 20 and komintenti.naziv like '"+ nameSearch +"' order by dok_id desc "
			;

	}
	else
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, iznos_faktura, 0, 0, faktura_br, tip_dokument, datum_f_ra, komintenti.id, komintenti.sifra, valuta_datum, dok_opis "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 20 and (datum between #"+ date1.toString("yyyy/MM/dd") +"# and #"+ date2.toString("yyyy/MM/dd") +"# ) and komintenti.naziv like '"+ nameSearch +"' order by dok_id desc "
			;
	}
	QSqlQuery query(temp);
	model = new QStandardItemModel(r,c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id.\n"));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Прием.\nбр."));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум\n"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Коминтенти\n"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Вкупна набавна\nвредност со ДДВ"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Платено\n"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Останато\nза плаќање"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Документ\nброј"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Документ\nТип"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Датум\nДокумент"));
	model->setHeaderData( 12, Qt::Horizontal, trUtf8("Валута\n"));
	model->setHeaderData( 13, Qt::Horizontal, trUtf8("Забелешка\n"));
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

			if ((i == 2)||(i == 9))
			{
				item = new QStandardItem(query.value(i).toString().left(10));
				item->setTextAlignment(Qt::AlignLeft);
			}

			if ((i == 4))
			{
				float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
				mVkupno += tempVkupen;
				tempVkupen = floor(tempVkupen + .5f);
				item = new QStandardItem(loc.toString((tempVkupen),'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 5))
			{
				float tempPlatenIznos = chc.getFakturaOdlivIznos(query.value(1).toString());
				tempPlatenIznos = floor(tempPlatenIznos + .5f);
				mVPlateno += tempPlatenIznos;
				item = new QStandardItem(loc.toString((tempPlatenIznos),'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 6))
			{
				float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
				tempVkupen = floor(tempVkupen + .5f);
				float tempPlatenIznos = chc.getFakturaOdlivIznos(query.value(1).toString());
				tempPlatenIznos = floor(tempPlatenIznos + .5f);
				mVOstanato += (tempVkupen - tempPlatenIznos); 
				item = new QStandardItem(loc.toString((tempVkupen - tempPlatenIznos), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 7))
			{
				item->setTextAlignment(Qt::AlignRight);
			}

			if ((i == 12))
			{
				item = new QStandardItem(query.value(i).toString().left(10));
				QDateTime tempD = query.value(i).toDateTime();
				QDateTime tempC = QDateTime::currentDateTime();
				QBrush newBrush;
				if (tempD > tempC)
				{
					newBrush.setColor(Qt::darkGreen);
					item->setForeground(newBrush);
				} 
				else
				{
					newBrush.setColor(Qt::red);
					item->setForeground(newBrush);
				}

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
	QString info = trUtf8(" Вкупен набавен износ со ДДВ: ") + loc.toString((mVkupno),'f',2) + trUtf8(" ден.") + "  "+
				   trUtf8(" Платено : ") + loc.toString((mVPlateno),'f',2) + trUtf8(" ден.") + " " +
		           trUtf8(" Останато за плаќање : ") + loc.toString((mVOstanato),'f',2) + trUtf8(" ден.") ;

	ui.label_11->setText(info);

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
	ui.tableView->setColumnHidden(0, true);
	ui.tableView->setColumnHidden(10, true);
	ui.tableView->setColumnHidden(11, true);
	ui.tableView->show();
}

void QKalkulacijaLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	QLocale loc;
	int i = modelX.row();
	m_selectedText = model->item(i, 1) ? model->item(i, 1)->text():"";
	ui.label->setText(trUtf8("Приемница бр: ") + model->item(i, 1)->text() + trUtf8(" - Шифра: ") + model->item(i, 11)->text() + 
		trUtf8(" - Коминтент: ") + model->item(i, 3)->text());
	ui.label_2->setText(trUtf8("Број на документот : ") + model->item(i, 7)->text() + trUtf8(" - Тип : ") + model->item(i, 8)->text() + 
		trUtf8(" - Датум на документот: ") + model->item(i, 9)->text().left(10));

	lista_detail(m_selectedText);
}
void QKalkulacijaLista::lista_detail(const QString& nameSearch)
{
	QLocale loc;
    CHelperClass chc(this);
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}

	int r = 0;
	int c = 17;
	int fieldNo[17];
	QString country[17];
	//int colWidth[] = {0, 70, 220, 60, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 120};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "mag_id" };
	QString temp = 
		"select artikli.id, sifra, artikal, edm, ikol, nab_cena, prod_cena, ddv, marza, rabat, nab_cena_bez_ddv "
		"from magacin "
		"left join artikli on magacin.artikal_id=artikli.id "
		"where magacin.dok_tip = 20 and magacin.dok_id= ";
	temp += nameSearch;
	temp += " order by magacin.id ";
	QSqlQuery query(temp);
	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид.\n"));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра\n"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал\n"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Ед.\nме."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Количина\n"));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Набавна цена\nбез ДДВ"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Пренесен\nДДВ (%)"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Вредност\n на ДДВ"));
	model2->setHeaderData( 8, Qt::Horizontal, trUtf8("Набавна цена\nсо ДДВ"));
	model2->setHeaderData( 9, Qt::Horizontal, trUtf8("Рабат\n(%)"));
	model2->setHeaderData( 10, Qt::Horizontal, trUtf8("Вкупен Набавен\nизнос со ДДВ"));
	model2->setHeaderData( 11, Qt::Horizontal, trUtf8("Maржа\n(%)"));
	model2->setHeaderData( 12, Qt::Horizontal, trUtf8("Маржа\n(ден.)"));
	model2->setHeaderData( 13, Qt::Horizontal, trUtf8("Продажна цена\nбез ДДВ"));
	model2->setHeaderData( 14, Qt::Horizontal, trUtf8("Пресметан\nДДВ"));
	model2->setHeaderData( 15, Qt::Horizontal, trUtf8("Продaжна цена\nсо ДДВ"));
	model2->setHeaderData( 16, Qt::Horizontal, trUtf8("Вкупен продажен\nизнос со ДДВ"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;

	m_vkupen_nabaven_iznos_bez_ddv = 0.f;
	m_vkupen_vlezen_ddv = 0.f;
	m_vkupen_nabaven_iznos_so_ddv = 0.f;
	m_vkupna_marza_iznos = 0.f;
	m_vkupen_prodazen_iznos_bez_ddv = 0.f;
	m_vkupen_presmetan_ddv = 0.f;
	m_vkupen_prodazen_iznos_so_ddv = 0.f;


	while (query.next()) 
	{
		int row = model2->rowCount();
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = "";
			//"select artikli.id, sifra, artikal, edm, ikol, icena, prod_cena, ddv "
			if (i == 0) // id
			{
				temp = query.value(0).toString();
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			if (i == 1) // sifra
			{
				temp = query.value(1).toString();
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}

			if (i == 2) // artikal
			{
				temp = query.value(2).toString();
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			if (i == 3) // edm
			{
				temp = query.value(3).toString();
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			if (i == 4) // kol
			{
				temp = query.value(4).toString();
				temp =  loc.toString(temp.toFloat(), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			if (i == 5) // nabavna cena - ddv
			{
				float nabCenabezDDV = query.value(10).toFloat();
				
				temp =  loc.toString((nabCenabezDDV), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				m_vkupen_nabaven_iznos_bez_ddv += query.value(4).toFloat() * nabCenabezDDV;
			}
			if (i == 6) // prenesen ddv
			{
				temp = query.value(7).toString();
				temp =  loc.toString(temp.toFloat(), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				
			}
			if (i == 7) // ddv
			{
				float nabCenasoDDV = query.value(5).toFloat();
				float prenesenDDVProcent = query.value(7).toFloat();
				float prenesenDDVIznos = nabCenasoDDV * ( prenesenDDVProcent / (100 + prenesenDDVProcent));
				m_vkupen_vlezen_ddv += prenesenDDVIznos * query.value(4).toFloat();
				temp =  loc.toString((prenesenDDVIznos), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);		
			}

			if (i == 8) // nabavna cena +ddv 
			{
				float nabCenasoDDV = query.value(5).toFloat();
				temp =  loc.toString((nabCenasoDDV), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
//				m_vkupen_nabaven_iznos_so_ddv += nabCenasoDDV * query.value(4).toFloat();
			}

			if (i == 9) // rabat
			{
				temp = query.value(9).toString();
				temp =  loc.toString(temp.toFloat(), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			if (i == 10) // vk nabavna + ddv
			{
				float nabCenasoDDV = query.value(5).toFloat();
				float prenesenDDVProcent = query.value(7).toFloat();
				float prenesenDDVIznos = nabCenasoDDV * ( prenesenDDVProcent / (100 + prenesenDDVProcent));
				float nabCenabezDDV = query.value(10).toFloat();
				float kolicinaStavka = query.value(4).toFloat();
				float nabCenaPlusDDV = query.value(5).toFloat();
				float rabatStavka = query.value(9).toFloat();
				float nabCenaPlusDDVsoRabat = nabCenaPlusDDV * (1 - rabatStavka/100);
				float vkupnoNabPlusDDV = nabCenaPlusDDVsoRabat * kolicinaStavka;
				m_sumaPoNabCena += vkupnoNabPlusDDV;
				m_vkupen_nabaven_iznos_so_ddv += vkupnoNabPlusDDV;
				temp =  loc.toString((vkupnoNabPlusDDV), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			if (i == 11) // marza
			{
				temp = query.value(8).toString();
				temp =  loc.toString(temp.toFloat(), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			if (i == 12) // marza den
			{
				float nabCenasoDDV = query.value(5).toFloat();
				float prenesenDDVProcent = query.value(7).toFloat();
				float prenesenDDVIznos = nabCenasoDDV * ( prenesenDDVProcent / (100 + prenesenDDVProcent));
				float nabCenabezDDV = query.value(10).toFloat();
				float kolicinaStavka = query.value(4).toFloat();
				float nabCenaPlusDDV = query.value(5).toFloat();
				float rabatStavka = query.value(9).toFloat();
				float nabCenaPlusDDVsoRabat = nabCenaPlusDDV * (1 - rabatStavka/100);
				float vkupnoNabPlusDDV = nabCenaPlusDDVsoRabat * kolicinaStavka;

				float marzaProcent = query.value(8).toFloat();
				float marzaIznos = nabCenaPlusDDVsoRabat * marzaProcent/100;
				temp =  loc.toString((marzaIznos), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				m_vkupna_marza_iznos += marzaIznos * query.value(4).toFloat();

			}

			if (i == 13) // prodazna cena - ddv
			{
				float nabCenasoDDV = query.value(5).toFloat();
				float prenesenDDVProcent = query.value(7).toFloat();
				float prenesenDDVIznos = nabCenasoDDV * ( prenesenDDVProcent / (100 + prenesenDDVProcent));
				float nabCenabezDDV =  query.value(10).toFloat();;
				float kolicinaStavka = query.value(4).toFloat();
				float nabCenaPlusDDV = query.value(5).toFloat();
				float rabatStavka = query.value(9).toFloat();
				float nabCenaPlusDDVsoRabat = nabCenaPlusDDV * (1 - rabatStavka/100);
				float vkupnoNabPlusDDV = nabCenaPlusDDVsoRabat * kolicinaStavka;

				float marzaProcent = query.value(8).toFloat();
				float marzaIznos = nabCenaPlusDDVsoRabat * marzaProcent/100;
				float prodCenaSoDDV = nabCenaPlusDDVsoRabat + marzaIznos;
				float vkupnoProdSoDDV = prodCenaSoDDV * kolicinaStavka;
				float presmetanDDV = marzaIznos * prenesenDDVProcent / 100;
				float prodCenaBezDDV = prodCenaSoDDV - presmetanDDV;

				temp =  loc.toString((prodCenaBezDDV), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				m_vkupen_prodazen_iznos_bez_ddv += prodCenaBezDDV * query.value(4).toFloat();
			}

			if (i == 14) // presmetan ddv
			{
				float kolicinaStavka = query.value(4).toFloat();
				float nabCenaPlusDDV = query.value(5).toFloat();
				float prenesenDDVProcent = query.value(7).toFloat();
				float prenesenDDVIznos = nabCenaPlusDDV * ( prenesenDDVProcent / (100 + prenesenDDVProcent));
				float nabCenabezDDV = query.value(10).toFloat();
				float rabatStavka = query.value(9).toFloat();
				float nabCenaPlusDDVsoRabat = nabCenaPlusDDV * (1 - rabatStavka/100);
				float vkupnoNabPlusDDV = nabCenaPlusDDVsoRabat * kolicinaStavka;
				float marzaProcent = query.value(8).toFloat();
				float marzaIznos = nabCenaPlusDDVsoRabat * marzaProcent/100;

				float prodCenaSoDDV = nabCenaPlusDDVsoRabat + marzaIznos;
				float vkupnoProdSoDDV = prodCenaSoDDV * kolicinaStavka;
				float presmetanDDV = marzaIznos * prenesenDDVProcent / 100;
				float prodCenaBezDDV = prodCenaSoDDV - presmetanDDV;

				temp =  loc.toString((presmetanDDV), 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				m_vkupen_presmetan_ddv += presmetanDDV * query.value(4).toFloat();
			}

			if (i == 15) // prod cena + ddv
			{
				float prodCenaSoDDV = query.value(6).toFloat();
				temp =  loc.toString(prodCenaSoDDV, 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}

			if (i == 16) // vk prodazna + ddv
			{
				float prodCenaSoDDV = query.value(6).toFloat();
				float kolicinaStavka = query.value(4).toFloat();
				float vkupnoProdSoDDV = prodCenaSoDDV * kolicinaStavka;
				m_sumaPoProdazCena += vkupnoProdSoDDV;
				m_vkupen_prodazen_iznos_so_ddv += vkupnoProdSoDDV;
				temp =  loc.toString(vkupnoProdSoDDV, 'f', 4);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(i, colWidth_detail[i]);
		model2->setItem(row, i, item);
		}        
	} 

	ui.lineEdit_4->setText( loc.toString(floor((m_vkupen_nabaven_iznos_bez_ddv) + .5f), 'f', 2));
	ui.lineEdit_5->setText( loc.toString(floor((m_vkupen_vlezen_ddv) + .5f), 'f', 2));
	ui.lineEdit_6->setText( loc.toString(floor((m_vkupen_nabaven_iznos_so_ddv) + .5f), 'f', 2));
	ui.lineEdit_7->setText( loc.toString(floor((m_vkupna_marza_iznos) + .5f), 'f', 2));
	ui.lineEdit_8->setText( loc.toString(floor((m_vkupen_prodazen_iznos_bez_ddv) + .5f), 'f', 2));
	ui.lineEdit_9->setText( loc.toString(floor((m_vkupen_presmetan_ddv) + .5f), 'f', 2));
	ui.lineEdit_10->setText( loc.toString(floor((m_vkupen_prodazen_iznos_so_ddv) + .5f), 'f', 2));
	connect(header2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized_detail(int, int, int)));
	ui.tableView_2->setColumnHidden(0, true);

	ui.tableView_2->show();
}
//	connect(header2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));

void QKalkulacijaLista::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}

void QKalkulacijaLista::procSectionResized_detail(int a, int b, int c)
{
	colWidth_detail[a] = c;
}

void QKalkulacijaLista::pressEscape()
{
	emit closeW();
}

void QKalkulacijaLista::deleteDok(int idDok)
{
}


void QKalkulacijaLista::on_pushButton_clicked()
{
    emit procF2();
}
void QKalkulacijaLista::on_pushButton_2_clicked()
{
    emit procF3();
}
QStringList QKalkulacijaLista::geInfo()
{
    QStringList info;
    info.clear();
//    info << ui.lineEdit_3->text() << ui.lineEdit_4->text() << ui.lineEdit_5->text() << ui.lineEdit->text() << ui.lineEdit_2->text(); 
    return info;
}

int QKalkulacijaLista::getRow()
{
	int m_row = -1;
	QModelIndexList indexes = ui.tableView->selectionModel()->selection().indexes();
	if (indexes.count())
	{
		m_row = indexes.at(0).row();
	}
	return m_row;
}

void QKalkulacijaLista::setRow(int mrow)
{
	ui.tableView->selectRow(mrow);
	ui.tableView->setFocus();
}
void QKalkulacijaLista::pressReturn()
{
	if (ui.tableView->hasFocus())
	{
		emit sFakturiToIzvod(m_listDataInfo);	
	}
}

void QKalkulacijaLista::setInitText(QString text, QDateTime &date1, QDateTime &date2)
{
	ui.tableView->setFocus();
	ui.tableView->setSelectionMode(QAbstractItemView::MultiSelection); 
	ui.label_4->setText(trUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Приемница-Калкулација - Листа</span></p></body></html>"));
	ui.tableView->setFocus();
	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(calcSelectedItems()));
	lista(text + "%", date1, date2);
}

void QKalkulacijaLista::calcSelectedItems()
{
	QLocale loc;
	QModelIndexList itemSelection = ui.tableView->selectionModel()->selectedRows();
	m_listDataInfo.clear();
	float mIznos = 0.f;
	for (int i = 0; i < itemSelection.count();i++)
	{
		QString itemData = "";
		for(int tempCol = 0; tempCol < 11; tempCol++)
		{
			itemData += model->item(itemSelection.at(i).row(), tempCol)->text()+ "  ::  ";
			if( tempCol == 6)
			{
				mIznos += loc.toFloat(model->item(itemSelection.at(i).row(), tempCol)->text());
			}
		}
		itemData += "0  :: 0  :: 0  :: 20  ::  ";
		m_listDataInfo << itemData;
		int stop = 0;
	}

	QString info = trUtf8("       Вкупен Неплатен Износ во селектираните фактури е : ") + loc.toString(mIznos,'f',2) + trUtf8(" ден.");
	ui.label_13->setText(info);
}

void QKalkulacijaLista::copyToClipBoard()
{
	QString m_copyedString = "";

	setUpdatesEnabled(false);	
	for(int c_row = 0; c_row < model2->rowCount(); c_row++)
	{
		QStringList c;
		c.clear();
		for(int c_col = 0; c_col < model2->columnCount(); c_col++)
		{
			QString temp = model2->item(c_row,c_col)->text().trimmed();
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

void QKalkulacijaLista::setTableColumnWidths(int ccolumn, int ccolumn_detail)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	QStringList tempWidth_detail;

	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	for (int i = 0; i < ccolumn_detail; i++)
	{
		tempWidth_detail << QString::number(ui.tableView_2->columnWidth(i), 10);
	}
	s->setKalkulacija_ColumnWidth(tempWidth);
	s->setKalkulacija_Detail_ColumnWidth(tempWidth_detail);
}

void QKalkulacijaLista::getTableColumnWidths(int ccolumn, int ccolumn_detail)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getKalkulacija_ColumnWidth();
	if (sss.count() == ccolumn)
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth[i1] = loc.toInt(sss.at(i1));
		}
	}
	else
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth[i1] = 100;
		}
	}

	sss = s->getKalkulacija_Detail_ColumnWidth();
	if (sss.count() == ccolumn_detail)
	{
		for (int i1 = 0; i1 < ccolumn_detail; i1++)
		{
			colWidth_detail[i1] = loc.toInt(sss.at(i1));
		}
	}
	else
	{
		for (int i1 = 0; i1 < ccolumn_detail; i1++)
		{
			colWidth_detail[i1] = 100;
		}
	}
}

