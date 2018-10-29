#include "qbanki.h"

#include "qizvodvnes.h"
#include "qizvodlista.h"
#include "qizvodkorekcija.h"

QMyBanki::QMyBanki(QWidget *parent)
	: QMyBaseWidget(parent)
	,bankiVnes(0)
	,bankiKorekcija(0)
	,bankiLista(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyBanki::~QMyBanki()
{

}

void QMyBanki::pressF2()
{
	closeAllForm();
	bankiVnes = showMyWidget<QBankiVnes>(bankiVnes); 
	connect(bankiVnes,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(bankiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
}
void QMyBanki::pressF3()
{
	QString selText = bankiLista ? bankiLista->getSelectedText() : "";
	if (selText.isEmpty())
	{
		return;
	}
	closeAllForm();
	bankiKorekcija = showMyWidget<QBankiKorekcija>(bankiKorekcija); 
	connect(bankiKorekcija,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(bankiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	bankiKorekcija->showData(selText);
}
void QMyBanki::pressF4()
{
	closeAllForm();
	bankiLista = showMyWidget<QBankiLista>(bankiLista);
	connect(bankiLista,SIGNAL(sKomintentToPriemnica(QString&, QString&)),this,SLOT(retKomintentToPriemnica(QString&, QString&)), Qt::DirectConnection);
    connect(bankiLista,SIGNAL(sBankiToIzvod(QString&, QString&)),this,SLOT(retBankiToIzvod(QString&,QString&)));
	connect(bankiLista, SIGNAL(procF2()), this, SLOT(procF2()));
	connect(bankiLista, SIGNAL(procF3()), this, SLOT(procF3()));
	connect(bankiLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
}
void QMyBanki::closeW()
{
	pressF4();
}
void QMyBanki::closeWLista()
{
	pressEscape();
}

void QMyBanki::procF2()
{
	pressF2();
}
void QMyBanki::procF3()
{
	pressF3();
}


void QMyBanki::pressEscape()
{
	raise();
	setFocus();
	emit signCloseMyWidget();
}
void QMyBanki::closeAllForm()
{
	bankiKorekcija = deleteMyWidget<QBankiKorekcija>(bankiKorekcija);
	bankiVnes = deleteMyWidget<QBankiVnes>(bankiVnes);
	bankiLista = deleteMyWidget<QBankiLista>(bankiLista);
}

void QMyBanki::succesfulEntryData()
{
	pressF4();
}

void QMyBanki::retBankiToIzvod(QString& text, QString& textName)
{
	QWidget *sour = getSourceWidget();
	if (qobject_cast<QIzvodLista*>(sour))
	{
		QIzvodLista *dest = qobject_cast<QIzvodLista*>(sour);
		dest->setZiroSmetka(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
		dest->setZiroSmetka(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
    if (qobject_cast<QIzvodKorekcija*>(sour))
    {
        QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
        dest->setZiroSmetka(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

}

QStandardItemModel* QMyBanki::getModel()
{
    QStandardItemModel * modelExt;
    if (bankiLista)
    {
        modelExt = bankiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

void QMyBanki::setInitSearchText(QString text)
{
    if (bankiLista)
    {
        bankiLista->setInitText(text);
    } 
}