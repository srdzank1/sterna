#include "qizlezniIspratnicilista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>
#include <QDate>
#include <QMessageBox>
#include <QSqlError>
#include "xx.h"


QIzlezniIspratniciLista::QIzlezniIspratniciLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_row(0)
	,m_fakturaIspratnica(0)
	,statA(false)
	,statB(true)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	getTableColumnWidths(17);
	getTableColumnWidths_detail(12);

	modelAll = new QStandardItemModel(0,16);
	modelAll->clear();
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableView->setSortingEnabled(true);
	
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));
    connect(ui.lineEdit_7, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit7Pressed(const QString &)));
	
    lista("%%%",QDateTime::currentDateTime(), QDateTime::currentDateTime());
    m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
    lista_detail(m_selectedText);
	//ui.tableView->setSortingEnabled(true); 
	ui.pushButton->setEnabled(true);
	ui.pushButton_2->setEnabled(true);
	ui.pushButton_4->setEnabled(false);
	statA = true;
	statB = true;
	ui.pushButton_3->setEnabled(true);
    ui.tableView->setFocus();
}

QIzlezniIspratniciLista::~QIzlezniIspratniciLista()
{
	setTableColumnWidths(17);
	setTableColumnWidths_detail(12);
}

bool QIzlezniIspratniciLista::getStat()
{
	return statA;
}	

void QIzlezniIspratniciLista::setRow(int mrow)
{
	ui.tableView->selectRow(mrow);
}

int QIzlezniIspratniciLista::getRow()
{
	return m_row;
}

void QIzlezniIspratniciLista::pressEscape()
{
    emit closeW();
}

