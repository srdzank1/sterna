#include "qizlezniSmetkivnes.h"
#include <QItemSelectionModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>
#include "chelperclass.h"
#include <QLocale>
#include "sterna.h"
#include <QDesktopWidget>
#include "qfiscalform.h"
#include "xx.h"


QIzlezniSmetkiVnes::QIzlezniSmetkiVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,selRow(-1)
    ,textId("")
    ,komintentID("")
    ,artikal_id(0)
    , pItemDelegate(0)
    , editorOpen(0)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
    ui.lineEdit_2->setFocus();
    ui.lineEdit_2->setText("");
    ui.lineEdit_2->selectAll();
    ui.lineEdit_2->setText("");
    ui.lineEdit_2->setStyleSheet("background-color: yellow");
    ui.lineEdit_2->installEventFilter(this);
    ui.lineEdit_2->installEventFilter(this);
    ui.lineEdit_3->installEventFilter(this);
    ui.lineEdit_4->installEventFilter(this);

   
    connect(ui.lineEdit_2, SIGNAL(returnPressed()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui.lineEdit_3, SIGNAL(returnPressed()), this, SLOT(on_plineEdit3_Pressed()));
    connect(ui.lineEdit_4, SIGNAL(returnPressed()), this, SLOT(on_plineEdit4_Pressed()));
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
}

void QIzlezniSmetkiVnes::pressF9()
{
	on_pushButton_4_clicked();
}


void QIzlezniSmetkiVnes::pressEscape()
{
    emit closeW();
}
void QIzlezniSmetkiVnes::setKomintent(QString text, QString textName)
{
}

void QIzlezniSmetkiVnes::setFocusLine()
{
}

void QIzlezniSmetkiVnes::setArtikli(QString text, QString textName, QString textKomintentId)
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
    ui.lineEdit_6->setText(query.value(0).toString());
}
void QIzlezniSmetkiVnes::setSaldo(QString text)
{
	ui.lineEdit_5->setText(text);
}

void QIzlezniSmetkiVnes::setProdCena(QString text)
{
	ui.lineEdit_3->setText(text);
	m_staraCena = text;
}

void QIzlezniSmetkiVnes::setNabCena(QString text)
{
	m_staraNabCena = text;
}

void QIzlezniSmetkiVnes::setFocusLine2()
{
    ui.lineEdit_2->setFocus();
    ui.lineEdit_2->selectAll();

}


void QIzlezniSmetkiVnes::on_pushButton_clicked()
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

void QIzlezniSmetkiVnes::lineEditPressReturn()
{
//    emit scallKomintenti((QWidget*)this, ui.lineEdit->text());
}

void QIzlezniSmetkiVnes::on_pushButton_2_clicked()
{
    CHelperClass hclass(this);
    if (!hclass.isArtikliExists(ui.lineEdit_2->text()))
    {
        emit scallArtikli((QWidget*)this, ui.lineEdit_2->text());
    }
    else
    {
        ui.lineEdit_4->setFocus();
		ui.lineEdit_4->setText("1");
		ui.lineEdit_4->selectAll();
    }
}

