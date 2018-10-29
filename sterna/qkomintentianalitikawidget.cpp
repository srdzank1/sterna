#include "qkomintentianalitikawidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopWidget>
#include "chelperclass.h"

QKomintentiAnalitikaWidget::QKomintentiAnalitikaWidget(QWidget *parent)
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
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(button2Clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(button3Clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(button4Clicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(button5Clicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(button6Clicked()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(button7Clicked()));
	ui.pushButton->setChecked(true);
	ui.pushButton_3->setChecked(true);
	on_lineEdit_textChanged(ui.lineEdit->text());
}

QKomintentiAnalitikaWidget::~QKomintentiAnalitikaWidget()
{

}


void QKomintentiAnalitikaWidget::pressEscape()
{
    emit closeW();
}
void QKomintentiAnalitikaWidget::listaArtikli(const QString& nameSearch)
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
	int colWidth[] = {50, 50, 250, 60, 60, 100 , 100 , 100 , 100 , 100, 50};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ref", "kataloski_broj", "art_nabavna_cena", "art_nabavna_cena_valuta",
		"art_prodazna_cena", "art_prodazna_cena_valuta" ,"ddv"};

	QString temp = "select id, sifra, artikal, edm, ref, kataloski_broj, "
		"art_nabavna_cena, art_nabavna_cena_valuta,  "
		"art_prodazna_cena, art_prodazna_cena_valuta, ddv "
		" from artikli where artikal like '%";
	temp += nameSearch;
	temp += "%' ";
	QSqlQuery query(temp);
	model = new QStandardItemModel(r,c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Каталошки број"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Набавна цена"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Валута"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Продажна цена"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Валута"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("ДДВ"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
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
			if (i == 6) 
			{
				temp1 = loc.toString(query.value(fieldNo[i]).toFloat(), 'f', 2);
			}
			if (i == 8) 
			{
				temp1 = loc.toString(query.value(fieldNo[i]).toFloat(), 'f', 2);
			}
			else
			{
				temp1 = query.value(fieldNo[i]).toString();
			}

			QStandardItem *item = new QStandardItem(temp1);

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
void QKomintentiAnalitikaWidget::listaKomintenti(const QString& nameSearch)
{
	if (nameSearch.length() < 0)
	{
		ui.tableView->hide();
		return;
	}
	int r = 0;
	int c = 14;
	int fieldNo[14];
	QString country[14];
	int colWidth[] = {50, 250, 250, 60, 60, 100 , 100 , 100 , 100 , 100};
	QString colName[] = {"id", "naziv", "adresa", "tel", 
		"mobil", "zirosmetka", "edb", "deponent", "sifdejnost", "mb", "zabeleska1", "zabeleska2", "rabat", "grad"};

	QString temp = "select id, naziv, adresa, tel, mobil, zirosmetka, edb, deponent, sifdejnost, mb, zabeleska1, zabeleska2, rabat, grad from komintenti where naziv like '%";

	temp += nameSearch;
	temp += "%' ";
	QSqlQuery query(temp);
	model = new QStandardItemModel(r,c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Назив"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Адреса"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Тел"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Мобилен"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Жиро сметка"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Едб."));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Банка Депонент"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Шифра дејност"));
	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Матичен Број"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("Забелешка"));
	model->setHeaderData( 11, Qt::Horizontal, trUtf8("Забелешка"));
	model->setHeaderData( 12, Qt::Horizontal, trUtf8("Рабат"));
	model->setHeaderData( 13, Qt::Horizontal, trUtf8("Град"));
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

void QKomintentiAnalitikaWidget::on_lineEdit_textChanged(const QString &)
{
    if (ui.pushButton->isChecked())
	{
		listaArtikli(ui.lineEdit->text());
	}
	else
	{
		listaKomintenti(ui.lineEdit->text());
	}

	if (ui.pushButton->isChecked())
	{
		if (ui.pushButton_3->isChecked())
		{
			m_currState = ART_IZLFKT;
		} 
		else if(ui.pushButton_4->isChecked())
		{
			m_currState = ART_VLZFKT;
		}
		else if(ui.pushButton_5->isChecked())
		{
			m_currState = ART_PRM;
		}
		else if(ui.pushButton_6->isChecked())
		{
			m_currState = ART_ISP;
		}
		else if(ui.pushButton_7->isChecked())
		{
			m_currState = ART_SLD;
		}
	}
	else
	{
		if (ui.pushButton_3->isChecked())
		{
			m_currState = KOM_IZLFKT;
		} 
		else if(ui.pushButton_4->isChecked())
		{
			m_currState = KOM_VLZFKT;
		}
		else if(ui.pushButton_5->isChecked())
		{
			m_currState = KOM_PRM;
		}
		else if(ui.pushButton_6->isChecked())
		{
			m_currState = KOM_ISP;
		}
		else if(ui.pushButton_7->isChecked())
		{
			m_currState = KOM_SLD;
		}
	}
	m_selectedText = m_selectedText.isEmpty() ? "-1" : m_selectedText;
    showTable2();
}


void QKomintentiAnalitikaWidget::on_tableView_clicked(const QModelIndex &modelX)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
}

