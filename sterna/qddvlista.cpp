#include "qddvlista.h"
#include <QSqlQuery>
#include <QSqlRecord>


QDdvLista::QDdvLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_selectedText("")
	,m_selectedText_name("")
{
	ui.setupUi(this);
	lista("%%%");
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.lineEdit->setFocus();
}

QDdvLista::~QDdvLista()
{

}
void QDdvLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 3;
    int fieldNo[3];
    QString country[3];
    int colWidth[] = {100, 250, 100};
    QString colName[] = {"ddvID", "ddvTxt", "ddvVal"};
    QString temp = "select ddvID, ddvTxt, ddvVal from tddv where ddvTxt like '%";
    temp += nameSearch;
    temp += "%' ";
    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("ДДВ Назив"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("ДДВ Износ"));
    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = query.record().indexOf(colName[i]);
            QStandardItem *item = new QStandardItem(query.value(fieldNo[i]).toString());
            item->setEditable(false);
            ui.tableView->setRowHeight(row, 18);
            ui.tableView->setColumnWidth(i, colWidth[i]);
            model->setItem(row, i, item);
        }
        row++;
    } 
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}


void QDdvLista::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}

void QDdvLista::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QDdvLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
	m_selectedText_name = model->item(i, 1) ? model->item(i, 1)->text():"";
	ui.lineEdit_2->setText(model->item(i, 0)->text());
	ui.lineEdit_3->setText(model->item(i, 1)->text());
    ui.lineEdit_4->setText(model->item(i, 2)->text());
}
void QDdvLista::pressEscape()
{
	emit closeW();
}

void QDdvLista::pressReturn()
{
	if (ui.tableView->hasFocus())
	{
		emit sKomintentToPriemnica(m_selectedText, m_selectedText_name);	
	}
}

void QDdvLista::on_tableView_pressed(QModelIndex modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}
