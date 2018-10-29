#include "qizvodvnes.h"
#include <QItemSelectionModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>
#include "chelperclass.h"
#include <QDesktopWidget>
#include "xx.h"

QIzvodVnes::QIzvodVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
    , selRow(-1)
    , textId("")
    , komintentID("")
    , artikal_id(0)
    , pItemDelegate(0)
    , editorOpen(0)
    , m_ZiroSmetka("")
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
	ui.lineEdit_8->installEventFilter(this);


    ui.dateTimeEdit->installEventFilter(this);
    
	connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(callProcBanki()));
	connect(ui.lineEdit_2, SIGNAL(returnPressed()), this, SLOT(callProcKomintenti()));
	connect(ui.lineEdit_3, SIGNAL(returnPressed()), this, SLOT(callProcLineEdit3()));
	connect(ui.lineEdit_4, SIGNAL(returnPressed()), this, SLOT(callProcLineEdit4()));
	connect(ui.lineEdit_5, SIGNAL(returnPressed()), this, SLOT(callProcLineEdit5()));


    connect(ui.lineEdit_8, SIGNAL(returnPressed()), this, SLOT(on_pRadioButton8_Pressed()));
    connect(ui.dateTimeEdit, SIGNAL(mousePressEvent ( QMouseEvent * )), this, SLOT(on_pDateTime_Pressed( QMouseEvent *)));

    ui.dateTimeEdit->setDate(QDate::currentDate());
    pItemDelegate = new QSTableWidgetDelegate(ui.tableView);
    connect(this ,SIGNAL(editCell()),this,SLOT(openEditor()));
    connect(this ,SIGNAL(closeCell()),this,SLOT(closeEditor()));

    ui.tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.tableView->setItemDelegate(pItemDelegate);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));


    model = new QStandardItemModel(0,7);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Датум"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Коминтент Ид."));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Коминтент Назив"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Прилив"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Одлив"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Ф-ра"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Key"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	header->show();

	model2 = new QStandardItemModel(0,6);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Коминтент Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Коминтент Назив"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Фактура Бр."));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Датум."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Неплатен Износ"));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Платено"));


	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();


}

QIzvodVnes::~QIzvodVnes()
{

}

void QIzvodVnes::pressEscape()
{
	emit closeW();
}

void QIzvodVnes::pressF9()
{
	on_pushButton_4_clicked();	
}

void QIzvodVnes::setZiroSmetka(QString text, QString textName)
{
	ui.lineEdit->setText(textName);
    m_ZiroSmetka = text;
	/// presmetaj /// izvod_broj ///////////////////////////////////////////////

	QSqlQuery query;
	query.clear();
	query.prepare("select max(izvodbr)+1 from Izvodi where bankaid = :bid");
	query.bindValue(":bid", m_ZiroSmetka);	
	query.exec();

	while (query.next()) 
	{
		ui.lineEdit_8->setText(query.value(0).toString());
	}

	///////////////////////////////////////////////////////////////////////

}

