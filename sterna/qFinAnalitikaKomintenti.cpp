#include "qFinAnalitikaKomintenti.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"


QFinAnalitKomintenti::QFinAnalitKomintenti(QWidget *parent)
	: QMyBaseWidget(parent)
    ,FinAnalitKomintentiLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QFinAnalitKomintenti::~QFinAnalitKomintenti()
{

}

void QFinAnalitKomintenti::refresh()
{
	pressF4();
}

void QFinAnalitKomintenti::pressF4()
{
    closeAllForm();
    FinAnalitKomintentiLista = showMyWidget<QFinAnalitKomintentiWidget>(FinAnalitKomintentiLista);
    connect(FinAnalitKomintentiLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(FinAnalitKomintentiLista, SIGNAL(sFinAnalitKomintentiToDokument(QString&, QString&, QString&)), this, SLOT(callretFinAnalitKomintentiToDokument(QString&,QString&, QString&)));

}
void QFinAnalitKomintenti::closeAllForm()
{
    FinAnalitKomintentiLista = deleteMyWidget<QFinAnalitKomintentiWidget>(FinAnalitKomintentiLista);
}

void QFinAnalitKomintenti::closeWLista()
{
    pressEscape();
}

void QFinAnalitKomintenti::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}


void QFinAnalitKomintenti::callretFinAnalitKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo )
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

void QFinAnalitKomintenti::setInitSearchText(QString text)
{
    if (FinAnalitKomintentiLista)
    {
        FinAnalitKomintentiLista->setInitText(text);
    } 
}

void QFinAnalitKomintenti::textChanged(const QString &text)
{
	if (FinAnalitKomintentiLista)
	{
		FinAnalitKomintentiLista->lista(text+"%");
	} 
}

QStandardItemModel* QFinAnalitKomintenti::getModel()
{
	QStandardItemModel * modelExt;
	if (FinAnalitKomintentiLista)
	{
		modelExt = FinAnalitKomintentiLista->model2;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}

QString QFinAnalitKomintenti::getModelInfo()
{
	QString info = "";
	if (FinAnalitKomintentiLista)
	{
		info = FinAnalitKomintentiLista->getSelectedText();
	} 
	return info;
}