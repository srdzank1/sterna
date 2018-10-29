#ifndef QMyProFakturi_H
#define QMyProFakturi_H

#include "qmybasewidget.h"
#include "ui_qprofakturi.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"
#include "qprofakturalista.h"

class QMyProFakturi : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyProFakturi(QWidget *parent = 0);
	~QMyProFakturi();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();

private:
	Ui::QMyProFakturiClass ui;
	QProFakturiVnes *profakturiVnes;
	QProFakturiKorekcija *profakturiKorekcija;
	QProFakturiLista *profakturiLista;


protected:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	void closeAllForm();
signals:
	void signCloseMyWidget();
	void signKomintentiFromProFaktura(QWidget*);
	void signArtikliFromProFaktura(QWidget*);

public slots:
	void closeWLista();
	void closeW();
	void callKomintenti(QWidget* myobj);
	void callArtikli(QWidget* myobj);
};

#endif // QMYISPRATNICI_H
