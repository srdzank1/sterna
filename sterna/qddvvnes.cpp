#include "qddvvnes.h"
#include <QSqlQuery>
#include <QMessageBox>

QDdvVnes::QDdvVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit_2->setFocus();
}

QDdvVnes::~QDdvVnes()
{

}

void QDdvVnes::on_pushButton_clicked()
{
	QMessageBox msgBox;
	msgBox.setText("The document has been inserted.");
	msgBox.setInformativeText("Do you want to save your changes?");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("insert into tddv(ddvTxt, ddvVal) values (:ddvTxt, :ddvVal)");
		query.bindValue(":ddvTxt", ui.lineEdit_2->text());
		query.bindValue(":ddvVal", ui.lineEdit_3->text().toFloat());

 		if (query.exec())
		{
			emit succesfulEntryData();
		}
	}
}
void QDdvVnes::pressEscape()
{
	emit closeW();
}