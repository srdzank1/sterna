#include "qmyartikli.h"
#include "qpriemnicavnes.h"
#include "qpriemnicakorekcija.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qfakturikorekcija.h"
#include "qfakturivnes.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"
#include "qizjavavnes.h"
#include "qizjavakorekcija.h"
#include "qkalkulacijavnes.h"
#include "qkalkulacijakorekcija.h"
#include "qizleznifaktmastervnes.h"
#include "qizleznifaktmasterkorekcija.h"
#include "qprofakturimastervnes.h"
#include "qprofakturimasterkorekcija.h"
#include "qporackismetkivnes.h"
#include "qporackismetkikorekcija.h"



QMyArtikli::QMyArtikli(QWidget *parent)
	: QMyBaseWidget(parent)
	,artikliVnes(0)
	,artikliKorekcija(0)
	,artikliLista(0)
	,m_row(0)
{
	ui.setupUi(this);
	pressF4();
	artikliLista->setFocusSearchField();
}

QMyArtikli::~QMyArtikli()
{

}

void QMyArtikli::pressF2()
{
	if(!artikliLista )
	{
		return;
	}
	closeAllForm();
	artikliVnes = showMyWidget<QArtikliVnes>(artikliVnes); 
	connect(artikliVnes,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(artikliVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	artikliVnes->setInitValue(lastSearchStr);
}
void QMyArtikli::pressF3()
{
	if(!artikliLista )
	{
		return;
	}
	QString selText = artikliLista ? artikliLista->getSelectedText() : "";
	if (selText.isEmpty())
	{
		return;
	}
	closeAllForm();
	artikliKorekcija = showMyWidget<QArtikliKorekcija>(artikliKorekcija); 
	connect(artikliKorekcija,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(artikliKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	artikliKorekcija->showData(selText);
}
void QMyArtikli::pressF4()
{
	closeAllForm();
	artikliLista = showMyWidget<QMyArtikliLista>(artikliLista); 
	artikliLista->setSearchText(lastSearchStr);  
	artikliLista->setRow(m_row);
	connect(artikliLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
	connect(artikliLista,SIGNAL(sArtikalToPriemnica(QString&, QString&)),this,SLOT(retArtikliToPriemnica(QString&,QString&)));
    connect(artikliLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(artikliLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(artikliLista,SIGNAL(procDel()),this,SLOT(procDel()));
}
void QMyArtikli::procF2()
{
    pressF2();
}
void QMyArtikli::procF3()
{
    pressF3();
}
void QMyArtikli::procDel()
{

}
void QMyArtikli::pressEscape()
{
	this->raise();
	this->setFocus();
	emit signCloseMyWidget();	
}
void QMyArtikli::closeW()
{
	pressF4();
}
void QMyArtikli::closeWLista()
{
	pressEscape();
}

void QMyArtikli::closeAllForm()
{
	artikliKorekcija = deleteMyWidget<QArtikliKorekcija>(artikliKorekcija);
	artikliVnes = deleteMyWidget<QArtikliVnes>(artikliVnes);
	if (artikliLista)
	{
		m_row = artikliLista->getRow();
		lastSearchStr = artikliLista->getSearchStr();
	}
	artikliLista = deleteMyWidget<QMyArtikliLista>(artikliLista);
}

void QMyArtikli::succesfulEntryData()
{
	pressF4();
}

QStandardItemModel* QMyArtikli::getModel()
{
    QStandardItemModel * modelExt;
    if (artikliLista)
    {
        modelExt = artikliLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


void QMyArtikli::retArtikliToPriemnica(QString& text, QString& textName)
{
    QWidget *sour = getSourceWidget();
    if (qobject_cast<QPriemnicaVnes*>(sour))
    {
        QPriemnicaVnes *dest = qobject_cast<QPriemnicaVnes*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QPriemnicaKorekcija*>(sour))
    {
        QPriemnicaKorekcija *dest = qobject_cast<QPriemnicaKorekcija*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }

	if (qobject_cast<QIzleznifaktmasterVnes*>(sour))
	{
		QIzleznifaktmasterVnes *dest = qobject_cast<QIzleznifaktmasterVnes*>(sour);
		dest->setArtikli(text, textName, "");
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznifaktmasterKorekcija*>(sour))
	{
		QIzleznifaktmasterKorekcija *dest = qobject_cast<QIzleznifaktmasterKorekcija*>(sour);
		dest->setArtikli(text, textName, "");
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzlezniprofakturimasterVnes*>(sour))
	{
		QIzlezniprofakturimasterVnes *dest = qobject_cast<QIzlezniprofakturimasterVnes*>(sour);
		dest->setArtikli(text, textName, "");
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour))
	{
		QIzlezniprofakturimasterKorekcija *dest = qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour);
		dest->setArtikli(text, textName, "");
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
    {
        QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
        dest->setArtikli(text, textName, "");
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
    {
        QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
        dest->setArtikli(text, textName, "");
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QFakturiVlezniVnes*>(sour))
    {
        QFakturiVlezniVnes *dest = qobject_cast<QFakturiVlezniVnes*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QFakturiVlezniKorekcija*>(sour))
    {
        QFakturiVlezniKorekcija *dest = qobject_cast<QFakturiVlezniKorekcija*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QPovratnicaVnes*>(sour))
    {
        QPovratnicaVnes *dest = qobject_cast<QPovratnicaVnes*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QPovratnicaKorekcija*>(sour))
    {
        QPovratnicaKorekcija *dest = qobject_cast<QPovratnicaKorekcija*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QProFakturiVnes*>(sour))
    {
        QProFakturiVnes *dest = qobject_cast<QProFakturiVnes*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QProFakturiKorekcija*>(sour))
    {
        QProFakturiKorekcija *dest = qobject_cast<QProFakturiKorekcija*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QKasaVnes*>(sour))
    {
        QKasaVnes *dest = qobject_cast<QKasaVnes*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QKasaKorekcija*>(sour))
    {
        QKasaKorekcija *dest = qobject_cast<QKasaKorekcija*>(sour);
        dest->setArtikli(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
	if (qobject_cast<QIzjavaVnes*>(sour))
	{
		QIzjavaVnes *dest = qobject_cast<QIzjavaVnes*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzjavaKorekcija*>(sour))
	{
		QIzjavaKorekcija *dest = qobject_cast<QIzjavaKorekcija*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QKalkulacijaVnes*>(sour))
	{
		QKalkulacijaVnes *dest = qobject_cast<QKalkulacijaVnes*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QKalkulacijaKorekcija*>(sour))
	{
		QKalkulacijaKorekcija *dest = qobject_cast<QKalkulacijaKorekcija*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QPorackiSmetkiVnes*>(sour))
	{
		QPorackiSmetkiVnes *dest = qobject_cast<QPorackiSmetkiVnes*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QPorackiSmetkiKorekcija*>(sour))
	{
		QPorackiSmetkiKorekcija *dest = qobject_cast<QPorackiSmetkiKorekcija*>(sour);
		dest->setArtikli(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
}


void QMyArtikli::setInitSearchText(QString text)
{
	if (artikliLista)
	{
		artikliLista->setInitText(text);
	} 
}

void QMyArtikli::textChanged(const QString &text)
{
	if (artikliLista)
	{
		artikliLista->setInitText(text+"%");
	} 
}