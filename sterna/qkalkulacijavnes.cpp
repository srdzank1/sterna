#include "qKalkulacijavnes.h"
#include <QItemSelectionModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>
#include "chelperclass.h"
#include <QDesktopWidget>
#include "xx.h"


QKalkulacijaVnes::QKalkulacijaVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,selRow(-1)
	,textId("")
    ,komintentID("")
    ,artikal_id(0)
	,m_i(0)
	,m_sumaIznosStavki(0)
	,m_sumaTrosoci(0)
	,isKomintent(true)
	,mm_prodCenaSoDDV(0)
	,mm_marzaProcent(0)

{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

	ui.lineEdit->setFocus();

	ui.lineEdit->setText("");
	ui.lineEdit->selectAll();
	ui.lineEdit_2->setText("");


	ui.lineEdit->setStyleSheet("background-color: yellow");
	ui.lineEdit->installEventFilter(this);

	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_3->installEventFilter(this);
	ui.lineEdit_4->installEventFilter(this);
	ui.lineEdit_14->installEventFilter(this);
	ui.lineEdit_15->installEventFilter(this);
	ui.lineEdit_17->installEventFilter(this);
	ui.lineEdit_21->installEventFilter(this);
	ui.lineEdit_23->installEventFilter(this);
    ui.dateTimeEdit->installEventFilter(this);
    ui.dateTimeEdit_2->installEventFilter(this);
    ui.dateTimeEdit_4->installEventFilter(this);
	ui.comboBox_2->installEventFilter(this);
	ui.lineEdit_5->installEventFilter(this);
	ui.lineEdit_16->installEventFilter(this);
	getTableColumnWidths(17);
	colWidth[0]= 0;
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton1_clicked()));
	connect(ui.lineEdit_14, SIGNAL(returnPressed()), this, SLOT(on_pushButton14_clicked()));
	connect(ui.comboBox_2->lineEdit(), SIGNAL(returnPressed()), this, SLOT(on_comboBox2_clicked()));
	connect(ui.dateTimeEdit_2, SIGNAL(editingFinished()), this, SLOT(on_dateTimeEdit2_clicked()));
	connect(ui.dateTimeEdit_4, SIGNAL(editingFinished()), this, SLOT(on_dateTimeEdit4_clicked()));
	connect(ui.lineEdit_5, SIGNAL(returnPressed()), this, SLOT(on_lineEdit5_clicked()));
	connect(ui.lineEdit_16, SIGNAL(returnPressed()), this, SLOT(on_lineEdit16_clicked()));


	connect(ui.lineEdit_2, SIGNAL(returnPressed()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui.lineEdit_3, SIGNAL(returnPressed()), this, SLOT(on_plineEdit3_Pressed()));
    connect(ui.lineEdit_4, SIGNAL(returnPressed()), this, SLOT(on_plineEdit4_Pressed()));
	connect(ui.lineEdit_15, SIGNAL(returnPressed()), this, SLOT(on_plineEdit15_Pressed()));
	connect(ui.lineEdit_17, SIGNAL(returnPressed()), this, SLOT(on_plineEdit17_Pressed()));
	connect(ui.lineEdit_23, SIGNAL(returnPressed()), this, SLOT(on_plineEdit23_Pressed()));
	
	connect(ui.lineEdit_23, SIGNAL(returnPressed()), this, SLOT(on_plineEdit23_Pressed()));
	connect(ui.lineEdit_23, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit23_TextChanged(const QString &)));

	connect(ui.lineEdit_18, SIGNAL(returnPressed()), this, SLOT(on_plineEdit18_Pressed()));
	connect(ui.lineEdit_19, SIGNAL(returnPressed()), this, SLOT(on_plineEdit19_Pressed()));
	connect(ui.lineEdit_21, SIGNAL(returnPressed()), this, SLOT(on_plineEdit21_Pressed()));
	connect(ui.lineEdit_21, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit21_TextChanged(const QString &)));

	connect(ui.lineEdit_24, SIGNAL(returnPressed()), this, SLOT(on_plineEdit24_Pressed()));

	connect(ui.lineEdit_5, SIGNAL(editingFinished()), this, SLOT(updateModelData()));
	connect(ui.lineEdit_6, SIGNAL(editingFinished()), this, SLOT(updateModelData()));
	connect(ui.lineEdit_7, SIGNAL(editingFinished()), this, SLOT(updateModelData()));
	connect(ui.lineEdit_8, SIGNAL(editingFinished()), this, SLOT(updateModelData()));
	connect(ui.lineEdit_9, SIGNAL(editingFinished()), this, SLOT(updateModelData()));

	connect(ui.lineEdit_13, SIGNAL(returnPressed()), this, SLOT(on_pushButton1_prevoznik()));

	ui.dateTimeEdit->setDate(QDate::currentDate());
	ui.dateTimeEdit_2->setDate(QDate::currentDate());
	ui.dateTimeEdit_3->setDate(QDate::currentDate());
	ui.dateTimeEdit_4->setDate(QDate::currentDate());
	pItemDelegate = new QSTableWidgetDelegate(ui.tableView);
	connect(this ,SIGNAL(editCell()),this,SLOT(openEditor()));
	connect(this ,SIGNAL(closeCell()),this,SLOT(closeEditor()));

    ui.tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.tableView->setItemDelegate(pItemDelegate);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	model = new QStandardItemModel(0, 17);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид.\n"));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра\n"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал\n"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Ед.\nме."));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Количина\n"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Набавна цена\nбез ДДВ"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Пренесен\nДДВ (%)"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Вредност\n на ДДВ"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Набавна цена\nсо ДДВ"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Рабат\n(%)"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("Вкупен Набавен\nизнос со ДДВ"));
	model->setHeaderData( 11, Qt::Horizontal, trUtf8("Maржа\n(%)"));
	model->setHeaderData( 12, Qt::Horizontal, trUtf8("Маржа\n(ден.)"));
	model->setHeaderData( 13, Qt::Horizontal, trUtf8("Продажна цена\nбез ДДВ"));
	model->setHeaderData( 14, Qt::Horizontal, trUtf8("Пресметан\nДДВ"));
	model->setHeaderData( 15, Qt::Horizontal, trUtf8("Продaжна цена\nсо ДДВ"));
	model->setHeaderData( 16, Qt::Horizontal, trUtf8("Вкупен продажен\nизнос со ДДВ"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	header->show();
}

QKalkulacijaVnes::~QKalkulacijaVnes()
{
	setTableColumnWidths(17);
}

void QKalkulacijaVnes::on_pushButton14_clicked()
{
	ui.comboBox_2->setFocus();
}
void QKalkulacijaVnes::on_comboBox2_clicked()
{
	ui.dateTimeEdit_2->setFocus();
}
void QKalkulacijaVnes::on_dateTimeEdit2_clicked()
{
	ui.dateTimeEdit_4->setFocus();
	ui.dateTimeEdit_4->selectAll();
}

void QKalkulacijaVnes::on_dateTimeEdit4_clicked()
{
	ui.lineEdit_5->setFocus();
	ui.lineEdit_5->selectAll();
}

void QKalkulacijaVnes::on_lineEdit5_clicked()
{
	ui.lineEdit_16->setFocus();
	ui.lineEdit_16->selectAll();
}
void QKalkulacijaVnes::on_lineEdit16_clicked()
{
	ui.lineEdit_2->setFocus();
	ui.lineEdit_2->selectAll();
}

void QKalkulacijaVnes::on_pushButton1_clicked()
{
	isKomintent = true;
	CHelperClass hclass(this);
	if (!hclass.isKomintentExists(ui.lineEdit->text()))
	{
		emit scallKomintenti((QWidget*)this, ui.lineEdit->text());
	}
	else
	{
		ui.lineEdit_14->setFocus();
		ui.lineEdit_14->selectAll();
	}
}

void QKalkulacijaVnes::on_pushButton1_prevoznik()
{
	isKomintent = false;
	CHelperClass hclass(this);
	if (!hclass.isKomintentExists(ui.lineEdit_13->text()))
	{
		emit scallKomintenti((QWidget*)this, ui.lineEdit_13->text());
	}
	else
	{
		ui.lineEdit_15->setFocus();
		ui.lineEdit_15->selectAll();
	}
}

void QKalkulacijaVnes::pressEscape()
{
	emit closeW();
}
void QKalkulacijaVnes::setKomintent(QString text, QString textName)
{
	if (isKomintent == true)
	{
		ui.lineEdit->setText(textName);
		komintentID = text;
	} 
	else
	{
		ui.lineEdit_13->setText(textName);
		prevoznikID = text;
	}
	QSqlQuery query;
	query.prepare("select sifra from komintenti where id = :id");
	query.bindValue(":id", komintentID);	
	query.exec();
	query.next();

	ui.lineEdit_26->setText(query.value(0).toString());
}

void QKalkulacijaVnes::setFocusLine()
{
	if (isKomintent == true)
	{
		ui.lineEdit->setFocus();
		ui.lineEdit->selectAll();
	} 
	else
	{
		ui.lineEdit_13->setFocus();
		ui.lineEdit_13->selectAll();
	}
}

void QKalkulacijaVnes::setArtikli(QString text, QString textName)
{
	disconnect(ui.lineEdit_23, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit23_TextChanged(const QString &)));
	disconnect(ui.lineEdit_21, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit21_TextChanged(const QString &)));

	ui.lineEdit_2->setText("");
	ui.lineEdit_8->setText("");
	ui.lineEdit_4->setText("");
	ui.lineEdit_3->setText("");
	ui.lineEdit_9->setText("");
	ui.lineEdit_13->setText("");
	ui.lineEdit_15->setText("");
	ui.lineEdit_17->setText("");
	ui.lineEdit_22->setText("");
	ui.lineEdit_23->setText("");
	ui.lineEdit_18->setText("");
	ui.lineEdit_19->setText("");
	ui.lineEdit_20->setText("");
	ui.lineEdit_21->setText("");
	ui.lineEdit_24->setText("");
	ui.lineEdit_12->setText("");

	ui.lineEdit_2->setText(textName);
	textId = text;
	artikal_id = text.toInt();

	QSqlQuery query;
	query.prepare("select id, edm, ddv, sifra from artikli where id = :id");
	query.bindValue(":id", artikal_id);	
	query.exec();
	query.next();

	QString art_id = query.value(0).toString();
	ui.lineEdit_8->setText(query.value(1).toString());
	ui.lineEdit_9->setText(query.value(2).toString());
	ui.lineEdit_12->setText(query.value(3).toString());

	QLocale loc;
	CHelperClass chc(this);
	chc.createSaldoArtikliOdlivMapAll_bezKomintent();
	chc.createSaldoProizvodiPrilivMapAllbezKomintent();
	QString keyT = art_id + "Key";
	float vkVlezKol = chc.getLagerListaAll(keyT , (QString)"PRILIV");

	keyT = art_id + "Key" ;
	float vkIzlezKol = chc.getLagerListaAll(keyT , (QString)"ODLIV");

	float vkSaldo = vkVlezKol - vkIzlezKol;
	QString temp =  loc.toString((vkSaldo) ,'f',2);
	if ((vkVlezKol != 0.f)||(vkIzlezKol != 0.f))
	{
		QKalkulacijaLagerLista * uf = new QKalkulacijaLagerLista((QDialog*)this);
		uf->lista(ui.lineEdit_12->text());
		uf->setModal(true);

		if(uf->exec() == QDialog::Accepted)
		{
			int stop = 0;	
		}
		QLocale loc;
		float nabCenaSoDDV = (loc.toFloat(uf->m_selectedNabavCena));
		float prenesenDDVProcent = (loc.toFloat(ui.lineEdit_9->text()));
		float nabCenaBezDDV = (nabCenaSoDDV / (1 + prenesenDDVProcent/100));
		ui.lineEdit_3->setText(loc.toString(nabCenaBezDDV));

		float prodCenaSoDDV = (loc.toFloat(uf->m_selectedProdCena));
		mm_prodCenaSoDDV = prodCenaSoDDV;
		float marzaProcent = (( prodCenaSoDDV / nabCenaSoDDV) *100 - 100);
		ui.lineEdit_23->setText(loc.toString(marzaProcent));
		ui.lineEdit_15->setText(uf->m_selectedNabavCena); 
		ui.lineEdit_21->setText(uf->m_selectedProdCena);
		updateModelData();
	} 
	else
	{
	}
	ui.lineEdit_25->setText(temp);
	connect(ui.lineEdit_23, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit23_TextChanged(const QString &)));
	connect(ui.lineEdit_21, SIGNAL(textChanged(const QString &)), this, SLOT(on_plineEdit21_TextChanged(const QString &)));
}


