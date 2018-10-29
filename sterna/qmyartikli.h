#ifndef QMYARTIKLI_H
#define QMYARTIKLI_H

#include "qmybasewidget.h"
#include "ui_qmyartikli.h"
#include "qartiklivnes.h"
#include "qartiklikorekcija.h"
#include "qmyartiklilista.h"



class QMyArtikli : public QMyBaseWidget
{
	Q_OBJECT

public:
	QMyArtikli(QWidget *parent = 0);
	~QMyArtikli();
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	QStandardItemModel* getModel();
	void setInitSearchText(QString text);
	

private:
	Ui::QMyArtikliClass ui;
	QArtikliVnes *artikliVnes;
	QArtikliKorekcija *artikliKorekcija;
	QMyArtikliLista *artikliLista;
	int m_row;
	QString lastSearchStr;
protected:

	void closeAllForm();
signals:
	void signCloseMyWidget();
	void eCloseArtikliFromPriemnica();
    void eupdateNanigator(QWidget*, QWidget*);
public slots:
	void succesfulEntryData();
	void closeWLista();
	void closeW();
	void retArtikliToPriemnica(QString& text, QString& textName);
    void procF2();
    void procF3();
    void procDel();
	void textChanged(const QString &);
};

#endif // QMYARTIKLI_H
