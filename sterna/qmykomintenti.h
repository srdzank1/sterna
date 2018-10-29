#ifndef QMYKOMINTENTI_H
#define QMYKOMINTENTI_H

#include "qmykomintenti.h"
#include "ui_qmykomintenti.h"
#include "qkomintentivnes.h"
#include "qkomintentikorekcija.h"
#include "qkomintentilista.h"


class QMyKomintenti : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyKomintenti(QWidget *parent = 0);
	~QMyKomintenti();
	
private:
	Ui::QMyKomintentiClass ui;
	QKomintentiVnes *komintentiVnes;
	QKomintentiKorekcija *komintentiKorekcija;
	QKomintentiLista *komintentiLista;
	QString lastSearchStr;

public:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	void closeAllForm();
    QStandardItemModel* getModel();
	void setInitSearchText(QString text);

signals:
	void signCloseMyWidget();
	void eCloseKomintentiFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
	void succesfulEntryData();
	void closeWLista();
	void closeW();
	void retKomintentToPriemnica(QString&, QString&);
    void procF2();
    void procF3();
    void procDel();
	void textChanged(const QString &text);
};

#endif // QMYKOMINTENTI_H