void QKalkulacijaVnes::on_pushButton_2_clicked()
{
    CHelperClass hclass(this);
    if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
    {
        emit scallArtikli((QWidget*)this, ui.lineEdit_2->text());
    }
    else
    {
        ui.lineEdit_4->setFocus();
		ui.lineEdit_4->selectAll();
    }
}

void QKalkulacijaVnes::setFocusLine2()
{
	ui.lineEdit_4->setFocus();
	ui.lineEdit_4->selectAll();
}

void QKalkulacijaVnes::on_pushButton_3_clicked()
{
	QLocale loc;
	CHelperClass chc(this);
	updateModelData();
	float kurs = (loc.toFloat(ui.lineEdit_9->text()));
	float vkIznosFaktura = (loc.toFloat(ui.lineEdit_5->text()));
	
	float carina = (loc.toFloat(ui.lineEdit_6->text()));
	float transport = (loc.toFloat(ui.lineEdit_7->text()));
	float drTrosoci = (loc.toFloat(ui.lineEdit_8->text()));


	float vkIznosTrosoci = (carina + transport + drTrosoci);
	float raspTrosoci = 0;
	if (vkIznosFaktura * kurs)
	{
		raspTrosoci = ((vkIznosFaktura * kurs + vkIznosTrosoci)/(vkIznosFaktura * kurs));
	}
	CHelperClass hclass(this);
	if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Податокот за артикал е невалиден\nОдбери артикал од листата на артикли!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_2->setFocus();
		ui.lineEdit_2->selectAll();
		return;
	}

    if(textId.toInt() == -1)
	{
		return;
	}

	//m_id = textId.toInt();

	QString temp = "select id, sifra, artikal, edm from artikli where id =";
	temp += textId;
	QSqlQuery query(temp);
	QString country1 = "";
	QString country2 = "";
	QString country3 = "";
	QString country4 = "";
	QString magacinTip = "";
    while (query.next()) {
		country1 = query.value(query.record().indexOf("id")).toString();
		country2 = query.value(query.record().indexOf("sifra")).toString();
		country3 = query.value(query.record().indexOf("artikal")).toString();
		country4 = query.value(query.record().indexOf("edm")).toString();
		//        ui.lineEdit->setText(country1);
	}

	int row = model->rowCount();

	QStandardItem *item = new QStandardItem(country1);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(0, colWidth[0]);
	model->setItem(row, 0, item);

	item = new QStandardItem(country2);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, colWidth[1]);
	model->setItem(row, 1, item);

	item = new QStandardItem(country3);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, colWidth[2]);
	model->setItem(row, 2, item);

	item = new QStandardItem(country4);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(32, colWidth[3]);
	model->setItem(row, 3, item);

	// kol 
    item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_4->text()), 'f', 4));
    item->setTextAlignment(Qt::AlignRight);
    item->setEditable(false);
    ui.tableView->setRowHeight(row, 18);
    ui.tableView->setColumnWidth(4, colWidth[4]);
    model->setItem(row, 4, item);

	//nabavna cena bez ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_3->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(5, colWidth[5]);
	model->setItem(row, 5, item);

	//prenesen ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_9->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(6, colWidth[6]);
	model->setItem(row, 6, item);

	// ddv iznos
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_13->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, colWidth[7]);
	model->setItem(row, 7, item);

	// nab cena so ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_15->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(8, colWidth[8]);
	model->setItem(row, 8, item);

	// rabat
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_17->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(9, colWidth[9]);
	model->setItem(row, 9, item);

	// vkupna Nabavna cena so ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_22->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(10, colWidth[10]);
	model->setItem(row, 10, item);

	// marza procent
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_23->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(11, colWidth[11]);
	model->setItem(row, 11, item);

	// marza iznos
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_18->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(12, colWidth[12]);
	model->setItem(row, 12, item);

	// prodazna cena bez ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_19->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(13, colWidth[13]);
	model->setItem(row, 13, item);

	// presmetan ddv
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_20->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(14, colWidth[14]);
	model->setItem(row, 14, item);

	// prodazna cenaso ddv 
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_21->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(15, colWidth[15]);
	model->setItem(row, 15, item);

	// vkupna prodazna so ddv 
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_24->text()), 'f', 4));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(16, colWidth[16]);
	model->setItem(row, 16, item);

	ui.tableView->selectRow(row);

    QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
	ui.tableView->setColumnHidden(0, true);
	ui.lineEdit_2->setText("");
	ui.lineEdit_8->setText("");
	ui.lineEdit_4->setText("");
	ui.lineEdit_3->setText("");
	ui.lineEdit_9->setText("");
	ui.lineEdit_13->setText("");
	ui.lineEdit_15->setText("");
	ui.lineEdit_17->setText("");
	ui.lineEdit_22->setText("");
	ui.lineEdit_23->setText("");
	ui.lineEdit_18->setText("");
	ui.lineEdit_19->setText("");
	ui.lineEdit_20->setText("");
	ui.lineEdit_21->setText("");
	ui.lineEdit_24->setText("");
	ui.lineEdit_12->setText("");

	ui.lineEdit_2->setFocus();
	ui.lineEdit_2->selectAll();
	textId = "-1";
	calculateNabCenaSoDDVIznos();
}


