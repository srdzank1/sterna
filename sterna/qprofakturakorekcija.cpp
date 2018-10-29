#include "qprofakturakorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>

QProFakturiKorekcija::QProFakturiKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,selRow(-1)
	,textId("")
{
	ui.setupUi(this);
	ui.pushButton->setFocus();
	model = new QStandardItemModel(0,4);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Едм"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Влезна количина"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
	ui.tableView->setHorizontalHeader(header);
	header->show();
}

QProFakturiKorekcija::~QProFakturiKorekcija()
{

}
void QProFakturiKorekcija::pressEscape()
{
	emit closeW();
}
void QProFakturiKorekcija::on_pushButton_clicked()
{
	emit scallKomintenti((QWidget*)this);
}

void QProFakturiKorekcija::setFocusLine()
{
	ui.pushButton->setFocus();
}
void QProFakturiKorekcija::setKomintent(QString text, QString textName)
{
	ui.lineEdit->setText(textName);

}

void QProFakturiKorekcija::setArtikli(QString text, QString textName)
{
	ui.lineEdit_2->setText(textName);
	textId = text;
}

void QProFakturiKorekcija::setFocusLine2()
{
	ui.pushButton_2->setFocus();
}

void QProFakturiKorekcija::on_pushButton_2_clicked()
{
	emit scallArtikli((QWidget*)this);
}

void QProFakturiKorekcija::on_pushButton_3_clicked()
{
	if(textId.toInt() == -1)
	{
		return;
	}

	QSqlQuery query;
	query.prepare("select sifra, artikal, edm from artikli where id = :id");
	query.bindValue(":id", textId.toInt());	
	query.exec();
	int  r= query.numRowsAffected();
	query.next();	
	int row = model->rowCount();

	QStandardItem *item = new QStandardItem(query.value(0).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	model->setItem(row, 0, item);

	item = new QStandardItem(query.value(1).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	model->setItem(row, 1, item);

	item = new QStandardItem(query.value(2).toString());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	model->setItem(row, 2, item);

	item = new QStandardItem(ui.lineEdit_3->text());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	model->setItem(row, 3, item);

	item = new QStandardItem(ui.lineEdit_4->text());
	item->setEditable(false);
	ui.tableView->setRowHeight(row, 18);
	model->setItem(row, 4, item);

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
void QProFakturiKorekcija::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
	selRow = modelX.row();
}

void QProFakturiKorekcija::on_pushButton_6_clicked()
{
	model->removeRow(selRow);
}
void QProFakturiKorekcija::pressReturn()
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
void QProFakturiKorekcija::init(int id)
{
	if(id == -1)
	{
		return;
	}

	QSqlQuery query;
	query.prepare("select id, priemnica_id, datum from priemnici order by priemnica_id desc ");
	query.exec();
	query.next();
	ui.lineEdit->setText(query.value(1).toString());
	// 	ui.lineEdit->setText(query.value(1).toString())
	// 	ui.lineEdit->setText(query.value(1).toString())


	query.prepare(
		"select sifra, artikal, edm, vlez_kol, komintenti.naziv "
		"from magacin_artikli "
		"	left join komintenti  on magacin_artikli.id_komintent=komintenti.id "
		"	left join artikli on magacin_artikli.id_artikal=artikli.id "
		"	where magacin_artikli.vid_dokument='P' and magacin_artikli.document_id=:id "
		);
	query.bindValue(":id", id);	
	query.exec();
	int  r= query.numRowsAffected();
	int c = 4;
	int row = model->rowCount();
	for (int row = 0; row < r; ++row) 
	{
		query.next();
		for (int column = 0; column < c; ++column) 
		{
			QStandardItem *item = new QStandardItem(query.value(column).toString());
			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			ui.tableView->setColumnWidth(column, 150);
			model->setItem(row, column, item);
		}
	}

	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}

void QProFakturiKorekcija::on_pushButton_5_clicked()
{
	pressEscape();
}

void QProFakturiKorekcija::on_pushButton_4_clicked()
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
        query.prepare("update priemnici set priemnica_id=:a1,datum=:a2,magacin=:a3 where id=:aid");
        query.bindValue(":a1", textId.toInt());	
        query.bindValue(":a2", textId.toInt());	
        query.bindValue(":a3", textId.toInt());	
        query.exec();

        query.clear();
        query.prepare("delete from magacin_artikli where document_id=:aid and vid_dokument=:vid");
        query.bindValue(":vid", "P");	
        query.bindValue(":aid", mid);	
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
        msgBox.setText(trUtf8("Приемницата е успешно корегирана."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        pressEscape();
    }
    catch (...)
    {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Приемницата не е корегирана !!!."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}