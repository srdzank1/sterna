#ifndef QMYBASEWIDGET_H
#define QMYBASEWIDGET_H

#include <QWidget>
#include "ui_qmybasewidget.h"
#include <QKeyEvent>


class QMyBaseWidget : public QWidget
{
	Q_OBJECT

public:
	QMyBaseWidget(QWidget *parent = 0);
	~QMyBaseWidget();

	typedef struct {
		QString faktura_id;
		QString faktura_datum;
		QString faktura_komintent_id;
		QString faktura_komintent;
		QString faktura_iznos;
		QString faktura_ddv;
		QString faktura_vkupenIznos;
		QString faktura_valuta;
		QString faktura_iznos_1;
		QString faktura_iznos_2;
		QString faktura_iznos_3;
		QString faktura_iznos_4;
		QString faktura_iznos_5;
		QString faktura_iznos_6;
	} izlFakturaData;

 	template <class T>
 	T* showMyWidget(T *a) 
 	{
		a = new T(this);
		a->showMaximized();
		a->raise();
		return a;
 	}

	template <class T>
	T* deleteMyWidget(T *a) 
	{
		if (a)
		{
			a->close();
			delete a;
			a = 0;		
		}
		return a;
	}
	

private:
    Ui::QMyBaseWidgetClass ui;
    void keyPressEvent(QKeyEvent *event);
    QWidget *m_sourceWidget;

public:
	virtual void pressF2();
	virtual void pressF3();
	virtual void pressF4();
	virtual void pressEscape();
	QWidget* getSourceWidget();
	void setSourceWidget(QWidget *sourceWidget);
	virtual void refresh();
};

#endif // QMYBASEWIDGET_H
