#include "qmyprofakturimaster.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMyprofakturimaster::QMyprofakturimaster(QWidget *parent)
: QMyBaseWidget(parent)
,profakturimasterVnes(0)
,profakturimasterKorekcija(0)
,profakturimasterLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMyprofakturimaster::~QMyprofakturimaster()
{

}

void QMyprofakturimaster::refresh()
{
}
void QMyprofakturimaster::pressF2()
{
	closeAllForm();
	profakturimasterVnes = showMyWidget<QIzlezniprofakturimasterVnes>(profakturimasterVnes); 
    profakturimasterVnes->setCategoryWidget(this);
	connect(profakturimasterVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(profakturimasterVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(profakturimasterVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(profakturimasterVnes,SIGNAL(scallprofakturimaster(QWidget*, QString)),this,SLOT(callprofakturimaster(QWidget*, QString)));
	emit disablePrint(true);

}
void QMyprofakturimaster::pressF3()
{
    if(!profakturimasterLista)
    {
        return;
    }
    int id = profakturimasterLista->getSelectedId();
    closeAllForm();
    profakturimasterKorekcija = showMyWidget<QIzlezniprofakturimasterKorekcija>(profakturimasterKorekcija); 
    profakturimasterKorekcija->setCategoryWidget(this);
    connect(profakturimasterKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(profakturimasterKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(profakturimasterKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(profakturimasterKorekcija,SIGNAL(scallprofakturimaster(QWidget*, QString)),this,SLOT(callprofakturimaster(QWidget*, QString)));
	
    profakturimasterKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMyprofakturimaster::pressF4()
{
    closeAllForm();
    profakturimasterLista = showMyWidget<QIzlezniprofakturimasterLista>(profakturimasterLista); 
    profakturimasterLista->setCategoryWidget(this);
	profakturimasterLista->setRow(m_row);
    connect(profakturimasterLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(profakturimasterLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(profakturimasterLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(profakturimasterLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(profakturimasterLista, SIGNAL(sprofakturimasterToIzvod(QStringList&)), this, SLOT(retprofakturimasterToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMyprofakturimaster::procF2()
{
    pressF2();
}
void QMyprofakturimaster::procF3()
{
    pressF3();
}
void QMyprofakturimaster::procDel()
{

}
void QMyprofakturimaster::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMyprofakturimaster::closeW()
{
    pressF4();
}
void QMyprofakturimaster::closeWLista()
{
    pressEscape();
}

void QMyprofakturimaster::closeAllForm()
{
    profakturimasterKorekcija = deleteMyWidget<QIzlezniprofakturimasterKorekcija>(profakturimasterKorekcija);
    profakturimasterVnes = deleteMyWidget<QIzlezniprofakturimasterVnes>(profakturimasterVnes);
	if (profakturimasterLista)
	{
		m_row = profakturimasterLista->getRow();
	}
    profakturimasterLista = deleteMyWidget<QIzlezniprofakturimasterLista>(profakturimasterLista);
}
void QMyprofakturimaster::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMyprofakturimaster::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMyprofakturimaster::callprofakturimaster(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMyprofakturimaster::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMyprofakturimaster::getModel()
{
    QStandardItemModel * modelExt;
    if (profakturimasterLista)
    {
        modelExt = profakturimasterLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMyprofakturimaster::isCheckedDetailFaktura()
{
	bool stat = false;
	if (profakturimasterLista)
	{
		stat = profakturimasterLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMyprofakturimaster::getModel2()
{
    QStandardItemModel * modelExt;
    if (profakturimasterLista)
    {
        modelExt = profakturimasterLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyprofakturimaster::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (profakturimasterLista)
    {
        modelExt = profakturimasterLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMyprofakturimaster::retprofakturimasterToIzvod(QStringList& listData)
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

void QMyprofakturimaster::setInitSearchText(QString text)
{
    if (profakturimasterLista)
    {
        profakturimasterLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMyprofakturimaster::setInitSearchTextFaturi(QString text)
{
	if (profakturimasterLista)
	{
		profakturimasterLista->setInitTextprofakturimaster(text, mmdate1, mmdate2);
	} 
}

void QMyprofakturimaster::textChanged(const QString &text)
{
	mmText = text;
	if (profakturimasterLista)
	{
		profakturimasterLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMyprofakturimaster::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (profakturimasterLista)
	{
		profakturimasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMyprofakturimaster::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (profakturimasterLista)
	{
		profakturimasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

