#include "qprofakturi.h"


QMyProFakturi::QMyProFakturi(QWidget *parent)
	: QMyBaseWidget(parent)
	,profakturiVnes(0)
	,profakturiKorekcija(0)
	,profakturiLista(0)
{
	ui.setupUi(this);
	pressF4();
}

QMyProFakturi::~QMyProFakturi()
{

}
void QMyProFakturi::pressF2()
{
	closeAllForm();
	profakturiVnes = showMyWidget<QProFakturiVnes>(profakturiVnes); 
	connect(profakturiVnes,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(profakturiVnes,SIGNAL(scallKomintenti(QWidget*)),this,SLOT(callKomintenti(QWidget*)));
	connect(profakturiVnes,SIGNAL(scallArtikli(QWidget*)),this,SLOT(callArtikli(QWidget*)));

}
void QMyProFakturi::pressF3()
{
	closeAllForm();
	profakturiKorekcija = showMyWidget<QProFakturiKorekcija>(profakturiKorekcija); 
	connect(profakturiKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
	connect(profakturiKorekcija,SIGNAL(scallKomintenti(QWidget*)),this,SLOT(callKomintenti(QWidget*)));
	connect(profakturiKorekcija,SIGNAL(scallArtikli(QWidget*)),this,SLOT(callArtikli(QWidget*)));
}
void QMyProFakturi::pressF4()
{
	closeAllForm();
	profakturiLista = showMyWidget<QProFakturiLista>(profakturiLista); 
	connect(profakturiLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
}
void QMyProFakturi::pressEscape()
{
	this->raise();
	this->setFocus();
	emit signCloseMyWidget();
}
void QMyProFakturi::closeW()
{
	pressF4();
}
void QMyProFakturi::closeWLista()
{
	pressEscape();
}

void QMyProFakturi::closeAllForm()
{
	profakturiKorekcija = deleteMyWidget<QProFakturiKorekcija>(profakturiKorekcija);
	profakturiVnes = deleteMyWidget<QProFakturiVnes>(profakturiVnes);
	profakturiLista = deleteMyWidget<QProFakturiLista>(profakturiLista);
}
void QMyProFakturi::callKomintenti(QWidget* myobj)
{
	emit signKomintentiFromProFaktura(myobj);
}

void QMyProFakturi::callArtikli(QWidget* myobj)
{
	emit signArtikliFromProFaktura(myobj);
}

QStandardItemModel* QMyProFakturi::getModel()
{
    QStandardItemModel * modelExt;
    if (profakturiLista)
    {
        modelExt = profakturiLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStandardItemModel* QMyProFakturi::getModel2()
{
    QStandardItemModel * modelExt;
    if (profakturiLista)
    {
        modelExt = profakturiLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}