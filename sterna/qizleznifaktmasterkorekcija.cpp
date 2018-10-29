#include "qizleznifaktmasterkorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>
#include "xx.h"



QIzleznifaktmasterKorekcija::QIzleznifaktmasterKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,selRow(-1)
    ,textId("")
    ,komintentID("")
    ,artikal_id(0)
    , pItemDelegate(0)
    , editorOpen(0)
	,lastColorNum(0)
	,m_fakturaNovaIspratnica(0)
	,m_nova_ispratnica(0)
	,m_ispratnicaMaxId(0)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
    ui.lineEdit->setFocus();
    ui.lineEdit->setText("");
    ui.lineEdit->setStyleSheet("background-color: yellow");
	getTableColumnWidths(16);
    ui.lineEdit_2->setText("");
    ui.lineEdit->installEventFilter(this);
    ui.lineEdit_2->installEventFilter(this);
    ui.lineEdit_3->installEventFilter(this);
    ui.lineEdit_4->installEventFilter(this);
    ui.lineEdit_5->installEventFilter(this);
    ui.lineEdit_7->installEventFilter(this);
	ui.dateTimeEdit->installEventFilter(this);

    connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_clicked()));
    connect(ui.lineEdit_2, SIGNAL(returnPressed()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui.lineEdit_3, SIGNAL(returnPressed()), this, SLOT(on_plineEdit3_Pressed()));
    connect(ui.lineEdit_4, SIGNAL(returnPressed()), this, SLOT(on_plineEdit4_Pressed()));
	connect(ui.lineEdit_7, SIGNAL(returnPressed()), this, SLOT(on_plineEdit7_Pressed()));
	connect(ui.lineEdit_8, SIGNAL(returnPressed()), this, SLOT(on_plineEdit8_Pressed()));

    pItemDelegate = new QSTableWidgetDelegate(ui.tableView);
    connect(this ,SIGNAL(editCell()),this,SLOT(openEditor()));
    connect(this ,SIGNAL(closeCell()),this,SLOT(closeEditor()));

    ui.tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.tableView->setItemDelegate(pItemDelegate);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));


	model = new QStandardItemModel(0,13);

	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена со ДДВ"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат %"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Цена со Рабат"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ %"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Износ"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("ДДВ Износ"));
	model->setHeaderData( 11, Qt::Horizontal, trUtf8("Износ со ДДВ"));
	model->setHeaderData( 12, Qt::Horizontal, trUtf8("Коминтент ID"));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
    header->show();
}

void QIzleznifaktmasterKorekcija::pressF9()
{
	on_pushButton_4_clicked();
}


QIzleznifaktmasterKorekcija::~QIzleznifaktmasterKorekcija()
{
	setTableColumnWidths(16);
}
void QIzleznifaktmasterKorekcija::pressEscape()
{
    if (ui.lineEdit_2->hasFocus())
    {
        ui.pushButton_4->setFocus();
        ui.pushButton_4->setChecked(true);
    }
    else
    {
        emit closeW();
    }
}
void QIzleznifaktmasterKorekcija::on_pushButton_clicked()
{
    CHelperClass hclass(this);
    if (!hclass.isKomintentExists(ui.lineEdit->text()))
    {
        emit scallKomintenti((QWidget*)this, ui.lineEdit->text());
    }
    else
    {
        ui.lineEdit_2->setFocus();
    }
}

void QIzleznifaktmasterKorekcija::on_pushButtonA_clicked()
{
	int stop = 0;
	emit scallfaktmaster((QWidget*)this, "");
}

void QIzleznifaktmasterKorekcija::setFocusLine()
{
    ui.lineEdit->setFocus();
}
void QIzleznifaktmasterKorekcija::setKomintent(QString text, QString textName)
{
    ui.lineEdit->setText(textName);
    komintentID = text;
	QSqlQuery query;
	query.prepare("select sifra from komintenti where id = :id");
	query.bindValue(":id", komintentID);	
	query.exec();
	query.next();
	ui.lineEdit_12->setText(query.value(0).toString());
}

void QIzleznifaktmasterKorekcija::setArtikli(QString text, QString textName, QString textKomintentId)
{
    ui.lineEdit_2->setText(textName);
    textId = text;
    artikal_id = text.toInt();
	artikal_komintent_id = textKomintentId;
	QSqlQuery query;
	query.prepare("select sifra from artikli where id = :id");
	query.bindValue(":id", artikal_id);	
	query.exec();
	query.next();
	ui.lineEdit_13->setText(query.value(0).toString());
}
void QIzleznifaktmasterKorekcija::setSaldo(QString text)
{
    ui.lineEdit_6->setText(text);
}

void QIzleznifaktmasterKorekcija::setProdCena(QString text)
{
	ui.lineEdit_3->setText(text);
	m_staraCena = text;
}

