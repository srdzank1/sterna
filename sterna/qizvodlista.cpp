#include "qizvodlista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include "chelperclass.h"
#include <QDesktopWidget>
#include <QSqlError>
#include <QMessageBox>
#include "xx.h"



QIzvodLista::QIzvodLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
    , pItemDelegate(0)
{

	ui.setupUi(this);

	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	listaBanki("%");
    pItemDelegate = new QSTableWidgetDelegate(ui.tableView);
    connect(this ,SIGNAL(editCell()),this,SLOT(openEditor()));
    connect(this ,SIGNAL(closeCell()),this,SLOT(closeEditor()));

    ui.tableView->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.tableView->setItemDelegate(pItemDelegate);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView_2->setEditTriggers(QAbstractItemView::CurrentChanged);
	ui.tableView_2->setItemDelegate(pItemDelegate);
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));
	ui.tableView_2->setFocus();
	listaBanki("%%%%");
}

void QIzvodLista::setIzvodiTable(QStringList &info)
{
	if(info.size() == 2)
	{
		QLocale loc;
		ui.tableView_2->selectRow(loc.toInt(info.at(0)));
		ui.tableView->selectRow(loc.toInt(info.at(1)));
	}
}
void QIzvodLista::on_lineEdit_textChanged(const QString & text)
{
    listaBanki(text);
}

QStringList QIzvodLista::getIndexTable()
{
	QStringList info;
	int selRowBanka = ui.tableView_2->currentIndex().row();
	int selRowIzvod = ui.tableView->currentIndex().row();
	info << QString::number(selRowBanka, 10) << QString::number(selRowIzvod, 10); 
	return info;
}
void QIzvodLista::setFocusLine()
{
//     ui.lineEdit->setFocus();
//     ui.lineEdit->selectAll();
}

QIzvodLista::~QIzvodLista()
{

}
void QIzvodLista::pressEscape()
{
	emit closeW();
}
void QIzvodLista::lista(const QString& nameSearch)
{
    ui.label_3->setText("");
	if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 6;
    int fieldNo[6];
    QString country[6];
    int colWidth[] = {0, 60, 80, 100, 100, 120};
    QString temp = 
	" select Izvodi.BankaId, Izvodi.IzvodBr, Datum, sum(Priliv) ,sum(Odliv) "
	" from (Izvodi "
	" left join Izvod_Stavki on "
	" Izvodi.bankaId = Izvod_Stavki.bankaId and Izvodi.IzvodBr = Izvod_Stavki.IzvodBr )"
	" group by Izvodi.BankaId, Izvodi.IzvodBr, Datum "
	" having Izvodi.BankaId = " + nameSearch;

	QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Жиро сметка"));    
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Извод бр."));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Прилив"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Одлив"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Извод-референца"));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
	ui.tableView->setHorizontalHeader(header);
	CHelperClass chlp(this);
	chlp.createListaIzvodiMap(nameSearch);
    header->show();
	int row = 0;
    float vkPriliv = 0.f;
    float vkOdliv = 0.f;
    float saldo = 0.f;
    QLocale loc;
    while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
			if (i < 2)
			{
				item = new QStandardItem(temp.left((10)));
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 2)
			{
                item = new QStandardItem(temp.left((10)));
				item->setTextAlignment(Qt::AlignRight);
			}
			else if ((i > 2)&&(i < 5))
			{
				temp = loc.toString(temp.toFloat(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 5)
			{
				temp = query.value(1).toString();
				temp = chlp.getIzvod_Ref(temp);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}

			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(i, colWidth[i]);
			model->setItem(row, i, item);
		}
		row++;
	} 
    
    QItemSelectionModel *sm2 = ui.tableView->selectionModel();
    connect(sm2, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged2(QModelIndex,QModelIndex)));
    ui.tableView_3->show();
	if (model->rowCount() > 0)
	{
		listaDetail(model->item(0, 0)->text(), model->item(0, 1)->text());
	}
	else
	{
		listaDetail("-1", "-1");
	}
}

void QIzvodLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model2->item(i, 0) ? model2->item(i, 0)->text() : "";
	lista(m_selectedText);
}

void QIzvodLista::deleteDok(int idDok)
{
    QSqlQuery query;
    query.clear();
    query.prepare(
        "delete from magacin where dok_tip = 40 and dok_id = :a"
        );
    query.bindValue(":a", idDok);	
    query.exec();
}

void QIzvodLista::on_pushButton_clicked()
{
    emit procF2();
}

void QIzvodLista::on_pushButton_2_clicked()
{
    emit procF3();
}

QStringList QIzvodLista::geInfo()
{
    QStringList info;
    info.clear();
    return info;
}
void QIzvodLista::setZiroSmetka(QString text, QString textName)
{
//      ui.lineEdit->setText(textName);
//      lista(text);
}

