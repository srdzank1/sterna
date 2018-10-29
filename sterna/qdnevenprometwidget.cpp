#include "qDnevenprometwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"
#include <QDate>

QDnevenprometWidget::QDnevenprometWidget(QWidget *parent)
	: QMyBaseFormWidget(parent)
    ,m_selectedText("") 
    ,m_selectedTextName("")
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);
    ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.dateTimeEdit->setDate(QDate::currentDate());
	connect(ui.dateTimeEdit, SIGNAL(editingFinished()), this, SLOT(funcEditingFinished()));
	lista("%");
}

QDnevenprometWidget::~QDnevenprometWidget()
{

}

QString QDnevenprometWidget::getDateAsString()
{
	QString dateString = "";
	dateString = trUtf8("на ден ") + ui.dateTimeEdit->date().toString("dd/MM/yyyy");
	return dateString;
}



void QDnevenprometWidget::refresh()
{
	lista("%");
}


void QDnevenprometWidget::pressEscape()
{
    emit closeW();
}

void QDnevenprometWidget::funcEditingFinished()
{
	lista(ui.lineEdit->text());
}


void QDnevenprometWidget::lista(const QString& nameSearch)
{
    QLocale loc;
    int r = 0;
    int c = 4;
    int fieldNo[4];
    QString country[6];
    int colWidth[] = {100, 180, 180, 100};
	QString temp = 
        "select dokumenti.dok_id, magacin.artikal_id, dokumenti.komintent_id, magacin.ikol  "  
        "from dokumenti "                                        
        "left join magacin on  dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip "
        "where dokumenti.dok_tip = 21 "  
        "and datum = #" + ui.dateTimeEdit->date().toString("yyyy/MM/dd") + "# ";
    QSqlQuery query(temp);
    QSqlError err = query.lastError();
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Артикал Шифра"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Коминтент"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);

    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
	CHelperClass chc(this);
	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkSaldo = 0.f;
    chc.createKomintentiMap();
    chc.createArtikliMap();
    chc.createSifraMap();
    

    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            QString temp = query.value(i).toString();
            if(i == 0)
            {
                temp = chc.getSifraNameByID(query.value(1).toString());
            }
            if(i == 1)
            {
                temp = chc.getArtikalNameByID(temp);
            }
            if (i == 2)
            {
                temp = chc.getKomintentNameByID(temp);
            }
            QStandardItem *item = NULL; 
            item = new QStandardItem(temp);
            item->setTextAlignment(Qt::AlignLeft);
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

void QDnevenprometWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QDnevenprometWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QDnevenprometWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}

void QDnevenprometWidget::pressF9()
{
	lista(ui.lineEdit->text());
}

void QDnevenprometWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sDnevenprometToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
	}

}

void QDnevenprometWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QDnevenprometWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 1) ? model->item(i, 1)->text():"";
    m_selectedTextNameSaldo = model->item(i, 5) ? model->item(i, 5)->text():"";
}

