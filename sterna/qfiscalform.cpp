#include "qfiscalform.h"

QFiscalForm::QFiscalForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.lineEdit_2, SIGNAL(textChanged(const QString & )), this, SLOT(procLine1TextChanged(const QString & )));
	connect(ui.lineEdit_2, SIGNAL(returnPressed ()), this, SLOT(procLine1ReturnPressed()));
}

QFiscalForm::~QFiscalForm()
{

}
void QFiscalForm::setIznos(QString &textIznos)
{
	ui.lineEdit->setText(textIznos);
	ui.lineEdit_2->setText(textIznos);
	ui.lineEdit_2->selectAll();
}
void QFiscalForm::procLine1TextChanged(const QString & plateno)
{
	QLocale loc;
	float platenoIznos = loc.toFloat(plateno);
	float Iznos = loc.toFloat(ui.lineEdit->text());
	float kusur = platenoIznos - Iznos;
	ui.lineEdit_3->setText(loc.toString(kusur, 'f', 2));
	
	int stop = 0;
}
void QFiscalForm::procLine1ReturnPressed()
{
	accept();
}
	