#ifndef QBANKIKOREKCIJA_H
#define QBANKIKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qbankikorekcija.h"

class QBankiKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QBankiKorekcija(QWidget *parent = 0);
	~QBankiKorekcija();
	void showData(const QString& id);
	virtual void pressEscape();

private:
	Ui::QBankiKorekcijaClass ui;
	int m_id;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QBANKIKOREKCIJA_H