void QIzlezniIspratniciLista::pressReturn()
{
	if (ui.tableView->hasFocus())
	{
		emit sIspratniciToIzvod(m_listDataInfo);	
	}
}
void QIzlezniIspratniciLista::lista(const QString& nameSearch, QDateTime date1, QDateTime date2)
{
    QLocale loc;
	
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 17;
    int fieldNo[17];
    QString country[17];
//    int colWidth[] = {0, 80, 80, 170, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 100, 0, 100};

    QString temp = "";
	if (date1 == date2)
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, 0,0,0,0,0, zabeleska, komintenti.adresa, komintenti.grad, rok, komintenti.id, valuta_datum, komintenti.sifra, faktura_ispratnica "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 60 and komintenti.naziv like '"+ nameSearch +"'order by dok_id desc "
			;
	}
	else
	{
		temp = 
			"select dokumenti.id, dok_id, datum, komintenti.naziv, 0,0,0,0,0,zabeleska,komintenti.adresa, komintenti.grad, rok, komintenti.id, valuta_datum, komintenti.sifra, faktura_ispratnica "
			"from dokumenti "
			"left join komintenti on dokumenti.komintent_id = komintenti.id "
			"where dok_tip = 60 and (datum between #"+ date1.toString("yyyy/MM/dd") +"# and #"+ date2.toString("yyyy/MM/dd") +"# ) and komintenti.naziv like '"+ nameSearch +"'order by dok_id desc "
			;
	}
    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id.\n"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Испратница\nброј"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум\n"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Коминтенти\n"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Износ \nбез ДДВ"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("ДДВ Износ\n"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Вкупен Износ\n со ДДВ"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Платено\n"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Останато \nза плаќање"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Забелешка\n"));
	model->setHeaderData( 14, Qt::Horizontal, trUtf8("Валута\n"));
	model->setHeaderData( 16, Qt::Horizontal, trUtf8("Фактура\n"));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
    CHelperClass chc(this);
    QString tip = "60";
    chc.createStatusMap(tip); 
    chc.createListaIzlezniFakturiIznosi(tip);
    chc.createListaKomintenti(tip);
	chc.createPovratnicaFakturiIznosi();

	chc.getFakturaIznosiAll(tip);
	
	float mIznos = 0.0f;
	float mDDV = 0.0f;
	float mVkupno = 0.0f;
	float mVPlateno = 0.0f;
	float mVOstanato = 0.0f;
	Singleton *s = Singleton::Instance();
	s->m_listFakturiS.clear();
	Singleton::tinfoFakturi itemInfo;

	setUpdatesEnabled(false);
    while (query.next()) 
    {
		itemInfo.fakturaData = query.value(2).toDateTime(); //2
		itemInfo.fakturaValuta = query.value(14).toDateTime(); //2
		itemInfo.komintent_naziv = query.value(3).toString(); //3
		//itemInfo.fakturaValuta = ; 
		itemInfo.iznos = query.value(4).toFloat(); //4
		//itemInfo.plateno = ; //7
		//itemInfo.komintent_id = ; 

		for (int i = 0; i < c; i++)
        {
			QStandardItem *item = new QStandardItem(query.value(i).toString());
            if ((i == 1))
            {
				if (query.value(16).toInt() > 0)
				{
					QIcon ic1(":/sterna/Resources/ok.png");
					item->setIcon(ic1);
					item->setToolTip(trUtf8("Фактурирана"));
				}
				else 
				{
					QIcon ic1(":/sterna/Resources/stop.png");
					item->setIcon(ic1);
					item->setToolTip(trUtf8("Испратницата не е фактурирана "));
				}

                item->setTextAlignment(Qt::AlignLeft);
            }

			if ((i == 2))
			{
				item = new QStandardItem(query.value(i).toString().left(10));
				item->setTextAlignment(Qt::AlignLeft);
			}
            if ((i == 3))
            {
                QString info = chc.getKomintentDetail(query.value(i).toString());
                item->setToolTip(info);
            }
            		
            if ((i == 4))
            { 
                float tempIznos = chc.getFakturaIznos(query.value(1).toString());
                mIznos += tempIznos;
                item = new QStandardItem(loc.toString(chc.rouded(tempIznos),'f',2));
                item->setTextAlignment(Qt::AlignRight);
            }
            if ((i == 5))
            {
                float tempDDV = chc.getFakturaDDV(query.value(1).toString());
                mDDV += tempDDV;
                item = new QStandardItem(loc.toString(chc.rouded(tempDDV),'f',2));
                item->setTextAlignment(Qt::AlignRight);
            }
            if ((i == 6))
            {
                float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
                mVkupno += tempVkupen;
                item = new QStandardItem(loc.toString(chc.rouded(tempVkupen),'f',2));
                item->setTextAlignment(Qt::AlignRight);
            }
			if ((i == 7))
			{
				float tempPlatenIznos = chc.getFakturaPrilivIznos(query.value(1).toString());
				float tempVratenIznos = chc.getPovratnicaFakturaVkupno(query.value(1).toString());

				mVPlateno += tempPlatenIznos;
				mVPlateno += tempVratenIznos;
				item = new QStandardItem(loc.toString(chc.rouded(tempPlatenIznos + tempVratenIznos),'f',2));
				item->setTextAlignment(Qt::AlignRight);
			}
			if ((i == 8))
			{
				QString idd = query.value(1).toString();
				float tempVkupen = chc.getFakturaVkupno(query.value(1).toString());
				float tempPlatenIznos = chc.getFakturaPrilivIznos(query.value(1).toString());
				float tempVratenIznos = chc.getPovratnicaFakturaVkupno(query.value(1).toString());
				mVOstanato += (tempVkupen - tempPlatenIznos - tempVratenIznos); 
				item = new QStandardItem(loc.toString(chc.rouded(tempVkupen - tempPlatenIznos - tempVratenIznos), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				itemInfo.iznos = tempVkupen; //4
				itemInfo.plateno = tempPlatenIznos + tempVratenIznos; //7
			}
			if ((i == 14))
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
			if ((i == 16))
			{
				item->setTextAlignment(Qt::AlignRight);
			}
            item->setEditable(false);
            ui.tableView->setRowHeight(row, 18);
            ui.tableView->setColumnWidth(i, colWidth[i]);
            item->setEditable(false);
            model->setItem(row, i, item);
        }
        row++;
		s->m_listFakturiS.push_back(itemInfo);
    } 
	setUpdatesEnabled(true);
	QString info = trUtf8("       Вкупен Износ : ") + loc.toString(chc.rouded(mIznos),'f',2) + trUtf8(" ден.") + 
		trUtf8("       Вкупен ДДВ : ") + loc.toString(chc.rouded(mDDV),'f',2) + trUtf8(" ден.") +
		trUtf8("       Вкупен Износ со ДДВ: ") + loc.toString(chc.rouded(mVkupno),'f',2) + trUtf8(" ден.") ;
	QString info2 = trUtf8("       Платено : ") + loc.toString(chc.rouded(mVPlateno),'f',2) + trUtf8(" ден.") + 
		trUtf8("       Останато за плаќање : ") + loc.toString(chc.rouded(mVOstanato),'f',2) + trUtf8(" ден.") ;

// 	ui.label_11->setText(info);
// 	ui.label_12->setText(info2);

    QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
	ui.tableView->setColumnHidden(0, true);
	ui.tableView->setColumnHidden(7, true);
	ui.tableView->setColumnHidden(8, true);
	ui.tableView->setColumnHidden(9, true);
	ui.tableView->setColumnHidden(10, true);
	ui.tableView->setColumnHidden(11, true);
	ui.tableView->setColumnHidden(12, true);
	ui.tableView->setColumnHidden(13, true);
	ui.tableView->setColumnHidden(15, true);
    ui.tableView->show();
}

void QIzlezniIspratniciLista::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}

