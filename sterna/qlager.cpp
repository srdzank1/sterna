#include "qlager.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"
#include "qizleznismetkivnes.h"
#include "qizleznismetkikorekcija.h"
#include "qizleznifaktmastervnes.h"
#include "qizleznifaktmasterkorekcija.h"
#include "qprofakturimastervnes.h"
#include "qprofakturimasterkorekcija.h"
#include "qizleznipovratnicamastervnes.h"
#include "qizleznipovratnicamasterkorekcija.h"

QLager::QLager(QWidget *parent)
	: QMyBaseWidget(parent)
    ,lagerLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QLager::~QLager()
{

}

void QLager::refresh()
{
	pressF4();
}

void QLager::pressF4()
{
    closeAllForm();
    lagerLista = showMyWidget<QLagerWidget>(lagerLista);
    connect(lagerLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(lagerLista, SIGNAL(sLagerToDokument(QString&, QString&, QString&, QString&, QString&, QString&)), this, SLOT(callretLagerToDokument(QString&, QString&, QString&, QString&, QString&, QString&)));
}

void QLager::closeAllForm()
{
    lagerLista = deleteMyWidget<QLagerWidget>(lagerLista);
}

void QLager::closeWLista()
{
    pressEscape();
}

void QLager::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QLager::callretLagerToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId,  QString& strProdCena, QString& strNabCena )
{
    QWidget *sour = getSourceWidget();

	if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
	{
		QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
	{
		QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzleznipovratnicamasterVnes*>(sour))
	{
		QIzleznipovratnicamasterVnes *dest = qobject_cast<QIzleznipovratnicamasterVnes*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznipovratnicamasterKorekcija*>(sour))
	{
		QIzleznipovratnicamasterKorekcija *dest = qobject_cast<QIzleznipovratnicamasterKorekcija*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}


	if (qobject_cast<QIzlezniSmetkiVnes*>(sour))
	{
		QIzlezniSmetkiVnes *dest = qobject_cast<QIzlezniSmetkiVnes*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzlezniSmetkiKorekcija*>(sour))
	{
		QIzlezniSmetkiKorekcija *dest = qobject_cast<QIzlezniSmetkiKorekcija*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzlezniprofakturimasterVnes*>(sour))
	{
		QIzlezniprofakturimasterVnes *dest = qobject_cast<QIzlezniprofakturimasterVnes*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour))
	{
		QIzlezniprofakturimasterKorekcija *dest = qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzleznifaktmasterVnes*>(sour))
	{
		QIzleznifaktmasterVnes *dest = qobject_cast<QIzleznifaktmasterVnes*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznifaktmasterKorekcija*>(sour))
	{
		QIzleznifaktmasterKorekcija *dest = qobject_cast<QIzleznifaktmasterKorekcija*>(sour);
		dest->setArtikli(text, textName, textKomintentId);
		dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

    if (qobject_cast<QIzlezniFakturiVnes*>(sour))
    {
        QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
    {
        QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		dest->setNabCena(strNabCena);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
	if (qobject_cast<QKasaVnes*>(sour))
	{
		QKasaVnes *dest = qobject_cast<QKasaVnes*>(sour);
		dest->setArtikli(text, textName);
		dest->setSaldo(textNameSaldo);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QKasaKorekcija*>(sour))
	{
		QKasaKorekcija *dest = qobject_cast<QKasaKorekcija*>(sour);
		dest->setArtikli(text, textName);
		dest->setSaldo(textNameSaldo);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

}

void QLager::setInitSearchText(QString text)
{
    if (lagerLista)
    {
        lagerLista->setInitText(text);
    } 
}

void QLager::textChanged(const QString &text)
{
	if (lagerLista)
	{
		lagerLista->lista(text+"%");
	} 
}

QStandardItemModel* QLager::getModel()
{
	QStandardItemModel * modelExt;
	if (lagerLista)
	{
		modelExt = lagerLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}

void QLager::refreshLista()
{
	if (lagerLista)
	{
		lagerLista->refresh();
	} 
}