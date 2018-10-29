#include "qsearchformfaktura.h"

QSearchFormFaktura::QSearchFormFaktura(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QSearchFormFaktura::~QSearchFormFaktura()
{

}

void QSearchFormFaktura::keyPressEvent ( QKeyEvent * e )
{
	if((e->key() == Qt::Key_Return)||(e->key() == Qt::Key_Return))
	{
		close();
	}
}