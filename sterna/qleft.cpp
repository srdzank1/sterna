#include "qleft.h"
#include <QKeyEvent>
#include "qmybasewidget.h"

QLeft::QLeft(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	item = new QTreeWidgetItem(ui.treeWidget);
	item->setText(0, trUtf8("Документи"));
    QIcon icon(":/sterna/Resources/arrow-down-icon.png");
    item->setIcon(0, icon);
	itemsMap.insertMulti(item, 0);
	item->setExpanded(true);
}

QLeft::~QLeft()
{

}
void QLeft::addTreeWidgetItem(QString itemInfo, QWidget *fWidget)
{
	QTreeWidgetItem* itemChild = new QTreeWidgetItem(item);
	itemChild->setText(0, itemInfo);
    QIcon icon(":/sterna/Resources/k-color-chooser-icon.png");
    itemChild->setIcon(0, icon);
    itemsMap.insertMulti(itemChild, fWidget);
	items.append(itemChild);
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i;
	for (i = itemsMap.begin(); i != itemsMap.end(); i++)
	{
		if (i.value() == fWidget)
		{
			for (int i1 = 0; i1 < items.size(); i1++)
			{
				if (items.at(i1) == (i.key()))
				{
					ui.treeWidget->setCurrentItem(i.key());
				}
			}
		}
	}
}

void QLeft::on_treeWidget_itemClicked(QTreeWidgetItem* item ,int)
{
	 QMap<QTreeWidgetItem*, QWidget*>::const_iterator i = itemsMap.find(item);
	 if (!i.value())
	 {
		 return;
	 }
	 (*i)->raise();
}


void QLeft::on_treeWidget_itemPressed(QTreeWidgetItem* item, int)
{
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i = itemsMap.find(item);
	if (!i.value())
	{
		return;
	}
	(*i)->raise();
}

void QLeft::on_treeWidget_itemSelectionChanged()
{
	QList<QTreeWidgetItem *> list = ui.treeWidget->selectedItems();
	if (!list.count())
	{
		return;
	}
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i = itemsMap.find(list.at(0));
	if (!i.value())
	{
		return;
	}
	(*i)->raise();
	emit updatePrinterStatus((*i));
}

void QLeft::deleteTreeWidgetItem(QWidget* itemWidget)
{
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i;
	for (i = itemsMap.begin(); i != itemsMap.end(); i++)
	{
		if (i.value() == itemWidget)
		{
			for (int i1 = 0; i1 < items.size(); i1++)
			{
				if (items.at(i1) == (i.key()))
				{
					items.removeAt(i1);
					item->removeChild(i.key());
				}
			}
		}
	}
}

void QLeft::keyPressEvent(QKeyEvent * event)
{

}


void QLeft::getSelection()
{
	QList<QTreeWidgetItem *> list = ui.treeWidget->selectedItems();
	if (!list.count())
	{
		return;
	}
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i = itemsMap.find(list.at(0));
	if (!i.value())
	{
		return;
	}
	(*i)->setFocus();
	(*i)->raise();
}


void QLeft::updateSelection(QWidget* itemWidget)
{
	QMap<QTreeWidgetItem*, QWidget*>::const_iterator i;
	for (i = itemsMap.begin(); i != itemsMap.end(); i++)
	{
		if (i.value() == itemWidget)
		{
			for (int i1 = 0; i1 < items.size(); i1++)
			{
				if (items.at(i1) == (i.key()))
				{
					items.at(i1)->setSelected(true);
				}
				else
				{
					items.at(i1)->setSelected(false);
				}
			}
		}
	}
}