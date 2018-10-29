#ifndef CHELPERCLASS_H
#define CHELPERCLASS_H

#include <QObject>
#include <QStandardItem>
#include <QFile>
#include <QDataStream>
#include <QTextStream>


class CHelperClass : public QObject
{
    Q_OBJECT

public:
    CHelperClass(QObject *parent);
    ~CHelperClass();
    bool isKomintentExists(QString &komName);
    bool isArtikliExists(QString &komName);
    int CHelperClass::genSifraArtikal();
    bool isBankExists(QString &komName);
	bool isFakturaExists(QString &fakturaId, QString& tip);
	void fakturaStatus(QStandardItem *item,  QString& tip);
	void getFakturaPlatenIznos(QString& faktBroj, QString& tip);
    float getPlatenIznos();
	QString getKomintentName(QString m_id);
    float getFakturaVkupenIznos(QString& faktBroj, QString& tip);
	QString getArtikalByID(QString text);
	float getVkKol(QString& artikal_ID, QString& tip);
	float getVkKolBetween(QString& artikal_ID, QString& tip, QString& tip1);
	float getVkKolByDate(QString& artikal_ID, QString& tip, QDate & mDate, QDate & mDate2);
	void createStatusMap(QString& tip);
	double rouded(double num);
	int calcMaxIdTblKalkulacii();
	int calcMaxIdTblKalkulaciiStavki();
	void calcPrilivOdlivPoKomintent();
	float getPrilivOdlivPoKomintent(QString& komintent_id, QString& dok_tip );
	void calcPlakanjaPoKomintent();
	float getPlakanjePoKomintent(QString& komintent_id, QString& dok_tip );
    void createKomintentiMap();
    void createArtikliMap();
    void createSifraMap();
    void createListaIzlezniFakturiIznosi(QString &tip);
    void createListaKomintenti(QString &tip);
	void getFakturaIznosiAll( QString& tip);
	float getFakturaPrilivIznos(QString& dok_id );
	float getFakturaOdlivIznos(QString& dok_id );
	void createMaxNabProdCenaMapAll();
	int isSifraArtikalExistsInSTore(QString mSifra);
	bool isKomintentExistsInStore(QString &komID);

    QString getArtikalNameByID(QString& id);
    QString getKomintentNameByID(QString& id);
    QString getSifraNameByID(QString& id);

    float getFakturaIznos(QString& dok_id);
    float getFakturaDDV(QString& dok_id);
    float getFakturaVkupno(QString& dok_id);

	void createSaldoArtikliOdlivMapAll();
	void createSaldoProizvodiPrilivMapAll();
	void createSaldoArtikliOdlivMapAll_bezKomintent();
	void createSaldoProizvodiPrilivMapAllbezKomintent();
	void createListProdCenaKalkulacijaMapAll();
	float getProdCenaFromKalkulacija(QString & item);
	float getNabCenaFromKalkulacija(QString & item);

	void createSaldoArtikliOdlivMapAll(QString date1, QString date2);
	void createSaldoProizvodiPrilivMapAll(QString date1, QString date2);

	float getLagerListaAll(QString & item,  QString& tip);
	bool isIzvodExists(QString &bankaId, QString &izvodId);

	QString GetRandomString();
	QString getPlatenIznosZaFaktura( QString& tip, QString &faktBr);
	void createPovratnicaFakturiIznosi();
	float getPovratnicaFakturaVkupno(QString& dok_id );
	QString getFakturaBrojOdPovratnica(QString povratnica_id);
	float getIznosOdPovratnica(QString povratnica_id, QString faktura_br );

	QStringList getVraboteniInfo(QString& u, QString& p);
	QString getVrabotenNextID();
    QString getKomintentDetail(QString& dok_id );
	int isSifraArtikalExists(QString mSifra);
	int isSifraKomintentExists(QString mSifra);
	void createMapPriemnici();
	QString getFakturaFromPriemnica(QString& priemnica_id);
	QString getTipDokumentFromPriemnica(QString& priemnica_id);
	void createMapNefakturiraniIspratnici();
	bool getNefaktiriranaIspratnica(int ispratnica_id);
	long printFiscal(QStringList itemArt);
	long printFiscalStorno(QStringList itemArt);
	void createListaKomintentiByID();
	QString getSifraKomintentByID(QString& dok_id );
	void printFiscalPodesuvanjeDatumCas();
	void printFiscalDnevnoFiskalnoZatvoranje();
	void SluzbenIzlezNaPari(QString &iznosPari);
	void SluzbenVlezNaPari(QString &iznosPari);
	void printKontrolenIzvestajProsiren();
	void printDetalenIzvestajPoPeriod(QString &date1, QString &date2);
	QString checkFiscal();
	void createListaIzvodiMap(QString bankaId);
	QString getIzvod_Ref(QString& izvodbr );
	typedef struct {
		float priliv;
		float odliv;
	} tdataInfo;

	QMap<QString, tdataInfo> mapIznosi;

private:
typedef struct
	{
		int komintent_id;
		int dok_id;
		int dok_tip;
	} analitikaKomintent; 

typedef struct
{
	int komintent_id;
	int dok_id;
	int dok_tip;
	float kol;
	float cena;
	float rabat;
} analitikaKomintentArtikli; 

typedef struct
{
    float iznos;
    float ddv;
    float vkupno;
} fakturiData; 

typedef struct
{
	QString dokument_id;
	QString dokument_tip;
	QString dokument_datum;
} tpriemniciData; 

	QMap <QString, tpriemniciData> m_mapPriemnici;
	QMap <int , int> m_mapNefakIspratnici;
	float m_vkupenPriliv;
	float m_vkupenOdliv;
    float m_plateno;
	QMap <int, float> m_mapZadolzuvanje;
	QMap <int, float> m_mapPlateno;
    QMap <QString, QString> m_mapArtikli;
    QMap <QString, QString> m_mapKomintenti;
    QMap <QString, QString> m_mapSifri;
    QMap <QString, fakturiData> m_mapFakturi;
    QMap <QString, QString> m_mapKomintentDetailInfo;
	QMap <QString, fakturiData> m_mapPovratnici;

	QMap <QString, float> m_mapPriliv;
	QMap <QString, float> m_mapOdliv;
	QMap <QString, float> m_mapKalkulacija;
	QMap <QString, float> m_mapKalkulacija2;

	QMap <QString, float> m_mapPrilivOdlivPoKomintent;
	QMap <QString, float> m_mapPlakanjePoKomintent;
	QMap <QString, QString> m_mapIzvod;


	QMap <QString, QString> m_mapKomintentByID; 
	void createZadolzuvanjeMap(QString& tip);
	void createPlatenoMap(QString& tip);
	QVector<analitikaKomintent> vAnalitikaKomintent;
	QVector<analitikaKomintentArtikli> vAnalitikaKomintentArtikli;
	
	void convertIme(QTextStream &stream, QString utfIme);
	
};

#endif // CHELPERCLASS_H
