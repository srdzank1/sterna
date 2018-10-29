#ifndef QFAKTURIVLEZNI_H
#define QFAKTURIVLEZNI_H

#include <qmybasewidget.h>
#include "ui_qmypriemnica.h"
#include "qfakturivnes.h"
#include "qfakturikorekcija.h"
#include "qfakturilista.h"

class QFakturiVlezni : public QMyBaseWidget
{
    Q_OBJECT

public:
    QFakturiVlezni(QWidget *parent = 0);
    ~QFakturiVlezni();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    QStandardItemModel* QFakturiVlezni::getModel();
    QStandardItemModel* QFakturiVlezni::getModel2();
    QStringList getPriemnicaInfo();
	void setInitSearchText(QString text, QDateTime &date1, QDateTime &date2);
	virtual void refresh();
	QStringList getIspratnicaInfo();

private:
    Ui::QMyPriemnicaClass ui;
    QFakturiVlezniVnes *fakturaVleznaVnes;
    QFakturiVlezniKorekcija *fakturaVleznaKorekcija;
    QFakturaVleznaLista *fakturaVleznaLista;
	int m_row;
	QDateTime mmdate1;
	QDateTime mmdate2;
	QString mmText;


protected:
    void closeAllForm();

signals:
    void signCloseMyWidget();
    void signKomintentiFromFaktura();
    void signKomintentiFromPriemnica(QWidget*, QString);
    void signArtikliFromPriemnica(QWidget*, QString);
	void eupdateNanigator(QWidget*, QWidget*);

public slots:
    void closeWLista();
    void closeW();
    void callKomintenti(QWidget*, QString);
    void callArtikli(QWidget* myobj, QString text);
    void procF2();
    void procF3();
    void procDel();
	void retFakturiToIzvod(QStringList& listData);
	void textChanged(const QString &text, QDateTime &date1, QDateTime &date2);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
	void textChanged(const QString &text);
};

#endif // QFAKTURIVLEZNI_H
