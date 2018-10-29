#ifndef QBANKIVNES_H
#define QBANKIVNES_H

#include "qmybaseformwidget.h"
#include "ui_qbankivnes.h"

class QBankiVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QBankiVnes(QWidget *parent = 0);
	~QBankiVnes();
	virtual void pressEscape();

private:
	Ui::QBankiVnesClass ui;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QBANKIVNES_H
