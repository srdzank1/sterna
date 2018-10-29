#ifndef QPriem_H
#define QPriem_H

#include "qmybasewidget.h"
#include "ui_qPriem.h"
#include "qPriemwidget.h"


class QPriem : public QMyBaseWidget
{
	Q_OBJECT

public:
	QPriem(QWidget *parent = 0);
	~QPriem();
private:
	Ui::QPriemClass ui;
    QPriemWidget *PriemLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	virtual void refresh();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
    void closeWLista();
    void callretPriemToDokument(QString& text, QString& textName, QString& textNameSaldo);
};

#endif // QPriem_H
