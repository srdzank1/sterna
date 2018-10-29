#include "qPromenaCeni.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"

QPromenaCeni::QPromenaCeni(QWidget *parent)
	: QMyBaseWidget(parent)
    ,PromenaCeniLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QPromenaCeni::~QPromenaCeni()
{

}

void QPromenaCeni::refresh()
{
	pressF4();
}

void QPromenaCeni::pressF4()
{
    closeAllForm();
    PromenaCeniLista = showMyWidget<QPromenaCeniWidget>(PromenaCeniLista);
    connect(PromenaCeniLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(PromenaCeniLista, SIGNAL(sPromenaCeniToDokument(QString&, QString&, QString&, QString&, QString&)), this, SLOT(callretPromenaCeniToDokument(QString&, QString&, QString&, QString&, QString&)));
}

void QPromenaCeni::closeAllForm()
{
    PromenaCeniLista = deleteMyWidget<QPromenaCeniWidget>(PromenaCeniLista);
}

void QPromenaCeni::closeWLista()
{
    pressEscape();
}

void QPromenaCeni::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QPromenaCeni::callretPromenaCeniToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId,  QString& strProdCena )
{
    QWidget *sour = getSourceWidget();

    if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
    {
        QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
    {
        QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiVnes*>(sour))
    {
        QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
    {
        QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
        dest->setArtikli(text, textName, textKomintentId);
        dest->setSaldo(textNameSaldo);
		dest->setProdCena(strProdCena);
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

void QPromenaCeni::setInitSearchText(QString text)
{
    if (PromenaCeniLista)
    {
        PromenaCeniLista->setInitText(text);
    } 
}

void QPromenaCeni::textChanged(const QString &text)
{
	if (PromenaCeniLista)
	{
		PromenaCeniLista->lista(text+"%");
	} 
}

QStandardItemModel* QPromenaCeni::getModel()
{
	QStandardItemModel * modelExt;
	if (PromenaCeniLista)
	{
		modelExt = PromenaCeniLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}