#include "qmyartiklilista.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QDesktopWidget>
#include <QClipboard>
#include "xx.h"





QMyArtikliLista::QMyArtikliLista(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_selectedText("")
	,m_selectedTextName("")
	, m_row(0)
{
	ui.setupUi(this);

	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	getTableColumnWidths(11);
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(copyToClipBoard()));
	lista("%%%");
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSortingEnabled(true);
	connect(ui.tableView->horizontalHeader(),SIGNAL(sectionClicked(int)), ui.tableView, SLOT(sortByColumn(int)));
	ui.lineEdit->setFocus();
}

QMyArtikliLista::~QMyArtikliLista()
{
	setTableColumnWidths(11);
}

void QMyArtikliLista::setSearchText(QString text)
{
	ui.lineEdit->setText(text); 
}

QString QMyArtikliLista::getSearchStr()
{
	return ui.lineEdit->text(); 
}

void QMyArtikliLista::setRow(int mrow)
{
	ui.tableView->selectRow(mrow);
}
int QMyArtikliLista::getRow()
{
	return m_row;
}

void QMyArtikliLista::lista(const QString& nameSearch)
{
    if (nameSearch.length() < 0)
    {
        ui.tableView->hide();
        return;
    }
    
    int r = 0;
    int c = 11;
    int fieldNo[11];
    QString country[11];
    //int colWidth[] = {0, 120, 250, 60, 60, 120 , 0 , 0 , 0 , 0, 80};
    QString colName[] = {"id", "sifra", "artikal", "edm", "ref", "kataloski_broj", "art_nabavna_cena", "art_nabavna_cena_valuta",
        "art_prodazna_cena", "art_prodazna_cena_valuta" ,"ddv"};
    QString temp = "";
        temp = "select id, sifra, artikal, edm, ref, kataloski_broj, "
            "art_nabavna_cena, art_nabavna_cena_valuta,  "
            "art_prodazna_cena, art_prodazna_cena_valuta, ddv "
            " from artikli where artikal like '"+nameSearch+"%' or sifra like '"+nameSearch+"%'";

    QSqlQuery query(temp);
    model = new QStandardItemModel(r,c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Катал. број"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8(""));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8(""));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8(""));
    model->setHeaderData( 9, Qt::Horizontal, trUtf8(""));
    model->setHeaderData( 10, Qt::Horizontal, trUtf8("ДДВ"));

    ui.tableView->setModel(model);
    header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);
    ui.tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;
    QLocale loc;
    QString temp1 = "";
    while (query.next()) 
    {
        for (int i = 0; i < c; i++)
        {
            fieldNo[i] = query.record().indexOf(colName[i]);
            if (i > 5 && i < 11) 
            {
                temp1 = loc.toString(query.value(fieldNo[i]).toDouble(), 'f', 2);
            }
            else
            {
                temp1 = query.value(fieldNo[i]).toString();
            }

            QStandardItem *item = new QStandardItem(temp1);
            
            if (i > 5)
            {
                 item->setTextAlignment(Qt::AlignRight);
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
	connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    //int colWidth[] = {0, 120, 250, 60, 60, 120 , 0 , 0 , 0 , 0, 80};
	ui.tableView->setColumnHidden(0, true);
	ui.tableView->setColumnHidden(6, true);
	ui.tableView->setColumnHidden(7, true);
	ui.tableView->setColumnHidden(8, true);
	ui.tableView->setColumnHidden(9, true);
	ui.tableView->show();
}


void QMyArtikliLista::procSectionResized(int a, int b, int c)
{
	colWidth[a] = c;
}

void QMyArtikliLista::on_lineEdit_textChanged(const QString &)
{
	lista(ui.lineEdit->text());
}



void QMyArtikliLista::on_tableView_clicked(const QModelIndex &modelX)
{
	int i = modelX.row();
	m_row = modelX.row();
	m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}


void QMyArtikliLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 2) ? model->item(i, 2)->text():"";

    ui.lineEdit_2->setText(model->item(i, 0)->text());
    ui.lineEdit_3->setText(model->item(i, 1)->text());
    ui.lineEdit_4->setText(model->item(i, 2)->text());
    ui.lineEdit_5->setText(model->item(i, 3)->text());
    ui.lineEdit_6->setText(model->item(i, 4)->text());
    ui.lineEdit_7->setText(model->item(i, 5)->text());
    ui.lineEdit_12->setText(model->item(i, 10)->text());
}


void QMyArtikliLista::setFocusSearchField()
{
	ui.lineEdit->setFocus();
}

void QMyArtikliLista::pressEscape()
{
	emit closeW();
}

void QMyArtikliLista::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
		ui.tableView->selectRow(0);
    }
    else if (ui.tableView->hasFocus())
	{
		emit sArtikalToPriemnica(m_selectedText, m_selectedTextName);	
	}

}

void QMyArtikliLista::setInitText(QString text)
{
	ui.lineEdit->setText(text);
	ui.lineEdit->selectAll();
	ui.lineEdit->setFocus();
}

void QMyArtikliLista::on_pushButton_clicked()
{
    emit procF2();
}
void QMyArtikliLista::on_pushButton_2_clicked()
{
    emit procF3();
}

void QMyArtikliLista::on_pushButton_3_clicked()
{
	CHelperClass *chlp = new CHelperClass(this);
	if (chlp->isSifraArtikalExistsInSTore(m_selectedText))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Артикалот е употребен и\nнеможе да се избрише!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.tableView->setFocus();
		return;
	}	

	QMessageBox msgBox;
	msgBox.setText(trUtf8("Warning"));
	msgBox.setInformativeText(trUtf8("Артикалот ке биде ИЗБРИШАН.!!!"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("delete from artikli where id = :artikal_id ");
		query.bindValue(":artikal_id", m_selectedText);
		if(query.exec())
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Артикалот e ИЗБРИШАН."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Артикалот НЕ Е ИЗБРИШАН."));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
		}
		lista("%%%");
	}
}

void QMyArtikliLista::copyToClipBoard()
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

void QMyArtikliLista::setTableColumnWidths(int ccolumn)
{
	Singleton *s = Singleton::Instance();
	QStringList tempWidth;
	for (int i = 0; i < ccolumn; i++)
	{
		tempWidth << QString::number(ui.tableView->columnWidth(i), 10);
	}
	s->setArtikliColumnWidth(tempWidth);
}

void QMyArtikliLista::getTableColumnWidths(int ccolumn)
{
	QLocale loc;
	Singleton *s = Singleton::Instance();
	QStringList sss = s->getArtikliColumnWidth();
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