void QKalkulacijaVnes::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}

void QKalkulacijaVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
	selRow = modelX.row();
    editorOpen = false;
    emit closeCell();
}

void QKalkulacijaVnes::on_pushButton_6_clicked()
{
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Ставката ке биде ИЗБРИШАНА"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Cancel)
	{
		return;
	}
	selRow = ui.tableView->currentIndex().row();
	model->removeRow(selRow);
	calculateNabCenaSoDDVIznos();
}
void QKalkulacijaVnes::pressReturn()
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

void QKalkulacijaVnes::pressF9()
{
	on_pushButton_4_clicked();
}

void QKalkulacijaVnes::on_pushButton_4_clicked()
{
	QLocale loc;
	if (!validateKomintent())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Податокот за коминтент е невалиден\nОдбери коминтент од листата на коминтенти!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit->setFocus();
		ui.lineEdit->selectAll();
		return;
	}

	QMessageBox msgBox;
	msgBox.setText(trUtf8("ПРИЕМНИЦАТА ке биде ВНЕСЕНА"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Cancel)
	{
		return;
	}

	int cols = model->columnCount();
    int rows = model->rowCount();
    if (!rows)
    {
        return;
    }
	QSqlDatabase db = QSqlDatabase::database();
	db.transaction();	
	bool sqlStat = true;

    int mid=0;

        // Presmetaj broj na Nalog 
        CHelperClass *hlp = new CHelperClass(this);
        int m_idDok = hlp->calcMaxIdTblKalkulacii(); 
        int m_idMag = hlp->calcMaxIdTblKalkulaciiStavki(); 
        delete hlp;

        int m_id = m_idDok >= m_idMag ? m_idDok : m_idMag;

        int row = model->rowCount();
        QSqlQuery query;
        
		
		query.clear();
		query.prepare(" insert into dokumenti(dok_id, dok_tip, datum, komintent_id, dok_opis, iznos_faktura, rabat, faktura_br, tip_dokument, datum_f_ra, valuta_datum) values(:a0,:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9, :a10)");
 		query.bindValue(":a0", m_id);	
		query.bindValue(":a1", 20);
 		query.bindValue(":a2", ui.dateTimeEdit->date().toString("yyyy-MM-dd"));	
 		query.bindValue(":a3", komintentID);	
 		query.bindValue(":a4", ui.textEdit->toPlainText());	
		query.bindValue(":a5", ui.lineEdit_5->text());
		query.bindValue(":a6", ui.lineEdit_16->text());
		query.bindValue(":a7", ui.lineEdit_14->text());
		query.bindValue(":a8", ui.comboBox_2->currentText()); //цомбо2
		query.bindValue(":a9",ui.dateTimeEdit_2->date().toString("yyyy-MM-dd"));
		query.bindValue(":a10",ui.dateTimeEdit_4->date().toString("yyyy-MM-dd"));
        sqlStat = sqlStat && query.exec();
		QSqlError err = query.lastError();
        query.clear();
        query.prepare("select max(dok_id) from  dokumenti where dok_tip = 20");
        sqlStat = sqlStat && query.exec();

        for (int i = 0; i < rows; i++)
        {

            QString mTipDok = "P";
            QString mEmpty ="Empty";
            QString mArtikalID = model->item(i, 0)->text();
            QString mArtikalKolicina = model->item(i, 4)->text();
            QString mArtikalNabCenaBezDDV = model->item(i, 5)->text();
			QString mArtikalNabCenasoDDV = model->item(i, 8)->text();
			QString mArtikalRabat = model->item(i, 9)->text();
			QString mArtikalProdCenaSoDDV = model->item(i, 15)->text();
			QString mArtikalMarza = model->item(i, 11)->text();

            int mMagacinTip = model->item(i, 6)->text() == trUtf8("Артикли") ? 0 : 1;

			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, ikol, icena, rabat, nab_cena, prod_cena, marza, komintent_id, nab_cena_bez_ddv) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10, :a11)"
				);

			query.bindValue(":a1", m_id );	
			query.bindValue(":a2", "20");
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", mArtikalKolicina);	
			query.bindValue(":a5", "0");	
			query.bindValue(":a6", mArtikalRabat);	
			query.bindValue(":a7", mArtikalNabCenasoDDV);	
			query.bindValue(":a8", mArtikalProdCenaSoDDV);	
			query.bindValue(":a9", mArtikalMarza);	
			query.bindValue(":a10", komintentID);	
			query.bindValue(":a11", mArtikalNabCenaBezDDV);	
			
			sqlStat = sqlStat && query.exec();
			QSqlError err = query.lastError();
        }

		if (sqlStat)
		{
			db.commit();
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Приемница - Калкулацијата е успешно внесена."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			pressEscape();
		}
		else
		{
			db.rollback();
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Приемница - Калкулацијата НЕ Е внесена !!!."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
		}
}


