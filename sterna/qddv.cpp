#include "qddv.h"
#include "qpriemnicavnes.h"
#include "qpriemnicakorekcija.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qfakturivnes.h"
#include "qfakturikorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"



QMyDdv::QMyDdv(QWidget *parent)
	: QMyBaseWidget(parent)
	,ddvVnes(0)
	,ddvKorekcija(0)
	,ddvLista(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyDdv::~QMyDdv()
{

}

void QMyDdv::pressF2()
{
	closeAllForm();
	ddvVnes = showMyWidget<QDdvVnes>(ddvVnes); 
	connect(ddvVnes,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(ddvVnes,SIGNAL(closeW()),this,SLOT(closeW()));
}
void QMyDdv::pressF3()
{
	QString selText = ddvLista ? ddvLista->getSelectedText() : "";
	if (selText.isEmpty())
	{
		return;
	}
	closeAllForm();
	ddvKorekcija = showMyWidget<QDdvKorekcija>(ddvKorekcija); 
	connect(ddvKorekcija,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(ddvKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	ddvKorekcija->showData(selText);
}
void QMyDdv::pressF4()
{
	closeAllForm();
	ddvLista = showMyWidget<QDdvLista>(ddvLista);
	connect(ddvLista,SIGNAL(sKomintentToPriemnica(QString&, QString&)),this,SLOT(retKomintentToPriemnica(QString&, QString&)), Qt::DirectConnection);

	connect(ddvLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
}
void QMyDdv::closeW()
{
	pressF4();
}
void QMyDdv::closeWLista()
{
	pressEscape();
}

void QMyDdv::pressEscape()
{
	raise();
	setFocus();
	emit signCloseMyWidget();
}
void QMyDdv::closeAllForm()
{
	ddvKorekcija = deleteMyWidget<QDdvKorekcija>(ddvKorekcija);
	ddvVnes = deleteMyWidget<QDdvVnes>(ddvVnes);
	ddvLista = deleteMyWidget<QDdvLista>(ddvLista);
}

void QMyDdv::succesfulEntryData()
{
	pressF4();
}

void QMyDdv::retKomintentToPriemnica(QString& text, QString& textName)
{

	QWidget *sour = getSourceWidget();
	if (qobject_cast<QPriemnicaVnes*>(sour))
	{
		QPriemnicaVnes *dest = qobject_cast<QPriemnicaVnes*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QPriemnicaKorekcija*>(sour))
	{
		QPriemnicaKorekcija *dest = qobject_cast<QPriemnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}

	if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
	{
		QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
	{
		QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QFakturiVlezniVnes*>(sour))
	{
		QFakturiVlezniVnes *dest = qobject_cast<QFakturiVlezniVnes*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QFakturiVlezniKorekcija*>(sour))
	{
		QFakturiVlezniKorekcija *dest = qobject_cast<QFakturiVlezniKorekcija*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QPovratnicaVnes*>(sour))
	{
		QPovratnicaVnes *dest = qobject_cast<QPovratnicaVnes*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}
	if (qobject_cast<QPovratnicaKorekcija*>(sour))
	{
		QPovratnicaKorekcija *dest = qobject_cast<QPovratnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
		this->raise();
		this->setFocus();
		emit this->eCloseDdvFromPriemnica();
		dest->setFocusLine();
	}

    if (qobject_cast<QProFakturiVnes*>(sour))
    {
        QProFakturiVnes *dest = qobject_cast<QProFakturiVnes*>(sour);
        dest->setKomintent(text, textName);
        this->raise();
        this->setFocus();
        emit this->eCloseDdvFromPriemnica();
        dest->setFocusLine();
    }
    if (qobject_cast<QProFakturiKorekcija*>(sour))
    {
        QProFakturiKorekcija *dest = qobject_cast<QProFakturiKorekcija*>(sour);
        dest->setKomintent(text, textName);
        this->raise();
        this->setFocus();
        emit this->eCloseDdvFromPriemnica();
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaVnes*>(sour))
    {
        QKasaVnes *dest = qobject_cast<QKasaVnes*>(sour);
        dest->setKomintent(text, textName);
        this->raise();
        this->setFocus();
        emit this->eCloseDdvFromPriemnica();
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaKorekcija*>(sour))
    {
        QKasaKorekcija *dest = qobject_cast<QKasaKorekcija*>(sour);
        dest->setKomintent(text, textName);
        this->raise();
        this->setFocus();
        emit this->eCloseDdvFromPriemnica();
        dest->setFocusLine();
    }
}