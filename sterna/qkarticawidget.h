#ifndef QKARTICAWIDGET_H
#define QKARTICAWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qkarticawidget.h"

class QKarticaWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKarticaWidget(QWidget *parent = 0);
	~QKarticaWidget();

private:
	Ui::QKarticaWidgetClass ui;
};

#endif // QKARTICAWIDGET_H
