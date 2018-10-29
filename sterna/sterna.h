#ifndef STERNA_H
#define STERNA_H

#include <QMainWindow>
#include "ui_sterna.h"
#include "qleft.h"
#include "qmyartikli.h"
#include "qmykomintenti.h"
#include "qmyispratnici.h"
#include "qmypriemnica.h"
#include "qmypovratnica.h"
#include "qmykalkulacija.h"
#include "qmyfakturi.h"
#include "qbanki.h"
#include "qddv.h"
#include "qizvod.h"
#include "qmykasa.h"
#include "qkartici.h"
#include "qlager.h"
#include "qpriem.h"
#include "qizvestai.h"
#include "qprofakturi.h"
#include "qfakturivlezni.h"
#include "qkomintentianalitika.h"
#include "qAnalitikaArtikli.h"
#include "qAnalitikaKomintenti.h"
#include "qmyizjava.h"
#include "qdnevenpromet.h"
#include "qperiodicenizvestaj.h"
#include "qFinAnalitikaKomintenti.h"
#include "qmyodobrenie.h"
#include <QDockWidget>
#include "qizvod.h"
#include "qsearchform.h"
#include "qsearchformfaktura.h"
#include "quserform.h"
#include "xx.h"
#include <QTimer>
#include "qmyEmploye.h"
#include "qmysmetki.h"
#include "qpromenaceni.h"
#include "qmyfaktmaster.h"
#include "qmyprofakturimaster.h"
#include "qmypovratnicamaster.h"
#include "qmypopismaster.h"
#include "qmyporackismetki.h"
#include <QPrinter>
#include <QDir>