void QIzleznifaktmasterKorekcija::setNabCena(QString text)
{
	m_staraNabCena = text;
}


void QIzleznifaktmasterKorekcija::setFocusLine2()
{
    ui.lineEdit_2->setFocus();
}

void QIzleznifaktmasterKorekcija::on_pushButton_2_clicked()
{
    CHelperClass hclass(this);
    if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
    {
        emit scallArtikli((QWidget*)this, ui.lineEdit_2->text());
    }
    else
    {
        ui.lineEdit_4->setFocus();
    }
}

void QIzleznifaktmasterKorekcija::on_pushButton_3_clicked()
{
	CHelperClass hclass(this);
	if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Податокот за артикал е невалиден\nОдбери артикал од листата на артикли!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_2->setFocus();
		return;
	}

	QLocale loc;
	if(textId.toInt() == -1)
	{
		return;
	}

	//m_id = textId.toInt();

	QString temp = "select id, sifra, artikal, edm, ddv from artikli where id =";
	temp += textId;
	QSqlQuery query(temp);
	QString country1 = "";
	QString country2 = "";
	QString country3 = "";
	QString country4 = "";
	QString country5 = "";
	float cena = 0.f;
	float rabat = 0.f;
	float ddvp = 0.f;
	float kol = 0.f;

	while (query.next()) {
		country1 = query.value(query.record().indexOf("id")).toString();
		country2 = query.value(query.record().indexOf("sifra")).toString();
		country3 = query.value(query.record().indexOf("artikal")).toString();
		country4 = query.value(query.record().indexOf("edm")).toString();
		country5 = query.value(query.record().indexOf("ddv")).toString();

		//        ui.lineEdit->setText(country1);
	}

	int row = model->rowCount();

	QStandardItem *item = new QStandardItem(country1);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(0, 50);
	model->setItem(row, 0, item);

	item = new QStandardItem(country2);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, 50);
	model->setItem(row, 1, item);

	item = new QStandardItem(country3);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 2, item);

	kol = loc.toFloat(ui.lineEdit_4->text());
	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(ui.lineEdit_4->text())), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(6, 80);
	model->setItem(row, 3, item);

	item = new QStandardItem(country4);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 4, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(ui.lineEdit_3->text())), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 5, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(ui.lineEdit_7->text())), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 6, item);

	//	"icena * (1 - rabat/100), " //cena + rabat
	cena = loc.toFloat(ui.lineEdit_3->text());
	rabat = loc.toFloat(ui.lineEdit_7->text());

	item = new QStandardItem(loc.toString(hclass.rouded(cena * ( 1 - rabat / 100)), 'f', 2)); // cena +rabat
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 7, item);

	ddvp = loc.toFloat(country5);
	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(country5)), 'f', 2)); // ddv
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 8, item);

	//	"ikol * icena * (1 - rabat/100) / ( 1 + artikli.ddv / 100), " //износ без ддв
	item = new QStandardItem(loc.toString(hclass.rouded(kol *cena * ( 1 - rabat / 100) / (1 + ddvp /100)), 'f', 2)); // iznos
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 9, item);

	//	"ikol * icena * (1 - rabat/100) -  ikol * icena * (1 - rabat/100) / ( 1 + artikli.ddv / 100) , " //ddv
	item = new QStandardItem(loc.toString(hclass.rouded(kol *cena * ( 1 - rabat / 100) - kol *cena * (1 - rabat /100) / (1 + ddvp / 100)), 'f', 2)); // ddv iznos
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 10, item);

	//	"ikol * icena * (1 - rabat/100) " //iznos
	item = new QStandardItem(loc.toString(hclass.rouded(kol *cena * ( 1 - rabat / 100)), 'f', 2)); // iznos so ddv
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 11, item);


	item = new QStandardItem(loc.toString(artikal_komintent_id.toInt())); // komintent id
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 12, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	model->setItem(row, 13, item);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(13, 0);

	item = new QStandardItem(loc.toString(hclass.rouded(m_staraNabCena.toDouble()), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	model->setItem(row, 14, item);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(14, 0);

	item = new QStandardItem("0");
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	model->setItem(row, 15, item);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(15, 80);

	calculateIznosi();
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();

	ui.lineEdit_2->setText("");
	ui.lineEdit_3->setText("");
	ui.lineEdit_4->setText("");

	ui.lineEdit_6->setText("");
	ui.lineEdit_13->setText("");
	ui.lineEdit_2->setFocus();

	textId = "-1";
}

void QIzleznifaktmasterKorekcija::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    selRow = modelX.row();
    editorOpen = false;
    emit closeCell();
}