void QIzlezniSmetkiVnes::on_pushButton_3_clicked()
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

	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Рабат"));
	item = new QStandardItem(loc.toString(0.f, 'f', 2));
    item->setTextAlignment(Qt::AlignRight);
    item->setEditable(false);
    ui.tableView->setRowHeight(row, 18);
    ui.tableView->setColumnWidth(7, 0);
	model->setItem(row, 7, item);
	

	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Износ"));
	double iznos = (loc.toFloat(ui.lineEdit_3->text()) * 
		loc.toFloat(ui.lineEdit_4->text()) * 
		(1 - 0.f/100));
	item = new QStandardItem(loc.toString(iznos, 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(8, 80);
	model->setItem(row, 8, item);


	item = new QStandardItem(loc.toString(artikal_komintent_id.toInt())); // komintent id
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(9, 0);
	model->setItem(row, 9, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(10, 0);
	model->setItem(row, 10, item);

	item = new QStandardItem(loc.toString(hclass.rouded(loc.toFloat(m_staraNabCena)), 'f', 2));
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(11, 0);
	model->setItem(row, 11, item);

	calculateIznosi();
	QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();

    ui.lineEdit_2->setText("");
    ui.lineEdit_3->setText("");
    ui.lineEdit_4->setText("");
    ui.lineEdit_5->setText("");
    ui.lineEdit_6->setText("");
	ui.lineEdit_2->setFocus();
    textId = "-1";
}
void QIzlezniSmetkiVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    selRow = modelX.row();
    editorOpen = false;
    emit closeCell();
}

void QIzlezniSmetkiVnes::on_pushButton_6_clicked()
{
	selRow = ui.tableView->currentIndex().row();
	if (selRow == -1)
	{
		return;
	}

	model->removeRow(selRow);
	calculateIznosi();
}
void QIzlezniSmetkiVnes::pressReturn()
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


void QIzlezniSmetkiVnes::on_pushButton_4_clicked()
{

	QMessageBox msgBox;
	msgBox.setText(trUtf8("СМЕТКАТА ке биде Внесена"));
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

	int mid=0;
	try
	{
		int m_id = 1;
		QString temp = "select max(dok_id) from dokumenti where dok_tip = 48";
		QSqlQuery query(temp);
		QString country1 = "";
		int fieldNo = query.record().indexOf("max(dok_id)");
		while (query.next()) {
			m_id = query.value(0).toInt() + 1;
		}

		int row = model->rowCount();
		Singleton* ss = Singleton::Instance();
		QStringList info = ss->getUserInfo();
		int user_id = info.at(9).toInt();
		komintentID = "0";
		QDateTime currDateTime = QDateTime::currentDateTime();
		query.clear();
		query.prepare("insert into dokumenti(dok_id, dok_tip, datum, faktura_id, mag_id, komintent_id, rok, zabeleska, user_id, tip_dokument) values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8,:a9,:a10)");
		query.bindValue(":a1", m_id);	
		query.bindValue(":a2", 48);	
		query.bindValue(":a3", currDateTime.toString("dd-MM-yyyy hh:mm:ss"));	
		query.bindValue(":a4", 0);	
		query.bindValue(":a5", 0);	
		query.bindValue(":a6", komintentID);	
		query.bindValue(":a7", "0");	
		query.bindValue(":a8", "");	
		query.bindValue(":a9", user_id);	
		query.bindValue(":a10", trUtf8("отворена сметка"));	
		query.exec();

		query.clear();
		query.prepare("select max(id)mid from  dokumenti");
		query.exec();
		QStringList artList;

		for (int i = 0; i < rows; i++)
		{
			QString mTipDok = "P";
			QString mEmpty ="Empty";
			QString mArtikalID = model->item(i, 0)->text();
			QString mArtikalSifra = model->item(i, 1)->text();
			QString mArtikalNaziv = model->item(i, 2)->text();
			QString mArtikalEdm = model->item(i, 3)->text();
			QString mArtikalDDV = model->item(i, 4)->text();
			QString mArtikalKolicina = model->item(i, 5)->text();
			QString mArtikalCena = model->item(i, 6)->text();
			QString mRabat = model->item(i, 7)->text();
			QString artikalKomintentId = model->item(i, 9)->text();
			QString mstara_cena = model->item(i, 10)->text();
			QString mstara_nabcena = model->item(i, 11)->text();
	//		artList << mArtikalNaziv + "<>" + mArtikalCena + "<>" + mArtikalKolicina;
			
			QLocale loc;
			float fiscArtKol = loc.toFloat(mArtikalKolicina);
			float fiscArtCena = loc.toFloat(mArtikalCena);

			artList << mArtikalNaziv + "<>" + QString::number(fiscArtCena, 'f', 2) + "<>" +  QString::number(fiscArtKol, 'f', 3) + "<>" + mArtikalID;

			query.clear();
			query.prepare(
				"insert into magacin(dok_id, dok_tip, artikal_id, vkol, vcena, ikol, icena, rabat, prod_cena, komintent_id, stara_prod_cena, nab_cena) "
				"values(:a1,:a2,:a3,:a4,:a5,:a6,:a7,:a8, :a9, :a10, :a11, :a12)"
				);

			query.bindValue(":a1", m_id);	
			query.bindValue(":a2", 48);	
			query.bindValue(":a3", mArtikalID);	
			query.bindValue(":a4", 0);	
			query.bindValue(":a5", 0); 
			query.bindValue(":a6", mArtikalKolicina);	
			query.bindValue(":a7", 0);	
			query.bindValue(":a8", mRabat);	
			query.bindValue(":a9", mArtikalCena);	
			query.bindValue(":a10", artikalKomintentId);	
			query.bindValue(":a11", mstara_cena);	
			query.bindValue(":a12", mstara_nabcena);	
			
			query.exec();
			QSqlError err = query.lastError();
		}

// 		QMessageBox msgBox;
// 		msgBox.setText(trUtf8("Сметката е успешно внесена."));
// 		msgBox.setStandardButtons(QMessageBox::Ok);
// 		msgBox.setDefaultButton(QMessageBox::Ok);
// 		msgBox.exec();
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
				QString info5 = chlp.checkFiscal();
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

		QSqlQuery query;
		query.clear();
		query.prepare("delete from priemnici where id=:aid");
		query.bindValue(":aid", mid);	
		query.exec();

		query.clear();
		query.prepare("delete from magacin_artikli where document_id=:aid and vid_dokument=:vid");
		query.bindValue(":vid", "P");	
		query.bindValue(":aid", mid);	

		query.exec();

		QMessageBox msgBox;
		msgBox.setText(trUtf8("Сметката не е внесена !!!."));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
}

void QIzlezniSmetkiVnes::on_pushButton_5_clicked()
{
    pressEscape();
}


bool QIzlezniSmetkiVnes::existDok(int idDok)
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

bool QIzlezniSmetkiVnes::eventFilter(QObject *object, QEvent *event)
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
    }

    return false;
}

