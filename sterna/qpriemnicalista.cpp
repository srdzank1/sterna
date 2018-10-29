#include "qpriemnicalista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>


QPriemnicaLista::QPriemnicaLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);

	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.tableView_2->setSortingEnabled(true);
	connect(ui.tableView_2->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView_2, SLOT(sortByColumn(int)));

	lista("%%%");
	m_selectedText = model->item(0, 0) ? model->item(0, 0)->text():"";
	lista_detail(m_selectedText);
	ui.tableView->setFocus();
}


QPriemnicaLista::~QPriemnicaLista()
{

}

void QPriemnicaLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 6;
    int fieldNo[6];
    QString country[6];
    int colWidth[] = {0, 80, 100, 350, 0, 0};
    QString colName[] = {"id", "dok_id", "datum", "naziv", "adresa", "grad"};
	QString temp = 
	"select dokumenti.id, dok_id, datum, komintenti.naziv, komintenti.adresa, komintenti.grad "
	"from dokumenti "
	"left join komintenti on dokumenti.komintent_id = komintenti.id "
	"where dok_tip = 20 order by dok_id desc "
    ;
    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Бр."));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Датум"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Град"));

	ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = query.record().indexOf(colName[i]);
            QStandardItem *item = new QStandardItem(query.value(fieldNo[i]).toString());

			if ((i == 2))
			{
				item = new QStandardItem(query.value(fieldNo[i]).toString().left(10));
			}

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
void QPriemnicaLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 1) ? model->item(i, 1)->text():"";

	m_info = model->item(i, 1)->text();
	m_info2 = model->item(i, 2)->text().left(10);
	m_info3 = model->item(i, 3)->text();
    m_info4 = model->item(i, 4)->text();
    m_info5 = model->item(i, 5)->text();

    lista_detail(m_selectedText);

}
void QPriemnicaLista::lista_detail(const QString& nameSearch)
{
	QLocale loc;
    if (nameSearch.length() < 0)
	{
		ui.tableView_2->hide();
		return;
	}

    int r = 0;
    int c = 6;
    int fieldNo[6];
    QString country[6];
    int colWidth[] = {0, 70, 300, 60, 100, 100, 0};
    QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena"};
    QString temp = 
        "select artikli.id, sifra, artikal, edm, ikol, icena  "
        "from magacin                                         "
        "left join artikli on magacin.artikal_id = artikli.id "
        "where magacin.dok_tip = 20 and magacin.dok_id=       ";
    temp += m_selectedText;
    temp += "";
    QSqlQuery query(temp);

    model2 = new QStandardItemModel(r,c);
    model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм."));
    model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Количина"));
    model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
    ui.tableView_2->setModel(model2);
    header2 = new QHeaderView(Qt::Horizontal, this);
    header2->setSectionsClickable(true);
    ui.tableView_2->setHorizontalHeader(header2);
    header2->show();
    int row = 0;
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = query.record().indexOf(colName[i]);
//            QStandardItem *item = new QStandardItem(query.value(fieldNo[i]).toString());
            QStandardItem *item = NULL;
            QString temp = query.value(fieldNo[i]).toString();
            if (i > 3)
            {
                temp =  loc.toString(temp.toDouble(), 'f', 2);
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
	ui.tableView_2->show();
}

void QPriemnicaLista::pressEscape()
{
	emit closeW();
}

void QPriemnicaLista::deleteDok(int idDok)
{
    QString temp = "select id from dokumenti where dok_tip = 20 and dok_id =";
    temp += QString::number(idDok);
    QSqlQuery query(temp);
    QString country = "";
    while (query.next()) {
        country = query.value(query.record().indexOf("id")).toString();
    }

    query.clear();
    query.prepare("delete from magacin where dok_tip = 20 and dok_id = :a");
    query.bindValue(":a", idDok);	
    query.exec();
}


void QPriemnicaLista::on_pushButton_clicked()
{
    emit procF2();
}
void QPriemnicaLista::on_pushButton_2_clicked()
{
    emit procF3();
}
QStringList QPriemnicaLista::geInfo()
{
    QStringList info;
    info.clear();
    info << m_info3 << m_info4 << m_info5 << m_info << m_info2; 
    return info;
}
