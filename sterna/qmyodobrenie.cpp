#include "qmyOdobrenie.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"


QMyOdobrenie::QMyOdobrenie(QWidget *parent)
: QMyBaseWidget(parent)
,OdobrenieVnes(0)
,OdobrenieKorekcija(0)
,OdobrenieLista(0)
,m_row(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyOdobrenie::~QMyOdobrenie()
{

}

void QMyOdobrenie::refresh()
{
}
void QMyOdobrenie::pressF2()
{
	closeAllForm();
	OdobrenieVnes = showMyWidget<QOdobrenieVnes>(OdobrenieVnes); 
    OdobrenieVnes->setCategoryWidget(this);
	connect(OdobrenieVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(OdobrenieVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(OdobrenieVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyOdobrenie::pressF3()
{
    if(!OdobrenieLista)
    {
        return;
    }
    int id = OdobrenieLista->getSelectedId();
    closeAllForm();
    OdobrenieKorekcija = showMyWidget<QOdobrenieKorekcija>(OdobrenieKorekcija); 
    OdobrenieKorekcija->setCategoryWidget(this);
    connect(OdobrenieKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(OdobrenieKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(OdobrenieKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    OdobrenieKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyOdobrenie::pressF4()
{
    closeAllForm();
    OdobrenieLista = showMyWidget<QOdobrenieLista>(OdobrenieLista); 
    OdobrenieLista->setCategoryWidget(this);
	OdobrenieLista->setRow(m_row);
    connect(OdobrenieLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(OdobrenieLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(OdobrenieLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(OdobrenieLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(OdobrenieLista, SIGNAL(sOdobrenieToIzvod(QString&, QString&, QString&, QString&)), this, SLOT(retOdobrenieToIzvod(QString&, QString&, QString&, QString&)));
	emit disablePrint(false);

}
void QMyOdobrenie::procF2()
{
    pressF2();
}
void QMyOdobrenie::procF3()
{
    pressF3();
}
void QMyOdobrenie::procDel()
{

}
void QMyOdobrenie::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyOdobrenie::closeW()
{
    pressF4();
}
void QMyOdobrenie::closeWLista()
{
    pressEscape();
}

void QMyOdobrenie::closeAllForm()
{
    OdobrenieKorekcija = deleteMyWidget<QOdobrenieKorekcija>(OdobrenieKorekcija);
    OdobrenieVnes = deleteMyWidget<QOdobrenieVnes>(OdobrenieVnes);
	if (OdobrenieLista)
	{
		m_row = OdobrenieLista->getRow();
	}
    OdobrenieLista = deleteMyWidget<QOdobrenieLista>(OdobrenieLista);
}
void QMyOdobrenie::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyOdobrenie::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyOdobrenie::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyOdobrenie::getModel()
{
    QStandardItemModel * modelExt;
    if (OdobrenieLista)
    {
        modelExt = OdobrenieLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStandardItemModel* QMyOdobrenie::getModel2()
{
    QStandardItemModel * modelExt;
    if (OdobrenieLista)
    {
        modelExt = OdobrenieLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyOdobrenie::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (OdobrenieLista)
    {
        modelExt = OdobrenieLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyOdobrenie::retOdobrenieToIzvod(QString& text6, QString& text8, QString& text9, QString& textName)
{
	QWidget *sour = getSourceWidget();
	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
//		dest->setFakturi(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
//		dest->setFakturi(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
}

void QMyOdobrenie::setInitSearchText(QString text)
{
    if (OdobrenieLista)
    {
        OdobrenieLista->setInitText(text);
    } 
}

void QMyOdobrenie::textChanged(const QString &text)
{
	if (OdobrenieLista)
	{
		OdobrenieLista->lista(text+"%");
	} 
}