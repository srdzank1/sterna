#ifndef QIZVESTAIWIDGET_H
#define QIZVESTAIWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qizvestaiwidget.h"
#include <QDateTime>
#include "xx.h"


typedef struct tbound 
{
    QRect r;
	QRect rt;
    QColor c;
    QString t;
	QString tt;
	bool selected;
} *bound;



class QIzvestaiWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzvestaiWidget(QWidget *parent = 0);
	~QIzvestaiWidget();
    virtual void paintEvent(QPaintEvent *);
    virtual void pressEscape();
	virtual void mouseMoveEvent(QMouseEvent * event);
	void createLagerList();
	void createTimeLine(QPainter &painter, int ww);
    void createSample(QPainter &painter);
	void createRedLine(QPainter &painter, int ww);

private:
	Ui::QIzvestaiWidgetClass ui;
    QVector<bound> listBound;
	int ww;
	QImage *imag;
	typedef struct {
		Singleton::tinfoFakturi item;
		QRect rectInfo;
	} tdok_infoSRG;
	QVector<tdok_infoSRG> listItemsSrg;
signals:
    void closeW();

};

#endif // QIZVESTAIWIDGET_H
