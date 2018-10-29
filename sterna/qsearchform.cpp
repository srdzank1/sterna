#include "qsearchform.h"

QSearchForm::QSearchForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QSearchForm::~QSearchForm()
{

}
void QSearchForm::keyPressEvent ( QKeyEvent * e )
{
	if((e->key() == Qt::Key_Return)||(e->key() == Qt::Key_Return))
	{
		close();
	}
}
