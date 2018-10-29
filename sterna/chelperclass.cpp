#include "chelperclass.h"
#include "QSqlQuery"
#include "QSqlRecord"
#include "QVariant"
#include <QLocale>
#include <QRegExp>
#include <QDate>
#include <QDateTime>
#include "qt_windows.h"
#include "qwindowdefs_win.h"
#include <shellapi.h>
#include <QTextCodec>




CHelperClass::CHelperClass(QObject *parent)
    : QObject(parent)
	, m_vkupenPriliv(0.f)
	, m_vkupenOdliv(0.f)
{

}

CHelperClass::~CHelperClass()
{

}

bool CHelperClass::isKomintentExists(QString &komName)
{
    bool stat = false;
    QString temp = "select id, naziv, adresa, tel, mobil, zirosmetka, edb, deponent, sifdejnost, mb, zabeleska1, zabeleska2, rabat, grad from komintenti where naziv like '%";
    temp += komName;
    temp += "%' ";
    QSqlQuery query(temp);
    while (query.next()) 
    {
        if (query.value(query.record().indexOf("naziv")).toString() == komName)
        {
            stat = true;
        }
    } 
    return stat;
}

bool CHelperClass::isKomintentExistsInStore(QString &komID)
{
	bool stat = false;
	QString temp = "select id from magacin where komintent_id = ";
	temp += komID;
	temp += " ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		stat = true;
	} 
	return stat;
}

QString  CHelperClass::getKomintentName(QString m_id)
{
	QString prevoznikIme = "";
	QString temp = "select naziv from komintenti where id = ";
	temp += m_id;

	QSqlQuery query(temp);
	while (query.next()) 
	{
		prevoznikIme = query.value(0).toString();
	} 
	return prevoznikIme;
}

bool CHelperClass::isArtikliExists(QString &artName)
{
    bool stat = false;
    QString temp = "select id, sifra, artikal, edm, ref, kataloski_broj, "
        "art_nabavna_cena, art_nabavna_cena_valuta,  "
        "art_prodazna_cena, art_prodazna_cena_valuta "
        " from artikli where artikal like '%";
    temp += artName;
    temp += "%' ";
    QSqlQuery query(temp);
    while (query.next()) 
    {
        if (query.value(query.record().indexOf("artikal")).toString() == artName)
        {
            stat = true;
        }
    } 
    return stat;
}

int CHelperClass::isSifraArtikalExists(QString mSifra)
{
	int res = 0;
	QString temp = "select sifra from artikli where sifra = '" + mSifra + "'";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		res = 1;
	} 
	return res;
}


int CHelperClass::isSifraArtikalExistsInSTore(QString mSifra)
{
	int res = 0;
	QString temp = "select id from magacin where artikal_id = " + mSifra + " ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		res = 1;
	} 
	return res;
}

int CHelperClass::isSifraKomintentExists(QString mSifra)
{
	int res = 0;

	QString temp = "select sifra from komintenti where sifra = '" + mSifra + "'";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		res = 1;
	} 
	return res;
}

int CHelperClass::genSifraArtikal()
{
	int maxArt = -1;
	QString temp = "select sifra from artikli ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		maxArt = maxArt > query.value(query.record().indexOf("sifra")).toInt() ? maxArt : query.value(query.record().indexOf("sifra")).toInt();
	} 
	return maxArt + 1;
}

bool CHelperClass::isBankExists(QString &bankName)
{
    bool stat = false;
    QString temp = "select  BankIme from TBank where BankIme like '%";
    temp += bankName;
    temp += "%' ";
    QSqlQuery query(temp);
    while (query.next()) 
    {
        if (query.value(query.record().indexOf("BankIme")).toString() == bankName)
        {
            stat = true;
        }
    } 
    return stat;
}

bool CHelperClass::isFakturaExists(QString &fakturaId, QString& tip )
{
	bool stat = false;
	QString temp = "select  dok_id"
		" from dokumenti where dok_id = ";
	temp += fakturaId;
	temp += " and dok_tip = ";
    temp += tip;
    temp += "";

    QSqlQuery query(temp);
	while (query.next()) 
	{
		if (query.value(query.record().indexOf("dok_id")).toString() == fakturaId)
		{
			stat = true;
		}
	} 
	return stat;
}


void CHelperClass::fakturaStatus(QStandardItem *item,  QString& tip)
{
	QString fakturaBroj = item->text();
	float vk_iznos = 0;
// 	getFakturaPlatenIznos(fakturaBroj, tip);
//     float vk_iznos = getFakturaVkupenIznos(fakturaBroj, tip);	
	bool okInt;
	m_plateno = 0;
	vk_iznos = 0;
	QMap<int, float>::iterator itPlateno = m_mapPlateno.find(fakturaBroj.toInt(&okInt, 10));
	if (itPlateno != m_mapPlateno.end()) 
	{
		m_plateno = itPlateno.value();
		m_plateno = floor(m_plateno + .5f);
	}

	QMap<int, float>::iterator itFakturirano = m_mapZadolzuvanje.find(fakturaBroj.toInt(&okInt, 10));
	if (itFakturirano != m_mapZadolzuvanje.end()) 
	{
		vk_iznos = itFakturirano.value();
		vk_iznos = floor(vk_iznos + .5f);
	}

	
	float razlika = vk_iznos - m_plateno;
    if (vk_iznos != 0 && abs(vk_iznos - m_plateno) < 0.1)
	{
		QIcon ic1(":/sterna/Resources/ok.png");
		item->setIcon(ic1);
		item->setToolTip(trUtf8("Платена "));
	}
	else if ((m_plateno > 0) && ((vk_iznos - m_plateno) >= 0.1))
	{
		QIcon ic1(":/sterna/Resources/information.png");
		item->setIcon(ic1);
		item->setToolTip(trUtf8("Делумно платена "));
	}
    else if ((m_plateno == 0) && (vk_iznos > 0))
    {
        QIcon ic1(":/sterna/Resources/stop.png");
        item->setIcon(ic1);
        item->setToolTip(trUtf8("Неплатена "));
    }
    else if (vk_iznos <= 0)
    {
        QIcon ic1(":/sterna/Resources/error.png");
        item->setIcon(ic1);
        item->setToolTip(trUtf8("Невалидна "));
    }
    else if (m_plateno > vk_iznos )
    {
        QIcon ic1(":/sterna/Resources/error.png");
        item->setIcon(ic1);
        item->setToolTip(trUtf8("Невалидна "));
    }

}