void QIzvodVnes::setFocusLine()
{
    ui.lineEdit->setFocus();
    ui.lineEdit->selectAll();
}
void QIzvodVnes::insertRowTable2(std::vector<sostavInfo> &rowData)
{
	QString tempKomintent_Id;
	QString tempKomintent_Naziv;
	QString tempFaktura_Id;
	QString datum_Id;
	QString tempIznoszaPlakanje;
	QString tempPlatenIznos;
	model2->clear();
	
	model2 = new QStandardItemModel(0,6);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Коминтент Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Коминтент Назив"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Фактура Бр."));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Датум."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Неплатен Износ"));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Платено"));

	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();

	setUpdatesEnabled(false);
	for (int rr = 0; rr < rowData.size(); rr++)
	{
		QBrush b;
		int row = model2->rowCount();
		// date
		QStandardItem *item = new QStandardItem(rowData.at(rr).datum);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(3, 120);
		model2->setItem(row, 3, item);
		// коминтент Ид
		QString tipTemp = rowData.at(rr).komintent_id;
		item = new QStandardItem(tipTemp);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(0, 50);
		model2->setItem(row, 0, item);
		// коминтент Назив
		QString tipTemp1 = rowData.at(rr).komintent_naziv;
		item = new QStandardItem(tipTemp1);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(1, 250);
		model2->setItem(row, 1, item);
		// фактура бр.
		tipTemp1 = rowData.at(rr).faktura_id;
		item = new QStandardItem(tipTemp1);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(2, 0);
		model2->setItem(row, 2, item);
// 		QLocale loc;
// 		QString priliv = loc.toString( loc.toFloat(ui.lineEdit_3->text()), 'f', 2);
// 		QString odliv = loc.toString( loc.toFloat(ui.lineEdit_4->text()), 'f', 2);
		// priliv
		item = new QStandardItem(rowData.at(rr).neplaten_iznos);
		item->setTextAlignment(Qt::AlignRight);
		b.setColor(Qt::darkGreen);
		item->setForeground(b);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(4, 100);
		model2->setItem(row, 4, item);
		// odliv
		item = new QStandardItem(rowData.at(rr).plateno);
		item->setTextAlignment(Qt::AlignRight);
		b.setColor(Qt::darkRed);
		item->setForeground(b);
		item->setEditable(false);
		item->setEditable(false);
		ui.tableView_2->setRowHeight(row, 18);
		ui.tableView_2->setColumnWidth(5, 100);
		model2->setItem(row, 5, item);
	}
	ui.lineEdit_2->setText("");
	ui.lineEdit_3->setText("");
	setUpdatesEnabled(true);
	ui.tableView_2->show();
	textId = "-1";
}
void QIzvodVnes::setFakturi(QStringList& listData)
{
	insertRowTable2Map(listData);
	std::map<QString, std::vector<sostavInfo>>::iterator it;
	it = m_map.find(m_randomId);
	if (it != m_map.end())
	{
		insertRowTable2(it->second);
	}
}

void QIzvodVnes::insertRowTable2Map(QStringList& listData)
{
	QLocale loc;
	float f_priliv = loc.toFloat(m_prilivItem);
	float f_odliv = loc.toFloat(m_odlivItem);
	int tip_priliv = f_priliv-f_odliv > 0 ? 1 : 0;
	float f_vk = 0.f;
	if (tip_priliv)
	{
		f_vk = f_priliv;
	} 
	else
	{
		f_vk = f_odliv;
	}

	typeSostavVector itemsVector;
	QString key = "";
	for(int i = 0; i< listData.count(); i++)
	{
		QStringList rowData = listData.at(i).split(" :: ");
		sostavInfo item;
		QString tip = rowData.at(14).trimmed();
		float f_neplatenIznos = 0.f;
		if(tip == "40")
		{
			key = m_randomId;
			item.komintent_id = rowData.at(13).trimmed();
			item.komintent_naziv = rowData.at(3).trimmed();
			item.faktura_id = rowData.at(1).trimmed();
			item.datum = rowData.at(2).trimmed();
			item.faktura_tip = tip; 
			f_neplatenIznos = loc.toFloat(rowData.at(8).trimmed());
		}
		else
		{
			key = m_randomId;
			item.komintent_id = rowData.at(10).trimmed();
			item.komintent_naziv = rowData.at(3).trimmed();
			item.faktura_id = rowData.at(1).trimmed();
			item.datum = rowData.at(2).trimmed();
			item.faktura_tip = tip; 
			f_neplatenIznos = loc.toFloat(rowData.at(4).trimmed());
		}

		CHelperClass chlp(this);

		QLocale loc;
		float vk_plakanja = loc.toFloat(chlp.getPlatenIznosZaFaktura( tip, item.faktura_id));
		f_neplatenIznos -= vk_plakanja;

		float f_platenIznos = 0.f;
		if ((f_neplatenIznos > 0)&&( f_vk >= f_neplatenIznos))
		{
			f_platenIznos = f_neplatenIznos;
			f_vk -= f_platenIznos; 
		}
		else if ((f_neplatenIznos > 0)&&( f_vk < f_neplatenIznos))
		{
			f_platenIznos = f_vk;
			f_vk = 0;
		}
		else
		{
			continue;
		}

		item.neplaten_iznos = loc.toString(f_neplatenIznos, 'f', 2);
		item.plateno = loc.toString(f_platenIznos, 'f', 2);
		if(f_platenIznos != 0.f)
		{
			itemsVector.push_back(item);
		}
	}
	if (itemsVector.size() >0)
	{
		m_map.insert(std::pair<QString, typeSostavVector>(key, itemsVector) );
	}

	int stop = 0;	
}

