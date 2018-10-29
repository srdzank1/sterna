#ifndef QMYSmetki_H
#define QMYSmetki_H

#include "qmybasewidget.h"
#include "ui_qmySmetki.h"
#include <QStandardItemModel>
#include "qizlezniSmetkivnes.h"
#include "qizlezniSmetkikorekcija.h"
#include "qizlezniSmetkilista.h"

class QMySmetki : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMySmetki(QWidget *parent = 0);
    ~QMySmetki();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	void setInitSearchTextFaturi(QString text);
	virtual void refresh();
	bool isCheckedDetailFaktura();

private:
    Ui::QMySmetkiClass ui;
    QIzlezniSmetkiVnes *SmetkiVnes;
    QIzlezniSmetkiKorekcija *SmetkiKorekcija;
    QIzlezniSmetkiLista *SmetkiLista;
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
    void signPrint();
	void eupdateNanigator(QWidget*, QWidget*);
	void disablePrint(bool );

public slots:
    void closeWLista();
    void procF2();
    void procF3();
    void procDel();
    void closeW();
    void callKomintenti(QWidget* myobj, QString text);
    void callArtikli(QWidget* myobj, QString text);
	void retSmetkiToIzvod(QStringList& listData);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
};

#endif // QMYSmetki_H
