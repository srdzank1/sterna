#include "sterna.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QtCore/qmath.h>
#include <QLocale>
#include "chelperclass.h"
#include <QCryptographicHash>
#include "qperioddialog.h"	
#include <QSettings>

// 

 #define _demo
// #define _juruk_01
// #define _juruk_02
// #define _ekolend
// #define _ekoultima
// #define _bubo
// #define _alea
// #define _doralek
// #define _global
// #define _hsg
//#define _uniparts


//Singleton* us = Singleton::Instance();
//Singleton *us = Config::getInstance();


sterna::sterna(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
    ,m_pageWidth(0)
    ,m_pageHeight(0)
    ,m_pageWidthScale(0)
    ,m_pageHeightScale(0)
    ,m_mykomintenti(0)
    ,m_myartikli(0)
    ,m_left(0)
    ,m_myispratnici(0)
    ,m_mypriemnici(0)
    ,m_mypovratnica(0)
    ,m_myfaktura(0)
    ,m_myfakturavlezna(0)
    ,m_mybanki(0)
    ,m_myddv(0)
    ,m_myizvod(0)	
    ,m_mykasa(0)
    ,m_mykartici(0)
    ,m_mylager(0)
    ,m_mypriem(0)
    ,m_myizvestai(0)
    ,m_myprofakturi(0)
	,m_selectedPrint(-1)
    ,m_mykomintenti_analitika(0)
	,m_myizjava(0)
    ,m_analitikaArtikli(0)
	,m_dnevenpromet(0)
    ,m_analitikaKomintenti(0)
	,m_periodicen(0)
	,m_finanalitikaKomintenti(0)
	,m_myodobrenie(0)
	,m_employe(0)
	,m_smetki(0)
	,m_promena_ceni(0)
	,m_mykalkulacija(0)
	,m_myfaktmaster(0)
	,m_profakturimaster(0)
	,m_povratnicamaster(0)
	,m_popismaster(0)
	,m_porackismetki(0)
{
	ui.setupUi(this);
	
	moi_periodicen = trUtf8("Периодичен Извештај");
	moi_artikli = trUtf8("Артикли");
	moi_banki = trUtf8("Банки");
	moi_ddv = trUtf8("ДДВ");
	moi_faktura = trUtf8("Испратници-Фактури");
    moi_fakturavlezna = trUtf8("Влезни Фактури");
	moi_ispratnici = trUtf8("Испратници");
	moi_izvod = trUtf8("Изводи");
	moi_komintenti = trUtf8("Коминтенти");
	moi_kasa = trUtf8("Каса");
	moi_kartici = trUtf8("Картици");
	moi_lagerlista = trUtf8("Лагер Листа");
	moi_priemlista = trUtf8("Прием на Артикли");
	moi_izvestai = trUtf8("Извештаи");
	moi_povratnica = trUtf8("Повратници");
	moi_priemnici = trUtf8("Приемници");
	moi_kalkulacija = trUtf8("Приемница-Калкулација");
	moi_profakturi = trUtf8("Про-Фактури");
	moi_komintenti_analitika = trUtf8("Аналитика по Коминтент");
	moi_analitikaArtikli = trUtf8("Аналитика по Артикли");
	moi_analitikaKomintenti = trUtf8("Аналитика по Коминтенти");
	moi_finanalitikaKomintenti = trUtf8("Обврски-Финансова Аналитика по Коминтенти");
	moi_odobrenie = trUtf8("Книжно одобрение");
	moi_izjava = trUtf8("Изјава");
	moi_dnevenpromet = trUtf8("Дневен Промет");
	moi_employe = trUtf8("Вработени");
	moi_smetki = trUtf8("Сметки");
	moi_promena_ceni = trUtf8("Извештај за промена на цени");
	moi_faktmaster = trUtf8("Фактури");
	moi_profakturimaster = trUtf8("Про-Фактури");
	moi_povratnicamaster = trUtf8("Повратници");
	moi_popis = trUtf8("Попис");
	moi_porackismetki = trUtf8("Порачки-Сметки");	

	moi_god = QString::number(QDate::currentDate().year(), 10);

#ifdef _demo
	moi_firma_info1 = trUtf8("ДПТУ Демо ДООЕЛ - Скопје");
	moi_firma_info2 = trUtf8("Ул. Скопска  бб");
    moi_firma_info3 = trUtf8("Скопје");
	moi_firma_tel = trUtf8("тел. +389 02/ 3123123");
	moi_firma_email = trUtf8("е-маил: info@website.com.mk");
	moi_firma_web = ("http://www.website.com.mk");
	moi_firma_banka1 = trUtf8("Стопанска банка: DM200001234567890");
	moi_firma_banka2 = trUtf8("ПроКредит банка:  DM380123456789012");
	moi_firma_edb = trUtf8("Даночен број  МК4012345678901");
	moi_logo = ":/sterna/Resources/ddv.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_prefix_prodavnica = "";
    moi_direktor = trUtf8("Демо Директор");
    moi_fakturiral = trUtf8("");

#endif //_demo

#ifdef _juruk_01
	moi_firma_info1 = trUtf8("ДИЗАЈН СТУДИО ЈУРУКОВ ДООЕЛ увоз-извоз  Битола");
	moi_firma_info2 = trUtf8("Ул.Климент Охридски 20 б");
	moi_firma_info3 = trUtf8("Битола");
	moi_firma_tel = trUtf8("тел. (+389 47) 227-833,228-965 ");
	moi_firma_email = trUtf8("е-маил: studiojurukov@gmail.com");
	moi_firma_web = ("http://www.juruklight.com");
	moi_firma_banka1 = trUtf8("");
	moi_firma_banka2 = trUtf8("Стопанска Банка Скопје:200002850612615");
	moi_firma_edb = trUtf8("ЕДБ 400201554058");
	moi_logo = ":/sterna/Resources/jurukov1.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_prefix_prodavnica = "/01";
	moi_direktor = trUtf8("Елена Ј.Раповске");
	moi_fakturiral = trUtf8("");

#endif //_demo
#ifdef _juruk_02
	moi_firma_info1 = trUtf8("ДИЗАЈН СТУДИО ЈУРУКОВ ДООЕЛ увоз-извоз  Битола");
	moi_firma_info2 = trUtf8("Ул.Климент Охридски 20 б");
	moi_firma_info3 = trUtf8("Битола");
	moi_firma_tel = trUtf8("тел. (+389 47) 227-833,228-965 ");
	moi_firma_email = trUtf8("е-маил: studiojurukov@gmail.com");
	moi_firma_web = ("http://www.juruklight.com");
	moi_firma_banka1 = trUtf8("");
	moi_firma_banka2 = trUtf8("Стопанска Банка Скопје:200002850612615");
	moi_firma_edb = trUtf8("ЕДБ 400201554058");
	moi_logo = ":/sterna/Resources/jurukov1.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_prefix_prodavnica = "/02";
	moi_direktor = "";
	moi_fakturiral = "";

#endif //_demo
	
#ifdef _ekolend
	moi_firma_info1 = trUtf8("ДПТУ ЕКОЛЕНД ДООЕЛ - Скопје");
	moi_firma_info2 = trUtf8("Ул. Коце Металец  2a/39");
    moi_firma_info3 = trUtf8("Скопје");
	moi_firma_tel = trUtf8("тел. +389 02/ 3220889");
	moi_firma_email = trUtf8("е-маил: dusan@steeltime.mk");
	moi_firma_web = ("http://www.steeltime.mk");
	moi_firma_banka1 = trUtf8("Стопанска банка: 200001295740930");
	moi_firma_banka2 = trUtf8("ПроКредит банка:  380176911504193");
	moi_firma_edb = trUtf8("Даночен број  МК4011006125146");
	moi_logo = ":/sterna/Resources/microsoft_logo.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно потекло кои ");
	moi_izjava2 = trUtf8("се во моја сопственост__________________________________");
#endif //_ekolend

#ifdef _ekoultima
	moi_firma_info1 = trUtf8("ЕКО УЛТИМА ДООЕЛ ");
	moi_firma_info2 = trUtf8("Ул. Герника бр.1 - Н. Драчево");
	moi_firma_info3 = trUtf8("Скопје");
    moi_firma_tel = trUtf8("тел. +389  077 939 550");
	moi_firma_email = trUtf8("е-маил: ekoultima@gmail.com");
	moi_firma_web = ("");
	moi_firma_banka1 = trUtf8("Охридска Банка: 530-0101014716-33");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("Даночен број  MK4058011510526");
	moi_logo = "";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно потекло ");
	moi_izjava2 = trUtf8("кои се во моја сопственост_________________________");
#endif //_ekoultima

#ifdef _bubo
	moi_firma_info1 = trUtf8("БУ-БО МЕТАЛИКА ДООЕЛ - Скопје");
	moi_firma_info2 = trUtf8("ул. Лука Геров б.б. - Населба Даме Груев - Скопје");
    moi_firma_info3 = trUtf8("Скопје");
	moi_firma_tel = trUtf8("тел/факс +389 02/ 204-4920");
	moi_firma_email = trUtf8("bubometalika@yahoo.com");
	moi_firma_web = ("");
	moi_firma_banka1 = trUtf8("ПроКредит банка:  380276836700116");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("Даночен број  4044010502600");
	moi_logo = "";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно потекло ");
	moi_izjava2 = trUtf8("кои се во моја сопственост_________________________");
#endif // _bubo

#ifdef _alea
    moi_firma_info1 = trUtf8("Т.Д. АЛЕА  ");
    moi_firma_info2 = trUtf8("бул.Јане Сандански бр.25-1/31");
    moi_firma_info3 = trUtf8("1000 Скопје");
    moi_firma_tel = trUtf8("тел. +3892 3296 630");
    moi_firma_email = trUtf8(" e-mail : alea@alea.com.mk");
    moi_firma_web = ("http://www.alea.com.mk");
    moi_firma_banka1 = trUtf8("Стопанска банка: 200000024351745");
    moi_firma_banka2 = trUtf8("Охридска банка: 530010100285129");
    moi_firma_edb = trUtf8("ЕДБ. МК4030993158284");
    moi_logo = ":/sterna/Resources/alea.png";
    moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
    moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_direktor = trUtf8("Недим Куловиќ");
	moi_fakturiral = trUtf8("Недим Куловиќ");

#endif 
	//_demo

#ifdef _doralek
	moi_firma_info1 = trUtf8("Д.T.У. ДОРАЛЕК ДООЕЛ експорт-импорт Скопје ");
	moi_firma_info2 = trUtf8("Адреса: “Коле Неделковски” бр.50");
	moi_firma_info3 = trUtf8("1000  Скопје, Р. Македонија");
	moi_firma_tel = trUtf8("тел: +389 (0)2 3296-715, факс: + 389 (0)2 3296-691");
	moi_firma_email = trUtf8(" e-mail: doralek@t-home.mk");
	moi_firma_web = ("");
	moi_firma_banka1 = trUtf8("НЛБ Тутунска банка: 210064984850150");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("ЕДБ. МК4080009504557 ");
	moi_logo = ":/sterna/Resources/hsg.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_direktor = "";
	moi_fakturiral = "";

#endif //_demo

#ifdef _global
	moi_firma_info1 = trUtf8("ДТУ ГЛОБАЛ ГРЕЕН РЕЦИКЛИНГ ДООЕЛ увоз-извоз Скопје");
	moi_firma_info2 = trUtf8("ул.Булевар МАКЕДОНСКО-КОСОВСКА БРИГАДА бр.87 ");
	moi_firma_info3 = trUtf8("1000 Скопје - Чаир");
	moi_firma_tel = trUtf8("тел: 076 98 22 22");
	moi_firma_email = trUtf8(" e-mail : ");
	moi_firma_web = ("");
	moi_firma_banka1 = trUtf8("Тутунска банка: 210068436970152");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("ЕДБ. 4082013510513");
	moi_logo = ":/sterna/Resources/ddv3.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_direktor = "";
	moi_fakturiral = "";

#endif 

#ifdef _hsg
	moi_firma_info1 = trUtf8("Хардвер-Софтвер ДОО Скопје");
	moi_firma_info2 = trUtf8("ул.Ацо Караманов бр.11а ");
	moi_firma_info3 = trUtf8("1000 Скопје ");
	moi_firma_tel = trUtf8("тел: 077 707-192");
	moi_firma_email = trUtf8("blagoja.ivanovski.hsg@gmail.com"); 
	moi_firma_web = "";
	moi_firma_banka1 = trUtf8("Тутунска банка: 210-0646143301-32");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("ЕДБ. MK4080009501426");
	moi_logo = ":/sterna/Resources/hsg.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_direktor = "";
	moi_fakturiral = "";

#endif 


#ifdef _uniparts
	moi_firma_info1 = trUtf8("УНИ ПАРТС ДС- ДООЕЛ Скопје");
	moi_firma_info2 = trUtf8("ул.Качанички пат бб ");
	moi_firma_info3 = trUtf8("1000 Скопје ");
	moi_firma_tel = trUtf8("тел/факс: +389 2 2600-232");
	moi_firma_email = trUtf8(" e-mail : mail@uniparts.mk");
	moi_firma_web = ("http://www.uniparts.mk");
	moi_firma_banka1 = trUtf8("Стопанска Банка: 200001401370244");
	moi_firma_banka2 = trUtf8("");
	moi_firma_edb = trUtf8("ЕДБ. MK4030006609571");
	moi_logo = ":/sterna/Resources/uniparts.png";
	moi_izjava1 = trUtf8("Изјавувам дека продавам артикли од домашно");
	moi_izjava2 = trUtf8("потекло кои се во моја сопственост________");
	moi_direktor = "";
	moi_fakturiral = "";

#endif 


	moi_nozici = ":/sterna/Resources/scissors.png";
	connectToDatabase();

#ifdef _alea
	Singleton *s = Singleton::Instance();
	QStringList infoAlea;
	infoAlea << "" << "" << "Admin" << "Alea" << "" << "" << "" << "" << "" << "9999" ;
	s->setUserInfo(infoAlea);
#else
	showUserDialog();
#endif
	Singleton *st = Singleton::Instance();
	QStringList info = st->getUserInfo();
	if(info.size())
	{
		statusBar()->showMessage(tr("Aplikacija Sterna - ")+ info.at(3) + " "+ info.at(4));
	}
	else
	{
		statusBar()->showMessage(tr("Aplikacija Sterna"));
	}
	ui.actionPrinter->setEnabled(false);
	ui.actionPreview->setEnabled(false);
	readSettings();
	readSettingsKalkulacija();
	readSettingsIspratnica();
	readSettingsFaktura();
	readSettingsSmetka();

// 	readSettingsPovratnica();
// 	readSettingsProFaktura();
// 	readSettingsLagerLista();
// 	readSettingsAnalitikaArtikli();
// 	readSettingsObvrski();
}

sterna::~sterna()
{
	writeSettings();
	writeSettingsKalkulacija();
	writeSettingsIspratnica();
	writeSettingsFaktura();
	writeSettingsSmetka();

// 	writeSettingsPovratnica();
// 	writeSettingsProFaktura();
// 	writeSettingsLagerLista();
// 	writeSettingsAnalitikaArtikli();
// 	writeSettingsObvrski();
}


void sterna::writeSettings()
{
	Singleton *s = Singleton::Instance();
	QString m_artikal_settings;
	QString m_komintenti_settings;


	QStringList temp_art = s->getArtikliColumnWidth();
	QStringList temp_kom = s->getKomintentiColumnWidth();


	for (int a = 0; a < temp_art.count(); a++)
	{
		if (a == temp_art.count()-1)
			m_artikal_settings += temp_art.at(a);
		else
			m_artikal_settings += temp_art.at(a) + ";";
	}
	for (int a1 = 0; a1 < temp_kom.count(); a1++)
	{
		if (a1 == temp_kom.count()-1)
			m_komintenti_settings += temp_kom.at(a1);
		else
			m_komintenti_settings += temp_kom.at(a1) + ";";
	}


	QSettings settings("HSG", "SternaX");
	settings.beginGroup("artikli_group");
	settings.setValue("artikli", m_artikal_settings);
	settings.endGroup();

	settings.beginGroup("komintenti_group");
	settings.setValue("komintenti", m_komintenti_settings);
	settings.endGroup();
}
void sterna::writeSettingsKalkulacija()
{
	Singleton *s = Singleton::Instance();
	QString m_kalkulacija_settings;
	QString m_kalkulacija_detail_settings;
	QString m_kalkulacija_vnes;
	QString m_kalkulacija_korekcija;

	QStringList temp_kalk = s->getKalkulacija_ColumnWidth();
	QStringList temp_kalk_detail = s->getKalkulacija_Detail_ColumnWidth();
	QStringList temp_kalk_vnes = s->getKalkulacijaVnes_ColumnWidth();
	QStringList temp_kalk_korekcija = s->getKalkulacijaKorekcija_ColumnWidth();

	for (int a2 = 0; a2 < temp_kalk.count(); a2++)
	{
		if (a2 == temp_kalk.count()-1)
			m_kalkulacija_settings += temp_kalk.at(a2);
		else
			m_kalkulacija_settings += temp_kalk.at(a2) + ";";
	}

	for (int a2 = 0; a2 < temp_kalk_detail.count(); a2++)
	{
		if (a2 == temp_kalk_detail.count()-1)
			m_kalkulacija_detail_settings += temp_kalk_detail.at(a2);
		else
			m_kalkulacija_detail_settings += temp_kalk_detail.at(a2) + ";";
	}

	for (int a3 = 0; a3 < temp_kalk_vnes.count(); a3++)
	{
		if (a3 == temp_kalk_vnes.count()-1)
			m_kalkulacija_vnes += temp_kalk_vnes.at(a3);
		else
			m_kalkulacija_vnes += temp_kalk_vnes.at(a3) + ";";
	}

	for (int a4 = 0; a4 < temp_kalk_korekcija.count(); a4++)
	{
		if (a4 == temp_kalk_korekcija.count()-1)
			m_kalkulacija_korekcija += temp_kalk_korekcija.at(a4);
		else
			m_kalkulacija_korekcija += temp_kalk_korekcija.at(a4) + ";";
	}

	QSettings settings("HSG", "SternaX");
	settings.beginGroup("kalkulacija_group");
	settings.setValue("kalkulacija", m_kalkulacija_settings);
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	settings.setValue("kalkulacija_detail", m_kalkulacija_detail_settings);
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	settings.setValue("kalkulacija_vnes", m_kalkulacija_vnes);
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	settings.setValue("kalkulacija_korekcija", m_kalkulacija_korekcija);
	settings.endGroup();
}
void sterna::writeSettingsIspratnica()
{
	Singleton *s = Singleton::Instance();
	QString m_ispratnica_settings;
	QString m_ispratnica_detail_settings;
	QString m_ispratnica_vnes;
	QString m_ispratnica_korekcija;

	QStringList temp_ispratnica = s->getIspratnica_ColumnWidth();
	QStringList temp_ispratnica_detail = s->getIspratnica_Detail_ColumnWidth();
	QStringList temp_ispratnica_vnes = s->getIspratnicaVnes_ColumnWidth();
	QStringList temp_ispratnica_korekcija = s->getIspratnicaKorekcija_ColumnWidth();

	for (int a2 = 0; a2 < temp_ispratnica.count(); a2++)
	{
		if (a2 == temp_ispratnica.count()-1)
			m_ispratnica_settings += temp_ispratnica.at(a2);
		else
			m_ispratnica_settings += temp_ispratnica.at(a2) + ";";
	}

	for (int a2 = 0; a2 < temp_ispratnica_detail.count(); a2++)
	{
		if (a2 == temp_ispratnica_detail.count()-1)
			m_ispratnica_detail_settings += temp_ispratnica_detail.at(a2);
		else
			m_ispratnica_detail_settings += temp_ispratnica_detail.at(a2) + ";";
	}

	for (int a3 = 0; a3 < temp_ispratnica_vnes.count(); a3++)
	{
		if (a3 == temp_ispratnica_vnes.count()-1)
			m_ispratnica_vnes += temp_ispratnica_vnes.at(a3);
		else
			m_ispratnica_vnes += temp_ispratnica_vnes.at(a3) + ";";
	}

	for (int a4 = 0; a4 < temp_ispratnica_korekcija.count(); a4++)
	{
		if (a4 == temp_ispratnica_korekcija.count()-1)
			m_ispratnica_korekcija += temp_ispratnica_korekcija.at(a4);
		else
			m_ispratnica_korekcija += temp_ispratnica_korekcija.at(a4) + ";";
	}

	QSettings settings("HSG", "SternaX");
	settings.beginGroup("ispratnica_group");
	settings.setValue("ispratnica", m_ispratnica_settings);
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	settings.setValue("ispratnica_detail", m_ispratnica_detail_settings);
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	settings.setValue("ispratnica_vnes", m_ispratnica_vnes);
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	settings.setValue("ispratnica_korekcija", m_ispratnica_korekcija);
	settings.endGroup();
}
void sterna::writeSettingsFaktura()
{
	Singleton *s = Singleton::Instance();
	QString m_Faktura_settings;
	QString m_Faktura_detail_settings;
	QString m_Faktura_vnes;
	QString m_Faktura_korekcija;

	QStringList temp_Faktura = s->getFaktura_ColumnWidth();
	QStringList temp_Faktura_detail = s->getFaktura_Detail_ColumnWidth();
	QStringList temp_Faktura_vnes = s->getFakturaVnes_ColumnWidth();
	QStringList temp_Faktura_korekcija = s->getFakturaKorekcija_ColumnWidth();

	for (int a2 = 0; a2 < temp_Faktura.count(); a2++)
	{
		if (a2 == temp_Faktura.count()-1)
			m_Faktura_settings += temp_Faktura.at(a2);
		else
			m_Faktura_settings += temp_Faktura.at(a2) + ";";
	}

	for (int a2 = 0; a2 < temp_Faktura_detail.count(); a2++)
	{
		if (a2 == temp_Faktura_detail.count()-1)
			m_Faktura_detail_settings += temp_Faktura_detail.at(a2);
		else
			m_Faktura_detail_settings += temp_Faktura_detail.at(a2) + ";";
	}

	for (int a3 = 0; a3 < temp_Faktura_vnes.count(); a3++)
	{
		if (a3 == temp_Faktura_vnes.count()-1)
			m_Faktura_vnes += temp_Faktura_vnes.at(a3);
		else
			m_Faktura_vnes += temp_Faktura_vnes.at(a3) + ";";
	}

	for (int a4 = 0; a4 < temp_Faktura_korekcija.count(); a4++)
	{
		if (a4 == temp_Faktura_korekcija.count()-1)
			m_Faktura_korekcija += temp_Faktura_korekcija.at(a4);
		else
			m_Faktura_korekcija += temp_Faktura_korekcija.at(a4) + ";";
	}

	QSettings settings("HSG", "SternaX");
	settings.beginGroup("faktura_group");
	settings.setValue("faktura", m_Faktura_settings);
	settings.endGroup();

	settings.beginGroup("faktura_group");
	settings.setValue("faktura_detail", m_Faktura_detail_settings);
	settings.endGroup();

	settings.beginGroup("faktura_group");
	settings.setValue("faktura_vnes", m_Faktura_vnes);
	settings.endGroup();

	settings.beginGroup("faktura_group");
	settings.setValue("faktura_korekcija", m_Faktura_korekcija);
	settings.endGroup();
}
void sterna::writeSettingsProFaktura()
{
	Singleton *s = Singleton::Instance();
	QString m_ProFaktura_settings;
	QString m_ProFaktura_detail_settings;
	QString m_ProFaktura_vnes;
	QString m_ProFaktura_korekcija;

	QStringList temp_ProFaktura = s->getProFaktura_ColumnWidth();
	QStringList temp_ProFaktura_detail = s->getProFaktura_Detail_ColumnWidth();
	QStringList temp_ProFaktura_vnes = s->getProFakturaVnes_ColumnWidth();
	QStringList temp_ProFaktura_korekcija = s->getProFakturaKorekcija_ColumnWidth();

	for (int a2 = 0; a2 < temp_ProFaktura.count(); a2++)
	{
		if (a2 == temp_ProFaktura.count()-1)
			m_ProFaktura_settings += temp_ProFaktura.at(a2);
		else
			m_ProFaktura_settings += temp_ProFaktura.at(a2) + ";";
	}

	for (int a2 = 0; a2 < temp_ProFaktura_detail.count(); a2++)
	{
		if (a2 == temp_ProFaktura_detail.count()-1)
			m_ProFaktura_detail_settings += temp_ProFaktura_detail.at(a2);
		else
			m_ProFaktura_detail_settings += temp_ProFaktura_detail.at(a2) + ";";
	}

	for (int a3 = 0; a3 < temp_ProFaktura_vnes.count(); a3++)
	{
		if (a3 == temp_ProFaktura_vnes.count()-1)
			m_ProFaktura_vnes += temp_ProFaktura_vnes.at(a3);
		else
			m_ProFaktura_vnes += temp_ProFaktura_vnes.at(a3) + ";";
	}

	for (int a4 = 0; a4 < temp_ProFaktura_korekcija.count(); a4++)
	{
		if (a4 == temp_ProFaktura_korekcija.count()-1)
			m_ProFaktura_korekcija += temp_ProFaktura_korekcija.at(a4);
		else
			m_ProFaktura_korekcija += temp_ProFaktura_korekcija.at(a4) + ";";
	}

	QSettings settings("HSG", "SternaX");
	settings.beginGroup("profaktura_group");
	settings.setValue("profaktura", m_ProFaktura_settings);
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	settings.setValue("profaktura_detail", m_ProFaktura_detail_settings);
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	settings.setValue("profaktura_vnes", m_ProFaktura_vnes);
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	settings.setValue("profaktura_korekcija", m_ProFaktura_korekcija);
	settings.endGroup();
}
void sterna::writeSettingsSmetka()
{
	Singleton *s = Singleton::Instance();
	QString m_Smetka_settings;
	QString m_Smetka_detail_settings;
	QString m_Smetka_vnes;
	QString m_Smetka_korekcija;

	QStringList temp_Smetka = s->getSmetka_ColumnWidth();
	QStringList temp_Smetka_detail = s->getSmetka_Detail_ColumnWidth();
	QStringList temp_Smetka_vnes = s->getSmetkaVnes_ColumnWidth();
	QStringList temp_Smetka_korekcija = s->getSmetkaKorekcija_ColumnWidth();

	for (int a2 = 0; a2 < temp_Smetka.count(); a2++)
	{
		if (a2 == temp_Smetka.count()-1)
			m_Smetka_settings += temp_Smetka.at(a2);
		else
			m_Smetka_settings += temp_Smetka.at(a2) + ";";
	}

	for (int a2 = 0; a2 < temp_Smetka_detail.count(); a2++)
	{
		if (a2 == temp_Smetka_detail.count()-1)
			m_Smetka_detail_settings += temp_Smetka_detail.at(a2);
		else
			m_Smetka_detail_settings += temp_Smetka_detail.at(a2) + ";";
	}

	for (int a3 = 0; a3 < temp_Smetka_vnes.count(); a3++)
	{
		if (a3 == temp_Smetka_vnes.count()-1)
			m_Smetka_vnes += temp_Smetka_vnes.at(a3);
		else
			m_Smetka_vnes += temp_Smetka_vnes.at(a3) + ";";
	}

	for (int a4 = 0; a4 < temp_Smetka_korekcija.count(); a4++)
	{
		if (a4 == temp_Smetka_korekcija.count()-1)
			m_Smetka_korekcija += temp_Smetka_korekcija.at(a4);
		else
			m_Smetka_korekcija += temp_Smetka_korekcija.at(a4) + ";";
	}

	QSettings settings("HSG", "SternaX");
	settings.beginGroup("smetka_group");
	settings.setValue("smetka", m_Smetka_settings);
	settings.endGroup();

	settings.beginGroup("smetka_group");
	settings.setValue("smetka_detail", m_Smetka_detail_settings);
	settings.endGroup();

	settings.beginGroup("smetka_group");
	settings.setValue("smetka_vnes", m_Smetka_vnes);
	settings.endGroup();

	settings.beginGroup("smetka_group");
	settings.setValue("smetka_korekcija", m_Smetka_korekcija);
	settings.endGroup();
}



