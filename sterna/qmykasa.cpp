#include "qmyKasa.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"


QMyKasa::QMyKasa(QWidget *parent)
: QMyBaseWidget(parent)
,KasaVnes(0)
,KasaKorekcija(0)
,KasaLista(0)
,m_row(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyKasa::~QMyKasa()
{

}

void QMyKasa::refresh()
{
}
void QMyKasa::pressF2()
{
	closeAllForm();
	KasaVnes = showMyWidget<QKasaVnes>(KasaVnes); 
    KasaVnes->setCategoryWidget(this);
	connect(KasaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(KasaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(KasaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyKasa::pressF3()
{
    if(!KasaLista)
    {
        return;
    }
    int id = KasaLista->getSelectedId();
    closeAllForm();
    KasaKorekcija = showMyWidget<QKasaKorekcija>(KasaKorekcija); 
    KasaKorekcija->setCategoryWidget(this);
    connect(KasaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(KasaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(KasaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    KasaKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyKasa::pressF4()
{
    closeAllForm();
    KasaLista = showMyWidget<QKasaLista>(KasaLista); 
    KasaLista->setCategoryWidget(this);
	KasaLista->setRow(m_row);
    connect(KasaLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(KasaLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(KasaLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(KasaLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(KasaLista, SIGNAL(sKasaToIzvod(QString&, QString&, QString&, QString&)), this, SLOT(retKasaToIzvod(QString&, QString&, QString&, QString&)));
	emit disablePrint(false);

}
void QMyKasa::procF2()
{
    pressF2();
}
void QMyKasa::procF3()
{
    pressF3();
}
void QMyKasa::procDel()
{

}
void QMyKasa::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyKasa::closeW()
{
    pressF4();
}
void QMyKasa::closeWLista()
{
    pressEscape();
}

void QMyKasa::closeAllForm()
{
    KasaKorekcija = deleteMyWidget<QKasaKorekcija>(KasaKorekcija);
    KasaVnes = deleteMyWidget<QKasaVnes>(KasaVnes);
	if (KasaLista)
	{
		m_row = KasaLista->getRow();
	}
    KasaLista = deleteMyWidget<QKasaLista>(KasaLista);
}
void QMyKasa::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyKasa::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyKasa::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyKasa::getModel()
{
    QStandardItemModel * modelExt;
    if (KasaLista)
    {
        modelExt = KasaLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStandardItemModel* QMyKasa::getModel2()
{
    QStandardItemModel * modelExt;
    if (KasaLista)
    {
        modelExt = KasaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyKasa::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (KasaLista)
    {
        modelExt = KasaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyKasa::retKasaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName)
{
	QWidget *sour = getSourceWidget();
	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
//		dest->setKasa(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
//		dest->setKasa(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
}

void QMyKasa::setInitSearchText(QString text)
{
    if (KasaLista)
    {
        KasaLista->setInitText(text);
    } 
}