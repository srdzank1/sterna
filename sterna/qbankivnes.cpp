#include "qbankivnes.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "xx.h"


QBankiVnes::QBankiVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	ui.lineEdit->setFocus();
}

QBankiVnes::~QBankiVnes()
{

}

void QBankiVnes::on_pushButton_clicked()
{
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Записот ке биде внесен!"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("insert into TBank(BankIme, BankZiro) values (:ime, :ziro)");
		query.bindValue(":ime", ui.lineEdit->text());
        query.bindValue(":ziro", ui.lineEdit_2->text());

 		if (query.exec())
		{
			emit succesfulEntryData();
		}
	}
}
void QBankiVnes::pressEscape()
{
	emit closeW();
}