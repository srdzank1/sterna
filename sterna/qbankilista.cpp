#include "qbankilista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "xx.h"


QBankiLista::QBankiLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_selectedText("")
	,m_selectedText_name("")
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	lista("%%%");
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	ui.lineEdit->setFocus();
}

QBankiLista::~QBankiLista()
{

}

void QBankiLista::lista(const QString& nameSearch)
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
    int colWidth[] = {100, 450, 200};
    QString colName[] = {"BankId", "BankIme", "BankZiro"};
    QString temp = "SELECT * FROM TBank where BankIme like '%";
    temp += nameSearch;
    temp += "%' order by BankId desc";
    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Жиро сметка"));
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

void QBankiLista::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}

void QBankiLista::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QBankiLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
	m_selectedText_name = model->item(i, 1) ? model->item(i, 1)->text():"";
	ui.lineEdit_2->setText(model->item(i, 0)->text());
	ui.lineEdit_3->setText(model->item(i, 1)->text());
    ui.lineEdit_4->setText(model->item(i, 2)->text());
}
void QBankiLista::pressEscape()
{
	emit closeW();
}

void QBankiLista::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
    {
        emit sBankiToIzvod(m_selectedText, m_selectedText_name);	
    }
}

void QBankiLista::on_tableView_pressed(QModelIndex modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QBankiLista::setInitText(QString text)
{
    ui.lineEdit->setText(text);
    ui.lineEdit->selectAll();
    ui.lineEdit->setFocus();
}

void QBankiLista::on_pushButton_clicked()
{
	emit procF2();
}
void QBankiLista::on_pushButton_2_clicked()
{
	emit procF3();
}
