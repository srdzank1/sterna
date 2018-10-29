#include "qprofakturalista.h"
#include <QSqlQuery>
#include <QSqlRecord>

QProFakturiLista::QProFakturiLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
	lista("%%%");
	m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
	lista_detail(m_selectedText);
	ui.tableView->setFocus();
}

QProFakturiLista::~QProFakturiLista()
{

}
void QProFakturiLista::pressEscape()
{
	emit closeW();
}
void QProFakturiLista::lista(const QString& nameSearch)
{
	if (nameSearch.length() < 0)
	{
		ui.tableView->hide();
		return;
	}
	QSqlQuery query;
	query.prepare("select id, ispratnica_id, datum from ispratnici order by ispratnica_id desc ");
	query.exec();
	int  r= query.numRowsAffected();

	int c = 3;
	model = new QStandardItemModel(r,c);

	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Испратница бр."));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
	ui.tableView->setHorizontalHeader(header);
	header->show();

	for (int row = 0; row < r; ++row) 
	{
		query.next();
		for (int column = 0; column < c; ++column) 
		{
			QStandardItem *item = new QStandardItem(query.value(column).toString());
			item->setEditable(false);
			ui.tableView->setRowHeight(row, 18);
			switch (column)
			{
			case 0: ui.tableView->setColumnWidth(column, 50);break;
			default:
				ui.tableView->setColumnWidth(column, 100);
			}
			model->setItem(row, column, item);
		}
	}
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}
void QProFakturiLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
	ui.lineEdit->setText(model->item(i, 0)->text());
	ui.lineEdit_2->setText(model->item(i, 1)->text());
	lista_detail(m_selectedText);

}
void QProFakturiLista::lista_detail(const QString& nameSearch)
{
	if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}
	QSqlQuery query;
	query.prepare(
		"select sifra, artikal, edm, vlez_kol, komintenti.naziv "
		"from magacin_artikli "
		"	left join komintenti  on magacin_artikli.id_komintent=komintenti.id "
		"	left join artikli on magacin_artikli.id_artikal=artikli.id "
		"	where magacin_artikli.vid_dokument='I' and magacin_artikli.document_id=:id "
		);
	query.bindValue(":id", nameSearch.toInt());
	query.exec();
	int  r= query.numRowsAffected();

	int c = 5;
	model2 = new QStandardItemModel(r,c);

	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Шифра"));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Едм"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Влезна количина"));

	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();

	for (int row = 0; row < r; ++row) 
	{
		query.next();
		for (int column = 0; column < c; ++column) 
		{
			QStandardItem *item = new QStandardItem(query.value(column).toString());
			item->setEditable(false);
			ui.tableView_2->setRowHeight(row, 18);
			ui.tableView_2->setColumnWidth(column, 150);
			model2->setItem(row, column, item);
		}
	}
	if(r)
	{
		ui.tableView_2->setColumnHidden(4,true);
		ui.lineEdit_3->setText(model2->item(0, 4)->text());
	}
	ui.tableView_2->show();
}

