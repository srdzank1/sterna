#include "qmykomintenti.h"
#include "qpriemnicavnes.h"
#include "qpriemnicakorekcija.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"
#include "qpovratnicavnes.h"
#include "qpovratnicakorekcija.h"
#include "qprofakturavnes.h"
#include "qprofakturakorekcija.h"
#include "qkasavnes.h"
#include "qkasakorekcija.h"
#include "qfakturivnes.h"
#include "qfakturikorekcija.h"
#include "qizjavavnes.h"
#include "qizjavakorekcija.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"
#include "qkalkulacijavnes.h"
#include "qkalkulacijakorekcija.h"
#include "qizleznismetkivnes.h"
#include "qizleznismetkikorekcija.h"
#include "qizleznifaktmastervnes.h"
#include "qizleznifaktmasterkorekcija.h"
#include "qprofakturimastervnes.h"
#include "qprofakturimasterkorekcija.h"
#include "qizleznipovratnicamastervnes.h"
#include "qizleznipovratnicamasterkorekcija.h"
#include "qporackismetkivnes.h"
#include "qporackismetkikorekcija.h"


QMyKomintenti::QMyKomintenti(QWidget *parent)
	: QMyBaseWidget(parent)
	,komintentiVnes(0)
	,komintentiKorekcija(0)
	,komintentiLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QMyKomintenti::~QMyKomintenti()
{

}