void CHelperClass::getFakturaPlatenIznos(QString& faktBroj, QString& tip)
{
	QString temp = "select  sum(priliv), sum(odliv) "
		" from TStavka where Faktura_ID   = ";
	temp += faktBroj;
	temp += " and Izvod_Tip = ";
	temp += tip;
	temp += "";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		m_vkupenPriliv = query.value(0).toFloat();
		m_vkupenOdliv = query.value(1).toFloat();
	}
    m_plateno = tip == "40" ? m_vkupenPriliv : m_vkupenOdliv;
}



float CHelperClass::getPlatenIznos()
{
    return m_plateno;
}

float CHelperClass::getFakturaVkupenIznos(QString& faktBroj, QString& tip)
{
    float vkupenIznos = 0.f;
    QString temp = ""; 
    if (tip != "21")
	{
		temp = " select sum((ikol*icena*(100-rabat)/100)*(1 + a.ddv/100))  ";
	}
	else
	{
		temp = " select sum((ikol*icena*(100-rabat)/100))  ";
	}

	temp += " from magacin m                                            "
    " left join artikli a on m.artikal_id = a.id                "
    " where dok_id = ";

    temp += faktBroj;
    temp += " and dok_tip = ";
    temp += tip;
    temp += "";

    QSqlQuery query(temp);
    while (query.next()) 
    {
        vkupenIznos = query.value(0).toFloat();
    }
    return vkupenIznos;
}


QString CHelperClass::getArtikalByID(QString text)
{
	int artikal_id = text.toInt();
	QSqlQuery query;
	query.prepare("select artikal from artikli where id = :id");
	query.bindValue(":id", artikal_id);	
	query.exec();
	query.next();
	return (query.value(0).toString());
}

float CHelperClass::getVkKol(QString& artikal_ID, QString& tip)
{
	float vkKolicina = 0.f;
	QString temp = "select  sum(ikol) "
		" from magacin where artikal_id   = ";
	temp += artikal_ID;
	temp += " and dok_tip = ";
	temp += tip;
	temp += "";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		vkKolicina = query.value(0).toFloat();
	}
	return vkKolicina;
}


void CHelperClass::createSaldoProizvodiPrilivMapAll()
{
	m_mapPriliv.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float vkupenPrilivProizvod = 0.f;
	QString temp = 

		" SELECT magacin.artikal_id, magacin.komintent_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip ) "
		" WHERE (magacin.dok_tip between  20 and 29) "
		" GROUP BY magacin.artikal_id, magacin.komintent_id ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		komintent_id = query.value(1).toString();
		keyT = art_id + "Key" + komintent_id;
		vkupenPrilivProizvod = query.value(2).toFloat();
		m_mapPriliv.insert(keyT, rouded(vkupenPrilivProizvod));	
	}
}
void CHelperClass::createSaldoProizvodiPrilivMapAllbezKomintent()
{
	m_mapPriliv.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float vkupenPrilivProizvod = 0.f;
	QString temp = 

		" SELECT magacin.artikal_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip ) "
		" WHERE (magacin.dok_tip between  20 and 29) "
		" GROUP BY magacin.artikal_id ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		keyT = art_id + "Key" ;
		vkupenPrilivProizvod = query.value(1).toFloat();
		m_mapPriliv.insert(keyT, rouded(vkupenPrilivProizvod));	
	}
}

void CHelperClass::createSaldoArtikliOdlivMapAll()
{
	m_mapOdliv.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float vkupenOdlivArtikal = 0.f;
	QString temp = 
		" SELECT magacin.artikal_id,magacin.komintent_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip) "
		" WHERE (magacin.dok_tip between 41 and 60 and dokumenti.dok_status = 0) "
		" GROUP BY magacin.artikal_id, magacin.komintent_id ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		komintent_id = query.value(1).toString();
		keyT = art_id + "Key" + komintent_id;
		vkupenOdlivArtikal = query.value(2).toFloat();
		m_mapOdliv.insert(keyT, rouded(vkupenOdlivArtikal));	
	}
}
void CHelperClass::createSaldoArtikliOdlivMapAll_bezKomintent()
{
	m_mapOdliv.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float vkupenOdlivArtikal = 0.f;
	QString temp = 
		" SELECT magacin.artikal_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip) "
		" WHERE (magacin.dok_tip between 40 and 49) "
		" GROUP BY magacin.artikal_id ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		keyT = art_id + "Key" ;
		vkupenOdlivArtikal = query.value(1).toFloat();
		m_mapOdliv.insert(keyT, rouded(vkupenOdlivArtikal));	
	}
}

void CHelperClass::createSaldoProizvodiPrilivMapAll(QString date1, QString date2)
{
	m_mapPriliv.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float vkupenPrilivProizvod = 0.f;
	QString temp = 

		" SELECT magacin.artikal_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip ) "
		" WHERE (magacin.dok_tip between  20 and 29) and dokumenti.datum between #"+date1+"# and #"+date2+"# "
		" GROUP BY magacin.artikal_id ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		vkupenPrilivProizvod = query.value(1).toFloat();
		m_mapPriliv.insert(art_id, vkupenPrilivProizvod);	
	}
}

void CHelperClass::createSaldoArtikliOdlivMapAll(QString date1, QString date2)
{
	m_mapOdliv.clear();
	QString art_id = "";
	float vkupenOdlivArtikal = 0.f;
	QString temp = 
		" SELECT magacin.artikal_id, SUM(ikol) "
		" FROM dokumenti "  
		" LEFT JOIN magacin ON (dokumenti.dok_id = magacin.dok_id and dokumenti.dok_tip = magacin.dok_tip) "
		" WHERE (magacin.dok_tip between 40 and 49) and dokumenti.datum between #"+date1+"# and #"+date2+"# "
		" GROUP BY magacin.artikal_id ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		vkupenOdlivArtikal = query.value(1).toFloat();
		m_mapOdliv.insert(art_id, vkupenOdlivArtikal);	
	}
}



float CHelperClass::getLagerListaAll(QString & item,  QString& tip)
{
	QString artikalBroj = item;
	float result = 0.f;
	float priliv = 0.f;
	float odliv = 0.f;

	if (tip == "PRILIV")
	{
		QMap<QString, float>::iterator itPriliv = m_mapPriliv.find(artikalBroj);
		if (itPriliv != m_mapPriliv.end()) 
		{
			priliv = itPriliv.value();
		}
		result = priliv;
	} 

	else if(tip == "ODLIV")
	{
		QMap<QString, float>::iterator itOdliv = m_mapOdliv.find(artikalBroj);
		if (itOdliv != m_mapOdliv.end()) 
		{
			odliv = itOdliv.value();
		}
		result = odliv;
	}
	return result;
}


