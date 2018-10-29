#include "qddvkorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>

QDdvKorekcija::QDdvKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
,m_id(0)
{
	ui.setupUi(this);
	ui.lineEdit->setFocus();
}

QDdvKorekcija::~QDdvKorekcija()
{

}

void QDdvKorekcija::showData(const QString& id)
{
	QSqlQuery query;
	query.prepare("select * from tddv where ddvID = :a");
	query.bindValue(":a", id);
	query.exec();
	query.next();

	m_id = query.value(0).toInt();
	ui.lineEdit->setText(query.value(1).toString());
	ui.lineEdit_2->setText(query.value(2).toString());
}


void QDdvKorekcija::on_pushButton_clicked()
{
	QMessageBox msgBox;
	msgBox.setText("The document has been modified.");
	msgBox.setInformativeText("Do you want to save your changes?");
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Save )
	{
		QSqlQuery query;
		query.prepare("update tddv set ddvTxt=:ddvTxt, ddvVal =:ddvVal where ddvID=:id");
		query.bindValue(":id", m_id);
		query.bindValue(":ddvTxt", ui.lineEdit->text());
		query.bindValue(":ddvVal", ui.lineEdit_2->text());

		if(query.exec())
		{
			QMessageBox msgBox;
			msgBox.setText("Transaction was Successful");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			emit succesfulEntryData();
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Transaction was Unsuccessful");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
		}
	}
}

void QDdvKorekcija::pressEscape()
{
	emit closeW();
}