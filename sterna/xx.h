#ifndef Singleton_H
#define Singleton_H
#include "qmybaseformwidget.h"
#include <QDateTime>

#include <QStringList>


class Singleton 
{
public: 
	typedef struct 
	{
		QDateTime fakturaData;
		QDateTime fakturaValuta;
		float iznos;
		float plateno;
		QString komintent_naziv;
		QString komintent_id;
	} tinfoFakturi;

	typedef std::vector<tinfoFakturi> tListInfoFakturi;
    static Singleton* Instance();
	int getUserID(){return m_user_id;}
	void setUserID(int userID){ m_user_id = userID;}
	QStringList getUserInfo(){return m_infoVraboten;}
	void setUserInfo(QStringList infoVraboten){ m_infoVraboten = infoVraboten;}
	tListInfoFakturi m_listFakturiS; 
	QRect getMainRect(){return m_rect;}
	void setMainRect(QRect t_rect){ m_rect = t_rect;}
	QStringList getArtikliColumnWidth(){return m_colWidth;}
	void setArtikliColumnWidth(QStringList a_colWidth){ m_colWidth = a_colWidth;}

	QStringList getKomintentiColumnWidth(){return m_colWidth_k;}
	void setKomintentiColumnWidth(QStringList a_colWidth_k){ m_colWidth_k = a_colWidth_k;}

	// kalkulacija priemnica
	QStringList getKalkulacija_ColumnWidth(){return m_colWidth_kalk;}
	void setKalkulacija_ColumnWidth(QStringList a_colWidth_kalk){ m_colWidth_kalk = a_colWidth_kalk;}
	QStringList getKalkulacija_Detail_ColumnWidth(){return m_colWidth_kalk_detail;}
	void setKalkulacija_Detail_ColumnWidth(QStringList a_colWidth_kalk_detail){ m_colWidth_kalk_detail = a_colWidth_kalk_detail;}
	QStringList getKalkulacijaVnes_ColumnWidth(){return m_colWidth_kalkVnes;}
	void setKalkulacijaVnes_ColumnWidth(QStringList a_colWidth_kalkVnes){ m_colWidth_kalkVnes = a_colWidth_kalkVnes;}
	QStringList getKalkulacijaKorekcija_ColumnWidth(){return m_colWidth_kalkKorekcija;}
	void setKalkulacijaKorekcija_ColumnWidth(QStringList a_colWidth_kalkKorekcija){ m_colWidth_kalkKorekcija = a_colWidth_kalkKorekcija;}

	// ispratnica
	QStringList getIspratnica_ColumnWidth(){return m_colWidth_ispr;}
	void setIspratnica_ColumnWidth(QStringList a_colWidth_ispr){ m_colWidth_ispr = a_colWidth_ispr;}
	QStringList getIspratnica_Detail_ColumnWidth(){return m_colWidth_ispr_detail;}
	void setIspratnica_Detail_ColumnWidth(QStringList a_colWidth_ispr_detail){ m_colWidth_ispr_detail = a_colWidth_ispr_detail;}
	QStringList getIspratnicaVnes_ColumnWidth(){return m_colWidth_isprVnes;}
	void setIspratnicaVnes_ColumnWidth(QStringList a_colWidth_isprVnes){ m_colWidth_isprVnes = a_colWidth_isprVnes;}
	QStringList getIspratnicaKorekcija_ColumnWidth(){return m_colWidth_isprKorekcija;}
	void setIspratnicaKorekcija_ColumnWidth(QStringList a_colWidth_isprKorekcija){ m_colWidth_isprKorekcija = a_colWidth_isprKorekcija;}

