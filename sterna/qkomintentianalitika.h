#ifndef QKOMINTENTIANALITIKA_H
#define QKOMINTENTIANALITIKA_H

#include "qmybasewidget.h"
#include "ui_qkomintentianalitika.h"
#include "qkomintentianalitikawidget.h"
#include <QStandardItemModel>

class QKomintentiAnalitika : public QMyBaseWidget
{
    Q_OBJECT

public:
    QKomintentiAnalitika(QWidget *parent = 0);
    ~QKomintentiAnalitika();

private:
	Ui::QKomintentiAnalitika ui;
    QKomintentiAnalitikaWidget *komintentAnalitikaLista;
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
    void callretLagerToDokument(QString& text, QString& textName, QString& textNameSaldo);
};

#endif // QKOMINTENTIANALITIKA_H