void QIzlezniIspratniciLista::procSectionResized_detail(int a, int b, int c)
{
	colWidth_detail[a] = c;
}


void QIzlezniIspratniciLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = ui.tableView->currentIndex().row();
	m_row = ui.tableView->currentIndex().row();
    m_selectedText = model->item(i, 1) ? model->item(i, 1)->text():"";
    m_fakturaBr = model->item(i, 1)->text();
    m_fakturadatum = model->item(i, 2)->text();
    m_komintent_naziv =  model->item(i, 3)->text();
    m_komintent_adresa =  model->item(i, 10)->text();
    m_komintent_grad =  model->item(i, 11)->text();
    m_rok =  model->item(i, 12)->text();
	ui.label->setText(trUtf8("Фактура бр:") + m_selectedText + 
		trUtf8(" - Шифра: ") + model->item(i, 15)->text() + 
		trUtf8(" - Коминтент: ") + m_komintent_naziv);
	m_komintentIDAll = model->item(i, 13)->text(); 
	ui.lineEdit_6->setText(model->item(i, 6)->text());
	ui.lineEdit_8->setText(model->item(i, 7)->text());
	ui.lineEdit_9->setText(model->item(i, 8)->text());
	QString faktura_ispratnica = model->item(i, 16)->text();

	if (faktura_ispratnica == "0")
	{
		statB = true;
		ui.pushButton_2->setEnabled(statB);
	} 
	else
	{
		statB = false;
		ui.pushButton_2->setEnabled(statB);
	}
    lista_detail(m_selectedText);

	
}
void QIzlezniIspratniciLista::lista_detail(const QString& nameSearch)
{
    QLocale loc;
	CHelperClass chc(this);
    if (nameSearch.length() < 0)
    {
        ui.tableView_2->hide();
        return;
    }

    int r = 0;
    int c = 12;
    int fieldNo[12];
    QString country[12];
//    int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 100, 70, 100, 100, 100};
    QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznos", "iznosddv", "vkupeniznos"};
    QString temp = 
        "select "
		"artikli.id, " 
		"sifra, "
		"artikal, "
		"ikol, "
		"edm, "
		"prod_cena ," //prod_cena (so ddv)
		"rabat, " 
		"prod_cena * (1 - rabat/100), " //cena + rabat
		"artikli.ddv, " //ddv
		"ikol * prod_cena * (1 - rabat/100) / ( 1 + artikli.ddv / 100), " //износ без ддв
		"ikol * prod_cena * (1 - rabat/100) -  ikol * prod_cena * (1 - rabat/100) / ( 1 + artikli.ddv / 100) , " //ddv
		"ikol * prod_cena * (1 - rabat/100) " //iznos
		"from magacin                                         "
        "left join artikli on magacin.artikal_id = artikli.id "
        "where magacin.dok_tip = 60 and magacin.dok_id=       ";
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
                item = new QStandardItem(loc.toString(chc.rouded(temp.toDouble()), 'f', 2));
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
            ui.tableView_2->setColumnWidth(i, colWidth_detail[i]);
            model2->setItem(row, i, item);
        }
        row++;
    } 