float CHelperClass::getVkKolBetween(QString& artikal_ID, QString& tip, QString& tip1)
{
	float vkKolicina = 0.f;
	QString temp = "select  sum(ikol) "
		" from magacin where artikal_id   = ";
	temp += artikal_ID;
	temp += " and dok_tip between ";
	temp += tip;
	temp += " and ";
	temp += tip1;

	QSqlQuery query(temp);
	while (query.next()) 
	{
		vkKolicina = query.value(0).toFloat();
	}
	return vkKolicina;
}


float CHelperClass::getVkKolByDate(QString& artikal_ID, QString& tip, QDate & mDate, QDate & mDate2)
{
	float vkKolicina = 0.f;
	QString temp = "";
	QString temp_tip = "";
	if (tip == "20")
	{
		temp = " select sum(ikol) from dokumenti "
			" left join magacin "
			" on dokumenti.dok_tip = magacin.dok_tip and "
			" dokumenti.dok_id = magacin.dok_id "
			" where dokumenti.dok_tip between 20 and 21 "
			" and artikal_id = " + artikal_ID +
			" and datum between #" + mDate.toString("yyyy/MM/dd") + "# and #" +  mDate2.toString("yyyy/MM/dd") + "#";
	}
	else
	{
		temp = " select sum(ikol) from dokumenti "
			" left join magacin "
			" on dokumenti.dok_tip = magacin.dok_tip and "
			" dokumenti.dok_id = magacin.dok_id "
			" where dokumenti.dok_tip between 40 and 45 "
			" and artikal_id = " + artikal_ID +
			" and datum between #" + mDate.toString("yyyy/MM/dd") + "# and #" +  mDate2.toString("yyyy/MM/dd") + "#";
	}
	
	QSqlQuery query(temp);
	while (query.next()) 
	{
		vkKolicina = query.value(0).toFloat();
	}
	return vkKolicina;
}

void CHelperClass::createZadolzuvanjeMap(QString& tip)
{
	m_mapZadolzuvanje.clear();
	int fakt_id = 0;
	float vkupenIznos = 0.f;

	QString temp = ""; 
	if (tip == "20")
	{
		temp = " select dok_id, sum((ikol*nab_cena*(100-rabat)/100))  ";
	}
	else if (tip == "25")
	{
		temp = "  select dok_id, sum((ikol*prod_cena*(100-rabat)/100))  ";
	}
	else if (tip == "40")
	{
		temp = " select dok_id, sum((ikol*prod_cena*(100-rabat)/100))  ";
	}

	temp += " from magacin m                                            "
	" left join artikli a on m.artikal_id = a.id "
	" where dok_tip = " + tip +
	" group by dok_id, dok_tip    ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		fakt_id = query.value(0).toInt();
		vkupenIznos = rouded(query.value(1).toFloat());
		m_mapZadolzuvanje.insert(fakt_id, vkupenIznos);
	}
}

void CHelperClass::createPlatenoMap(QString& tip)
{
	m_mapPlateno.clear();
	int fakt_id = 0;
	float vkupenPriliv = 0.f;
	float vkupenOdliv = 0.f;

	QString temp = 

	" select Dok_Id, sum(IznosPlaten) "
		" from Izvod_Plakanje "
		" where Dok_Tip = "+ tip +
		" group by Dok_Tip, Dok_Id ";


	QSqlQuery query(temp);
	while (query.next()) 
	{
		fakt_id = query.value(0).toInt();
		vkupenPriliv = rouded(query.value(1).toFloat());
		vkupenOdliv = rouded(query.value(1).toFloat());
		if (tip == "40")
		{
			m_mapPlateno.insert(fakt_id, vkupenPriliv);
		} 
		else if (tip == "20")
		{
			m_mapPlateno.insert(fakt_id, vkupenOdliv);
		}
		else if (tip == "25")
		{
			m_mapPlateno.insert(fakt_id, vkupenOdliv);
		}
	}
}

void CHelperClass::createStatusMap(QString& tip)
{
	createPlatenoMap(tip);
	createZadolzuvanjeMap(tip);
}

void CHelperClass::createListaIzlezniFakturiIznosi(QString &tip)
{
    m_mapFakturi.clear();
    QString dok_id = "";
    fakturiData dataFakt;

    QString temp = "";
	if (tip == "20")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * nab_cena * (1-rabat / 100)), "
			" sum(ikol * nab_cena * (1-rabat/100) - ikol * nab_cena * (1 - rabat/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "40")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "48")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "150")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "60")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "25")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}
	else if (tip == "80")
	{
		temp =
			" select magacin.dok_tip, magacin.dok_id, "
			" sum(ikol * prod_cena * (1-rabat / 100) / (1 + artikli.ddv / 100)), "
			" sum(ikol * prod_cena * (1-rabat/100) - ikol * prod_cena * (1 - rabat/100) /(1 + artikli.ddv/100)) "
			" from magacin "
			" left join artikli  on magacin.artikal_id = artikli.id "
			" group by magacin.dok_tip, magacin.dok_id "
			" having magacin.dok_tip = " + tip +" ";
	}

    QSqlQuery query(temp);
    while (query.next()) 
    {
        dok_id = query.value(1).toString();
        dataFakt.iznos = query.value(2).toFloat();
        dataFakt.ddv = query.value(3).toFloat();
        dataFakt.vkupno = (dataFakt.iznos + dataFakt.ddv);
		m_mapFakturi.insert(dok_id, dataFakt);
    }

}

void CHelperClass::createPovratnicaFakturiIznosi()
{
	m_mapPovratnici.clear();
	QString dok_id = "";
	fakturiData dataFakt;

	QString temp = 
		" select  IzleznaFakturaBroj, sum(IznosVraten) "
		" from povratniciPlakanje "
		" group by IzleznaFakturaBroj ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		dok_id = query.value(0).toString();
		dataFakt.vkupno = query.value(1).toFloat();
		dataFakt.iznos = 0;
		dataFakt.ddv = 0;
		m_mapPovratnici.insert(dok_id, dataFakt);
	}
}

QString CHelperClass::getFakturaBrojOdPovratnica(QString povratnica_id)
{
	QString fakt_br = "-1";
	QString temp = 
		" select  IzleznaFakturaBroj "
		" from povratniciPlakanje "
		" where Dok_ID ="+povratnica_id;
	QSqlQuery query(temp);
	while (query.next()) 
	{
		fakt_br = query.value(0).toString();
	}
	return fakt_br;
}

QStringList CHelperClass::getVraboteniInfo(QString& u, QString& p)
{
	QStringList info;
	QString fakt_br = "";
	QString temp = 
		" select id,korisnicko_ime, pasword, ime, prezime, adresa, grad, tel, uloga, user_id "
		" from vraboteni "
		" where korisnicko_ime ='"+u+"' and pasword = '"+p+"'";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		info << query.value(0).toString() 
			<< query.value(1).toString() 
			<< query.value(2).toString() 
			<< query.value(3).toString() 
			<< query.value(4).toString() 
			<< query.value(5).toString() 
			<< query.value(6).toString() 
			<< query.value(7).toString() 
			<< query.value(8).toString() 
			<< query.value(9).toString() 
			;
	}
	return info;
}

