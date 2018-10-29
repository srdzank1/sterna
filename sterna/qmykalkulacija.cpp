#include "qmyKalkulacija.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"

QMyKalkulacija::QMyKalkulacija(QWidget *parent)
    : QMyBaseWidget(parent)
    ,KalkulacijaVnes(0)
    ,KalkulacijaKorekcija(0)
    ,KalkulacijaLista(0)
	,m_row(0)
{
    ui.setupUi(this);
    pressF4();
}

QMyKalkulacija::~QMyKalkulacija()
{

}
void QMyKalkulacija::pressF2()
{
	if(!KalkulacijaLista)
	{
		return;
	}
	closeAllForm();
    KalkulacijaVnes = showMyWidget<QKalkulacijaVnes>(KalkulacijaVnes); 
    KalkulacijaVnes->setCategoryWidget(this);
    connect(KalkulacijaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(KalkulacijaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(KalkulacijaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(KalkulacijaVnes,SIGNAL(scallPriemnici(QWidget*, QString)),this,SLOT(callPriemnici(QWidget*, QString)));
	emit disablePrint(true);
}
void QMyKalkulacija::pressF3()
{
	if(!KalkulacijaLista)
	{
		return;
	}
    int id = KalkulacijaLista->getSelectedId();
    closeAllForm();
    KalkulacijaKorekcija = showMyWidget<QKalkulacijaKorekcija>(KalkulacijaKorekcija); 
    KalkulacijaKorekcija->setCategoryWidget(this);
    connect(KalkulacijaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(KalkulacijaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(KalkulacijaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(KalkulacijaKorekcija,SIGNAL(scallPriemnici(QWidget*, QString)),this,SLOT(callPriemnici(QWidget*, QString)));

	KalkulacijaKorekcija->init(id);
	emit disablePrint(true);
}
void QMyKalkulacija::pressF4()
{
    closeAllForm();
    KalkulacijaLista = showMyWidget<QKalkulacijaLista>(KalkulacijaLista); 
    KalkulacijaLista->setCategoryWidget(this);
	KalkulacijaLista->setRow(m_row);
    connect(KalkulacijaLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(KalkulacijaLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(KalkulacijaLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(KalkulacijaLista,SIGNAL(procDel()),this,SLOT(procDel()));
	connect(KalkulacijaLista, SIGNAL(sFakturiToIzvod(QStringList& )), this, SLOT(retFakturiToIzvod(QStringList& )));

	emit disablePrint(false);
}

void QMyKalkulacija::procF2()
{
    pressF2();
}
void QMyKalkulacija::procF3()
{
    pressF3();
}
void QMyKalkulacija::procDel()
{

}

void QMyKalkulacija::refresh()
{

}


void QMyKalkulacija::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);
    emit signCloseMyWidget();
}
void QMyKalkulacija::closeW()
{
    pressF4();
}
void QMyKalkulacija::closeWLista()
{
    pressEscape();
}


void QMyKalkulacija::closeAllForm()
{
    KalkulacijaKorekcija = deleteMyWidget<QKalkulacijaKorekcija>(KalkulacijaKorekcija);
    KalkulacijaVnes = deleteMyWidget<QKalkulacijaVnes>(KalkulacijaVnes);
	if (KalkulacijaLista)
	{
		m_row = KalkulacijaLista->getRow();
	}
    KalkulacijaLista = deleteMyWidget<QKalkulacijaLista>(KalkulacijaLista);
}

void QMyKalkulacija::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromKalkulacija(myobj, text);
}

void QMyKalkulacija::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromKalkulacija(myobj, text);
}

void QMyKalkulacija::callPriemnici(QWidget* myobj, QString text)
{
	emit signImportArtikliFromKalkulacija(myobj, text);
}


QStandardItemModel* QMyKalkulacija::getModel()
{
    QStandardItemModel * modelExt;
    if (KalkulacijaLista)
    {
        modelExt = KalkulacijaLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyKalkulacija::getKalkulacijaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (KalkulacijaLista)
    {
        modelExt = KalkulacijaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

QStandardItemModel* QMyKalkulacija::getModel2()
{
    QStandardItemModel * modelExt;
    if (KalkulacijaLista)
    {
        modelExt = KalkulacijaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

void QMyKalkulacija::retFakturiToIzvod(QStringList& listData)
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
}

void QMyKalkulacija::setInitSearchText(QString text, QDateTime &date1, QDateTime &date2)
{
	if (KalkulacijaLista)
	{
		KalkulacijaLista->setInitText(text, date1, date2);
	} 
}

void QMyKalkulacija::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (KalkulacijaLista)
	{
		KalkulacijaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyKalkulacija::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (KalkulacijaLista)
	{
		KalkulacijaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

void QMyKalkulacija::textChanged(const QString &text)
{
	mmText = text;
	if (KalkulacijaLista)
	{
		KalkulacijaLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

