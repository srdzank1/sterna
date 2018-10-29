#ifndef QMYKalkulacija_H
#define QMYKalkulacija_H

#include <qmybasewidget.h>
#include "ui_qmyKalkulacija.h"
#include "qKalkulacijavnes.h"
#include "qKalkulacijakorekcija.h"
#include "qKalkulacijalista.h"

class QMyKalkulacija : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyKalkulacija(QWidget *parent = 0);
	~QMyKalkulacija();
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
    QStandardItemModel* QMyKalkulacija::getModel();
    QStandardItemModel* QMyKalkulacija::getModel2();
    QStringList getKalkulacijaInfo();
	virtual void refresh();
	void setInitSearchText(QString text, QDateTime &date1, QDateTime &date2);

private:
	Ui::QMyKalkulacijaClass ui;
	QKalkulacijaVnes *KalkulacijaVnes;
	QKalkulacijaKorekcija *KalkulacijaKorekcija;
	QKalkulacijaLista *KalkulacijaLista;
	int m_row;
	QDateTime mmdate1;
	QDateTime mmdate2;
	QString mmText;
protected:
	void closeAllForm();

signals:
	void signCloseMyWidget();
	void signKomintentiFromFaktura();
	void signKomintentiFromKalkulacija(QWidget*, QString);
	void signArtikliFromKalkulacija(QWidget*, QString);
	void signImportArtikliFromKalkulacija(QWidget*, QString);
	void disablePrint(bool);
	void eupdateNanigator(QWidget*, QWidget*);

public slots:
	void closeWLista();
	void closeW();
	void callKomintenti(QWidget*, QString);
	void callArtikli(QWidget* myobj, QString text);
	void callPriemnici(QWidget* myobj, QString text);
    void procF2();
    void procF3();
    void procDel();
	void retFakturiToIzvod(QStringList& listData);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
};

#endif // QMYKalkulacija_H