void QIzleznifaktmasterKorekcija::on_pushButton_6_clicked()
{
	QLocale loc;
	selRow = ui.tableView->currentIndex().row();
	if (selRow == -1)
	{
		return;
	}
	QString temp_ispratnicaID = model->item(selRow, 15)->text();
	float tempId = loc.toFloat(temp_ispratnicaID);
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Ставката ке биде избришана"));
		msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Cancel)
		{
			return;
		}
		model->removeRow(selRow);
		calculateIznosi();
}

void QIzleznifaktmasterKorekcija::pressReturn()
{
    if (ui.pushButton_3->hasFocus())
    {
        on_pushButton_3_clicked();
    }
    else if (ui.pushButton_6->hasFocus())
    {
        on_pushButton_6_clicked();
    }
    else if (ui.tableView->hasFocus())
    {
        if (editorOpen)
        {
            emit closeCell();
        }
        else
        {
            emit editCell();
        }
        editorOpen = !editorOpen;
    }
}
void QIzleznifaktmasterKorekcija::init(int id)
{
    CHelperClass chc(this);
	QLocale loc;
    if(id == -1)
    {
        return;
    }
    m_id = id;
    ui.lineEdit_5->setText(QString::number(id, 10));
    QString temp1 = 
        "select dokumenti.id, komintenti.id , komintenti.naziv, datum, dokumenti.rok, dokumenti.zabeleska, dokumenti.user_id, dokumenti.valuta_datum "
        "from dokumenti "
        "left join komintenti on dokumenti.komintent_id = komintenti.id "
        "where dokumenti.dok_tip = 40 and dokumenti.dok_id = ";        
    temp1 += QString::number(id, 10);
    QSqlQuery query1(temp1);
    while (query1.next())
    {
        ui.lineEdit->setText(query1.value(2).toString().isEmpty() ? "" : query1.value(2).toString());
        komintentID = query1.value(1).toString();
        dokumentID = query1.value(0).toString();
        QString a = query1.value(0).toString();
        ui.dateTimeEdit->setDate(query1.value(3).toDate());
        ui.lineEdit_8->setText(query1.value(4).toString());
        ui.textEdit->setPlainText(query1.value(5).toString());
		m_user_id = query1.value(6).toInt();
		ui.dateTimeEdit_2->setDate(query1.value(7).toDate());
    }
	
	QSqlQuery query2;
	query2.prepare("select sifra from komintenti where id = :id");
	query2.bindValue(":id", komintentID);	
	query2.exec();
	query2.next();
	ui.lineEdit_12->setText(query2.value(0).toString());

	int r = 0;
	int c = 16;
	int fieldNo[16];
	QString country[16];
	//int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 100, 70, 100, 100, 100, 100, 0, 0, 100};

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
		"ikol * prod_cena * (1 - rabat/100), komintent_id, stara_prod_cena, nab_cena, ispratnica_id " //iznos
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 40 and magacin.dok_id=       ";
	temp += QString::number(id, 10);;
	temp += "";
	QSqlQuery query(temp);

	model = new QStandardItemModel(r,c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат %"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Цена со Рабат"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ %"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Износ"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("ДДВ Износ"));
	model->setHeaderData( 11, Qt::Horizontal, trUtf8("Износ со ДДВ"));
	model->setHeaderData( 12, Qt::Horizontal, trUtf8("Коминтент ID"));
	model->setHeaderData( 15, Qt::Horizontal, trUtf8("Испратница ID"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	header->show();
	int row = 0;
	float sumaDDV = 0.f;
	int color1_old = 0;
	bool colorCurr = false;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;

			item = new QStandardItem("");
			int color1 = query.value(15).toInt();
			if (color1 > 0)
			{
				if (color1 != color1_old)
				{
					colorCurr = !colorCurr;							
				} 
			} 
			color1_old = color1;
			if (color1 > 0)
			{
				if (colorCurr)
				{
					item->setData(QBrush(QColor(140,255,255)), Qt::BackgroundColorRole);
				} 
				else
				{
					item->setData(QBrush(QColor(QColor(188,255,255))), Qt::BackgroundColorRole);
				}

			}

			QString temp = query.value(i).toString();
			if (((i < 15)&&(i > 4))||(i == 3))
			{
				
				item->setText(loc.toString(chc.rouded(temp.toDouble()), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				if (i == 11)
				{
					sumaDDV += temp.toFloat();
				}
			}
			else
			{
				item->setText(temp);
				item->setTextAlignment(Qt::AlignLeft);
				if (i == 15)
				{
					item->setTextAlignment(Qt::AlignRight);
				}
			}

			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			model->setItem(row, i, item);

			QMap<int, QString>::iterator itA = m_mapIspratnici.find(loc.toInt(query.value(15).toString()));
			if (itA == m_mapIspratnici.end())
			{
				m_mapIspratnici.insert(loc.toInt(query.value(15).toString()), query.value(15).toString());
			} 
		}
		row++;
	} 
	colorCurr = false;
	float tId_old = 0;
	for (int i = 0; i < model->rowCount(); i++)
	{
		QString temp_ispID = model->item(i, 15)->text();
		float tId = loc.toFloat(temp_ispID);

		if (tId_old != tId)
		{
			colorCurr = !colorCurr; 
		} 


		if (tId > 0)
		{
			if (colorCurr)
			{
				for(int j = 0; j <16; j++)
				{
					model->item(i, j)->setData(QBrush(QColor(140,255,255)), Qt::BackgroundColorRole);
				}
			} 
			else
			{
				for(int j = 0; j <16; j++)
				{
					model->item(i, j)->setData(QBrush(QColor(188,255,255)), Qt::BackgroundColorRole);
				}

			}
		}
		tId_old = tId;
	}

	
	calculateIznosi();
	ui.tableView->show();
    QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
	ui.tableView->setColumnHidden(0, true);
	ui.tableView->setColumnHidden(13, true);
	ui.tableView->setColumnHidden(14, true);

	ui.tableView->show();
    ui.lineEdit->setFocus();
}

void QIzleznifaktmasterKorekcija::on_pushButton_5_clicked()
{
    pressEscape();
}

void QIzleznifaktmasterKorekcija::on_pushButton_4_clicked()
{
	//-------------------------------------------------------------------------------------------------------------
	QLocale loc;
	QSqlQuery query;
	int row = model->rowCount();
	int rows = model->rowCount();
	for(int jj = 0; jj < model->rowCount(); jj++)
	{
		QMap<int, QString>::iterator itA = m_mapIspratniciNovi.find((int)loc.toFloat(model->item(jj, 15)->text()));
		if (itA == m_mapIspratniciNovi.end())
		{
			m_mapIspratniciNovi.insert((int)loc.toFloat(model->item(jj, 15)->text()), model->item(jj, 15)->text());
		} 
	}
	//-------------------------------------------------------------------------------------------------------------

	if (!validateKomintent())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Податокот за коминтент е невалиден\nОдбери коминтент од листата на коминтенти!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit->setFocus();
		return;
	}

	QMessageBox msgBox;
	msgBox.setText(trUtf8("ФАКТУРАТА ке биде КОРЕГИРАНА"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Cancel)
	{
		return;
	}

	
	QString temp = "select max(dok_id) from dokumenti where dok_tip = 60";
	QSqlQuery queryA(temp);
	QString country1 = "";
	int fieldNo = queryA.record().indexOf("max(dok_id)");
	while (queryA.next()) {
		m_ispratnicaMaxId = queryA.value(0).toInt() + 1;
	}


	//------------------brisi ispratnici-------------------------------------------------------------------------------------------

	
	QMap<int, QString>::iterator it;
	for(it = m_mapIspratnici.begin(); it != m_mapIspratnici.end(); it++)
	{
		// add delete ispratnica vo dokument
		QSqlQuery query2;
		QString ispra_id = loc.toString((int)(loc.toFloat(it.value())));

		query2.clear();
		query2.prepare( "delete from dokumenti where dok_tip = 60 and dok_id = :a");
		query2.bindValue(":a", ispra_id);	
		query2.exec();

		query2.clear();
		query2.prepare("delete from magacin where dok_tip = 60 and dok_id = :a1");
		query2.bindValue(":a1", ispra_id);	
		query2.exec();
	}

//	QMap<int, QString>::iterator it;
	for(it = m_mapIspratniciNovi.begin(); it != m_mapIspratniciNovi.end(); it++)
	{
		// add delete ispratnica vo dokument
		QSqlQuery query2;
		QString ispra_id = loc.toString((int)(loc.toFloat(it.value())));

		query2.clear();
		query2.prepare( "delete from dokumenti where dok_tip = 60 and dok_id = :a");
		query2.bindValue(":a", ispra_id);	
		query2.exec();

		query2.clear();
		query2.prepare("delete from magacin where dok_tip = 60 and dok_id = :a1");
		query2.bindValue(":a1", ispra_id);	
		query2.exec();
	}

	//-------------------vnesi samo novi stavki------------------------------------------------------------------------------------------
	
	m_fakturaNovaIspratnica = loc.toInt(ui.lineEdit_5->text());
	
	QMap<int, QString>::Iterator itBB = m_mapIspratniciNovi.find(0);
	if (itBB != m_mapIspratniciNovi.end())
	{
		vnesNovaiIspratnica();
	}

	koregirajFaktura();
	
	m_mapIspratniciNovi.clear();
	
	for(int jj = 0; jj < model->rowCount(); jj++)
	{
		QMap<int, QString>::iterator itA = m_mapIspratniciNovi.find((int)loc.toFloat(model->item(jj, 15)->text()));
		if (itA == m_mapIspratniciNovi.end())
		{
			m_mapIspratniciNovi.insert((int)loc.toFloat(model->item(jj, 15)->text()), model->item(jj, 15)->text());
		} 
	}

	//-----------------------------------------------------------------------------------------------------------------------------------
	
	QMap<int, QString>::iterator it1;
	QString faktura_ispratnica = ui.lineEdit_5->text();
	for(it1 = m_mapIspratniciNovi.begin(); it1 != m_mapIspratniciNovi.end(); it1++)
	{
		try
		{
			if (it1.key() == 0)
			{
				continue;
			}

			Singleton* ss = Singleton::Instance();
			QStringList info = ss->getUserInfo();
			int user_id = info.at(9).toInt();
			QLocale loc;
			QSqlQuery query;

			query.clear();
			query.prepare("insert into dokumenti(dok_id, dok_tip, datum, faktura_id, mag_id, komintent_id, rok, zabeleska, user_id, valuta_datum, faktura_ispratnica) values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11)");
			query.bindValue(":a1", it1.value());	
			query.bindValue(":a2", 60);	
			query.bindValue(":a3", ui.dateTimeEdit->date().toString("yyyy-MM-dd"));	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0);	
			query.bindValue(":a6", komintentID);	
			query.bindValue(":a7", ui.lineEdit_7->text());	
			query.bindValue(":a8", ui.textEdit->toPlainText());	
			query.bindValue(":a9", user_id);	
			query.bindValue(":a10", ui.dateTimeEdit_2->date().toString("yyyy-MM-dd"));
			query.bindValue(":a11", faktura_ispratnica);
			query.exec();

			query.clear();
			query.prepare("select max(id)mid from  dokumenti");
			query.exec();
		}
		catch (...)
		{
		}
	}



	try
	{
		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = model->item(i, 0)->text();
			QString mArtikalSifra = model->item(i, 1)->text();
			QString mArtikalNaziv = model->item(i, 2)->text();
			QString mArtikalKolicina = model->item(i, 3)->text();
			QString mArtikalEdm = model->item(i, 4)->text();
			QString mArtikalCena = model->item(i, 5)->text();
			QString mRabat = model->item(i, 6)->text();
			QString mArtikalItemKomintent = model->item(i, 12)->text();
			QString mArtikalStaraProdCena = model->item(i, 13)->text();
			QString mArtikalNabCena = model->item(i, 14)->text();
			QString mIspratnicaID = model->item(i, 15)->text();

			QLocale loc;


			QString mArtikalDDV = model->item(i, 8)->text();

			mRabat = mRabat.isEmpty() ? "0" : mRabat;

			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, prod_cena, rabat,komintent_id, stara_prod_cena,nab_cena) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11)"
				);

			query.bindValue(":a1", mIspratnicaID);	
			query.bindValue(":a2", 60);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", mArtikalCena);	
			query.bindValue(":a8", mRabat);	
			query.bindValue(":a9", mArtikalItemKomintent);	
			query.bindValue(":a10", mArtikalStaraProdCena);	
			query.bindValue(":a11", mArtikalNabCena);	
			query.exec();
			QSqlError err = query.lastError();
		}

	}
	catch (...)
	{
		
	}
	QMap<int, QString>::iterator it2;
	it2 = m_mapIspratniciNovi.find(0);
	if (it2 != m_mapIspratniciNovi.end())
	{
		//vnesNovaiIspratnica();
	}
	pressEscape();
}

