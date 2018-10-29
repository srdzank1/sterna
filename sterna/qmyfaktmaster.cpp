#include "qmyfaktmaster.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMyfaktmaster::QMyfaktmaster(QWidget *parent)
: QMyBaseWidget(parent)
,faktmasterVnes(0)
,faktmasterKorekcija(0)
,faktmasterLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMyfaktmaster::~QMyfaktmaster()
{

}

void QMyfaktmaster::refresh()
{
}
void QMyfaktmaster::pressF2()
{
	if(!faktmasterLista)
	{
		return;
	}
	closeAllForm();
	faktmasterVnes = showMyWidget<QIzleznifaktmasterVnes>(faktmasterVnes); 
    faktmasterVnes->setCategoryWidget(this);
	connect(faktmasterVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(faktmasterVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(faktmasterVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(faktmasterVnes,SIGNAL(scallfaktmaster(QWidget*, QString)),this,SLOT(callfaktmaster(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyfaktmaster::pressF3()
{
    if(!faktmasterLista)
    {
        return;
    }
    int id = faktmasterLista->getSelectedId();
    closeAllForm();
    faktmasterKorekcija = showMyWidget<QIzleznifaktmasterKorekcija>(faktmasterKorekcija); 
    faktmasterKorekcija->setCategoryWidget(this);
    connect(faktmasterKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(faktmasterKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(faktmasterKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(faktmasterKorekcija,SIGNAL(scallfaktmaster(QWidget*, QString)),this,SLOT(callfaktmaster(QWidget*, QString)));
	
    faktmasterKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyfaktmaster::pressF4()
{
    closeAllForm();
    faktmasterLista = showMyWidget<QIzleznifaktmasterLista>(faktmasterLista); 
    faktmasterLista->setCategoryWidget(this);
	faktmasterLista->setRow(m_row);
    connect(faktmasterLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(faktmasterLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(faktmasterLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(faktmasterLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(faktmasterLista, SIGNAL(sfaktmasterToIzvod(QStringList&)), this, SLOT(retfaktmasterToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMyfaktmaster::procF2()
{
    pressF2();
}
void QMyfaktmaster::procF3()
{
    pressF3();
}
void QMyfaktmaster::procDel()
{

}
void QMyfaktmaster::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyfaktmaster::closeW()
{
    pressF4();
}
void QMyfaktmaster::closeWLista()
{
    pressEscape();
}

void QMyfaktmaster::closeAllForm()
{
    faktmasterKorekcija = deleteMyWidget<QIzleznifaktmasterKorekcija>(faktmasterKorekcija);
    faktmasterVnes = deleteMyWidget<QIzleznifaktmasterVnes>(faktmasterVnes);
	if (faktmasterLista)
	{
		m_row = faktmasterLista->getRow();
	}
    faktmasterLista = deleteMyWidget<QIzleznifaktmasterLista>(faktmasterLista);
}
void QMyfaktmaster::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyfaktmaster::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyfaktmaster::callfaktmaster(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMyfaktmaster::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyfaktmaster::getModel()
{
    QStandardItemModel * modelExt;
    if (faktmasterLista)
    {
        modelExt = faktmasterLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMyfaktmaster::isCheckedDetailFaktura()
{
	bool stat = false;
	if (faktmasterLista)
	{
		stat = faktmasterLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMyfaktmaster::getModel2()
{
    QStandardItemModel * modelExt;
    if (faktmasterLista)
    {
        modelExt = faktmasterLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyfaktmaster::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (faktmasterLista)
    {
        modelExt = faktmasterLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyfaktmaster::retfaktmasterToIzvod(QStringList& listData)
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

void QMyfaktmaster::setInitSearchText(QString text)
{
    if (faktmasterLista)
    {
        faktmasterLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMyfaktmaster::setInitSearchTextFaturi(QString text)
{
	if (faktmasterLista)
	{
		faktmasterLista->setInitTextfaktmaster(text, mmdate1, mmdate2);
	} 
}

void QMyfaktmaster::textChanged(const QString &text)
{
	mmText = text;
	if (faktmasterLista)
	{
		faktmasterLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyfaktmaster::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (faktmasterLista)
	{
		faktmasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyfaktmaster::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (faktmasterLista)
	{
		faktmasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

void QMyfaktmaster::refreshLista()
{
	if (faktmasterLista)
	{
		faktmasterLista-> lista("%%%",QDateTime::currentDateTime(), QDateTime::currentDateTime());
	} 
}