void sterna::readSettings()
{
	Singleton *s = Singleton::Instance();
	QString m_artikal_settings;
	QString m_komintenti_settings;


	QSettings settings("HSG", "SternaX");
	settings.beginGroup("artikli_group");
	m_artikal_settings = settings.value("artikli").toString();
	settings.endGroup();

	settings.beginGroup("komintenti_group");
	m_komintenti_settings = settings.value("komintenti").toString();
	settings.endGroup();

	s->setArtikliColumnWidth(m_artikal_settings.split(";"));
	s->setKomintentiColumnWidth(m_komintenti_settings.split(";"));
}
void sterna::readSettingsKalkulacija()
{
	Singleton *s = Singleton::Instance();
	QString m_kalkulacija_settings;
	QString m_kalkulacija_detail_settings;
	QString m_kalkulacija_vnes_settings;
	QString m_kalkulacija_korekcija_settings;

	QSettings settings("HSG", "SternaX");

	settings.beginGroup("kalkulacija_group");
	m_kalkulacija_settings = settings.value("kalkulacija").toString();
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	m_kalkulacija_detail_settings = settings.value("kalkulacija_detail").toString();
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	m_kalkulacija_vnes_settings = settings.value("kalkulacija_vnes").toString();
	settings.endGroup();

	settings.beginGroup("kalkulacija_group");
	m_kalkulacija_korekcija_settings = settings.value("kalkulacija_korekcija").toString();
	settings.endGroup();

	s->setKalkulacija_ColumnWidth(m_kalkulacija_settings.split(";"));
	s->setKalkulacija_Detail_ColumnWidth(m_kalkulacija_detail_settings.split(";"));
	s->setKalkulacijaVnes_ColumnWidth(m_kalkulacija_vnes_settings.split(";"));
	s->setKalkulacijaKorekcija_ColumnWidth(m_kalkulacija_korekcija_settings.split(";"));
}
void sterna::readSettingsIspratnica()
{
	Singleton *s = Singleton::Instance();

	QString m_ispratnica_settings;
	QString m_ispratnica_detail_settings;
	QString m_ispratnica_vnes_settings;
	QString m_ispratnica_korekcija_settings;

	QSettings settings("HSG", "SternaX");

	settings.beginGroup("ispratnica_group");
	m_ispratnica_settings = settings.value("ispratnica").toString();
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	m_ispratnica_detail_settings = settings.value("ispratnica_detail").toString();
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	m_ispratnica_vnes_settings = settings.value("ispratnica_vnes").toString();
	settings.endGroup();

	settings.beginGroup("ispratnica_group");
	m_ispratnica_korekcija_settings = settings.value("ispratnica_korekcija").toString();
	settings.endGroup();

	s->setIspratnica_ColumnWidth(m_ispratnica_settings.split(";"));
	s->setIspratnica_Detail_ColumnWidth(m_ispratnica_detail_settings.split(";"));
	s->setIspratnicaVnes_ColumnWidth(m_ispratnica_vnes_settings.split(";"));
	s->setIspratnicaKorekcija_ColumnWidth(m_ispratnica_korekcija_settings.split(";"));
}
void sterna::readSettingsFaktura()
{
	Singleton *s = Singleton::Instance();

	QString m_Faktura_settings;
	QString m_Faktura_detail_settings;
	QString m_Faktura_vnes_settings;
	QString m_Faktura_korekcija_settings;

	QSettings settings("HSG", "SternaX");

	settings.beginGroup("faktura_group");
	m_Faktura_settings = settings.value("faktura").toString();
	settings.endGroup();

	settings.beginGroup("faktura_group");
	m_Faktura_detail_settings = settings.value("faktura_detail").toString();
	settings.endGroup();

	settings.beginGroup("faktura_group");
	m_Faktura_vnes_settings = settings.value("faktura_vnes").toString();
	settings.endGroup();

	settings.beginGroup("faktura_group");
	m_Faktura_korekcija_settings = settings.value("faktura_korekcija").toString();
	settings.endGroup();

	s->setFaktura_ColumnWidth(m_Faktura_settings.split(";"));
	s->setFaktura_Detail_ColumnWidth(m_Faktura_detail_settings.split(";"));
	s->setFakturaVnes_ColumnWidth(m_Faktura_vnes_settings.split(";"));
	s->setFakturaKorekcija_ColumnWidth(m_Faktura_korekcija_settings.split(";"));
}
void sterna::readSettingsProFaktura()
{
	Singleton *s = Singleton::Instance();

	QString m_ProFaktura_settings;
	QString m_ProFaktura_detail_settings;
	QString m_ProFaktura_vnes_settings;
	QString m_ProFaktura_korekcija_settings;

	QSettings settings("HSG", "SternaX");

	settings.beginGroup("profaktura_group");
	m_ProFaktura_settings = settings.value("profaktura").toString();
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	m_ProFaktura_detail_settings = settings.value("profaktura_detail").toString();
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	m_ProFaktura_vnes_settings = settings.value("profaktura_vnes").toString();
	settings.endGroup();

	settings.beginGroup("profaktura_group");
	m_ProFaktura_korekcija_settings = settings.value("profaktura_korekcija").toString();
	settings.endGroup();

	s->setProFaktura_ColumnWidth(m_ProFaktura_settings.split(";"));
	s->setProFaktura_Detail_ColumnWidth(m_ProFaktura_detail_settings.split(";"));
	s->setProFakturaVnes_ColumnWidth(m_ProFaktura_vnes_settings.split(";"));
	s->setProFakturaKorekcija_ColumnWidth(m_ProFaktura_korekcija_settings.split(";"));
}
void sterna::readSettingsSmetka()
{
	Singleton *s = Singleton::Instance();

	QString m_Smetka_settings;
	QString m_Smetka_detail_settings;
	QString m_Smetka_vnes_settings;
	QString m_Smetka_korekcija_settings;

	QSettings settings("HSG", "SternaX");

	settings.beginGroup("smetka_group");
	m_Smetka_settings = settings.value("smetka").toString();
	settings.endGroup();

	settings.beginGroup("smetka_group");
	m_Smetka_detail_settings = settings.value("smetka_detail").toString();
	settings.endGroup();

	settings.beginGroup("smetka_group");
	m_Smetka_vnes_settings = settings.value("smetka_vnes").toString();
	settings.endGroup();

	settings.beginGroup("smetka_group");
	m_Smetka_korekcija_settings = settings.value("smetka_korekcija").toString();
	settings.endGroup();

	s->setSmetka_ColumnWidth(m_Smetka_settings.split(";"));
	s->setSmetka_Detail_ColumnWidth(m_Smetka_detail_settings.split(";"));
	s->setSmetkaVnes_ColumnWidth(m_Smetka_vnes_settings.split(";"));
	s->setSmetkaKorekcija_ColumnWidth(m_Smetka_korekcija_settings.split(";"));
}



void sterna::createDockWindows()
{
    dock = new QDockWidget(this);
    dock->setWindowTitle(tr("Navigate"));
    dock->setFixedWidth(210);
    dock->setFixedHeight(500);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_left = new QLeft(dock);
    dock->setWidget(m_left);
	addDockWidget(Qt::LeftDockWidgetArea, dock);
	connect(m_left, SIGNAL(updatePrinterStatus(QWidget*)), this, SLOT(updatePrinterStat(QWidget*)));
	QDesktopWidget *desk = new QDesktopWidget();
	QRect screenRect = desk->screenGeometry();
	int  mLeftW = m_left->width();
	QRect rMain = QRect(0, 0, screenRect.width() - mLeftW, screenRect.height() - 100);
	Singleton *s = Singleton::Instance();
	s->setMainRect(rMain);

}

