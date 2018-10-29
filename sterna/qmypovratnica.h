#ifndef QMYPovratnica_H
#define QMYPovratnica_H

#include "qmybasewidget.h"
#include "ui_qmyPovratnica.h"
#include <QStandardItemModel>
#include "qPovratnicavnes.h"
#include "qPovratnicakorekcija.h"
#include "qPovratnicalista.h"

class QMyPovratnica : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMyPovratnica(QWidget *parent = 0);
    ~QMyPovratnica();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	virtual void refresh();

private:
    Ui::QMyPovratnicaClass ui;
    QPovratnicaVnes *PovratnicaVnes;
    QPovratnicaKorekcija *PovratnicaKorekcija;
    QPovratnicaLista *PovratnicaLista;
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
	void signFakturiFromPovratnica(QWidget*, QString);
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
	void callFakturi(QWidget* myobj, QString text);
	void retPovratnicaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
	void textChanged(const QString &text);
	void date1Changed( const QDateTime & date1);
	void date2Changed( const QDateTime & date2);
};

#endif // QMYPovratnica_H