void QKomintentiAnalitikaWidget::setFocusSearchField()
{
    ui.lineEdit->setFocus();
}


void QKomintentiAnalitikaWidget::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.tableView->setFocus();
    }
    else if (ui.tableView->hasFocus())
    {
        emit sLagerToDokument(m_selectedText, m_selectedTextName, m_selectedTextNameSaldo);	
    }

}

void QKomintentiAnalitikaWidget::setInitText(QString text)
{
    ui.lineEdit->setText(text);
    ui.lineEdit->selectAll();
    ui.lineEdit->setFocus();
}

void QKomintentiAnalitikaWidget::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
    int i = modelX.row();
    m_selectedText = model->item(i, 0) ? model->item(i, 0)->text():"";
    m_selectedTextName = model->item(i, 1) ? model->item(i, 1)->text():"";
    m_selectedTextNameSaldo = model->item(i, 5) ? model->item(i, 5)->text():"";
	if (ui.pushButton->isChecked())
	{
		if (ui.pushButton_3->isChecked())
		{
			m_currState = ART_IZLFKT;
		} 
		else if(ui.pushButton_4->isChecked())
		{
			m_currState = ART_VLZFKT;
		}
		else if(ui.pushButton_5->isChecked())
		{
			m_currState = ART_ISP;
		}
		else if(ui.pushButton_6->isChecked())
		{
			m_currState = ART_PRM;
		}
		else if(ui.pushButton_7->isChecked())
		{
			m_currState = ART_SLD;
		}
	}
	else
	{
		if (ui.pushButton_3->isChecked())
		{
			m_currState = KOM_IZLFKT;
		} 
		else if(ui.pushButton_4->isChecked())
		{
			m_currState = KOM_VLZFKT;
		}
		else if(ui.pushButton_5->isChecked())
		{
			m_currState = KOM_ISP;
		}
		else if(ui.pushButton_6->isChecked())
		{
			m_currState = KOM_PRM;
		}
		else if(ui.pushButton_7->isChecked())
		{
			m_currState = KOM_SLD;
		}
	}
	m_selectedText = m_selectedText.isEmpty() ? "-1" : m_selectedText;
    showTable2();
}

void QKomintentiAnalitikaWidget::showTable2()
{
	switch (m_currState)
	{
	case ART_IZLFKT: funcART_IZLFKT(); break;
	case ART_VLZFKT: funcART_VLZFKT(); break;
	case ART_ISP: funcART_ISP(); break;
	case ART_PRM: funcART_PRM(); break;
	case ART_SLD: funcART_SLD(); break;
	case KOM_IZLFKT: funcKOM_IZLFKT(); break;
	case KOM_VLZFKT: funcKOM_VLZFKT(); break;
	case KOM_ISP: funcKOM_ISP(); break;
	case KOM_PRM: funcKOM_PRM(); break;
	case KOM_SLD: funcKOM_SLD(); break;
	}
}
void QKomintentiAnalitikaWidget::buttonClicked()
{
	ui.pushButton->setChecked(true);
	ui.pushButton_2->setChecked(false);
	on_lineEdit_textChanged(ui.lineEdit->text());
	
}
void QKomintentiAnalitikaWidget::button2Clicked()
{
	ui.pushButton->setChecked(false);
	ui.pushButton_2->setChecked(true);
	on_lineEdit_textChanged(ui.lineEdit->text());
}

