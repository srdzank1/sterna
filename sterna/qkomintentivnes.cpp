#include "qkomintentivnes.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "xx.h"

QKomintentiVnes::QKomintentiVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
{
	ui.setupUi(this);
	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

 	ui.lineEdit_14->setFocus();
	ui.lineEdit_14->setStyleSheet("background-color: yellow");
    ui.lineEdit->installEventFilter(this);
    ui.lineEdit_2->installEventFilter(this);
    ui.lineEdit_3->installEventFilter(this);
    ui.lineEdit_4->installEventFilter(this);
    ui.lineEdit_5->installEventFilter(this);
    ui.lineEdit_6->installEventFilter(this);
    ui.lineEdit_7->installEventFilter(this);
    ui.lineEdit_8->installEventFilter(this);
    ui.lineEdit_9->installEventFilter(this);
    ui.lineEdit_10->installEventFilter(this);
    ui.lineEdit_11->installEventFilter(this);
    ui.lineEdit_12->installEventFilter(this);
    ui.lineEdit_13->installEventFilter(this);
    ui.lineEdit_14->installEventFilter(this);
}

QKomintentiVnes::~QKomintentiVnes()
{

}

void QKomintentiVnes::setInitValue(QString text)
{
	ui.lineEdit_14->setText(text);
	ui.lineEdit_14->selectAll();
	ui.lineEdit->setText(text);
}


void QKomintentiVnes::pressF9()
{
	on_pushButton_clicked();
}


void QKomintentiVnes::on_pushButton_clicked()
{
	CHelperClass *chlp = new CHelperClass(this);
	if (ui.lineEdit_14->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси шифра на коминтентот!!!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_14->setFocus();
		return;
	}	

	if (chlp->isSifraKomintentExists(ui.lineEdit_14->text()))
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Постои коминтент со таа шифра!\nВнеси друга шифра"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_14->setFocus();
		return;
	}	

	if (ui.lineEdit->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси назив на коминтентот!!!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit->setFocus();
		return;
	}	


	QMessageBox msgBox;
	msgBox.setText(trUtf8("Записот ке биде внесен"));
	msgBox.setInformativeText(trUtf8("Дали сакате да ги сочувате промените"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("insert into komintenti(naziv, adresa, tel, mobil, zirosmetka, edb, deponent,sifdejnost, mb, zabeleska1, zabeleska2, rabat, grad, sifra, tip) values (:naziv, :adresa, :tel, :mobil, :zirosmetka, :edb, :deponent,:sifdejnost, :mb, :zabeleska1, :zabeleska2, :rabat, :grad, :sifra,:tip)");
		query.bindValue(":naziv", ui.lineEdit->text());
		query.bindValue(":adresa", ui.lineEdit_2->text());
		query.bindValue(":tel", ui.lineEdit_3->text());
		query.bindValue(":mobil", ui.lineEdit_4->text());
		query.bindValue(":zirosmetka", ui.lineEdit_5->text());
		query.bindValue(":edb", ui.lineEdit_6->text());
		query.bindValue(":deponent", ui.lineEdit_7->text());
		query.bindValue(":sifdejnost", ui.lineEdit_8->text());
		query.bindValue(":mb", ui.lineEdit_9->text());
		query.bindValue(":zabeleska1", ui.lineEdit_10->text());
		query.bindValue(":zabeleska2", ui.lineEdit_11->text());
		QString rabat = ui.lineEdit_12->text()!="" ? ui.lineEdit_12->text(): "0";
		query.bindValue(":rabat", rabat);
		query.bindValue(":grad", ui.lineEdit_13->text());
        query.bindValue(":sifra", ui.lineEdit_14->text());
        query.bindValue(":tip", 0);
 		if (query.exec())
		{
			emit succesfulEntryData();
		}
	}
}
void QKomintentiVnes::pressEscape()
{
	emit closeW();
}

void QKomintentiVnes::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.lineEdit_2->setFocus();
		ui.lineEdit_2->selectAll();
    }
    else if (ui.lineEdit_2->hasFocus())
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
        ui.lineEdit_7->setFocus();
		ui.lineEdit_7->selectAll();
    }
    else if (ui.lineEdit_7->hasFocus())
    {
        ui.lineEdit_8->setFocus();
		ui.lineEdit_8->selectAll();
    }
    else if (ui.lineEdit_8->hasFocus())
    {
        ui.lineEdit_9->setFocus();
		ui.lineEdit_9->selectAll();
    }
    else if (ui.lineEdit_9->hasFocus())
    {
        ui.lineEdit_10->setFocus();
		ui.lineEdit_10->selectAll();
    }
    else if (ui.lineEdit_10->hasFocus())
    {
        ui.lineEdit_11->setFocus();
		ui.lineEdit_11->selectAll();
    }
    else if (ui.lineEdit_11->hasFocus())
    {
        ui.lineEdit_12->setFocus();
		ui.lineEdit_12->selectAll();
    }
    else if (ui.lineEdit_12->hasFocus())
    {
        ui.lineEdit_13->setFocus();
		ui.lineEdit_13->selectAll();
    }
    else if (ui.lineEdit_13->hasFocus())
    {
        on_pushButton_clicked();
    }
    else if (ui.lineEdit_14->hasFocus())
    {
		ui.lineEdit->setFocus();
		ui.lineEdit->selectAll();
    }
}


bool QKomintentiVnes::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if (object == ui.lineEdit)
        {
            ui.lineEdit->setStyleSheet("background-color: yellow");
        }
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
        if (object == ui.lineEdit_7)
        {
            ui.lineEdit_7->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_8)
        {
            ui.lineEdit_8->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_9)
        {
            ui.lineEdit_9->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_10)
        {
            ui.lineEdit_10->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_11)
        {
            ui.lineEdit_11->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_12)
        {
            ui.lineEdit_12->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_13)
        {
            ui.lineEdit_13->setStyleSheet("background-color: yellow");
        }
        if (object == ui.lineEdit_14)
        {
            ui.lineEdit_14->setStyleSheet("background-color: yellow");
        }
    }
    if (event->type() == QEvent::FocusOut)
    {
        if (object == ui.lineEdit)
        {
            ui.lineEdit->setStyleSheet("background-color: none");
        }
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
        if (object == ui.lineEdit_7)
        {
            ui.lineEdit_7->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_8)
        {
            ui.lineEdit_8->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_9)
        {
            ui.lineEdit_9->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_10)
        {
            ui.lineEdit_10->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_11)
        {
            ui.lineEdit_11->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_12)
        {
            ui.lineEdit_12->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_13)
        {
            ui.lineEdit_13->setStyleSheet("background-color: none");
        }
        if (object == ui.lineEdit_14)
        {
            ui.lineEdit_14->setStyleSheet("background-color: none");
        }
    }
    return false;
}
