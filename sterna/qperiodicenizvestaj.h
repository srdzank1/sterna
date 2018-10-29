#ifndef QPeriodicenIzvestaj_H
#define QPeriodicenIzvestaj_H

#include "qmybasewidget.h"
#include "ui_qPeriodicenIzvestaj.h"
#include "qPeriodicenIzvestajwidget.h"


class QPeriodicenIzvestaj : public QMyBaseWidget
{
	Q_OBJECT

public:
	QPeriodicenIzvestaj(QWidget *parent = 0);
	~QPeriodicenIzvestaj();
private:
	Ui::QPeriodicenIzvestajClass ui;
    QPeriodicenIzvestajWidget *PeriodicenIzvestajLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	virtual void refresh();
	QString getDateRange();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
    void closeWLista();
    void callretPeriodicenIzvestajToDokument(QString& text, QString& textName, QString& textNameSaldo);
	void textChanged(const QString &text);
};

#endif // QPeriodicenIzvestaj_H
