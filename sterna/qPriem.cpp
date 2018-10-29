#include "qPriem.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"

QPriem::QPriem(QWidget *parent)
	: QMyBaseWidget(parent)
    ,PriemLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QPriem::~QPriem()
{

}

void QPriem::refresh()
{
	pressF4();
}

void QPriem::pressF4()
{
    closeAllForm();
    PriemLista = showMyWidget<QPriemWidget>(PriemLista);
    connect(PriemLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(PriemLista, SIGNAL(sPriemToDokument(QString&, QString&, QString&)), this, SLOT(callretPriemToDokument(QString&,QString&, QString&)));

}
void QPriem::closeAllForm()
{
    PriemLista = deleteMyWidget<QPriemWidget>(PriemLista);
}

void QPriem::closeWLista()
{
    pressEscape();
}

void QPriem::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QPriem::callretPriemToDokument(QString& text, QString& textName, QString& textNameSaldo )
{
    QWidget *sour = getSourceWidget();

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
    if (qobject_cast<QIzlezniFakturiVnes*>(sour))
    {
        QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
        dest->setArtikli(text, textName, "");
        dest->setSaldo(textNameSaldo);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
    {
        QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
        dest->setArtikli(text, textName, "");
        dest->setSaldo(textNameSaldo);
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

void QPriem::setInitSearchText(QString text)
{
    if (PriemLista)
    {
        PriemLista->setInitText(text);
    } 
}

QStandardItemModel* QPriem::getModel()
{
	QStandardItemModel * modelExt;
	if (PriemLista)
	{
		modelExt = PriemLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}