void sterna::updatePrinterStat(QWidget* i)
{
	if (qobject_cast<QMyIspratnici*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
		((QMyIspratnici*)i)->refreshLista();
	}
	else if (qobject_cast<QMyPriemnica*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
	else if (qobject_cast<QMyprofakturimaster*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
	else if (qobject_cast<QMySmetki*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}

	else if (qobject_cast<QMyfaktmaster*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
		((QMyfaktmaster*)i)->refreshLista();
	}

	else if (qobject_cast<QMyKomintenti*>(i))
	{
		ui.actionPrinter->setEnabled(false);
		ui.actionPreview->setEnabled(false);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QMyArtikli*>(i))
	{
		ui.actionPrinter->setEnabled(false);
		ui.actionPreview->setEnabled(false);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QMypovratnicamaster*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QLager*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
		((QLager*)i)->refreshLista();
	}

	else if (qobject_cast<QPeriodicenIzvestaj*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
	else if (qobject_cast<QMyFakturi*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QFakturiVlezni*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QDnevenpromet*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
	else if (qobject_cast<QMyKasa*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
	else if (qobject_cast<QMyIzjava*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(false);
	}
    else if (qobject_cast<QAnalitikaArtikli*>(i))
    {
        ui.actionPrinter->setEnabled(true);
        ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
    }
    else if (qobject_cast<QAnalitikaKomintenti*>(i))
    {
        ui.actionPrinter->setEnabled(true);
        ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QFinAnalitKomintenti*>(i))
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
		ui.actionSearch->setEnabled(true);
	}
	else if (qobject_cast<QMyKalkulacija*>(i))
	{
		ui.actionPrinter->setEnabled(false);
		ui.actionPreview->setEnabled(false);
		ui.actionSearch->setEnabled(true);
	}
	else
	{
		ui.actionPrinter->setEnabled(false);
		ui.actionPreview->setEnabled(false);
		ui.actionSearch->setEnabled(false);
	}
}

void sterna::disablePrintPreview(bool stat)
{
	if (stat)
	{
		ui.actionPrinter->setEnabled(false);
		ui.actionPreview->setEnabled(false);
	}
	else
	{
		ui.actionPrinter->setEnabled(true);
		ui.actionPreview->setEnabled(true);
	}
}

void sterna::on_actionLager_triggered()
{
    m_mylager = showMyWidget<QLager, QWidget, QWidget>(m_mylager, moi_lagerlista, ui.centralWidget, NULL);
//     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
//     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
}

void sterna::on_actionPeriodicenIzvestaj_triggered()
{
	m_periodicen = showMyWidget<QPeriodicenIzvestaj, QWidget, QWidget>(m_periodicen, moi_periodicen, ui.centralWidget, NULL);
}

void sterna::on_actionPriem_triggered()
{
    m_mypriem = showMyWidget<QPriem, QWidget, QWidget>(m_mypriem, moi_priemlista, ui.centralWidget, NULL);
}


void sterna::on_actionIzvestaPromenaCeni_triggered()
{
	m_promena_ceni = showMyWidget<QPromenaCeni, QWidget, QWidget>(m_promena_ceni, moi_promena_ceni, ui.centralWidget, NULL);
	//     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	//     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
}

void sterna::on_actionDnevenPromet_triggered()
{
	m_dnevenpromet = showMyWidget<QDnevenpromet, QWidget, QWidget>(m_dnevenpromet, moi_dnevenpromet, ui.centralWidget, NULL);
//	connect(m_dnevenpromet, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
	//     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	//     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
}

void sterna::on_actionAnalitikaKomintent_triggered()
{
    m_analitikaKomintenti = showMyWidget<QAnalitikaKomintenti, QWidget, QWidget>(m_analitikaKomintenti, moi_analitikaKomintenti, ui.centralWidget, NULL);
    //     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
    //     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
}


void sterna::on_actionFinansova_Kartica_triggered()
{
	m_finanalitikaKomintenti = showMyWidget<QFinAnalitKomintenti, QWidget, QWidget>(m_finanalitikaKomintenti, moi_finanalitikaKomintenti, ui.centralWidget, NULL);
	//     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	//     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
	connect(m_finanalitikaKomintenti, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
}
void sterna::on_actionAnalitikaArtikli_triggered()
{
    m_analitikaArtikli = showMyWidget<QAnalitikaArtikli, QWidget, QWidget>(m_analitikaArtikli, moi_analitikaArtikli, ui.centralWidget, NULL);
    //     connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
    //     connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
}

void sterna::on_actionVraboteni_triggered()
{
	m_employe = showMyWidget<QMyEmploye, QWidget, QWidget>(m_employe, moi_employe, ui.centralWidget, NULL);
}

void sterna::on_action_KomintentiLista_triggered()
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, NULL);
}

void sterna::on_action_MyArtikli_triggered()
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, NULL);
}

void sterna::on_actionMyOdobrenie_triggered()
{
	m_myodobrenie = showMyWidget<QMyOdobrenie, QWidget, QWidget>(m_myodobrenie, moi_odobrenie, ui.centralWidget, NULL);
}

void sterna::on_actionMyIspratnici_triggered()
{
	m_myispratnici = showMyWidget<QMyIspratnici, QWidget, QWidget>(m_myispratnici, moi_ispratnici, ui.centralWidget, NULL);
	ui.actionPrinter->setEnabled(true);
	connect(m_myispratnici, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_myispratnici, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_myispratnici, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_myispratnici, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
	connect(m_myispratnici, SIGNAL(signCallSearchForm()), this, SLOT(callProcCallSearchForm( )));
}

void sterna::callProcCallSearchForm()
{
	 on_actionSearch_triggered();
}

void sterna::on_actionFakturiMaster_triggered()
{
	m_myfaktmaster = showMyWidget<QMyfaktmaster, QWidget, QWidget>(m_myfaktmaster, moi_faktmaster, ui.centralWidget, NULL);
	ui.actionPrinter->setEnabled(true);
	connect(m_myfaktmaster, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_myfaktmaster, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_myfaktmaster, SIGNAL(signIspratnica(QWidget*, QString)), this, SLOT(callProcIspratniciFromFakturi(QWidget*, QString)));
	connect(m_myfaktmaster, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_myfaktmaster, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));

}


void sterna::on_actionMyPriemnici_triggered()
{
	m_mypriemnici = showMyWidget<QMyPriemnica, QWidget, QWidget>(m_mypriemnici, moi_priemnici, ui.centralWidget, NULL);
 	connect(m_mypriemnici, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	connect(m_mypriemnici, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
	connect(m_mypriemnici, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));

}

void sterna::on_actionIzjava_triggered()
{
	m_myizjava = showMyWidget<QMyIzjava, QWidget, QWidget>(m_myizjava, moi_izjava, ui.centralWidget, NULL);
	connect(m_myizjava, SIGNAL(signKomintentiFromIzjava(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	connect(m_myizjava, SIGNAL(signArtikliFromIzjava(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
	connect(m_myizjava, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
    connect(m_myizjava, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}


void sterna::on_actionMyPovratnica_triggered()
{
	m_povratnicamaster = showMyWidget<QMypovratnicamaster, QWidget, QWidget>(m_povratnicamaster, moi_povratnicamaster, ui.centralWidget, NULL);
	connect(m_povratnicamaster, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_povratnicamaster, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_povratnicamaster, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_povratnicamaster, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}


void sterna::on_actionMyFakturi_triggered()
{
	m_myfaktura = showMyWidget<QMyFakturi, QWidget, QWidget>(m_myfaktura, moi_faktura, ui.centralWidget, NULL);
    connect(m_myfaktura, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
    connect(m_myfaktura, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
    connect(m_myfaktura, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_myfaktura, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}

void sterna::on_actionPopis_triggered()
{
	m_popismaster = showMyWidget<QMypopismaster, QWidget, QWidget>(m_popismaster, moi_popis, ui.centralWidget, NULL);
	connect(m_popismaster, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_popismaster, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_popismaster, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_popismaster, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}

void sterna::on_actionSmetki_triggered()
{
	m_smetki = showMyWidget<QMySmetki, QWidget, QWidget>(m_smetki, moi_smetki, ui.centralWidget, NULL);
	connect(m_smetki, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_smetki, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_smetki, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_smetki, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}

void sterna::on_actionPorackiSmetki_triggered()
{
	m_porackismetki = showMyWidget<QMyPorackiSmetki, QWidget, QWidget>(m_porackismetki, moi_porackismetki, ui.centralWidget, NULL);
	connect(m_porackismetki, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_porackismetki, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
	connect(m_porackismetki, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_porackismetki, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}


void sterna::on_actionMyFakturiVlezni_triggered()
{
    m_myfakturavlezna = showMyWidget<QFakturiVlezni, QWidget, QWidget>(m_myfakturavlezna, moi_fakturavlezna, ui.centralWidget, NULL);
    connect(m_myfakturavlezna, SIGNAL(signKomintentiFromPriemnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
    connect(m_myfakturavlezna, SIGNAL(signArtikliFromPriemnica(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
    connect(m_myfakturavlezna, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
}

void sterna::on_actionProFaktura_triggered()
{
	m_profakturimaster = showMyWidget<QMyprofakturimaster, QWidget, QWidget>(m_profakturimaster, moi_profakturimaster, ui.centralWidget, NULL);
	connect(m_profakturimaster, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_profakturimaster, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_profakturimaster, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_profakturimaster, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
}

void sterna::on_actionKasi_triggered()
{
    m_mykasa = showMyWidget<QMyKasa, QWidget, QWidget>(m_mykasa, moi_kasa, ui.centralWidget, NULL);
    connect(m_mykasa, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
    connect(m_mykasa, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_mykasa, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	connect(m_mykasa, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
}

void sterna::on_actionKalkulacii_triggered()
{
	m_mykalkulacija = showMyWidget<QMyKalkulacija, QWidget, QWidget>(m_mykalkulacija, moi_kalkulacija, ui.centralWidget, NULL);
	connect(m_mykalkulacija, SIGNAL(signKomintentiFromKalkulacija(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
	connect(m_mykalkulacija, SIGNAL(signArtikliFromKalkulacija(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
	connect(m_mykalkulacija, SIGNAL(signImportArtikliFromKalkulacija(QWidget*, QString)), this, SLOT(callProcPriemnicaFromKalkulacii(QWidget*, QString)));
	connect(m_mykalkulacija, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));

}
void sterna::callProcKalkulacija(QWidget * widget, QString text)
{
	m_mykalkulacija = showMyWidget<QMyKalkulacija, QWidget, QWidget>(m_mykalkulacija, moi_kalkulacija, ui.centralWidget, widget);
	connect(m_mykalkulacija, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	connect(m_mykalkulacija, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_mykalkulacija->raise();
}
void sterna::callProcPriemnicaFromKalkulacii(QWidget * widget, QString text)
{
	m_mypriemnici = showMyWidget<QMyPriemnica, QWidget, QWidget>(m_mypriemnici, moi_priemnici, ui.centralWidget, widget);
	connect(m_mypriemnici, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	connect(m_mypriemnici, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_mypriemnici->raise();
}


void sterna::on_actionBanki_triggered()
{
    m_mybanki = showMyWidget<QMyBanki, QWidget, QWidget>(m_mybanki, moi_banki, ui.centralWidget, NULL);
}

void sterna::on_actionIzvodi_triggered()
{
    m_myizvod = showMyWidget<QMyIzvod, QWidget, QWidget>(m_myizvod, moi_izvod, ui.centralWidget, NULL);
    connect(m_myizvod, SIGNAL(signZiroSmetkiFromIzvod(QWidget*, QString)), this, SLOT(callProcZiroSmetkiFromIzvod(QWidget*, QString)));
	connect(m_myizvod, SIGNAL(signFakturiFromIzvod(QWidget*, QString, int)), this, SLOT(callProcFakturiFromIzvod(QWidget*, QString, int)));
	connect(m_myizvod, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_myizvod, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
}

void sterna::on_actionIzvestai_triggered()
{
    m_myizvestai = showMyWidget<QIzvestai, QWidget, QWidget>(m_myizvestai, moi_izvestai, ui.centralWidget, NULL);
}


void sterna::on_actionClose_triggered()
{
	if (m_left)
	{
		m_left->setFocus();
		m_left->getSelection();
	}
	
	closeMyWidget();
}

/////////////////////////////////////////////////////////////////////////////
void sterna::callProcArtikliFromFaktura(QMyBaseWidget * widget)
{
	QMyFakturi * sourceWidget = qobject_cast<QMyFakturi*>(widget);
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, sourceWidget);
	m_myartikli->pressF2();
}

void sterna::callProcKomintentiFromFaktura(QMyBaseWidget * widget)
{
	QMyFakturi * sourceWidget = qobject_cast<QMyFakturi*>(widget);
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, sourceWidget);
	m_mykomintenti->raise();
}

void sterna::callProcKomintentiFromPriemnica(QWidget * widget, QString text)
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
	connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mykomintenti->setInitSearchText(text);
	m_mykomintenti->raise();
}


void sterna::callProcArtikliFromPriemnica(QWidget * widget, QString text)
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
	connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_myartikli, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_myartikli->setInitSearchText(text);
	m_myartikli->raise();
}

void sterna::callProcFakturiFromPovratnica(QWidget * widget, QString text)
{
	m_myfaktura = showMyWidget<QMyFakturi, QWidget, QWidget>(m_myfaktura, moi_faktura, ui.centralWidget, widget);
	connect(m_myfaktura, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	connect(m_myfaktura, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_myfaktura->setInitSearchTextFaturi(text);
	m_myfaktura->raise();
}


void sterna::callProcKomintentiFromIspratnica(QWidget * widget, QString text)
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
	connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_mykomintenti->setInitSearchText(text);
	m_mykomintenti->raise();
}
void sterna::callProcArtikliFromIspratnica(QWidget * widget, QString text)
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
	connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_myartikli, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_myartikli->setInitSearchText(text);
	m_myartikli->raise();
}

void sterna::callProcLagerFromIspratnica(QWidget * widget, QString text)
{
    m_mylager = showMyWidget<QLager, QWidget, QWidget>(m_mylager, moi_lagerlista, ui.centralWidget, widget);
    connect(m_mylager, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mylager, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mylager->setInitSearchText(text);
    m_mylager->raise();
}



void sterna::callProcKomintentiFromFaktura(QWidget * widget)
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
	connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_mykomintenti->raise();
}
void sterna::callProcArtikliFromFaktura(QWidget * widget)
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
	connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	m_myartikli->raise();
}

void sterna::callProcKomintentiFromPovratnica(QWidget * widget, QString text)
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
	connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_mykomintenti->setInitSearchText(text);
	m_mykomintenti->raise();
}
void sterna::callProcArtikliFromPovratnica(QWidget * widget, QString text)
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
	connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	m_myartikli->raise();
}

void sterna::callProcKomintentiFromProFakturi(QWidget * widget)
{
    m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
    connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mykomintenti->raise();
}
void sterna::callProcArtikliFromProFakturi(QWidget * widget)
{
    m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
    connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
    m_myartikli->raise();
}

void sterna::callProcKomintentiFromKasa(QWidget * widget, QString text)
{
    m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
    connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
    connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mykomintenti->raise();
}

void sterna::callProcZiroSmetkiFromIzvod(QWidget * widget, QString ziro)
{
    m_mybanki = showMyWidget<QMyBanki, QWidget, QWidget>(m_mybanki, moi_banki, ui.centralWidget, widget);
    connect(m_mybanki, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mybanki->setInitSearchText(ziro);
    m_mybanki->raise();
}


void sterna::callProcFakturiFromIzvod(QWidget * widget, QString ziro, int tip)
{
	if (tip == 1)
	{
		m_myfaktura = showMyWidget<QMyFakturi, QWidget, QWidget>(m_myfaktura, moi_faktura, ui.centralWidget, widget);
		connect(m_myfaktura, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
		connect(m_myfaktura, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
		connect(m_myfaktura, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));

		m_myfaktura->setInitSearchText(ziro);
		m_myfaktura->raise();
	}
	else if(tip == 2)
	{
		m_mykalkulacija = showMyWidget<QMyKalkulacija, QWidget, QWidget>(m_mykalkulacija, moi_kalkulacija, ui.centralWidget, widget);
		connect(m_mykalkulacija, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
		connect(m_mykalkulacija, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
		connect(m_mykalkulacija, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));

		m_mykalkulacija->setInitSearchText(ziro, QDateTime::currentDateTime(), QDateTime::currentDateTime());
		m_mykalkulacija->raise();
	}
	else if(tip == 3)
	{
		m_myizjava = showMyWidget<QMyIzjava, QWidget, QWidget>(m_myizjava, moi_izjava, ui.centralWidget, widget);
		connect(m_myizjava, SIGNAL(signKomintentiFromIzjava(QWidget*, QString)), this, SLOT(callProcKomintentiFromPriemnica(QWidget*, QString)));
		connect(m_myizjava, SIGNAL(signArtikliFromIzjava(QWidget*, QString)), this, SLOT(callProcArtikliFromPriemnica(QWidget*, QString)));
		connect(m_myizjava, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
		connect(m_myizjava, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
		m_myizjava->setInitSearchText("");
		m_myizjava->raise();
	}
	else if (tip == 4)
	{
		m_mypovratnica = showMyWidget<QMyPovratnica, QWidget, QWidget>(m_mypovratnica, moi_povratnica, ui.centralWidget, widget);
		connect(m_mypovratnica, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
		connect(m_mypovratnica, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
		connect(m_mypovratnica, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));

		m_mypovratnica->setInitSearchText(ziro);
		m_mypovratnica->raise();
	}


}

void sterna::callProcIspratniciFromFakturi(QWidget * widget, QString ziro)
{
	m_myispratnici = showMyWidget<QMyIspratnici, QWidget, QWidget>(m_myispratnici, moi_ispratnici, ui.centralWidget, widget);
	connect(m_myispratnici, SIGNAL(signKomintentiFromIspratnica(QWidget*, QString)), this, SLOT(callProcKomintentiFromIspratnica(QWidget*, QString)));
	connect(m_myispratnici, SIGNAL(signArtikliFromIspratnica(QWidget*, QString)), this, SLOT(callProcLagerFromIspratnica(QWidget*, QString)));
	connect(m_myispratnici, SIGNAL(signPrint()), this, SLOT(filePrintPreview()));
	connect(m_myispratnici, SIGNAL(disablePrint(bool )), this, SLOT(disablePrintPreview(bool )));
	connect(m_myispratnici, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

	m_myispratnici->setInitSearchText(ziro);
	m_myispratnici->raise();
}


void sterna::callProcArtikliFromKasa(QWidget * widget, QString text)
{
	m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
	connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
	connect(m_myartikli, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
	m_myartikli->raise();
}

void sterna::callProcKomintentiFromIzvod(QWidget * widget)
{
	m_mykomintenti = showMyWidget<QMyKomintenti, QWidget, QWidget>(m_mykomintenti, moi_komintenti, ui.centralWidget, widget);
	connect(m_mykomintenti, SIGNAL(eCloseKomintentiFromPriemnica()), this, SLOT(closeMyWidget()));
	connect(m_mykomintenti, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
    m_mykomintenti->raise();
}
void sterna::callProcArtikliFromIzvod(QWidget * widget)
{
    m_myartikli = showMyWidget<QMyArtikli, QWidget, QWidget>(m_myartikli, moi_artikli, ui.centralWidget, widget);
    connect(m_myartikli, SIGNAL(eCloseArtikliFromPriemnica()), this, SLOT(closeMyWidget()));
    m_myartikli->raise();
}

void sterna::on_actionPrinter_triggered()
{
    m_left->getSelection();
	if (qobject_cast<QMyArtikli*>(qApp->focusWidget()))
	{
		if (m_myartikli->getModel())
		{
			m_selectedPrint = SV_ART;
			//filePrintPreview();
		}
	}

	if (qobject_cast<QMyprofakturimaster*>(qApp->focusWidget()))
	{
		if (m_profakturimaster->getModel())
		{
			if (m_profakturimaster->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_PROFAKTURIMASTER_ALL;
				filePrintPreview();
			}
			else
			{
				m_selectedPrint = SV_PROFAKTURIMASTER;
				filePrintPreview();
			}
		}
	}

	if (qobject_cast<QMyKomintenti*>(qApp->focusWidget()))
	{
		if (m_mykomintenti->getModel())
		{
			m_selectedPrint = SV_KOM;
			//filePrintPreview();
		}
	}
	if (qobject_cast<QMyIzjava*>(qApp->focusWidget()))
	{
		if (m_myizjava->getModel())
		{
			m_selectedPrint = SV_IZJ;
			filePrintPreview();
		}
	}

	if (qobject_cast<QDnevenpromet*>(qApp->focusWidget()))
	{
		if (m_dnevenpromet->getModel())
		{
			m_selectedPrint = SV_DNVIZV;
			filePrintPreview();
		}
	}

	if (qobject_cast<QMyIspratnici*>(qApp->focusWidget()))
    {
        if (m_myispratnici->getModel() && m_myispratnici->getModel2())
        {
			if (m_myispratnici->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_ISP_ALL;
				filePrintPreview();
			}
			else
			{
				m_selectedPrint = SV_ISP;
				filePrintPreview();
			}
        }
    }
    if (qobject_cast<QMyPriemnica*>(qApp->focusWidget()))
    {
        if (m_mypriemnici->getModel() && m_mypriemnici->getModel2())
        {
            m_selectedPrint = SV_PRI;
            filePrintPreview();
        }
    }
    if (qobject_cast<QMyPovratnica*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_POV;
    }
    
	if (qobject_cast<QMyFakturi*>(qApp->focusWidget()))
    {
        if (m_myfaktura->getModel() && m_myfaktura->getModel2())
        {
            m_selectedPrint = SV_FKT;
            filePrintPreview();
        }
    }
	 
	if (qobject_cast<QFakturiVlezni*>(qApp->focusWidget()))
	{
		if (m_myfakturavlezna->getModel() && m_myfakturavlezna->getModel2())
		{
			m_selectedPrint = SV_VLFKT;
			filePrintPreview();
		}
	}

// 	if (qobject_cast<QFakturiVlezni*>(qApp->focusWidget()))
// 	{
// 		if (m_myfakturavlezna->getModel() && m_myfakturavlezna->getModel2())
// 		{
// 			m_selectedPrint = SV_FKT_VLEZNA;
// 			filePrintPreview();
// 		}
// 	}
	
	if (qobject_cast<QMyDdv*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_DDV;
    }
    if (qobject_cast<QMyProFakturi*>(qApp->focusWidget()))
    {
        if (m_mypriemnici->getModel() && m_mypriemnici->getModel2())
        {
            m_selectedPrint = SV_PFKT;
            //filePrintPreview();
        }
    }
    if (qobject_cast<QMyKasa*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_SMT;
		//filePrintPreview();
    }

	if (qobject_cast<QMySmetki*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_SMT;
		filePrintPreview();
	}

    if (qobject_cast<QMyBanki*>(qApp->focusWidget()))
    {
        if (m_mykomintenti->getModel())
        {
            m_selectedPrint = SV_BNK;    
         //   filePrintPreview();
        }
        
    }
    if (qobject_cast<QMyIzvod*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_IZV;
    }
    if (qobject_cast<QIzvestai*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_IZVES;
    }
    if (qobject_cast<QLager*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_LGR;
        filePrintPreview();
    }
	if (qobject_cast<QPeriodicenIzvestaj*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_PER_IZV;
		filePrintPreview();
	}

	
	if (qobject_cast<QAnalitikaArtikli*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_ANA;
        filePrintPreview(QPrinter::Landscape);
    }
    if (qobject_cast<QAnalitikaKomintenti*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_ANKOM;
        filePrintPreview();
    }

}

void sterna::on_actionPreview_triggered()
{
	m_left->getSelection();

	if (qobject_cast<QFinAnalitKomintenti*>(qApp->focusWidget()))
	{
		//if (m_myartikli->getModel())
		{
			m_selectedPrint = SV_FIN_A_K;
			filePreview();
		}
	}


	if (qobject_cast<QMyKalkulacija*>(qApp->focusWidget()))
	{
		if (m_mykalkulacija->getModel())
		{
				m_selectedPrint = SV_KALKULACIJA;
				filePreview(QPrinter::Landscape);
		}
	}

	if (qobject_cast<QMyprofakturimaster*>(qApp->focusWidget()))
	{
		if (m_profakturimaster->getModel())
		{
			if (m_profakturimaster->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_PROFAKTURIMASTER_ALL;
				filePreview();
			}
			else
			{
				m_selectedPrint = SV_PROFAKTURIMASTER;
				filePreview();
			}
		}
	}


	if (qobject_cast<QMyfaktmaster*>(qApp->focusWidget()))
	{
		if (m_myfaktmaster->getModel())
		{
			if (m_myfaktmaster->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_FAKTURIMASTER_ALL;
				filePreview();
			}
			else
			{
				m_selectedPrint = SV_FAKTURIMASTER;
				filePreview();
			}
		}
	}

	if (qobject_cast<QMyArtikli*>(qApp->focusWidget()))
	{
		if (m_myartikli->getModel())
		{
			m_selectedPrint = SV_ART;
			//filePrintPreview();
		}
	}

	if (qobject_cast<QMyPovratnica*>(qApp->focusWidget()))
	{
		if (m_mypovratnica->getModel())
		{
			m_selectedPrint = SV_POV;
			filePreview();
		}
	}

	if (qobject_cast<QMyKomintenti*>(qApp->focusWidget()))
	{
		if (m_mykomintenti->getModel())
		{
			m_selectedPrint = SV_KOM;
			//filePrintPreview();
		}
	}
	if (qobject_cast<QMyIzjava*>(qApp->focusWidget()))
	{
		if (m_myizjava->getModel())
		{
			m_selectedPrint = SV_IZJ;
			filePreview();
		}
	}

	if (qobject_cast<QDnevenpromet*>(qApp->focusWidget()))
	{
		if (m_dnevenpromet->getModel())
		{
			m_selectedPrint = SV_DNVIZV;
			filePreview();
		}
	}

	if (qobject_cast<QMyIspratnici*>(qApp->focusWidget()))
	{
		if (m_myispratnici->getModel() && m_myispratnici->getModel2())
		{
			if (m_myispratnici->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_ISP_ALL;
				filePreview();
			}
			else
			{
				m_selectedPrint = SV_ISP;
				filePreview();
			}
		}
	}
	if (qobject_cast<QMyPriemnica*>(qApp->focusWidget()))
	{
		if (m_mypriemnici->getModel() && m_mypriemnici->getModel2())
		{
			m_selectedPrint = SV_PRI;
			filePreview();
		}
	}
	if (qobject_cast<QMypovratnicamaster*>(qApp->focusWidget()))
	{
		if (m_povratnicamaster->getModel() && m_povratnicamaster->getModel2())
		{
			m_selectedPrint = SV_POV;
			filePreview();
		}
	}

	if (qobject_cast<QMyFakturi*>(qApp->focusWidget()))
	{
		if (m_myfaktura->getModel() && m_myfaktura->getModel2())
		{
			if (m_myfaktura->isCheckedDetailFaktura())
			{
				m_selectedPrint = SV_FKT_ALL;
				filePreview();
			}
			else
			{
				m_selectedPrint = SV_FKT;
				filePreview();
			}
		}
	}
	if (qobject_cast<QFakturiVlezni*>(qApp->focusWidget()))
	{
		if (m_myfakturavlezna->getModel() && m_myfakturavlezna->getModel2())
		{
			m_selectedPrint = SV_VLFKT;
			filePreview();
		}
	}

	if (qobject_cast<QMyDdv*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_DDV;
	}
	if (qobject_cast<QMyProFakturi*>(qApp->focusWidget()))
	{
		if (m_mypriemnici->getModel() && m_mypriemnici->getModel2())
		{
			m_selectedPrint = SV_PFKT;
			//filePrintPreview();
		}
	}
	if (qobject_cast<QMyKasa*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_SMT;
		filePreview();
	}

	if (qobject_cast<QMyBanki*>(qApp->focusWidget()))
	{
		if (m_mykomintenti->getModel())
		{
			m_selectedPrint = SV_BNK;    
			//   filePrintPreview();
		}

	}
	if (qobject_cast<QMyIzvod*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_IZV;
		//filePreview();
	}
	if (qobject_cast<QIzvestai*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_IZVES;
	}
    if (qobject_cast<QAnalitikaArtikli*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_ANA;
        filePreview(QPrinter::Landscape);
    }

    if (qobject_cast<QAnalitikaKomintenti*>(qApp->focusWidget()))
    {
        m_selectedPrint = SV_ANKOM;
        filePreview();
    }

    
    if (qobject_cast<QLager*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_LGR;
		filePreview();
	}

	if (qobject_cast<QPeriodicenIzvestaj*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_PER_IZV;
		filePreview();
	}
	if (qobject_cast<QMySmetki*>(qApp->focusWidget()))
	{
		m_selectedPrint = SV_SMT;
		//filePreview();s
	}
}

void sterna::showUserDialog()
{
	QUserForm * uf = new QUserForm((QDialog*)this);
	uf->setModal(true);
	if(uf->exec() == QDialog::Accepted)
	{
		CHelperClass *chc = new CHelperClass(this);

		int stop = 0;	
		QString str = uf->ui.lineEdit_2->text();
		QByteArray hash = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
		QString str_pass = QString(hash.toHex());
		QString str_user = uf->ui.lineEdit->text();
		QStringList info = chc->getVraboteniInfo(str_user, str_pass);
		if (info.size())
		{
			Singleton *s = Singleton::Instance();
			s->setUserInfo(info);
			if (info.at(9) == "9999")
			{
				ui.actionVraboteni->setVisible(true);
			} 
			else
			{
				ui.actionVraboteni->setVisible(false);
			}
		} 
		else
		{
			QTimer::singleShot(0, qApp, SLOT(quit()));
		}
	}
	else
	{
		QTimer::singleShot(0, qApp, SLOT(quit()));
	}
}

void sterna::showSearchDialog(QWidget * dest)
{
	QSearchForm * uf = new QSearchForm((QDialog*)this);
	uf->setModal(true);
	connect(uf->ui.lineEdit, SIGNAL(textChanged(const QString & )), dest, SLOT(textChanged(const QString &)));
	if(uf->exec() == QDialog::Accepted)
	{
		int stop = 0;	

	}
}


void sterna::showSearchDialogPovratnica(QWidget * dest)
{
	QSearchFormFaktura * uf = new QSearchFormFaktura((QDialog*)this);
	uf->setModal(true);
	uf->ui.dateTimeEdit->setDate(QDate::currentDate());
	uf->ui.dateTimeEdit_2->setDate(QDate::currentDate());
	connect(uf->ui.lineEdit, SIGNAL(textChanged(const QString & )), dest, SLOT(textChanged(const QString &)));
	connect(uf->ui.dateTimeEdit, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date1Changed( const QDateTime &)));
	connect(uf->ui.dateTimeEdit_2, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date2Changed( const QDateTime &)));

	if(uf->exec() == QDialog::Accepted)
	{
		int stop = 0;	

	}
}


void sterna::showSearchDialogFakturi(QWidget * dest)
{
	QSearchFormFaktura * uf = new QSearchFormFaktura((QDialog*)this);
	uf->setModal(true);
	uf->ui.dateTimeEdit->setDate(QDate::currentDate());
	uf->ui.dateTimeEdit_2->setDate(QDate::currentDate());
	connect(uf->ui.lineEdit, SIGNAL(textChanged(const QString & )), dest, SLOT(textChanged(const QString &)));
	connect(uf->ui.dateTimeEdit, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date1Changed( const QDateTime &)));
	connect(uf->ui.dateTimeEdit_2, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date2Changed( const QDateTime &)));

	if(uf->exec() == QDialog::Accepted)
	{
		int stop = 0;	

	}
}

void sterna::showSearchDialogVlezniFakturi(QWidget * dest)
{
	QSearchFormFaktura * uf = new QSearchFormFaktura((QDialog*)this);
	uf->setModal(true);
	uf->ui.dateTimeEdit->setDate(QDate::currentDate());
	uf->ui.dateTimeEdit_2->setDate(QDate::currentDate());
	connect(uf->ui.lineEdit, SIGNAL(textChanged(const QString & )), dest, SLOT(textChanged(const QString &)));
	connect(uf->ui.dateTimeEdit, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date1Changed( const QDateTime &)));
	connect(uf->ui.dateTimeEdit_2, SIGNAL(dateTimeChanged( const QDateTime & )), dest, SLOT(date2Changed( const QDateTime &)));

	if(uf->exec() == QDialog::Accepted)
	{
		int stop = 0;	

	}
}
void sterna::on_actionDnevnoFiskalnoZatvaranje_triggered()
{
	int stop = 0;
	//call fiscal printer
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Печати ДНЕВНО ФИСКАЛНО ЗАТВАРАЊЕ !!!"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok)
	{
		CHelperClass chlp(this);
		chlp.printFiscalDnevnoFiskalnoZatvoranje();
		QString info5 = chlp.checkFiscal();
		msgBox.setText(trUtf8("ДНЕВНО ФИСКАЛНО ЗАТВАРАЊЕ\nЕ ОТПЕЧАТЕНО  !!!"));
		msgBox.setInformativeText(info5);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}

}

void sterna::on_actionKontrolenIzvestaj_triggered()
{
	int stop = 0;
	//call fiscal printer
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Печати КОНТРОЛЕН ИЗВЕШТАЈ !!!"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok)
	{
		CHelperClass chlp(this);
		chlp.printFiscalDnevnoFiskalnoZatvoranje();
		QString info5 = chlp.checkFiscal();
		msgBox.setText(trUtf8("КОНТРОЛЕН ИЗВЕШТАЈ\nЕ ОТПЕЧАТЕН  !!!"));
		msgBox.setInformativeText(info5);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
}

void sterna::on_actionPodesuvanjeDatumCas_triggered()
{
	int stop = 0;
	//call fiscal printer
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Подесување на ДАТУМ и Час !!!"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok)
	{
		CHelperClass chlp(this);
		chlp.printFiscalPodesuvanjeDatumCas();
		QString info5 = chlp.checkFiscal();
		msgBox.setText(trUtf8("ДАТУМ и Час\nЕ подесен  !!!"));
		msgBox.setInformativeText(info5);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.exec();
	}
}


void sterna::on_actionDetalenIzvestajPoPeriod_triggered()
{
	int stop = 0;
	//call fiscal printer
	QMessageBox msgBox;
	msgBox.setText(trUtf8("Печати ДЕТАЛЕН ИЗВЕШТАЈ ПО ПЕРИОД !!!"));
	msgBox.setInformativeText(trUtf8("Одбери OK за да потврдиш."));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok)
	{
		CHelperClass chlp(this);
//		QPeriodDialog * uf = new QPeriodDialog((QDialog*)this);
//		uf->setModal(true);
//		if(uf->exec() == QDialog::Accepted)
//		{
//			QString date1 = uf->getDate1();
//			QString date2 = uf->getDate2();

//			chlp.printDetalenIzvestajPoPeriod(date1, date2);
//			QString info5 = chlp.checkFiscal();
//			msgBox.setText(trUtf8("ДЕТАЛЕН ИЗВЕШТАЈ ПО ПЕРИОД\nЕ ОТПЕЧАТЕН  !!!"));
//			msgBox.setInformativeText(info5);
//			msgBox.setStandardButtons(QMessageBox::Ok);
//			msgBox.setDefaultButton(QMessageBox::Ok);
//			msgBox.exec();
//		}
	}
}


void sterna::on_actionSearch_triggered()
{
	m_left->getSelection();
	if (qobject_cast<QMyArtikli*>(qApp->focusWidget()))
	{
		if (m_myartikli->getModel())
		{
			showSearchDialog(m_myartikli);		
		}
	}

	if (qobject_cast<QMyPovratnica*>(qApp->focusWidget()))
	{
		if (m_mypovratnica->getModel())
		{
			showSearchDialogPovratnica(m_mypovratnica);		
		}
	}

	if (qobject_cast<QMyKomintenti*>(qApp->focusWidget()))
	{
		if (m_mykomintenti->getModel())
		{
			showSearchDialog(m_mykomintenti);		
		}
	}


	if (qobject_cast<QMyFakturi*>(qApp->focusWidget()))
	{
		if (m_myfaktura->getModel() && m_myfaktura->getModel2())
		{
			showSearchDialogFakturi(m_myfaktura);		
		}
	}

	if (qobject_cast<QMyfaktmaster*>(qApp->focusWidget()))
	{
		if (m_myfaktmaster->getModel() && m_myfaktmaster->getModel2())
		{
			showSearchDialogFakturi(m_myfaktmaster);		
		}
	}

	if (qobject_cast<QMyIspratnici*>(qApp->focusWidget()))
	{
		if (m_myispratnici->getModel() && m_myispratnici->getModel2())
		{
			showSearchDialogFakturi(m_myispratnici);		
		}
	}

	if (qobject_cast<QMyKalkulacija*>(qApp->focusWidget()))
	{
		if (m_mykalkulacija->getModel() && m_mykalkulacija->getModel2())
		{
			showSearchDialogVlezniFakturi(m_mykalkulacija);		
		}
	}

	if (qobject_cast<QMySmetki*>(qApp->focusWidget()))
	{
		if (m_smetki->getModel() && m_smetki->getModel2())
		{
			showSearchDialogVlezniFakturi(m_smetki);		
		}
	}


	if (qobject_cast<QAnalitikaArtikli*>(qApp->focusWidget()))
	{
		showSearchDialog(m_analitikaArtikli);	
	}

	if (qobject_cast<QAnalitikaKomintenti*>(qApp->focusWidget()))
	{
		showSearchDialog(m_analitikaKomintenti);
	}

	if (qobject_cast<QLager*>(qApp->focusWidget()))
	{
		showSearchDialog(m_mylager);	
	}
}


void sterna::closeMyWidget()
{
	if (qobject_cast<QPromenaCeni*>(qApp->focusWidget()))
	{
		deleteMyWidget<QPromenaCeni>((QPromenaCeni*)qApp->focusWidget());
		m_promena_ceni = NULL;
	}

	if (qobject_cast<QMyPorackiSmetki*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyPorackiSmetki>((QMyPorackiSmetki*)qApp->focusWidget());
		m_porackismetki = NULL;
	}

	if (qobject_cast<QMypovratnicamaster*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMypovratnicamaster>((QMypovratnicamaster*)qApp->focusWidget());
		m_povratnicamaster = NULL;
	}

	if (qobject_cast<QMypopismaster*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMypopismaster>((QMypopismaster*)qApp->focusWidget());
		m_popismaster = NULL; 
	}


	if (qobject_cast<QMyfaktmaster*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyfaktmaster>((QMyfaktmaster*)qApp->focusWidget());
		m_myfaktmaster = NULL;
	}
	
	if (qobject_cast<QMyprofakturimaster*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyprofakturimaster>((QMyprofakturimaster*)qApp->focusWidget());
		m_profakturimaster = NULL;
	}

	if (qobject_cast<QMySmetki*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMySmetki>((QMySmetki*)qApp->focusWidget());
		m_smetki = NULL;
	}

	if (qobject_cast<QMyKalkulacija*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyKalkulacija>((QMyKalkulacija*)qApp->focusWidget());
		m_mykalkulacija = NULL;
	}

	if (qobject_cast<QPriem*>(qApp->focusWidget()))
    {
        deleteMyWidget<QPriem>((QPriem*)qApp->focusWidget());
        m_mypriem = NULL;
    }

	if (qobject_cast<QMyEmploye*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyEmploye>((QMyEmploye*)qApp->focusWidget());
		m_employe = NULL;
	}


	if (qobject_cast<QAnalitikaKomintenti*>(qApp->focusWidget()))
	{
		deleteMyWidget<QAnalitikaKomintenti>((QAnalitikaKomintenti*)qApp->focusWidget());
		m_analitikaKomintenti = NULL;
	}

	if (qobject_cast<QMyOdobrenie*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyOdobrenie>((QMyOdobrenie*)qApp->focusWidget());
		m_myodobrenie = NULL;
	}

	if (qobject_cast<QFinAnalitKomintenti*>(qApp->focusWidget()))
	{
		deleteMyWidget<QFinAnalitKomintenti>((QFinAnalitKomintenti*)qApp->focusWidget());
		m_finanalitikaKomintenti = NULL;
	}

	if (qobject_cast<QPeriodicenIzvestaj*>(qApp->focusWidget()))
	{
		deleteMyWidget<QPeriodicenIzvestaj>((QPeriodicenIzvestaj*)qApp->focusWidget());
		m_periodicen = NULL;
	}
    if (qobject_cast<QAnalitikaArtikli*>(qApp->focusWidget()))
    {
        deleteMyWidget<QAnalitikaArtikli>((QAnalitikaArtikli*)qApp->focusWidget());
        m_analitikaArtikli = NULL;
    }
    
    if (qobject_cast<QDnevenpromet*>(qApp->focusWidget()))
	{
		deleteMyWidget<QDnevenpromet>((QDnevenpromet*)qApp->focusWidget());
		m_dnevenpromet = NULL;
	}

	if (qobject_cast<QMyIzjava*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyIzjava>((QMyIzjava*)qApp->focusWidget());
		m_myizjava = NULL;
	}

    if (qobject_cast<QKomintentiAnalitika*>(qApp->focusWidget()))
    {
        deleteMyWidget<QKomintentiAnalitika>((QKomintentiAnalitika*)qApp->focusWidget());
        m_mykomintenti_analitika = NULL;
    }

    if (qobject_cast<QMyArtikli*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyArtikli>((QMyArtikli*)qApp->focusWidget());
		m_myartikli = NULL;
	}
	if (qobject_cast<QMyKomintenti*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyKomintenti>((QMyKomintenti*)qApp->focusWidget());
		m_mykomintenti = NULL;
	}
    if (qobject_cast<QLager*>(qApp->focusWidget()))
    {
        deleteMyWidget<QLager>((QLager*)qApp->focusWidget());
        m_mylager = NULL;
    }
	if (qobject_cast<QMyIspratnici*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyIspratnici>((QMyIspratnici*)qApp->focusWidget());
		m_myispratnici = NULL;
	}

	if (qobject_cast<QMyPriemnica*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyPriemnica>((QMyPriemnica*)qApp->focusWidget());
		m_mypriemnici = NULL;
	}
	if (qobject_cast<QMyPovratnica*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyPovratnica>((QMyPovratnica*)qApp->focusWidget());
		m_mypovratnica = NULL;
	}
	if (qobject_cast<QMyFakturi*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyFakturi>((QMyFakturi*)qApp->focusWidget());
		m_myfaktura = NULL;
	}
    if (qobject_cast<QFakturiVlezni*>(qApp->focusWidget()))
    {
        deleteMyWidget<QFakturiVlezni>((QFakturiVlezni*)qApp->focusWidget());
        m_myfakturavlezna = NULL;
    }
	if (qobject_cast<QMyDdv*>(qApp->focusWidget()))
	{
		deleteMyWidget<QMyDdv>((QMyDdv*)qApp->focusWidget());
		m_myddv = NULL;
	}
    if (qobject_cast<QMyProFakturi*>(qApp->focusWidget()))
    {
        deleteMyWidget<QMyProFakturi>((QMyProFakturi*)qApp->focusWidget());
        m_myprofakturi = NULL;
    }
    if (qobject_cast<QMyKasa*>(qApp->focusWidget()))
    {
        deleteMyWidget<QMyKasa>((QMyKasa*)qApp->focusWidget());
        m_mykasa = NULL;
    }
    if (qobject_cast<QMyBanki*>(qApp->focusWidget()))
    {
        deleteMyWidget<QMyBanki>((QMyBanki*)qApp->focusWidget());
        m_mybanki = NULL;
    }
    if (qobject_cast<QMyIzvod*>(qApp->focusWidget()))
    {
        deleteMyWidget<QMyIzvod>((QMyIzvod*)qApp->focusWidget());
        m_myizvod = NULL;
    }
    if (qobject_cast<QIzvestai*>(qApp->focusWidget()))
    {
        deleteMyWidget<QIzvestai>((QIzvestai*)qApp->focusWidget());
        m_myizvestai = NULL;
    }
}

void sterna::connectToDatabase()
{
	// create database 
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("sterna");
    db.setPassword("zEn");

	if (!db.open()) 
	{
		QMessageBox msgBox;
        msgBox.setText("Connection with database failed !!!"+db.lastError().text());
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();	
	}
	QSqlError a = db.lastError();
}

void sterna::on_actionDDV_triggered()
{
	m_myddv = showMyWidget<QMyDdv, QWidget, QWidget>(m_myddv, moi_ddv, ui.centralWidget, NULL);
}

void sterna::filePrintPreview(int orient)
{
    int m_aleft = 0;
    int m_atop = 0;
    int m_aright = 0;
    int m_abottom = 0;
    QPrinter printer(QPrinter::HighResolution);
    if (orient)
    {
        printer.setOrientation(QPrinter::Landscape);
        m_pageWidth = printer.pageRect().height();  //4961
        m_pageHeight = printer.pageRect().width(); //7016
        m_pageHeightScale = (float)printer.pageRect().height() / 4961.0f;
        m_pageWidthScale = (float)printer.pageRect().width() /7016.0f;
    }
    else
    {
        printer.setOrientation(QPrinter::Portrait);
        m_pageWidth = printer.pageRect().width();  //4961
        m_pageHeight = printer.pageRect().height(); //7016
        m_pageWidthScale = (float)printer.pageRect().width() / 4961.0f;
        m_pageHeightScale = (float)printer.pageRect().height() /7016.0f;
    }

    printer.setPageMargins(m_aleft,m_atop,m_aright,m_abottom,QPrinter::Millimeter);
    printPreview(&printer);
}

void sterna::filePreview(int orient)
{
    int m_aleft = 0;
    int m_atop = 0;
    int m_aright = 0;
    int m_abottom = 0;
    QPrinter printer(QPrinter::HighResolution);
    if (orient)
    {
        printer.setOrientation(QPrinter::Landscape);
        m_pageWidth = printer.pageRect().height();  //4961
        m_pageHeight = printer.pageRect().width(); //7016
        m_pageHeightScale = (float)printer.pageRect().height() / 4961.0f;
        m_pageWidthScale = (float)printer.pageRect().width() /7016.0f;
    }
    else
    {
        printer.setOrientation(QPrinter::Portrait);
        m_pageWidth = printer.pageRect().width();  //4961
        m_pageHeight = printer.pageRect().height(); //7016
        m_pageWidthScale = (float)printer.pageRect().width() / 4961.0f;
        m_pageHeightScale = (float)printer.pageRect().height() /7016.0f;
    }

    printer.setPageMargins(m_aleft,m_atop,m_aright,m_abottom,QPrinter::Millimeter);
    QPrintPreviewDialog preview(&printer, this);
    preview.setWindowFlags(Qt::Window);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
    preview.resize(width(), height());
    preview.exec();
}


void sterna::printPreview(QPrinter *printer)
{

    QPainter painter( printer );
    painter.setPen( Qt::black );

    m_left->getSelection();
	switch (m_selectedPrint)
	{
	case SV_ART: drawArtikliLista(printer, painter); break;
	case SV_KOM: drawKomintentiLista(painter); break;
	case SV_ISP: drawIspratnica(printer, painter); break;
	case SV_ISP_ALL: drawIspratnicaALL(printer, painter); break;
	case SV_PRI: drawPriemnica(printer, painter); break;
	case SV_POV: drawPovratnica(printer, painter); break;
	case SV_FKT: drawFaktura(printer, painter); break;
	case SV_FKT_ALL: drawFakturaALL(printer, painter); break;
	case SV_VLFKT: drawVleznaFaktura(printer, painter); break;
	case SV_FIN_A_K: drawFinAnalitikaKomintenti(printer, painter); break;
	case SV_KALKULACIJA: drawKalkulacija(printer, painter); break;
	case SV_DDV: break;
	case SV_PFKT: drawProFaktura(painter); break;
	case SV_KAS: break;
	case SV_BNK: break;
	case SV_IZV: drawIzvod(printer, painter); break;
	case SV_IZVES: break;
	case SV_LGR: drawLagerLista(printer, painter); break;
	case SV_IZJ: drawIzjava(printer, painter); break;
	case SV_DNVIZV: drawDnevenIzvestaj(printer, painter); break;
    case SV_ANA: drawAnalitikaArtikli(printer, painter); break;
    case SV_ANKOM: drawAnalitikaKomintenti(printer, painter); break;
    case SV_SMT: drawSmetka(printer, painter); break;
	case SV_PER_IZV: draw_PeriodicenIzvestaj(printer, painter); break;
	case SV_PROFAKTURIMASTER : drawProFakturaMaster(printer, painter); break;
	case SV_PROFAKTURIMASTER_ALL : drawProFakturaMaster_all(printer, painter); break;
	case SV_FAKTURIMASTER : drawFakturaMaster(printer, painter); break;
	case SV_FAKTURIMASTER_ALL : drawFakturaMaster_all(printer, painter); break;

	}
}

void sterna::drawHeader(QPainter& painter)
{
    QFont f;
    QPainterPath path;
    f.setPointSize(18);
    painter.setFont(f);
    painter.drawText(relX(30), relY(100), trUtf8("Фактура бр:"));
    f.setPointSize(8);
    painter.setFont(f);
    painter.drawText(relX(20), relY(110), trUtf8("Врз основа на Ваше барање број _____________ од ____________________ Ви се испорачани долунаведените материјали:"));
    QBrush b;
    painter.fillRect(relX(20), relY(120), relX(170), relY(5), QColor(0, 200, 5));
    path.addRect(relX(20), relY(120), relX(170), relY(5));
    path.addRect(relX(20), relY(125), relX(170), relY(5));
    path.addRect(relX(20), relY(130), relX(170), relY(5));
	path.addRect(relX(20), relY(135), relX(170), relY(5));
	path.addRect(relX(20), relY(140), relX(170), relY(5));
	path.addRect(relX(20), relY(145), relX(170), relY(5));
	path.addRect(relX(20), relY(150), relX(170), relY(5));
	path.addRect(relX(20), relY(155), relX(170), relY(5));
	path.addRect(relX(20), relY(160), relX(170), relY(5));
	path.addRect(relX(20), relY(165), relX(170), relY(5));
    path.addRect(relX(20), relY(170), relX(170), relY(5));
    path.addRect(relX(20), relY(170), relX(170), relY(5));
    path.addRect(relX(20), relY(175), relX(170), relY(5));
    path.addRect(relX(20), relY(180), relX(170), relY(5));
    path.addRect(relX(20), relY(185), relX(170), relY(5));
    path.addRect(relX(20), relY(190), relX(170), relY(5));
    path.addRect(relX(20), relY(195), relX(170), relY(5));
    path.addRect(relX(20), relY(200), relX(170), relY(5));
    path.addRect(relX(20), relY(205), relX(170), relY(5));
    path.addRect(relX(20), relY(210), relX(170), relY(5));
    path.addRect(relX(20), relY(215), relX(170), relY(5));

    path.moveTo(relX(21),relY(120));
    path.lineTo(relX(21),relY(220));
    path.moveTo(relX(30),relY(120));
    path.lineTo(relX(30),relY(220));
    path.moveTo(relX(85),relY(120));
    path.lineTo(relX(85),relY(220));
    path.moveTo(relX(100),relY(120));
    path.lineTo(relX(100),relY(220));
    path.moveTo(relX(115),relY(120));
    path.lineTo(relX(115),relY(220));
    path.moveTo(relX(130),relY(120));
    path.lineTo(relX(130),relY(220));
    path.moveTo(relX(160),relY(120));
    path.lineTo(relX(160),relY(220));

    f.setPointSize(8);
    painter.setFont(f);
    painter.drawText(relX(22), relY(124), trUtf8("Рб."));
    painter.drawText(relX(32), relY(124), trUtf8("ОПИС"));
    painter.drawText(relX(87), relY(124), trUtf8("Едм"));
    painter.drawText(relX(102), relY(124), trUtf8("Кол."));
    painter.drawText(relX(117), relY(124), trUtf8("Цена"));
    painter.drawText(relX(132), relY(124), trUtf8("ДДВ"));
    painter.drawText(relX(162), relY(124), trUtf8("Износ со ДДВ"));
    painter.drawRoundedRect(relX(100), relY(45), relX(90), relY(45), relX(3), relY(3), Qt::AbsoluteSize );
    path.moveTo(relX(20),relY(260));
    path.lineTo(relX(70),relY(260));
    path.moveTo(relX(140),relY(260));
    path.lineTo(relX(190),relY(260));
    painter.drawText(relX(25), relY(265), trUtf8("Фактурирал"));
    painter.drawText(relX(145), relY(265), trUtf8("Директор"));
    painter.drawPath(path);
    painter.drawRoundedRect(relX(20), relY(117), relX(170), relY(106), relX(3), relY(3), Qt::AbsoluteSize );

}

void sterna::drawFooter(QPainter& painter)
{
}

int sterna::relX(double x)
{
    return (int) (m_pageWidthScale * 4961 * x * 10 / 2100); //mm 210
}

int sterna::relY(double y)
{
    return (int) (m_pageHeightScale * 7016 *y * 10/ 2970); //mm  297
}
void sterna::drawFakturaVkupno(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myfaktura->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Фактура-Испратница"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Фактура"));
#endif

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		int rok = modelFakturaInfo.at(5).toInt();
		QString separ = modelFakturaInfo.at(3).mid(4,1);
		QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
		dateTimeTemp = dateTimeTemp.addDays(rok);
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(95));
		path.lineTo(relX(200),relY(95));

		path.moveTo(relX(15),relY(90));
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(60),relY(90));
		path.lineTo(relX(60),relY(235));

		path.moveTo(relX(80),relY(90));
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(89),relY(90));
		path.lineTo(relX(89),relY(235));

		path.moveTo(relX(107),relY(90));
		path.lineTo(relX(107),relY(235));

		path.moveTo(relX(117),relY(90));
		path.lineTo(relX(117),relY(235));

		path.moveTo(relX(127),relY(90));
		path.lineTo(relX(127),relY(235));

		path.moveTo(relX(152),relY(90));
		path.lineTo(relX(152),relY(235));

		path.moveTo(relX(175),relY(90));
		path.lineTo(relX(175),relY(235));

		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(17), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(62), relY(94), trUtf8("Кол."));
		painter.drawText(relX(82), relY(94), trUtf8("Едм."));
		painter.drawText(relX(90), relY(94), trUtf8("Цена"));
		painter.drawText(relX(108), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(118), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(129), relY(94), trUtf8("Вкупен Износ"));
		painter.drawText(relX(154), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(177), relY(94), trUtf8("Вк.Износ со ДДВ"));

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(60),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(11), relY(280), trUtf8("Фактурирал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));
		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myfaktura->getModel2();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(54), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(61), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(92), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(107), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(129), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(152), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: painter.drawText(relX(177), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());

						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));

	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
#ifdef _demo
	drawDemo(painter);
#endif

}

void sterna::drawFaktura(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
    int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
    double DDV5 = 0;
    double DDV18 = 0;
    double OsnovicaDDV5 = 0;
    double OsnovicaDDV18 = 0;
    QPen pen;
    QStringList modelFakturaInfo = m_myfaktura->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

	QPainterPath path;

	f.setPointSize(12);
	painter.setFont(f);
	painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
	f.setPointSize(10);
	painter.setFont(f);
	painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);
	    
    QPixmap image1(moi_logo);
    painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

	f.setPointSize(18);
	painter.setFont(f);
	#ifdef _alea
        painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Испратница-Фактура"));
    #endif

    #ifndef _alea
        painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Испратница-Фактура"));
    #endif

	f.setPointSize(8);

	painter.setFont(f);
	
	QString textNumberS = "0000"+modelFakturaInfo.at(4);
	textNumberS = textNumberS.right(4);
	f.setBold(true);
	painter.setFont(f);
    painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS);
	f.setBold(false);
	painter.setFont(f);
	painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
	int rok = modelFakturaInfo.at(5).toInt();
	QString separ = modelFakturaInfo.at(3).mid(4,1);
	QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
	dateTimeTemp = dateTimeTemp.addDays(rok);
    painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
	painter.drawText(relX(15), relY(60), trUtf8("До:"));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
    painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
    painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));
	f.setBold(false);
	painter.setFont(f);

	painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
	painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
	painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

	painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
	path.moveTo(relX(10),relY(97)); //rb
	path.lineTo(relX(200),relY(97));

	path.moveTo(relX(15),relY(90)); //naziv
	path.lineTo(relX(15),relY(235));

	path.moveTo(relX(80),relY(90)); //edm
	path.lineTo(relX(80),relY(235));

	path.moveTo(relX(92),relY(90)); //kol
	path.lineTo(relX(92),relY(235));

	path.moveTo(relX(105),relY(90)); //cena -ddv
	path.lineTo(relX(105),relY(235));

	path.moveTo(relX(120),relY(90));
	path.lineTo(relX(120),relY(235));

	path.moveTo(relX(130),relY(90));
	path.lineTo(relX(130),relY(235));

	path.moveTo(relX(140),relY(90));
	path.lineTo(relX(140),relY(235));

	path.moveTo(relX(160),relY(90));
	path.lineTo(relX(160),relY(235));

	path.moveTo(relX(180),relY(90));
	path.lineTo(relX(180),relY(235));
	
	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(11), relY(94), trUtf8("Рб."));
	painter.drawText(relX(16), relY(94), trUtf8("Опис на артикал - услуга"));
	painter.drawText(relX(81), relY(94), trUtf8("Едм."));
	painter.drawText(relX(93), relY(94), trUtf8("Кол."));
	painter.drawText(relX(106), relY(93), trUtf8("Цена"));
	painter.drawText(relX(106), relY(96), trUtf8("без ДДВ"));
	painter.drawText(relX(121), relY(94), trUtf8("Раб.%"));
	painter.drawText(relX(131), relY(94), trUtf8("ДДВ%"));
	painter.drawText(relX(141), relY(93), trUtf8("Вк.Износ"));
	painter.drawText(relX(141), relY(96), trUtf8("без ДДВ"));
	painter.drawText(relX(161), relY(94), trUtf8("ДДВ Износ"));
	painter.drawText(relX(181), relY(93), trUtf8("Вк.Вредност"));
	painter.drawText(relX(181), relY(96), trUtf8("со ДДВ"));
	f.setPointSize(8);
	painter.setFont(f);

	path.moveTo(relX(10),relY(275));
	path.lineTo(relX(56),relY(275));
	path.moveTo(relX(60),relY(275));
	path.lineTo(relX(108),relY(275));
	path.moveTo(relX(110),relY(275));
	path.lineTo(relX(153),relY(275));
	path.moveTo(relX(155),relY(275));
	path.lineTo(relX(198),relY(275));


	painter.drawText(relX(11), relY(280), trUtf8("Примил"));
	painter.drawText(relX(60), relY(280), trUtf8("Предал"));
	painter.drawText(relX(110), relY(280), trUtf8("Фактурирал"));
	painter.drawText(relX(155), relY(280), trUtf8("Директор"));

	painter.drawText(relX(155), relY(265), trUtf8("МП"));

	path.moveTo(relX(10),relY(249));
	path.lineTo(relX(200),relY(249));
	painter.drawPath(path);
	
	QStandardItemModel * modelFaktura2 = m_myfaktura->getModel2();
	double cenaDDV = 0;
	double DDV = 0;


    if (modelFaktura2)
	{
		int maxRowPage = 21;
		maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
		int pagefrom = page * maxRowPage;
		int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

		for (int row = pagefrom; row < pageto; row++)
		{
			for (int col = 0; col <= 10; col++)
			{
				switch (col)
				{
				case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
				case 1: 
					painter.drawText(relX(16), relY(97 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, trUtf8("Шифра: ") + modelFaktura2->item(row, col )->text());
					painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
					break;
				case 2: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(11), relY(9), Qt::AlignLeft, modelFaktura2->item(row, 4)->text());break;
				case 3: painter.drawText(relX(93), relY(100 + 6 * (row - pagefrom)), relX(12), relY(9), Qt::AlignRight,  modelFaktura2->item(row, 3)->text());break;
				case 4: 
					cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
					DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
					painter.drawText(relX(106), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
					break;
				case 5: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
				case 7: painter.drawText(relX(131), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
                case 8: painter.drawText(relX(141), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
                    if (DDV == 18)
                    {
                        OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
                    } 
                    else if (DDV == 5)
                    {
                        OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
                    }
                    break;

                case 9: painter.drawText(relX(161), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
					ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
                    if (DDV == 18)
                    {
                        DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
                    } 
                    else if (DDV == 5)
                    {
                        DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
                    }
					break;
				case 10: painter.drawText(relX(181), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
					sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						
					break;
				}
			}
		}
	}
	if(page < maxpage - 1)
		printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));
	f.setBold(false);
	painter.setFont(f);
    painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

    painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
    painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

    painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
    painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

    painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
    painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

    painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
    painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));

    
    // 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
    QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
	QString t2 = trUtf8("Рекламации се примаат во рок од 3 дена од приемот на стоката со уреден записник.");
	painter.drawText(relX(10), relY(261), relX(130), relY(6), Qt::AlignLeft, t2);
	QString t3 = trUtf8("Во случај на спор надлежен е Стопански суд.");
	painter.drawText(relX(10), relY(264), relX(130), relY(6), Qt::AlignLeft, t3);

#ifdef _demo
	drawDemo(painter);
#endif
	
}
void sterna::drawProFakturaMaster(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_profakturimaster->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Испратница-Фактура"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Про-Фактура"));
#endif

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);

		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS + moi_prefix_prodavnica);
		f.setBold(false);
		painter.setFont(f);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		int rok = modelFakturaInfo.at(5).toInt();
		QString separ = modelFakturaInfo.at(3).mid(4,1);
		QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
		dateTimeTemp = dateTimeTemp.addDays(rok);
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));
		f.setBold(false);
		painter.setFont(f);

		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(97)); //rb
		path.lineTo(relX(200),relY(97));

		path.moveTo(relX(15),relY(90)); //naziv
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(80),relY(90)); //edm
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(92),relY(90)); //kol
		path.lineTo(relX(92),relY(235));

		path.moveTo(relX(105),relY(90)); //cena -ddv
		path.lineTo(relX(105),relY(235));

		path.moveTo(relX(120),relY(90));
		path.lineTo(relX(120),relY(235));

		path.moveTo(relX(130),relY(90));
		path.lineTo(relX(130),relY(235));

		path.moveTo(relX(140),relY(90));
		path.lineTo(relX(140),relY(235));

		path.moveTo(relX(160),relY(90));
		path.lineTo(relX(160),relY(235));

		path.moveTo(relX(180),relY(90));
		path.lineTo(relX(180),relY(235));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(16), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(81), relY(94), trUtf8("Едм."));
		painter.drawText(relX(93), relY(94), trUtf8("Кол."));
		painter.drawText(relX(106), relY(93), trUtf8("Цена"));
		painter.drawText(relX(106), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(121), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(131), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(141), relY(93), trUtf8("Вк.Износ"));
		painter.drawText(relX(141), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(161), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(181), relY(93), trUtf8("Вк.Вредност"));
		painter.drawText(relX(181), relY(96), trUtf8("со ДДВ"));
		f.setPointSize(8);
		painter.setFont(f);

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(56),relY(275));
		path.moveTo(relX(60),relY(275));
		path.lineTo(relX(108),relY(275));
		path.moveTo(relX(110),relY(275));
		path.lineTo(relX(153),relY(275));
		path.moveTo(relX(155),relY(275));
		path.lineTo(relX(198),relY(275));


		painter.drawText(relX(11), relY(278), trUtf8("Примил и согласен сум"));
		painter.drawText(relX(11), relY(280), trUtf8("со условите од оваа фактура"));

		painter.drawText(relX(60), relY(278), trUtf8("Предал"));
		painter.drawText(relX(110), relY(278), trUtf8("Фактурирал"));
		painter.drawText(relX(155), relY(278), trUtf8(""));
		painter.drawText(relX(110), relY(282), moi_fakturiral);
		painter.drawText(relX(155), relY(282), moi_direktor);


		painter.drawText(relX(140), relY(265), trUtf8("МП"));
		painter.drawText(relX(155), relY(265), trUtf8("Овластено лице"));
		painter.drawText(relX(155), relY(268), trUtf8("за потпис на фактура"));

		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_profakturimaster->getModel2();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
#ifndef _alea
						painter.drawText(relX(16), relY(97 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, trUtf8("Шифра: ") + modelFaktura2->item(row, col )->text());
#endif
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(11), relY(9), Qt::AlignLeft, modelFaktura2->item(row, 4)->text());break;
					case 3: painter.drawText(relX(93), relY(100 + 6 * (row - pagefrom)), relX(12), relY(9), Qt::AlignRight,  modelFaktura2->item(row, 3)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(106), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(131), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(141), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(161), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: painter.drawText(relX(181), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());

						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));
	f.setBold(false);
	painter.setFont(f);
	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
	QString t2 = trUtf8("Рекламации се примаат во рок од 3 дена од приемот на стоката со уреден записник.");
	painter.drawText(relX(10), relY(261), relX(130), relY(6), Qt::AlignLeft, t2);
	QString t3 = trUtf8("Во случај на спор надлежен е Стопански суд.");
	painter.drawText(relX(10), relY(264), relX(130), relY(6), Qt::AlignLeft, t3);

#ifdef _demo
	drawDemo(painter);
#endif

}
void sterna::drawFakturaMaster(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	double RabatIznos = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myfaktmaster->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Фактура-Испратница"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Фактура"));
#endif

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(140), relY(35), relX(60), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(140), relY(40), relX(60), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(140), relY(45), relX(60), relY(50), Qt::AlignRight, moi_firma_web);

		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(140), relY(60), relX(60), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS + moi_prefix_prodavnica);
		f.setBold(false);
		painter.setFont(f);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		int rok = modelFakturaInfo.at(5).toInt();
		QString separ = modelFakturaInfo.at(3).mid(4,1);
		QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
		dateTimeTemp = dateTimeTemp.addDays(rok);
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));
		f.setBold(false);
		painter.setFont(f);

		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(97)); //rb
		path.lineTo(relX(200),relY(97));

		path.moveTo(relX(15),relY(90)); //naziv
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(80),relY(90)); //edm
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(92),relY(90)); //kol
		path.lineTo(relX(92),relY(235));

		path.moveTo(relX(105),relY(90)); //cena -ddv
		path.lineTo(relX(105),relY(235));

		path.moveTo(relX(120),relY(90));
		path.lineTo(relX(120),relY(235));

		path.moveTo(relX(130),relY(90));
		path.lineTo(relX(130),relY(235));

		path.moveTo(relX(140),relY(90));
		path.lineTo(relX(140),relY(235));

		path.moveTo(relX(160),relY(90));
		path.lineTo(relX(160),relY(235));

		path.moveTo(relX(180),relY(90));
		path.lineTo(relX(180),relY(235));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(16), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(81), relY(94), trUtf8("Едм."));
		painter.drawText(relX(93), relY(94), trUtf8("Кол."));
		painter.drawText(relX(106), relY(93), trUtf8("Цена"));
		painter.drawText(relX(106), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(121), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(131), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(141), relY(93), trUtf8("Вк.Износ"));
		painter.drawText(relX(141), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(161), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(181), relY(93), trUtf8("Вк.Вредност"));
		painter.drawText(relX(181), relY(96), trUtf8("со ДДВ"));
		f.setPointSize(8);
		painter.setFont(f);

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(56),relY(275));
		path.moveTo(relX(60),relY(275));
		path.lineTo(relX(108),relY(275));
		path.moveTo(relX(110),relY(275));
		path.lineTo(relX(153),relY(275));
		path.moveTo(relX(155),relY(275));
		path.lineTo(relX(198),relY(275));


		painter.drawText(relX(11), relY(278), trUtf8("Примил и согласен сум"));
		painter.drawText(relX(11), relY(280), trUtf8("со условите од оваа фактура"));

		painter.drawText(relX(60), relY(278), trUtf8("Предал"));
		painter.drawText(relX(110), relY(278), trUtf8("Фактурирал"));
		painter.drawText(relX(155), relY(278), trUtf8(""));
		painter.drawText(relX(110), relY(282), moi_fakturiral);
		painter.drawText(relX(155), relY(282), moi_direktor);


		painter.drawText(relX(140), relY(265), trUtf8("МП"));
		painter.drawText(relX(155), relY(265), trUtf8("Овластено лице"));
		painter.drawText(relX(155), relY(268), trUtf8("за потпис на фактура"));

		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myfaktmaster->getModel2();
		double cenaDDV = 0;
		double DDV = 0;



		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
#ifndef _alea
						painter.drawText(relX(16), relY(97 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, trUtf8("Шифра: ") + modelFaktura2->item(row, col )->text());
#endif
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(11), relY(9), Qt::AlignLeft, modelFaktura2->item(row, 4)->text());break;
					case 3: painter.drawText(relX(93), relY(100 + 6 * (row - pagefrom)), relX(12), relY(9), Qt::AlignRight,  modelFaktura2->item(row, 3)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(106), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(131), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(141), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(161), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: painter.drawText(relX(181), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						RabatIznos = RabatIznos + loc.toDouble(modelFaktura2->item(row, 13)->text());
						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(238), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Рабат"));
	painter.drawText(relX(170), relY(238), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded((-1)* RabatIznos), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(241), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(floor(sumaDDV+.5f)), 'f', 2) + trUtf8("  ден."));
	f.setBold(false);
	painter.setFont(f);
	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
	QString t2 = trUtf8("Рекламации се примаат во рок од 3 дена од приемот на стоката со уреден записник.");
	painter.drawText(relX(10), relY(261), relX(130), relY(6), Qt::AlignLeft, t2);
	QString t3 = trUtf8("Во случај на спор надлежен е Стопански суд.");
	painter.drawText(relX(10), relY(264), relX(130), relY(6), Qt::AlignLeft, t3);

#ifdef _demo
	drawDemo(painter);
#endif

}
void sterna::drawFakturaALL(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myfaktura->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;


		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(10), relY(10), relX(190), relY(20), Qt::AlignCenter, trUtf8("Листа на Испратници-Фактури"));

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(50), relX(190), relY(225), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(55));
		path.lineTo(relX(200),relY(55));

		path.moveTo(relX(15),relY(50));
		path.lineTo(relX(15),relY(275));

		path.moveTo(relX(31),relY(50));
		path.lineTo(relX(31),relY(275));

		path.moveTo(relX(82),relY(50));
		path.lineTo(relX(82),relY(275));

		path.moveTo(relX(105),relY(50));
		path.lineTo(relX(105),relY(275));

		path.moveTo(relX(128),relY(50));
		path.lineTo(relX(128),relY(275));

		path.moveTo(relX(151),relY(50));
		path.lineTo(relX(151),relY(275));

		path.moveTo(relX(174),relY(50));
		path.lineTo(relX(174),relY(275));

		painter.drawText(relX(12), relY(54), trUtf8("Ф."));
		painter.drawText(relX(17), relY(54), trUtf8("Датум"));
		painter.drawText(relX(33), relY(54), trUtf8("Коминтент"));
		painter.drawText(relX(84), relY(54), trUtf8("Износ"));
		painter.drawText(relX(107), relY(54), trUtf8("ДДВ"));
		painter.drawText(relX(130), relY(54), trUtf8("Вкупно"));
		painter.drawText(relX(153), relY(54), trUtf8("Платено"));
		painter.drawText(relX(176), relY(54), trUtf8("Останато за плак."));

// 		path.moveTo(relX(10),relY(275));
// 		path.lineTo(relX(60),relY(275));
// 		path.moveTo(relX(140),relY(275));
// 		path.lineTo(relX(190),relY(275));
// 		painter.drawText(relX(11), relY(280), trUtf8("Фактурирал"));
// 		painter.drawText(relX(145), relY(280), trUtf8("Примил"));
// 		path.moveTo(relX(10),relY(249));
// 		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myfaktura->getModel();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 35;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(10), relY(60 + 6 * (row - pagefrom)), relX(5), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 1: painter.drawText(relX(16), relY(60 + 6 * (row - pagefrom)), relX(15), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 2: painter.drawText(relX(32), relY(60 + 6 * (row - pagefrom)), relX(50), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(83), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: painter.drawText(relX(106), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 5: painter.drawText(relX(129), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 6: painter.drawText(relX(152), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(175), relY(60 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
// 	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
// 	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
// 	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
// 	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );
// 
// 	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
// 	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
// 	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
// 	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
// 	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

// 	f.setPointSize(7);
// 	painter.setFont(f);
// 	int p = int(sumaDDV + 0.5f);
// 	QString t = convertIntToText(p);
// 	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
// 	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
// 	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
#ifdef _demo
	drawDemo(painter);
#endif

}
void sterna::drawProFakturaMaster_all(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_profakturimaster->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;


		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(10), relY(10), relX(190), relY(20), Qt::AlignCenter, trUtf8("Листа на Про-Фактури"));

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(50), relX(190), relY(225), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(55));
		path.lineTo(relX(200),relY(55));

		path.moveTo(relX(15),relY(50));
		path.lineTo(relX(15),relY(275));

		path.moveTo(relX(31),relY(50));
		path.lineTo(relX(31),relY(275));

		path.moveTo(relX(82),relY(50));
		path.lineTo(relX(82),relY(275));

		path.moveTo(relX(105),relY(50));
		path.lineTo(relX(105),relY(275));

		path.moveTo(relX(128),relY(50));
		path.lineTo(relX(128),relY(275));

		path.moveTo(relX(151),relY(50));
		path.lineTo(relX(151),relY(275));

		path.moveTo(relX(174),relY(50));
		path.lineTo(relX(174),relY(275));

		painter.drawText(relX(12), relY(54), trUtf8("Ф."));
		painter.drawText(relX(17), relY(54), trUtf8("Датум"));
		painter.drawText(relX(33), relY(54), trUtf8("Коминтент"));
		painter.drawText(relX(84), relY(54), trUtf8("Износ"));
		painter.drawText(relX(107), relY(54), trUtf8("ДДВ"));
		painter.drawText(relX(130), relY(54), trUtf8("Вкупно"));
		painter.drawText(relX(153), relY(54), trUtf8("Платено"));
		painter.drawText(relX(176), relY(54), trUtf8("Останато за плак."));

		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_profakturimaster->getModel();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 35;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(10), relY(60 + 6 * (row - pagefrom)), relX(5), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 1: painter.drawText(relX(16), relY(60 + 6 * (row - pagefrom)), relX(15), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 2: painter.drawText(relX(32), relY(60 + 6 * (row - pagefrom)), relX(50), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(83), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: painter.drawText(relX(106), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 5: painter.drawText(relX(129), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 6: painter.drawText(relX(152), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(175), relY(60 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
#ifdef _demo
	drawDemo(painter);
#endif

}
void sterna::drawFakturaMaster_all(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myfaktmaster->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;


		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(10), relY(10), relX(190), relY(20), Qt::AlignCenter, trUtf8("Листа на Фактури"));

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(50), relX(190), relY(225), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(55));
		path.lineTo(relX(200),relY(55));

		path.moveTo(relX(15),relY(50));
		path.lineTo(relX(15),relY(275));

		path.moveTo(relX(31),relY(50));
		path.lineTo(relX(31),relY(275));

		path.moveTo(relX(82),relY(50));
		path.lineTo(relX(82),relY(275));

		path.moveTo(relX(105),relY(50));
		path.lineTo(relX(105),relY(275));

		path.moveTo(relX(128),relY(50));
		path.lineTo(relX(128),relY(275));

		path.moveTo(relX(151),relY(50));
		path.lineTo(relX(151),relY(275));

		path.moveTo(relX(174),relY(50));
		path.lineTo(relX(174),relY(275));

		painter.drawText(relX(12), relY(54), trUtf8("Ф."));
		painter.drawText(relX(17), relY(54), trUtf8("Датум"));
		painter.drawText(relX(33), relY(54), trUtf8("Коминтент"));
		painter.drawText(relX(84), relY(54), trUtf8("Износ"));
		painter.drawText(relX(107), relY(54), trUtf8("ДДВ"));
		painter.drawText(relX(130), relY(54), trUtf8("Вкупно"));
		painter.drawText(relX(153), relY(54), trUtf8("Платено"));
		painter.drawText(relX(176), relY(54), trUtf8("Останато за плак."));

		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myfaktmaster->getModel();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 35;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(10), relY(60 + 6 * (row - pagefrom)), relX(5), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 1: painter.drawText(relX(16), relY(60 + 6 * (row - pagefrom)), relX(15), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 2: painter.drawText(relX(32), relY(60 + 6 * (row - pagefrom)), relX(50), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(83), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: painter.drawText(relX(106), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 5: painter.drawText(relX(129), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 6: painter.drawText(relX(152), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(175), relY(60 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
#ifdef _demo
	drawDemo(painter);
#endif

}


void sterna::drawVleznaFaktura(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myfakturavlezna->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Влезна Фактура-Приемница"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Фактура"));
#endif

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(0);
		textNumberS = textNumberS.right(4);
		painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(1));
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + modelFakturaInfo.at(1));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(2));
// 		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
// 		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(95));
		path.lineTo(relX(200),relY(95));

		path.moveTo(relX(15),relY(90));
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(60),relY(90));
		path.lineTo(relX(60),relY(235));

		path.moveTo(relX(80),relY(90));
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(89),relY(90));
		path.lineTo(relX(89),relY(235));

		path.moveTo(relX(107),relY(90));
		path.lineTo(relX(107),relY(235));

		path.moveTo(relX(117),relY(90));
		path.lineTo(relX(117),relY(235));

		path.moveTo(relX(127),relY(90));
		path.lineTo(relX(127),relY(235));

		path.moveTo(relX(152),relY(90));
		path.lineTo(relX(152),relY(235));

		path.moveTo(relX(175),relY(90));
		path.lineTo(relX(175),relY(235));

		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(17), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(62), relY(94), trUtf8("Кол."));
		painter.drawText(relX(82), relY(94), trUtf8("Едм."));
		painter.drawText(relX(90), relY(94), trUtf8("Цена"));
		painter.drawText(relX(108), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(118), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(129), relY(94), trUtf8("Вкупен Износ"));
		painter.drawText(relX(154), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(177), relY(94), trUtf8("Вк.Износ со ДДВ"));

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(60),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(11), relY(280), trUtf8("Фактурирал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));
		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myfakturavlezna->getModel2();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(54), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(61), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(92), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(107), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(129), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(152), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: painter.drawText(relX(177), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());

						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));

	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
//	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
//	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
#ifdef _demo
	drawDemo(painter);
#endif

}

