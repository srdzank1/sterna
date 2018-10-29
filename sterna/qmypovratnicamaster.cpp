#include "qmypovratnicamaster.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"


QMypovratnicamaster::QMypovratnicamaster(QWidget *parent)
: QMyBaseWidget(parent)
,povratnicamasterVnes(0)
,povratnicamasterKorekcija(0)
,povratnicamasterLista(0)
,m_row(0)
{
	mmdate1 = QDateTime::currentDateTime();
	mmdate2 = QDateTime::currentDateTime();
	mmText = "";
	ui.setupUi(this);
	pressF4();
}

QMypovratnicamaster::~QMypovratnicamaster()
{

}

void QMypovratnicamaster::refresh()
{
}
void QMypovratnicamaster::pressF2()
{
	closeAllForm();
	povratnicamasterVnes = showMyWidget<QIzleznipovratnicamasterVnes>(povratnicamasterVnes); 
    povratnicamasterVnes->setCategoryWidget(this);
	connect(povratnicamasterVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(povratnicamasterVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	connect(povratnicamasterVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(povratnicamasterVnes,SIGNAL(scallpovratnicamaster(QWidget*, QString)),this,SLOT(callpovratnicamaster(QWidget*, QString)));
	emit disablePrint(true);

}
void QMypovratnicamaster::pressF3()
{
    if(!povratnicamasterLista)
    {
        return;
    }
    int id = povratnicamasterLista->getSelectedId();
    closeAllForm();
    povratnicamasterKorekcija = showMyWidget<QIzleznipovratnicamasterKorekcija>(povratnicamasterKorekcija); 
    povratnicamasterKorekcija->setCategoryWidget(this);
    connect(povratnicamasterKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(povratnicamasterKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(povratnicamasterKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	connect(povratnicamasterKorekcija,SIGNAL(scallpovratnicamaster(QWidget*, QString)),this,SLOT(callpovratnicamaster(QWidget*, QString)));
	
    povratnicamasterKorekcija->init(id);
	emit disablePrint(true);
	
}
void QMypovratnicamaster::pressF4()
{
    closeAllForm();
    povratnicamasterLista = showMyWidget<QIzleznipovratnicamasterLista>(povratnicamasterLista); 
    povratnicamasterLista->setCategoryWidget(this);
	povratnicamasterLista->setRow(m_row);
    connect(povratnicamasterLista, SIGNAL(closeW()), this, SLOT(closeWLista()));
    connect(povratnicamasterLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(povratnicamasterLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(povratnicamasterLista, SIGNAL(procDel()), this, SLOT(procDel()));
	connect(povratnicamasterLista, SIGNAL(spovratnicamasterToIzvod(QStringList&)), this, SLOT(retpovratnicamasterToIzvod(QStringList&)));
	emit disablePrint(false);

}
void QMypovratnicamaster::procF2()
{
    pressF2();
}
void QMypovratnicamaster::procF3()
{
    pressF3();
}
void QMypovratnicamaster::procDel()
{

}
void QMypovratnicamaster::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);

    emit signCloseMyWidget();
}
void QMypovratnicamaster::closeW()
{
    pressF4();
}
void QMypovratnicamaster::closeWLista()
{
    pressEscape();
}

void QMypovratnicamaster::closeAllForm()
{
    povratnicamasterKorekcija = deleteMyWidget<QIzleznipovratnicamasterKorekcija>(povratnicamasterKorekcija);
    povratnicamasterVnes = deleteMyWidget<QIzleznipovratnicamasterVnes>(povratnicamasterVnes);
	if (povratnicamasterLista)
	{
		m_row = povratnicamasterLista->getRow();
	}
    povratnicamasterLista = deleteMyWidget<QIzleznipovratnicamasterLista>(povratnicamasterLista);
}
void QMypovratnicamaster::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIspratnica(myobj, text);
}

void QMypovratnicamaster::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIspratnica(myobj, text);
}

void QMypovratnicamaster::callpovratnicamaster(QWidget* myobj, QString text)
{
	emit signIspratnica(myobj, text);
}

void QMypovratnicamaster::sendPrintMessage()
{
    emit signPrint();
}


QStandardItemModel* QMypovratnicamaster::getModel()
{
    QStandardItemModel * modelExt;
    if (povratnicamasterLista)
    {
        modelExt = povratnicamasterLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


bool QMypovratnicamaster::isCheckedDetailFaktura()
{
	bool stat = false;
	if (povratnicamasterLista)
	{
		stat = povratnicamasterLista->isButtonChecked();
	} 
	else
	{
		stat = false;
	}
	return stat;
}

QStandardItemModel* QMypovratnicamaster::getModel2()
{
    QStandardItemModel * modelExt;
    if (povratnicamasterLista)
    {
        modelExt = povratnicamasterLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMypovratnicamaster::getIspratnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (povratnicamasterLista)
    {
        modelExt = povratnicamasterLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

void QMypovratnicamaster::retpovratnicamasterToIzvod(QStringList& listData)
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

void QMypovratnicamaster::setInitSearchText(QString text)
{
    if (povratnicamasterLista)
    {
        povratnicamasterLista->setInitText(text, mmdate1, mmdate2);
    } 
}

void QMypovratnicamaster::setInitSearchTextFaturi(QString text)
{
	if (povratnicamasterLista)
	{
		povratnicamasterLista->setInitTextpovratnicamaster(text, mmdate1, mmdate2);
	} 
}

void QMypovratnicamaster::textChanged(const QString &text)
{
	mmText = text;
	if (povratnicamasterLista)
	{
		povratnicamasterLista->setInitText(text+"%", mmdate1, mmdate2);
	} 
}

void QMypovratnicamaster::date1Changed( const QDateTime & date1)
{
	mmdate1 = date1;
	if (povratnicamasterLista)
	{
		povratnicamasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}
void QMypovratnicamaster::date2Changed( const QDateTime & date2)
{
	mmdate2 = date2;
	if (povratnicamasterLista)
	{
		povratnicamasterLista->setInitText(mmText+"%", mmdate1, mmdate2);
	} 
}

