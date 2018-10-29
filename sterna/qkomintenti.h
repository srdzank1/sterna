#ifndef QKOMINTENTI_H
#define QKOMINTENTI_H

#include <QWidget>
#include "ui_qkomintenti.h"

class QKomintenti : public QWidget
{
	Q_OBJECT

public:
	QKomintenti(QWidget *parent = 0);
	~QKomintenti();

private:
	Ui::QKomintentiClass ui;
};

#endif // QKOMINTENTI_H
