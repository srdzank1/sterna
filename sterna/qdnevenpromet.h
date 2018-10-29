#ifndef QDnevenpromet_H
#define QDnevenpromet_H

#include "qmybasewidget.h"
#include "ui_qDnevenpromet.h"
#include "qDnevenprometwidget.h"


class QDnevenpromet : public QMyBaseWidget
{
	Q_OBJECT

public:
	QDnevenpromet(QWidget *parent = 0);
	~QDnevenpromet();
private:
	Ui::QDnevenprometClass ui;
    QDnevenprometWidget *DnevenprometLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	virtual void refresh();
	QString getDatum();
	QString getPeriod();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
	void disablePrint(bool);
public slots:
    void closeWLista();
    void callretDnevenprometToDokument(QString& text, QString& textName, QString& textNameSaldo);
};

#endif // QDnevenpromet_H
