#include "qfakturivlezni.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"

QFakturiVlezni::QFakturiVlezni(QWidget *parent)
    : QMyBaseWidget(parent)
    ,fakturaVleznaVnes(0)
    ,fakturaVleznaKorekcija(0)
    ,fakturaVleznaLista(0)
	,m_row(0)
{
    ui.setupUi(this);
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	pressF4();
}

QFakturiVlezni::~QFakturiVlezni()
{

}
void QFakturiVlezni::pressF2()
{
    closeAllForm();
    fakturaVleznaVnes = showMyWidget<QFakturiVlezniVnes>(fakturaVleznaVnes); 
    fakturaVleznaVnes->setCategoryWidget(this);
    connect(fakturaVleznaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(fakturaVleznaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(fakturaVleznaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
}
void QFakturiVlezni::pressF3()
{
    if(!fakturaVleznaLista)
    {
        return;
    }
    int id = fakturaVleznaLista->getSelectedId();
    closeAllForm();
    fakturaVleznaKorekcija = showMyWidget<QFakturiVlezniKorekcija>(fakturaVleznaKorekcija); 
    fakturaVleznaKorekcija->setCategoryWidget(this);
    connect(fakturaVleznaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(fakturaVleznaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(fakturaVleznaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    fakturaVleznaKorekcija->init(id);
}
void QFakturiVlezni::pressF4()
{
    closeAllForm();
    fakturaVleznaLista = showMyWidget<QFakturaVleznaLista>(fakturaVleznaLista); 
    fakturaVleznaLista->setCategoryWidget(this);
	fakturaVleznaLista->setRow(m_row);
    connect(fakturaVleznaLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(fakturaVleznaLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(fakturaVleznaLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(fakturaVleznaLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(fakturaVleznaLista, SIGNAL(sFakturiToIzvod(QStringList&)), this, SLOT(retFakturiToIzvod(QStringList&)));
}

void QFakturiVlezni::procF2()
{
    pressF2();
}
void QFakturiVlezni::procF3()
{
    pressF3();
}
void QFakturiVlezni::procDel()
{

}

void QFakturiVlezni::refresh()
{
}

void QFakturiVlezni::pressEscape()
{
    this->raise();
    this->setFocus();
    emit signCloseMyWidget();
}
void QFakturiVlezni::closeW()
{
    pressF4();
}
void QFakturiVlezni::closeWLista()
{
    pressEscape();
}


void QFakturiVlezni::closeAllForm()
{
    fakturaVleznaKorekcija = deleteMyWidget<QFakturiVlezniKorekcija>(fakturaVleznaKorekcija);
    fakturaVleznaVnes = deleteMyWidget<QFakturiVlezniVnes>(fakturaVleznaVnes);
    if(fakturaVleznaLista)
	{
		m_row = fakturaVleznaLista->getRow();
	}
	fakturaVleznaLista = deleteMyWidget<QFakturaVleznaLista>(fakturaVleznaLista);
}

void QFakturiVlezni::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromPriemnica(myobj, text);
}

void QFakturiVlezni::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromPriemnica(myobj, text);
}
QStandardItemModel* QFakturiVlezni::getModel()
{
    QStandardItemModel * modelExt;
    if (fakturaVleznaLista)
    {
        modelExt = fakturaVleznaLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QFakturiVlezni::getPriemnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (fakturaVleznaLista)
    {
        modelExt = fakturaVleznaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

QStandardItemModel* QFakturiVlezni::getModel2()
{
    QStandardItemModel * modelExt;
    if (fakturaVleznaLista)
    {
        modelExt = fakturaVleznaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

void QFakturiVlezni::retFakturiToIzvod(QStringList& listData)
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

void QFakturiVlezni::setInitSearchText(QString text, QDateTime &date1, QDateTime &date2)
{
    if (fakturaVleznaLista)
    {
        fakturaVleznaLista->setInitText(text, date1, date2);
    } 
}

void QFakturiVlezni::textChanged(const QString &text, QDateTime &date1, QDateTime &date2)
{
	if (fakturaVleznaLista)
	{
		fakturaVleznaLista->setInitText(text+"%", date1, date2);
	} 
}

QStringList QFakturiVlezni::getIspratnicaInfo()
{
	QStringList modelExt;
	modelExt.clear();

	if (fakturaVleznaLista)
	{
		modelExt = fakturaVleznaLista->geInfo();
	} 
	else
	{
		modelExt;
	}
	return modelExt;
}

void QFakturiVlezni::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (fakturaVleznaLista)
	{
		fakturaVleznaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QFakturiVlezni::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (fakturaVleznaLista)
	{
		fakturaVleznaLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

void QFakturiVlezni::textChanged(const QString &text)
{
	mmText = text;
	if (fakturaVleznaLista)
	{
		fakturaVleznaLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

