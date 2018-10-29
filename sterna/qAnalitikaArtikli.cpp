#include "qAnalitikaArtikli.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"

QAnalitikaArtikli::QAnalitikaArtikli(QWidget *parent)
	: QMyBaseWidget(parent)
    ,AnalitikaArtikliLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QAnalitikaArtikli::~QAnalitikaArtikli()
{

}

void QAnalitikaArtikli::refresh()
{
	pressF4();
}

void QAnalitikaArtikli::pressF4()
{
    closeAllForm();
    AnalitikaArtikliLista = showMyWidget<QAnalitikaArtikliWidget>(AnalitikaArtikliLista);
    connect(AnalitikaArtikliLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(AnalitikaArtikliLista, SIGNAL(sAnalitikaArtikliToDokument(QString&, QString&, QString&)), this, SLOT(callretAnalitikaArtikliToDokument(QString&,QString&, QString&)));

}
void QAnalitikaArtikli::closeAllForm()
{
    AnalitikaArtikliLista = deleteMyWidget<QAnalitikaArtikliWidget>(AnalitikaArtikliLista);
}

void QAnalitikaArtikli::closeWLista()
{
    pressEscape();
}

void QAnalitikaArtikli::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QAnalitikaArtikli::callretAnalitikaArtikliToDokument(QString& text, QString& textName, QString& textNameSaldo )
{
    QWidget *sour = getSourceWidget();

    if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
    {
        QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
        dest->setArtikli(text, textName,"");
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

void QAnalitikaArtikli::setInitSearchText(QString text)
{
    if (AnalitikaArtikliLista)
    {
        AnalitikaArtikliLista->setInitText(text);
    } 
}

QStandardItemModel* QAnalitikaArtikli::getModel()
{
	QStandardItemModel * modelExt;
	if (AnalitikaArtikliLista)
	{
		modelExt = AnalitikaArtikliLista->model2;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}
QString QAnalitikaArtikli::getModelInfo()
{
    QString info = "";
    if (AnalitikaArtikliLista)
    {
        info = AnalitikaArtikliLista->getSelectedText2();
    } 

    return info;
}

QString QAnalitikaArtikli::getModelInfo2()
{
    QString info = "";
    if (AnalitikaArtikliLista)
    {
        info = AnalitikaArtikliLista->getSelectedText2();
    } 

    return info;
}

void QAnalitikaArtikli::textChanged(const QString &text)
{
	if (AnalitikaArtikliLista)
	{
		AnalitikaArtikliLista->lista(text);
	} 
}