	// faktura
	QStringList getFaktura_ColumnWidth(){return m_colWidth_fakt;}
	void setFaktura_ColumnWidth(QStringList a_colWidth_fakt){ m_colWidth_fakt = a_colWidth_fakt;}
	QStringList getFaktura_Detail_ColumnWidth(){return m_colWidth_fakt_detail;}
	void setFaktura_Detail_ColumnWidth(QStringList a_colWidth_fakt_detail){ m_colWidth_fakt_detail = a_colWidth_fakt_detail;}
	QStringList getFakturaVnes_ColumnWidth(){return m_colWidth_faktVnes;}
	void setFakturaVnes_ColumnWidth(QStringList a_colWidth_faktVnes){ m_colWidth_faktVnes = a_colWidth_faktVnes;}
	QStringList getFakturaKorekcija_ColumnWidth(){return m_colWidth_faktKorekcija;}
	void setFakturaKorekcija_ColumnWidth(QStringList a_colWidth_faktKorekcija){ m_colWidth_faktKorekcija = a_colWidth_faktKorekcija;}

	// profaktura
	QStringList getProFaktura_ColumnWidth(){return m_colWidth_profakt;}
	void setProFaktura_ColumnWidth(QStringList a_colWidth_profakt){ m_colWidth_profakt = a_colWidth_profakt;}
	QStringList getProFaktura_Detail_ColumnWidth(){return m_colWidth_profakt_detail;}
	void setProFaktura_Detail_ColumnWidth(QStringList a_colWidth_profakt_detail){ m_colWidth_profakt_detail = a_colWidth_profakt_detail;}
	QStringList getProFakturaVnes_ColumnWidth(){return m_colWidth_profaktVnes;}
	void setProFakturaVnes_ColumnWidth(QStringList a_colWidth_profaktVnes){ m_colWidth_profaktVnes = a_colWidth_profaktVnes;}
	QStringList getProFakturaKorekcija_ColumnWidth(){return m_colWidth_profaktKorekcija;}
	void setProFakturaKorekcija_ColumnWidth(QStringList a_colWidth_profaktKorekcija){ m_colWidth_profaktKorekcija = a_colWidth_profaktKorekcija;}

	// smetki - fiskalni
	QStringList getSmetka_ColumnWidth(){return m_colWidth_smetka;}
	void setSmetka_ColumnWidth(QStringList a_colWidth_smetka){ m_colWidth_smetka = a_colWidth_smetka;}
	QStringList getSmetka_Detail_ColumnWidth(){return m_colWidth_smetka_detail;}
	void setSmetka_Detail_ColumnWidth(QStringList a_colWidth_smetka_detail){ m_colWidth_smetka_detail = a_colWidth_smetka_detail;}

	QStringList getSmetkaVnes_ColumnWidth(){return m_colWidth_smetkaVnes;}
	void setSmetkaVnes_ColumnWidth(QStringList a_colWidth_smetkaVnes){ m_colWidth_smetkaVnes = a_colWidth_smetkaVnes;}
	QStringList getSmetkaKorekcija_ColumnWidth(){return m_colWidth_smetkaKorekcija;}
	void setSmetkaKorekcija_ColumnWidth(QStringList a_colWidth_smetkaKorekcija){ m_colWidth_smetkaKorekcija = a_colWidth_smetkaKorekcija;}


protected: 
	//Singleton();
private:
	int m_user_id;
	QRect m_rect;
	QStringList m_infoVraboten;
	static Singleton* _instance;
	QStringList m_colWidth;
	QStringList m_colWidth_k;
	QStringList m_colWidth_kalk_detail;
	QStringList m_colWidth_kalk;
	QStringList m_colWidth_kalkVnes;
	QStringList m_colWidth_kalkKorekcija;

	QStringList m_colWidth_ispr;
	QStringList m_colWidth_ispr_detail;
	QStringList m_colWidth_isprVnes;
	QStringList m_colWidth_isprKorekcija;


	QStringList m_colWidth_fakt;
	QStringList m_colWidth_fakt_detail;
	QStringList m_colWidth_faktVnes;
	QStringList m_colWidth_faktKorekcija;

	QStringList m_colWidth_profakt;
	QStringList m_colWidth_profakt_detail;
	QStringList m_colWidth_profaktVnes;
	QStringList m_colWidth_profaktKorekcija;

	
	QStringList m_colWidth_smetka;
	QStringList m_colWidth_smetka_detail;
	QStringList m_colWidth_smetkaVnes;
	QStringList m_colWidth_smetkaKorekcija;


};
#endif // Singleton_H