float CHelperClass::getIznosOdPovratnica(QString povratnica_id, QString faktura_br )
{
	float iznos = 0.f;
	QString temp = 
		" select  IznosVraten "
		" from povratniciPlakanje "
		" where Dok_ID ="+povratnica_id + " and IzleznaFakturaBroj = '" + faktura_br+"'";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		iznos = query.value(0).toFloat();
	}
	return iznos;
}


float CHelperClass::getPovratnicaFakturaVkupno(QString& dok_id )
{
	float vkupno = 0.0f;
	QMap <QString, fakturiData>::iterator it = m_mapPovratnici.find(dok_id);
	if (it != m_mapPovratnici.end()) 
	{
		vkupno = it.value().vkupno;
	}
	return vkupno;
}

void CHelperClass::createListaKomintenti(QString &tip)
{
    m_mapKomintentDetailInfo.clear();
    QString dok_id = "";

    QString temp = 
        "select distinct komintenti.naziv, komintenti.adresa, komintenti.tel, komintenti.mobil, komintenti.zirosmetka, komintenti.edb, komintenti.grad "
        "from dokumenti "
        "left join komintenti on dokumenti.komintent_id = komintenti.id "
        "where dok_tip = "+ tip +"  ";
    QSqlQuery query(temp);
    while (query.next()) 
    {
        dok_id = query.value(0).toString();
        QString temp = trUtf8("      Назив : ")+query.value(0).toString()+"<br>"+
                       trUtf8("     Адреса : ")+query.value(1).toString()+"<br>"+
                       trUtf8("        Тел : ")+query.value(2).toString()+"<br>"+
                       trUtf8("    Мобилен : ")+query.value(3).toString()+"<br>"+
                       trUtf8("Жиро сметка : ")+query.value(4).toString()+"<br>"+
                       trUtf8("        ЕДБ : ")+query.value(5).toString()+"<br>"+
                       trUtf8("       Град : ")+query.value(6).toString();

        m_mapKomintentDetailInfo.insert(dok_id, temp);
    }
}


double CHelperClass::rouded(double num)
{ 
	int n = 4;
	// round 2 decimal
	return floor(num * pow(10., n) + .5) / pow(10., n);
}


void CHelperClass::createArtikliMap()
{
    m_mapArtikli.clear();
    QString artikal_id = "";
    QString artikal_naziv = "";

    QString temp = 
        " select id, artikal from artikli ";

    QSqlQuery query(temp);
    while (query.next()) 
    {
        artikal_id = query.value(0).toString();
        artikal_naziv = query.value(1).toString();
        m_mapArtikli.insert(artikal_id, artikal_naziv);
    }
}

void CHelperClass::createKomintentiMap()
{
    m_mapKomintenti.clear();
    QString komintenti_id = "";
    QString komintenti_naziv = "";

    QString temp = 
        " select id, naziv from komintenti ";

    QSqlQuery query(temp);
    while (query.next()) 
    {
        komintenti_id = query.value(0).toString();
        komintenti_naziv = query.value(1).toString();
        m_mapKomintenti.insert(komintenti_id, komintenti_naziv);
    }
}


QString CHelperClass::getArtikalNameByID(QString& id)
{
    QString artikalName = "";
    QMap<QString, QString>::iterator itArtikal = m_mapArtikli.find(id);
    if (itArtikal != m_mapArtikli.end()) 
    {
        artikalName = itArtikal.value();
    }
    return artikalName;
}

QString CHelperClass::getKomintentNameByID(QString& id)
{
    QString komintentName = "";
    QMap<QString, QString>::iterator itKomintent = m_mapKomintenti.find(id);
    if (itKomintent != m_mapKomintenti.end()) 
    {
        komintentName = itKomintent.value();
    }
    return komintentName;
}


void CHelperClass::createSifraMap()
{
    m_mapSifri.clear();
    QString artikal_id = "";
    QString artikal_sifra = "";

    QString temp = 
        " select id, sifra from artikli ";

    QSqlQuery query(temp);
    while (query.next()) 
    {
        artikal_id = query.value(0).toString();
        artikal_sifra = query.value(1).toString();
        m_mapSifri.insert(artikal_id, artikal_sifra);
    }
}


QString CHelperClass::getSifraNameByID(QString& id)
{
    QString sifraName = "";
    QMap<QString, QString>::iterator itSifra = m_mapSifri.find(id);
    if (itSifra != m_mapSifri.end()) 
    {
        sifraName = itSifra.value();
    }
    return sifraName;
}


float CHelperClass::getFakturaIznos(QString& dok_id )
{
    float iznos = 0.0f;
    QMap <QString, fakturiData>::iterator it = m_mapFakturi.find(dok_id);
    if (it != m_mapFakturi.end()) 
    {
        iznos = it.value().iznos;
    }
    return iznos;
}

float CHelperClass::getFakturaDDV(QString& dok_id )
{
    float ddv = 0.0f;
    QMap <QString, fakturiData>::iterator it = m_mapFakturi.find(dok_id);
    if (it != m_mapFakturi.end()) 
    {
        ddv = it.value().ddv;
    }
    return ddv;
}

float CHelperClass::getFakturaVkupno(QString& dok_id )
{
    float vkupno = 0.0f;
    QMap <QString, fakturiData>::iterator it = m_mapFakturi.find(dok_id);
    if (it != m_mapFakturi.end()) 
    {
        vkupno = it.value().vkupno;
    }
    return vkupno;
}

QString CHelperClass::getKomintentDetail(QString& dok_id )
{
    QString info = "";
    QMap <QString, QString>::iterator it = m_mapKomintentDetailInfo.find(dok_id);
    if (it != m_mapKomintentDetailInfo.end()) 
    {
        info = it.value();
    }
    return info;
}


void CHelperClass::getFakturaIznosiAll( QString& tip)
{
	mapIznosi.clear();
	QString temp = 

		" select Dok_Id, sum(IznosPlaten) "
		" from Izvod_Plakanje "
		" where Dok_Tip = "+ tip +
		" group by Dok_Tip, Dok_Id ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		QString m_fakturiId = query.value(0).toString();
		float m_vkupenPriliv = query.value(1).toFloat();
		float m_vkupenOdliv = query.value(1).toFloat();

		tdataInfo temp;
		temp.priliv = m_vkupenPriliv;
		temp.odliv = m_vkupenOdliv;
		mapIznosi.insert(m_fakturiId, temp);
	}
}

