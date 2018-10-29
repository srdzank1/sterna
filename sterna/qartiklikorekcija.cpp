#include "qartiklikorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "chelperclass.h"
#include "xx.h"

QArtikliKorekcija::QArtikliKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,m_id(0)
{
	ui.setupUi(this);

	Singleton *s = Singleton::Instance();
	QRect rMain = s->getMainRect();
	ui.gridLayout->setGeometry(rMain);
	setLayout(ui.gridLayout);
	setFixedSize(QSize(rMain.width()-20, rMain.height()-65));

// 	ui.lineEdit_2->setFocus();
// 	ui.lineEdit_2->setStyleSheet("background-color: yellow");
	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_3->installEventFilter(this);
	ui.lineEdit_4->installEventFilter(this);
	ui.lineEdit_5->installEventFilter(this);
	ui.lineEdit_6->installEventFilter(this);
	ui.comboBox->installEventFilter(this);
}

void QArtikliKorekcija::pressF9()
{
	on_pushButton_clicked();
}



QArtikliKorekcija::~QArtikliKorekcija()
{

}
void QArtikliKorekcija::showData(const QString& id)
{
	QSqlQuery query;
	query.prepare("select * from artikli where id = :a");
	query.bindValue(":a", id);
	query.exec();
	query.next();
	m_id = query.value(0).toInt();
	ui.lineEdit_2->setText(query.value(1).toString());
	ui.lineEdit_3->setText(query.value(2).toString());
	ui.lineEdit_4->setText(query.value(3).toString());
	ui.lineEdit_5->setText(query.value(4).toString());	
	ui.lineEdit_6->setText(query.value(5).toString());
    int index1 = ui.comboBox->findText(query.value(10).toString());
	if (index1 != -1) 
	{ 
		ui.comboBox->setCurrentIndex(index1);
	}
	m_initSifraArtikal = ui.lineEdit_2->text();
	ui.lineEdit_3->setFocus();
}


void QArtikliKorekcija::on_pushButton_clicked()
{
	CHelperClass *chlp = new CHelperClass(this);
	if (ui.lineEdit_2->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси име на артикалот!!!"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
		ui.lineEdit_2->setFocus();
		return;
	}	
	if(	m_initSifraArtikal != ui.lineEdit_2->text())
	{
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
	msgBox.setText(trUtf8("Документот ке биде изменет."));
	msgBox.setInformativeText(trUtf8("Дали сакате да ги сочувате промените?"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("update artikli set sifra=:sifra, "
			"artikal =:artikal, "
			"edm =:edm, "
			"ref =:ref, "
			"kataloski_broj=:kb ,"
			"art_nabavna_cena=:anc, "
			"art_nabavna_cena_valuta=:ancv, "
			"art_prodazna_cena=:apc, "
			"art_prodazna_cena_valuta=:apcv, "
            "ddv=:iddv "
            "where id=:id");
		query.bindValue(":id", m_id);
		query.bindValue(":sifra",ui.lineEdit_2->text());
		query.bindValue(":artikal",ui.lineEdit_3->text());
		query.bindValue(":edm",ui.lineEdit_4->text());
		query.bindValue(":ref",ui.lineEdit_5->text());
		query.bindValue(":kb",ui.lineEdit_6->text());
		query.bindValue(":anc","0");
		query.bindValue(":ancv","0");
		query.bindValue(":apc","0");
		query.bindValue(":apcv","0");
        query.bindValue(":iddv",ui.comboBox->currentText());
        if(query.exec())
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Трансакцијата е успешна"));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			emit succesfulEntryData();
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(trUtf8("Трансакцијата ne е успешна"));
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
		}
	}
}

void QArtikliKorekcija::pressEscape()
{
	emit closeW();
}

void QArtikliKorekcija::pressReturn()
{
	if (ui.lineEdit_2->hasFocus())
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
		ui.comboBox->setFocus();	
	}
	else if (ui.comboBox->hasFocus())
	{
		on_pushButton_clicked();
	}
}

bool QArtikliKorekcija::eventFilter(QObject *object, QEvent *event)
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
