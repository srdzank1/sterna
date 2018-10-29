#include "qEmployevnes.h"


QEmployeVnes::QEmployeVnes(QWidget *parent)
	: QMyBaseFormWidget(parent)
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
	CHelperClass chc(this);
	ui.lineEdit_8->setText(chc.getVrabotenNextID());

}

QEmployeVnes::~QEmployeVnes()
{

}

void QEmployeVnes::pressF9()
{
	on_pushButton_clicked();
}


void QEmployeVnes::on_pushButton_clicked()
{
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Записот ке биде внесен"));
	msgBox.setInformativeText(trUtf8("Дали сакате да ги сочувате промените"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok )
	{
		QSqlQuery query;
		query.prepare("insert into vraboteni(korisnicko_ime, pasword, ime, prezime, adresa, grad, tel, uloga, user_id) values (:a1, :a2, :a3, :a4, :a5, :a6, :a7,:a8, :a9)");
		
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
 		
		if (query.exec())
		{
			emit succesfulEntryData();
		}
	}
}
void QEmployeVnes::pressEscape()
{
	emit closeW();
}

void QEmployeVnes::pressReturn()
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


bool QEmployeVnes::eventFilter(QObject *object, QEvent *event)
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
