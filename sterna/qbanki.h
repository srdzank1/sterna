#ifndef QMYBANKI_H
#define QMYBANKI_H

#include "qbanki.h"
#include "ui_qbanki.h"
#include "qbankivnes.h"
#include "qbankikorekcija.h"
#include "qbankilista.h"


class QMyBanki : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyBanki(QWidget *parent = 0);
	~QMyBanki();
	
private:
	Ui::QMyBankiClass ui;
	QBankiVnes *bankiVnes;
	QBankiKorekcija *bankiKorekcija;
	QBankiLista *bankiLista;

public:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	void closeAllForm();
    QStandardItemModel* getModel();
    void setInitSearchText(QString text);

signals:
	void signCloseMyWidget();
	void eCloseBankiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
	void succesfulEntryData();
	void closeWLista();
	void closeW();
	void retBankiToIzvod(QString&, QString&);
	void procF2();
	void procF3();
};

#endif // QMYBANKI_H
