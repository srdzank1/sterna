#ifndef QMYIspratnici_H
#define QMYIspratnici_H

#include "qmybasewidget.h"
#include "ui_qmyIspratnici.h"
#include <QStandardItemModel>
#include "qizlezniIspratnicivnes.h"
#include "qizlezniIspratnicikorekcija.h"
#include "qizlezniIspratnicilista.h"

class QMyIspratnici : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMyIspratnici(QWidget *parent = 0);
    ~QMyIspratnici();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	void setInitSearchTextFaturi(QString text);
	virtual void refresh();
	bool isCheckedDetailFaktura();
	void refreshLista();

private:
    Ui::QMyIspratniciClass ui;
    QIzlezniIspratniciVnes *IspratniciVnes;
    QIzlezniIspratniciKorekcija *IspratniciKorekcija;
    QIzlezniIspratniciLista *IspratniciLista;
	int m_row;
	QDateTime mmdate1;
	QDateTime mmdate2;
	QString mmText;

protected:
    virtual void pressF2();
    virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	void closeAllForm();

signals:
    void signCloseMyWidget();
    void signKomintentiFromIspratnica(QWidget*, QString);
    void signArtikliFromIspratnica(QWidget*, QString);
	void signIspratnica(QWidget*, QString);
    void signPrint();
	void eupdateNanigator(QWidget*, QWidget*);
	void disablePrint(bool );
	void signCallSearchForm();



public slots:
    void closeWLista();
    void procF2();
    void procF3();
    void procDel();
    void closeW();
    void callKomintenti(QWidget* myobj, QString text);
    void callArtikli(QWidget* myobj, QString text);
	void retIspratniciToIzvod(QStringList& listData);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
	void callIspratnici(QWidget* myobj, QString text);
	void procCallSearchFormA();
};

#endif // QMYIspratnici_H
