#include "qmyFakturi.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMyFakturi::QMyFakturi(QWidget *parent)
: QMyBaseWidget(parent)
,FakturiVnes(0)
,FakturiKorekcija(0)
,FakturiLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMyFakturi::~QMyFakturi()
{

}

void QMyFakturi::refresh()
{
}
void QMyFakturi::pressF2()
{
	closeAllForm();
	FakturiVnes = showMyWidget<QIzlezniFakturiVnes>(FakturiVnes); 
    FakturiVnes->setCategoryWidget(this);
	connect(FakturiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(FakturiVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(FakturiVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(FakturiVnes,SIGNAL(scallIspratnici(QWidget*, QString)),this,SLOT(callIspratnici(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyFakturi::pressF3()
{
    if(!FakturiLista)
    {
        return;
    }
    int id = FakturiLista->getSelectedId();
    closeAllForm();
    FakturiKorekcija = showMyWidget<QIzlezniFakturiKorekcija>(FakturiKorekcija); 
    FakturiKorekcija->setCategoryWidget(this);
    connect(FakturiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(FakturiKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(FakturiKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(FakturiKorekcija,SIGNAL(scallIspratnici(QWidget*, QString)),this,SLOT(callIspratnici(QWidget*, QString)));
	
    FakturiKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyFakturi::pressF4()
{
    closeAllForm();
    FakturiLista = showMyWidget<QIzlezniFakturiLista>(FakturiLista); 
    FakturiLista->setCategoryWidget(this);
	FakturiLista->setRow(m_row);
    connect(FakturiLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(FakturiLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(FakturiLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(FakturiLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(FakturiLista, SIGNAL(sFakturiToIzvod(QStringList&)), this, SLOT(retFakturiToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMyFakturi::procF2()
{
    pressF2();
}
void QMyFakturi::procF3()
{
    pressF3();
}
void QMyFakturi::procDel()
{

}
void QMyFakturi::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyFakturi::closeW()
{
    pressF4();
}
void QMyFakturi::closeWLista()
{
    pressEscape();
}

void QMyFakturi::closeAllForm()
{
    FakturiKorekcija = deleteMyWidget<QIzlezniFakturiKorekcija>(FakturiKorekcija);
    FakturiVnes = deleteMyWidget<QIzlezniFakturiVnes>(FakturiVnes);
	if (FakturiLista)
	{
		m_row = FakturiLista->getRow();
	}
    FakturiLista = deleteMyWidget<QIzlezniFakturiLista>(FakturiLista);
}
void QMyFakturi::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyFakturi::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyFakturi::callIspratnici(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMyFakturi::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyFakturi::getModel()
{
    QStandardItemModel * modelExt;
    if (FakturiLista)
    {
        modelExt = FakturiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMyFakturi::isCheckedDetailFaktura()
{
	bool stat = false;
	if (FakturiLista)
	{
		stat = FakturiLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMyFakturi::getModel2()
{
    QStandardItemModel * modelExt;
    if (FakturiLista)
    {
        modelExt = FakturiLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyFakturi::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (FakturiLista)
    {
        modelExt = FakturiLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyFakturi::retFakturiToIzvod(QStringList& listData)
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

void QMyFakturi::setInitSearchText(QString text)
{
    if (FakturiLista)
    {
        FakturiLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMyFakturi::setInitSearchTextFaturi(QString text)
{
	if (FakturiLista)
	{
		FakturiLista->setInitTextFakturi(text, mmdate1, mmdate2);
	} 
}

void QMyFakturi::textChanged(const QString &text)
{
	mmText = text;
	if (FakturiLista)
	{
		FakturiLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyFakturi::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (FakturiLista)
	{
		FakturiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyFakturi::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (FakturiLista)
	{
		FakturiLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

