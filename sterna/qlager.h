#ifndef QLAGER_H
#define QLAGER_H

#include "qmybasewidget.h"
#include "ui_qlager.h"
#include "qlagerwidget.h"


class QLager : public QMyBaseWidget
{
	Q_OBJECT

public:
	QLager(QWidget *parent = 0);
	~QLager();
private:
	Ui::QLagerClass ui;
    QLagerWidget *lagerLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	virtual void refresh();
	void refreshLista();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
    void closeWLista();
	void callretLagerToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId,  QString& strProdCena, QString& strNabCena );
	void textChanged(const QString &text);
};

#endif // QLAGER_H
