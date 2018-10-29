#include "qmyIzjava.h"
#include "qizvodvnes.h"
#include "qizvodkorekcija.h"


QMyIzjava::QMyIzjava(QWidget *parent)
    : QMyBaseWidget(parent)
    ,IzjavaVnes(0)
    ,IzjavaKorekcija(0)
    ,IzjavaLista(0)
	,m_row(0)
{
    ui.setupUi(this);
    pressF4();
}

QMyIzjava::~QMyIzjava()
{

}

void QMyIzjava::refresh()
{

}

void QMyIzjava::pressF2()
{
    closeAllForm();
    IzjavaVnes = showMyWidget<QIzjavaVnes>(IzjavaVnes); 
    IzjavaVnes->setCategoryWidget(this);
    connect(IzjavaVnes,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(IzjavaVnes,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(IzjavaVnes,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
	emit disablePrint(true);
}
void QMyIzjava::pressF3()
{
    if(!IzjavaLista)
    {
        return;
    }
    int id = IzjavaLista->getSelectedId();
    closeAllForm();
    IzjavaKorekcija = showMyWidget<QIzjavaKorekcija>(IzjavaKorekcija); 
    IzjavaKorekcija->setCategoryWidget(this);
    connect(IzjavaKorekcija,SIGNAL(closeW()),this,SLOT(closeW()));
    connect(IzjavaKorekcija,SIGNAL(scallKomintenti(QWidget*, QString)),this,SLOT(callKomintenti(QWidget*, QString)));
    connect(IzjavaKorekcija,SIGNAL(scallArtikli(QWidget*, QString)),this,SLOT(callArtikli(QWidget*, QString)));
    IzjavaKorekcija->init(id);
	emit disablePrint(true);
}
void QMyIzjava::pressF4()
{
    closeAllForm();
    IzjavaLista = showMyWidget<QIzjavaLista>(IzjavaLista); 
    IzjavaLista->setCategoryWidget(this);
	IzjavaLista->setRowIndex(m_row);
    connect(IzjavaLista,SIGNAL(closeW()),this,SLOT(closeWLista()));
    connect(IzjavaLista,SIGNAL(procF2()),this,SLOT(procF2()));
    connect(IzjavaLista,SIGNAL(procF3()),this,SLOT(procF3()));
    connect(IzjavaLista,SIGNAL(procDel()),this,SLOT(procDel()));
	connect(IzjavaLista, SIGNAL(sIzjavaToIzvod(QString&, QString&, QString&, QString&)), this, SLOT(retIzjavaToIzvod(QString&, QString&, QString&, QString&)));
	emit disablePrint(false);
}

void QMyIzjava::procF2()
{
    pressF2();
}
void QMyIzjava::procF3()
{
    pressF3();
}
void QMyIzjava::procDel()
{

}


void QMyIzjava::pressEscape()
{
    this->raise();
    this->setFocus();
	emit disablePrint(true);
    emit signCloseMyWidget();
}
void QMyIzjava::closeW()
{
    pressF4();
}
void QMyIzjava::closeWLista()
{
    pressEscape();
}


void QMyIzjava::closeAllForm()
{
    IzjavaKorekcija = deleteMyWidget<QIzjavaKorekcija>(IzjavaKorekcija);
    IzjavaVnes = deleteMyWidget<QIzjavaVnes>(IzjavaVnes);
    if (IzjavaLista)
	{
		m_row = IzjavaLista->getSelectedRow();
	}
	IzjavaLista = deleteMyWidget<QIzjavaLista>(IzjavaLista);
}

void QMyIzjava::callKomintenti(QWidget* myobj, QString text)
{
    emit signKomintentiFromIzjava(myobj, text);
}

void QMyIzjava::callArtikli(QWidget* myobj, QString text)
{
    emit signArtikliFromIzjava(myobj, text);
}
QStandardItemModel* QMyIzjava::getModel()
{
    QStandardItemModel * modelExt;
    if (IzjavaLista)
    {
        modelExt = IzjavaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

QStringList QMyIzjava::getIzjavaInfo()
{
    QStringList modelExt;
    modelExt.clear();

    if (IzjavaLista)
    {
        modelExt = IzjavaLista->geInfo();
    } 
    else
    {
        modelExt;
    }
    return modelExt;
}

QStandardItemModel* QMyIzjava::getModel2()
{
    QStandardItemModel * modelExt;
    if (IzjavaLista)
    {
        modelExt = IzjavaLista->model2;
    } 
    else
    {
        modelExt = NULL;
    }
    return modelExt;
}

void QMyIzjava::retIzjavaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName)
{
	QWidget *sour = getSourceWidget();
	if (qobject_cast<QIzvodVnes*>(sour))
	{
		QIzvodVnes *dest = qobject_cast<QIzvodVnes*>(sour);

//		dest->setFakturi(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
	if (qobject_cast<QIzvodKorekcija*>(sour))
	{
		QIzvodKorekcija *dest = qobject_cast<QIzvodKorekcija*>(sour);
//		dest->setFakturi(text6, text8, text9, textName);
		emit eupdateNanigator(dest->getCategoryWidget(), this);
		dest->setFocusLine2();
	}
}
void QMyIzjava::setInitSearchText(QString text)
{
	if (IzjavaLista)
	{
		IzjavaLista->setInitText(text);
	} 
}