void sterna::drawFinAnalitikaKomintenti(QPrinter *printer, QPainter& painter)
{
	int maxpage = 1;
	for( int page=0; page<maxpage; page++)
	{
		QFont f;
		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(3), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);

		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(6), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(15), relX(15), relY(15), image1);

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(30), Qt::AlignCenter, trUtf8("Финансова Аналитика \nпо коминтент: ") + m_finanalitikaKomintenti->getModelInfo());
		f.setPointSize(8);


		painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(220), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(20),relY(45));
		path.lineTo(relX(200),relY(45));

		path.moveTo(relX(30),relY(40));
		path.lineTo(relX(30),relY(260));

		path.moveTo(relX(90),relY(40));
		path.lineTo(relX(90),relY(260));

		path.moveTo(relX(125),relY(40));
		path.lineTo(relX(125),relY(260));

		path.moveTo(relX(150),relY(40));
		path.lineTo(relX(150),relY(260));

		path.moveTo(relX(175),relY(40));
		path.lineTo(relX(175),relY(260));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(22), relY(44), trUtf8("Рб."));
		painter.drawText(relX(32), relY(44), trUtf8("Вид док."));
		painter.drawText(relX(92), relY(44), trUtf8("Датум"));
		f.setPointSize(6);
		painter.setFont(f);
		painter.drawText(relX(129), relY(42), trUtf8("Должи по фактура"));
		painter.drawText(relX(129), relY(44), trUtf8("Одлив по извод"));
		f.setPointSize(8);
		painter.setFont(f);

		f.setPointSize(6);
		painter.setFont(f);
		painter.drawText(relX(153), relY(42), trUtf8("Побарува по фактура"));
		painter.drawText(relX(153), relY(44), trUtf8("Прилив по извод"));
		f.setPointSize(8);
		painter.setFont(f);

		painter.drawText(relX(180), relY(44), trUtf8("Салдо"));
		path.moveTo(relX(20),relY(275));
		path.lineTo(relX(70),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(25), relY(280), trUtf8("Предал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));


		painter.drawPath(path);
		QStandardItemModel * modelIspratnica2 = m_finanalitikaKomintenti->getModel();
		if (modelIspratnica2)
		{
			int maxRowPage = 35;
			maxpage = modelIspratnica2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col < modelIspratnica2->columnCount(); col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(21), relY(50 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: painter.drawText(relX(31), relY(50 + 6 * (row - pagefrom)), relX(60), relY(9), Qt::AlignLeft,  modelIspratnica2->item(row, 0)->text() + " - " +modelIspratnica2->item(row, 1)->text());break;
					case 2: painter.drawText(relX(91), relY(50 + 6 * (row - pagefrom)), relX(34), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text());break;
					case 3: painter.drawText(relX(125), relY(50 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 3)->text().left(10));break;
					case 4: painter.drawText(relX(150), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 4)->text());break;
					case 5: painter.drawText(relX(175), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 5)->text());break;
					}
				}
			}
		}
		if( page < maxpage-1 )
			printer->newPage();
	}
