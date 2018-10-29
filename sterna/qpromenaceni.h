#ifndef QPromenaCeni_H
#define QPromenaCeni_H

#include "qmybasewidget.h"
#include "ui_qPromenaCeni.h"
#include "qPromenaCeniwidget.h"


class QPromenaCeni : public QMyBaseWidget
{
	Q_OBJECT

public:
	QPromenaCeni(QWidget *parent = 0);
	~QPromenaCeni();
private:
	Ui::QPromenaCeniClass ui;
    QPromenaCeniWidget *PromenaCeniLista;
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
	void callretPromenaCeniToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId,  QString& strProdCena );
	void textChanged(const QString &text);
};

#endif // QPromenaCeni_H
