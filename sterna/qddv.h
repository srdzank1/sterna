#ifndef QMYDDV_H
#define QMYDDV_H

#include "qddv.h"
#include "ui_qddv.h"
#include "qddvvnes.h"
#include "qddvkorekcija.h"
#include "qddvlista.h"


class QMyDdv : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyDdv(QWidget *parent = 0);
	~QMyDdv();
	
private:
	Ui::QMyDdvClass ui;
	QDdvVnes *ddvVnes;
	QDdvKorekcija *ddvKorekcija;
	QDdvLista *ddvLista;

public:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	void closeAllForm();
signals:
	void signCloseMyWidget();
	void eCloseDdvFromPriemnica();
public slots:
	void succesfulEntryData();
	void closeWLista();
	void closeW();
	void retKomintentToPriemnica(QString&, QString&);

};

#endif // QMYDDV_H