// 	ui.lineEdit_6->setText(loc.toString(sumaDDV, 'f', 2));
// 	CHelperClass chc(this);
// 	QString tip = "60";
// 	chc.getFakturaPlatenIznos(m_selectedText, tip);
// 	ui.lineEdit_8->setText(loc.toString(chc.getPlatenIznos(), 'f', 2));
// 	ui.lineEdit_9->setText(loc.toString(sumaDDV - chc.getPlatenIznos(), 'f', 2));
	connect(header2, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized_detail(int, int, int)));
	ui.tableView_2->setColumnHidden(0, true);
;
    ui.tableView_2->show();
}

void QIzlezniIspratniciLista::deleteDok(int idDok)
{
    QSqlQuery query;
    query.clear();
    query.prepare(
        "delete from magacin where dok_tip = 60 and dok_id = :a"
        );
    query.bindValue(":a", idDok);	
    query.exec();
}
void QIzlezniIspratniciLista::on_pushButton_clicked()
{
    emit procF2();
}
void QIzlezniIspratniciLista::on_pushButton_2_clicked()
{
    emit procF3();
}

QStringList QIzlezniIspratniciLista::geInfo()
{
    QStringList info;
    info.clear();
    info << m_komintent_naziv << m_komintent_adresa << m_komintent_grad << m_fakturadatum << m_fakturaBr << m_rok;
    return info;
}

void QIzlezniIspratniciLista::setInitText(QString text, QDateTime &date1, QDateTime &date2)
{
    ui.tableView->setSelectionMode(QAbstractItemView::MultiSelection); 
	ui.label_4->setText(trUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Испратници - Листа</span></p></body></html>"));
	ui.tableView->setFocus();
	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(calcSelectedItems()));
	ui.lineEdit_7->setText(text);
	lista(text + "%", date1, date2);
	ui.pushButton->setEnabled(false);
	ui.pushButton_2->setEnabled(false);
	statA = false;
	statB = false;
	ui.pushButton_3->setEnabled(true);
}         

void QIzlezniIspratniciLista::setInitTextIspratnici(QString text, QDateTime &date1, QDateTime &date2)
{
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection); 
	ui.label_4->setText(trUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">Испратници - Листа</span></p></body></html>"));
	ui.tableView->setFocus();
	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(calcSelectedItems()));

	ui.lineEdit_7->setText(text);
	lista(text + "%", date1, date2);

}

void QIzlezniIspratniciLista::lineEdit7Pressed(const QString & text)
{
    lista(text + "%", QDateTime::currentDateTime(), QDateTime::currentDateTime());
}

void QIzlezniIspratniciLista::calcSelectedItems()
{
	QLocale loc;
	QModelIndexList itemSelection = ui.tableView->selectionModel()->selectedRows();
	m_listDataInfo.clear();
	float mIznos = 0.f;
	if (itemSelection.count())
	{
		ui.pushButton_4->setEnabled(true);	
	}
	else
	{
		ui.pushButton_4->setEnabled(false);
	}

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
		itemData += "60  ::  ";
		if (model->item(itemSelection.at(i).row(), 16)->text() == "0")
		{
			m_listDataInfo << itemData;
		}

		int stop = 0;
	}
	CHelperClass chc(this);
	QString info = trUtf8("       Вкупен износ во селектираните испратници е : ") + loc.toString(chc.rouded(mIznos),'f',2) + trUtf8(" ден.");
//	ui.label_13->setText(info);
	
	if(m_listDataInfo.count())
	{
		ui.pushButton_4->setEnabled(true);
	}
	else
	{
		ui.pushButton_4->setEnabled(false);
	}
}

bool QIzlezniIspratniciLista::isButtonChecked()
{
	return ui.radioButton->isChecked();
}

void QIzlezniIspratniciLista::on_pushButton_3_clicked()
{
	emit callSearchForm();
}