bool QKalkulacijaVnes::existDok(int idDok)
{
    int nCount = 0;
    QString temp = "select count(dok_id) br from dokumenti where dok_tip = 20 and dok_id =";
    temp += QString::number(idDok, 10);
    QSqlQuery query(temp);
    QString country1 = "";
    int fieldNo = query.record().indexOf("br");
    while (query.next()) {
        nCount = query.value(0).toInt() + 1;
    }
    return nCount > 0 ? true : false;
}

bool QKalkulacijaVnes::eventFilter(QObject *object, QEvent *event)
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
		if (object == ui.lineEdit_14)
		{
			ui.lineEdit_14->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_15)
		{
			ui.lineEdit_15->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_17)
		{
			ui.lineEdit_17->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_23)
		{
			ui.lineEdit_23->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_21)
		{
			ui.lineEdit_21->setStyleSheet("background-color: yellow");
		}
		if (object == ui.comboBox_2)
		{
			ui.comboBox_2->setStyleSheet("background-color: yellow");
		}
		if (object == ui.dateTimeEdit)
        {
            ui.dateTimeEdit->setStyleSheet("background-color: yellow");
        }
		if (object == ui.dateTimeEdit_2)
		{
			ui.dateTimeEdit_2->setStyleSheet("background-color: yellow");
		}
		if (object == ui.dateTimeEdit_4)
		{
			ui.dateTimeEdit_4->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_16)
		{
			ui.lineEdit_16->setStyleSheet("background-color: yellow");
		}
	}
	if (event->type() == QEvent::FocusOut)
	{

		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_16)
		{
			ui.lineEdit_16->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit)
		{
			ui.lineEdit->setStyleSheet("background-color: none");
		}
		if (object == ui.comboBox_2)
		{
			ui.comboBox_2->setStyleSheet("background-color: none");
		}

		if (object == ui.dateTimeEdit_2)
		{
			ui.dateTimeEdit_2->setStyleSheet("background-color: none");
		}
		if (object == ui.dateTimeEdit_4)
		{
			ui.dateTimeEdit_4->setStyleSheet("background-color: none");
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
		if (object == ui.lineEdit_14)
		{
			ui.lineEdit_14->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_15)
		{
			ui.lineEdit_15->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_17)
		{
			ui.lineEdit_17->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_23)
		{
			ui.lineEdit_23->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_21)
		{
			ui.lineEdit_21->setStyleSheet("background-color: none");
		}
        if (object == ui.dateTimeEdit)
        {
            ui.dateTimeEdit->setStyleSheet("background-color: none");
        }
	}

	return false;
}