float CHelperClass::getFakturaPrilivIznos(QString& dok_id )
{
	float iznos = 0.0f;
	QMap <QString, tdataInfo>::iterator it = mapIznosi.find(dok_id);
	if (it != mapIznosi.end()) 
	{
		iznos = it.value().priliv;
	}
	return iznos;
}

float CHelperClass::getFakturaOdlivIznos(QString& dok_id )
{
	float iznos = 0.0f;
	QMap <QString, tdataInfo>::iterator it = mapIznosi.find(dok_id);
	if (it != mapIznosi.end()) 
	{
		iznos = it.value().odliv;
	}
	return iznos;
}

bool CHelperClass::isIzvodExists(QString &bankaId, QString &izvodId)
{
	bool stat = false;
	QString temp = " select IzvodBr from Izvodi where BankaId  = " + bankaId + " and IzvodBr =" + izvodId;
	QSqlQuery query(temp);
	while (query.next()) 
	{
		if (query.value(query.record().indexOf("IzvodBr")).toString() == izvodId)
		{
			stat = true;
		}
	} 
	return stat;
}

QString CHelperClass::GetRandomString()
{
	QString randomString;
	QDateTime currentDateTime = QDateTime::currentDateTime();
	quint64 tt = currentDateTime.toMSecsSinceEpoch();
	randomString = QString::number(tt);
	return randomString;
}


QString CHelperClass::getPlatenIznosZaFaktura( QString& tip, QString &faktBr)
{
	QString resA;
	QString temp = 
		" select Dok_Tip, Dok_Id, sum(IznosPlaten) "
		" from Izvod_Plakanje "
		" where Dok_Tip = "+ tip +" and Dok_Id = " + faktBr +
		" group by Dok_Tip, Dok_Id ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		resA = query.value(2).toString();
	}
	return resA;
}

QString CHelperClass::getVrabotenNextID()
{
	QString user_br = "";
	QString temp = 
		" select max (user_id) +1 as nextID "
		" from vraboteni "
		" where user_id < 9000";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		 user_br =  query.value(0).toString() ;
	}
	return user_br;
}

int CHelperClass::calcMaxIdTblKalkulacii()
{
	int m_id = -1;
	QString temp = "select max(dok_id) from dokumenti where dok_tip = 20 ";
	QSqlQuery query(temp);
	QString country1 = "";
	int fieldNo = query.record().indexOf("max(dok_id)");
	while (query.next()) 
	{
		m_id = query.value(0).toInt() + 1;
	}
	return m_id;
}

int CHelperClass::calcMaxIdTblKalkulaciiStavki()
{
	int m_id = -1;
	QString temp = "select max(dok_id) from magacin where dok_tip = 20 ";
	QSqlQuery query(temp);
	QString country1 = "";
	int fieldNo = query.record().indexOf("max(dok_id)");
	while (query.next()) 
	{
		m_id = query.value(0).toInt() + 1;
	}
	return m_id;
}


void CHelperClass::calcPrilivOdlivPoKomintent()
{
	QString d_dok_tip;
	QString mKey;
	QString d_komintent_id;
	float d_iznos = 0.f;

	QString temp = 
		" select d.dok_tip,d.komintent_id, sum(ikol*prod_cena*(1-m.rabat/100)), sum(ikol*nab_cena*(1-m.rabat/100)) "
		" from dokumenti d "
		" left join magacin m on d.dok_id=m.dok_id and d.dok_tip=m.dok_tip "
		" group by d.dok_tip,d.komintent_id ";	
	QSqlQuery query(temp);

	while (query.next()) 
	{
		d_dok_tip = query.value(0).toString();
		d_komintent_id = query.value(1).toString();
		mKey = d_komintent_id + "Key" + d_dok_tip;
		if (d_dok_tip == "20")
		{
			d_iznos = query.value(3).toFloat();
			m_mapPrilivOdlivPoKomintent.insert(mKey, d_iznos);
		} 
		else if(d_dok_tip == "25")
		{
			d_iznos = query.value(2).toFloat();
			m_mapPrilivOdlivPoKomintent.insert(mKey, d_iznos);
		}
		else if(d_dok_tip == "40")
		{
			d_iznos = query.value(2).toFloat();
			m_mapPrilivOdlivPoKomintent.insert(mKey, d_iznos);
		}
	}
	QString temp1 = 
		" select d.dok_tip,d.komintent_id,faktura_ispratnica,sum(ikol*prod_cena*(1-m.rabat/100)), sum(ikol*nab_cena*(1-m.rabat/100)) "
		" from dokumenti d "
		" left join magacin m on d.dok_id=m.dok_id and d.dok_tip=m.dok_tip "
		" group by d.dok_tip,d.komintent_id, faktura_ispratnica "
		" having d.dok_tip = 60 and faktura_ispratnica = 0";
	QSqlQuery query1(temp1);

	while (query1.next()) 
	{
		d_dok_tip = query1.value(0).toString();
		d_komintent_id = query1.value(1).toString();
		mKey = d_komintent_id + "Key" + d_dok_tip;

		if(d_dok_tip == "60")
		{
			d_iznos = query1.value(3).toFloat();
			m_mapPrilivOdlivPoKomintent.insert(mKey, d_iznos);
		}
	}
}

float CHelperClass::getPrilivOdlivPoKomintent(QString& komintent_id, QString& dok_tip )
{
	float vkupno = 0.f;
	QString mKey = komintent_id + "Key" + dok_tip;
	QMap <QString, float>::iterator it = m_mapPrilivOdlivPoKomintent.find(mKey);
	if (it != m_mapPrilivOdlivPoKomintent.end()) 
	{
		vkupno = it.value();
	}
	return vkupno;
}


void CHelperClass::calcPlakanjaPoKomintent()
{
	QString d_dok_tip;
	QString mKey;
	QString d_komintent_id;
	float d_iznos = 0.f;

	QString temp = 
    " select komintentbr, sum(priliv), sum(odliv)  "
	" from izvod_stavki "
	" group by komintentbr ";
	QSqlQuery query(temp);

	while (query.next()) 
	{

		d_dok_tip = "40";
		d_komintent_id = query.value(0).toString();
		mKey = d_komintent_id + "Key" + d_dok_tip;
		d_iznos = query.value(1).toFloat();
		m_mapPlakanjePoKomintent.insert(mKey, d_iznos);

		d_dok_tip = "20";
		d_komintent_id = query.value(0).toString();
		mKey = d_komintent_id + "Key" + d_dok_tip;
		d_iznos = query.value(2).toFloat();
		m_mapPlakanjePoKomintent.insert(mKey, d_iznos);
	}
}

