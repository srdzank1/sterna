#ifndef QFISCALFORM_H
#define QFISCALFORM_H

#include <QDialog>
#include "ui_qfiscalform.h"

class QFiscalForm : public QDialog
{
	Q_OBJECT

public:
	QFiscalForm(QWidget *parent = 0);
	~QFiscalForm();
	void setIznos(QString &textIznos);
	QString getPlatenIznos(){return ui.lineEdit_2->text();}

private:
	Ui::QFiscalForm ui;
private slots:
	void procLine1TextChanged(const QString & );
	void procLine1ReturnPressed();

};

#endif // QFISCALFORM_H