class sterna : public QMainWindow
{
	Q_OBJECT

public:
	static float ZeroPointFive;
    sterna(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~sterna();
	void createDockWindows();
	void connectToDatabase();
    void drawHeader(QPainter& painter);
    void drawFooter(QPainter& painter);
	void drawFaktura(QPrinter *printer, QPainter& painter);
	void drawProFakturaMaster(QPrinter *printer, QPainter& painter);
	void drawFakturaMaster(QPrinter *printer, QPainter& painter);
	void drawFakturaALL(QPrinter *printer, QPainter& painter);
	void drawProFakturaMaster_all(QPrinter *printer, QPainter& painter);
	void drawFakturaMaster_all(QPrinter *printer, QPainter& painter);

	void drawSmetka(QPrinter *printer, QPainter& painter);
	void drawProFaktura(QPainter& painter);
	void drawIspratnica(QPrinter *printer, QPainter& painter);
	void drawPriemnica(QPrinter *printer, QPainter& painter);
	void drawLagerLista(QPrinter *printer,QPainter& painter);
	void drawArtikliLista(QPrinter *printer, QPainter& painter);
	void drawIzjava(QPrinter *printer, QPainter& painter);
	void drawKomintentiLista(QPainter& painter);
	void drawDnevenIzvestaj(QPrinter *printer,QPainter& painter);
    void drawAnalitikaArtikli(QPrinter *printer,QPainter& painter);
    void drawAnalitikaKomintenti(QPrinter *printer,QPainter& painter);
	void drawPovratnica(QPrinter *printer, QPainter& painter);
	void draw_PeriodicenIzvestaj(QPrinter *printer,QPainter& painter);
	void drawVleznaFaktura(QPrinter *printer, QPainter& painter);
	void drawIzvod(QPrinter *printer, QPainter& painter);
	void drawFinAnalitikaKomintenti(QPrinter *printer, QPainter& painter);
	void drawFakturaVkupno(QPrinter *printer, QPainter& painter);
	void drawIspratnicaALL(QPrinter *printer, QPainter& painter);
	void drawKalkulacija(QPrinter *printer, QPainter& painter);
	


	QString convertSToText(int& num);
	QString convertIntToText(int& num);
	
	void writeSettings();
	void readSettings();
	
	void writeSettingsKalkulacija();
	void readSettingsKalkulacija();
	
	void writeSettingsIspratnica();
	void readSettingsIspratnica();

	void writeSettingsFaktura();
	void readSettingsFaktura();

	void writeSettingsProFaktura();
	void readSettingsProFaktura();

	void writeSettingsSmetka();
	void readSettingsSmetka();

private:
    Ui::sternaClass ui;
	QDockWidget *dock;
	QLeft *m_left;
	QMyArtikli *m_myartikli;
	QMyOdobrenie *m_myodobrenie;
	QMyKomintenti *m_mykomintenti;
	QMyIspratnici *m_myispratnici;
	QMyPriemnica *m_mypriemnici;
	QMyPovratnica *m_mypovratnica;
	QMyFakturi *m_myfaktura;
	QMyfaktmaster *m_myfaktmaster;

	QFakturiVlezni *m_myfakturavlezna;
	
	QMyBanki *m_mybanki;
	QMyDdv *m_myddv;
	QMyIzvod *m_myizvod;	
	QMyKasa *m_mykasa;
	QKartici *m_mykartici;
	QLager *m_mylager;
    QPriem *m_mypriem;

    QIzvestai *m_myizvestai;
	QMyProFakturi *m_myprofakturi;
    QKomintentiAnalitika * m_mykomintenti_analitika;
    QAnalitikaKomintenti *m_analitikaKomintenti;
    QFinAnalitKomintenti *m_finanalitikaKomintenti;

    
    QAnalitikaArtikli *m_analitikaArtikli;
	QMyIzjava * m_myizjava;
	QDnevenpromet *m_dnevenpromet;
	QPeriodicenIzvestaj *m_periodicen;
	QMySmetki *m_smetki;
	QMyKalkulacija *m_mykalkulacija;
	QMyEmploye *m_employe;
	QPromenaCeni *m_promena_ceni;
	QMyprofakturimaster *m_profakturimaster;
	QMypovratnicamaster *m_povratnicamaster;
	QMypopismaster *m_popismaster;
	QMyPorackiSmetki *m_porackismetki;

	QString moi_porackismetki;
	QString moi_promena_ceni;
	QString moi_smetki;
	QString moi_employe;
	QString moi_periodicen;
	QString moi_artikli;
	QString moi_banki;
	QString moi_ddv;
	QString moi_faktura;
	QString moi_ispratnici;
	QString moi_izvod;
	QString moi_komintenti;
	QString moi_kasa;
	QString moi_kartici;
	QString moi_lagerlista;
    QString moi_priemlista;
    QString moi_izvestai;
	QString moi_povratnica;
	QString moi_priemnici;
	QString moi_profakturi;
	QString moi_fakturavlezna;
	QString moi_firma_info1;
	QString moi_firma_info2;
    QString moi_firma_info3;
	QString moi_firma_tel;
	QString moi_firma_email;
	QString moi_firma_web;
	QString moi_firma_banka1;
	QString moi_firma_banka2;
	QString moi_firma_edb;
	QString moi_logo;
	QString moi_nozici;
    QString moi_komintenti_analitika;
    QString moi_analitikaArtikli;
	QString moi_izjava;
	QString moi_dnevenpromet;
	QString moi_izjava1;
    QString moi_izjava2;
	QString moi_prefix_prodavnica;
	QString moi_god;
    QString moi_analitikaKomintenti;
	QString moi_finanalitikaKomintenti;
	QString moi_odobrenie;
	QString moi_kalkulacija;
	QString moi_faktmaster;
	QString moi_profakturimaster;
	QString moi_povratnicamaster;
	QString moi_popis;
	QString moi_direktor;
	QString moi_fakturiral;

	int m_pageWidth;
    int m_pageHeight;
    double m_pageWidthScale;
    double m_pageHeightScale;
    int relX(double x);
    int relY(double y);
	int m_selectedPrint;

    enum selView
    {
        SV_ART          = 1,
        SV_KOM          = 2,
        SV_ISP          = 3,
		SV_PRI          = 4,
        SV_POV          = 5,
        SV_FKT          = 6,
        SV_DDV          = 7,
        SV_PFKT         = 8,
        SV_KAS          = 9,
        SV_BNK          = 10,
        SV_IZV          = 11,
        SV_IZVES        = 12,
        SV_LGR          = 13,
		SV_FKT_VLEZNA   = 14,
		SV_IZJ			= 15,
		SV_DNVIZV		= 16,
		SV_SMT			= 17,
        SV_ANA          = 18,
        SV_ANKOM        = 19,
		SV_PER_IZV		= 20,
		SV_VLFKT		= 21,
		SV_FIN_A_K		= 22,
		SV_FKT_ALL		= 23,
		SV_PROFAKTURIMASTER = 24,
		SV_PROFAKTURIMASTER_ALL = 25,
		SV_FAKTURIMASTER_ALL = 26,
		SV_FAKTURIMASTER = 27,
		SV_ISP_ALL       = 28,
		SV_KALKULACIJA = 29
    };


public:


	template <class T, class P, class S>
	T* showMyWidget(T *a, QString info, P *parent, S* source) 
	{
		if (a)
		{
			a->setFocus();
			a->refresh();
			a->raise();
			a->setSourceWidget(source);
			m_left->updateSelection((QWidget*)a);
			return a;
		}
		a = new T(parent);
		connect(a, SIGNAL(signCloseMyWidget()), this, SLOT(closeMyWidget()));
		a->setGeometry(parent->rect());
		m_left->addTreeWidgetItem(info, (P*)a);
		a->setSourceWidget(source);
		a->show();
		a->setFocus();
		a->raise();
		return a;
	}

	template <class T>
	void deleteMyWidget(T *a) 
	{
		m_left->deleteTreeWidgetItem((QWidget*)a);
		a->close();
		delete a;
		a = 0;
	}


private slots:
	void printPreview(QPrinter *printer);
    
    void on_actionDDV_triggered();
	void callProcCallSearchForm();
	void on_actionMyFakturi_triggered();
    void on_actionMyFakturiVlezni_triggered();
	void on_actionMyPovratnica_triggered();
	void on_actionMyPriemnici_triggered();
	void on_actionMyIspratnici_triggered();
	void on_actionFakturiMaster_triggered();
	void on_action_MyArtikli_triggered();
	void on_action_KomintentiLista_triggered();
	void on_actionVraboteni_triggered();
	void on_actionProFaktura_triggered();
	void on_actionKasi_triggered();
	void on_actionKalkulacii_triggered();
	void on_actionPorackiSmetki_triggered();
	void callProcKalkulacija(QWidget * widget, QString text);
	void callProcPriemnicaFromKalkulacii(QWidget * widget, QString text);
    void on_actionBanki_triggered();
    void on_actionIzvodi_triggered();
    void on_actionIzvestai_triggered();
    void on_actionLager_triggered();
    void on_actionPriem_triggered();
    void on_actionAnalitikaKomintent_triggered();
    void on_actionAnalitikaArtikli_triggered();
	void on_actionIzjava_triggered();
	void on_actionDnevenPromet_triggered();
	void on_actionClose_triggered();
	void on_actionPeriodicenIzvestaj_triggered();
	void on_actionFinansova_Kartica_triggered();
	void on_actionMyOdobrenie_triggered();
	void on_actionSmetki_triggered();
	void on_actionPopis_triggered();
	void on_actionIzvestaPromenaCeni_triggered();
	void on_actionDnevnoFiskalnoZatvaranje_triggered();
	void on_actionKontrolenIzvestaj_triggered();
	void on_actionPodesuvanjeDatumCas_triggered();

	void on_actionDetalenIzvestajPoPeriod_triggered();



	void closeMyWidget();
	void callProcArtikliFromFaktura(QMyBaseWidget * widget);
	void callProcKomintentiFromFaktura(QMyBaseWidget * widget);
	void callProcKomintentiFromPriemnica(QWidget * widget, QString);
	void callProcArtikliFromPriemnica(QWidget * widget, QString);
	void callProcKomintentiFromIspratnica(QWidget * widget, QString);
	void callProcArtikliFromIspratnica(QWidget * widget, QString);
	void callProcKomintentiFromFaktura(QWidget * widget);
	void callProcArtikliFromFaktura(QWidget * widget);
	void callProcKomintentiFromPovratnica(QWidget * widget, QString text);
	void callProcFakturiFromPovratnica(QWidget * widget, QString text);
	void callProcArtikliFromPovratnica(QWidget * widget, QString text);
    void callProcKomintentiFromProFakturi(QWidget * widget);
    void callProcArtikliFromProFakturi(QWidget * widget);
    void callProcKomintentiFromKasa(QWidget * widget, QString text);
    void callProcArtikliFromKasa(QWidget * widget, QString text);
    void callProcArtikliFromIzvod(QWidget * widget);
    void callProcKomintentiFromIzvod(QWidget * widget);
    void callProcLagerFromIspratnica(QWidget * widget, QString text);
    void callProcZiroSmetkiFromIzvod(QWidget * widget, QString text);
	void callProcFakturiFromIzvod(QWidget * widget, QString ziro, int tip);
	void callProcIspratniciFromFakturi(QWidget * widget, QString ziro);
    void on_actionPrinter_triggered();
	void on_actionPreview_triggered();
	void on_actionSearch_triggered();
	void showSearchDialog(QWidget * dest);
	void showUserDialog();
	void showSearchDialogFakturi(QWidget * dest);
	void showSearchDialogVlezniFakturi(QWidget * dest);
	void showSearchDialogPovratnica(QWidget * dest);


	void filePrintPreview(int orient = 0);
	void filePreview(int orient = 0);
    void updateNavigator(QWidget* a, QWidget* b);
	void updatePrinterStat(QWidget* i);
	void disablePrintPreview(bool stat);
	void drawDemo(QPainter& painter);

};

#endif // STERNA_H