void QIzleznifaktmasterKorekcija::koregirajFaktura()
{

	Singleton* ss = Singleton::Instance();
	QStringList info = ss->getUserInfo();
	int user_id = info.at(9).toInt();

	if ((user_id != 9999)&&(user_id != m_user_id))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Немате привилегија да ја направите измената!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit->setFocus();
		return;
	}
	int mmid = m_id;
	int cols = model->columnCount();
	int rows = model->rowCount();
	if (!rows)
	{
		return;
	}

	int mid=0;
	
	int m_id = 1;
	QString temp = "select max(dok_id) from dokumenti where dok_tip = 40";
	QSqlQuery query(temp);
	QString country1 = "";
	int fieldNo = query.record().indexOf("max(dok_id)");
	while (query.next()) 
	{
		m_id = query.value(0).toInt() + 1;
	}


	QSqlQuery query1;
	query1.clear();
	query1.prepare("update dokumenti set dok_id = :a0, datum=:a1, faktura_id=:a2, mag_id=:a3, komintent_id=:a4 , rok=:a5, zabeleska =:a6, valuta_datum =:a7 where id=:aid and dok_tip = 40");
	query1.bindValue(":a0", ui.lineEdit_5->text());	
	query1.bindValue(":a1", ui.dateTimeEdit->dateTime());	
	query1.bindValue(":a2", 0);	
	query1.bindValue(":a3", 0);	
	query1.bindValue(":a4", komintentID);	
	query1.bindValue(":aid", dokumentID);	
	query1.bindValue(":a5", ui.lineEdit_8->text());	
	query1.bindValue(":a6", ui.textEdit->toPlainText());	
	query1.bindValue(":a7", ui.dateTimeEdit_2->dateTime());

	query1.exec();
	QSqlError err = query1.lastError();

	query1.clear();
	query1.prepare(
		"delete from magacin where dok_tip = 40 and dok_id = :a"
		);
	query1.bindValue(":a", mmid);	
	query1.exec();
	try
	{
		QString temp = "select max(dok_id) from dokumenti where dok_tip = 40";
		QSqlQuery query;
		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = model->item(i, 0)->text();
			QString mArtikalSifra = model->item(i, 1)->text();
			QString mArtikalNaziv = model->item(i, 2)->text();
			QString mArtikalKolicina = model->item(i, 3)->text();
			QString mArtikalEdm = model->item(i, 4)->text();
			QString mArtikalCena = model->item(i, 5)->text();
			QString mArtikalRabat = model->item(i, 6)->text();
			QString mArtikalItemKomintent = model->item(i, 12)->text();
			QString mArtikalStaraProdCena = model->item(i, 13)->text();
			QString mArtikalNabCena = model->item(i, 14)->text();
			QString mAIspratnicaId = model->item(i, 15)->text();

			QLocale loc;
			float tempId = loc.toFloat(mAIspratnicaId);
			if (tempId == 0)
			{
				mAIspratnicaId = loc.toString(m_nova_ispratnica);
			}

			mArtikalRabat = mArtikalRabat.isEmpty() ? "0" : mArtikalRabat;
			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, prod_cena, rabat, komintent_id, stara_prod_cena, nab_cena, ispratnica_id) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8, :a9, :a10, :a11,:a12)"
				);
			query.bindValue(":a1", ui.lineEdit_5->text());	
			query.bindValue(":a2", 40);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", mArtikalCena);	
			query.bindValue(":a8", mArtikalRabat);	
			query.bindValue(":a9", mArtikalItemKomintent);	
			query.bindValue(":a10", mArtikalStaraProdCena);	
			query.bindValue(":a11", mArtikalNabCena);	
			query.bindValue(":a12", mAIspratnicaId);

			query.exec();
			QSqlError err = query.lastError();
		}

	}
	catch (...)
	{
	}

}
void QIzleznifaktmasterKorekcija::koregirajIspratnici(QString ispratnicaID)
{

}

