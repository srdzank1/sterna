#ifndef QMYPRIEMNICA_H
#define QMYPRIEMNICA_H

#include <qmybasewidget.h>
#include "ui_qmypriemnica.h"
#include "qpriemnicavnes.h"
#include "qpriemnicakorekcija.h"
#include "qpriemnicalista.h"

class QMyPriemnica : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyPriemnica(QWidget *parent = 0);
	~QMyPriemnica();
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
    QStandardItemModel* QMyPriemnica::getModel();
    QStandardItemModel* QMyPriemnica::getModel2();
    QStringList getPriemnicaInfo();
	virtual void refresh();

private:
	Ui::QMyPriemnicaClass ui;
	QPriemnicaVnes *priemnicaVnes;
	QPriemnicaKorekcija *priemnicaKorekcija;
	QPriemnicaLista *priemnicaLista;

protected:
	void closeAllForm();

signals:
	void signCloseMyWidget();
	void signKomintentiFromFaktura();
	void signKomintentiFromPriemnica(QWidget*, QString);
	void signArtikliFromPriemnica(QWidget*, QString);
	void disablePrint(bool);
public slots:
	void closeWLista();
	void closeW();
	void callKomintenti(QWidget*, QString);
	void callArtikli(QWidget* myobj, QString text);
    void procF2();
    void procF3();
    void procDel();
};

#endif // QMYPRIEMNICA_H
