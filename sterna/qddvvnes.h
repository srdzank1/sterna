#ifndef QDDVVNES_H
#define QDDVVNES_H

#include "qmybaseformwidget.h"
#include "ui_qddvvnes.h"

class QDdvVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QDdvVnes(QWidget *parent = 0);
	~QDdvVnes();
	virtual void pressEscape();

private:
	Ui::QDdvVnesClass ui;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QDDVVNES_H
