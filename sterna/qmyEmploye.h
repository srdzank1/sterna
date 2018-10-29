#ifndef QMYEmploye_H
#define QMYEmploye_H

#include "qmyEmploye.h"
#include "ui_qmyEmploye.h"
#include "qEmployevnes.h"
#include "qEmployekorekcija.h"
#include "qEmployelista.h"


class QMyEmploye : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyEmploye(QWidget *parent = 0);
	~QMyEmploye();
	
private:
	Ui::QMyEmployeClass ui;
	QEmployeVnes *EmployeVnes;
	QEmployeKorekcija *EmployeKorekcija;
	QEmployeLista *EmployeLista;

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
	void eCloseEmployeFromPriemnica();
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

#endif // QMYEmploye_H
