#include "qFinAnalitikaKomintentiwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "xx.h"


QFinAnalitKomintentiWidget::QFinAnalitKomintentiWidget(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,m_selectedText("") 
    ,m_selectedTextName("")
	,m_priemnici_helper(this)
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
	ui.lineEdit_5->hide();
	ui.lineEdit_6->hide();
	ui.lineEdit_7->hide();
	ui.label_8->hide();
	ui.label_9->hide();
	ui.label_10->hide();
	m_priemnici_helper.createMapPriemnici();
}
// select komintentbr, datum , izvod_stavki.izvodbr
// 	from izvodi
// 	left join izvod_stavki on
// 	izvodi.izvodBr = izvod_stavki.izvodBr
// 	and izvodi.BankaId = izvod_stavki.BankaId
// where komintentbr = 599

QFinAnalitKomintentiWidget::~QFinAnalitKomintentiWidget()
{

}


void QFinAnalitKomintentiWidget::pressEscape()
{
    emit closeW();
}


void QFinAnalitKomintentiWidget::lista(const QString& nameSearch)
{
	QLocale loc;
    int r = 0;
    int c = 6;
    int fieldNo[6];
    QString country[6];
    int colWidth[] = {0, 120, 350, 100,100,100};
    QString colName[7] = {"id", "artikal", "edm", "proizvoditel", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};

    QString temp;
    temp =
// 		" SELECT komintenti.id, sifra, naziv, 0, 0, 0 "
// 		" FROM ((izvod_stavki "
// 		" LEFT JOIN komintenti ON izvod_stavki.komintentbr = komintenti.id) "
// 		" LEFT JOIN dokumenti  ON  dokumenti.komintent_id = komintenti.id) "
// 		" GROUP BY  komintenti.id, naziv, sifra "
// 		" HAVING (komintenti.naziv LIKE '"+nameSearch+"%' or komintenti.sifra LIKE '"+nameSearch+"%') ";
	" SELECT komintenti.id, sifra, naziv, 0, 0, 0 "
	" FROM komintenti  "
	" LEFT JOIN dokumenti  ON  dokumenti.komintent_id = komintenti.id "
	" GROUP BY  komintenti.id, naziv, sifra "
	" HAVING (komintenti.naziv LIKE '"+nameSearch+"%' or komintenti.sifra LIKE '"+nameSearch+"%') ";

	QSqlQuery query(temp);
    QSqlError err = query.lastError();
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Коминтент"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Должи"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Побарува"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Салдо"));

	ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);

    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
	CHelperClass chc(this);
	chc.calcPlakanjaPoKomintent();
	chc.calcPrilivOdlivPoKomintent();

	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkSaldo = 0.f;
	
	float vkPobaruva = 0.f;
	float vkDolzi = 0.f;
	float vkSaldoFin = 0.f;
	float totalPobaruva = 0.f;
	float totalDolzi = 0.f;
	float totalSaldoFin = 0.f;
	
	setUpdatesEnabled(false);
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            if (i < 3)
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
			if (i == 3)
			{
				vkDolzi = 0.f;
				vkDolzi += chc.getPrilivOdlivPoKomintent(query.value(0).toString(), QString("40"));
				vkDolzi += chc.getPrilivOdlivPoKomintent(query.value(0).toString(), QString("60"));
				vkDolzi += chc.getPlakanjePoKomintent(query.value(0).toString(), QString("20"));
				vkDolzi += chc.getPlakanjePoKomintent(query.value(0).toString(), QString("25"));
				totalDolzi += vkDolzi;
				QString temp = loc.toString(vkDolzi, 'f', 2);
				QStandardItem *item = NULL; 
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				item->setEditable(false);
				ui.tableView->setRowHeight(row, 18);
				ui.tableView->setColumnWidth(i, colWidth[i]);
				model->setItem(row, i, item);
			}
			if (i == 4)
			{
				vkPobaruva = 0.f;
				vkPobaruva += chc.getPrilivOdlivPoKomintent(query.value(0).toString(), QString("20"));
				vkPobaruva += chc.getPrilivOdlivPoKomintent(query.value(0).toString(), QString("25"));
				vkPobaruva += chc.getPlakanjePoKomintent(query.value(0).toString(), QString("40"));

				totalPobaruva += vkPobaruva;
				QString temp = loc.toString(vkPobaruva, 'f', 2);
				QStandardItem *item = NULL; 
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				item->setEditable(false);
				ui.tableView->setRowHeight(row, 18);
				ui.tableView->setColumnWidth(i, colWidth[i]);
				model->setItem(row, i, item);
			}
			if (i == 5)
			{
				QString temp = loc.toString(vkPobaruva - vkDolzi, 'f', 2);
				QStandardItem *item = NULL; 
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
				item->setEditable(false);
				ui.tableView->setRowHeight(row, 18);
				ui.tableView->setColumnWidth(i, colWidth[i]);
				model->setItem(row, i, item);
			}
        }
		row++;
    } 
	setUpdatesEnabled(true);

	ui.lineEdit_2->setText(loc.toString(totalDolzi, 'f', 2));
	ui.lineEdit_3->setText(loc.toString(totalPobaruva, 'f', 2));
	ui.lineEdit_4->setText(loc.toString(totalPobaruva - totalDolzi, 'f', 2));
	QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
    this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();
}
bool sortFunction (tFinData i, tFinData j) { return (i.datum < j.datum); }