void QIzlezniSmetkiVnes::on_plineEdit3_Pressed()
{
    ui.lineEdit_4->setFocus();
	ui.lineEdit_4->selectAll();
}
void QIzlezniSmetkiVnes::on_plineEdit4_Pressed()
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

void QIzlezniSmetkiVnes::on_plineEdit6_Pressed()
{
       
}

void QIzlezniSmetkiVnes::openEditor()
{
    //	tableView->closePersistentEditor(indexPrev);
    QModelIndex index;
    QModelIndexList indexes = ui.tableView->selectionModel()->selection().indexes();
    index = indexes.at(0);	// To get the row/column numbers use 
    if (index.column() > 3)
    {
        ui.tableView->openPersistentEditor(index);
    }
    indexPrev = index;
}

void QIzlezniSmetkiVnes::closeEditor()
{
    ui.tableView->closePersistentEditor(indexPrev);
}



QIzlezniSmetkiVnes::~QIzlezniSmetkiVnes()
{

}

bool QIzlezniSmetkiVnes::validateKomintent()
{
 	bool stat = false;
// 	CHelperClass hclass(this);
// 	if (hclass.isKomintentExists(ui.lineEdit->text()))
// 	{
// 		stat = true;
// 	}
 	return stat;
}

void QIzlezniSmetkiVnes::calculateIznosi()
{
	QLocale loc;
	CHelperClass chc(this);
	int rows = model->rowCount();

	float sumTempIznossoDDV = 0.f;

	for (int i = 0; i < rows; i++)
	{
		sumTempIznossoDDV += loc.toFloat(model->item(i, 8)->text());
	}
	ui.lineEdit->setText(loc.toString((sumTempIznossoDDV), 'f', 2));
}
