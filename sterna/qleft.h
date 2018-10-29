#ifndef QLEFT_H
#define QLEFT_H

#include <QWidget>
#include "ui_qleft.h"
#include <QMap>
class QMyBaseWidget;
class QLeft : public QWidget
{
	Q_OBJECT

public:
	QLeft(QWidget *parent = 0);
	~QLeft();
	void addTreeWidgetItem(QString itemInfo, QWidget *fWidget);
	void deleteTreeWidgetItem(QWidget* itemWidget);
	void getSelection();
	void updateSelection(QWidget* a);


private:
	Ui::QLeftClass ui;
	QMap<QTreeWidgetItem*, QWidget*> itemsMap;
	QList<QTreeWidgetItem*> items;
	QTreeWidgetItem * item;
	void keyPressEvent(QKeyEvent *event);

signals:
//	void signCloseMyWidget();
	void updatePrinterStatus(QWidget* i);

private slots:
	void on_treeWidget_itemSelectionChanged();
	void on_treeWidget_itemPressed(QTreeWidgetItem*,int);
	void on_treeWidget_itemClicked(QTreeWidgetItem*,int);
};

#endif // QLEFT_H
