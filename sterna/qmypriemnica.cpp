#include "qmypriemnica.h"

QMyPriemnica::QMyPriemnica(QWidget *parent)
    : QMyBaseWidget(parent)
    ,priemnicaVnes(0)
    ,priemnicaKorekcija(0)
    ,priemnicaLista(0)
{
    ui.setupUi(this);
    pressF4();
}

QMyPriemnica::~QMyPriemnica()
{

}
void QMyPriemnica::pressF2()
{
    closeAllForm();
    priemnicaVnes = showMyWidget<QPriemnicaVnes>(priemnicaVnes); 
    priemnicaVnes->setCategoryWidget(this);
    connect(priemnicaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(priemnicaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(priemnicaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);
}
void QMyPriemnica::pressF3()
{
    if(!priemnicaLista)
    {
        return;
    }
    int id = priemnicaLista->getSelectedId();
    closeAllForm();
    priemnicaKorekcija = showMyWidget<QPriemnicaKorekcija>(priemnicaKorekcija); 
    priemnicaKorekcija->setCategoryWidget(this);
    connect(priemnicaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(priemnicaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(priemnicaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    priemnicaKorekcija->init(id);
	emit disablePrint(true);
}
void QMyPriemnica::pressF4()
{
    closeAllForm();
    priemnicaLista = showMyWidget<QPriemnicaLista>(priemnicaLista); 
    priemnicaLista->setCategoryWidget(this);
    connect(priemnicaLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(priemnicaLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(priemnicaLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(priemnicaLista,SIGNAL(procDel()),this,SLOT(procDel()));
	emit disablePrint(false);
}

void QMyPriemnica::procF2()
{
    pressF2();
}
void QMyPriemnica::procF3()
{
    pressF3();
}
void QMyPriemnica::procDel()
{

}

void QMyPriemnica::refresh()
{

}


void QMyPriemnica::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);
    emit signCloseMyWidget();
}
void QMyPriemnica::closeW()
{
    pressF4();
}
void QMyPriemnica::closeWLista()
{
    pressEscape();
}


void QMyPriemnica::closeAllForm()
{
    priemnicaKorekcija = deleteMyWidget<QPriemnicaKorekcija>(priemnicaKorekcija);
    priemnicaVnes = deleteMyWidget<QPriemnicaVnes>(priemnicaVnes);
    priemnicaLista = deleteMyWidget<QPriemnicaLista>(priemnicaLista);
}

void QMyPriemnica::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromPriemnica(myobj, text);
}

void QMyPriemnica::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromPriemnica(myobj, text);
}
QStandardItemModel* QMyPriemnica::getModel()
{
    QStandardItemModel * modelExt;
    if (priemnicaLista)
    {
        modelExt = priemnicaLista->model;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyPriemnica::getPriemnicaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (priemnicaLista)
    {
        modelExt = priemnicaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

QStandardItemModel* QMyPriemnica::getModel2()
{
    QStandardItemModel * modelExt;
    if (priemnicaLista)
    {
        modelExt = priemnicaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}