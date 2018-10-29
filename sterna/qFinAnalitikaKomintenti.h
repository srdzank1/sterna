#ifndef QFinAnalitKomintenti_H
#define QFinAnalitKomintenti_H

#include "qmybasewidget.h"
#include "ui_qFinAnalitikaKomintenti.h"
#include "qFinAnalitikaKomintentiwidget.h"


class QFinAnalitKomintenti : public QMyBaseWidget
{
	Q_OBJECT

public:
	QFinAnalitKomintenti(QWidget *parent = 0);
	~QFinAnalitKomintenti();
private:
	Ui::QFinAnalitKomintentiClass ui;
    QFinAnalitKomintentiWidget *FinAnalitKomintentiLista;
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
    void callretFinAnalitKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo);
	void textChanged(const QString &text);

};

#endif // QFinAnalitKomintenti_H