void QFinAnalitKomintentiWidget::lista_detail(const QString& nameSearch)
{
	QLocale loc;
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}

	int r = 0;
	int c = 6;
	int fieldNo[6];
	QString country[6];
	int colWidth[] = {50, 380, 120, 100, 100, 120};
	
	QString temp = 

    " SELECT dokumenti.dok_id, dokumenti.dok_tip, datum, sum(ikol * prod_cena * (100 - magacin.rabat)/100) as iznos_prod, sum(ikol * nab_cena * (100 - magacin.rabat)/100) as iznos_nab "
	" FROM (dokumenti "
	" LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND "
    " dokumenti.dok_tip = magacin.dok_tip) "
	" WHERE dokumenti.komintent_id = " + m_selectedText + 
	" GROUP BY dokumenti.dok_id, dokumenti.dok_tip, datum "
	" ORDER BY datum";

	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Док.Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Вид на документ"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Должи "));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Побарува"));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Салдо"));
    ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
    float saldo = 0;
	float mDolzi = 0;
	float mPobaruva = 0;
	float mSaldo = 0;
	CHelperClass chc(this);
	chc.createMapNefakturiraniIspratnici();
	listFinData.clear();
	tFinData itemFinData;
	while (query.next()) 
	{
		itemFinData.dok_id = query.value(0).toInt();
		itemFinData.dok_tip = query.value(1).toInt();
		itemFinData.datum = query.value(2).toDateTime();
		float iznos = 0.f;
		if (itemFinData.dok_tip == 20)
		{
			iznos = query.value(4).toFloat();
		} 
		else if (itemFinData.dok_tip == 25)
		{
			iznos = query.value(3).toFloat();
		}
		else if (itemFinData.dok_tip == 40)
		{
			iznos = query.value(3).toFloat();
		}
		else if (itemFinData.dok_tip == 60)
		{
			if(chc.getNefaktiriranaIspratnica(itemFinData.dok_id))
			{
				continue;
			}
			iznos = query.value(3).toFloat();
		}
		switch(itemFinData.dok_tip)
		{
			case 20 : itemFinData.pobaruva = iznos;
					  itemFinData.dolzi = 0.f;
					  itemFinData.vidDok = trUtf8("ПРИЕМНИЦА");

					  itemFinData.vidDok_Detail = 
					  m_priemnici_helper.getTipDokumentFromPriemnica(query.value(0).toString()) + " "+ 
					  m_priemnici_helper.getFakturaFromPriemnica(query.value(0).toString());
					  listFinData.push_back(itemFinData);
					  break;

			case 40 : itemFinData.dolzi = iznos;
					  itemFinData.pobaruva = 0.f;
					  itemFinData.vidDok = trUtf8("ИЗЛЕЗНА ФАКТУРА");
					  listFinData.push_back(itemFinData);
					  break;

			case 60 : itemFinData.dolzi = iznos;
				itemFinData.pobaruva = 0.f;
				itemFinData.vidDok = trUtf8("ИСПРАТНИЦА");
				listFinData.push_back(itemFinData);
				break;

			case 25 : itemFinData.pobaruva = iznos;
     				  itemFinData.dolzi = 0.f;
					  itemFinData.vidDok = trUtf8("ПОВРАТНИЦА");
					  listFinData.push_back(itemFinData);
					  break;
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////

		temp = 

		" select izvod_stavki.izvodbr, 180, datum , priliv, odliv "
		" from izvodi "
		" left join izvod_stavki on "
		" izvodi.izvodBr = izvod_stavki.izvodBr "
		" and izvodi.BankaId = izvod_stavki.BankaId "
		" where komintentbr = "  + m_selectedText;

	QSqlQuery query2(temp);

	tFinData itemFinData2;
	while (query2.next()) 
	{
		itemFinData2.dok_id = query2.value(0).toInt();
		itemFinData2.dok_tip = query2.value(1).toInt();
		itemFinData2.datum = query2.value(2).toDateTime();
		itemFinData2.pobaruva = query2.value(3).toFloat();
		itemFinData2.dolzi = query2.value(4).toFloat();
		itemFinData2.vidDok = trUtf8("ИЗВОД");
		listFinData.push_back(itemFinData2);
	}
	std::sort (listFinData.begin(), listFinData.end(), sortFunction); // 12 32 45 71(26 33 53 80)
	saldo = 0.f;
	for( int rr = 0; rr < listFinData.size(); rr++)
	{
			int temp_dok_id = listFinData.at(rr).dok_id;
			QString temp_vidDok = "";
			if (listFinData.at(rr).dok_tip == 20)
			{
				temp_vidDok = listFinData.at(rr).vidDok + " (" + listFinData.at(rr).vidDok_Detail+")";
			} 
			else
			{
				temp_vidDok = listFinData.at(rr).vidDok;
			}
			
			QDateTime temp_datum = listFinData.at(rr).datum;
			float temp_dolzi = listFinData.at(rr).dolzi;
			float temp_pobaruva = listFinData.at(rr).pobaruva;

			QStandardItem *item = NULL; 
			temp = QString::number(temp_dok_id);
			item = new QStandardItem(temp);
			item->setTextAlignment(Qt::AlignCenter);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(0, 100);
			model2->setItem(rr, 0, item);

			item = new QStandardItem(temp_vidDok);
			item->setTextAlignment(Qt::AlignLeft);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(1, 250);
			model2->setItem(rr, 1, item);

			item = new QStandardItem(temp_datum.toString("dd/MM/yyyy"));
			item->setTextAlignment(Qt::AlignLeft);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(2, 100);
			model2->setItem(rr, 2, item);
			
			item = new QStandardItem(loc.toString(temp_dolzi, 'f', 2));
			item->setTextAlignment(Qt::AlignRight);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(3, 120);
			model2->setItem(rr, 3, item);

			item = new QStandardItem(loc.toString(temp_pobaruva, 'f', 2));
			item->setTextAlignment(Qt::AlignRight);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(4, 120);
			model2->setItem(rr, 4, item);

			saldo += (temp_pobaruva - temp_dolzi );

			item = new QStandardItem(loc.toString(saldo, 'f', 2));
			item->setTextAlignment(Qt::AlignRight);
			item->setEditable(false);
			ui.tableView_2->setRowHeight(rr, 18);
			ui.tableView_2->setColumnWidth(5, 120);
			model2->setItem(rr, 5, item);
	} 
	ui.tableView_2->show();
	ui.lineEdit_5->show();
	ui.lineEdit_6->show();
	ui.lineEdit_7->show();
	ui.label_8->show();
	ui.label_9->show();
	ui.label_10->show();
}
void QFinAnalitKomintentiWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QFinAnalitKomintentiWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QFinAnalitKomintentiWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}


void QFinAnalitKomintentiWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sFinAnalitKomintentiToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
	}

}

void QFinAnalitKomintentiWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QFinAnalitKomintentiWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 2) ? model->item(i, 2)->text():"";
    m_selectedTextNameSaldo = model->item(i, 5) ? model->item(i, 5)->text():"";
	ui.label_7->setText(trUtf8("Финансова Аналитика за коминтент: ") + m_selectedTextName);
	ui.lineEdit_7->setText(model->item(i, 3)->text());
	ui.lineEdit_6->setText(model->item(i, 4)->text());
	ui.lineEdit_5->setText(model->item(i, 5)->text());
	lista_detail(m_selectedText);
	
}

