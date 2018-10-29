#include "qbankikorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "xx.h"


QBankiKorekcija::QBankiKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
,m_id(0)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));
	ui.lineEdit->setFocus();
}

QBankiKorekcija::~QBankiKorekcija()
{

}

void QBankiKorekcija::showData(const QString& id)
{
	m_id = id.toInt();
	QString temp = "SELECT * FROM TBank where BankId =";
	temp += id;
	QSqlQuery query(temp);
	int fieldNo1 = query.record().indexOf("BankIme");
    int fieldNo2 = query.record().indexOf("BankZiro");
    while (query.next()) {
		QString country1 = query.value(fieldNo1).toString();
        QString country2 = query.value(fieldNo2).toString();
        ui.lineEdit->setText(country1);
        ui.lineEdit_2->setText(country2);
	}
}


void QBankiKorekcija::on_pushButton_clicked()
{
	QMessageBox msgBox;
    msgBox.setText(trUtf8("Записот ќе биде изменет!"));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Save )
	{
		QSqlQuery query;
		query.prepare("update TBank set BankIme =:ime, BankZiro = :ziro  where BankId=:id");
		query.bindValue(":id", m_id);
		query.bindValue(":ime", ui.lineEdit->text());
        query.bindValue(":ziro", ui.lineEdit_2->text());

		if(query.exec())
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Трансакцијата е успешна!"));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			emit succesfulEntryData();
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Трансакцијата не е успешна!"));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
		}
	}
}

void QBankiKorekcija::pressEscape()
{
	emit closeW();
}