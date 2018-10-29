#ifndef QMYOdobrenie_H
#define QMYOdobrenie_H

#include "qmybasewidget.h"
#include "ui_qmyOdobrenie.h"
#include <QStandardItemModel>
#include "qOdobrenievnes.h"
#include "qOdobreniekorekcija.h"
#include "qOdobrenielista.h"

class QMyOdobrenie : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMyOdobrenie(QWidget *parent = 0);
    ~QMyOdobrenie();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	virtual void refresh();

private:
    Ui::QMyOdobrenieClass ui;
    QOdobrenieVnes *OdobrenieVnes;
    QOdobrenieKorekcija *OdobrenieKorekcija;
    QOdobrenieLista *OdobrenieLista;
	int m_row;

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
	void retOdobrenieToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
	void textChanged(const QString &text);
};

#endif // QMYOdobrenie_H
