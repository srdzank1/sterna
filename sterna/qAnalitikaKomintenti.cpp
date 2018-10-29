#include "qAnalitikaKomintenti.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"


QAnalitikaKomintenti::QAnalitikaKomintenti(QWidget *parent)
	: QMyBaseWidget(parent)
    ,AnalitikaKomintentiLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QAnalitikaKomintenti::~QAnalitikaKomintenti()
{

}

void QAnalitikaKomintenti::refresh()
{
	pressF4();
}

void QAnalitikaKomintenti::pressF4()
{
    closeAllForm();
    AnalitikaKomintentiLista = showMyWidget<QAnalitikaKomintentiWidget>(AnalitikaKomintentiLista);
    connect(AnalitikaKomintentiLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(AnalitikaKomintentiLista, SIGNAL(sAnalitikaKomintentiToDokument(QString&, QString&, QString&)), this, SLOT(callretAnalitikaKomintentiToDokument(QString&,QString&, QString&)));

}
void QAnalitikaKomintenti::closeAllForm()
{
    AnalitikaKomintentiLista = deleteMyWidget<QAnalitikaKomintentiWidget>(AnalitikaKomintentiLista);
}

void QAnalitikaKomintenti::closeWLista()
{
    pressEscape();
}

void QAnalitikaKomintenti::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QAnalitikaKomintenti::callretAnalitikaKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo )
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
}

void QAnalitikaKomintenti::setInitSearchText(QString text)
{
    if (AnalitikaKomintentiLista)
    {
        AnalitikaKomintentiLista->setInitText(text);
    } 
}

void QAnalitikaKomintenti::textChanged(const QString &text)
{
	if (AnalitikaKomintentiLista)
	{
		AnalitikaKomintentiLista->lista(text+"%");
	} 
}

QStandardItemModel* QAnalitikaKomintenti::getModel()
{
	QStandardItemModel * modelExt;
	if (AnalitikaKomintentiLista)
	{
		modelExt = AnalitikaKomintentiLista->model2;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}

QString QAnalitikaKomintenti::getModelInfo()
{
	QString info = "";
	if (AnalitikaKomintentiLista)
	{
		info = AnalitikaKomintentiLista->getSelectedText();
	} 
	return info;
}