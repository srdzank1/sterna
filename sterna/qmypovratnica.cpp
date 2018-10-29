#include "qmyPovratnica.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"


QMyPovratnica::QMyPovratnica(QWidget *parent)
: QMyBaseWidget(parent)
,PovratnicaVnes(0)
,PovratnicaKorekcija(0)
,PovratnicaLista(0)
,m_row(0)
{
	ui.setupUi(this);
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	pressF4();
}

QMyPovratnica::~QMyPovratnica()
{

}

void QMyPovratnica::refresh()
{
}
void QMyPovratnica::pressF2()
{
	closeAllForm();
	PovratnicaVnes = showMyWidget<QPovratnicaVnes>(PovratnicaVnes); 
    PovratnicaVnes->setCategoryWidget(this);
	connect(PovratnicaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(PovratnicaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(PovratnicaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(PovratnicaVnes,SIGNAL(scallFakturi(QWidget*, QString)),this,SLOT(callFakturi(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyPovratnica::pressF3()
{
    if(!PovratnicaLista)
    {
        return;
    }
    int id = PovratnicaLista->getSelectedId();
    closeAllForm();
    PovratnicaKorekcija = showMyWidget<QPovratnicaKorekcija>(PovratnicaKorekcija); 
    PovratnicaKorekcija->setCategoryWidget(this);
    connect(PovratnicaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(PovratnicaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(PovratnicaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(PovratnicaKorekcija,SIGNAL(scallFakturi(QWidget*, QString)),this,SLOT(callFakturi(QWidget*, QString)));

	PovratnicaKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyPovratnica::pressF4()
{
    closeAllForm();
    PovratnicaLista = showMyWidget<QPovratnicaLista>(PovratnicaLista); 
    PovratnicaLista->setCategoryWidget(this);
	PovratnicaLista->setRow(m_row);
    connect(PovratnicaLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(PovratnicaLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(PovratnicaLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(PovratnicaLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(PovratnicaLista, SIGNAL(sPovratnicaToIzvod(QString&, QString&, QString&, QString&)), this, SLOT(retPovratnicaToIzvod(QString&, QString&, QString&, QString&)));
	emit disablePrint(false);

}
void QMyPovratnica::procF2()
{
    pressF2();
}
void QMyPovratnica::procF3()
{
    pressF3();
}
void QMyPovratnica::procDel()
{

}
void QMyPovratnica::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyPovratnica::closeW()
{
    pressF4();
}
void QMyPovratnica::closeWLista()
{
    pressEscape();
}

void QMyPovratnica::closeAllForm()
{
    PovratnicaKorekcija = deleteMyWidget<QPovratnicaKorekcija>(PovratnicaKorekcija);
    PovratnicaVnes = deleteMyWidget<QPovratnicaVnes>(PovratnicaVnes);
	if (PovratnicaLista)
	{
		m_row = PovratnicaLista->getRow();
	}
    PovratnicaLista = deleteMyWidget<QPovratnicaLista>(PovratnicaLista);
}
void QMyPovratnica::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyPovratnica::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyPovratnica::callFakturi(QWidget* myobj, QString text)
{
	emit signFakturiFromPovratnica(myobj, text);
}
void QMyPovratnica::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyPovratnica::getModel()
{
    QStandardItemModel * modelExt;
    if (PovratnicaLista)
    {
        modelExt = PovratnicaLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStandardItemModel* QMyPovratnica::getModel2()
{
    QStandardItemModel * modelExt;
    if (PovratnicaLista)
    {
        modelExt = PovratnicaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyPovratnica::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (PovratnicaLista)
    {
        modelExt = PovratnicaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyPovratnica::retPovratnicaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName)
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

void QMyPovratnica::setInitSearchText(QString text)
{
    if (PovratnicaLista)
    {
        PovratnicaLista->setInitText(text, mmdate1, mmdate2);
    } 
}



void QMyPovratnica::textChanged(const QString &text)
{
	mmText = text;
	if (PovratnicaLista)
	{
		PovratnicaLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyPovratnica::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (PovratnicaLista)
	{
		PovratnicaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyPovratnica::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (PovratnicaLista)
	{
		PovratnicaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

