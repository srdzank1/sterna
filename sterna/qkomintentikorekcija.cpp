#include "qkomintentikorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "chelperclass.h"
#include "xx.h"



QKomintentiKorekcija::QKomintentiKorekcija(QWidget *parent)
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
    ui.lineEdit->setStyleSheet("background-color: yellow");
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

QKomintentiKorekcija::~QKomintentiKorekcija()
{

}

void QKomintentiKorekcija::pressF9()
{
	on_pushButton_clicked();
}

void QKomintentiKorekcija::showData(const QString& id)
{
	QSqlQuery query;
	query.prepare("select * from komintenti where id = :a");
	query.bindValue(":a", id);
	query.exec();
	query.next();

	m_id = query.value(0).toInt();
	ui.lineEdit->setText(query.value(1).toString());
	ui.lineEdit_2->setText(query.value(2).toString());
	ui.lineEdit_3->setText(query.value(3).toString());
	ui.lineEdit_4->setText(query.value(4).toString());	
	ui.lineEdit_5->setText(query.value(5).toString());
	ui.lineEdit_6->setText(query.value(6).toString());
	ui.lineEdit_7->setText(query.value(7).toString());
	ui.lineEdit_8->setText(query.value(8).toString());
	ui.lineEdit_9->setText(query.value(9).toString());	
	ui.lineEdit_10->setText(query.value(10).toString());
	ui.lineEdit_11->setText(query.value(11).toString());
	ui.lineEdit_12->setText(query.value(12).toString());
	ui.lineEdit_13->setText(query.value(13).toString());
	ui.lineEdit_14->setText(query.value(14).toString());
	m_initSifraKomintent = ui.lineEdit_14->text();
}



void QKomintentiKorekcija::on_pushButton_clicked()
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
		if(	m_initSifraKomintent != ui.lineEdit_14->text())
		{
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
	msgBox.setText(trUtf8("Записот ке биде променет"));
	msgBox.setInformativeText(trUtf8("Дали сакате да ги сочувате промените?"));
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Save )
	{
		QSqlQuery query;
		query.prepare("update komintenti set naziv=:naziv, adresa =:adresa, tel =:tel, mobil =:mobil, zirosmetka =:zirosmetka, edb =:edb, deponent =:deponent, sifdejnost =:sifdejnost, mb =:mb, zabeleska1 =:zabeleska1, zabeleska2 =:zabeleska2, rabat =:rabat, grad =:grad, sifra =:sifra where id=:id");
		query.bindValue(":id", m_id);
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
		query.bindValue(":rabat", ui.lineEdit_12->text());
		query.bindValue(":grad", ui.lineEdit_13->text());
        query.bindValue(":sifra", ui.lineEdit_14->text());

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

void QKomintentiKorekcija::pressEscape()
{
	emit closeW();
}

void QKomintentiKorekcija::pressReturn()
{
    if (ui.lineEdit->hasFocus())
    {
        ui.lineEdit_2->setFocus();
    }
    else if (ui.lineEdit_2->hasFocus())
    {
        ui.lineEdit_3->setFocus();
    }
    else if (ui.lineEdit_3->hasFocus())
    {
        ui.lineEdit_4->setFocus();
    }
    else if (ui.lineEdit_4->hasFocus())
    {
        ui.lineEdit_5->setFocus();
    }
    else if (ui.lineEdit_5->hasFocus())
    {
        ui.lineEdit_6->setFocus();
    }
    else if (ui.lineEdit_6->hasFocus())
    {
        ui.lineEdit_7->setFocus();
    }
    else if (ui.lineEdit_7->hasFocus())
    {
        ui.lineEdit_8->setFocus();
    }
    else if (ui.lineEdit_8->hasFocus())
    {
        ui.lineEdit_9->setFocus();
    }
    else if (ui.lineEdit_9->hasFocus())
    {
        ui.lineEdit_10->setFocus();
    }
    else if (ui.lineEdit_10->hasFocus())
    {
        ui.lineEdit_11->setFocus();
    }
    else if (ui.lineEdit_11->hasFocus())
    {
        ui.lineEdit_12->setFocus();
    }
    else if (ui.lineEdit_12->hasFocus())
    {
        ui.lineEdit_13->setFocus();
    }
    else if (ui.lineEdit_13->hasFocus())
    {
        on_pushButton_clicked();
    }
    else if (ui.lineEdit_14->hasFocus())
    {
        ui.lineEdit->setFocus();
    }
}

bool QKomintentiKorekcija::eventFilter(QObject *object, QEvent *event)
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