void QIzleznifaktmasterKorekcija::vnesNovaiIspratnica()
{
	int cols = model->columnCount();
	int rows = model->rowCount();
	if (!rows)
	{
		return;
	}

	int mid=0;
	try
	{
		int m_id = 1;
 		QSqlQuery query;

		int row = model->rowCount();
		Singleton* ss = Singleton::Instance();
		QStringList info = ss->getUserInfo();
		int user_id = info.at(9).toInt();

		query.clear();
		query.prepare("insert into dokumenti(dok_id, dok_tip, datum, faktura_id, mag_id, komintent_id, rok, zabeleska, user_id, valuta_datum, faktura_ispratnica) values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11)");
		query.bindValue(":a1", m_ispratnicaMaxId);	
		query.bindValue(":a2", 60);	
		query.bindValue(":a3", ui.dateTimeEdit->date().toString("yyyy-MM-dd"));	
		query.bindValue(":a4", 0);	
		query.bindValue(":a5", 0);	
		query.bindValue(":a6", komintentID);	
		query.bindValue(":a7", ui.lineEdit_7->text());	
		query.bindValue(":a8", ui.textEdit->toPlainText());	
		query.bindValue(":a9", user_id);	
		query.bindValue(":a10", ui.dateTimeEdit_2->date().toString("yyyy-MM-dd"));
		query.bindValue(":a11", m_fakturaNovaIspratnica);
		query.exec();

		query.clear();
		query.prepare("select max(id)mid from  dokumenti");
		query.exec();

		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = model->item(i, 0)->text();
			QString mArtikalSifra = model->item(i, 1)->text();
			QString mArtikalNaziv = model->item(i, 2)->text();
			QString mArtikalKolicina = model->item(i, 3)->text();
			QString mArtikalEdm = model->item(i, 4)->text();
			QString mArtikalCena = model->item(i, 5)->text();
			QString mRabat = model->item(i, 6)->text();
			QString mArtikalItemKomintent = model->item(i, 12)->text();
			QString mArtikalStaraProdCena = model->item(i, 13)->text();
			QString mArtikalNabCena = model->item(i, 14)->text();
			QString mIspratnicaID = model->item(i, 15)->text();

			QLocale loc;
			float tempId = loc.toFloat(mIspratnicaID);
			if (tempId != 0)
			{
				continue;
			}

			QString mArtikalDDV = model->item(i, 8)->text();

			mRabat = mRabat.isEmpty() ? "0" : mRabat;

			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, prod_cena, rabat,komintent_id, stara_prod_cena,nab_cena) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10,:a11)"
				);

			query.bindValue(":a1", m_ispratnicaMaxId);	
			query.bindValue(":a2", 60);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", mArtikalCena);	
			query.bindValue(":a8", mRabat);	
			query.bindValue(":a9", mArtikalItemKomintent);	
			query.bindValue(":a10", mArtikalStaraProdCena);	
			query.bindValue(":a11", mArtikalNabCena);	
			query.exec();
			QSqlError err = query.lastError();
			m_nova_ispratnica = m_ispratnicaMaxId;
		}
	}
	catch (...)
	{
	}
}