void QKalkulacijaVnes::on_plineEdit3_Pressed()
{
    updateModelData();
	ui.lineEdit_15->setFocus();
	ui.lineEdit_15->selectAll();
}
void QKalkulacijaVnes::on_plineEdit4_Pressed()
{
	QLocale loc;
	updateModelData();
	if (loc.toFloat(ui.lineEdit_4->text()) > 0.f)
	{
		ui.lineEdit_3->setFocus(); // nab_cena-DDV
		ui.lineEdit_3->selectAll();
	}
	else
	{
		ui.lineEdit_4->setFocus(); // nab_cena-DDV
		ui.lineEdit_4->selectAll();
	}
}

void QKalkulacijaVnes::on_plineEdit15_Pressed()
{
	QLocale loc;
	CHelperClass chc(this);
	float nabCenaSoDDV = (loc.toFloat(ui.lineEdit_15->text()));
	float prenesenDDVProcent = (loc.toFloat(ui.lineEdit_9->text()));
	float nabCenaBezDDV = (nabCenaSoDDV / (1 + prenesenDDVProcent/100));

	ui.lineEdit_3->setText(loc.toString((nabCenaBezDDV), 'f', 4));
	updateModelData();
	if (loc.toFloat(ui.lineEdit_15->text()) > 0.f)
	{
		ui.lineEdit_17->setFocus(); // nab_cena-DDV
		ui.lineEdit_17->selectAll(); 
	}
	else
	{
		ui.lineEdit_15->setFocus(); // nab_cena-DDV
		ui.lineEdit_15->selectAll();
	}

}

void QKalkulacijaVnes::on_plineEdit17_Pressed()
{
	updateModelData();
	ui.lineEdit_23->setFocus(); // nab_cena-DDV
	ui.lineEdit_23->selectAll();
}

void QKalkulacijaVnes::on_plineEdit23_Pressed()
{
	QLocale loc;
	ui.lineEdit_21->setText(loc.toString(mm_prodCenaSoDDV));
	updateModelData();
	ui.lineEdit_21->setFocus(); // nab_cena-DDV
	ui.lineEdit_21->selectAll(); 
}

void QKalkulacijaVnes::on_plineEdit23_TextChanged(const QString &)
{
	QLocale loc;
	CHelperClass chc(this);
	float nabCenaSoDDV = loc.toFloat(ui.lineEdit_15->text());
	float marzaProcent = loc.toFloat(ui.lineEdit_23->text());

	mm_prodCenaSoDDV = nabCenaSoDDV * (1 + marzaProcent / 100);
}

void QKalkulacijaVnes::on_plineEdit18_Pressed()
{
	ui.lineEdit_19->setFocus(); // nab_cena-DDV
	ui.lineEdit_19->selectAll(); // nab_cena-DDV
}
void QKalkulacijaVnes::on_plineEdit19_Pressed()
{
	ui.lineEdit_21->setFocus(); // nab_cena-DDV
	ui.lineEdit_21->selectAll(); 
}
void QKalkulacijaVnes::on_plineEdit21_Pressed()
{
	QLocale loc;
	ui.lineEdit_23->setText(loc.toString(mm_marzaProcent));
	updateModelData();
	ui.lineEdit_24->setFocus(); 
	ui.lineEdit_24->selectAll(); 
}

void QKalkulacijaVnes::on_plineEdit21_TextChanged(const QString &)
{
	QLocale loc;
	CHelperClass chc(this);
	float nabCenaSoDDV = loc.toFloat(ui.lineEdit_15->text());
	float prodCenaSoDDV = loc.toFloat(ui.lineEdit_21->text());
	mm_marzaProcent = ( prodCenaSoDDV / nabCenaSoDDV) *100 - 100;
}

void QKalkulacijaVnes::on_plineEdit24_Pressed()
{
	ui.pushButton_3->setFocus(); // nab_cena-DDV
}


void QKalkulacijaVnes::openEditor()
{
	//	tableView->closePersistentEditor(indexPrev);
	QModelIndex index;
	QModelIndexList indexes = ui.tableView->selectionModel()->selection().indexes();
	index = indexes.at(0);	// To get the row/column numbers use 
	if (
		(index.column() == 1)||
		(index.column() == 4)||
		(index.column() == 5)||
		(index.column() == 8)||
		(index.column() == 9)||
		(index.column() == 11)||
		(index.column() == 15))
	{
		ui.tableView->openPersistentEditor(index);
	}
	indexPrev = index;
}

