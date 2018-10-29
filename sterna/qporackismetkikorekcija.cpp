#include "qporackismetkikorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>
#include "xx.h"
#include "qfiscalform.h"



QPorackiSmetkiKorekcija::QPorackiSmetkiKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,selRow(-1)
    ,textId("")
    ,komintentID("")
    ,artikal_id(0)
    ,pItemDelegate(0)
    ,editorOpen(0)
	,stat_artikal_call(0)
	,artikal_id_plakanje(0)
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);
    ui.lineEdit_7->setFocus();
    ui.lineEdit_7->setText("");
    ui.lineEdit_7->setStyleSheet("background-color: yellow");

    ui.lineEdit_7->setText("");
    ui.lineEdit_7->installEventFilter(this);
    ui.lineEdit_2->installEventFilter(this);
    ui.lineEdit_3->installEventFilter(this);
    ui.lineEdit_4->installEventFilter(this);

    
    connect(ui.lineEdit_2, SIGNAL(returnPressed()), this, SLOT(on_pushButton_2_clicked()));
	connect(ui.lineEdit_9, SIGNAL(returnPressed()), this, SLOT(on_pushButton_9_clicked()));
	connect(ui.lineEdit_10, SIGNAL(returnPressed()), this, SLOT(on_pushButton_10_clicked()));

	connect(ui.lineEdit_3, SIGNAL(returnPressed()), this, SLOT(on_plineEdit3_Pressed()));
    connect(ui.lineEdit_4, SIGNAL(returnPressed()), this, SLOT(on_plineEdit4_Pressed()));
	connect(ui.lineEdit_7, SIGNAL(returnPressed()), this, SLOT(on_plineEdit7_Pressed()));

    pItemDelegate = new QSTableWidgetDelegate(ui.tableView);
    connect(this ,SIGNAL(editCell()),this,SLOT(openEditor()));
    connect(this ,SIGNAL(closeCell()),this,SLOT(closeEditor()));

    ui.tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.tableView->setItemDelegate(pItemDelegate);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	model = new QStandardItemModel(0,11);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("ДДВ (%)"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Количина"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8(""));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8(""));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8(""));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
    header->show();

	model2 = new QStandardItemModel(0,11);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("ДДВ (%)"));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Количина"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	model2->setHeaderData( 8, Qt::Horizontal, trUtf8(""));
	model2->setHeaderData( 9, Qt::Horizontal, trUtf8(""));
	model2->setHeaderData( 10, Qt::Horizontal, trUtf8(""));

	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();

}

void QPorackiSmetkiKorekcija::pressF9()
{
	on_pushButton_4_clicked();
}


QPorackiSmetkiKorekcija::~QPorackiSmetkiKorekcija()
{

}
void QPorackiSmetkiKorekcija::pressEscape()
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
void QPorackiSmetkiKorekcija::on_pushButton_clicked()
{
//     CHelperClass hclass(this);
//     if (!hclass.isKomintentExists(ui.lineEdit->text()))
//     {
//         emit scallKomintenti((QWidget*)this, ui.lineEdit->text());
//     }
//     else
//     {
//         ui.lineEdit_2->setFocus();
//     }
}

void QPorackiSmetkiKorekcija::setFocusLine()
{
//    ui.lineEdit->setFocus();
}

void QPorackiSmetkiKorekcija::setKomintent(QString text, QString textName)
{
	ui.lineEdit_7->setText(textName);
	komintentID = text;
	QSqlQuery query;
	query.prepare("select sifra from komintenti where id = :id");
	query.bindValue(":id", komintentID);	
	query.exec();
	query.next();
	ui.lineEdit_8->setText(query.value(0).toString());
}

void QPorackiSmetkiKorekcija::setArtikli(QString text, QString textName)
{
	if (stat_artikal_call == 2)
	{
		ui.lineEdit_2->setText(textName);
		textId = text;
		artikal_id = text.toInt();
		QSqlQuery query;
		query.prepare("select sifra from artikli where id = :id");
		query.bindValue(":id", artikal_id);	
		query.exec();
		query.next();
		ui.lineEdit_6->setText(query.value(0).toString());
	} 
	else
	{
		ui.lineEdit_9->setText(textName);
		textIdPlakanje = text;
		artikal_id_plakanje = text.toInt();
		QSqlQuery query;
		query.prepare("select sifra from artikli where id = :id");
		query.bindValue(":id", artikal_id);	
		query.exec();
		query.next();
		//ui.lineEdit_6->setText(query.value(0).toString());
	}
}

