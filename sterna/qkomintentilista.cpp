#include "qkomintentilista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "xx.h"


QKomintentiLista::QKomintentiLista(QWidget *parent)
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
	getTableColumnWidths(15);
	lista("%%%");
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));

	ui.lineEdit->setFocus();
}

QKomintentiLista::~QKomintentiLista()
{
	setTableColumnWidths(15);
}


void QKomintentiLista::setSearchText(QString text)
{
	ui.lineEdit->setText(text); 
}

QString QKomintentiLista::getSearchStr()
{
	return ui.lineEdit->text(); 
}

void QKomintentiLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    int r = 0;
    int c = 15;

    int fieldNo[15];
    QString country[15];
//    int colWidth[] = {0, 120, 250, 250, 100, 100, 150 , 150 , 150 , 150 , 150, 100, 100, 100, 100};

    QString temp = "";
    temp = " select  id, sifra, naziv, adresa, tel, mobil, zirosmetka, edb, deponent, sifdejnost, mb, "
           " zabeleska1, zabeleska2, rabat, grad "
           " from komintenti " 
           " where naziv like '"+ nameSearch +"%' or sifra like '"+ nameSearch +"%' ";

    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id"));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Назив"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Адреса"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Тел"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Мобилен"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Жиро сметка"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Едб."));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Банка Депонент"));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8("Шифра дејност"));
    model->setHeaderData( 10, Qt::Horizontal, trUtf8("Матичен Број"));
    model->setHeaderData( 11, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 12, Qt::Horizontal, trUtf8("Забелешка"));
    model->setHeaderData( 13, Qt::Horizontal, trUtf8("Рабат"));
    model->setHeaderData( 14, Qt::Horizontal, trUtf8("Град"));
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
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
	ui.tableView->setColumnHidden(0, true);

    ui.tableView->show();
}

void QKomintentiLista::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}
void QKomintentiLista::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}

void QKomintentiLista::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QKomintentiLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
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
	ui.lineEdit_11->setText(model->item(i, 10)->text());
	ui.lineEdit_12->setText(model->item(i, 11)->text());
	ui.lineEdit_13->setText(model->item(i, 12)->text());
	ui.lineEdit_14->setText(model->item(i, 13)->text());
    ui.lineEdit_15->setText(model->item(i, 14)->text());
}
void QKomintentiLista::pressEscape()
{
	emit closeW();
}

void QKomintentiLista::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
		ui.tableView->selectRow(0);
    }
    else if (ui.tableView->hasFocus())
	{
		emit sKomintentToPriemnica(m_selectedText, m_selectedText_name);	
	}
}

void QKomintentiLista::on_tableView_pressed(QModelIndex modelX)
{
	int i = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QKomintentiLista::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QKomintentiLista::on_pushButton_clicked()
{
    emit procF2();
}
void QKomintentiLista::on_pushButton_2_clicked()
{
    emit procF3();
}


void QKomintentiLista::on_pushButton_3_clicked()
{
	CHelperClass *chlp = new CHelperClass(this);
	if (chlp->isKomintentExistsInStore(m_selectedText))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Коминтентот е употребен и\nнеможе да се избрише!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.tableView->setFocus();
		return;
	}	

	QMessageBox msgBox;
	msgBox.setText(trUtf8("Warning"));
	msgBox.setInformativeText(trUtf8("Коминтентот ке биде ИЗБРИШАН.!!!"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("delete from komintenti where id = :komintent_id ");
		query.bindValue(":komintent_id", m_selectedText);
		if(query.exec())
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Коминтентот e ИЗБРИШАН."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Коминтентот НЕ Е ИЗБРИШАН."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
		}
		lista("%%%");
	}
}

void QKomintentiLista::setTableColumnWidths(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	s->setKomintentiColumnWidth(tempWidth);
}

void QKomintentiLista::getTableColumnWidths(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getKomintentiColumnWidth();
	if (sss.count() == ccolumn)
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth[i1] = loc.toInt(sss.at(i1));
		}
	}
	else
	{
		for (int i1 = 0; i1 < ccolumn; i1++)
		{
			colWidth[i1] = 100;
		}
	}
}

