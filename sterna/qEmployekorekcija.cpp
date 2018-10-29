#include "qEmployekorekcija.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>

QEmployeKorekcija::QEmployeKorekcija(QWidget *parent)
	: QMyBaseFormWidget(parent)
,m_id(0)
{
	ui.setupUi(this);
	QDesktopWidget desk;
	QRect deskRect = desk.screenGeometry();
	ui.layoutWidget->setFixedWidth(deskRect.width() - 250);
	ui.layoutWidget->setFixedHeight(deskRect.height()-200);
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
}

QEmployeKorekcija::~QEmployeKorekcija()
{

}

void QEmployeKorekcija::pressF9()
{
	on_pushButton_clicked();
}

void QEmployeKorekcija::showData(const QString& id)
{
	QSqlQuery query;
	query.prepare("select * from vraboteni where id = :a");
	query.bindValue(":a", id);
	query.exec();
	query.next();

	m_id = query.value(0).toInt();
	ui.lineEdit_14->setText(query.value(1).toString());
	//ui.lineEdit->setText(query.value(2).toString());
	ui.lineEdit_2->setText(query.value(3).toString());
	ui.lineEdit_3->setText(query.value(4).toString());	
	ui.lineEdit_4->setText(query.value(5).toString());
	ui.lineEdit_5->setText(query.value(6).toString());
	ui.lineEdit_6->setText(query.value(7).toString());
	ui.lineEdit_7->setText(query.value(8).toString());
	ui.lineEdit_8->setText(query.value(9).toString());
}


void QEmployeKorekcija::on_pushButton_clicked()
{
	if(ui.lineEdit->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(trUtf8("Внеси лозинка!!!"));
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
		query.prepare("update vraboteni set korisnicko_ime=:a1, pasword =:a2, ime =:a3, prezime =:a4, adresa =:a5, grad =:a6, tel =:a7, uloga =:a8, user_id =:a9 where id=:id");
		query.bindValue(":id", m_id);
		query.bindValue(":a1", ui.lineEdit_14->text());

		QString str = ui.lineEdit->text();
		QByteArray hash = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
		QString str_pass = QString(hash.toHex());

		query.bindValue(":a2", str_pass);

		query.bindValue(":a3", ui.lineEdit_2->text());
		query.bindValue(":a4", ui.lineEdit_3->text());
		query.bindValue(":a5", ui.lineEdit_4->text());
		query.bindValue(":a6", ui.lineEdit_5->text());
		query.bindValue(":a7", ui.lineEdit_6->text());
		query.bindValue(":a8", ui.lineEdit_7->text());
		query.bindValue(":a9", ui.lineEdit_8->text());

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

void QEmployeKorekcija::pressEscape()
{
	emit closeW();
}

void QEmployeKorekcija::pressReturn()
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
		on_pushButton_clicked();
    }
}

bool QEmployeKorekcija::eventFilter(QObject *object, QEvent *event)
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
    }
    return false;
}
