#include "qperioddialog.h"

QPeriodDialog::QPeriodDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.dateTimeEdit->setDate(QDate::currentDate());
	ui.dateTimeEdit_2->setDate(QDate::currentDate());
}

QPeriodDialog::~QPeriodDialog()
{

}

void QPeriodDialog::keyPressEvent ( QKeyEvent * e )
{
	if((e->key() == Qt::Key_Return)||(e->key() == Qt::Key_Enter))
	{
		accept();
		//close();
	}
}