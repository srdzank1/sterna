#include "qartiklivnes.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "chelperclass.h"
#include <QDesktopWidget>
#include "xx.h"

QArtikliVnes::QArtikliVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

	ui.lineEdit_2->setFocus();
	ui.lineEdit_2->setStyleSheet("background-color: yellow");
	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_3->installEventFilter(this);
	ui.lineEdit_4->installEventFilter(this);
	ui.lineEdit_5->installEventFilter(this);
	ui.lineEdit_6->installEventFilter(this);
	ui.comboBox->installEventFilter(this);
    ui.lineEdit_2->setFocus();

}


QArtikliVnes::~QArtikliVnes()
{

}

void QArtikliVnes::setInitValue(QString text)
{
	ui.lineEdit_2->setText(text);
	ui.lineEdit_2->selectAll();
	ui.lineEdit_3->setText(text);
}

void QArtikliVnes::on_pushButton_clicked()
{
	CHelperClass *chlp = new CHelperClass(this);
	if (ui.lineEdit_2->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси шифра на артикал!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_2->setFocus();
		return;
	}
	if (chlp->isSifraArtikalExists(ui.lineEdit_2->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Постои артикал со таа шифра!\nВнеси друга шифра"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_2->setFocus();
		return;
	}	
	if (ui.lineEdit_3->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси име на артикалот!!!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_3->setFocus();
		return;
	}	
	


	
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Документот ќе биде внесен."));
		msgBox.setInformativeText(trUtf8("Дали сакате да ги сочувате промените?"));
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();
        QLocale loc;
		if (ret == QMessageBox::Ok )
		{
			QSqlQuery query;
			query.prepare("insert into artikli (sifra, artikal, edm, ref, kataloski_broj, art_nabavna_cena, art_nabavna_cena_valuta, art_prodazna_cena, art_prodazna_cena_valuta, ddv)" 
				"values(:sifra, :artikal, :edm, :ref, :kb, :anc, :ancv, :apc, :apcv, :iddv)");
			query.bindValue(":sifra", ui.lineEdit_2->text());
			query.bindValue(":artikal", ui.lineEdit_3->text());
			query.bindValue(":edm", ui.lineEdit_4->text());
			query.bindValue(":ref", ui.lineEdit_5->text());
			query.bindValue(":kb", ui.lineEdit_6->text());
			query.bindValue(":anc", "0");
			query.bindValue(":ancv", "0");
            query.bindValue(":apc", "0");
			query.bindValue(":apcv", "0");
            query.bindValue(":iddv", ui.comboBox->currentText());

			if (query.exec())
			{
				emit succesfulEntryData();
			}
		}
}
void QArtikliVnes::pressEscape()
{
	emit closeW();
}

void QArtikliVnes::pressReturn()
{
    if (ui.lineEdit_2->hasFocus())
    {
        ui.lineEdit_3->setFocus();
		ui.lineEdit_3->selectAll();
    }
    else if (ui.lineEdit_3->hasFocus())
    {
        ui.lineEdit_4->setFocus();
		ui.lineEdit_4->selectAll();

    }
    else if (ui.lineEdit_4->hasFocus())
    {
        ui.lineEdit_5->setFocus();
		ui.lineEdit_5->selectAll();
    }
    else if (ui.lineEdit_5->hasFocus())
    {
        ui.lineEdit_6->setFocus();
		ui.lineEdit_6->selectAll();
    }
    else if (ui.lineEdit_6->hasFocus())
    {
        ui.comboBox->setFocus();
    }
    else if (ui.comboBox->hasFocus())
    {
		on_pushButton_clicked();
    }
}

bool QArtikliVnes::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::FocusIn)
	{
		if (object == ui.lineEdit_2)
		{
			ui.lineEdit_2->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_3)
		{
			ui.lineEdit_3->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_4)
		{
			ui.lineEdit_4->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: yellow");
		}
		if (object == ui.lineEdit_6)
		{
			ui.lineEdit_6->setStyleSheet("background-color: yellow");
		}
		if (object == ui.comboBox)
		{
			ui.comboBox->setStyleSheet("background-color: yellow");
		}

	}
	if (event->type() == QEvent::FocusOut)
	{
		if (object == ui.lineEdit_2)
		{
			ui.lineEdit_2->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_3)
		{
			ui.lineEdit_3->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_4)
		{
			ui.lineEdit_4->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_5)
		{
			ui.lineEdit_5->setStyleSheet("background-color: none");
		}
		if (object == ui.lineEdit_6)
		{
			ui.lineEdit_6->setStyleSheet("background-color: none");
		}
		if (object == ui.comboBox)
		{
			ui.comboBox->setStyleSheet("background-color: none");
		}
	}
	return false;
}

void QArtikliVnes::pressF9()
{
	on_pushButton_clicked();
}