float CHelperClass::getPlakanjePoKomintent(QString& komintent_id, QString& dok_tip )
{
	float vkupno = 0.f;
	QString mKey = komintent_id + "Key" + dok_tip;
	QMap <QString, float>::iterator it = m_mapPlakanjePoKomintent.find(mKey);
	if (it != m_mapPlakanjePoKomintent.end()) 
	{
		vkupno = it.value();
	}
	return vkupno;
}

void CHelperClass::createMapPriemnici()
{
	m_mapPriemnici.clear();
	QString priemnica_id;


	QString temp = 
		" select dok_id, faktura_br, tip_dokument, datum_f_ra "
		" from dokumenti "
	    " where dok_tip = 20 ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		priemnica_id = query.value(0).toString();
		tpriemniciData itemTemp;
		itemTemp.dokument_id = query.value(1).toString();
		itemTemp.dokument_tip = query.value(2).toString();
		itemTemp.dokument_datum = query.value(3).toString();
		m_mapPriemnici.insert(priemnica_id, itemTemp);
	}
}

QString CHelperClass::getFakturaFromPriemnica(QString& priemnica_id)
{
	QString Faktura_Id = "";
	QMap<QString, tpriemniciData>::iterator itA = m_mapPriemnici.find(priemnica_id);
	if (itA != m_mapPriemnici.end()) 
	{
		Faktura_Id = itA->dokument_id;
	}
	return Faktura_Id;
}
QString CHelperClass::getTipDokumentFromPriemnica(QString& priemnica_id)
{
	QString Dokument_tip = "";
	QMap<QString, tpriemniciData>::iterator itA = m_mapPriemnici.find(priemnica_id);
	if (itA != m_mapPriemnici.end()) 
	{
		Dokument_tip = itA->dokument_tip;
	}
	return Dokument_tip;
}

void CHelperClass::createMapNefakturiraniIspratnici()
{
	m_mapNefakIspratnici.clear();
	int ispratnica_id = 0;


	QString temp = 
	    " select dok_id "
		" from dokumenti "
		" where dok_tip = 60 and faktura_ispratnica = 0 ";

	QSqlQuery query(temp);
	while (query.next()) 
	{
		ispratnica_id = query.value(0).toInt();
		m_mapNefakIspratnici.insert(ispratnica_id, ispratnica_id);
	}
}

bool CHelperClass::getNefaktiriranaIspratnica(int ispratnica_id)
{
	bool stat = false;
	QMap<int, int>::iterator itA = m_mapNefakIspratnici.find(ispratnica_id);
	if (itA != m_mapNefakIspratnici.end()) 
	{
		stat = false;
	}
	else
	{
		stat = true;
	}
	return stat;
}

long CHelperClass::printFiscal(QStringList itemArt)
{
	QString art;
	QString cena;
	QString kol;
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return -1;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");

	// 	'Otvoranje na fiskalna smetka
	QLocale loc;

	stream << QChar(0x20) << QChar(0x30) << QChar(0x31) << QChar(0x09) << QChar(0x31) << QChar(0x09) 
		<< QChar(0x09) << QChar(0x30) << QChar(0x09) << QChar(0x0d) << QChar(0x0a);
		
	
// 	'Pisuvanje artikli <seq> = Chr(35) ose Chr(36)
	
	for (int kk = 0; kk < itemArt.size(); kk++)
	{
		QStringList itemValue = itemArt.at(kk).split("<>");
		stream << QChar(35+kk);
		stream << QChar(0x31); // command
		art = itemValue.at(0);
		convertIme(stream, art); 
		stream << QChar(0x09);
		stream << QChar(0x31); // ddv tarifa 1;
		stream << QChar(0x09);
		cena = itemValue.at(1);
		stream << cena; // cena
		stream << QChar(0x09);
// 		stream << QChar(0x30); //flag za mkd
// 		stream << QChar(0x09);
		kol = itemValue.at(2);
// 		double tempKol = loc.toDouble(kol);
// 		kol = loc.toString(tempKol, 'f', 3);
		stream << QString(kol); // kol
		stream << QChar(0x09);


		stream << QChar(0x30); // discount type 0
		stream << QChar(0x09);
		stream << QChar(0x09);
		stream << QChar(0x09);


		stream << QChar(0x0d) << QChar(0x0a);
	}

// 	' TOTAL
	stream << QChar(0x26)  << QChar(0x35) << QChar(0x30) <<  QChar(0x09) << QChar(0x09) << QChar(0x0d) << QChar(0x0a);

// 
// 	'Zatvoranje smetka
	stream << QChar(0x25) << QChar(0x38) << QChar(0x0d) << QChar(0x0a);

	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	
	return 0;
}

QString CHelperClass::checkFiscal()
{
	bool stat = false;
	QFile file("PF500.out");
	if( !file.open( QIODevice::ReadOnly) )
	{
		int stop = 0;
		return false;
	}

	QTextStream stream( &file);
	QString line;
	while(!stream.atEnd())
	{
		line += stream.readLine();   
	}
	file.close();

	return line;
}

