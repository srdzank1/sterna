#include "qPeriodicenIzvestaj.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"

QPeriodicenIzvestaj::QPeriodicenIzvestaj(QWidget *parent)
	: QMyBaseWidget(parent)
    ,PeriodicenIzvestajLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QPeriodicenIzvestaj::~QPeriodicenIzvestaj()
{

}

void QPeriodicenIzvestaj::refresh()
{
	pressF4();
}

void QPeriodicenIzvestaj::pressF4()
{
    closeAllForm();
    PeriodicenIzvestajLista = showMyWidget<QPeriodicenIzvestajWidget>(PeriodicenIzvestajLista);
    connect(PeriodicenIzvestajLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(PeriodicenIzvestajLista, SIGNAL(sPeriodicenIzvestajToDokument(QString&, QString&, QString&)), this, SLOT(callretPeriodicenIzvestajToDokument(QString&,QString&, QString&)));

}
void QPeriodicenIzvestaj::closeAllForm()
{
    PeriodicenIzvestajLista = deleteMyWidget<QPeriodicenIzvestajWidget>(PeriodicenIzvestajLista);
}

void QPeriodicenIzvestaj::closeWLista()
{
    pressEscape();
}

void QPeriodicenIzvestaj::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QPeriodicenIzvestaj::callretPeriodicenIzvestajToDokument(QString& text, QString& textName, QString& textNameSaldo )
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
        dest->setArtikli(text, textName,"");
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
        dest->setArtikli(text, textName,"");
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

void QPeriodicenIzvestaj::setInitSearchText(QString text)
{
    if (PeriodicenIzvestajLista)
    {
        PeriodicenIzvestajLista->setInitText(text);
    } 
}

void QPeriodicenIzvestaj::textChanged(const QString &text)
{
	if (PeriodicenIzvestajLista)
	{
		//PeriodicenIzvestajLista->lista(text+"%");
	} 
}

QStandardItemModel* QPeriodicenIzvestaj::getModel()
{
	QStandardItemModel * modelExt;
	if (PeriodicenIzvestajLista)
	{
		modelExt = PeriodicenIzvestajLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}

QString QPeriodicenIzvestaj::getDateRange()
{
	QString str = "";
	if (PeriodicenIzvestajLista)
	{
		str = PeriodicenIzvestajLista->getDateRange();
	}
	return str;
}