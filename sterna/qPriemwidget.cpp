#include "qPriemwidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"
#include <QClipboard>

QPriemWidget::QPriemWidget(QWidget *parent)
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
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(copyToClipBoard()));
    lista("%");
}

QPriemWidget::~QPriemWidget()
{

}


void QPriemWidget::pressEscape()
{
    emit closeW();
}


void QPriemWidget::lista(const QString& nameSearch)
{
    QLocale loc;
    int r = 0;
    int c = 9;
    int fieldNo[9];
    QString country[9];
    int colWidth[] = {0, 80, 180, 80, 100, 100, 100, 100, 100};
    QString colName[9] = {"id", "sifra", "artikal", "edm", "ncena", "pcena", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};

    QString temp = 
        "select distinct artikal_id, artikli.sifra, artikli.artikal, artikli.edm , artikli.art_nabavna_cena_valuta, artikli.art_prodazna_cena_valuta "
        "from magacin "
		"left join artikli on  magacin.artikal_id = artikli.id "
		"where artikli.artikal like '%" + nameSearch + 
		"%' or artikli.sifra like '%" + nameSearch +"%' order by artikal_id";
    QSqlQuery query(temp);
    QSqlError err = query.lastError();
    model = new QStandardItemModel(r, c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("ID"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Наб. Цена"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Прод. Цена"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Влез. Кол."));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Изл. Кол."));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Салдо"));
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
	setUpdatesEnabled(false);
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            QString temp = query.value(i).toString();
            QStandardItem *item = NULL; 
			if (i == 6)
			{
				QString tip = "20";
				QString tip1 = "21";
				vkVlezKol = chc.getVkKolBetween(query.value(0).toString(), tip , tip1);
				temp =  loc.toString(vkVlezKol ,'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 7)
			{
				QString tip = "40";
				QString tip1 = "45";
				vkIzlezKol = chc.getVkKolBetween(query.value(0).toString(), tip , tip1);
				temp =  loc.toString(vkIzlezKol ,'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 8)
			{
				vkSaldo = vkVlezKol - vkIzlezKol;
				temp =  loc.toString(vkSaldo ,'f',2);
				item = new QStandardItem(temp);
				QBrush newBrush;
				if (vkSaldo < 0)
				{
					newBrush.setColor(Qt::darkRed);
					item->setForeground(newBrush);
				}
				else if (vkSaldo == 0)
				{
					newBrush.setColor(Qt::black);
					item->setForeground(newBrush);
				}
				else
				{
					newBrush.setColor(Qt::darkGreen);
					item->setForeground(newBrush);
				}
				item->setTextAlignment(Qt::AlignRight);
			}
            else
            {
                item = new QStandardItem(temp);
                if ((i > 3)&&(i < 6))
                {
                    QString temp =  item->text();
                    temp = loc.toString(temp.toFloat() ,'f', 2);
                    item->setText(temp);
                    item->setTextAlignment(Qt::AlignRight);
                }
                else
                {
                    item->setTextAlignment(Qt::AlignLeft);
                }
            }
            item->setEditable(false);
            ui.tableView->setRowHeight(row, 18);
            ui.tableView->setColumnWidth(i, colWidth[i]);
            model->setItem(row, i, item);
        }
        if (vkSaldo)
        {
			row++;
        }
    } 
	setUpdatesEnabled(true);

    QItemSelectionModel *sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    ui.tableView->show();
}

void QPriemWidget::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}


void QPriemWidget::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QPriemWidget::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}


void QPriemWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
	{
		emit sPriemToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
	}

}

void QPriemWidget::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QPriemWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 2) ? model->item(i, 2)->text():"";
    m_selectedTextNameSaldo = model->item(i, 6) ? model->item(i, 6)->text():"";
}

void QPriemWidget::copyToClipBoard()
{
    QString m_copyedString = "";
    setUpdatesEnabled(false);	
    for(int c_row = 0; c_row < model->rowCount(); c_row++)
    {
        QStringList c;
        c.clear();
        for(int c_col = 0; c_col < model->columnCount(); c_col++)
        {
            QString temp = model->item(c_row,c_col)->text().trimmed();
            if(temp.contains('\n'))
            {
                int stop = 0;
            }
                c << temp;
        }
        m_copyedString = m_copyedString + c.join("\t");
        c.clear();
        m_copyedString = m_copyedString + "\n";
    }
    setUpdatesEnabled(true);

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_copyedString);
}
