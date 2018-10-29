#include "qmySmetki.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMySmetki::QMySmetki(QWidget *parent)
: QMyBaseWidget(parent)
,SmetkiVnes(0)
,SmetkiKorekcija(0)
,SmetkiLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMySmetki::~QMySmetki()
{

}

void QMySmetki::refresh()
{
}
void QMySmetki::pressF2()
{
	if(!SmetkiLista )
	{
		return;
	}
	closeAllForm();
	SmetkiVnes = showMyWidget<QIzlezniSmetkiVnes>(SmetkiVnes); 
    SmetkiVnes->setCategoryWidget(this);
	connect(SmetkiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(SmetkiVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(SmetkiVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);

}
void QMySmetki::pressF3()
{
    if(!SmetkiLista )
    {
        return;
    }
    int id = SmetkiLista->getSelectedId();
	if (!SmetkiLista->m_statKorekcija)
	{
		return;
	}
    closeAllForm();
    SmetkiKorekcija = showMyWidget<QIzlezniSmetkiKorekcija>(SmetkiKorekcija); 
    SmetkiKorekcija->setCategoryWidget(this);
    connect(SmetkiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(SmetkiKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(SmetkiKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    SmetkiKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMySmetki::pressF4()
{
    closeAllForm();
    SmetkiLista = showMyWidget<QIzlezniSmetkiLista>(SmetkiLista); 
    SmetkiLista->setCategoryWidget(this);
	SmetkiLista->setRow(m_row);
    connect(SmetkiLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(SmetkiLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(SmetkiLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(SmetkiLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(SmetkiLista, SIGNAL(sSmetkiToIzvod(QStringList&)), this, SLOT(retSmetkiToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMySmetki::procF2()
{
    pressF2();
}
void QMySmetki::procF3()
{
    pressF3();
}
void QMySmetki::procDel()
{

}
void QMySmetki::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMySmetki::closeW()
{
    pressF4();
}
void QMySmetki::closeWLista()
{
    pressEscape();
}

void QMySmetki::closeAllForm()
{
    SmetkiKorekcija = deleteMyWidget<QIzlezniSmetkiKorekcija>(SmetkiKorekcija);
    SmetkiVnes = deleteMyWidget<QIzlezniSmetkiVnes>(SmetkiVnes);
	if (SmetkiLista)
	{
		m_row = SmetkiLista->getRow();
	}
    SmetkiLista = deleteMyWidget<QIzlezniSmetkiLista>(SmetkiLista);
}
void QMySmetki::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMySmetki::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMySmetki::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMySmetki::getModel()
{
    QStandardItemModel * modelExt;
    if (SmetkiLista)
    {
        modelExt = SmetkiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMySmetki::isCheckedDetailFaktura()
{
	bool stat = false;
	if (SmetkiLista)
	{
		stat = SmetkiLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMySmetki::getModel2()
{
    QStandardItemModel * modelExt;
    if (SmetkiLista)
    {
        modelExt = SmetkiLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMySmetki::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (SmetkiLista)
    {
        modelExt = SmetkiLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMySmetki::retSmetkiToIzvod(QStringList& listData)
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

void QMySmetki::setInitSearchText(QString text)
{
    if (SmetkiLista)
    {
        SmetkiLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMySmetki::setInitSearchTextFaturi(QString text)
{
	if (SmetkiLista)
	{
		SmetkiLista->setInitTextSmetki(text, mmdate1, mmdate2);
	} 
}

void QMySmetki::textChanged(const QString &text)
{
	mmText = text;
	if (SmetkiLista)
	{
		SmetkiLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMySmetki::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (SmetkiLista)
	{
		SmetkiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMySmetki::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (SmetkiLista)
	{
		SmetkiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