void QKomintentiAnalitikaWidget::button3Clicked()
{
	ui.pushButton_3->setChecked(true);
	ui.pushButton_4->setChecked(false);
	ui.pushButton_5->setChecked(false);
	ui.pushButton_6->setChecked(false);
	ui.pushButton_7->setChecked(false);
	on_lineEdit_textChanged(ui.lineEdit->text());
}

void QKomintentiAnalitikaWidget::button4Clicked()
{
	ui.pushButton_3->setChecked(false);
	ui.pushButton_4->setChecked(true);
	ui.pushButton_5->setChecked(false);
	ui.pushButton_6->setChecked(false);
	ui.pushButton_7->setChecked(false);
	on_lineEdit_textChanged(ui.lineEdit->text());
}
void QKomintentiAnalitikaWidget::button5Clicked()
{
	ui.pushButton_3->setChecked(false);
	ui.pushButton_4->setChecked(false);
	ui.pushButton_5->setChecked(true);
	ui.pushButton_6->setChecked(false);
	ui.pushButton_7->setChecked(false);
	on_lineEdit_textChanged(ui.lineEdit->text());
}
void QKomintentiAnalitikaWidget::button6Clicked()
{
	ui.pushButton_3->setChecked(false);
	ui.pushButton_4->setChecked(false);
	ui.pushButton_5->setChecked(false);
	ui.pushButton_6->setChecked(true);
	ui.pushButton_7->setChecked(false);
	on_lineEdit_textChanged(ui.lineEdit->text());
}
void QKomintentiAnalitikaWidget::button7Clicked()
{
	ui.pushButton_3->setChecked(false);
	ui.pushButton_4->setChecked(false);
	ui.pushButton_5->setChecked(false);
	ui.pushButton_6->setChecked(false);
	ui.pushButton_7->setChecked(true);
	on_lineEdit_textChanged(ui.lineEdit->text());
}

