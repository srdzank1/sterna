#ifndef QMYIzjava_H
#define QMYIzjava_H

#include <qmybasewidget.h>
#include "ui_qmyIzjava.h"
#include "qizjavavnes.h"
#include "qizjavakorekcija.h"
#include "qizjavalista.h"

class QMyIzjava : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyIzjava(QWidget *parent = 0);
	~QMyIzjava();
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
    QStandardItemModel* QMyIzjava::getModel();
    QStandardItemModel* QMyIzjava::getModel2();
    QStringList getIzjavaInfo();
	virtual void refresh();
	void setInitSearchText(QString text);

private:
	Ui::QMyIzjavaClass ui;
	QIzjavaVnes *IzjavaVnes;
	QIzjavaKorekcija *IzjavaKorekcija;
	QIzjavaLista *IzjavaLista;
	int m_row;

protected:
	void closeAllForm();

signals:
	void signCloseMyWidget();
	void signKomintentiFromFaktura();
	void signKomintentiFromIzjava(QWidget*, QString);
	void signArtikliFromIzjava(QWidget*, QString);
	void disablePrint(bool);
	void eupdateNanigator(QWidget*, QWidget*);

public slots:
	void closeWLista();
	void closeW();
	void callKomintenti(QWidget*, QString);
	void callArtikli(QWidget* myobj, QString text);
    void procF2();
    void procF3();
    void procDel();
	void retIzjavaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
};

#endif // QMYIzjava_H
