#include "qmybaseformwidget.h"
#include <QKeyEvent>

QMyBaseFormWidget::QMyBaseFormWidget(QWidget *parent)
	: QWidget(parent)
    ,m_Widget(0)
{
	ui.setupUi(this);
	setMouseTracking(true);
}

QMyBaseFormWidget::~QMyBaseFormWidget()
{

}

void QMyBaseFormWidget::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) 
	{
	case Qt::Key_Escape: 
		pressEscape(); break;
	case Qt::Key_Return: 
		pressReturn(); break;
	case Qt::Key_Enter: 
		pressReturn(); break;
	case Qt::Key_F9: 
		pressF9(); break;

	default:
		QWidget::keyPressEvent(event);
	}
}

void QMyBaseFormWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
	pressReturn();
}

void QMyBaseFormWidget::pressEscape()
{
}
void QMyBaseFormWidget::refresh()
{
}

void QMyBaseFormWidget::pressReturn()
{
}

void QMyBaseFormWidget::pressF9()
{
}


void QMyBaseFormWidget::paintEvent ( QPaintEvent * event )
{
	// paint here
}