void QIzvodVnes::setKomintent(QString text, QString textName)
{
	m_komintent_id = text;
	m_komintent_name = textName;
	ui.lineEdit_2->setText(m_komintent_name);
	int stop = 0;
}


void QIzvodVnes::setFocusLine2()
{
	ui.lineEdit_2->setFocus();
	ui.lineEdit_2->selectAll();

}


void QIzvodVnes::on_pushButton_clicked()
{
	CHelperClass hclass(this);
	QString  dok_tip = "";
	int tip = 0;

	tip = 1;

	//setEnabledFields(false);

	if (!hclass.isFakturaExists(ui.lineEdit_2->text(), dok_tip))
	{
		emit signFakturiFromIzvod((QWidget*)this, m_komintent_name, tip);
	}
}

void QIzvodVnes::lineEditPressReturn()
{
}

void QIzvodVnes::setEnabledFields(bool stat)
{
    ui.lineEdit_3->setReadOnly(stat);
    ui.lineEdit_3->setEnabled(stat);
}

void QIzvodVnes::on_pushButton_2_clicked()
{
	CHelperClass hclass(this);
	QString  dok_tip = "";
	int tip = 0;

	tip = 2;
    
    setEnabledFields(false);

    if (!hclass.isFakturaExists(ui.lineEdit_2->text(), dok_tip))
	{
		emit signFakturiFromIzvod((QWidget*)this, m_komintent_name, tip);
	}
}

void QIzvodVnes::on_pushButton_3_clicked()
{
	QBrush b;

	int row = model->rowCount();
    
    // date
	QStandardItem *item = new QStandardItem(ui.dateTimeEdit->date().toString("yyyy-MM-dd"));
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(0, 120);
	model->setItem(row, 0, item);
    
    // коминтент Ид
	QString tipTemp = m_komintent_id;


	item = new QStandardItem(tipTemp);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, 50);
	model->setItem(row, 1, item);
    
	// коминтент Назив
	QString tipTemp1 = m_komintent_name;


	item = new QStandardItem(tipTemp1);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, 50);
	model->setItem(row, 2, item);

	QLocale loc;
    QString priliv = loc.toString( loc.toFloat(ui.lineEdit_3->text()), 'f', 2);
    QString odliv = loc.toString( loc.toFloat(ui.lineEdit_4->text()), 'f', 2);

    // priliv
    item = new QStandardItem(priliv);
    item->setTextAlignment(Qt::AlignRight);
   
    b.setColor(Qt::darkGreen);
    item->setForeground(b);
    item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(3, 100);
	model->setItem(row, 3, item);
    
    // odliv
	item = new QStandardItem(odliv);
    item->setTextAlignment(Qt::AlignRight);
   
    b.setColor(Qt::darkRed);
    item->setForeground(b);
    item->setEditable(false);
    item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(4, 100);
	model->setItem(row, 4, item);
    
    // faktura
	item = new QStandardItem(QString::number(ui.lineEdit_2->text().toInt()));
    item->setTextAlignment(Qt::AlignRight);
    item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(5, 0);
	model->setItem(row, 5, item);

	// random string
	CHelperClass chlp(this);
	item = new QStandardItem(chlp.GetRandomString());
	item->setTextAlignment(Qt::AlignRight);
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(6, 0);
	model->setItem(row, 6, item);

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();

	ui.lineEdit_3->setText("");
	ui.lineEdit_2->setText("");
	ui.lineEdit_4->setText("");

	ui.tableView->setFocus();
    ui.lineEdit_2->setFocus();
	ui.pushButton_3->setEnabled(false);
	textId = "-1";


}
void QIzvodVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
	QLocale loc;
	selRow = modelX.row();
	if (selRow == -1)
	{
		model2->clear();
		return;
	}
	int iii= 0;
	m_komintent_id = model->item(selRow, 1)->text();
	m_komintent_name = model->item(selRow, 2)->text();
	m_randomId = model->item(selRow, 6)->text();
	m_prilivItem = model->item( selRow, 3)->text();
	m_odlivItem = model->item( selRow, 4)->text();

	float prilivTemp = loc.toFloat(m_prilivItem);
	float odlivTemp = loc.toFloat(m_odlivItem);
	if (prilivTemp > odlivTemp)
	{
		ui.pushButton->setEnabled(true);
		ui.pushButton_2->setEnabled(false);
	}
	else
	{
		ui.pushButton_2->setEnabled(true);
		ui.pushButton->setEnabled(false);
	}

	std::map<QString, std::vector<sostavInfo>>::iterator it;
	it = m_map.find(m_randomId);
	if (it != m_map.end())
	{
		insertRowTable2(it->second);
	}
	else
	{
		model2->clear();
	}
	editorOpen = false;
	emit closeCell();
}

