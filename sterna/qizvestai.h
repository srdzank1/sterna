#ifndef QIZVESTAI_H
#define QIZVESTAI_H

#include "qmybasewidget.h"
#include "ui_qizvestai.h"
#include <QScrollArea>
#include <QScrollBar>
#include "qizvestaiwidget.h"



class QIzvestai : public QMyBaseWidget
{
	Q_OBJECT

public:
	QIzvestai(QWidget *parent = 0);
	~QIzvestai();
    virtual void refresh();

private:
	Ui::QIzvestaiClass ui;
    QScrollArea scrollArea;
    QIzvestaiWidget *izvestai;
protected:
	virtual void pressEscape();
	

public slots:
    void closeW();

signals:
	void signCloseMyWidget();

};

#endif // QIZVESTAI_H
