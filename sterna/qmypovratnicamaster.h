#ifndef QMYpovratnicamaster_H
#define QMYpovratnicamaster_H

#include "qmybasewidget.h"
#include "ui_qmypovratnicamaster.h"
#include <QStandardItemModel>
#include "qizleznipovratnicamastervnes.h"
#include "qizleznipovratnicamasterkorekcija.h"
#include "qizleznipovratnicamasterlista.h"

class QMypovratnicamaster : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMypovratnicamaster(QWidget *parent = 0);
    ~QMypovratnicamaster();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	void setInitSearchTextFaturi(QString text);
	virtual void refresh();
	bool isCheckedDetailFaktura();

private:
    Ui::QMypovratnicamasterClass ui;
    QIzleznipovratnicamasterVnes *povratnicamasterVnes;
    QIzleznipovratnicamasterKorekcija *povratnicamasterKorekcija;
    QIzleznipovratnicamasterLista *povratnicamasterLista;
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
	void retpovratnicamasterToIzvod(QStringList& listData);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
	void callpovratnicamaster(QWidget* myobj, QString text);
};

#endif // QMYpovratnicamaster_H
