#include "qDnevenpromet.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"

QDnevenpromet::QDnevenpromet(QWidget *parent)
	: QMyBaseWidget(parent)
    ,DnevenprometLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QDnevenpromet::~QDnevenpromet()
{

}

void QDnevenpromet::pressF4()
{
    closeAllForm();
    DnevenprometLista = showMyWidget<QDnevenprometWidget>(DnevenprometLista);
    connect(DnevenprometLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(DnevenprometLista, SIGNAL(sDnevenprometToDokument(QString&, QString&, QString&)), this, SLOT(callretDnevenprometToDokument(QString&,QString&, QString&)));
	emit disablePrint(false);
}
void QDnevenpromet::closeAllForm()
{
    DnevenprometLista = deleteMyWidget<QDnevenprometWidget>(DnevenprometLista);
}

void QDnevenpromet::closeWLista()
{
    pressEscape();
}

void QDnevenpromet::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}

void QDnevenpromet::refresh()
{
	pressF4();
}

void QDnevenpromet::callretDnevenprometToDokument(QString& text, QString& textName, QString& textNameSaldo )
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

void QDnevenpromet::setInitSearchText(QString text)
{
    if (DnevenprometLista)
    {
        DnevenprometLista->setInitText(text);
    } 
}

QStandardItemModel* QDnevenpromet::getModel()
{
	QStandardItemModel * modelExt;
	if (DnevenprometLista)
	{
		modelExt = DnevenprometLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}

QString QDnevenpromet::getDatum()
{
	QString str = "";
	if (DnevenprometLista)
	{
		str = DnevenprometLista->getDateAsString();
	}
	return str;
}