void QIzvodLista::openEditor()
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

void QIzvodLista::closeEditor()
{
    ui.tableView->closePersistentEditor(indexPrev);
}

void QIzvodLista::listaBanki(const QString& nameSearch)
{
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}
	int r = 0;
	int c = 6;
	int fieldNo[6];
	QString country[6];
	int colWidth[] = {30, 250, 150, 100, 100, 100};
	QString colName[] = {"BankId", "BankIme", "BankZiro", "Odliv","Priliv","Saldo"};
	QString temp = 
		" select BankID, BankIme, BankZiro, sum(Priliv), sum(Odliv), -sum(Odliv)+ sum(Priliv) "
		" from TBank "
		" left join Izvod_Stavki on TBank.BankID = Izvod_Stavki.BankaId "
		" group by BankID, BankIme, BankZiro "
		" order by BankID desc";
	QSqlQuery query(temp);
	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Назив"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Жиро сметка"));
    model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Прилив"));
    model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Одлив"));
    model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Салдо"));

    ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
    QLocale loc;
	int row = 0;
	while (query.next()) 
	{
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = i; //query.record().indexOf(colName[i]);
            QStandardItem *item = NULL;
            QString temp = query.value(fieldNo[i]).toString();
            if (i > 2)
            {
                temp = loc.toString(temp.toFloat(), 'f', 2);
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignRight);
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
	QItemSelectionModel *sm = ui.tableView_2->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView_2->show();
	if (model2->rowCount() > 0)
	{
		lista(model2->item(0, 0)->text());
	}
	else
	{
		lista("-1");
	}
}

void QIzvodLista::listaDetail(const QString& nameSearch, const QString& nameSearch2)
{
    ui.label_3->setText("");
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 7;
    int fieldNo[7];
    QString country[7];
    int colWidth[] = {50, 50, 350, 100, 100, 0, 0};
    QString colName[] = {"opis", "faktura_id", "priliv", "odliv"};
    QString temp = 
        " select  Izvod_Stavki.IzvodBr, komintenti.id, komintenti.naziv, priliv, odliv, Izvod_Stavki.BankaId, Izvod_Stavki.MKey "
        " from (Izvod_Stavki "
		" left join komintenti on Izvod_Stavki.KomintentBr = komintenti.id)"
        " where BankaId =" + nameSearch + " and IzvodBr =" + nameSearch2;    
	
    QSqlQuery query(temp);
    model3 = new QStandardItemModel(r,c);
    model3->setHeaderData( 0, Qt::Horizontal, trUtf8("Извод Бр."));    
    model3->setHeaderData( 1, Qt::Horizontal, trUtf8("Ком.Ид"));
    model3->setHeaderData( 2, Qt::Horizontal, trUtf8("Назив"));
	model3->setHeaderData( 3, Qt::Horizontal, trUtf8("Прилив"));
	model3->setHeaderData( 4, Qt::Horizontal, trUtf8("Одлив"));
	model3->setHeaderData( 5, Qt::Horizontal, trUtf8("Банка Ид"));
	model3->setHeaderData( 6, Qt::Horizontal, trUtf8("МК"));

    ui.tableView_3->setModel(model3);
    header3 = new QHeaderView(Qt::Horizontal, this);
    header3->setSectionsClickable(true);
    ui.tableView_3->setHorizontalHeader(header3);
    header3->show();
    int row = 0;
    float vkPriliv = 0.f;
    float vkOdliv = 0.f;
    float saldo = 0.f;
    QLocale loc;
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = i; //query.record().indexOf(colName[i]);
            QStandardItem *item = NULL;
            QString temp = query.value(fieldNo[i]).toString();
            
			if (i > 2 && i < 5)
            {
                temp = loc.toString(temp.toFloat(), 'f', 2);
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignRight);
            }
			else
            {
                item = new QStandardItem(temp);
                item->setTextAlignment(Qt::AlignLeft);
            }
            item->setEditable(false);
            ui.tableView_3->setRowHeight(row, 18);
            ui.tableView_3->setColumnWidth(i, colWidth[i]);
            model3->setItem(row, i, item);
        }
        row++;
    } 
	QItemSelectionModel *sm3 = ui.tableView_3->selectionModel();
	connect(sm3, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged3(QModelIndex,QModelIndex)));
    ui.tableView_3->show();
	if (model3->rowCount() > 0)
	{
		listaDetailPlakanje(model3->item(0, 5)->text(), model3->item(0, 0)->text(), model3->item(0, 1)->text(), model3->item(0, 6)->text());
	}
	else
	{
		listaDetailPlakanje("-1", "-1", "-1", "-1");
	}

}

