#ifndef QSEARCHFORM_H
#define QSEARCHFORM_H

#include <QDialog>
#include "ui_qsearchform.h"
#include <QKeyEvent>

class QSearchForm : public QDialog
{
	Q_OBJECT

public:
	QSearchForm(QWidget *parent = 0);
	~QSearchForm();
	virtual void keyPressEvent ( QKeyEvent * e );
	Ui::QSearchForm ui;
};

#endif // QSEARCHFORM_H
