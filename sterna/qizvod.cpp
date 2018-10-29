#include "qizvod.h"


QMyIzvod::QMyIzvod(QWidget *parent)
	: QMyBaseWidget(parent)
	,izvodVnes(0)
	,izvodKorekcija(0)
	,izvodLista(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyIzvod::~QMyIzvod()
{

}
void QMyIzvod::pressF2()
{
	if(!izvodLista)
	{
		return;
	}
	closeAllForm();
	izvodVnes = showMyWidget<QIzvodVnes>(izvodVnes); 
    izvodVnes->setCategoryWidget(this);
    connect(izvodVnes, SIGNAL(closeW()),this,SLOT(closeW()));
    connect(izvodVnes, SIGNAL(signBankiFromIzvod(QWidget*, QString)),this,SLOT(callZiroSmetki(QWidget*, QString)));
	connect(izvodVnes, SIGNAL(signFakturiFromIzvod(QWidget*, QString, int)),this,SLOT(callFakturi(QWidget*, QString, int)));
	connect(izvodVnes, SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));

}
void QMyIzvod::pressF3()
{
	if(!izvodLista)
	{
		return;
	}
	QString bankId = izvodLista->getSelectedBankaId();
	QString izvodId = izvodLista->getSelectedIzvodId();
	QStringList info;
	info << bankId << izvodId;
	closeAllForm();
	izvodKorekcija = showMyWidget<QIzvodKorekcija>(izvodKorekcija); 
	izvodKorekcija->setCategoryWidget(this);
	connect(izvodKorekcija, SIGNAL(closeW()),this,SLOT(closeW()));
	connect(izvodKorekcija, SIGNAL(signBankiFromIzvod(QWidget*, QString)),this,SLOT(callZiroSmetki(QWidget*, QString)));
	connect(izvodKorekcija, SIGNAL(signFakturiFromIzvod(QWidget*, QString, int)),this,SLOT(callFakturi(QWidget*, QString, int)));
	connect(izvodKorekcija, SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
	izvodKorekcija->init(info);
	

}
void QMyIzvod::pressF4()
{
	closeAllForm();
	izvodLista = showMyWidget<QIzvodLista>(izvodLista); 
	izvodLista->setCategoryWidget(this);
	izvodLista->setIzvodiTable(m_info);
	connect(izvodLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(izvodLista,SIGNAL(signBankiFromIzvod(QWidget*, QString)),this,SLOT(callZiroSmetki(QWidget*, QString)));
    connect(izvodLista, SIGNAL(procF2()), this, SLOT(procF2()));
    connect(izvodLista, SIGNAL(procF3()), this, SLOT(procF3()));
    connect(izvodLista, SIGNAL(procDel()), this, SLOT(procDel()));
}

void QMyIzvod::procF2()
{
    pressF2();
}
void QMyIzvod::procF3()
{
    pressF3();
}
void QMyIzvod::procDel()
{

}


void QMyIzvod::pressEscape()
{
	this->raise();
	this->setFocus();
	emit signCloseMyWidget();
}
void QMyIzvod::closeW()
{
	pressF4();
}
void QMyIzvod::closeWLista()
{
	pressEscape();
}

void QMyIzvod::closeAllForm()
{
	izvodKorekcija = deleteMyWidget<QIzvodKorekcija>(izvodKorekcija);
	izvodVnes = deleteMyWidget<QIzvodVnes>(izvodVnes);
	if (izvodLista)
	{
		m_info = izvodLista->getIndexTable();
	}
	izvodLista = deleteMyWidget<QIzvodLista>(izvodLista);
}

void QMyIzvod::callZiroSmetki(QWidget* myobj, QString ziro)
{
	emit signZiroSmetkiFromIzvod(myobj, ziro);
}

void QMyIzvod::callFakturi(QWidget* myobj, QString ziro, int tip)
{
	emit signFakturiFromIzvod(myobj, ziro, tip);
}

void QMyIzvod::refresh()
{
	pressF4();
}
void QMyIzvod::callKomintenti(QWidget* myobj, QString text)
{
	emit signKomintentiFromIspratnica(myobj, text);
}