#include "qkalkulacijalagerlista.h"

QKalkulacijaLagerLista::QKalkulacijaLagerLista(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//	connect(ui.tableView, SIGNAL(returnPressed()), this, SLOT(on_returnPressed()));

	ui.tableView->setFocus();
	ui.tableView->show();
}

QKalkulacijaLagerLista::~QKalkulacijaLagerLista()
{

}

void QKalkulacijaLagerLista::lista(const QString& nameSearch)
{
	QLocale loc;
	int r = 0;
	int c = 11;
	int fieldNo[11]; 
	QString country[11];
	int colWidth[] = {0, 80, 180, 80, 100, 100, 0, 0, 100, 0, 100};
	QString colName[9] = {"id", "sifra", "artikal", "edm", "ncena", "pcena", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};

	QString temp = 
		"select artikal_id, artikli.sifra, artikli.artikal, artikli.edm , max(magacin.nab_cena), max(magacin.prod_cena),0,0,0,0, komintent_id "
		"from magacin "
		"left join artikli on  magacin.artikal_id = artikli.id "
		"where artikli.sifra like '" + nameSearch + "' "
		"group by artikal_id, artikli.sifra, artikli.artikal, artikli.edm, komintent_id order by artikal_id";
	QSqlQuery query(temp);
	QSqlError err = query.lastError(); 
	model = new QStandardItemModel(r, c);
	model->setHeaderData( 0, Qt::Horizontal, trUtf8("ID\n"));
	model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра\n"));
	model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал\n"));
	model->setHeaderData( 3, Qt::Horizontal, trUtf8("Един.\nмера"));
	model->setHeaderData( 4, Qt::Horizontal, trUtf8("Набавна Цена\nсо ДДВ"));
	model->setHeaderData( 5, Qt::Horizontal, trUtf8("Продажна Цена\nсо ДДВ"));
	model->setHeaderData( 6, Qt::Horizontal, trUtf8("Влезна\nКоличина"));
	model->setHeaderData( 7, Qt::Horizontal, trUtf8("Излезна\nКоличина"));
	model->setHeaderData( 8, Qt::Horizontal, trUtf8("Салдо\nКоличина"));
	//	model->setHeaderData( 9, Qt::Horizontal, trUtf8("Салдо Износ\nсо ДДВ"));
	model->setHeaderData( 10, Qt::Horizontal, trUtf8("Коминтент\n"));

	ui.tableView->setModel(model);
	header = new QHeaderView(Qt::Horizontal, this);
    header->setSectionsClickable(true);

	ui.tableView->setHorizontalHeader(header);
	header->show();
	int row = 0;
	CHelperClass chc(this);
	chc.createSaldoArtikliOdlivMapAll();
	chc.createSaldoProizvodiPrilivMapAll();
	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkSaldo = 0.f;
	float vkSaldoNab = 0.f;
	float vkTotalSaldoNab = 0.f;
	setUpdatesEnabled(false);
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QString temp = query.value(i).toString();
			QStandardItem *item = NULL; 
			if (i == 6)
			{
				QString keyT = query.value(0).toString() + "Key" + query.value(10).toString();
				vkVlezKol = chc.getLagerListaAll(keyT , (QString)"PRILIV");
				temp =  loc.toString(vkVlezKol ,'f', 2);
				item = new QStandardItem(temp);
				item->setTextAlignment(Qt::AlignRight);
			}
			else if (i == 7)
			{
				QString keyT = query.value(0).toString() + "Key" + query.value(10).toString();
				vkIzlezKol = chc.getLagerListaAll(keyT , (QString)"ODLIV");
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
			// 			else if (i == 9)
			// 			{
			// 				vkSaldoNab = vkSaldo * query.value(4).toFloat();
			// 				vkTotalSaldoNab += vkSaldoNab;
			// 				temp =  loc.toString(vkSaldoNab ,'f', 2);
			// 				item = new QStandardItem(temp);
			// 				item->setTextAlignment(Qt::AlignRight);
			// 			}
			else if (i == 10)
			{
				item = new QStandardItem(temp);
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
		row++;
	} 
	setUpdatesEnabled(true);
	temp =  loc.toString(vkTotalSaldoNab ,'f', 2);
	QItemSelectionModel *sm = ui.tableView->selectionModel();
	connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
		this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
	ui.tableView->show();
}

void QKalkulacijaLagerLista::selectionChanged(QModelIndex modelX, QModelIndex modelY)
{
	
	int i = modelX.row();
	m_selectedNabavCena = model->item(i, 4) ? model->item(i, 4)->text():"";
	m_selectedProdCena = model->item(i, 5) ? model->item(i, 5)->text():"";
	ui.tableView->setFocus();
	ui.tableView->selectRow(i);
}

void QKalkulacijaLagerLista::on_returnPressed()
{
//	close();
}

void QKalkulacijaLagerLista::keyPressEvent ( QKeyEvent * e )
{
	if((e->key() == Qt::Key_Return)||(e->key() == Qt::Key_Enter))
	{
		close();
	}
}
