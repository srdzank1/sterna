#include "qmyEmploye.h"
#include "qpriemnicavnes.h"
#include "qpriemnicakorekcija.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"
#include "qfakturivnes.h"
#include "qfakturikorekcija.h"
#include "qizjavavnes.h"
#include "qizjavakorekcija.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"


QMyEmploye::QMyEmploye(QWidget *parent)
	: QMyBaseWidget(parent)
	,EmployeVnes(0)
	,EmployeKorekcija(0)
	,EmployeLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QMyEmploye::~QMyEmploye()
{

}

void QMyEmploye::pressF2()
{
	closeAllForm();
	EmployeVnes = showMyWidget<QEmployeVnes>(EmployeVnes); 
	connect(EmployeVnes,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(EmployeVnes,SIGNAL(closeW()),this,SLOT(closeW()));
}
void QMyEmploye::pressF3()
{
	QString selText = EmployeLista ? EmployeLista->getSelectedText() : "";
	if (selText.isEmpty())
	{
		return;
	}
	closeAllForm();
	EmployeKorekcija = showMyWidget<QEmployeKorekcija>(EmployeKorekcija); 
	connect(EmployeKorekcija,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(EmployeKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	EmployeKorekcija->showData(selText);
}
void QMyEmploye::pressF4()
{
    closeAllForm();
	EmployeLista = showMyWidget<QEmployeLista>(EmployeLista);
	connect(EmployeLista,SIGNAL(sKomintentToPriemnica(QString&, QString&)),this,SLOT(retKomintentToPriemnica(QString&, QString&)), Qt::DirectConnection);
	connect(EmployeLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(EmployeLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(EmployeLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(EmployeLista,SIGNAL(procDel()),this,SLOT(procDel()));
}

void QMyEmploye::procF2()
{
    pressF2();
}
void QMyEmploye::procF3()
{
    pressF3();
}
void QMyEmploye::procDel()
{

}

void QMyEmploye::closeW()
{
	pressF4();
}
void QMyEmploye::closeWLista()
{
	pressEscape();
}

void QMyEmploye::pressEscape()
{
	raise();
	setFocus();
	emit signCloseMyWidget();
}
void QMyEmploye::closeAllForm()
{
    EmployeKorekcija = deleteMyWidget<QEmployeKorekcija>(EmployeKorekcija);
    EmployeVnes = deleteMyWidget<QEmployeVnes>(EmployeVnes);
    EmployeLista = deleteMyWidget<QEmployeLista>(EmployeLista);
}

void QMyEmploye::succesfulEntryData()
{
	pressF4();
}

void QMyEmploye::retKomintentToPriemnica(QString& text, QString& textName)
{

	QWidget *sour = getSourceWidget();

	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QPriemnicaVnes*>(sour))
	{
		QPriemnicaVnes *dest = qobject_cast<QPriemnicaVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QPriemnicaKorekcija*>(sour))
	{
		QPriemnicaKorekcija *dest = qobject_cast<QPriemnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

	if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
	{
		QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
    }
	if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
	{
		QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QFakturiVlezniVnes*>(sour))
    {
        QFakturiVlezniVnes *dest = qobject_cast<QFakturiVlezniVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QFakturiVlezniKorekcija*>(sour))
    {
        QFakturiVlezniKorekcija *dest = qobject_cast<QFakturiVlezniKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();

    }
	if (qobject_cast<QIzlezniFakturiVnes*>(sour))
	{
		QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
	{
		QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QPovratnicaVnes*>(sour))
	{
		QPovratnicaVnes *dest = qobject_cast<QPovratnicaVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QPovratnicaKorekcija*>(sour))
	{
		QPovratnicaKorekcija *dest = qobject_cast<QPovratnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

    if (qobject_cast<QProFakturiVnes*>(sour))
    {
        QProFakturiVnes *dest = qobject_cast<QProFakturiVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QProFakturiKorekcija*>(sour))
    {
        QProFakturiKorekcija *dest = qobject_cast<QProFakturiKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaVnes*>(sour))
    {
        QKasaVnes *dest = qobject_cast<QKasaVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaKorekcija*>(sour))
    {
        QKasaKorekcija *dest = qobject_cast<QKasaKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

	if (qobject_cast<QIzjavaVnes*>(sour))
	{
		QIzjavaVnes *dest = qobject_cast<QIzjavaVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QIzjavaKorekcija*>(sour))
	{
		QIzjavaKorekcija *dest = qobject_cast<QIzjavaKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}

}

QStandardItemModel* QMyEmploye::getModel()
{
    QStandardItemModel * modelExt;
    if (EmployeLista)
    {
        modelExt = EmployeLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


void QMyEmploye::setInitSearchText(QString text)
{
	if (EmployeLista)
	{
		EmployeLista->setInitText(text);
	} 
}

void QMyEmploye::textChanged(const QString &text)
{
	if (EmployeLista)
	{
		EmployeLista->setInitText(text+"%");
	} 
}