void QIzvodLista::listaDetailPlakanje(const QString& nameSearch, const QString& nameSearch2, const QString& nameSearch3, const QString& nameSearch4)
{
	ui.label_3->setText("");
	if (nameSearch.length() < 0)
	{
		ui.tableView->hide();
		return;
	}
	int r = 0;
	int c = 3;
	int fieldNo[3];
	QString country[3];
	int colWidth[] = {100, 150, 250};
	QString colName[] = {"opis", "faktura_id", "priliv", "odliv"};
	QString temp = 
		" select  Izvod_Plakanje.Dok_Id, Izvod_Plakanje.Dok_Tip, Izvod_Plakanje.IznosPlaten "
		" from Izvod_Plakanje "
		" where BankaId =" + nameSearch 
		+ " and IzvodBr =" + nameSearch2 
		+ " and Izvod_Plakanje.KomintentBr =" + nameSearch3 
		+ " and Izvod_Plakanje.MKey ='" + nameSearch4 +"'";    

	QSqlQuery query(temp);
	model4 = new QStandardItemModel(r,c);
	model4->setHeaderData( 0, Qt::Horizontal, trUtf8("Документ Бр."));    
	model4->setHeaderData( 1, Qt::Horizontal, trUtf8("Тип Документ"));
	model4->setHeaderData( 2, Qt::Horizontal, trUtf8("Платен Износ"));

	ui.tableView_4->setModel(model4);
	header4 = new QHeaderView(Qt::Horizontal, this);
    header4->setSectionsClickable(true);
	ui.tableView_4->setHorizontalHeader(header4);
	header4->show();
	int row = 0;
	float vkPriliv = 0.f;
	float vkOdliv = 0.f;
	float saldo = 0.f;
	QLocale loc;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();

			if (i == 2)
			{
				temp = loc.toString(temp.toFloat(), 'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 1)
			{
				temp = loc.toString(temp.toFloat(), 'f', 2);
				if (temp.toFloat() == 40)
				{
					temp = trUtf8("ИЗЛЕЗНА ФАКТУРА");
				}
				else if (temp.toFloat() == 20)
				{
					temp = trUtf8("ВЛЕЗНА ФАКТУРА");
				}
				else if (temp.toFloat() == 21)
				{
					temp = trUtf8("ИЗЈАВА");
				}
				else if (temp.toFloat() == 25)
				{
					temp = trUtf8("ПОВРАТНИЦА");
				}

				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			else
			{
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignLeft);
			}
			item->setEditable(false);
			ui.tableView_4->setRowHeight(row, 18);
			ui.tableView_4->setColumnWidth(i, colWidth[i]);
			model4->setItem(row, i, item);
		}
		row++;
	} 
	ui.tableView_4->show();
}

void QIzvodLista::selectionChanged2(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text() : "";
	m_selectedText2 = model->item(i, 1) ? model->item(i, 1)->text() : "";

	listaDetail(m_selectedText, m_selectedText2);
}

void QIzvodLista::selectionChanged3(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model3->item(i, 5) ? model3->item(i, 5)->text() : "";
	m_selectedText2 = model3->item(i, 0) ? model3->item(i, 0)->text() : "";
	m_selectedText3 = model3->item(i, 1) ? model3->item(i, 1)->text() : "";
	m_selectedText4 = model3->item(i, 6) ? model3->item(i, 6)->text() : "";

	listaDetailPlakanje(m_selectedText, m_selectedText2, m_selectedText3, m_selectedText4);
}


void QIzvodLista::on_pushButton_3_clicked()
{
    deleteStavka(m_selectedText, m_selectedText2);
}

void QIzvodLista::deleteStavka(const QString& nameSearch, const QString& nameSearch2)
{
    if (nameSearch.isEmpty()||nameSearch2.isEmpty())
    {
        return;
    }
    QMessageBox msgbox;
    msgbox.setWindowTitle("Warning"); //this is ignore on mac
    msgbox.setText(trUtf8("Селектираниот извод од \nлистата на изводи ке биде избришан!!!")); //set message box text
    msgbox.addButton(QMessageBox::Ok); //add ok button
    msgbox.addButton(QMessageBox::Cancel); //add cancel button
    int status = msgbox.exec(); //display message box
    /* display which option was choosen */
    if (status == QMessageBox::Ok)
    {
        QSqlError err;
        QSqlQuery query;
        int row = model->rowCount();
        query.clear();
        query.prepare("delete from TStavka where ZiroSmetka_ID = :a and Izvod_br = :b");
        query.bindValue(":a", nameSearch);	
        query.bindValue(":b", nameSearch2.toInt());	
        query.exec();
        err = query.lastError();

        if (err.isValid ())
        {
            QMessageBox msgBox;
            msgBox.setText(trUtf8("Ставката НЕ Е избришана."));
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        
        } 
        else
        {
            QMessageBox msgBox;
            msgBox.setText(trUtf8("Ставката е успешно избришана."));
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            lista(nameSearch);
        }
    }
}


