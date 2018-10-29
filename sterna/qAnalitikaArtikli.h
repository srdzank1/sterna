#ifndef QAnalitikaArtikli_H
#define QAnalitikaArtikli_H

#include "qmybasewidget.h"
#include "ui_qAnalitikaArtikli.h"
#include "qAnalitikaArtikliwidget.h"


class QAnalitikaArtikli : public QMyBaseWidget
{
	Q_OBJECT

public:
	QAnalitikaArtikli(QWidget *parent = 0);
	~QAnalitikaArtikli();
private:
	Ui::QAnalitikaArtikliClass ui;
    QAnalitikaArtikliWidget *AnalitikaArtikliLista;
public:
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();
    void setInitSearchText(QString text);
	QStandardItemModel* getModel();
	virtual void refresh();
    QString getModelInfo();
    QString getModelInfo2();

signals:
    void signCloseMyWidget();
    void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
    void closeWLista();
    void callretAnalitikaArtikliToDokument(QString& text, QString& textName, QString& textNameSaldo);
	void textChanged(const QString &text);
};

#endif // QAnalitikaArtikli_H