void QIzvodVnes::on_pushButton_6_clicked()
{
	selRow = ui.tableView->currentIndex().row();
	if (selRow == -1)
	{
		return;
	}

	m_komintent_id = model->item(selRow, 1)->text();

	std::map<QString, std::vector<sostavInfo>>::iterator it;
	it = m_map.find(m_komintent_id);
	if (it != m_map.end())
	{
		m_map.erase(it);
	}

	model->removeRow(selRow);

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}

void QIzvodVnes::pressReturn()
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


void QIzvodVnes::on_pushButton_4_clicked()
{
    
 	CHelperClass *chlp = new CHelperClass(this);
	if (chlp->isIzvodExists(m_ZiroSmetka, ui.lineEdit_8->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Извод со тој број постои!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	delete chlp;
	int cols = model->columnCount();
	int rows = model->rowCount();
	if (!rows)
	{
		return;
	}

    int mid = 0;
    QSqlError err;
    try
    {
		QSqlQuery query;
		int row = model->rowCount();
		
		QString mBankaId = m_ZiroSmetka;
		QString mIzvodBr = ui.lineEdit_8->text();
		
		Singleton* ss = Singleton::Instance();
		QStringList info = ss->getUserInfo();
		int user_id = info.at(9).toInt();
		QString mIzvodRef = ui.lineEdit_5->text();
		
		query.clear();
		query.prepare("insert into Izvodi(BankaId, IzvodBr, Datum, user_id, izvod_ref) values(:a1, :a2, :a3, :a4, :a5)");
		query.bindValue(":a1", mBankaId);	
		query.bindValue(":a2", mIzvodBr);	
		query.bindValue(":a3", ui.dateTimeEdit->dateTime());	
		query.bindValue(":a4", user_id);	
		query.bindValue(":a5", mIzvodRef);	

		query.exec();
		err = query.lastError();
		
		for (int i = 0; i < rows; i++)
		{
			QString mmDatum = model->item(i, 0)->text();
			QString mmKomintentId = model->item(i, 1)->text();
			QString mmKomintentNaziv = model->item(i, 2)->text();
			QString mmPriliv = model->item(i, 3)->text();
			QString mmOdliv = model->item(i, 4)->text();
			QString mmKey = model->item(i, 6)->text();

			int row = model->rowCount();
			query.clear();
			query.prepare("insert into Izvod_Stavki(IzvodBr, KomintentBr, Priliv, Odliv, BankaId, MKey) values(:a1, :a2, :a3, :a4, :a5, :a6)");
			query.bindValue(":a1", mIzvodBr);	
			query.bindValue(":a2", mmKomintentId);	
			query.bindValue(":a3", mmPriliv);	
			query.bindValue(":a4", mmOdliv);	
			query.bindValue(":a5", mBankaId);	
			query.bindValue(":a6", mmKey);	

			query.exec();
			err = query.lastError();

			std::map<QString, std::vector<sostavInfo>>::iterator it;
			it = m_map.find(mmKey);
			if (it != m_map.end())
			{
				for (int t = 0; t < it->second.size(); t++)
				{
					sostavInfo tempItem = it->second.at(t);
					int row = model->rowCount();
					query.clear();
					query.prepare("insert into Izvod_Plakanje(BankaId, IzvodBr, KomintentBr, Dok_Id, Dok_Tip, IznosPlaten, MKey ) values(:a1, :a2, :a3, :a4, :a5, :a6, :a7)");
					query.bindValue(":a1", mBankaId);	
					query.bindValue(":a2", mIzvodBr);	
					query.bindValue(":a3", mmKomintentId);	
					query.bindValue(":a4", tempItem.faktura_id);	
					query.bindValue(":a5", tempItem.faktura_tip);	
					query.bindValue(":a6", tempItem.plateno);	
					query.bindValue(":a7", mmKey);	

					query.exec();
					err = query.lastError();
				}
			}
		}
		if (err.isValid ())
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Изводот НЕ Е внесен."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
		} 
		else
		{
            QMessageBox msgBox;
            msgBox.setText(trUtf8("Изводот е успешно внесен."));
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            pressEscape();
        }
    }
    catch (...)
    {
    }
}


void QIzvodVnes::on_pushButton_5_clicked()
{
	pressEscape();
}


bool QIzvodVnes::existDok(int idDok)
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

bool QIzvodVnes::eventFilter(QObject *object, QEvent *event)
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
        if (object == ui.dateTimeEdit)
        {
            ui.dateTimeEdit->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_8)
        {
            ui.lineEdit_8->setStyleSheet("background-color: yellow");
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
        if (object == ui.dateTimeEdit)
        {
            ui.dateTimeEdit->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_8)
        {
            ui.lineEdit_8->setStyleSheet("background-color: none");
        }

	}
	return false;
}