#ifdef _demo
	drawDemo(painter);
#endif
}

void sterna::drawSmetka(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	QPen pen;

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(160), relY(50), relX(40), relY(60), Qt::AlignRight, trUtf8("Сметка"));
		f.setPointSize(8);
		QStringList modelFakturaInfo = m_mykasa->getIspratnicaInfo();

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + modelFakturaInfo.at(3));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(95));
		path.lineTo(relX(200),relY(95));

		path.moveTo(relX(15),relY(90));
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(60),relY(90));
		path.lineTo(relX(60),relY(235));

		path.moveTo(relX(80),relY(90));
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(89),relY(90));
		path.lineTo(relX(89),relY(235));

		path.moveTo(relX(107),relY(90));
		path.lineTo(relX(107),relY(235));

		path.moveTo(relX(117),relY(90));
		path.lineTo(relX(117),relY(235));

		path.moveTo(relX(127),relY(90));
		path.lineTo(relX(127),relY(235));

		path.moveTo(relX(152),relY(90));
		path.lineTo(relX(152),relY(235));

		path.moveTo(relX(175),relY(90));
		path.lineTo(relX(175),relY(235));

		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(17), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(62), relY(94), trUtf8("Кол."));
		painter.drawText(relX(82), relY(94), trUtf8("Едм."));
		painter.drawText(relX(90), relY(94), trUtf8("Цена"));
		painter.drawText(relX(108), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(118), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(129), relY(94), trUtf8("Вкупен Износ"));
		painter.drawText(relX(154), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(177), relY(94), trUtf8("Вк.Износ со ДДВ"));

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(60),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(11), relY(280), trUtf8("Фактурирал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));
		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_mykasa->getModel2();
		double cenaDDV = 0;
		double DDV = 0;
		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(54), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(61), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(92), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(107), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(129), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 9: painter.drawText(relX(152), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						break;
					case 10: painter.drawText(relX(177), relY(100 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());

						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));

	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(120), relY(6), Qt::AlignLeft,
		trUtf8("Рок на плаќање 8 дена од денот на фактурирањето.Во спротивно пресметуваме законска камата."));

}
void sterna::drawProFaktura(QPainter& painter)
{
	QFont f;
	QPainterPath path;

	f.setPointSize(12);
	painter.setFont(f);
	painter.drawText(relX(0), relY(3), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
	f.setPointSize(10);
	painter.setFont(f);
	painter.drawText(relX(0), relY(6), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

    QPixmap image1(moi_logo);
    painter.drawPixmap(relX(90), relY(20), relX(30), relX(20), image1);

	f.setPointSize(18);
	painter.setFont(f);
	painter.drawText(relX(160), relY(50), relX(40), relY(60), Qt::AlignRight, trUtf8("Профактура"));
	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
	painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
	painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
	painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број 2011-034"));
	painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: 21-ное-2011"));
	painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: 21-ное-2011"));
	painter.drawRoundedRect(relX(20), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
	painter.drawText(relX(25), relY(60), trUtf8("До:"));

	painter.drawText(relX(20), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
	painter.drawText(relX(20), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
	painter.drawText(relX(20), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

	painter.drawRoundedRect(relX(20), relY(90), relX(180), relY(140), relX(2), relY(2), Qt::AbsoluteSize );
	path.moveTo(relX(20),relY(95));
	path.lineTo(relX(200),relY(95));

	path.moveTo(relX(30),relY(90));
	path.lineTo(relX(30),relY(230));

	path.moveTo(relX(110),relY(90));
	path.lineTo(relX(110),relY(230));

	path.moveTo(relX(125),relY(90));
	path.lineTo(relX(125),relY(230));

	path.moveTo(relX(145),relY(90));
	path.lineTo(relX(145),relY(230));

	path.moveTo(relX(160),relY(90));
	path.lineTo(relX(160),relY(230));

	path.moveTo(relX(175),relY(90));
	path.lineTo(relX(175),relY(230));

	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(22), relY(94), trUtf8("Рб."));
	painter.drawText(relX(32), relY(94), trUtf8("Опис на артикал - услуга"));
	painter.drawText(relX(115), relY(94), trUtf8("Кол."));
	painter.drawText(relX(130), relY(94), trUtf8("Цена"));
	painter.drawText(relX(150), relY(94), trUtf8("Износ"));
	painter.drawText(relX(165), relY(94), trUtf8("ДДВ"));
	painter.drawText(relX(180), relY(94), trUtf8("Вкупно"));
	path.moveTo(relX(20),relY(275));
	path.lineTo(relX(70),relY(275));
	path.moveTo(relX(140),relY(275));
	path.lineTo(relX(190),relY(275));
	painter.drawText(relX(25), relY(280), trUtf8("Фактурирал"));
	painter.drawText(relX(145), relY(280), trUtf8("Директор"));

	painter.drawText(relX(130), relY(232), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупна цена"));
	painter.drawText(relX(130), relY(238), relX(40), relY(10), Qt::AlignRight, trUtf8("ДДВ"));
	painter.drawText(relX(130), relY(243), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари"));
	path.moveTo(relX(20),relY(248));
	path.lineTo(relX(200),relY(248));
	painter.drawText(relX(25), relY(280), trUtf8("Фактурирал"));
	f.setPointSize(6);
	painter.setFont(f);
	painter.drawText(relX(20), relY(248), relX(100), relY(6), Qt::AlignLeft, 
		trUtf8("Со зборови:"));


	painter.drawPath(path);


}

void sterna::drawKalkulacija(QPrinter *printer, QPainter& painter)
{
	int maxpage = 1;
	for( int page= 0; page < maxpage; page++)
	{
		QFont f;
		QPainterPath path;


		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(10), relY(15), relX(270), relY(5), Qt::AlignCenter, trUtf8("МАТЕРИЈАЛНА ЕВИДЕНЦИЈА ВО ТРГОВИЈА НА ГОЛЕМО"));
		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(10), relY(15), relX(277), relY(5), Qt::AlignLeft, trUtf8("Трговец"));
		painter.drawText(relX(25), relY(15), relX(100), relY(5), Qt::AlignLeft, moi_firma_info1);
		path.moveTo(relX(25),relY(18));
		path.lineTo(relX(80),relY(18));

		painter.drawText(relX(10), relY(20), relX(277), relY(5), Qt::AlignLeft, trUtf8("Адреса"));
		painter.drawText(relX(25), relY(20), relX(100), relY(5), Qt::AlignLeft, moi_firma_info2);

		path.moveTo(relX(25),relY(23));
		path.lineTo(relX(80),relY(23));

		painter.drawText(relX(10), relY(25), relX(277), relY(5), Qt::AlignLeft, trUtf8("Место"));
		painter.drawText(relX(25), relY(25), relX(100), relY(5), Qt::AlignLeft, moi_firma_info3);

		path.moveTo(relX(25),relY(28));
		path.lineTo(relX(80),relY(28));

		painter.drawText(relX(10), relY(30), relX(277), relY(5), Qt::AlignLeft, trUtf8("Едб"));
		painter.drawText(relX(25), relY(30), relX(100), relY(5), Qt::AlignLeft, moi_firma_edb);

		path.moveTo(relX(25),relY(33));
		path.lineTo(relX(80),relY(33));

		////////////////////////////////////////////////////////////////////////////////////////////////////////

		painter.setFont(f);
		painter.drawText(relX(220), relY(15), relX(67), relY(5), Qt::AlignLeft, trUtf8("____________________________"));
		painter.drawText(relX(220), relY(20), relX(67), relY(5), Qt::AlignLeft, trUtf8("Продажна Цена"));
		painter.drawText(relX(220), relY(25), relX(67), relY(5), Qt::AlignLeft, trUtf8("____________________________"));
		painter.drawText(relX(220), relY(30), relX(67), relY(5), Qt::AlignLeft, trUtf8("Едм:   "));


		////////////////////////////////////////////////////////////////////////////////////////////////////////
		QString m_proizvod = "";//m_mykalkulacija->getKalkulacijaInfo();
		painter.drawText(relX(90), relY(25), relX(160), relY(5), Qt::AlignLeft, trUtf8("Назив на производот:" ));
		painter.drawText(relX(130), relY(25), relX(100), relY(5), Qt::AlignLeft, m_proizvod);
		path.moveTo(relX(130),relY(28));
		path.lineTo(relX(200),relY(28));

		painter.drawText(relX(90), relY(30), relX(60), relY(5), Qt::AlignLeft, trUtf8("Магацин-стовариште"));
		path.moveTo(relX(130),relY(33));
		path.lineTo(relX(200),relY(33));

		////////////////////////////////////////////////////////////////////////////////////////////////////////

		painter.drawRoundedRect(relX(10), relY(40), relX(277), relY(140), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(45),relY(45));
		path.lineTo(relX(287),relY(45));
		path.moveTo(relX(10),relY(55));
		path.lineTo(relX(287),relY(55));
		path.moveTo(relX(10),relY(60));
		path.lineTo(relX(287),relY(60));

		painter.drawText(relX(12), relY(50), trUtf8("Рб."));
		painter.drawText(relX(12), relY(58), trUtf8("1"));

		//reden broj.
		path.moveTo(relX(20),relY(40));
		path.lineTo(relX(20),relY(180));
		painter.drawText(relX(22), relY(50), trUtf8("Дат.книжење"));
		painter.drawText(relX(22), relY(58), trUtf8("2"));

		//datum na knizenje
		path.moveTo(relX(45),relY(40));
		path.lineTo(relX(45),relY(180));
		painter.drawText(relX(47), relY(43), trUtf8("Книговодствен документ"));
		painter.drawText(relX(47), relY(50), trUtf8("Бр. документ"));
		painter.drawText(relX(47), relY(58), trUtf8("3"));

		//broj na dokument
		path.moveTo(relX(70),relY(45));
		path.lineTo(relX(70),relY(180));
		painter.drawText(relX(72), relY(50), trUtf8("Дат. на док."));
		painter.drawText(relX(72), relY(58), trUtf8("4"));


		//naziv na dokument
		path.moveTo(relX(95),relY(45));
		path.lineTo(relX(95),relY(180));
		painter.drawText(relX(97), relY(50), trUtf8("Назив Док."));
		painter.drawText(relX(97), relY(58), trUtf8("5"));

		//vlez
		path.moveTo(relX(170),relY(40));
		path.lineTo(relX(170),relY(180));
		painter.drawText(relX(172), relY(43), trUtf8("Количина"));
		painter.drawText(relX(172), relY(50), trUtf8("Влез"));
		painter.drawText(relX(172), relY(58), trUtf8("6"));

		//izlez
		path.moveTo(relX(209),relY(45));
		path.lineTo(relX(209),relY(180));
		painter.drawText(relX(211), relY(50), trUtf8("Излез"));
		painter.drawText(relX(211), relY(58), trUtf8("7"));

		//sostojba
		path.moveTo(relX(248),relY(45));
		path.lineTo(relX(248),relY(180));
		painter.drawText(relX(250), relY(50), trUtf8("Состојба"));
		painter.drawText(relX(250), relY(58), trUtf8("8"));

		f.setPointSize(8);
		painter.setFont(f);



		painter.drawText(relX(10), relY(190), trUtf8("Образец МЕТГ"));
		painter.drawText(relX(145), relY(190), trUtf8("(М.П.)"));
		painter.drawText(relX(237), relY(195), trUtf8("Потпис на овластено лице"));
		path.moveTo(relX(237),relY(190));
		path.lineTo(relX(287),relY(190));


		painter.drawPath(path);
		QStandardItemModel * modelIspratnica2 = m_mykalkulacija->getModel2();
		if (modelIspratnica2)
		{
			int maxRowPage = 20;
			maxpage = modelIspratnica2->rowCount() / (maxRowPage) + (modelIspratnica2->rowCount() % (maxRowPage) ? 1 : 0);
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col < modelIspratnica2->columnCount() + 2; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(61 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: painter.drawText(relX(21), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 0)->text().left(10));break;
					case 2: painter.drawText(relX(47), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 1)->text());break;
					case 4: painter.drawText(relX(71), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text().left(10));break;
					case 5: painter.drawText(relX(96), relY(61 + 6 * (row - pagefrom)), relX(93), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 3)->text());break;
					case 6: painter.drawText(relX(171), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 4) ? modelIspratnica2->item(row, 4)->text() : "");break;
					case 7: painter.drawText(relX(210), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 5) ? modelIspratnica2->item(row, 5)->text() : "");break;
					case 8: painter.drawText(relX(249), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 6) ? modelIspratnica2->item(row, 6)->text() : "");break;
					}
				}
			}
		}
		if( page < maxpage-1 )
			printer->newPage();
	}