bool QIzleznifaktmasterKorekcija::existDok(int idDok)
{
	int nCount = 0;
	QString temp = "select count(dok_id) br from dokumenti where dok_tip = 40 and dok_id =";
	temp += QString::number(idDok, 10);
	QSqlQuery query(temp);
	QString country1 = "";
	int fieldNo = query.record().indexOf("br");
	while (query.next()) {
		nCount = query.value(0).toInt() + 1;
	}
	return nCount > 0 ? true : false;
}

bool QIzleznifaktmasterKorekcija::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::FocusIn)
	{
		if (object == ui.lineEdit)
		{
			ui.lineEdit->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_2)
		{
			ui.lineEdit_2->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_3)
		{
			ui.lineEdit_3->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_4)
		{
			ui.lineEdit_4->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_7)
		{
			ui.lineEdit_7->setStyleSheet("background-color: yellow");
		}

		if (object == ui.dateTimeEdit)
		{
			ui.dateTimeEdit->setStyleSheet("background-color: yellow");
		}

	}
	if (event->type() == QEvent::FocusOut)
	{
		if (object == ui.lineEdit)
		{
			ui.lineEdit->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_2)
		{
			ui.lineEdit_2->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_3)
		{
			ui.lineEdit_3->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_4)
		{
			ui.lineEdit_4->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_7)
		{
			ui.lineEdit_7->setStyleSheet("background-color: none");
		}
		if (object == ui.dateTimeEdit)
		{
			ui.dateTimeEdit->setStyleSheet("background-color: none");
		}
	}

	return false;
}

