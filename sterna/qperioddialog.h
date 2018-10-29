#ifndef QPERIODDIALOG_H
#define QPERIODDIALOG_H

#include <QDialog>
#include <QDate>
#include <QKeyEvent>
//#include "ui_qperioddialog.h"

class QPeriodDialog : public QDialog
{
	Q_OBJECT

public:
	QPeriodDialog(QWidget *parent = 0);
	~QPeriodDialog();
	virtual void keyPressEvent ( QKeyEvent * e );
//	QString getDate1(){return ui.dateTimeEdit->date().toString("dd-MM-yy");}
//	QString getDate2(){return ui.dateTimeEdit_2->date().toString("dd-MM-yy");}

private:
//	Ui::QPeriodDialog ui;
};

#endif // QPERIODDIALOG_H