void QPorackiSmetkiKorekcija::setSaldo(QString text)
{
	ui.lineEdit_6->setText(text);
}

void QPorackiSmetkiKorekcija::setProdCena(QString text)
{
	ui.lineEdit_3->setText(text);
	m_staraCena = text;
}

void QPorackiSmetkiKorekcija::setNabCena(QString text)
{
	m_staraNabCena = text;
}

void QPorackiSmetkiKorekcija::setFocusLine2()
{
	if (stat_artikal_call == 2)
	{
		ui.lineEdit_2->setFocus();
		ui.lineEdit_2->selectAll();
	}
	else if(stat_artikal_call == 9)
	{
		ui.lineEdit_9->setFocus();
		ui.lineEdit_9->selectAll();
	}
	else
	{
		ui.lineEdit_2->setFocus();
		ui.lineEdit_2->selectAll();
	}
}

void QPorackiSmetkiKorekcija::on_pushButton_2_clicked()
{
    CHelperClass hclass(this);
    if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
    {
        stat_artikal_call = 2;
		emit scallArtikli((QWidget*)this, ui.lineEdit_2->text());
    }
    else
    {
        ui.lineEdit_3->setFocus();
		ui.lineEdit_3->selectAll();
    }
}

void QPorackiSmetkiKorekcija::on_pushButton_9_clicked()
{
	CHelperClass hclass(this);
	if (!hclass.isArtikliExists(ui.lineEdit_9->text()))
	{
		stat_artikal_call = 9;
		emit scallArtikli((QWidget*)this, ui.lineEdit_9->text());
	}
	else
	{
		ui.lineEdit_10->setFocus();
		ui.lineEdit_10->selectAll();
	}
}


void QPorackiSmetkiKorekcija::on_pushButton_10_clicked()
{
	on_pushButton_7_clicked();
}

