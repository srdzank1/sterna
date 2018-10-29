#include "qprofakturavnes.h"
#include <QItemSelectionModel>
#include <QSqlQuery>
#include <QMessageBox>


QProFakturiVnes::QProFakturiVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,selRow(-1)
	,textId("")
{
	ui.setupUi(this);
	ui.pushButton->setFocus();
	model = new QStandardItemModel(0,8);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф."));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Катал. број"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Цена"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Количина"));
	ui.lineEdit->setText("Press Lista na komintenti ->");
	ui.lineEdit->selectAll();

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
	ui.tableView->setHorizontalHeader(header);
	header->show();
}

QProFakturiVnes::~QProFakturiVnes()
{

}

void QProFakturiVnes::pressEscape()
{
	emit closeW();
}
void QProFakturiVnes::setKomintent(QString text, QString textName)
{
	ui.lineEdit->setText(textName);
}

void QProFakturiVnes::setFocusLine()
{
	ui.lineEdit->setFocus();
}

void QProFakturiVnes::setArtikli(QString text, QString textName)
{
	ui.lineEdit_2->setText(textName);
	textId = text;
}
void QProFakturiVnes::setFocusLine2()
{
	ui.lineEdit_2->setFocus();
}
void QProFakturiVnes::pressReturn()
{
	if (ui.pushButton->hasFocus())
	{
		on_pushButton_clicked();
	}
	else if (ui.pushButton_2->hasFocus())
	{
		on_pushButton_2_clicked();
	}
	else if (ui.pushButton_3->hasFocus())
	{
		on_pushButton_3_clicked();
	}
	else if (ui.pushButton_6->hasFocus())
	{
		on_pushButton_6_clicked();
	}
}

void QProFakturiVnes::on_pushButton_clicked()
{
	emit scallKomintenti((QWidget*)this);
}

void QProFakturiVnes::on_pushButton_2_clicked()
{
	emit scallArtikli((QWidget*)this);
}

void QProFakturiVnes::on_pushButton_3_clicked()
{
	if(textId.toInt() == -1)
	{
		return;
	}

	QSqlQuery query;
	query.prepare("select * from artikli where id = :id");
	query.bindValue(":id", textId.toInt());	
	query.exec();
	int  r= query.numRowsAffected();
	query.next();	
	int row = model->rowCount();

	QStandardItem *item = new QStandardItem(query.value(0).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(0, 50);
	model->setItem(row, 0, item);

	item = new QStandardItem(query.value(1).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(1, 50);
	model->setItem(row, 1, item);

	item = new QStandardItem(query.value(2).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(2, 250);
	model->setItem(row, 2, item);

	item = new QStandardItem(query.value(3).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(3, 50);
	model->setItem(row, 3, item);

	item = new QStandardItem(query.value(4).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(4, 100);
	model->setItem(row, 4, item);

	item = new QStandardItem(query.value(5).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(5, 100);
	model->setItem(row, 5, item);

	item = new QStandardItem(ui.lineEdit_3->text());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(6, 80);
	model->setItem(row, 6, item);

	item = new QStandardItem(ui.lineEdit_4->text());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	ui.tableView->setColumnWidth(7, 80);
	model->setItem(row, 7, item);

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();

	ui.lineEdit_2->setText("");
	ui.lineEdit_3->setText("");
	ui.lineEdit_4->setText("");
	ui.pushButton_2->setFocus();
	textId = "-1";

}

void QProFakturiVnes::on_pushButton_6_clicked()
{
	model->removeRow(selRow);
}

void QProFakturiVnes::on_pushButton_4_clicked()
{
    //    pressEscape();
    int cols = model->columnCount();
    int rows = model->rowCount();
    if (!rows)
    {
        return;
    }

    int mid=0;
    try
    {
        QSqlQuery query;
        query.clear();
        query.prepare("select max(priemnica_id)+1 m_max from priemnici");
        query.exec();
        int  r= query.numRowsAffected();
        query.next();	
        int row = model->rowCount();
        query.clear();
        query.prepare("insert into priemnici(priemnica_id,datum,magacin) values(:a1,:a2,:a3)");
        query.bindValue(":a1", textId.toInt());	
        query.bindValue(":a2", textId.toInt());	
        query.bindValue(":a3", textId.toInt());	
        query.exec();

        query.clear();
        query.prepare("select max(id)mid from  priemnici");
        query.exec();

        for (int i = 1; i < rows; rows++)
        {

            query.clear();
            query.prepare(
                "insert into magacin_artikli(vid_dokument,document_id,id_komintent,id_artikal,vlez_kol,izlez_kol,"
                "datum_referenca,firma_id,document_id_label,nabavna_cena,magacin,tip,prodazna_cena,nabavna_cena_valuta,prodazna_cena_valuta) values(:a1,:a2,:a3,:a4,:a5,"
                ":a6,:a7,:a8,:a9,:a10,:a11,:a12,:a14,:a15,:a16)");

            query.bindValue(":a1", textId.toInt());	
            query.bindValue(":a2", textId.toInt());	
            query.bindValue(":a3", textId.toInt());	
            query.bindValue(":a4", textId.toInt());	
            query.bindValue(":a5", textId.toInt());	
            query.bindValue(":a6", textId.toInt());	
            query.bindValue(":a7", textId.toInt());	
            query.bindValue(":a8", textId.toInt());	
            query.bindValue(":a9", textId.toInt());	
            query.bindValue(":a10", textId.toInt());	
            query.bindValue(":a11", textId.toInt());	
            query.bindValue(":a12", textId.toInt());	
            query.bindValue(":a13", textId.toInt());	
            query.bindValue(":a14", textId.toInt());	
            query.bindValue(":a15", textId.toInt());	
            query.bindValue(":a16", textId.toInt());	

            query.exec();
        }

        QMessageBox msgBox;
        msgBox.setText(trUtf8("Приемницата е успешно внесена."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
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
        msgBox.setText(trUtf8("Приемницата не е внесена !!!."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}
void QProFakturiVnes::on_pushButton_5_clicked()
{
	pressEscape();
}

void QProFakturiVnes::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
	selRow = modelX.row();
}