void QKomintentiAnalitikaWidget::funcART_IZLFKT()
{
	QLocale loc;
	int r = 0;
	int c = 10;
	int fieldNo[10];
	QString country[10];
	int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 70, 70, 100};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznosddv"};
	QString temp = 
		"select artikli.id, sifra, artikal, ikol, edm, icena, rabat, ikol * icena * (1 - rabat/100), ikol * icena * (artikli.ddv / 100) * (1 - rabat/100), ikol * icena * (1 + artikli.ddv / 100) * (1 - rabat/100)"
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 40 and magacin.dok_id=       ";
	temp += m_selectedText;
	temp += "";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Ид."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	model2->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ"));
	model2->setHeaderData( 9, Qt::Horizontal, trUtf8("Износ со ДДВ"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();
			if (i > 4)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				if (i == 9)
				{
					sumaDDV += temp.toFloat();
				}
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);

	ui.tableView_2->show();
}
void QKomintentiAnalitikaWidget::funcART_VLZFKT()
{
	QLocale loc;
	int r = 0;
	int c = 10;
	int fieldNo[10];
	QString country[10];
	int colWidth[] = {0, 50, 170, 70, 70, 70, 70, 70, 70, 100};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena", "rabat" "iznos", "ddv", "iznosddv"};
	QString temp = 
		"select artikli.id, sifra, artikal, ikol, edm, icena, rabat, ikol * icena * (1 - rabat/100), ikol * icena * (artikli.ddv / 100) * (1 - rabat/100), ikol * icena * (1 + artikli.ddv / 100) * (1 - rabat/100)"
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
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Кол."));
	model2->setHeaderData( 4, Qt::Horizontal, trUtf8("Едм."));
	model2->setHeaderData( 5, Qt::Horizontal, trUtf8("Цена"));
	model2->setHeaderData( 6, Qt::Horizontal, trUtf8("Рабат"));
	model2->setHeaderData( 7, Qt::Horizontal, trUtf8("Износ"));
	model2->setHeaderData( 8, Qt::Horizontal, trUtf8("ДДВ"));
	model2->setHeaderData( 9, Qt::Horizontal, trUtf8("Износ со ДДВ"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = i; //query.record().indexOf(colName[i]);
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();
			if (i > 4)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
				if (i == 9)
				{
					sumaDDV += temp.toFloat();
				}
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.tableView_2->show();

}
void QKomintentiAnalitikaWidget::funcART_ISP()
{
	QLocale loc;
	int r = 0;
	int c = 6;
	int fieldNo[6];
	QString country[6];
	int colWidth[] = {40, 70, 170, 70, 70, 70};
	QString colName[] = {"id", "sifra", "artikal", "edm", "ikol", "icena"};
	QString temp = 
		"select artikli.id, sifra, artikal, edm, ikol, icena  "
		"from magacin                                         "
		"left join artikli on magacin.artikal_id = artikli.id "
		"where magacin.dok_tip = 40 and magacin.dok_id=       ";
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
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			fieldNo[i] = query.record().indexOf(colName[i]);
			//             QStandardItem *item = new QStandardItem(query.value(fieldNo[i]).toString());
			QStandardItem *item = NULL;
			QString temp = query.value(fieldNo[i]).toString();
			if (i > 3)
			{
				temp =  loc.toString(temp.toFloat(), 'f', 2);
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
void QKomintentiAnalitikaWidget::funcART_PRM()
{
	QLocale loc;
	int r = 0;
	int c = 6;
	int fieldNo[6];
	QString country[6];
	int colWidth[] = {0, 70, 200, 60, 100, 100, 0};
	QString colName[] = {"id", "sifra", "artikal", "edm", "vkol", "vcena"};
	QString temp = 
		"select artikli.id, sifra, artikal, edm, vkol, vcena  "
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
				temp =  loc.toString(temp.toFloat(), 'f', 2);
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
void QKomintentiAnalitikaWidget::funcART_SLD()
{

}



void QKomintentiAnalitikaWidget::funcKOM_IZLFKT()
{
	CHelperClass hclass(this);
	if (m_selectedText.isEmpty())
	{
		m_selectedText = "-1";
	}
	QLocale loc;
	int r = 0;
	int c = 4;
	QString country[10];
	int colWidth[] = {100, 150, 100, 100};

    QString temp = 
        "SELECT dokumenti.dok_id, magacin.artikal_id, sum(magacin.ikol), SUM(magacin.ikol * magacin.icena * (1+ (select ddv from artikli where id = magacin.artikal_id)/100) * (1 - magacin.rabat/100))"
		"FROM dokumenti	"
		"LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND dokumenti.dok_tip = magacin.dok_tip	"
		"WHERE dokumenti.dok_tip = 40 AND dokumenti.komintent_id = ";
	temp += m_selectedText;
	temp += " GROUP BY dokumenti.dok_tip, dokumenti.dok_id, magacin.artikal_id ";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Излезна Факт."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Вк. излезна кол"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Вк. износ со ДДВ"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
			if (i > 1)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
			else
			{
				temp = i == 1 ? hclass.getArtikalByID(temp) : temp;
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.tableView_2->show();
}
void QKomintentiAnalitikaWidget::funcKOM_VLZFKT()
{
	CHelperClass hclass(this);
	if (m_selectedText.isEmpty())
	{
		m_selectedText = "-1";
	}
	QLocale loc;
	int r = 0;
	int c = 4;
	QString country[10];
	int colWidth[] = {100, 150, 100, 100};

    QString temp = 
		"SELECT dokumenti.dok_id, magacin.artikal_id, sum(magacin.ikol), SUM(magacin.ikol * magacin.icena * (1+ (select ddv from artikli where id = magacin.artikal_id)/100) * (1 - magacin.rabat/100))"
		"FROM dokumenti	"
		"LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND dokumenti.dok_tip = magacin.dok_tip	"
		"WHERE dokumenti.dok_tip = 20 AND dokumenti.komintent_id = ";
	temp += m_selectedText;
	temp += " GROUP BY dokumenti.dok_tip, dokumenti.dok_id, magacin.artikal_id ";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Влезна Факт."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Вк. влезна кол"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Вк. износ со ДДВ"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
			if (i > 1)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
			else
			{
				temp = i == 1 ? hclass.getArtikalByID(temp) : temp;
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.tableView_2->show();
}
void QKomintentiAnalitikaWidget::funcKOM_ISP()
{
	CHelperClass hclass(this);
	if (m_selectedText.isEmpty())
	{
		m_selectedText = "-1";
	}
	QLocale loc;
	int r = 0;
	int c = 4;
	QString country[10];
	int colWidth[] = {100, 150, 100, 100};
	QString temp = 
		"SELECT dokumenti.dok_id, magacin.artikal_id, SUM(magacin.vkol), SUM(magacin.ikol)"
		"FROM dokumenti	"
		"LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND dokumenti.dok_tip = magacin.dok_tip	"
		"WHERE dokumenti.dok_tip = 40 AND dokumenti.komintent_id = ";
	temp += m_selectedText;
	temp += " GROUP BY dokumenti.dok_tip, dokumenti.dok_id, magacin.artikal_id ";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Излезна Факт."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Вк. влезна кол"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Вк. излезна кол"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
			if (i > 1)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
			else
			{
				temp = i == 1 ? hclass.getArtikalByID(temp) : temp;
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.tableView_2->show();
}
void QKomintentiAnalitikaWidget::funcKOM_PRM()
{
	CHelperClass hclass(this);
	if (m_selectedText.isEmpty())
	{
		m_selectedText = "-1";
	}
	QLocale loc;
	int r = 0;
	int c = 4;
	QString country[10];
	int colWidth[] = {100, 150, 100, 100};
	QString temp = 
		"SELECT dokumenti.dok_id, magacin.artikal_id, SUM(magacin.vkol), SUM(magacin.ikol)"
		"FROM dokumenti	"
		"LEFT JOIN magacin ON dokumenti.dok_id = magacin.dok_id AND dokumenti.dok_tip = magacin.dok_tip	"
		"WHERE dokumenti.dok_tip = 20 AND dokumenti.komintent_id = ";
	temp += m_selectedText;
	temp += " GROUP BY dokumenti.dok_tip, dokumenti.dok_id, magacin.artikal_id ";
	QSqlQuery query(temp);

	model2 = new QStandardItemModel(r,c);
	model2->setHeaderData( 0, Qt::Horizontal, trUtf8("Влезна Факт."));
	model2->setHeaderData( 1, Qt::Horizontal, trUtf8("Артикал"));
	model2->setHeaderData( 2, Qt::Horizontal, trUtf8("Вк. влезна кол"));
	model2->setHeaderData( 3, Qt::Horizontal, trUtf8("Вк. излезна кол"));
	ui.tableView_2->setModel(model2);
	header2 = new QHeaderView(Qt::Horizontal, this);
	ui.tableView_2->setHorizontalHeader(header2);
	header2->show();
	int row = 0;
	float sumaDDV = 0.f;
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QStandardItem *item = NULL;
			QString temp = query.value(i).toString();
			if (i > 1)
			{
				item = new QStandardItem(loc.toString(temp.toFloat(), 'f', 2));
				item->setTextAlignment(Qt::AlignRight);
			}
			else
			{
				temp = i == 1 ? hclass.getArtikalByID(temp) : temp;
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
	CHelperClass chc(this);
	QString tip = "40";
	chc.getFakturaPlatenIznos(m_selectedText, tip);
	ui.tableView_2->show();
}
void QKomintentiAnalitikaWidget::funcKOM_SLD()
{

}