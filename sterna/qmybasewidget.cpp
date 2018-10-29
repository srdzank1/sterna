#include "qmybasewidget.h"

QMyBaseWidget::QMyBaseWidget(QWidget *parent)
	: QWidget(parent)
	,m_sourceWidget(0)
{
	ui.setupUi(this);
}

QMyBaseWidget::~QMyBaseWidget()
{

}
void QMyBaseWidget::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) 
	{
	 case Qt::Key_F2: pressF2(); break;
	 case Qt::Key_F3: pressF3(); break;
	 case Qt::Key_F4: pressF4(); break;
	 case Qt::Key_Escape: pressEscape(); break;
	 default:
		 QWidget::keyPressEvent(event);
	}
}
void QMyBaseWidget::pressF2()
{

}
void QMyBaseWidget::pressF3()
{

}
void QMyBaseWidget::pressF4()
{

}
void QMyBaseWidget::pressEscape()
{

}
void QMyBaseWidget::refresh()
{

}

QWidget* QMyBaseWidget::getSourceWidget()
{
	return m_sourceWidget;
}
void QMyBaseWidget::setSourceWidget(QWidget *sourceWidget)
{
	m_sourceWidget = sourceWidget;
}

