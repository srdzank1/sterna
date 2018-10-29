#include "qmypopismaster.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qizleznipopismastervnes.h"
#include "qizleznipopismasterkorekcija.h"


QMypopismaster::QMypopismaster(QWidget *parent)
: QMyBaseWidget(parent)
,popismasterVnes(0)
,popismasterKorekcija(0)
,popismasterLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMypopismaster::~QMypopismaster()
{

}

void QMypopismaster::refresh()
{
}
void QMypopismaster::pressF2()
{
	if(!popismasterLista)
	{
		return;
	}
	closeAllForm();
	popismasterVnes = showMyWidget<QIzleznipopismasterVnes>(popismasterVnes); 
    popismasterVnes->setCategoryWidget(this);
	connect(popismasterVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(popismasterVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(popismasterVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(popismasterVnes,SIGNAL(scallpopismaster(QWidget*, QString)),this,SLOT(callpopismaster(QWidget*, QString)));
	emit disablePrint(true);

}
void QMypopismaster::pressF3()
{
    if(!popismasterLista)
    {
        return;
    }
    int id = popismasterLista->getSelectedId();
    closeAllForm();
    popismasterKorekcija = showMyWidget<QIzleznipopismasterKorekcija>(popismasterKorekcija); 
    popismasterKorekcija->setCategoryWidget(this);
    connect(popismasterKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(popismasterKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(popismasterKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(popismasterKorekcija,SIGNAL(scallpopismaster(QWidget*, QString)),this,SLOT(callpopismaster(QWidget*, QString)));
	
    popismasterKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMypopismaster::pressF4()
{
    closeAllForm();
    popismasterLista = showMyWidget<QIzleznipopismasterLista>(popismasterLista); 
    popismasterLista->setCategoryWidget(this);
	popismasterLista->setRow(m_row);
    connect(popismasterLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(popismasterLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(popismasterLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(popismasterLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(popismasterLista, SIGNAL(spopismasterToIzvod(QStringList&)), this, SLOT(retpopismasterToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMypopismaster::procF2()
{
    pressF2();
}
void QMypopismaster::procF3()
{
    pressF3();
}
void QMypopismaster::procDel()
{

}
void QMypopismaster::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMypopismaster::closeW()
{
    pressF4();
}
void QMypopismaster::closeWLista()
{
    pressEscape();
}

void QMypopismaster::closeAllForm()
{
    popismasterKorekcija = deleteMyWidget<QIzleznipopismasterKorekcija>(popismasterKorekcija);
    popismasterVnes = deleteMyWidget<QIzleznipopismasterVnes>(popismasterVnes);
	if (popismasterLista)
	{
		m_row = popismasterLista->getRow();
	}
    popismasterLista = deleteMyWidget<QIzleznipopismasterLista>(popismasterLista);
}
void QMypopismaster::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMypopismaster::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMypopismaster::callpopismaster(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMypopismaster::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMypopismaster::getModel()
{
    QStandardItemModel * modelExt;
    if (popismasterLista)
    {
        modelExt = popismasterLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMypopismaster::isCheckedDetailFaktura()
{
	bool stat = false;
	if (popismasterLista)
	{
		stat = popismasterLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMypopismaster::getModel2()
{
    QStandardItemModel * modelExt;
    if (popismasterLista)
    {
        modelExt = popismasterLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMypopismaster::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (popismasterLista)
    {
        modelExt = popismasterLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMypopismaster::retpopismasterToIzvod(QStringList& listData)
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

// 	if (qobject_cast<QpopisVnes*>(sour))
// 	{
// 		QpopisVnes *dest = qobject_cast<QpopisVnes*>(sour);
// 		dest->setFakturi(listData);
// 		emit eupdateNanigator(dest->getCategoryWidget(), this);
// 		dest->setFocusLine3();
// 	}
// 	if (qobject_cast<QpopisKorekcija*>(sour))
// 	{
// 		QpopisKorekcija *dest = qobject_cast<QpopisKorekcija*>(sour);
// 		dest->setFakturi(listData);
// 		emit eupdateNanigator(dest->getCategoryWidget(), this);
// 		dest->setFocusLine3();
// 	}

}

void QMypopismaster::setInitSearchText(QString text)
{
    if (popismasterLista)
    {
        popismasterLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMypopismaster::setInitSearchTextFaturi(QString text)
{
	if (popismasterLista)
	{
		popismasterLista->setInitTextpopismaster(text, mmdate1, mmdate2);
	} 
}

void QMypopismaster::textChanged(const QString &text)
{
	mmText = text;
	if (popismasterLista)
	{
		popismasterLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMypopismaster::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (popismasterLista)
	{
		popismasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMypopismaster::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (popismasterLista)
	{
		popismasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