void QIzleznifaktmasterKorekcija::on_plineEdit3_Pressed()
{
	ui.lineEdit_7->setFocus();
	ui.lineEdit_7->selectAll();
}
void QIzleznifaktmasterKorekcija::on_plineEdit4_Pressed()
{
	if (ui.lineEdit_4->text().isEmpty())
	{

		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси количина."));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_4->setFocus();
	}
	else
    {
        ui.lineEdit_3->setFocus();
		ui.lineEdit_3->selectAll();
    }
}

void QIzleznifaktmasterKorekcija::on_plineEdit7_Pressed()
{
	on_pushButton_3_clicked();
}

void QIzleznifaktmasterKorekcija::on_plineEdit8_Pressed()
{
	ui.dateTimeEdit->date();
	QDate valDate = ui.dateTimeEdit->date();
	int days = ui.lineEdit_8->text().toInt();
	valDate = valDate.addDays(days);
	ui.dateTimeEdit_2->setDate(valDate);
}

void QIzleznifaktmasterKorekcija::openEditor()
{
    //	tableView->closePersistentEditor(indexPrev);
    QModelIndex index;
    QModelIndexList indexes = ui.tableView->selectionModel()->selection().indexes();
    index = indexes.at(0);	// To get the row/column numbers use 
    if (index.column() > 2)
    {
        ui.tableView->openPersistentEditor(index);
    }
    indexPrev = index;
}

void QIzleznifaktmasterKorekcija::closeEditor()
{
    ui.tableView->closePersistentEditor(indexPrev);
	QLocale loc;
	CHelperClass chc(this);
	
	int row = indexPrev.row();
 	if ((row < model->rowCount())&&(row > -1))
 	{
		float kol = loc.toFloat(model->item(row, 3)->text());
		float cenaSoDDV = loc.toFloat(model->item(row, 5)->text());
		float rabat = loc.toFloat(model->item(row, 6)->text());
		float ddv = loc.toFloat(model->item(row, 8)->text());


		float cenaSoRabat = cenaSoDDV * (1 - rabat/100);
		float iznosBezDDV = kol * cenaSoDDV * (1 - rabat/100) / ( 1 + ddv / 100);  //износ без ддв
		float iznosDDV = kol * cenaSoDDV * (1 - rabat/100) -  kol * cenaSoDDV * (1 - rabat/100) / ( 1 + ddv / 100);
		float iznosSoDDV = kol * cenaSoDDV * (1 - rabat/100);

		model->item(row, 7)->setText(loc.toString(cenaSoRabat, 'f', 2));
		model->item(row, 9)->setText(loc.toString(iznosBezDDV, 'f', 2));
		model->item(row, 10)->setText(loc.toString(iznosDDV, 'f', 2));
		model->item(row, 11)->setText(loc.toString(iznosSoDDV, 'f', 2));
	}
	calculateIznosi();
}