void QKalkulacijaVnes::closeEditor()
{
	QModelIndex index;
	QModelIndexList indexes = ui.tableView->selectionModel()->selection().indexes();
	if (indexes.isEmpty())
	{
		return;
	}
	else
	{
		index = indexes.at(0);	// To get the row/column numbers use 
		if (!(
			(index.column() == 1)||
			(index.column() == 4)||
			(index.column() == 5)||
			(index.column() == 8)||
			(index.column() == 9)||
			(index.column() == 11)||
			(index.column() == 15)
			))
		{
			return;
		}
	}
	if ((index.row() < 0) ||(index.row() > model->rowCount()))
	{
		return;
	}
	ui.tableView->closePersistentEditor(indexPrev);
	QLocale loc;
	bool ok_temp;
	float tempKol  = loc.toFloat(model->item(index.row(), 4)->text(), &ok_temp);
	float tempNabavnaCenaBezDDV  = loc.toFloat(model->item(index.row(), 5)->text(), &ok_temp);
	float tempPrenesenDDV  = loc.toFloat(model->item(index.row(), 6)->text(), &ok_temp);
	float tempVrednostNaDDV  = loc.toFloat(model->item(index.row(), 7)->text(), &ok_temp);
	float tempNabavnaCenaSoDDV  = loc.toFloat(model->item(index.row(), 8)->text(), &ok_temp);
	float tempRabat  = loc.toFloat(model->item(index.row(), 9)->text(), &ok_temp);

	float tempNabavnaCenaSoDDVSoRabat = tempNabavnaCenaSoDDV * (1 - tempRabat / 100);

	float tempVkupenNabavenIznosSoDDV  = loc.toFloat(model->item(index.row(), 10)->text(), &ok_temp);
	float tempMarza  = loc.toFloat(model->item(index.row(), 11)->text(), &ok_temp);
	float tempMarzaDenari  = loc.toFloat(model->item(index.row(), 12)->text(), &ok_temp);
	float tempProdaznaCenaBezDDV  = loc.toFloat(model->item(index.row(), 13)->text(), &ok_temp);
	float tempPresmetanDDV  = loc.toFloat(model->item(index.row(), 14)->text(), &ok_temp);
	float tempProdaznaCenaSoDDV  = loc.toFloat(model->item(index.row(), 15)->text(), &ok_temp);
	float tempVkupenProdazenIznosSoDDV  = loc.toFloat(model->item(index.row(), 16)->text(), &ok_temp);

	if (index.column() == 1) // sifra_artikal
	{
		QString temp = 
			"select artikli.id, artikal, edm "
			"from artikli "
			"where sifra = '";
		temp += model->item(index.row(), 1)->text() + "'";
		QSqlQuery query(temp);	
		model->item(index.row(), 0)->setText("0");  
		model->item(index.row(), 2)->setText("");  
		model->item(index.row(), 3)->setText("");  
		while (query.next()) 
		{
			model->item(index.row(), 0)->setText(query.value(0).toString());  
			model->item(index.row(), 2)->setText(query.value(1).toString());  
			model->item(index.row(), 3)->setText(query.value(2).toString());  
		}
	}

	if (index.column() == 4) // kolicina
	{
		model->item(index.row(), 4)->setText(loc.toString(tempKol, 'f', 4));  
		tempVkupenNabavenIznosSoDDV = tempNabavnaCenaSoDDVSoRabat * tempKol;
		model->item(index.row(), 10)->setText(loc.toString(tempVkupenNabavenIznosSoDDV, 'f', 4));  
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		model->item(index.row(), 16)->setText(loc.toString(tempVkupenProdazenIznosSoDDV, 'f', 4));  
	} 
	else if(index.column() == 5) //Nabavna cena bez DDV 
	{
		tempVrednostNaDDV = tempNabavnaCenaBezDDV * tempPrenesenDDV / 100;
		tempNabavnaCenaSoDDV = tempNabavnaCenaBezDDV + tempVrednostNaDDV;
		tempNabavnaCenaSoDDVSoRabat = tempNabavnaCenaSoDDV * (1 - tempRabat / 100);
		tempVkupenNabavenIznosSoDDV = tempNabavnaCenaSoDDVSoRabat * tempKol;

		tempMarza = (tempProdaznaCenaSoDDV / tempNabavnaCenaSoDDVSoRabat - 1) * 100;
		tempMarzaDenari = tempNabavnaCenaSoDDVSoRabat * tempMarza / 100;
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		tempPresmetanDDV = (tempMarzaDenari * tempPrenesenDDV / 100);
		tempProdaznaCenaBezDDV = tempProdaznaCenaSoDDV - tempPresmetanDDV;
	}
	else if(index.column() == 8) //Nabavna cena so DDV
	{
		tempNabavnaCenaBezDDV = tempNabavnaCenaSoDDV - tempVrednostNaDDV;
		tempVrednostNaDDV = tempNabavnaCenaBezDDV * tempPrenesenDDV / 100;

		tempNabavnaCenaSoDDVSoRabat = tempNabavnaCenaSoDDV * (1 - tempRabat / 100);
		tempVkupenNabavenIznosSoDDV = tempNabavnaCenaSoDDVSoRabat * tempKol;

		tempMarza = (tempProdaznaCenaSoDDV / tempNabavnaCenaSoDDVSoRabat - 1) * 100;
		tempMarzaDenari = tempNabavnaCenaSoDDVSoRabat * tempMarza / 100;
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		tempPresmetanDDV = (tempMarzaDenari * tempPrenesenDDV / 100);
		tempProdaznaCenaBezDDV = tempProdaznaCenaSoDDV - tempPresmetanDDV;
	}
	else if(index.column() == 9) //Rabat
	{

		tempNabavnaCenaSoDDVSoRabat = tempNabavnaCenaSoDDV * (1 - tempRabat / 100);
		tempVkupenNabavenIznosSoDDV = tempNabavnaCenaSoDDVSoRabat * tempKol;

		tempMarza = (tempProdaznaCenaSoDDV / tempNabavnaCenaSoDDVSoRabat - 1) * 100;
		tempMarzaDenari = tempNabavnaCenaSoDDVSoRabat * tempMarza / 100;
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		tempPresmetanDDV = (tempMarzaDenari * tempPrenesenDDV / 100);
		tempProdaznaCenaBezDDV = tempProdaznaCenaSoDDV - tempPresmetanDDV;
	}
	else if(index.column() == 11)//Marza
	{
		tempProdaznaCenaSoDDV = (tempMarza / 100 + 1) * tempNabavnaCenaSoDDVSoRabat;
		tempMarzaDenari = tempNabavnaCenaSoDDVSoRabat * tempMarza / 100;
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		tempPresmetanDDV = (tempMarzaDenari * tempPrenesenDDV / 100);
		tempProdaznaCenaBezDDV = tempProdaznaCenaSoDDV - tempPresmetanDDV;
	}
	else if(index.column() == 15)//Prodazna cena so DDV
	{
		tempMarza = (tempProdaznaCenaSoDDV / tempNabavnaCenaSoDDVSoRabat - 1) * 100;
		tempMarzaDenari = tempNabavnaCenaSoDDVSoRabat * tempMarza / 100;
		tempVkupenProdazenIznosSoDDV = tempProdaznaCenaSoDDV * tempKol;
		tempPresmetanDDV = (tempMarzaDenari * tempPrenesenDDV / 100);
		tempProdaznaCenaBezDDV = tempProdaznaCenaSoDDV - tempPresmetanDDV;
	}
	else
	{
	}

	model->item(index.row(), 4)->setText(loc.toString(tempKol, 'f', 4));  
	model->item(index.row(), 5)->setText(loc.toString(tempNabavnaCenaBezDDV, 'f', 4));  
	model->item(index.row(), 6)->setText(loc.toString(tempPrenesenDDV, 'f', 4));  
	model->item(index.row(), 7)->setText(loc.toString(tempVrednostNaDDV, 'f', 4));  
	model->item(index.row(), 8)->setText(loc.toString(tempNabavnaCenaSoDDV, 'f', 4));  
	model->item(index.row(), 9)->setText(loc.toString(tempRabat, 'f', 4));  
	model->item(index.row(), 10)->setText(loc.toString(tempVkupenNabavenIznosSoDDV, 'f', 4));  
	model->item(index.row(), 11)->setText(loc.toString(tempMarza, 'f', 4));  
	model->item(index.row(), 12)->setText(loc.toString(tempMarzaDenari, 'f', 4));  
	model->item(index.row(), 13)->setText(loc.toString(tempProdaznaCenaBezDDV, 'f', 4));  
	model->item(index.row(), 14)->setText(loc.toString(tempPresmetanDDV, 'f', 4));  
	model->item(index.row(), 15)->setText(loc.toString(tempProdaznaCenaSoDDV, 'f', 4));  
	model->item(index.row(), 16)->setText(loc.toString(tempVkupenProdazenIznosSoDDV, 'f', 4));  

}