void QIzlezniIspratniciLista::on_pushButton_4_clicked()
{
	
	ui.pushButton_3->setEnabled(false);

	QMessageBox msgBox;
	msgBox.setText(trUtf8("ФАКТУРАТА ке биде ВНЕСЕНА"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Cancel)
	{
		return;
	}
	modelAll->clear();
	
	sostavInfo a;
	QLocale loc;
	for(int i = 0; i< m_listDataInfo.count(); i++)
	{
		QStringList rowData = m_listDataInfo.at(i).split(" :: ");
		sostavInfo item;
		QString id = rowData.at(1).trimmed();
		int mid = loc.toInt(id);
		addItemFromIspratnicainit(mid, 0);
	}
	vnesiFaktura();
	updateIspratnicaFaktura(m_listDataInfo);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	lista("%%%",QDateTime::currentDateTime(), QDateTime::currentDateTime());
	ui.pushButton->setEnabled(true);
	ui.pushButton_2->setEnabled(true);
	ui.pushButton_3->setEnabled(true);
	ui.pushButton_4->setEnabled(false);

	statA = true;
	statB = true;
	ui.pushButton_3->setEnabled(true);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void QIzlezniIspratniciLista::updateIspratnicaFaktura(QStringList listA)
{
	QLocale loc;
	for(int i = 0; i< listA.count(); i++)
	{
		QStringList rowData = m_listDataInfo.at(i).split(" :: ");
		sostavInfo item;
		QString id = rowData.at(1).trimmed();
		int mid = loc.toInt(id); // ispratnica
		
		
		QSqlQuery query1;
		query1.clear();
		query1.prepare("update dokumenti set faktura_ispratnica = :a0 where dok_id=:aid and dok_tip = 60");
		query1.bindValue(":a0", m_fakturaIspratnica);	
		query1.bindValue(":aid", mid);	
		query1.exec();
		QSqlError err = query1.lastError();
	}
}

void QIzlezniIspratniciLista::addItemFromIspratnicainit(int id, int color1)
{
	CHelperClass chc(this);
	QLocale loc;


	int r = 0;
	int c = 16;
	int fieldNo[16];
	QString country[16];
	int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 100, 70, 100, 100, 100, 100, 0, 0, 100};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznos", "iznosddv", "vkupeniznos"};
	QString temp = 
		"select "
		"artikli.id, " 
		"sifra, "
		"artikal, "
		"ikol, "
		"edm, "
		"prod_cena ," //prod_cena (so ddv)
		"rabat, " 
		"prod_cena * (1 - rabat/100), " //cena + rabat
		"artikli.ddv, " //ddv
		"ikol * prod_cena * (1 - rabat/100) / ( 1 + artikli.ddv / 100), " //износ без ддв
		"ikol * prod_cena * (1 - rabat/100) -  ikol * prod_cena * (1 - rabat/100) / ( 1 + artikli.ddv / 100) , " //ddv
		"ikol * prod_cena * (1 - rabat/100), komintent_id, stara_prod_cena, nab_cena, 0 " //iznos
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 60 and magacin.dok_id=       ";
	temp += QString::number(id, 10);;
	temp += "";
	int row = modelAll->rowCount();
	float sumaDDV = 0.f;
	QSqlQuery query(temp);
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();
			item = new QStandardItem();
			QBrush brushColor;
			if (color1)
			{
				item->setData(QBrush(QColor(Qt::green)), Qt::BackgroundColorRole);
			} 
			else
			{
				item->setData(QBrush(QColor(Qt::yellow)), Qt::BackgroundColorRole);
			}

			if ((i > 4)||(i == 3))
			{
				item ->setText(loc.toString(chc.rouded(temp.toDouble()), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				if (i == 11)
				{
					sumaDDV += temp.toFloat();
				}
				else if (i == 15)
				{
					item->setText(loc.toString(id));
					item->setTextAlignment(Qt::AlignRight);
				}
			}
			else
			{
				item->setText(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}

			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);

			modelAll->setItem(row, i, item);
		}
		row++;
	} 
}

void QIzlezniIspratniciLista::vnesiFaktura()
{


	int cols = modelAll->columnCount();
	int rows = modelAll->rowCount();
	if (!rows)
	{
		return;
	}

	int mid=0;
	try
	{
		int m_id = 1;
		QString temp = "select max(dok_id) from dokumenti where dok_tip = 40";
		QSqlQuery query(temp);
		QString country1 = "";
		int fieldNo = query.record().indexOf("max(dok_id)");
		while (query.next()) {
			m_id = query.value(0).toInt() + 1;
		}

		int row = modelAll->rowCount();
		Singleton* ss = Singleton::Instance();
		QStringList info = ss->getUserInfo();
		int user_id = info.at(9).toInt();
		
		QDate DateA = QDate::currentDate();
		QDate DateB = DateA.addDays(8);

		int komintentID = m_komintentIDAll.toInt();
		m_fakturaIspratnica = m_id;
		query.clear();
		query.prepare("insert into dokumenti(dok_id, dok_tip, datum, faktura_id, mag_id, komintent_id, rok, zabeleska, user_id, valuta_datum) values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10)");
		query.bindValue(":a1", m_id);	
		query.bindValue(":a2", 40);	
		query.bindValue(":a3", DateA.toString("yyyy-MM-dd"));	
		query.bindValue(":a4", 0);	
		query.bindValue(":a5", 0);	
		query.bindValue(":a6", komintentID);	
		query.bindValue(":a7", "8");	
		query.bindValue(":a8", "");	
		query.bindValue(":a9", user_id);	
		query.bindValue(":a10", DateB.toString("yyyy-MM-dd"));
		query.exec();

		query.clear();
		query.prepare("select max(id)mid from  dokumenti");
		query.exec();

		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = modelAll->item(i, 0)->text();
			QString mArtikalSifra = modelAll->item(i, 1)->text();
			QString mArtikalNaziv = modelAll->item(i, 2)->text();
			QString mArtikalKolicina = modelAll->item(i, 3)->text();
			QString mArtikalEdm = modelAll->item(i, 4)->text();
			QString mArtikalCena = modelAll->item(i, 5)->text();
			QString mRabat = modelAll->item(i, 6)->text();
			QString mArtikalItemKomintent = modelAll->item(i, 12)->text();
			QString mArtikalStaraProdCena = modelAll->item(i, 13)->text();
			QString mArtikalNabCena = modelAll->item(i, 14)->text();
			QString mIspratnicaID = modelAll->item(i, 15)->text();

			QString mArtikalDDV = modelAll->item(i, 8)->text();

			mRabat = mRabat.isEmpty() ? "0" : mRabat;
			QLocale loc;

			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, prod_cena, rabat,komintent_id, stara_prod_cena,nab_cena, ispratnica_id) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11,:a12)"
				);

			query.bindValue(":a1", m_id);	
			query.bindValue(":a2", 40);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", mArtikalCena);	
			query.bindValue(":a8", mRabat);	
			query.bindValue(":a9", mArtikalItemKomintent);	
			query.bindValue(":a10", mArtikalStaraProdCena);	
			query.bindValue(":a11", mArtikalNabCena);	
			query.bindValue(":a12", mIspratnicaID);	

			query.exec();
			QSqlError err = query.lastError();
		}
		ui.pushButton->setEnabled(true);
		ui.pushButton_2->setEnabled(true);
		statA = true;
		statB = true;
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Фактурата е успешно внесена."));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
	catch (...)
	{
		ui.pushButton_2->setEnabled(false);

		QMessageBox msgBox;
		msgBox.setText(trUtf8("Фактурата не е внесена !!!."));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
}


void QIzlezniIspratniciLista::setTableColumnWidths(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	s->setIspratnica_ColumnWidth(tempWidth);
}

void QIzlezniIspratniciLista::getTableColumnWidths(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getIspratnica_ColumnWidth();
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
}

void QIzlezniIspratniciLista::setTableColumnWidths_detail(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView_2->columnWidth(i), 10);
	}
	s->setIspratnica_Detail_ColumnWidth(tempWidth);
}

void QIzlezniIspratniciLista::getTableColumnWidths_detail(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getIspratnica_Detail_ColumnWidth();
	if (sss.count() == ccolumn)
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth_detail[i1] = loc.toInt(sss.at(i1));
		}
	}
	else
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth_detail[i1] = 100;
		}
	}
}