#ifdef _demo
	drawDemo(painter);
#endif
}


void sterna::drawIspratnica(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	double RabatIznos = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myispratnici->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Испратница"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Испратница"));
#endif

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(140), relY(35), relX(60), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(140), relY(40), relX(60), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(140), relY(45), relX(60), relY(50), Qt::AlignRight, moi_firma_web);

		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(140), relY(60), relX(60), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS + moi_prefix_prodavnica);
		f.setBold(false);
		painter.setFont(f);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		int rok = modelFakturaInfo.at(5).toInt();
		QString separ = modelFakturaInfo.at(3).mid(4,1);
		QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
		dateTimeTemp = dateTimeTemp.addDays(rok);
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));
		f.setBold(false);
		painter.setFont(f);

		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(97)); //rb
		path.lineTo(relX(200),relY(97));

		path.moveTo(relX(15),relY(90)); //naziv
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(80),relY(90)); //edm
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(92),relY(90)); //kol
		path.lineTo(relX(92),relY(235));

		path.moveTo(relX(105),relY(90)); //cena -ddv
		path.lineTo(relX(105),relY(235));

		path.moveTo(relX(120),relY(90));
		path.lineTo(relX(120),relY(235));

		path.moveTo(relX(130),relY(90));
		path.lineTo(relX(130),relY(235));

		path.moveTo(relX(140),relY(90));
		path.lineTo(relX(140),relY(235));

		path.moveTo(relX(160),relY(90));
		path.lineTo(relX(160),relY(235));

		path.moveTo(relX(180),relY(90));
		path.lineTo(relX(180),relY(235));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(16), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(81), relY(94), trUtf8("Едм."));
		painter.drawText(relX(93), relY(94), trUtf8("Кол."));
		painter.drawText(relX(106), relY(93), trUtf8("Цена"));
		painter.drawText(relX(106), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(121), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(131), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(141), relY(93), trUtf8("Вк.Износ"));
		painter.drawText(relX(141), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(161), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(181), relY(93), trUtf8("Вк.Вредност"));
		painter.drawText(relX(181), relY(96), trUtf8("со ДДВ"));
		f.setPointSize(8);
		painter.setFont(f);

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(56),relY(275));
		path.moveTo(relX(155),relY(275));
		path.lineTo(relX(198),relY(275));


		painter.drawText(relX(11), relY(280), trUtf8("Примил"));
		painter.drawText(relX(155), relY(280), trUtf8("Предал"));

		painter.drawText(relX(100), relY(265), trUtf8("МП"));

		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myispratnici->getModel2();
		double cenaDDV = 0;
		double DDV = 0;



		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
#ifndef _alea
						painter.drawText(relX(16), relY(97 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, trUtf8("Шифра: ") + modelFaktura2->item(row, col )->text());
#endif

						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(11), relY(9), Qt::AlignLeft, modelFaktura2->item(row, 4)->text());break;
					case 3: painter.drawText(relX(93), relY(100 + 6 * (row - pagefrom)), relX(12), relY(9), Qt::AlignRight,  modelFaktura2->item(row, 3)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(106), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(131), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(141), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(161), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: 
						painter.drawText(relX(181), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						//RabatIznos = RabatIznos + loc.toDouble(modelFaktura2->item(row, 13)->text());
						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
// 	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
// 	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(130), relY(238), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Рабат"));
// 	painter.drawText(relX(170), relY(238), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded((-1)* RabatIznos), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(130), relY(241), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
// 	painter.drawText(relX(170), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(floor(sumaDDV+.5f)), 'f', 2) + trUtf8("  ден."));
	f.setBold(false);
	painter.setFont(f);
// 	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );
// 
// 	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
// 	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
// 	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
// 	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));
// 
// 	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
// 	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
// 	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(50), relY(249), relX(120), relY(6), Qt::AlignRight, t);
//	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
// 	QString t2 = trUtf8("Рекламации се примаат во рок од 3 дена од приемот на стоката со уреден записник.");
// 	painter.drawText(relX(10), relY(261), relX(130), relY(6), Qt::AlignLeft, t2);
// 	QString t3 = trUtf8("Во случај на спор надлежен е Стопански суд.");
// 	painter.drawText(relX(10), relY(264), relX(130), relY(6), Qt::AlignLeft, t3);

#ifdef _demo
	drawDemo(painter);
#endif

}
void sterna::drawIspratnicaALL(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_myispratnici->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;


		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(10), relY(10), relX(190), relY(20), Qt::AlignCenter, trUtf8("Листа на Испратници"));

		f.setPointSize(8);

		painter.setFont(f);
		painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
		painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
		painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);
		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);


		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(50), relX(190), relY(225), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(55));
		path.lineTo(relX(200),relY(55));

		path.moveTo(relX(15),relY(50));
		path.lineTo(relX(15),relY(275));

		path.moveTo(relX(31),relY(50));
		path.lineTo(relX(31),relY(275));

		path.moveTo(relX(82),relY(50));
		path.lineTo(relX(82),relY(275));

		path.moveTo(relX(105),relY(50));
		path.lineTo(relX(105),relY(275));

		path.moveTo(relX(128),relY(50));
		path.lineTo(relX(128),relY(275));

		path.moveTo(relX(151),relY(50));
		path.lineTo(relX(151),relY(275));

		path.moveTo(relX(174),relY(50));
		path.lineTo(relX(174),relY(275));

		painter.drawText(relX(12), relY(54), trUtf8("Ф."));
		painter.drawText(relX(17), relY(54), trUtf8("Датум"));
		painter.drawText(relX(33), relY(54), trUtf8("Коминтент"));
		painter.drawText(relX(84), relY(54), trUtf8("Износ"));
		painter.drawText(relX(107), relY(54), trUtf8("ДДВ"));
		painter.drawText(relX(130), relY(54), trUtf8("Вкупно"));
		painter.drawText(relX(153), relY(54), trUtf8("Платено"));
		painter.drawText(relX(176), relY(54), trUtf8("Останато за плак."));

		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_myispratnici->getModel();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 35;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(10), relY(60 + 6 * (row - pagefrom)), relX(5), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 1: painter.drawText(relX(16), relY(60 + 6 * (row - pagefrom)), relX(15), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 2: painter.drawText(relX(32), relY(60 + 6 * (row - pagefrom)), relX(50), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());break;
					case 3: painter.drawText(relX(83), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignLeft,  modelFaktura2->item(row, col + 1)->text());break;
					case 4: painter.drawText(relX(106), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 5: painter.drawText(relX(129), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 6: painter.drawText(relX(152), relY(60 + 6 * (row - pagefrom)), relX(22), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(175), relY(60 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
#ifdef _demo
	drawDemo(painter);
#endif

}

void sterna::drawPriemnica(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	for( int page=0; page<maxpage; page++)
	{
	QFont f;
	QPen pen;
	QPainterPath path;
    QStringList modelPriemnicaInfo = m_mypriemnici->getPriemnicaInfo();

    painter.drawText(relX(25), relY(65), modelPriemnicaInfo.at(0));
    painter.drawText(relX(25), relY(70), modelPriemnicaInfo.at(1));
    painter.drawText(relX(25), relY(75), modelPriemnicaInfo.at(2));

    f.setPointSize(12);
    painter.setFont(f);
    painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
    f.setPointSize(10);
    painter.setFont(f);
    painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

    QPixmap image1(moi_logo);
    painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

	f.setPointSize(18);
	painter.setFont(f);
	painter.drawText(relX(160), relY(50), relX(40), relY(60), Qt::AlignRight, trUtf8("Приемница"));
	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(160), relY(35), relX(40), relY(40), Qt::AlignRight, moi_firma_tel);
	painter.drawText(relX(160), relY(40), relX(40), relY(45), Qt::AlignRight, moi_firma_email);
	painter.drawText(relX(150), relY(45), relX(50), relY(50), Qt::AlignRight, moi_firma_web);

	QString textNumberS = "0000"+modelPriemnicaInfo.at(3);
	textNumberS = textNumberS.right(4);

	painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS);
	painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelPriemnicaInfo.at(4));
	painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + modelPriemnicaInfo.at(4));
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawRoundedRect(relX(20), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
	painter.drawText(relX(25), relY(60), trUtf8("До:"));

	painter.drawText(relX(20), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
	painter.drawText(relX(20), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
	painter.drawText(relX(20), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

	painter.drawRoundedRect(relX(20), relY(90), relX(180), relY(140), relX(2), relY(2), Qt::AbsoluteSize );
	path.moveTo(relX(20),relY(95));
	path.lineTo(relX(200),relY(95));

	path.moveTo(relX(30),relY(90));
	path.lineTo(relX(30),relY(230));

	path.moveTo(relX(120),relY(90));
	path.lineTo(relX(120),relY(230));

	path.moveTo(relX(141),relY(90));
	path.lineTo(relX(141),relY(230));

	path.moveTo(relX(157),relY(90));
	path.lineTo(relX(157),relY(230));

	path.moveTo(relX(176),relY(90));
	path.lineTo(relX(176),relY(230));


	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(22), relY(94), trUtf8("Рб."));
	painter.drawText(relX(32), relY(94), trUtf8("Опис на артикли"));

	painter.drawText(relX(130), relY(94), trUtf8("Кол."));
	painter.drawText(relX(150), relY(94), trUtf8("Едм."));
	painter.drawText(relX(165), relY(94), trUtf8("Цена"));
	painter.drawText(relX(182), relY(94), trUtf8("Износ"));
	path.moveTo(relX(20),relY(275));
	path.lineTo(relX(70),relY(275));
	path.moveTo(relX(140),relY(275));
	path.lineTo(relX(190),relY(275));
	painter.drawText(relX(25), relY(280), trUtf8("Предал"));
	painter.drawText(relX(145), relY(280), trUtf8("Примил"));


	painter.drawPath(path);
	QStandardItemModel * modelPriemnica2 = m_mypriemnici->getModel2();
	if (modelPriemnica2)
	{
		int maxRowPage = 21;
        maxpage = modelPriemnica2->rowCount() / (maxRowPage + 1) + 1;
		int pagefrom = page * maxRowPage;
		int pageto = (page + 1) * maxRowPage < modelPriemnica2->rowCount() ? (page + 1) * maxRowPage : modelPriemnica2->rowCount();

		for (int row = pagefrom; row < pageto; row++)
		{
			for (int col = 0; col < modelPriemnica2->columnCount(); col++)
			{
				switch (col)
				{
				case 0: painter.drawText(relX(21), relY(100 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
				case 1: painter.drawText(relX(31), relY(100 + 6 * (row - pagefrom)), relX(89), relY(9), Qt::AlignLeft, modelPriemnica2->item(row, 2)->text());break;
				case 2: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(20), relY(9), Qt::AlignRight, modelPriemnica2->item(row, 4)->text());break;
				case 3: painter.drawText(relX(142), relY(100 + 6 * (row - pagefrom)), relX(156), relY(9), Qt::AlignLeft, modelPriemnica2->item(row, 3)->text());break;
				case 4: painter.drawText(relX(158), relY(100 + 6 * (row - pagefrom)), relX(17), relY(9), Qt::AlignRight, modelPriemnica2->item(row, 5)->text());break;
				case 5: 
					float iznos = loc.toFloat(modelPriemnica2->item(row, 4)->text()) * loc.toFloat(modelPriemnica2->item(row, 5)->text()); 
					painter.drawText(relX(179), relY(100 + 6 * (row - pagefrom)), relX(20), relY(9), Qt::AlignRight, loc.toString(iznos, 'f', 2));break;
				}
			}
		}
	}
	if( page < maxpage-1 )
		printer->newPage();
	}
#ifdef _demo
	drawDemo(painter);
#endif
}
void sterna::drawLagerLista(QPrinter *printer,QPainter& painter)
{
	int maxpage = 1;
	for( int page=0; page<maxpage; page++)
	{
		QFont f;
		QPainterPath path;

        f.setPointSize(12);
        painter.setFont(f);
        painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
        f.setPointSize(10);
        painter.setFont(f);
        painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

//         QPixmap image1(moi_logo);
//         painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(30), Qt::AlignCenter, trUtf8("Лагер Листа"));
		f.setPointSize(8);


		painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(220), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(20),relY(45));
		path.lineTo(relX(200),relY(45));

		path.moveTo(relX(40),relY(40));
		path.lineTo(relX(40),relY(260));

		path.moveTo(relX(100),relY(40));
		path.lineTo(relX(100),relY(260));

		path.moveTo(relX(125),relY(40));
		path.lineTo(relX(125),relY(260));

		path.moveTo(relX(150),relY(40));
		path.lineTo(relX(150),relY(260));

		path.moveTo(relX(175),relY(40));
		path.lineTo(relX(175),relY(260));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(22), relY(44), trUtf8("Рб."));
		painter.drawText(relX(42), relY(44), trUtf8("Опис на артикли"));

		painter.drawText(relX(105), relY(44), trUtf8("Ед.мера"));
		painter.drawText(relX(130), relY(44), trUtf8("Влез"));
		painter.drawText(relX(155), relY(44), trUtf8("Излез"));
		painter.drawText(relX(180), relY(44), trUtf8("Салдо"));
		path.moveTo(relX(20),relY(275));
		path.lineTo(relX(70),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(25), relY(280), trUtf8("Предал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));


		painter.drawPath(path);
		QStandardItemModel * modelIspratnica2 = m_mylager->getModel();
		if (modelIspratnica2)
		{
			int maxRowPage = 30;
			maxpage = modelIspratnica2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col < modelIspratnica2->columnCount(); col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(21), relY(50 + 6 * (row - pagefrom)), relX(18), relY(9), Qt::AlignLeft,modelIspratnica2->item(row, 1)->text());break;
					case 1: painter.drawText(relX(41), relY(50 + 6 * (row - pagefrom)), relX(60), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text());break;
					case 2: painter.drawText(relX(101), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 3)->text());break;
					case 3: painter.drawText(relX(125), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 6)->text());break;
					case 4: painter.drawText(relX(150), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 7)->text());break;
					case 5: painter.drawText(relX(175), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 8)->text());break;
					}
				}
			}
		}
		if( page < maxpage-1 )
		{
		#ifdef _demo
			drawDemo(painter);
		#endif
			printer->newPage();

		}

	}
}

void sterna::draw_PeriodicenIzvestaj(QPrinter *printer,QPainter& painter)
{
	int maxpage = 1;
	QStandardItemModel * modelIspratnica2 = m_periodicen->getModel();
	for( int page=0; page<maxpage; page++)
	{
		QFont f;
		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		//         QPixmap image1(moi_logo);
		//         painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(14);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(30), Qt::AlignCenter, trUtf8("Извештај за период -") + m_periodicen->getDateRange());
		f.setPointSize(8);


		painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(220), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(20),relY(45));
		path.lineTo(relX(200),relY(45));

		path.moveTo(relX(40),relY(40));
		path.lineTo(relX(40),relY(260));

		path.moveTo(relX(100),relY(40));
		path.lineTo(relX(100),relY(260));

		path.moveTo(relX(125),relY(40));
		path.lineTo(relX(125),relY(260));

		path.moveTo(relX(150),relY(40));
		path.lineTo(relX(150),relY(260));

		path.moveTo(relX(175),relY(40));
		path.lineTo(relX(175),relY(260));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(22), relY(44), trUtf8("Рб."));
		painter.drawText(relX(42), relY(44), trUtf8("Опис на артикли"));

		painter.drawText(relX(105), relY(44), trUtf8("Ед.мера"));
		painter.drawText(relX(130), relY(44), trUtf8("Влез"));
		painter.drawText(relX(155), relY(44), trUtf8("Излез"));
		painter.drawText(relX(180), relY(44), trUtf8("Салдо"));
		path.moveTo(relX(20),relY(275));
		path.lineTo(relX(70),relY(275));
		path.moveTo(relX(140),relY(275));
		path.lineTo(relX(190),relY(275));
		painter.drawText(relX(25), relY(280), trUtf8("Предал"));
		painter.drawText(relX(145), relY(280), trUtf8("Примил"));


		painter.drawPath(path);
		
		if (modelIspratnica2)
		{
			int maxRowPage = 30;
			maxpage = modelIspratnica2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col < modelIspratnica2->columnCount(); col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(21), relY(50 + 6 * (row - pagefrom)), relX(18), relY(9), Qt::AlignLeft,modelIspratnica2->item(row, 1)->text());break;
					case 1: painter.drawText(relX(41), relY(50 + 6 * (row - pagefrom)), relX(60), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text());break;
					case 2: painter.drawText(relX(101), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 3)->text());break;
					case 3: painter.drawText(relX(125), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 6)->text());break;
					case 4: painter.drawText(relX(150), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 7)->text());break;
					case 5: painter.drawText(relX(175), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 8)->text());break;
					}
				}
			}
		}
		if( page < maxpage-1 )
		{
#ifdef _demo
			drawDemo(painter);
#endif
			printer->newPage();

		}

	}
}

