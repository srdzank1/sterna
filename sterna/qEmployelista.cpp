#include "qEmployelista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>


QEmployeLista::QEmployeLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_selectedText("")
	,m_selectedText_name("")
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);

	lista("%%%");
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	ui.lineEdit->setFocus();
}

QEmployeLista::~QEmployeLista()
{

}
void QEmployeLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 10;

    int fieldNo[10];
    QString country[10];
    int colWidth[] = {0, 120, 250, 250, 100, 100, 150 , 150 , 150 , 150 };
    QString temp = "";
    temp = " select  top 100 id, korisnicko_ime, pasword, ime, prezime, adresa, grad, tel, uloga, user_id "
           " from vraboteni ";

    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Корисничко Име"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Лозинка"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Име"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Презиме"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Град"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Тел"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Улога"));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8("Кириснички број"));
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
            QStandardItem *item = new QStandardItem(query.value(i).toString());
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


void QEmployeLista::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}

void QEmployeLista::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QEmployeLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
	m_selectedText_name = model->item(i, 2) ? model->item(i, 2)->text():"";
    ui.lineEdit_2->setText(model->item(i, 1)->text());
	ui.lineEdit_3->setText(model->item(i, 2)->text());
	ui.lineEdit_4->setText(model->item(i, 3)->text());
	ui.lineEdit_5->setText(model->item(i, 4)->text());
	ui.lineEdit_6->setText(model->item(i, 5)->text());
	ui.lineEdit_7->setText(model->item(i, 6)->text());
	ui.lineEdit_8->setText(model->item(i, 7)->text());
	ui.lineEdit_9->setText(model->item(i, 8)->text());
	ui.lineEdit_10->setText(model->item(i, 9)->text());
//	ui.lineEdit_11->setText(model->item(i, 10)->text());
}
void QEmployeLista::pressEscape()
{
	emit closeW();
}

void QEmployeLista::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sKomintentToPriemnica(m_selectedText, m_selectedText_name);	
	}
}

void QEmployeLista::on_tableView_pressed(QModelIndex modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QEmployeLista::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QEmployeLista::on_pushButton_clicked()
{
    emit procF2();
}
void QEmployeLista::on_pushButton_2_clicked()
{
    emit procF3();
}