void QKalkulacijaVnes::on_pushButton_5_clicked()
{
	pressEscape();
}

bool QKalkulacijaVnes::validateKomintent()
{
	bool stat = false;
	CHelperClass hclass(this);
	if (hclass.isKomintentExists(ui.lineEdit->text()))
	{
		stat = true;
	}
	return stat;
}

bool QKalkulacijaVnes::validateПревозник()
{
	bool stat = false;
	CHelperClass hclass(this);
	if (hclass.isKomintentExists(ui.lineEdit_13->text()))
	{
		stat = true;
	}
	return stat;
}

void QKalkulacijaVnes::callImportPriemnici()
{
	emit scallPriemnici((QWidget*)this, ui.lineEdit->text());
}


void QKalkulacijaVnes::setPriemnicaID(QString text, QString textName)
{
	QLocale loc;
	float kurs = ui.lineEdit_9->text().toFloat();
	float vkIznosFaktura = ui.lineEdit_5->text().toFloat();

	float carina = ui.lineEdit_6->text().toFloat();
	float transport = ui.lineEdit_7->text().toFloat();
	float drTrosoci = ui.lineEdit_8->text().toFloat();

	float vkIznosTrosoci = carina + transport + drTrosoci;
	float raspTrosoci = 0;
	if (vkIznosFaktura * kurs)
	{
		raspTrosoci = (vkIznosFaktura * kurs + vkIznosTrosoci)/(vkIznosFaktura * kurs);
	}

	int m_id = text.toInt();
	int id = m_id;
	if(m_id == -1)
	{
		return;
	}
	int r = 0;
	int c = 11;
	int fieldNo[10];
	QString country[10];
	int colWidth[] = {40, 70, 220, 60, 80, 80, 80, 80, 80, 80};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "mag_id" };
	QString temp = 
		"select artikli.id, sifra, artikal, edm, ikol, icena "
		"from magacin "
		"left join artikli on magacin.artikal_id=artikli.id "
		"where (magacin.dok_tip = 20 or magacin.dok_tip = 24) and magacin.dok_id= ";
	temp += QString::number(id, 10);
	QSqlQuery query(temp);
/*	model = new QStandardItemModel(r,c);*/
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Количина"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Е.Цена.Вал."));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Е.Цена.Ден."));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Е.Трошоци"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Е.Наб.Цена"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Вк.Износ."));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("Приемн. бр."));


	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	header->show();