void sterna::drawArtikliLista(QPrinter *printer, QPainter& painter)
{
	int maxpage = 2;
	for( int page=0; page<maxpage; page++)
	{
	QFont f;
	QPainterPath path;

	f.setPointSize(12);
	painter.setFont(f);
	painter.drawText(relX(0), relY(3), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
	f.setPointSize(10);
	painter.setFont(f);
	painter.drawText(relX(0), relY(6), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

	f.setPointSize(20);
	painter.setFont(f);
	painter.drawText(relX(0), relY(12), relX(210), relY(9), Qt::AlignCenter, 
		trUtf8("Листа на артикли"));

    QPixmap image1(moi_logo);
    painter.drawPixmap(relX(90), relY(20), relX(30), relX(20), image1);

	painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(230), relX(2), relY(2), Qt::AbsoluteSize );
	path.moveTo(relX(20),relY(45));
	path.lineTo(relX(200),relY(45));

	path.moveTo(relX(30),relY(40));
	path.lineTo(relX(30),relY(270));

	path.moveTo(relX(110),relY(40));
	path.lineTo(relX(110),relY(270));

	path.moveTo(relX(125),relY(40));
	path.lineTo(relX(125),relY(270));

	path.moveTo(relX(145),relY(40));
	path.lineTo(relX(145),relY(270));

	path.moveTo(relX(160),relY(40));
	path.lineTo(relX(160),relY(270));

	path.moveTo(relX(175),relY(40));
	path.lineTo(relX(175),relY(270));

	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(22), relY(44), trUtf8("Рб."));
	painter.drawText(relX(32), relY(44), trUtf8("Опис на артикал - услуга"));
	painter.drawText(relX(115), relY(44), trUtf8("Кол."));
	painter.drawText(relX(130), relY(44), trUtf8("Цена"));
	painter.drawText(relX(150), relY(44), trUtf8("Износ"));
	painter.drawText(relX(165), relY(44), trUtf8("ДДВ"));
	painter.drawText(relX(180), relY(44), trUtf8("Вкупно"));

	path.moveTo(relX(20),relY(275));
	path.lineTo(relX(70),relY(275));
	path.moveTo(relX(140),relY(275));
	path.lineTo(relX(190),relY(275));
	painter.drawText(relX(25), relY(280), trUtf8("Изработил"));
	painter.drawText(relX(145), relY(280), trUtf8("Директор"));

	painter.drawPath(path);


	QStandardItemModel * modelArtikli = m_myartikli->getModel();
	if (modelArtikli)
	{
		int maxRowPage = 15;
		int pagefrom = page * maxRowPage;
		int pageto = (page + 1) * maxRowPage < modelArtikli->rowCount() ? (page + 1) * maxRowPage : modelArtikli->rowCount();

		for (int row = pagefrom; row < pageto; row++)
		{
			for (int col = 0; col < modelArtikli->columnCount(); col++)
			{
				switch (col)
				{
				case 0: painter.drawText(relX(21), relY(50 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: painter.drawText(relX(31), relY(50 + 6 * (row - pagefrom)), relX(78), relY(9), Qt::AlignLeft, modelArtikli->item(row, col + 1)->text());break;
					case 2: painter.drawText(relX(111), relY(50 + 6 * (row - pagefrom)), relX(13), relY(9), Qt::AlignLeft, trUtf8("ул.Народен Фронт "));break;
					case 3: painter.drawText(relX(126), relY(50 + 6 * (row - pagefrom)), relX(18), relY(9), Qt::AlignRight, trUtf8("CCCC"));break;
					case 4: painter.drawText(relX(146), relY(50 + 6 * (row - pagefrom)), relX(13), relY(9), Qt::AlignRight, trUtf8("BBBB"));break;
					case 5: painter.drawText(relX(161), relY(50 + 6 * (row - pagefrom)), relX(13), relY(9), Qt::AlignRight, trUtf8("AAAA"));break;
				}
			}
		}
	}
	if( page < maxpage-1 )
		printer->newPage();
	}
}
void sterna::drawAnalitikaArtikli(QPrinter *printer,QPainter& painter)
{
    int maxpage = 1;
    for( int page= 0; page < maxpage; page++)
    {
        QFont f;
        QPainterPath path;


        f.setPointSize(10);
        painter.setFont(f);
        painter.drawText(relX(10), relY(15), relX(270), relY(5), Qt::AlignCenter, trUtf8("МАТЕРИЈАЛНА ЕВИДЕНЦИЈА ВО ТРГОВИЈА НА ГОЛЕМО"));
        f.setPointSize(8);

        painter.setFont(f);
        painter.drawText(relX(10), relY(15), relX(277), relY(5), Qt::AlignLeft, trUtf8("Трговец"));
        painter.drawText(relX(25), relY(15), relX(100), relY(5), Qt::AlignLeft, moi_firma_info1);
        path.moveTo(relX(25),relY(18));
        path.lineTo(relX(80),relY(18));

        painter.drawText(relX(10), relY(20), relX(277), relY(5), Qt::AlignLeft, trUtf8("Адреса"));
        painter.drawText(relX(25), relY(20), relX(100), relY(5), Qt::AlignLeft, moi_firma_info2);

        path.moveTo(relX(25),relY(23));
        path.lineTo(relX(80),relY(23));

        painter.drawText(relX(10), relY(25), relX(277), relY(5), Qt::AlignLeft, trUtf8("Место"));
        painter.drawText(relX(25), relY(25), relX(100), relY(5), Qt::AlignLeft, moi_firma_info3);

        path.moveTo(relX(25),relY(28));
        path.lineTo(relX(80),relY(28));

        painter.drawText(relX(10), relY(30), relX(277), relY(5), Qt::AlignLeft, trUtf8("Едб"));
        painter.drawText(relX(25), relY(30), relX(100), relY(5), Qt::AlignLeft, moi_firma_edb);

        path.moveTo(relX(25),relY(33));
        path.lineTo(relX(80),relY(33));

        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        painter.setFont(f);
        painter.drawText(relX(220), relY(15), relX(67), relY(5), Qt::AlignLeft, trUtf8("____________________________"));
        painter.drawText(relX(220), relY(20), relX(67), relY(5), Qt::AlignLeft, trUtf8("Продажна Цена"));
        painter.drawText(relX(220), relY(25), relX(67), relY(5), Qt::AlignLeft, trUtf8("____________________________"));
        painter.drawText(relX(220), relY(30), relX(67), relY(5), Qt::AlignLeft, trUtf8("Едм:   ") +  m_analitikaArtikli->getModelInfo2());


        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        QString m_proizvod = m_analitikaArtikli->getModelInfo();
        painter.drawText(relX(90), relY(25), relX(160), relY(5), Qt::AlignLeft, trUtf8("Назив на производот:" ));
        painter.drawText(relX(130), relY(25), relX(100), relY(5), Qt::AlignLeft, m_proizvod);
        path.moveTo(relX(130),relY(28));
        path.lineTo(relX(200),relY(28));

        painter.drawText(relX(90), relY(30), relX(60), relY(5), Qt::AlignLeft, trUtf8("Магацин-стовариште"));
        path.moveTo(relX(130),relY(33));
        path.lineTo(relX(200),relY(33));

        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        painter.drawRoundedRect(relX(10), relY(40), relX(277), relY(140), relX(2), relY(2), Qt::AbsoluteSize );
        path.moveTo(relX(45),relY(45));
        path.lineTo(relX(287),relY(45));
        path.moveTo(relX(10),relY(55));
        path.lineTo(relX(287),relY(55));
        path.moveTo(relX(10),relY(60));
        path.lineTo(relX(287),relY(60));

        painter.drawText(relX(12), relY(50), trUtf8("Рб."));
        painter.drawText(relX(12), relY(58), trUtf8("1"));

        //reden broj.
        path.moveTo(relX(20),relY(40));
        path.lineTo(relX(20),relY(180));
        painter.drawText(relX(22), relY(50), trUtf8("Дат.книжење"));
        painter.drawText(relX(22), relY(58), trUtf8("2"));

        //datum na knizenje
        path.moveTo(relX(45),relY(40));
        path.lineTo(relX(45),relY(180));
        painter.drawText(relX(47), relY(43), trUtf8("Книговодствен документ"));
        painter.drawText(relX(47), relY(50), trUtf8("Бр. документ"));
        painter.drawText(relX(47), relY(58), trUtf8("3"));

        //broj na dokument
        path.moveTo(relX(70),relY(45));
        path.lineTo(relX(70),relY(180));
        painter.drawText(relX(72), relY(50), trUtf8("Дат. на док."));
        painter.drawText(relX(72), relY(58), trUtf8("4"));


        //naziv na dokument
        path.moveTo(relX(95),relY(45));
        path.lineTo(relX(95),relY(180));
        painter.drawText(relX(97), relY(50), trUtf8("Назив Док."));
        painter.drawText(relX(97), relY(58), trUtf8("5"));

        //vlez
        path.moveTo(relX(170),relY(40));
        path.lineTo(relX(170),relY(180));
        painter.drawText(relX(172), relY(43), trUtf8("Количина"));
        painter.drawText(relX(172), relY(50), trUtf8("Влез"));
        painter.drawText(relX(172), relY(58), trUtf8("6"));

        //izlez
        path.moveTo(relX(209),relY(45));
        path.lineTo(relX(209),relY(180));
        painter.drawText(relX(211), relY(50), trUtf8("Излез"));
        painter.drawText(relX(211), relY(58), trUtf8("7"));

        //sostojba
        path.moveTo(relX(248),relY(45));
        path.lineTo(relX(248),relY(180));
        painter.drawText(relX(250), relY(50), trUtf8("Состојба"));
        painter.drawText(relX(250), relY(58), trUtf8("8"));

        f.setPointSize(8);
        painter.setFont(f);



        painter.drawText(relX(10), relY(190), trUtf8("Образец МЕТГ"));
        painter.drawText(relX(145), relY(190), trUtf8("(М.П.)"));
        painter.drawText(relX(237), relY(195), trUtf8("Потпис на овластено лице"));
        path.moveTo(relX(237),relY(190));
        path.lineTo(relX(287),relY(190));


        painter.drawPath(path);
        QStandardItemModel * modelIspratnica2 = m_analitikaArtikli->getModel();
        if (modelIspratnica2)
        {
            int maxRowPage = 20;
            maxpage = modelIspratnica2->rowCount() / (maxRowPage) + (modelIspratnica2->rowCount() % (maxRowPage) ? 1 : 0);
            int pagefrom = page * maxRowPage;
            int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

            for (int row = pagefrom; row < pageto; row++)
            {
                for (int col = 0; col < modelIspratnica2->columnCount() + 2; col++)
                {
                    switch (col)
                    {
                    case 0: painter.drawText(relX(11), relY(61 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
                    case 1: painter.drawText(relX(21), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 0)->text().left(10));break;
                    case 2: painter.drawText(relX(47), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 1)->text());break;
                    case 4: painter.drawText(relX(71), relY(61 + 6 * (row - pagefrom)), relX(23), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text().left(10));break;
                    case 5: painter.drawText(relX(96), relY(61 + 6 * (row - pagefrom)), relX(93), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 3)->text());break;
                    case 6: painter.drawText(relX(171), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 4) ? modelIspratnica2->item(row, 4)->text() : "");break;
                    case 7: painter.drawText(relX(210), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 5) ? modelIspratnica2->item(row, 5)->text() : "");break;
                    case 8: painter.drawText(relX(249), relY(61 + 6 * (row - pagefrom)), relX(37), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 6) ? modelIspratnica2->item(row, 6)->text() : "");break;
                    }
                }
            }
        }
        if( page < maxpage-1 )
            printer->newPage();
    }
#ifdef _demo
	drawDemo(painter);
#endif
}
void sterna::drawAnalitikaKomintenti(QPrinter *printer,QPainter& painter)
{
    int maxpage = 1;
    for( int page=0; page<maxpage; page++)
    {
        QFont f;
        QPainterPath path;

        f.setPointSize(12);
        painter.setFont(f);
        painter.drawText(relX(0), relY(3), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);

        f.setPointSize(10);
        painter.setFont(f);
        painter.drawText(relX(0), relY(6), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

        //         QPixmap image1(":/sterna/Resources/microsoft_logo.png");
        //         painter.drawPixmap(relX(90), relY(20), relX(30), relX(20), image1);

        f.setPointSize(12);
        painter.setFont(f);
        painter.drawText(relX(0), relY(20), relX(210), relY(30), Qt::AlignCenter, trUtf8("Аналитика по Коминтент:") + m_analitikaKomintenti->getModelInfo());
        f.setPointSize(8);


        painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(220), relX(2), relY(2), Qt::AbsoluteSize );
        path.moveTo(relX(20),relY(45));
        path.lineTo(relX(200),relY(45));

        path.moveTo(relX(30),relY(40));
        path.lineTo(relX(30),relY(260));

        path.moveTo(relX(60),relY(40));
        path.lineTo(relX(60),relY(260));

        path.moveTo(relX(125),relY(40));
        path.lineTo(relX(125),relY(260));

        path.moveTo(relX(150),relY(40));
        path.lineTo(relX(150),relY(260));

        path.moveTo(relX(175),relY(40));
        path.lineTo(relX(175),relY(260));

        f.setPointSize(8);
        painter.setFont(f);
        painter.drawText(relX(22), relY(44), trUtf8("Рб."));
        painter.drawText(relX(32), relY(44), trUtf8("Вид док."));
        painter.drawText(relX(62), relY(44), trUtf8("Артикал"));
        painter.drawText(relX(130), relY(44), trUtf8("Датум"));
        painter.drawText(relX(155), relY(44), trUtf8("Количина"));
        painter.drawText(relX(180), relY(44), trUtf8("Цена"));
        path.moveTo(relX(20),relY(275));
        path.lineTo(relX(70),relY(275));
        path.moveTo(relX(140),relY(275));
        path.lineTo(relX(190),relY(275));
        painter.drawText(relX(25), relY(280), trUtf8("Предал"));
        painter.drawText(relX(145), relY(280), trUtf8("Примил"));


        painter.drawPath(path);
        QStandardItemModel * modelIspratnica2 = m_analitikaKomintenti->getModel();
        if (modelIspratnica2)
        {
            int maxRowPage = 35;
            maxpage = modelIspratnica2->rowCount() / (maxRowPage + 1) + 1;
            int pagefrom = page * maxRowPage;
            int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();

            for (int row = pagefrom; row < pageto; row++)
            {
                for (int col = 0; col < modelIspratnica2->columnCount(); col++)
                {
                    switch (col)
                    {
                    case 0: painter.drawText(relX(21), relY(50 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
                    case 1: painter.drawText(relX(31), relY(50 + 6 * (row - pagefrom)), relX(30), relY(9), Qt::AlignLeft,  modelIspratnica2->item(row, 0)->text() + " - " +modelIspratnica2->item(row, 1)->text());break;
                    case 2: painter.drawText(relX(61), relY(50 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 3)->text());break;
                    case 4: painter.drawText(relX(125), relY(50 + 6 * (row - pagefrom)), relX(25), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 2)->text().left(10));break;
                    case 5: painter.drawText(relX(150), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 4)->text());break;
                    case 6: painter.drawText(relX(175), relY(50 + 6 * (row - pagefrom)), relX(24), relY(9), Qt::AlignRight, modelIspratnica2->item(row, 5)->text());break;
                    }
                }
            }
        }
        if( page < maxpage-1 )
            printer->newPage();
    }
#ifdef _demo
	drawDemo(painter);
#endif
}



void sterna::drawKomintentiLista(QPainter& painter)
{
	QFont f;
	QPainterPath path;

	f.setPointSize(12);
	painter.setFont(f);
	painter.drawText(relX(0), relY(3), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
	f.setPointSize(10);
	painter.setFont(f);
	painter.drawText(relX(0), relY(6), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

	f.setPointSize(20);
	painter.setFont(f);
	painter.drawText(relX(0), relY(12), relX(210), relY(9), Qt::AlignCenter, 
		trUtf8("Листа на коминтенти"));

    QPixmap image1(moi_logo);
    painter.drawPixmap(relX(90), relY(20), relX(30), relX(20), image1);

	painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(230), relX(2), relY(2), Qt::AbsoluteSize );
	path.moveTo(relX(20),relY(45));
	path.lineTo(relX(200),relY(45));

	path.moveTo(relX(30),relY(40));
	path.lineTo(relX(30),relY(270));

	path.moveTo(relX(110),relY(40));
	path.lineTo(relX(110),relY(270));

	path.moveTo(relX(125),relY(40));
	path.lineTo(relX(125),relY(270));

	path.moveTo(relX(145),relY(40));
	path.lineTo(relX(145),relY(270));

	path.moveTo(relX(160),relY(40));
	path.lineTo(relX(160),relY(270));

	path.moveTo(relX(175),relY(40));
	path.lineTo(relX(175),relY(270));

	f.setPointSize(8);
	painter.setFont(f);
	painter.drawText(relX(22), relY(44), trUtf8("Рб."));
	painter.drawText(relX(32), relY(44), trUtf8("Опис на артикал - услуга"));
	painter.drawText(relX(115), relY(44), trUtf8("Кол."));
	painter.drawText(relX(130), relY(44), trUtf8("Цена"));
	painter.drawText(relX(150), relY(44), trUtf8("Износ"));
	painter.drawText(relX(165), relY(44), trUtf8("ДДВ"));
	painter.drawText(relX(180), relY(44), trUtf8("Вкупно"));

	path.moveTo(relX(20),relY(275));
	path.lineTo(relX(70),relY(275));
	path.moveTo(relX(140),relY(275));
	path.lineTo(relX(190),relY(275));
	painter.drawText(relX(25), relY(280), trUtf8("Изработил"));
	painter.drawText(relX(145), relY(280), trUtf8("Директор"));

	painter.drawPath(path);
}
QString sterna::convertIntToText(int& num)
{
	QString t = trUtf8("Со зборови: ");
	int m = 0;
	int i = 0;
	int s = 0;
	int d = 0;
	int e = 0;
	m = num / qPow(10,6);
	num = num - m * qPow(10,6);
	i = num / qPow(10,3);
	num = num - i * qPow(10,3);
	s = num;
	if (m == 1)
	{
		QString temp = trUtf8("еденмилион");
		t += temp;
	}
	if (m == 2)
	{
		QString temp = trUtf8("двамилиона");
		t += convertSToText(m) + temp;
	}
	if (m > 2)
	{
		QString temp = (m == 1) ? trUtf8("милион") : trUtf8("милиони");
		t += convertSToText(m) + temp;
	}

	if (i == 1)
	{
		t += trUtf8("еднаилјада");
	}
	if (i == 2)
	{
		t += trUtf8("двеилјади");
	}
	if (i > 2)
	{
		t += convertSToText(i) + trUtf8("илјади");
	}

	t += (m || i) && e ? trUtf8("и") : "";
	if (s)
	{
		t += convertSToText(s) + trUtf8("денари");
	}
	return t;

}
void sterna::updateNavigator(QWidget* a, QWidget* b)
{
    b->setFocus();
    closeMyWidget();
    a->setFocus();
    m_left->updateSelection(a);
	ui.actionPrinter->setEnabled(false);
}
QString sterna::convertSToText(int& num)
{
	QString ss = "";
	int s = 0;
	int d = 0;
	int e = 0;
	s = num / qPow(10,2);
	num = num - s * qPow(10,2);
	if (num > 20)
	{
		d = num / qPow(10,1);
		num = num - d * qPow(10,1);
		e = num;
	}
	else
	{
		d = 0;
		e = num;
	}
	switch (s)
	{
	case 0: ss += (""); break; 
	case 1: ss += trUtf8("сто");; break; 
	case 2: ss += trUtf8("двеста"); break; 
	case 3: ss += trUtf8("триста"); break; 
	case 4: ss += trUtf8("четрсто"); break; 
	case 5: ss += trUtf8("петсто"); break; 
	case 6: ss += trUtf8("шесто"); break; 
	case 7: ss += trUtf8("седумсто"); break; 
	case 8: ss += trUtf8("осумсто"); break; 
	case 9: ss += trUtf8("деветсто"); break; 
	}
	switch (d)
	{
	case 0: ss += (""); break; 
	case 2: ss += trUtf8("дваесет");; break; 
	case 3: ss += trUtf8("триесет");; break; 
	case 4: ss += trUtf8("четириесет");; break; 
	case 5: ss += trUtf8("педесет");; break; 
	case 6: ss += trUtf8("шеесет");; break; 
	case 7: ss += trUtf8("седумдесет");; break; 
	case 8: ss += trUtf8("осумдесет");; break; 
	case 9: ss += trUtf8("деведесет");; break; 
	}
	ss += (s || d) && e ? trUtf8("и") : "";
	switch (e)
	{
	case 0: ss += (""); break; 
	case 1: ss += trUtf8("еден"); break; 
	case 2: ss += trUtf8("два"); break; 
	case 3: ss += trUtf8("три"); break; 
	case 4: ss += trUtf8("четири"); break; 
	case 5: ss += trUtf8("пет"); break; 
	case 6: ss += trUtf8("шест"); break; 
	case 7: ss += trUtf8("седум"); break; 
	case 8: ss += trUtf8("осум"); break; 
	case 9: ss += trUtf8("девет"); break; 
	case 10: ss += trUtf8("десет"); break; 
	case 11: ss += trUtf8("единаесет"); break; 
	case 12: ss += trUtf8("дванаесет"); break; 
	case 13: ss += trUtf8("тринаесет"); break; 
	case 14: ss += trUtf8("четиринаесет"); break; 
	case 15: ss += trUtf8("петнаесет"); break; 
	case 16: ss += trUtf8("шеснаесет"); break; 
	case 17: ss += trUtf8("седумнаесет"); break; 
	case 18: ss += trUtf8("осумнаесет"); break; 
	case 19: ss += trUtf8("деветнаесет"); break; 
	case 20: ss += trUtf8("дваесет"); break; 
	}
	return ss;
}


void sterna::drawIzvod(QPrinter *printer, QPainter& painter)
{
	painter.begin(printer);
	QFont f;
	QLocale loc;
	f.setPointSize(8);

	QPen pen;  // creates a default pen
	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(3);
	painter.setPen(pen);
	painter.drawLine (relX(0), relY(148), relX(210), relY(148));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	painter.setPen(pen);

	QPixmap image1(moi_nozici);
	painter.drawPixmap(relX(5), relY(146), relX(6), relX(4), image1);

	int pOffset = 148;
	for (int rr = 0; rr < 2; rr++)
	{
		painter.drawRoundedRect(relX(10), relY(30 + rr * pOffset), relX(100), relY(107), relX(0), relY(0), Qt::AbsoluteSize );
		for (int i = 0; i < 20; i++)
		{
			painter.drawLine (relX(10), relY(37 + i * 5 + rr * pOffset), relX(110), relY(37 + i * 5 + rr * pOffset));
		}
		painter.drawLine (relX(15), relY(30 + rr * pOffset), relX(15), relY(137 -15 + rr * pOffset));
		painter.drawLine (relX(60), relY(30 + rr * pOffset), relX(60), relY(137 + rr * pOffset));
		painter.drawLine (relX(75), relY(30 + rr * pOffset), relX(75), relY(137 + rr * pOffset));
		painter.drawLine (relX(90), relY(30 + rr * pOffset), relX(90), relY(137 + rr * pOffset));

		f.setPointSize(7);
		painter.setFont(f);		

		painter.drawText(relX(10), relY(30 + rr * pOffset), relX(5), relY(7), Qt::AlignCenter, trUtf8("Рб."));
		painter.drawText(relX(15), relY(30 + rr * pOffset), relX(45), relY(7), Qt::AlignCenter, trUtf8("Отпадни материјали"));
		painter.drawText(relX(60), relY(30 + rr * pOffset), relX(15), relY(7), Qt::AlignCenter, trUtf8("Вк.кгр"));
		painter.drawText(relX(75), relY(30 + rr * pOffset), relX(15), relY(7), Qt::AlignCenter, trUtf8("Цена."));
		painter.drawText(relX(90), relY(30 + rr * pOffset), relX(20), relY(7), Qt::AlignCenter, trUtf8("ВКУПНО."));

		f.setPointSize(7);
		painter.setFont(f);		

		for (int rr = 0; rr < 2; rr++)
		{
			for (int i = 0; i < 17; i++)
			{
				painter.drawText(relX(10), relY(37 + i * 5 + rr * pOffset), relX(5), relY(5), Qt::AlignCenter, QString::number(i + 1 , 10) +".");
			}
		}
	}



	f.setPointSize(8);
	painter.setFont(f);

// 	QStringList modelIzjavaInfo = m_myizjava->getIzjavaInfo();
// 	float iznos = 0.f;
// 	QStandardItemModel * modelIzjava2 = m_myizjava->getModel();

	for (int i = 0; i < 2; i++)
	{

		f.setPointSize(12);
		f.setBold(true);	
		painter.setFont(f);
		painter.drawText(relX(10), relY(148 * i + 10), moi_firma_info1);
		f.setPointSize(8);
		f.setBold(false);	
		painter.setFont(f);
		painter.drawText(relX(10), relY(148 * i + 14), moi_firma_banka1);
		painter.drawText(relX(10), relY(148 * i + 18), moi_firma_edb);

		QString kantarnaIzjavaText = trUtf8("КАНТАРНО-КАСА ИСПЛАТИ Бр. ")/* + modelIzjavaInfo.at(3) +"/" + (modelIzjavaInfo.at(4)).left(4)*/;
		painter.drawText(relX(10), relY(148 * i + 26), kantarnaIzjavaText);

		f.setPointSize(12);
		painter.setFont(f);
		QString izjavaText = trUtf8("ИЗЈАВА Број ")/*+ modelIzjavaInfo.at(3) + "/" + (modelIzjavaInfo.at(4)).left(4)*/;
		painter.drawText(relX(125), relY(148 * i + 25), izjavaText);
		f.setPointSize(8);
		painter.setFont(f);

		painter.drawText(relX(115), relY(148 * i + 35), trUtf8("Јас долупотпишаниот_____________________________"));

		painter.drawText(relX(115), relY(148 * i + 41), trUtf8("ЕМБГ_________________________со место на живеење"));

		painter.drawText(relX(115), relY(148 * i + 47), trUtf8("во град(с)______________________________________"));

		painter.drawText(relX(115), relY(148 * i + 53), trUtf8("лична карта_____________________________________"));

		painter.drawText(relX(115), relY(148 * i + 59), trUtf8("трансaкциска.сметка______________________________"));

		painter.drawText(relX(115), relY(148 * i + 65), trUtf8("банка депонент__________________________________"));

		painter.drawText(relX(115), relY(148 * i + 71), trUtf8("телефон________________________________________"));

		painter.drawText(relX(115), relY(148 * i + 77), trUtf8("мобилен________________________________________"));

		painter.drawText(relX(115), relY(148 * i + 83), moi_izjava1);
		painter.drawText(relX(115), relY(148 * i + 89), moi_izjava2);

		painter.drawText(relX(115), relY(148 * i + 95), trUtf8("_______________________________________________"));
		painter.drawText(relX(115), relY(148 * i + 105), trUtf8("На ") + moi_firma_info1);

		painter.drawText(relX(115), relY(148 * i + 110), moi_firma_banka1);
		painter.drawText(relX(115), relY(148 * i + 115), moi_firma_edb);

		painter.drawText(relX(115), relY(148 * i + 123), trUtf8("________________"));
		painter.drawText(relX(115), relY(148 * i + 126), trUtf8("Дата"));

		painter.drawText(relX(115), relY(148 * i + 135), trUtf8("________________________________"));
		painter.drawText(relX(115), relY(148 * i + 138), trUtf8("Изјавувач"));

		float vkupno = 0.f;
// 		if (modelIzjava2)
// 		{
// 			for (int row = 0; row < modelIzjava2->rowCount(); row++)
// 			{
// 				painter.drawText(relX(16), relY(148 * i + 38 + row * 5), relX(30), relY(5), Qt::AlignLeft, modelIzjava2->item(row, 2)->text());
// 				painter.drawText(relX(60), relY(148 * i + 38 + row * 5), relX(14), relY(5), Qt::AlignRight, modelIzjava2->item(row, 3)->text());
// 				painter.drawText(relX(75), relY(148 * i + 38 + row * 5), relX(14), relY(5), Qt::AlignRight, modelIzjava2->item(row, 5)->text());
// 				iznos = loc.toFloat( modelIzjava2->item(row, 3)->text()) * loc.toFloat( modelIzjava2->item(row, 5)->text());
// 				vkupno += iznos;
// 				painter.drawText(relX(90), relY(148 * i + 38 + row * 5), relX(19), relY(5), Qt::AlignRight, loc.toString( iznos, 'f', 2));
// 			}
// 		}
		painter.drawText(relX(16), relY(148 * i + 123), relX(35), relY(5), Qt::AlignRight, trUtf8("ЗБИР:"));
		painter.drawText(relX(16), relY(148 * i + 128), relX(35), relY(5), Qt::AlignRight, trUtf8("Персонален Данок 6.5%:"));
		painter.drawText(relX(16), relY(148 * i + 133), relX(35), relY(5), Qt::AlignRight, trUtf8("Вкупно:"));

		painter.drawText(relX(90), relY(148 * i + 123), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno, 'f', 2));
		painter.drawText(relX(90), relY(148 * i + 128), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno * 0.065, 'f', 2));
		painter.drawText(relX(90), relY(148 * i + 133), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno * 0.935, 'f', 2));

	}
	painter.end();
}