void QIzvodVnes::on_plineEdit7_Pressed()
{
}
void QIzvodVnes::on_plineEdit6_Pressed()
{
    on_pushButton_3_clicked();
}
void QIzvodVnes::openEditor()
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

void QIzvodVnes::closeEditor()
{
    updatePlakanje();
	ui.tableView->closePersistentEditor(indexPrev);
}

void QIzvodVnes::on_pRadioButton_Pressed()
{
    ui.lineEdit_8->setFocus();
}
void QIzvodVnes::on_pRadioButton2_Pressed()
{
    ui.lineEdit_2->setFocus();
}

void QIzvodVnes::on_pRadioButton8_Pressed()
{
    CHelperClass chlp(this);
	if (chlp.isIzvodExists(m_ZiroSmetka, ui.lineEdit_8->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Извод со тој број постои!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
	else
	{
		ui.lineEdit_2->setFocus();
	}
}

void QIzvodVnes::on_pDateTime_Pressed( QMouseEvent *)
{
   
}

void QIzvodVnes::callProcBanki()
{
	CHelperClass hclass(this);
	if (!hclass.isBankExists(ui.lineEdit->text()))
	{
		emit signBankiFromIzvod((QWidget*)this, ui.lineEdit->text());
	}
	else
	{
		ui.lineEdit_5->setFocus();
	}
}

void QIzvodVnes::callProcKomintenti()
{
	CHelperClass hclass(this);
	if (!hclass.isKomintentExists(ui.lineEdit_2->text()))
	{
		emit scallKomintenti((QWidget*)this, ui.lineEdit_2->text());
	}
	else
	{
		ui.pushButton_3->setEnabled(true);
		ui.lineEdit_3->setFocus();
	}
}


void QIzvodVnes::callProcLineEdit3()
{
	ui.lineEdit_4->setFocus();
}

void QIzvodVnes::callProcLineEdit4()
{
	ui.pushButton_3->setFocus();
}
void QIzvodVnes::updatePlakanje()
{
	selRow = ui.tableView->currentIndex().row();
	QString mkey   = model->item(selRow, 6)->text();
		QLocale loc;
		float priliv = loc.toFloat(model->item(selRow, 3)->text());
		float odliv  = loc.toFloat(model->item(selRow, 4)->text());
		std::map<QString , std::vector<sostavInfo>>::iterator it = m_map.find(mkey); 
		if (it != m_map.end())
		{
			std::vector<sostavInfo> temp = it->second;
			if (temp.size() == 1)
			{
				((sostavInfo)it->second.at(0)).plateno = QString::number(priliv + odliv, 'f', 2);
				temp.at(0).plateno = QString::number(priliv + odliv, 'f', 2);
				int stop = 0;
				it->second = temp;
				insertRowTable2(it->second);
			}
		}
}


void QIzvodVnes::callProcLineEdit5()
{
	ui.lineEdit_2->setFocus();
}