//	int row = 0;
	m_sumaIznosStavki = 0;
	m_sumaTrosoci = 0;
	while (query.next()) 
	{
		int row = model->rowCount();
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = "";

			if ((i > 3) && (i < 6))
			{
				temp = query.value(i).toString();
				temp =  loc.toString(temp.toFloat(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if(i <= 3)
			{
				temp = query.value(i).toString();
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			else 
			{
				if (i == 6)
				{
					temp = query.value(5).toString();
					//temp =  loc.toString(temp.toFloat() * kurs , 'f', 2);
					item = new QStandardItem(temp);
					item->setTextAlignment(Qt::AlignRight);
				}
				if (i == 7)
				{
					temp =  loc.toString( query.value(5).toFloat() * kurs * (raspTrosoci- 1), 'f', 2);
					item = new QStandardItem(temp);
					item->setTextAlignment(Qt::AlignRight);
					m_sumaTrosoci += query.value(4).toFloat() * query.value(5).toFloat() * kurs * (raspTrosoci- 1);
				}
				if (i == 8)
				{
					temp = query.value(6).toString();
					//temp =  loc.toString(temp.toFloat() * raspTrosoci, 'f', 2);
					item = new QStandardItem(temp);
					item->setTextAlignment(Qt::AlignRight);
				}

				if (i == 9)
				{
					temp =  loc.toString(query.value(4).toFloat() * query.value(5).toFloat() * kurs * raspTrosoci, 'f', 2); // kol * cena vo valuta
					item = new QStandardItem(temp);
					m_sumaIznosStavki += query.value(4).toFloat() * query.value(5).toFloat();
					item->setTextAlignment(Qt::AlignRight);
				}
				if (i == 10)
				{
					item = new QStandardItem(text);
					item->setTextAlignment(Qt::AlignRight);
				}
			}

			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			model->setItem(row, i, item);
		}        
	} 
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
	ui.lineEdit->setFocus();
	ui.lineEdit->selectAll();
}

void QKalkulacijaVnes::comboBoxChanged(const QString & str)
{
	ui.lineEdit_9->setFocus();
	ui.lineEdit_9->selectAll();
}


void QKalkulacijaVnes::updateModelData()
{
	QLocale loc;
	CHelperClass chc(this);

	float iznosFaktura = (loc.toFloat(ui.lineEdit_5->text()));
	ui.lineEdit_5->setText(loc.toString((iznosFaktura), 'f', 4));

	float rabatFaktura = (loc.toFloat(ui.lineEdit_16->text()));
	ui.lineEdit_16->setText(loc.toString((rabatFaktura), 'f', 4));

	float presmetanIznos = (loc.toFloat(ui.lineEdit_6->text()));
	ui.lineEdit_6->setText(loc.toString((presmetanIznos), 'f', 4));

	float razlikaIznos = (loc.toFloat(ui.lineEdit_7->text()));
	ui.lineEdit_7->setText(loc.toString((razlikaIznos), 'f', 4));

	float kolicinaStavka = loc.toFloat(ui.lineEdit_4->text()); 

	float nabCenaBezDDV = (loc.toFloat(ui.lineEdit_3->text()));
	ui.lineEdit_3->setText(loc.toString((nabCenaBezDDV), 'f', 4));

	float prenesenDDVProcent = (loc.toFloat(ui.lineEdit_9->text()));
	ui.lineEdit_9->setText(loc.toString((prenesenDDVProcent), 'f', 4));

	float prenesenDDVIznos = (nabCenaBezDDV * prenesenDDVProcent / 100);
	ui.lineEdit_13->setText(loc.toString((prenesenDDVIznos), 'f', 4));

	float nabCenaPlusDDV = (nabCenaBezDDV + prenesenDDVIznos);
	ui.lineEdit_15->setText(loc.toString((nabCenaPlusDDV), 'f', 4));

	float rabatStavka = (loc.toFloat(ui.lineEdit_17->text()));
	float nabCenaPlusDDVsoRabat = (nabCenaPlusDDV * (1 - rabatStavka/100));

	float vkupnoNabPlusDDV = (nabCenaPlusDDVsoRabat * kolicinaStavka);
	ui.lineEdit_22->setText(loc.toString((vkupnoNabPlusDDV), 'f', 4));


	float prodCenaSoDDV = loc.toFloat(ui.lineEdit_21->text());
	ui.lineEdit_21->setText(loc.toString((prodCenaSoDDV), 'f', 4));

	float marzaProcent = (prodCenaSoDDV / nabCenaPlusDDVsoRabat -1) * 100;
	ui.lineEdit_23->setText(loc.toString((marzaProcent), 'f', 4));

	float marzaIznos = (nabCenaPlusDDVsoRabat * marzaProcent/100);
	ui.lineEdit_18->setText(loc.toString((marzaIznos), 'f', 4));

	float vkupnoProdSoDDV = (prodCenaSoDDV * kolicinaStavka);
	ui.lineEdit_24->setText(loc.toString((vkupnoProdSoDDV), 'f', 4));
	float presmetanDDV = (marzaIznos * prenesenDDVProcent / 100);
	ui.lineEdit_20->setText(loc.toString((presmetanDDV), 'f', 4));

	float prodCenaBezDDV = (prodCenaSoDDV - presmetanDDV);
	ui.lineEdit_19->setText(loc.toString((prodCenaBezDDV), 'f', 4));

	calculateNabCenaSoDDVIznos();
}



void QKalkulacijaVnes::calculateNabCenaSoDDVIznos()
{
	QLocale loc;
	CHelperClass chc(this);
	int rows = model->rowCount();
	float sumTemp = 0.f;
	float sumIzleznaTemp = 0.f;
	for (int i = 0; i < rows; i++)
	{
		sumTemp += loc.toFloat(model->item(i, 10)->text());
		sumIzleznaTemp += loc.toFloat(model->item(i, 16)->text());
	}
	ui.lineEdit_6->setText(loc.toString((sumTemp), 'f', 4));
	ui.lineEdit_10->setText(loc.toString((sumIzleznaTemp), 'f', 4));
	float iznosFaktura = loc.toFloat(ui.lineEdit_5->text());

	float razlikaTemp = iznosFaktura - sumTemp;
	float dobivkaTemp = sumIzleznaTemp - iznosFaktura;
	ui.lineEdit_7->setText(loc.toString((razlikaTemp), 'f', 4));
	ui.lineEdit_11->setText(loc.toString((dobivkaTemp), 'f', 4));
}

void QKalkulacijaVnes::setTableColumnWidths(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	s->setKalkulacijaVnes_ColumnWidth(tempWidth);
}

void QKalkulacijaVnes::getTableColumnWidths(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getKalkulacijaVnes_ColumnWidth();
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
