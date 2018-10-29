#include "qkomintentianalitika.h"
#include "qizlezniispratnicivnes.h"
#include "qizlezniispratnicikorekcija.h"
#include "qizleznifakturivnes.h"
#include "qizleznifakturikorekcija.h"

QKomintentiAnalitika::QKomintentiAnalitika(QWidget *parent)
    : QMyBaseWidget(parent)
    ,komintentAnalitikaLista(0)
{
	ui.setupUi(this);
    pressF4();
}

QKomintentiAnalitika::~QKomintentiAnalitika()
{

}

void QKomintentiAnalitika::pressF4()
{
    closeAllForm();
    komintentAnalitikaLista = showMyWidget<QKomintentiAnalitikaWidget>(komintentAnalitikaLista);
    connect(komintentAnalitikaLista, SIGNAL(closeW()), this, SLOT(closeWLista()));

}
void QKomintentiAnalitika::closeAllForm()
{
    komintentAnalitikaLista = deleteMyWidget<QKomintentiAnalitikaWidget>(komintentAnalitikaLista);
}

void QKomintentiAnalitika::closeWLista()
{
    pressEscape();
}

void QKomintentiAnalitika::pressEscape()
{
    raise();
    setFocus();
    emit signCloseMyWidget();
}
void QKomintentiAnalitika::refresh()
{
}

void QKomintentiAnalitika::callretLagerToDokument(QString& text, QString& textName, QString& textNameSaldo )
{
    QWidget *sour = getSourceWidget();

    if (qobject_cast<QIzlezniIspratniciVnes*>(sour))
    {
        QIzlezniIspratniciVnes *dest = qobject_cast<QIzlezniIspratniciVnes*>(sour);
        dest->setArtikli(text, textName, "");
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniIspratniciKorekcija*>(sour))
    {
        QIzlezniIspratniciKorekcija *dest = qobject_cast<QIzlezniIspratniciKorekcija*>(sour);
        dest->setArtikli(text, textName, "");
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiVnes*>(sour))
    {
        QIzlezniFakturiVnes *dest = qobject_cast<QIzlezniFakturiVnes*>(sour);
        dest->setArtikli(text, textName, "");
        dest->setSaldo(textNameSaldo);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }
    if (qobject_cast<QIzlezniFakturiKorekcija*>(sour))
    {
        QIzlezniFakturiKorekcija *dest = qobject_cast<QIzlezniFakturiKorekcija*>(sour);
        dest->setArtikli(text, textName, "");
        dest->setSaldo(textNameSaldo);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusLine2();
    }

}

void QKomintentiAnalitika::setInitSearchText(QString text)
{
    if (komintentAnalitikaLista)
    {
        komintentAnalitikaLista->setInitText(text);
    } 
}

QStandardItemModel* QKomintentiAnalitika::getModel()
{
	QStandardItemModel * modelExt;
	if (komintentAnalitikaLista)
	{
		modelExt = komintentAnalitikaLista->model;
	} 
	else
	{
		modelExt = NULL;
	}
	return modelExt;
}