bool QIzleznifaktmasterKorekcija::validateKomintent()
{
	bool stat = false;
	CHelperClass hclass(this);
	if (hclass.isKomintentExists(ui.lineEdit->text()))
	{
		stat = true;
	}
	return stat;
}

void QIzleznifaktmasterKorekcija::calculateIznosi()
{
	QLocale loc;
	CHelperClass chc(this);
	int rows = model->rowCount();
	float sumTempIznosbezDDV = 0.f;
	float sumTempDDV = 0.f;
	float sumTempIznossoDDV = 0.f;

	for (int i = 0; i < rows; i++)
	{
		sumTempIznosbezDDV += loc.toFloat(model->item(i, 9)->text());
		sumTempDDV += loc.toFloat(model->item(i, 10)->text());
		sumTempIznossoDDV += loc.toFloat(model->item(i, 11)->text());
	}
	ui.lineEdit_9->setText(loc.toString(chc.rouded(sumTempIznosbezDDV), 'f', 2));
	ui.lineEdit_10->setText(loc.toString(chc.rouded(sumTempDDV), 'f', 2));
	ui.lineEdit_11->setText(loc.toString(chc.rouded(sumTempIznossoDDV), 'f', 2));
}

void QIzleznifaktmasterKorekcija::setFakturi(QStringList& listData)
{
	sostavInfo a;
	QLocale loc;
	for(int i = 0; i< listData.count(); i++)
	{
		QStringList rowData = listData.at(i).split(" :: ");
		sostavInfo item;
		QString id = rowData.at(1).trimmed();
		int mid = loc.toInt(id);
		addItemFromIspratnicainit(mid, (lastColorNum+i)%2);
	}
	lastColorNum = lastColorNum + listData.count();
}
void QIzleznifaktmasterKorekcija::addItemFromIspratnicainit(int id, int color1)
{
	CHelperClass chc(this);
	QLocale loc;
	if(id == -1)
	{
		return;
	}
	int m_id = id;
	//ui.lineEdit_5->setText(QString::number(id, 10));
	QString temp1 = 
		"select dokumenti.id, komintenti.id , komintenti.naziv, datum, dokumenti.rok, dokumenti.zabeleska, dokumenti.user_id, dokumenti.valuta_datum "
		"from dokumenti "
		"left join komintenti on dokumenti.komintent_id = komintenti.id "
		"where dokumenti.dok_tip = 60 and dokumenti.dok_id = ";        
	temp1 += QString::number(id, 10);
	QSqlQuery query1(temp1);
	while (query1.next())
	{
		ui.lineEdit->setText(query1.value(2).toString().isEmpty() ? "" : query1.value(2).toString());
		komintentID = query1.value(1).toString();
		dokumentID = query1.value(0).toString();
		QString a = query1.value(0).toString();
		ui.dateTimeEdit->setDate(query1.value(3).toDate());
		//ui.lineEdit_8->setText(query1.value(4).toString());
		ui.textEdit->setPlainText(query1.value(5).toString());
		//m_user_id = query1.value(6).toInt();
		ui.dateTimeEdit_2->setDate(query1.value(7).toDate());
	}

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
		"ikol * prod_cena * (1 - rabat/100), komintent_id, stara_prod_cena, nab_cena , ispratnica_id " //iznos
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 60 and magacin.dok_id=       ";
	temp += QString::number(id, 10);;
	temp += "";
	int row = model->rowCount();
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
				item->setData(QBrush(QColor(140,255,255)), Qt::BackgroundColorRole);
			} 
			else
			{
				item->setData(QBrush(QColor(188,255,255)), Qt::BackgroundColorRole);
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

			model->setItem(row, i, item);
		}
		row++;
	} 
	calculateIznosi();
	ui.tableView->show();
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
	ui.lineEdit->setFocus();
}


void QIzleznifaktmasterKorekcija::setTableColumnWidths(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	s->setFakturaKorekcija_ColumnWidth(tempWidth);
}

void QIzleznifaktmasterKorekcija::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}

void QIzleznifaktmasterKorekcija::getTableColumnWidths(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getFakturaKorekcija_ColumnWidth();
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