void CHelperClass::convertIme(QTextStream &stream, QString utfIme)
{
	QString imeE = "";
	utfIme = utfIme.left(20);
	utfIme = utfIme.toUpper();
	QString::iterator it;
	for (it = utfIme.begin(); it != utfIme.end(); it++)
	{
		if(QString(*it) == (QString)trUtf8("З")){imeE += "З";}
		else if(QString(*it) == (QString)trUtf8("з")){stream << trUtf8("з");}
		else if(QString(*it) == (QString)trUtf8("Џ")){stream << trUtf8("Џ");}
		else if(QString(*it) == (QString)trUtf8("џ")){stream << trUtf8("џ");}
		else if(QString(*it) == (QString)trUtf8("Ц")){stream << trUtf8("Ц");}
		else if(QString(*it) == (QString)trUtf8("ц")){stream << trUtf8("ц");}
		else if(QString(*it) == (QString)trUtf8("В")){stream << trUtf8("В");}
		else if(QString(*it) == (QString)trUtf8("Б")){stream << trUtf8("Б");}
		else if(QString(*it) == (QString)trUtf8("б")){stream << trUtf8("б");}
		else if(QString(*it) == (QString)trUtf8("Н")){stream << trUtf8("Н");}
		else if(QString(*it) == (QString)trUtf8("н")){stream << trUtf8("н");}
		else if(QString(*it) == (QString)trUtf8("М")){stream << trUtf8("М");}
		else if(QString(*it) == (QString)trUtf8("м")){stream << trUtf8("м");}
		else if(QString(*it) == (QString)trUtf8("А")){stream << trUtf8("А");}
		else if(QString(*it) == (QString)trUtf8("а")){stream << trUtf8("а");}
		else if(QString(*it) == (QString)trUtf8("С")){stream << trUtf8("С");}
		else if(QString(*it) == (QString)trUtf8("с")){stream << trUtf8("с");}
		else if(QString(*it) == (QString)trUtf8("Д")){stream << trUtf8("Д");}
		else if(QString(*it) == (QString)trUtf8("д")){stream << trUtf8("д");}
		else if(QString(*it) == (QString)trUtf8("Ф")){stream << trUtf8("Ф");}
		else if(QString(*it) == (QString)trUtf8("ф")){stream << trUtf8("ф");}
		else if(QString(*it) == (QString)trUtf8("Г")){stream << trUtf8("Г");}
		else if(QString(*it) == (QString)trUtf8("г")){stream << trUtf8("г");}
		else if(QString(*it) == (QString)trUtf8("Х")){stream << trUtf8("Х");}
		else if(QString(*it) == (QString)trUtf8("х")){stream << trUtf8("х");}
		else if(QString(*it) == (QString)trUtf8("Ј")){stream << trUtf8("Ј");}
		else if(QString(*it) == (QString)trUtf8("ј")){stream << trUtf8("ј");}
		else if(QString(*it) == (QString)trUtf8("К")){stream << trUtf8("К");}
		else if(QString(*it) == (QString)trUtf8("к")){stream << trUtf8("к");}
		else if(QString(*it) == (QString)trUtf8("Л")){stream << trUtf8("Л");}
		else if(QString(*it) == (QString)trUtf8("л")){stream << trUtf8("л");}
		else if(QString(*it) == (QString)trUtf8("Ч")){stream << trUtf8("Ч");}
		else if(QString(*it) == (QString)trUtf8("ч")){stream << trUtf8("ч");}
		else if(QString(*it) == (QString)trUtf8("Ќ")){stream << trUtf8("Ќ");}
		else if(QString(*it) == (QString)trUtf8("ќ")){stream << trUtf8("ќ");}
		else if(QString(*it) == (QString)trUtf8("Љ")){stream << trUtf8("Љ");}
		else if(QString(*it) == (QString)trUtf8("љ")){stream << trUtf8("љ");}
		else if(QString(*it) == (QString)trUtf8("Њ")){stream << trUtf8("Њ");}
		else if(QString(*it) == (QString)trUtf8("њ")){stream << trUtf8("њ");}
		else if(QString(*it) == (QString)trUtf8("Е")){stream << trUtf8("Е");}
		else if(QString(*it) == (QString)trUtf8("е")){stream << trUtf8("е");}
		else if(QString(*it) == (QString)trUtf8("Р")){stream << trUtf8("Р");}
		else if(QString(*it) == (QString)trUtf8("р")){stream << trUtf8("р");}
		else if(QString(*it) == (QString)trUtf8("Т")){stream << trUtf8("Т");}
		else if(QString(*it) == (QString)trUtf8("т")){stream << trUtf8("т");}
		else if(QString(*it) == (QString)trUtf8("Ѕ")){stream << trUtf8("Ѕ");}
		else if(QString(*it) == (QString)trUtf8("ѕ")){stream << trUtf8("ѕ");}
		else if(QString(*it) == (QString)trUtf8("У")){stream << trUtf8("У");}
		else if(QString(*it) == (QString)trUtf8("у")){stream << trUtf8("у");}
		else if(QString(*it) == (QString)trUtf8("И")){stream << trUtf8("И");}
		else if(QString(*it) == (QString)trUtf8("и")){stream << trUtf8("и");}
		else if(QString(*it) == (QString)trUtf8("О")){stream << trUtf8("О");}
		else if(QString(*it) == (QString)trUtf8("о")){stream << trUtf8("о");}
		else if(QString(*it) == (QString)trUtf8("П")){stream << trUtf8("П");}
		else if(QString(*it) == (QString)trUtf8("п")){stream << trUtf8("п");}
		else if(QString(*it) == (QString)trUtf8("Ш")){stream << trUtf8("Ш");}
		else if(QString(*it) == (QString)trUtf8("ш")){stream << trUtf8("ш");}
		else if(QString(*it) == (QString)trUtf8("Ѓ")){stream << trUtf8("Ѓ");}
		else if(QString(*it) == (QString)trUtf8("ѓ")){stream << trUtf8("ѓ");}
		else if(QString(*it) == (QString)trUtf8("Ж")){stream << trUtf8("Ж");}
		else if(QString(*it) == (QString)trUtf8("ж")){stream << trUtf8("ж");}
		else if(QString(*it) == (QString)trUtf8(" ")){stream << trUtf8(" ");}
		else if(QString(*it) == (QString)trUtf8(",")){stream << trUtf8(",");}
		else if(QString(*it) == (QString)trUtf8("1")){stream << trUtf8("1");}
		else if(QString(*it) == (QString)trUtf8("2")){stream << trUtf8("2");}
		else if(QString(*it) == (QString)trUtf8("3")){stream << trUtf8("3");}
		else if(QString(*it) == (QString)trUtf8("4")){stream << trUtf8("4");}
		else if(QString(*it) == (QString)trUtf8("5")){stream << trUtf8("5");}
		else if(QString(*it) == (QString)trUtf8("6")){stream << trUtf8("6");}
		else if(QString(*it) == (QString)trUtf8("7")){stream << trUtf8("7");}
		else if(QString(*it) == (QString)trUtf8("8")){stream << trUtf8("8");}
		else if(QString(*it) == (QString)trUtf8("9")){stream << trUtf8("9");}
		else if(QString(*it) == (QString)trUtf8("0")){stream << trUtf8("0");}
		else if(QString(*it) == (QString)trUtf8("*")){stream << trUtf8("*");}
		else if(QString(*it) == (QString)trUtf8("(")){stream << trUtf8("(");}
		else if(QString(*it) == (QString)trUtf8(")")){stream << trUtf8(")");}
	}
}

void CHelperClass::createListaKomintentiByID()
{
	m_mapKomintentByID.clear();
	QString tempID;
	QString tempSifra;

	QString temp = 
		" select distinct id, sifra "
		" from komintenti ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		tempID = query.value(0).toString();
		tempSifra = query.value(1).toString();

		m_mapKomintentByID.insert(tempID, tempSifra);
	}
}

QString CHelperClass::getSifraKomintentByID(QString& dok_id )
{
	QString retSifra = "";
	QMap <QString, QString>::iterator it = m_mapKomintentByID.find(dok_id);
	if (it != m_mapKomintentByID.end()) 
	{
		retSifra = it.value();
	}
	return retSifra;
}

