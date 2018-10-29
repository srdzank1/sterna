#ifndef QKARTICI_H
#define QKARTICI_H

#include <QWidget>
#include "ui_qkartici.h"

class QKartici : public QWidget
{
	Q_OBJECT

public:
	QKartici(QWidget *parent = 0);
	~QKartici();

private:
	Ui::QKarticiClass ui;
};

#endif // QKARTICI_H