void QMyKomintenti::pressF2()
{
	if(!komintentiLista )
	{
		return;
	}
	closeAllForm();
	komintentiVnes = showMyWidget<QKomintentiVnes>(komintentiVnes); 
	connect(komintentiVnes,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(komintentiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	komintentiVnes->setInitValue( lastSearchStr);
}
void QMyKomintenti::pressF3()
{
	if(!komintentiLista )
	{
		return;
	}
	QString selText = komintentiLista ? komintentiLista->getSelectedText() : "";
	if (selText.isEmpty())
	{
		return;
	}
	closeAllForm();
	komintentiKorekcija = showMyWidget<QKomintentiKorekcija>(komintentiKorekcija); 
	connect(komintentiKorekcija,SIGNAL(succesfulEntryData()),this,SLOT(succesfulEntryData()));
	connect(komintentiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	komintentiKorekcija->showData(selText);
}
void QMyKomintenti::pressF4()
{
    closeAllForm();
	komintentiLista = showMyWidget<QKomintentiLista>(komintentiLista);
	komintentiLista->setSearchText(lastSearchStr);  
	connect(komintentiLista,SIGNAL(sKomintentToPriemnica(QString&, QString&)),this,SLOT(retKomintentToPriemnica(QString&, QString&)), Qt::DirectConnection);
	connect(komintentiLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(komintentiLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(komintentiLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(komintentiLista,SIGNAL(procDel()),this,SLOT(procDel()));
}

void QMyKomintenti::procF2()
{
    pressF2();
}
void QMyKomintenti::procF3()
{
    pressF3();
}
void QMyKomintenti::procDel()
{

}

void QMyKomintenti::closeW()
{
	pressF4();
}
void QMyKomintenti::closeWLista()
{
	pressEscape();
}

void QMyKomintenti::pressEscape()
{
	raise();
	setFocus();
	emit signCloseMyWidget();
}
void QMyKomintenti::closeAllForm()
{
    komintentiKorekcija = deleteMyWidget<QKomintentiKorekcija>(komintentiKorekcija);
    komintentiVnes = deleteMyWidget<QKomintentiVnes>(komintentiVnes);
	if (komintentiLista)
	{
		lastSearchStr = komintentiLista->getSearchStr();
	}
    komintentiLista = deleteMyWidget<QKomintentiLista>(komintentiLista);
}

void QMyKomintenti::succesfulEntryData()
{
	pressF4();
}

void QMyKomintenti::retKomintentToPriemnica(QString& text, QString& textName)
{

	QWidget *sour = getSourceWidget();

	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QIzleznifaktmasterVnes*>(sour))
	{
		QIzleznifaktmasterVnes *dest = qobject_cast<QIzleznifaktmasterVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznifaktmasterKorekcija*>(sour))
	{
		QIzleznifaktmasterKorekcija *dest = qobject_cast<QIzleznifaktmasterKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznipovratnicamasterVnes*>(sour))
	{
		QIzleznipovratnicamasterVnes *dest = qobject_cast<QIzleznipovratnicamasterVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzleznipovratnicamasterKorekcija*>(sour))
	{
		QIzleznipovratnicamasterKorekcija *dest = qobject_cast<QIzleznipovratnicamasterKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}

	if (qobject_cast<QPorackiSmetkiVnes*>(sour))
	{
		QPorackiSmetkiVnes *dest = qobject_cast<QPorackiSmetkiVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QPorackiSmetkiKorekcija*>(sour))
	{
		QPorackiSmetkiKorekcija *dest = qobject_cast<QPorackiSmetkiKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}


	if (qobject_cast<QIzlezniSmetkiVnes*>(sour))
	{
		QIzlezniSmetkiVnes *dest = qobject_cast<QIzlezniSmetkiVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzlezniSmetkiKorekcija*>(sour))
	{
		QIzlezniSmetkiKorekcija *dest = qobject_cast<QIzlezniSmetkiKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QPriemnicaVnes*>(sour))
	{
		QPriemnicaVnes *dest = qobject_cast<QPriemnicaVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QPriemnicaKorekcija*>(sour))
	{
		QPriemnicaKorekcija *dest = qobject_cast<QPriemnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

	if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
	{
		QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
    }
	if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
	{
		QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QFakturiVlezniVnes*>(sour))
    {
        QFakturiVlezniVnes *dest = qobject_cast<QFakturiVlezniVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QFakturiVlezniKorekcija*>(sour))
    {
        QFakturiVlezniKorekcija *dest = qobject_cast<QFakturiVlezniKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();

    }
	if (qobject_cast<QIzlezniFakturiVnes*>(sour))
	{
		QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
	{
		QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QPovratnicaVnes*>(sour))
	{
		QPovratnicaVnes *dest = qobject_cast<QPovratnicaVnes*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
	if (qobject_cast<QPovratnicaKorekcija*>(sour))
	{
		QPovratnicaKorekcija *dest = qobject_cast<QPovratnicaKorekcija*>(sour);
		dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

    if (qobject_cast<QProFakturiVnes*>(sour))
    {
        QProFakturiVnes *dest = qobject_cast<QProFakturiVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QProFakturiKorekcija*>(sour))
    {
        QProFakturiKorekcija *dest = qobject_cast<QProFakturiKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaVnes*>(sour))
    {
        QKasaVnes *dest = qobject_cast<QKasaVnes*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }
    if (qobject_cast<QKasaKorekcija*>(sour))
    {
        QKasaKorekcija *dest = qobject_cast<QKasaKorekcija*>(sour);
        dest->setKomintent(text, textName);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine();
    }

	if (qobject_cast<QIzjavaVnes*>(sour))
	{
		QIzjavaVnes *dest = qobject_cast<QIzjavaVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QIzjavaKorekcija*>(sour))
	{
		QIzjavaKorekcija *dest = qobject_cast<QIzjavaKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QKalkulacijaVnes*>(sour))
	{
		QKalkulacijaVnes *dest = qobject_cast<QKalkulacijaVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QKalkulacijaKorekcija*>(sour))
	{
		QKalkulacijaKorekcija *dest = qobject_cast<QKalkulacijaKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	
	if (qobject_cast<QIzlezniprofakturimasterVnes*>(sour))
	{
		QIzlezniprofakturimasterVnes *dest = qobject_cast<QIzlezniprofakturimasterVnes*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}
	if (qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour))
	{
		QIzlezniprofakturimasterKorekcija *dest = qobject_cast<QIzlezniprofakturimasterKorekcija*>(sour);
		dest->setKomintent(text, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine();
	}

}

QStandardItemModel* QMyKomintenti::getModel()
{
    QStandardItemModel * modelExt;
    if (komintentiLista)
    {
        modelExt = komintentiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}


void QMyKomintenti::setInitSearchText(QString text)
{
	if (komintentiLista)
	{
		komintentiLista->setInitText(text);
	} 
}

void QMyKomintenti::textChanged(const QString &text)
{
	if (komintentiLista)
	{
		komintentiLista->setInitText(text+"%");
	} 
}