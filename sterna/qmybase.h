#ifndef QMYBASE_H
#define QMYBASE_H

#include <QWidget>
#include "ui_qmybase.h"

class QMyBase : public QWidget
{
	Q_OBJECT

public:
	QMyBase(QWidget *parent = 0);
	~QMyBase();

private:
	Ui::QMyBaseClass ui;
};

#endif // QMYBASE_H
