#ifndef QProFakturiVnes_H
#define QProFakturiVnes_H

#include "qmybaseformwidget.h"
#include "ui_qprofakturavnes.h"
#include <QStandardItemModel>
#include <QHeaderView>

class QProFakturiVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QProFakturiVnes(QWidget *parent = 0);
	~QProFakturiVnes();
	virtual void pressEscape();
	void setKomintent(QString text, QString textName);
	void setFocusLine();
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void pressReturn();

private:
	Ui::QProFakturiVnesClass ui;
	QStandardItemModel *model;
	QHeaderView *header; 
	int selRow;
	QString textId;

private slots:
	void on_pushButton_5_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_clicked();
	void selectionChanged(QModelIndex,QModelIndex);
signals:
	void closeW();
	void callListOfKomintenti(QWidget*);
	void scallKomintenti(QWidget*);
	void scallArtikli(QWidget*);
};

#endif // QISPRATNICIVNES_H
