#ifndef QProFakturiKorekcija_H
#define QProFakturiKorekcija_H

#include "qmybaseformwidget.h"
#include "ui_qprofakturakorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>

class QProFakturiKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QProFakturiKorekcija(QWidget *parent = 0);
	~QProFakturiKorekcija();
	virtual void pressEscape();
	virtual void pressReturn();
	void setFocusLine();
	void setKomintent(QString text, QString textName);
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void init(int id);
private:
	Ui::QProFakturiKorekcijaClass ui;
	QStandardItemModel *model;
	QHeaderView *header; 
	int selRow;
	QString textId;
signals:
	void closeW();
	void scallKomintenti(QWidget*);
	void scallArtikli(QWidget*);

	private slots:
		void on_pushButton_4_clicked();
		void on_pushButton_5_clicked();
		void on_pushButton_6_clicked();
		void on_pushButton_3_clicked();
		void on_pushButton_2_clicked();
		void on_pushButton_clicked();
		void selectionChanged(QModelIndex,QModelIndex);
};

#endif // QISPRATNICIKOREKCIJA_H
