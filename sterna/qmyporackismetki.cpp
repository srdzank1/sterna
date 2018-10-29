#include "qmyporackismetki.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMyPorackiSmetki::QMyPorackiSmetki(QWidget *parent)
: QMyBaseWidget(parent)
,PorackiSmetkiVnes(0)
,PorackiSmetkiKorekcija(0)
,PorackiSmetkiLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMyPorackiSmetki::~QMyPorackiSmetki()
{

}

void QMyPorackiSmetki::refresh()
{
}
void QMyPorackiSmetki::pressF2()
{
	closeAllForm();
	PorackiSmetkiVnes = showMyWidget<QPorackiSmetkiVnes>(PorackiSmetkiVnes); 
    PorackiSmetkiVnes->setCategoryWidget(this);
	connect(PorackiSmetkiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(PorackiSmetkiVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(PorackiSmetkiVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyPorackiSmetki::pressF3()
{
    if(!PorackiSmetkiLista )
    {
        return;
    }
    int id = PorackiSmetkiLista->getSelectedId();
	if (!PorackiSmetkiLista->m_statKorekcija)
	{
		//return;
	}
    closeAllForm();
    PorackiSmetkiKorekcija = showMyWidget<QPorackiSmetkiKorekcija>(PorackiSmetkiKorekcija); 
    PorackiSmetkiKorekcija->setCategoryWidget(this);
    connect(PorackiSmetkiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(PorackiSmetkiKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(PorackiSmetkiKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    PorackiSmetkiKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyPorackiSmetki::pressF4()
{
    closeAllForm();
    PorackiSmetkiLista = showMyWidget<QPorackiSmetkiLista>(PorackiSmetkiLista); 
    PorackiSmetkiLista->setCategoryWidget(this);
	PorackiSmetkiLista->setRow(m_row);
    connect(PorackiSmetkiLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(PorackiSmetkiLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(PorackiSmetkiLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(PorackiSmetkiLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(PorackiSmetkiLista, SIGNAL(sSmetkiToIzvod(QStringList&)), this, SLOT(retSmetkiToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMyPorackiSmetki::procF2()
{
    pressF2();
}
void QMyPorackiSmetki::procF3()
{
    pressF3();
}
void QMyPorackiSmetki::procDel()
{

}
void QMyPorackiSmetki::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyPorackiSmetki::closeW()
{
    pressF4();
}
void QMyPorackiSmetki::closeWLista()
{
    pressEscape();
}

void QMyPorackiSmetki::closeAllForm()
{
    PorackiSmetkiKorekcija = deleteMyWidget<QPorackiSmetkiKorekcija>(PorackiSmetkiKorekcija);
    PorackiSmetkiVnes = deleteMyWidget<QPorackiSmetkiVnes>(PorackiSmetkiVnes);
	if (PorackiSmetkiLista)
	{
		m_row = PorackiSmetkiLista->getRow();
	}
    PorackiSmetkiLista = deleteMyWidget<QPorackiSmetkiLista>(PorackiSmetkiLista);
}
void QMyPorackiSmetki::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyPorackiSmetki::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyPorackiSmetki::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyPorackiSmetki::getModel()
{
    QStandardItemModel * modelExt;
    if (PorackiSmetkiLista)
    {
        modelExt = PorackiSmetkiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMyPorackiSmetki::isCheckedDetailFaktura()
{
	bool stat = false;
	if (PorackiSmetkiLista)
	{
		stat = PorackiSmetkiLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMyPorackiSmetki::getModel2()
{
    QStandardItemModel * modelExt;
    if (PorackiSmetkiLista)
    {
        modelExt = PorackiSmetkiLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyPorackiSmetki::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (PorackiSmetkiLista)
    {
        modelExt = PorackiSmetkiLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyPorackiSmetki::retSmetkiToIzvod(QStringList& listData)
{
	QWidget *sour = getSourceWidget();
	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QPovratnicaVnes*>(sour))
	{
		QPovratnicaVnes *dest = qobject_cast<QPovratnicaVnes*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine3();
	}
	if (qobject_cast<QPovratnicaKorekcija*>(sour))
	{
		QPovratnicaKorekcija *dest = qobject_cast<QPovratnicaKorekcija*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine3();
	}

}

void QMyPorackiSmetki::setInitSearchText(QString text)
{
    if (PorackiSmetkiLista)
    {
        PorackiSmetkiLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMyPorackiSmetki::setInitSearchTextFaturi(QString text)
{
	if (PorackiSmetkiLista)
	{
		PorackiSmetkiLista->setInitTextSmetki(text, mmdate1, mmdate2);
	} 
}

void QMyPorackiSmetki::textChanged(const QString &text)
{
	mmText = text;
	if (PorackiSmetkiLista)
	{
		PorackiSmetkiLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyPorackiSmetki::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (PorackiSmetkiLista)
	{
		PorackiSmetkiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyPorackiSmetki::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (PorackiSmetkiLista)
	{
		PorackiSmetkiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

