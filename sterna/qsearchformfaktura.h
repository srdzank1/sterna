#ifndef QSEARCHFORMFAKTURA_H
#define QSEARCHFORMFAKTURA_H

#include <QDialog>
#include "ui_qsearchformfaktura.h"
#include <QKeyEvent>

class QSearchFormFaktura : public QDialog
{
	Q_OBJECT

public:
	QSearchFormFaktura(QWidget *parent = 0);
	~QSearchFormFaktura();
	virtual void keyPressEvent(QKeyEvent *e);

	Ui::QSearchFormFaktura ui;
};

#endif // QSEARCHFORMFAKTURA_H
