#ifndef QMYfaktmaster_H
#define QMYfaktmaster_H

#include "qmybasewidget.h"
#include "ui_qmyfaktmaster.h"
#include <QStandardItemModel>
#include "qizleznifaktmastervnes.h"
#include "qizleznifaktmasterkorekcija.h"
#include "qizleznifaktmasterlista.h"

class QMyfaktmaster : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMyfaktmaster(QWidget *parent = 0);
    ~QMyfaktmaster();
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
    Ui::QMyfaktmasterClass ui;
    QIzleznifaktmasterVnes *faktmasterVnes;
    QIzleznifaktmasterKorekcija *faktmasterKorekcija;
    QIzleznifaktmasterLista *faktmasterLista;
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

public slots:
    void closeWLista();
    void procF2();
    void procF3();
    void procDel();
    void closeW();
    void callKomintenti(QWidget* myobj, QString text);
    void callArtikli(QWidget* myobj, QString text);
	void retfaktmasterToIzvod(QStringList& listData);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
	void callfaktmaster(QWidget* myobj, QString text);
};

#endif // QMYfaktmaster_H