void QPorackiSmetkiKorekcija::on_pushButton_3_clicked()
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

	while (query.next()) {
		country1 = query.value(query.record().indexOf("id")).toString();
		country2 = query.value(query.record().indexOf("sifra")).toString();
		country3 = query.value(query.record().indexOf("artikal")).toString();
		country4 = query.value(query.record().indexOf("edm")).toString();
		country5 = query.value(query.record().indexOf("ddv")).toString();

		//        ui.lineEdit->setText(country1);
	}

	int row = model->rowCount();

	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	QStandardItem *item = new QStandardItem(country1);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(0, 50);
	model->setItem(row, 0, item);


	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	item = new QStandardItem(country2);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, 100);
	model->setItem(row, 1, item);

	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	item = new QStandardItem(country3);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 2, item);

	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
	item = new QStandardItem(country4);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 3, item);

	model->setHeaderData( 4, Qt::Horizontal, trUtf8("ДДВ (%)"));
	item = new QStandardItem(loc.toString(loc.toFloat(country5), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 4, item);

	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Количина"));
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_4->text()), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(6, 80);
	model->setItem(row, 5, item);

	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_3->text()), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 6, item);

	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	double iznos = (loc.toFloat(ui.lineEdit_3->text()) * 
		loc.toFloat(ui.lineEdit_4->text()) * 
		(1 - 0.f/100));
	item = new QStandardItem(loc.toString(iznos, 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 7, item);


	item = new QStandardItem(loc.toString(artikal_komintent_id.toInt())); // komintent id
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(8, 0);
	model->setItem(row, 8, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(9, 0);
	model->setItem(row, 9, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraNabCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(10, 0);
	model->setItem(row, 10, item);


	calculateIznosi();
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();

	ui.lineEdit_2->setText("");
	ui.lineEdit_3->setText("");
	ui.lineEdit_4->setText("");
	ui.lineEdit_7->setText("");
	ui.lineEdit_2->setFocus();
	textId = "-1";
}
void QPorackiSmetkiKorekcija::on_pushButton_7_clicked()
{
	CHelperClass hclass(this);
	if (!hclass.isArtikliExists(ui.lineEdit_9->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Податокот за артикал е невалиден\nОдбери артикал од листата на артикли!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_9->setFocus();
		return;
	}

	QLocale loc;
	if(textIdPlakanje.toInt() == -1)
	{
		return;
	}

	//m_id = textId.toInt();

	QString temp = "select id, sifra, artikal, edm, ddv from artikli where id =";
	temp += textIdPlakanje;
	QSqlQuery query(temp);
	QString country1 = "";
	QString country2 = "";
	QString country3 = "";
	QString country4 = "";
	QString country5 = "";

	while (query.next()) {
		country1 = query.value(query.record().indexOf("id")).toString();
		country2 = query.value(query.record().indexOf("sifra")).toString();
		country3 = query.value(query.record().indexOf("artikal")).toString();
		country4 = query.value(query.record().indexOf("edm")).toString();
		country5 = query.value(query.record().indexOf("ddv")).toString();

		//        ui.lineEdit->setText(country1);
	}

	int row = model2->rowCount();

	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	QStandardItem *item = new QStandardItem(country1);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(0, 50);
	model2->setItem(row, 0, item);


	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	item = new QStandardItem(country2);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(1, 100);
	model2->setItem(row, 1, item);

	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	item = new QStandardItem(country3);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(2, 250);
	model2->setItem(row, 2, item);

	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
	item = new QStandardItem(country4);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(2, 250);
	model2->setItem(row, 3, item);

	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("ДДВ (%)"));
	item = new QStandardItem(loc.toString(loc.toFloat(country5), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(2, 250);
	model2->setItem(row, 4, item);

	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Количина"));
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_4->text()), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(6, 80);
	model2->setItem(row, 5, item);

	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
	item = new QStandardItem(loc.toString(loc.toFloat(ui.lineEdit_3->text()), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(7, 80);
	model2->setItem(row, 6, item);

	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	double iznos = (loc.toFloat(ui.lineEdit_3->text()) * 
		loc.toFloat(ui.lineEdit_4->text()) * 
		(1 - 0.f/100));
	item = new QStandardItem(loc.toString(iznos, 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(7, 80);
	model2->setItem(row, 7, item);


	item = new QStandardItem(loc.toString(artikal_komintent_id.toInt())); // komintent id
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(8, 0);
	model2->setItem(row, 8, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(9, 0);
	model2->setItem(row, 9, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraNabCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView_2->setRowHeight(row, 18);
	ui.tableView_2->setColumnWidth(10, 0);
	model2->setItem(row, 10, item);


	calculateIznosi();
	QItemSelectionModel *sm = ui.tableView_2->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView_2->show();

	ui.lineEdit_9->setText("");
	ui.lineEdit_10->setText("");
	ui.lineEdit_9->setFocus();
	textIdPlakanje = "-1";
}


void QPorackiSmetkiKorekcija::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    selRow = modelX.row();
    editorOpen = false;
    emit closeCell();
}

void QPorackiSmetkiKorekcija::on_pushButton_6_clicked()
{
	selRow = ui.tableView->currentIndex().row();
	if (selRow == -1)
	{
		return;
	}
	
	model->removeRow(selRow);
	calculateIznosi();
}

void QPorackiSmetkiKorekcija::pressReturn()
{
	if (ui.pushButton_3->hasFocus())
	{
		on_pushButton_3_clicked();
	}
	else if (ui.pushButton_7->hasFocus())
	{
		on_pushButton_7_clicked();
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
void QPorackiSmetkiKorekcija::init(int id)
{
    QLocale loc;
    if(id == -1)
    {
        return;
    }
    m_id = id;
//    ui.lineEdit_5->setText(QString::number(id, 10));

    QString temp1 = 
        "select dokumenti.id, 0 , dok_id, datum, 0, 0, dokumenti.user_id "
        "from dokumenti "
        "where dokumenti.dok_tip = 48 and dokumenti.dok_id = ";        
    temp1 += QString::number(id, 10);
    QSqlQuery query1(temp1);
    while (query1.next())
    {
        komintentID = query1.value(1).toString();
        dokumentID = query1.value(0).toString();
        QString a = query1.value(0).toString();
		m_dok_id = query1.value(2).toString();
		m_user_id = query1.value(6).toInt();
    }

    int r = 0;
    int c = 11;
	int fieldNo[11];
    
	QString country[11];
    int colWidth[] = {40, 70, 220, 60, 100, 100, 100, 100, 0, 0, 0};
    QString colName[] = {"id", "sifra", "artikal", "edm", "ddv", "ikol", "prod_cena", "rabat" };
    QString temp = 
        "select artikli.id, sifra, artikal, edm, artikli.ddv, ikol, prod_cena, (ikol * prod_cena ) as iznos_so_ddv, 0, 0, 0 " 
        "from magacin "
        "left join artikli on magacin.artikal_id=artikli.id "
        "where magacin.dok_tip = 48 and magacin.dok_id= ";
    temp += QString::number(id, 10);
    QSqlQuery query(temp);
//     model = new QStandardItemModel(r,c);
// 	
// 	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
// 	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
// 	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
// 	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
// 	model->setHeaderData( 4, Qt::Horizontal, trUtf8("ДДВ (%)"));
// 	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Количина"));
// 	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
// 	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Рабат"));
// 	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Износ со ДДВ"));
	ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
    float vk_iznos = 0.f;
	while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            QStandardItem *item = NULL;
            QString temp = query.value(i).toString();
            if ((i > 3)&&(i<8))
            {
                temp = loc.toString(temp.toDouble(), 'f', 2);
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignRight);
            }
			else if (i == 8)
			{
				float iznos = temp.toDouble();
				vk_iznos += iznos;
				temp = loc.toString(temp.toDouble(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
            else
            {
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignLeft);
            }
            item->setEditable(false);
            ui.tableView->setRowHeight(row, 18);
            ui.tableView->setColumnWidth(i, colWidth[i]);
            model->setItem(row, i, item);
        }
        row++;
    } 
    ui.lineEdit->setText(loc.toString(vk_iznos, 'f', 2));
	QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();
	calculateIznosi();
//    ui.lineEdit->setFocus();
}

void QPorackiSmetkiKorekcija::on_pushButton_5_clicked()
{
    pressEscape();
}

void QPorackiSmetkiKorekcija::on_pushButton_4_clicked()
{

	QMessageBox msgBox;
	msgBox.setText(trUtf8("СМЕТКАТА ке биде КОРЕГИРАНА"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Cancel)
	{
		return;
	}


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
	QSqlQuery query1;
	query1.clear();
	query1.prepare("update dokumenti set dok_id = :a0, datum=:a1, tip_dokument= :a2 where id=:aid and dok_tip = 48");
	QString test = m_dok_id;
	query1.bindValue(":a0", m_dok_id);	
	query1.bindValue(":a1", QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));
	query1.bindValue(":a2", trUtf8("отворена сметка"));	
	query1.bindValue(":aid", dokumentID);	

	query1.exec();
	QSqlError err = query1.lastError();

	query1.clear();
	query1.prepare(
		"delete from magacin where dok_tip = 48 and dok_id = :a"
		);
	query1.bindValue(":a", mmid);	
	query1.exec();
	try
	{
		QStringList artList;
		QSqlQuery query;
		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = model->item(i, 0)->text();
			QString mArtikalSifra = model->item(i, 1)->text();
			QString mArtikalNaziv = model->item(i, 2)->text();
			QString mArtikalEdm = model->item(i, 3)->text();
			QString mArtikalKolicina = model->item(i, 5)->text();
			QString mArtikalCena = model->item(i, 6)->text();
			QString mArtikalRabat = "0";
			QString mArtikalItemKomintent = model->item(i, 8)->text();
			QString mArtikalStaraProdCena = model->item(i, 9)->text();
			QString mArtikalStaraNabCena = model->item(i, 10)->text();
			artList << mArtikalNaziv + "<>" + mArtikalCena + "<>" + mArtikalKolicina + "<>" + mArtikalID;
			QString mArtikalDDV = "";

			mArtikalRabat = mArtikalRabat.isEmpty() ? "0" : mArtikalRabat;
			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, prod_cena, rabat, komintent_id, stara_prod_cena, nab_cena) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8, :a9, :a10, :a11)"
				);
			query.bindValue(":a1", m_dok_id);	
			query.bindValue(":a2", 48);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", mArtikalCena);	
			query.bindValue(":a8", mArtikalRabat);	
			query.bindValue(":a9", mArtikalItemKomintent);	
			query.bindValue(":a10", mArtikalStaraProdCena);	
			query.bindValue(":a11", mArtikalStaraNabCena);	

			query.exec();
			QSqlError err = query.lastError();
		}

		QFiscalForm * uf = new QFiscalForm((QDialog*)this);
		uf->setIznos(ui.lineEdit->text());
		uf->setModal(true);
		if(uf->exec() == QDialog::Accepted)
		{
			//call fiscal printer

			msgBox.setText(trUtf8("Печати ФИСКАЛНА СМЕТКАТА !!!"));
			msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
			msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
			msgBox.setDefaultButton(QMessageBox::Ok);
			int ret = msgBox.exec();
			if (ret == QMessageBox::Ok)
			{
				CHelperClass chlp(this);
				int  statErr = (int)chlp.printFiscal(artList);
				QString errText = QString(statErr);
				QString info5 = "";
				if (!info5.contains("F"))
				{
					QString platenIznos = uf->getPlatenIznos();
					QSqlQuery query1;
					query1.clear();
					query1.prepare("update dokumenti set fisc_platen_iznos = :a0, tip_dokument = :a1 where dok_id=:aid and dok_tip = 48");
					query1.bindValue(":a0", platenIznos);	
					query1.bindValue(":a1", trUtf8("фискална сметка"));	
					query1.bindValue(":aid", m_id);	
					msgBox.setText(trUtf8("ФИСКАЛНАТА СМЕТКА\nЕ ОТПЕЧАТЕНА  !!!"));
					msgBox.setInformativeText(info5);
					msgBox.setStandardButtons(QMessageBox::Cancel);
					msgBox.setDefaultButton(QMessageBox::Cancel);
					msgBox.exec();

					query1.exec();
					QSqlError err = query1.lastError();
				}
				else
				{
					QString platenIznos = uf->getPlatenIznos();
					QSqlQuery query1;
					query1.clear();
					query1.prepare("update dokumenti set fisc_platen_iznos = :a0, tip_dokument = :a1 where dok_id=:aid and dok_tip = 48");
					query1.bindValue(":a0", platenIznos);	
					query1.bindValue(":a1", trUtf8("грешка -неиспечатена фискална сметка"));	
					query1.bindValue(":aid", m_id);	
					msgBox.setText(trUtf8("ФИСКАЛНАТА СМЕТКА\nНЕ Е ОТПЕЧАТЕНА  !!!"));
					msgBox.setInformativeText(info5);
					msgBox.setStandardButtons(QMessageBox::Cancel);
					msgBox.setDefaultButton(QMessageBox::Cancel);
					msgBox.exec();

					query1.exec();
					QSqlError err = query1.lastError();
				}
			}
		}
		pressEscape();
	}
	catch (...)
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Фактурата не е корегирана !!!."));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}

}

bool QPorackiSmetkiKorekcija::existDok(int idDok)
{
    int nCount = 0;
    QString temp = "select count(dok_id) br from dokumenti where dok_tip = 48 and dok_id =";
    temp += QString::number(idDok, 10);
    QSqlQuery query(temp);
    QString country1 = "";
    int fieldNo = query.record().indexOf("br");
    while (query.next()) {
        nCount = query.value(0).toInt() + 1;
    }
    return nCount > 0 ? true : false;
}

bool QPorackiSmetkiKorekcija::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
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
        if (object == ui.lineEdit_7)
        {
            ui.lineEdit_7->setStyleSheet("background-color: yellow");
        }
    }
    if (event->type() == QEvent::FocusOut)
    {
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
        if (object == ui.lineEdit_7)
        {
            ui.lineEdit_7->setStyleSheet("background-color: none");
        }
    }

    return false;
}

void QPorackiSmetkiKorekcija::on_plineEdit3_Pressed()
{
    ui.lineEdit_4->setFocus();
}

void QPorackiSmetkiKorekcija::on_plineEdit4_Pressed()
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
        on_pushButton_3_clicked();
    }
}

void QPorackiSmetkiKorekcija::on_plineEdit7_Pressed()
{
	CHelperClass hclass(this);
	if (!hclass.isKomintentExists(ui.lineEdit_7->text()))
	{
		emit scallKomintenti((QWidget*)this, ui.lineEdit_7->text());
	}
	else
	{
		ui.lineEdit_2->setFocus();
	}
}

void QPorackiSmetkiKorekcija::openEditor()
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

void QPorackiSmetkiKorekcija::closeEditor()
{
    ui.tableView->closePersistentEditor(indexPrev);
}

bool QPorackiSmetkiKorekcija::validateKomintent()
{
	bool stat = false;
// 	CHelperClass hclass(this);
// 	if (hclass.isKomintentExists(ui.lineEdit->text()))
// 	{
// 		stat = true;
// 	}
	return stat;
}

void QPorackiSmetkiKorekcija::calculateIznosi()
{
	QLocale loc;
	CHelperClass chc(this);
	int rows = model->rowCount();

	float sumTempIznossoDDV = 0.f;

	for (int i = 0; i < rows; i++)
	{
		sumTempIznossoDDV += loc.toFloat(model->item(i, 7)->text());
	}
	ui.lineEdit->setText(loc.toString(chc.rouded(sumTempIznossoDDV), 'f', 2));
}
