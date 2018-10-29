#ifndef QMYIZVOD_H
#define QMYIZVOD_H

#include "qmybasewidget.h"
#include "ui_qizvod.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qizvodlista.h"
#include <QStringList>

class QMyIzvod : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyIzvod(QWidget *parent = 0);
	~QMyIzvod();
	void refresh();
private:
	Ui::QMyIzvodClass ui;
	QIzvodVnes *izvodVnes;
	QIzvodKorekcija *izvodKorekcija;
	QIzvodLista *izvodLista;
	QStringList m_info;



protected:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();

	void closeAllForm();
signals:
	void signCloseMyWidget();
	void signZiroSmetkiFromIzvod(QWidget*, QString);
	void signFakturiFromIzvod(QWidget*, QString, int);
	void signKomintentiFromIspratnica(QWidget*, QString);
public slots:
	void closeWLista();
	void closeW();
	void callZiroSmetki(QWidget* myobj, QString ziro);
	void callFakturi(QWidget* myobj, QString ziro, int tip);
    void procF2();
    void procF3();
    void procDel();
	void callKomintenti(QWidget* myobj, QString text);
	

};

#endif // QMYIZVOD_H
