#include "qmyIspratnici.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"
#include "qizleznifaktmastervnes.h"
#include "qizleznifaktmasterkorekcija.h"


QMyIspratnici::QMyIspratnici(QWidget *parent)
: QMyBaseWidget(parent)
,IspratniciVnes(0)
,IspratniciKorekcija(0)
,IspratniciLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMyIspratnici::~QMyIspratnici()
{

}

void QMyIspratnici::refresh()
{
}
void QMyIspratnici::pressF2()
{
	if(!IspratniciLista)
	{
		return;
	}
	if (!IspratniciLista->getStat())
	{
		return;
	}
	closeAllForm();
	IspratniciVnes = showMyWidget<QIzlezniIspratniciVnes>(IspratniciVnes); 
    IspratniciVnes->setCategoryWidget(this);
	connect(IspratniciVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(IspratniciVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(IspratniciVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(IspratniciVnes,SIGNAL(scallIspratnici(QWidget*, QString)),this,SLOT(callIspratnici(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyIspratnici::pressF3()
{
    if(!IspratniciLista)
    {
        return;
    }
	if (!IspratniciLista->getStatB())
	{
		return;
	}

	int id = IspratniciLista->getSelectedId();
    closeAllForm();
    IspratniciKorekcija = showMyWidget<QIzlezniIspratniciKorekcija>(IspratniciKorekcija); 
    IspratniciKorekcija->setCategoryWidget(this);
    connect(IspratniciKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(IspratniciKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(IspratniciKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(IspratniciKorekcija,SIGNAL(scallIspratnici(QWidget*, QString)),this,SLOT(callIspratnici(QWidget*, QString)));
	
    IspratniciKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyIspratnici::pressF4()
{
    closeAllForm();
    IspratniciLista = showMyWidget<QIzlezniIspratniciLista>(IspratniciLista); 
    IspratniciLista->setCategoryWidget(this);
	IspratniciLista->setRow(m_row);
    connect(IspratniciLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(IspratniciLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(IspratniciLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(IspratniciLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(IspratniciLista, SIGNAL(sIspratniciToIzvod(QStringList&)), this, SLOT(retIspratniciToIzvod(QStringList&)));
	connect(IspratniciLista, SIGNAL(callSearchForm()), this, SLOT(procCallSearchFormA()));
	emit disablePrint(false);

}

void QMyIspratnici::procCallSearchFormA()
{
	emit signCallSearchForm();
}

void QMyIspratnici::procF2()
{
    pressF2();
}
void QMyIspratnici::procF3()
{
    pressF3();
}
void QMyIspratnici::procDel()
{

}
void QMyIspratnici::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyIspratnici::closeW()
{
    pressF4();
}
void QMyIspratnici::closeWLista()
{
    pressEscape();
}

void QMyIspratnici::closeAllForm()
{
    IspratniciKorekcija = deleteMyWidget<QIzlezniIspratniciKorekcija>(IspratniciKorekcija);
    IspratniciVnes = deleteMyWidget<QIzlezniIspratniciVnes>(IspratniciVnes);
	if (IspratniciLista)
	{
		m_row = IspratniciLista->getRow();
	}
    IspratniciLista = deleteMyWidget<QIzlezniIspratniciLista>(IspratniciLista);
}
void QMyIspratnici::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyIspratnici::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyIspratnici::callIspratnici(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMyIspratnici::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyIspratnici::getModel()
{
    QStandardItemModel * modelExt;
    if (IspratniciLista)
    {
        modelExt = IspratniciLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMyIspratnici::isCheckedDetailFaktura()
{
	bool stat = false;
	if (IspratniciLista)
	{
		stat = IspratniciLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMyIspratnici::getModel2()
{
    QStandardItemModel * modelExt;
    if (IspratniciLista)
    {
        modelExt = IspratniciLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyIspratnici::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (IspratniciLista)
    {
        modelExt = IspratniciLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyIspratnici::retIspratniciToIzvod(QStringList& listData)
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
	if (qobject_cast<QIzleznifaktmasterVnes*>(sour))
	{
		QIzleznifaktmasterVnes *dest = qobject_cast<QIzleznifaktmasterVnes*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
//		dest->setFocusLine3();
	}
	if (qobject_cast<QIzleznifaktmasterKorekcija*>(sour))
	{
		QIzleznifaktmasterKorekcija *dest = qobject_cast<QIzleznifaktmasterKorekcija*>(sour);
		dest->setFakturi(listData);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
//		dest->setFocusLine3();
	}
}

void QMyIspratnici::setInitSearchText(QString text)
{
    if (IspratniciLista)
    {
        IspratniciLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMyIspratnici::setInitSearchTextFaturi(QString text)
{
	if (IspratniciLista)
	{
		IspratniciLista->setInitTextIspratnici(text, mmdate1, mmdate2);
	} 
}

void QMyIspratnici::textChanged(const QString &text)
{
	mmText = text;
	if (IspratniciLista)
	{
		IspratniciLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyIspratnici::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (IspratniciLista)
	{
		IspratniciLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyIspratnici::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (IspratniciLista)
	{
		IspratniciLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

void QMyIspratnici::refreshLista()
{
	if (IspratniciLista)
	{
		IspratniciLista-> lista("%%%",QDateTime::currentDateTime(), QDateTime::currentDateTime());
	} 
}