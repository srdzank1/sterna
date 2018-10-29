#ifndef QMYKasa_H
#define QMYKasa_H

#include "qmybasewidget.h"
#include "ui_qmyKasa.h"
#include <QStandardItemModel>
#include "qKasavnes.h"
#include "qKasakorekcija.h"
#include "qKasalista.h"

class QMyKasa : public QMyBaseWidget
{
    Q_OBJECT

public:
    QMyKasa(QWidget *parent = 0);
    ~QMyKasa();
    void sendPrintMessage();
    QStandardItemModel* getModel();
    QStandardItemModel* getModel2();
    QStringList getIspratnicaInfo();
    void setInitSearchText(QString text);
	virtual void refresh();

private:
    Ui::QMyKasaClass ui;
    QKasaVnes *KasaVnes;
    QKasaKorekcija *KasaKorekcija;
    QKasaLista *KasaLista;
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
	void retKasaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
};

#endif // QMYKasa_H