long CHelperClass::printFiscalStorno(QStringList itemArt)
{
	QString art;
	QString cena;
	QString kol;
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return -1;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");

	// 	'Otvoranje na fiskalna smetka
	QLocale loc;

	stream << QChar(0x20) << QChar(0x30) << QChar(0x31) << QChar(0x09) << QChar(0x31) << QChar(0x09) 
		<< QChar(0x09) << QChar(0x31) << QChar(0x09) << QChar(0x0d) << QChar(0x0a);


	// 	'Pisuvanje artikli <seq> = Chr(35) ose Chr(36)

	for (int kk = 0; kk < itemArt.size(); kk++)
	{
		QStringList itemValue = itemArt.at(kk).split("<>");
		stream << QChar(35+kk);
		stream << QChar(0x31); // command
		art = itemValue.at(0);
		convertIme(stream, art); 
		stream << QChar(0x09);
		stream << QChar(0x31); // ddv tarifa 1;
		stream << QChar(0x09);
		cena = itemValue.at(1);
		stream << cena; // cena
		stream << QChar(0x09);
		// 		stream << QChar(0x30); //flag za mkd
		// 		stream << QChar(0x09);
		kol = itemValue.at(2);
// 		double tempKol = loc.toDouble(kol);
// 		kol = loc.toString(tempKol, 'f', 3);
		stream << QString(kol); // kol
		stream << QChar(0x09);


		stream << QChar(0x30); // discount type 0
		stream << QChar(0x09);
		stream << QChar(0x09);
		stream << QChar(0x09);


		stream << QChar(0x0d) << QChar(0x0a);
	}

	// 	' TOTAL
	stream << QChar(0x26)  << QChar(0x35) << QChar(0x30) <<  QChar(0x09) << QChar(0x09) << QChar(0x0d) << QChar(0x0a);

	// 
	// 	'Zatvoranje smetka
	stream << QChar(0x25) << QChar(0x38) << QChar(0x0d) << QChar(0x0a);


	file.close();
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	long result = 0;
	return result;
}

void CHelperClass::printFiscalPodesuvanjeDatumCas()
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;

	stream << QChar(0x2d) << QChar(0x3d);
	stream << dateCurr.toString("dd-MM-yy hh:mm:ss");
	stream << QChar(0x09);
	file.close();
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}

void CHelperClass::printFiscalDnevnoFiskalnoZatvoranje()
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;

	stream << QChar(0x2a) << QChar(0x45) << QChar(0x5a) << QChar(0x09);
	
	file.close();
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}

void CHelperClass::SluzbenIzlezNaPari(QString &iznosPari)
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;

	stream << QChar(0x29) << QChar(0x46) << QChar(0x31) << QChar(0x09);
	stream << iznosPari;
	stream << QChar(0x09);

	file.close();
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}

void CHelperClass::SluzbenVlezNaPari(QString &iznosPari)
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;

	stream << QChar(0x28) << QChar(0x46) << QChar(0x30) << QChar(0x09);
	stream << iznosPari;
	stream << QChar(0x09);

	file.close();
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}

void CHelperClass::printKontrolenIzvestajProsiren()
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;
	
	stream << QChar(0x27) << QChar(0x45) << QChar(0x58) << QChar(0x09);

	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}

void CHelperClass::printDetalenIzvestajPoPeriod(QString &date1, QString &date2)
{
	QFile file("PF500.IN");
	if( !file.open( QIODevice::WriteOnly) )
		return;
	QTextStream stream( &file);
	stream.setCodec("Windows-1251");
	QDateTime dateCurr = QDateTime::currentDateTime();
	QLocale loc;

	stream << QChar(0x5f) << QChar(0x5e) << QChar(0x31) << QChar(0x09);
	stream << date1 << QChar(0x09);
	stream << date2 << QChar(0x09);
	file.close();
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = L"Fiscal32.exe";        
	ShExecInfo.lpParameters = L"PF500.IN";   
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL; 
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}


void CHelperClass::createListProdCenaKalkulacijaMapAll()
{
	m_mapKalkulacija.clear();
	m_mapKalkulacija2.clear();
	QString art_id = "";
	QString komintent_id = "";
	QString keyT = "";
	float prod_cena = 0.f;
	float nab_cena = 0.f;
	QString temp = 
		" SELECT artikal_id,komintent_id, MAX(prod_cena), MAX(nab_cena) "
		" FROM magacin "  
		" WHERE (magacin.dok_tip between 20 and 39) "
		" GROUP BY artikal_id, komintent_id ";
	QSqlQuery query(temp);
	while (query.next()) 
	{
		art_id = query.value(0).toString();
		komintent_id = query.value(1).toString();
		keyT = art_id + "Key" + komintent_id;
		prod_cena = query.value(2).toFloat();
		nab_cena = query.value(3).toFloat();
		m_mapKalkulacija.insert(keyT, rouded(prod_cena));	
		m_mapKalkulacija2.insert(keyT, rouded(nab_cena));
	}
}

float CHelperClass::getProdCenaFromKalkulacija(QString & item)
{
	QString artikalBroj = item;
	float result = 0.f;


		QMap<QString, float>::iterator itPriliv = m_mapKalkulacija.find(artikalBroj);
		if (itPriliv != m_mapKalkulacija.end()) 
		{
			result = itPriliv.value();
		}
	return result;
}

float CHelperClass::getNabCenaFromKalkulacija(QString & item)
{
	QString artikalBroj = item;
	float result = 0.f;


	QMap<QString, float>::iterator itPriliv = m_mapKalkulacija2.find(artikalBroj);
	if (itPriliv != m_mapKalkulacija2.end()) 
	{
		result = itPriliv.value();
	}
	return result;
}

void CHelperClass::createListaIzvodiMap(QString bankaId)
{
	m_mapIzvod.clear();
	QString s_izvodbr = "";
	QString s_izvod_ref = "";
	
	float vkupenPrilivProizvod = 0.f;
	QString temp = 
	" select izvodbr, izvod_ref "
	" from izvodi "
	" where bankaid = ";
	temp += bankaId;
	QSqlQuery query(temp);
	while (query.next()) 
	{
		s_izvodbr = query.value(0).toString();
		s_izvod_ref = query.value(1).toString();
		
		vkupenPrilivProizvod = query.value(2).toFloat();
		m_mapIzvod.insert(s_izvodbr, s_izvod_ref);	
	}
}

QString CHelperClass::getIzvod_Ref(QString& izvodbr )
{
	QString izvod_ref = "";
	QMap <QString, QString>::iterator it = m_mapIzvod.find(izvodbr);
	if (it != m_mapIzvod.end()) 
	{
		izvod_ref = it.value();
	}
	return izvod_ref;
}

