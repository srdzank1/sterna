#ifndef QAnalitikaKomintenti_H
#define QAnalitikaKomintenti_H

#include "qmybasewidget.h"
#include "ui_qAnalitikaKomintenti.h"
#include "qAnalitikaKomintentiwidget.h"


class QAnalitikaKomintenti : public QMyBaseWidget
{
	Q_OBJECT

public:
	QAnalitikaKomintenti(QWidget *parent = 0);
	~QAnalitikaKomintenti();
private:
	Ui::QAnalitikaKomintentiClass ui;
    QAnalitikaKomintentiWidget *AnalitikaKomintentiLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	QString getModelInfo();
	virtual void refresh();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
    void closeWLista();
    void callretAnalitikaKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo);
	void textChanged(const QString &text);

};

#endif // QAnalitikaKomintenti_H