void sterna::drawIzjava(QPrinter *printer, QPainter& painter)
{
	painter.begin(printer);
	QFont f;
	QLocale loc;
	f.setPointSize(8);

	QPen pen;  // creates a default pen
	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(3);
	painter.setPen(pen);
	painter.drawLine (relX(0), relY(148), relX(210), relY(148));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	painter.setPen(pen);

	QPixmap image1(moi_nozici);
	painter.drawPixmap(relX(5), relY(146), relX(6), relX(4), image1);

	int pOffset = 148;
	for (int rr = 0; rr < 2; rr++)
	{
		painter.drawRoundedRect(relX(10), relY(30 + rr * pOffset), relX(100), relY(107), relX(0), relY(0), Qt::AbsoluteSize );
		for (int i = 0; i < 20; i++)
		{
			painter.drawLine (relX(10), relY(37 + i * 5 + rr * pOffset), relX(110), relY(37 + i * 5 + rr * pOffset));
		}
		painter.drawLine (relX(15), relY(30 + rr * pOffset), relX(15), relY(137 -15 + rr * pOffset));
		painter.drawLine (relX(60), relY(30 + rr * pOffset), relX(60), relY(137 + rr * pOffset));
		painter.drawLine (relX(75), relY(30 + rr * pOffset), relX(75), relY(137 + rr * pOffset));
		painter.drawLine (relX(90), relY(30 + rr * pOffset), relX(90), relY(137 + rr * pOffset));

		f.setPointSize(7);
		painter.setFont(f);		

		painter.drawText(relX(10), relY(30 + rr * pOffset), relX(5), relY(7), Qt::AlignCenter, trUtf8("Рб."));
		painter.drawText(relX(15), relY(30 + rr * pOffset), relX(45), relY(7), Qt::AlignCenter, trUtf8("Отпадни материјали"));
		painter.drawText(relX(60), relY(30 + rr * pOffset), relX(15), relY(7), Qt::AlignCenter, trUtf8("Вк.кгр"));
		painter.drawText(relX(75), relY(30 + rr * pOffset), relX(15), relY(7), Qt::AlignCenter, trUtf8("Цена."));
		painter.drawText(relX(90), relY(30 + rr * pOffset), relX(20), relY(7), Qt::AlignCenter, trUtf8("ВКУПНО."));

		f.setPointSize(7);
		painter.setFont(f);		

		for (int rr = 0; rr < 2; rr++)
		{
			for (int i = 0; i < 17; i++)
			{
				painter.drawText(relX(10), relY(37 + i * 5 + rr * pOffset), relX(5), relY(5), Qt::AlignCenter, QString::number(i + 1 , 10) +".");
			}
		}
	}



	f.setPointSize(8);
	painter.setFont(f);

	QStringList modelIzjavaInfo = m_myizjava->getIzjavaInfo();
	float iznos = 0.f;
	QStandardItemModel * modelIzjava2 = m_myizjava->getModel();

	for (int i = 0; i < 2; i++)
	{

		f.setPointSize(12);
		f.setBold(true);	
		painter.setFont(f);
		painter.drawText(relX(10), relY(148 * i + 10), moi_firma_info1);
		f.setPointSize(8);
		f.setBold(false);	
		painter.setFont(f);
		painter.drawText(relX(10), relY(148 * i + 14), moi_firma_banka1);
		painter.drawText(relX(10), relY(148 * i + 18), moi_firma_edb);

		QString kantarnaIzjavaText = trUtf8("КАНТАРНО-КАСА ИСПЛАТИ Бр. ") + modelIzjavaInfo.at(3) +"/" + (modelIzjavaInfo.at(4)).left(4);
		painter.drawText(relX(10), relY(148 * i + 26), kantarnaIzjavaText);

		f.setPointSize(12);
		painter.setFont(f);
		QString izjavaText = trUtf8("ИЗЈАВА Број ")+ modelIzjavaInfo.at(3) + "/" + (modelIzjavaInfo.at(4)).left(4);
		painter.drawText(relX(125), relY(148 * i + 25), izjavaText);
		f.setPointSize(8);
		painter.setFont(f);

		painter.drawText(relX(115), relY(148 * i + 35), trUtf8("Јас долупотпишаниот_____________________________"));
		painter.drawText(relX(155), relY(148 * i + 32), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(0));

		painter.drawText(relX(115), relY(148 * i + 41), trUtf8("ЕМБГ_________________________со место на живеење"));
		painter.drawText(relX(125), relY(148 * i + 38), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(5));

		painter.drawText(relX(115), relY(148 * i + 47), trUtf8("во град(с)______________________________________"));
		painter.drawText(relX(135), relY(148 * i + 44), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(2));

		painter.drawText(relX(115), relY(148 * i + 53), trUtf8("лична карта_____________________________________"));
		painter.drawText(relX(135), relY(148 * i + 50), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(6));

		painter.drawText(relX(115), relY(148 * i + 59), trUtf8("трансaкциска.сметка______________________________"));
		painter.drawText(relX(150), relY(148 * i + 56), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(8));
		
		painter.drawText(relX(115), relY(148 * i + 65), trUtf8("банка депонент__________________________________"));
		painter.drawText(relX(145), relY(148 * i + 62), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(7));
		
		painter.drawText(relX(115), relY(148 * i + 71), trUtf8("телефон________________________________________"));
		painter.drawText(relX(135), relY(148 * i + 68), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(9));
		
		painter.drawText(relX(115), relY(148 * i + 77), trUtf8("мобилен________________________________________"));
		painter.drawText(relX(135), relY(148 * i + 74), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(10));

		painter.drawText(relX(115), relY(148 * i + 83), moi_izjava1);
		painter.drawText(relX(115), relY(148 * i + 89), moi_izjava2);
		
		painter.drawText(relX(115), relY(148 * i + 95), trUtf8("_______________________________________________"));
		painter.drawText(relX(115), relY(148 * i + 105), trUtf8("На ") + moi_firma_info1);
		
		painter.drawText(relX(115), relY(148 * i + 110), moi_firma_banka1);
		painter.drawText(relX(115), relY(148 * i + 115), moi_firma_edb);

		painter.drawText(relX(115), relY(148 * i + 123), trUtf8("________________"));
		painter.drawText(relX(115), relY(148 * i + 120), relX(50), relY(5), Qt::AlignLeft, modelIzjavaInfo.at(4));
		painter.drawText(relX(115), relY(148 * i + 126), trUtf8("Дата"));

		painter.drawText(relX(115), relY(148 * i + 135), trUtf8("________________________________"));
		painter.drawText(relX(115), relY(148 * i + 138), trUtf8("Изјавувач"));

		float vkupno = 0.f;
		if (modelIzjava2)
		{
			for (int row = 0; row < modelIzjava2->rowCount(); row++)
			{
				painter.drawText(relX(16), relY(148 * i + 38 + row * 5), relX(30), relY(5), Qt::AlignLeft, modelIzjava2->item(row, 2)->text());
				painter.drawText(relX(60), relY(148 * i + 38 + row * 5), relX(14), relY(5), Qt::AlignRight, modelIzjava2->item(row, 3)->text());
				painter.drawText(relX(75), relY(148 * i + 38 + row * 5), relX(14), relY(5), Qt::AlignRight, modelIzjava2->item(row, 5)->text());
				iznos = loc.toFloat( modelIzjava2->item(row, 3)->text()) * loc.toFloat( modelIzjava2->item(row, 5)->text());
				vkupno += iznos;
				painter.drawText(relX(90), relY(148 * i + 38 + row * 5), relX(19), relY(5), Qt::AlignRight, loc.toString( iznos, 'f', 2));
			}
		}
		painter.drawText(relX(16), relY(148 * i + 123), relX(35), relY(5), Qt::AlignRight, trUtf8("ЗБИР:"));
		painter.drawText(relX(16), relY(148 * i + 128), relX(35), relY(5), Qt::AlignRight, trUtf8("Персонален Данок 6.5%:"));
		painter.drawText(relX(16), relY(148 * i + 133), relX(35), relY(5), Qt::AlignRight, trUtf8("Вкупно:"));

		painter.drawText(relX(90), relY(148 * i + 123), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno, 'f', 2));
		painter.drawText(relX(90), relY(148 * i + 128), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno * 0.065, 'f', 2));
		painter.drawText(relX(90), relY(148 * i + 133), relX(19), relY(5), Qt::AlignRight, loc.toString( vkupno * 0.935, 'f', 2));

	}
	painter.end();
}
void sterna::drawDnevenIzvestaj(QPrinter *printer,QPainter& painter)
{
	int maxpage = 1;
	for( int page=0; page<maxpage; page++)
	{
		QFont f;
		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(16), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);

		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(18), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		//         QPixmap image1(":/sterna/Resources/microsoft_logo.png");
		//         painter.drawPixmap(relX(90), relY(20), relX(30), relX(20), image1);

		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(20), Qt::AlignCenter, trUtf8("Отпад примен од други лица"));
		QString temp = m_dnevenpromet->getDatum();
		painter.drawText(relX(0), relY(22), relX(210), relY(25), Qt::AlignCenter, temp);

		f.setPointSize(8);


		painter.drawRoundedRect(relX(20), relY(40), relX(180), relY(220), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(20),relY(55));
		path.lineTo(relX(200),relY(55));

		path.moveTo(relX(30),relY(40));
		path.lineTo(relX(30),relY(260));

        for (int i = 1; i < 6;i++)
        {
            path.moveTo(relX(30 + i*3), relY(55));
            path.lineTo(relX(30 + i*3), relY(260));
        }

        path.moveTo(relX(48),relY(40));
        path.lineTo(relX(48),relY(260));

        path.moveTo(relX(52),relY(40));
        path.lineTo(relX(52),relY(260));

        path.moveTo(relX(95),relY(40));
        path.lineTo(relX(95),relY(260));

        path.moveTo(relX(142),relY(40));
		path.lineTo(relX(142),relY(260));

        for (int i = 0; i < 5; i++)
        {
            if (i % 2 == 0)
            {
                path.moveTo(relX(142 + i*10), relY(40));
                path.lineTo(relX(142 + i*10), relY(260));
            }
            else
            {
                path.moveTo(relX(142 + i*10), relY(55));
                path.lineTo(relX(142 + i*10), relY(260));
            }
        }
		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(22), relY(44), trUtf8("Рб."));
		painter.drawText(relX(32), relY(44), trUtf8("Шифра"));

		painter.drawText(relX(54), relY(44), trUtf8("Вид на отпад"));
		painter.drawText(relX(100), relY(44), trUtf8("Потекло на примениот отпад"));
		
        painter.drawText(relX(143), relY(44), trUtf8("Количина"));
        painter.drawText(relX(143), relY(47), trUtf8("на примен"));
        painter.drawText(relX(143), relY(50), trUtf8("отпад"));
        painter.drawText(relX(143), relY(55), trUtf8("t"));
        painter.drawText(relX(153), relY(55), trUtf8("m3"));

        painter.drawText(relX(163), relY(44), trUtf8("Количина"));
        painter.drawText(relX(163), relY(47), trUtf8("на отпад"));
        painter.drawText(relX(163), relY(50), trUtf8("од увоз"));
        painter.drawText(relX(163), relY(55), trUtf8("t"));
        painter.drawText(relX(173), relY(55), trUtf8("m3"));

        painter.drawText(relX(185), relY(44), trUtf8("Понатамо-"));
        painter.drawText(relX(185), relY(47), trUtf8("шно по-"));
        painter.drawText(relX(185), relY(50), trUtf8("стапување"));

        

		painter.drawText(relX(25), relY(270), trUtf8("Датум _______________"));
        painter.drawText(relX(25), relY(280), trUtf8("Место________________"));

        painter.drawText(relX(95), relY(270), trUtf8("МП"));
        painter.drawText(relX(145), relY(270), trUtf8("Одговорно лице"));
        painter.drawText(relX(145), relY(280), trUtf8("_____________________"));

		painter.drawPath(path);
        QStandardItemModel * modelIspratnica2 = m_dnevenpromet->getModel();
		if (modelIspratnica2)
		{
			int maxRowPage = 30;
			maxpage = modelIspratnica2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelIspratnica2->rowCount() ? (page + 1) * maxRowPage : modelIspratnica2->rowCount();
            QString sifra = "";
            int sif = 0;
            int modSif = 0;
            int resSif = 0;
			float kolTon = 0;
            for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col < 6; col++)
				{
					
                    switch (col)
					{
					case 0: painter.drawText(relX(21), relY(60 + 6 * (row - pagefrom)), relX(8), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
                    case 1: 
                            sifra = modelIspratnica2->item(row, 0)->text();
                            sif = sifra.toInt();
                            for(int i = 0; i < 6; i++)
                            {
                                modSif = sif % 10;
                                sif = sif / 10;
                                painter.drawText(relX(46 - i*3), relY(60 + 6 * (row - pagefrom)), relX(70), relY(9), Qt::AlignLeft, QString::number(modSif));
                            }
                            break;
					case 2: painter.drawText(relX(53), relY(60 + 6 * (row - pagefrom)), relX(42), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 1)->text());break;
					case 3: painter.drawText(relX(96), relY(60 + 6 * (row - pagefrom)), relX(54), relY(9), Qt::AlignLeft, modelIspratnica2->item(row, 2)->text());break;
					case 4: 
                        kolTon = modelIspratnica2->item(row, 3)->text().toFloat() / 1000;
                        painter.drawText(relX(131), relY(60 + 6 * (row - pagefrom)), relX(20), relY(9), Qt::AlignRight, QString::number(kolTon,'f', 3));break;
                    case 5: painter.drawText(relX(183), relY(60 + 6 * (row - pagefrom)), relX(15), relY(9), Qt::AlignLeft, trUtf8("транспорт"));break;

                    }
				}
			}
		}
		if( page < maxpage-1 )
			printer->newPage();
	}
}
void sterna::drawPovratnica(QPrinter *printer, QPainter& painter)
{
	QLocale loc;
	int maxpage = 1;
	double suma = 0.0f;
	double ddv = 0.0f;
	double sumaDDV = 0.0f;
	double DDV5 = 0;
	double DDV18 = 0;
	double OsnovicaDDV5 = 0;
	double OsnovicaDDV18 = 0;
	QPen pen;
	QStringList modelFakturaInfo = m_povratnicamaster->getIspratnicaInfo();

	QFont f;
	for( int page=0; page<maxpage; page++)
	{

		QPainterPath path;

		f.setPointSize(12);
		painter.setFont(f);
		painter.drawText(relX(0), relY(15), relX(210), relY(6), Qt::AlignCenter, moi_firma_info1);
		f.setPointSize(10);
		painter.setFont(f);
		painter.drawText(relX(0), relY(20), relX(210), relY(9), Qt::AlignCenter, moi_firma_info2);

		QPixmap image1(moi_logo);
		painter.drawPixmap(relX(90), relY(30), relX(30), relX(20), image1);

		f.setPointSize(18);
		painter.setFont(f);
#ifdef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Повратницa"));
#endif

#ifndef _alea
		painter.drawText(relX(100), relY(50), relX(100), relY(60), Qt::AlignRight, trUtf8("Повратницa"));
#endif

		f.setPointSize(8);

		painter.setFont(f);

		QString textNumberS = "0000"+modelFakturaInfo.at(4);
		textNumberS = textNumberS.right(4);
		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(160), relY(60), relX(40), relY(65), Qt::AlignRight, trUtf8("Сериски Број: ") + moi_god + "-" + textNumberS + moi_prefix_prodavnica);
		f.setBold(false);
		painter.setFont(f);
		painter.drawText(relX(160), relY(65), relX(40), relY(70), Qt::AlignRight, trUtf8("Датум: ") + modelFakturaInfo.at(3));
		int rok = modelFakturaInfo.at(5).toInt();
		QString separ = modelFakturaInfo.at(3).mid(4,1);
		QDateTime dateTimeTemp = QDateTime::fromString(modelFakturaInfo.at(3),"yyyy" + separ + "MM" + separ + "dd");
		dateTimeTemp = dateTimeTemp.addDays(rok);
		painter.drawText(relX(160), relY(70), relX(40), relY(75), Qt::AlignRight, trUtf8("Валута: ") + dateTimeTemp.toString("yyyy" + separ + "MM" + separ + "dd"));
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawRoundedRect(relX(10), relY(55), relX(80), relY(30), relX(3), relY(3), Qt::AbsoluteSize );
		painter.drawText(relX(15), relY(60), trUtf8("До:"));

		f.setBold(true);
		painter.setFont(f);
		painter.drawText(relX(15), relY(65), modelFakturaInfo.at(0));
		painter.drawText(relX(15), relY(70), modelFakturaInfo.at(1));
		painter.drawText(relX(15), relY(75), modelFakturaInfo.at(2));
		f.setBold(false);
		painter.setFont(f);

		painter.drawText(relX(10), relY(35), relX(60), relY(40), Qt::AlignLeft, moi_firma_banka1);
		painter.drawText(relX(10), relY(40), relX(60), relY(45), Qt::AlignLeft, moi_firma_banka2);
		painter.drawText(relX(10), relY(45), relX(60), relY(50), Qt::AlignLeft, moi_firma_edb);

		painter.drawRoundedRect(relX(10), relY(90), relX(190), relY(145), relX(2), relY(2), Qt::AbsoluteSize );
		path.moveTo(relX(10),relY(97)); //rb
		path.lineTo(relX(200),relY(97));

		path.moveTo(relX(15),relY(90)); //naziv
		path.lineTo(relX(15),relY(235));

		path.moveTo(relX(80),relY(90)); //edm
		path.lineTo(relX(80),relY(235));

		path.moveTo(relX(92),relY(90)); //kol
		path.lineTo(relX(92),relY(235));

		path.moveTo(relX(105),relY(90)); //cena -ddv
		path.lineTo(relX(105),relY(235));

		path.moveTo(relX(120),relY(90));
		path.lineTo(relX(120),relY(235));

		path.moveTo(relX(130),relY(90));
		path.lineTo(relX(130),relY(235));

		path.moveTo(relX(140),relY(90));
		path.lineTo(relX(140),relY(235));

		path.moveTo(relX(160),relY(90));
		path.lineTo(relX(160),relY(235));

		path.moveTo(relX(180),relY(90));
		path.lineTo(relX(180),relY(235));

		f.setPointSize(8);
		painter.setFont(f);
		painter.drawText(relX(11), relY(94), trUtf8("Рб."));
		painter.drawText(relX(16), relY(94), trUtf8("Опис на артикал - услуга"));
		painter.drawText(relX(81), relY(94), trUtf8("Едм."));
		painter.drawText(relX(93), relY(94), trUtf8("Кол."));
		painter.drawText(relX(106), relY(93), trUtf8("Цена"));
		painter.drawText(relX(106), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(121), relY(94), trUtf8("Раб.%"));
		painter.drawText(relX(131), relY(94), trUtf8("ДДВ%"));
		painter.drawText(relX(141), relY(93), trUtf8("Вк.Износ"));
		painter.drawText(relX(141), relY(96), trUtf8("без ДДВ"));
		painter.drawText(relX(161), relY(94), trUtf8("ДДВ Износ"));
		painter.drawText(relX(181), relY(93), trUtf8("Вк.Вредност"));
		painter.drawText(relX(181), relY(96), trUtf8("со ДДВ"));
		f.setPointSize(8);
		painter.setFont(f);

		path.moveTo(relX(10),relY(275));
		path.lineTo(relX(56),relY(275));
		path.moveTo(relX(60),relY(275));
		path.lineTo(relX(108),relY(275));
		path.moveTo(relX(110),relY(275));
		path.lineTo(relX(153),relY(275));
		path.moveTo(relX(155),relY(275));
		path.lineTo(relX(198),relY(275));


		painter.drawText(relX(11), relY(278), trUtf8("Примил и согласен сум"));
		painter.drawText(relX(11), relY(280), trUtf8("со условите од оваа фактура"));

		painter.drawText(relX(60), relY(278), trUtf8("Предал"));
		painter.drawText(relX(110), relY(278), trUtf8("Фактурирал"));
		painter.drawText(relX(155), relY(278), trUtf8(""));
		painter.drawText(relX(110), relY(282), moi_fakturiral);
		painter.drawText(relX(155), relY(282), moi_direktor);


		painter.drawText(relX(140), relY(265), trUtf8("МП"));
		painter.drawText(relX(155), relY(265), trUtf8("Овластено лице"));
		painter.drawText(relX(155), relY(268), trUtf8("за потпис на фактура"));

		path.moveTo(relX(10),relY(249));
		path.lineTo(relX(200),relY(249));
		painter.drawPath(path);

		QStandardItemModel * modelFaktura2 = m_povratnicamaster->getModel2();
		double cenaDDV = 0;
		double DDV = 0;


		if (modelFaktura2)
		{
			int maxRowPage = 21;
			maxpage = modelFaktura2->rowCount() / (maxRowPage + 1) + 1;
			int pagefrom = page * maxRowPage;
			int pageto = (page + 1) * maxRowPage < modelFaktura2->rowCount() ? (page + 1) * maxRowPage : modelFaktura2->rowCount();

			for (int row = pagefrom; row < pageto; row++)
			{
				for (int col = 0; col <= 10; col++)
				{
					switch (col)
					{
					case 0: painter.drawText(relX(11), relY(100 + 6 * (row - pagefrom)), relX(4), relY(9), Qt::AlignLeft, QString::number(row + 1, 10));break;
					case 1: 
					#ifndef _alea
						painter.drawText(relX(16), relY(97 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, trUtf8("Шифра: ") + modelFaktura2->item(row, col )->text());
					#endif
		
						painter.drawText(relX(16), relY(100 + 6 * (row - pagefrom)), relX(64), relY(9), Qt::AlignLeft, modelFaktura2->item(row, col + 1)->text());
						break;
					case 2: painter.drawText(relX(81), relY(100 + 6 * (row - pagefrom)), relX(11), relY(9), Qt::AlignLeft, modelFaktura2->item(row, 4)->text());break;
					case 3: painter.drawText(relX(93), relY(100 + 6 * (row - pagefrom)), relX(12), relY(9), Qt::AlignRight,  modelFaktura2->item(row, 3)->text());break;
					case 4: 
						cenaDDV =  loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						DDV =  loc.toDouble(modelFaktura2->item(row, col + 4 )->text());
						painter.drawText(relX(106), relY(100 + 6 * (row - pagefrom)), relX(14), relY(9), Qt::AlignRight,  loc.toString( (cenaDDV / (1 + DDV / 100)), 'f', 2));
						break;
					case 5: painter.drawText(relX(121), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
						//				case 6: painter.drawText(relX(118), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 7: painter.drawText(relX(131), relY(100 + 6 * (row - pagefrom)), relX(9), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());break;
					case 8: painter.drawText(relX(141), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							OsnovicaDDV18 = OsnovicaDDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							OsnovicaDDV5 = OsnovicaDDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;

					case 9: painter.drawText(relX(161), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						ddv =ddv + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						if (DDV == 18)
						{
							DDV18 = DDV18 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						} 
						else if (DDV == 5)
						{
							DDV5 = DDV5 + loc.toDouble(modelFaktura2->item(row, col + 1)->text());
						}
						break;
					case 10: painter.drawText(relX(181), relY(100 + 6 * (row - pagefrom)), relX(19), relY(9), Qt::AlignRight,  modelFaktura2->item(row, col + 1)->text());
						sumaDDV =sumaDDV + loc.toDouble(modelFaktura2->item(row, col + 1)->text());

						break;
					}
				}
			}
		}
		if(page < maxpage - 1)
			printer->newPage();
	}
	CHelperClass hlp(this);
	painter.drawText(relX(130), relY(235), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен Износ"));
	painter.drawText(relX(170), relY(235), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV - ddv), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(130), relY(240), relX(40), relY(10), Qt::AlignRight, trUtf8("Вкупен ДДВ"));
	painter.drawText(relX(170), relY(240), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(ddv), 'f', 2) + trUtf8("  ден."));

	f.setBold(true);
	painter.setFont(f);
	painter.drawText(relX(90), relY(245), relX(80), relY(10), Qt::AlignRight, trUtf8("Вкупно за наплата денари со пресметан ДДВ"));
	painter.drawText(relX(170), relY(245), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(sumaDDV), 'f', 2) + trUtf8("  ден."));
	f.setBold(false);
	painter.setFont(f);
	painter.drawRoundedRect(relX(10), relY(236), relX(140), relY(9), relX(1), relY(1), Qt::AbsoluteSize );

	painter.drawText(relX(12), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(5%)"));
	painter.drawText(relX(46), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(12), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Основица за ДДВ(18%)"));
	painter.drawText(relX(46), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(OsnovicaDDV18), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(236), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ  (5%)"));
	painter.drawText(relX(110), relY(236), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV5), 'f', 2) + trUtf8("  ден."));

	painter.drawText(relX(80), relY(241), relX(40), relY(10), Qt::AlignLeft, trUtf8("Вкупен ДДВ (18%)"));
	painter.drawText(relX(110), relY(241), relX(30), relY(10), Qt::AlignRight, loc.toString( hlp.rouded(DDV18), 'f', 2) + trUtf8("  ден."));


	// 	painter.drawText(relX(15), relY(280), trUtf8("Фактурирал"));

	f.setPointSize(7);
	painter.setFont(f);
	int p = int(sumaDDV + 0.5f);
	QString t = convertIntToText(p);
	QString t1 = trUtf8("Рок на плаќање ")+ modelFakturaInfo.at(5)+trUtf8(" дена од денот на фактурирањето.Во спротивно пресметуваме законска камата.");
	painter.drawText(relX(10), relY(249), relX(120), relY(6), Qt::AlignLeft, t);
	painter.drawText(relX(10), relY(258), relX(130), relY(6), Qt::AlignLeft, t1);
	QString t2 = trUtf8("Рекламации се примаат во рок од 3 дена од приемот на стоката со уреден записник.");
	painter.drawText(relX(10), relY(261), relX(130), relY(6), Qt::AlignLeft, t2);
	QString t3 = trUtf8("Во случај на спор надлежен е Стопански суд.");
	painter.drawText(relX(10), relY(264), relX(130), relY(6), Qt::AlignLeft, t3);

#ifdef _demo
	drawDemo(painter);
#endif

}

void sterna::drawDemo(QPainter& painter)
{
	painter.setPen(Qt::red);
	painter.save();
	painter.rotate(45);
	QFont m_font;
	m_font.setPointSize(20);
	painter.setFont(m_font);
	painter.drawText(500, 500, QString(trUtf8("ДЕМО ВЕРЗИЈА - АПЛИКАЦИЈА СТЕРНА - (c) HardwareSoftwareGroup - ДЕМО ВЕРЗИЈА ")));
	painter.restore();
	painter.setPen( Qt::black );
}
