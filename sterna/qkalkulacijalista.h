#ifndef QKalkulacijaLISTA_H
#define QKalkulacijaLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qKalkulacijalista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "chelperclass.h"
#include <QDateTime>


class QKalkulacijaLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKalkulacijaLista(QWidget *parent = 0);
	~QKalkulacijaLista();
	void lista(const QString& nameSearch, QDateTime date1, QDateTime date2);
	void lista_detail(const QString& nameSearch);
	int getSelectedId(){return m_selectedText.toInt();}
	virtual void pressEscape();
	virtual void pressReturn();

    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
	int getRow();
	void setRow(int mrow);
	void setInitText(QString text, QDateTime &date1, QDateTime &date2);
	void setTableColumnWidths(int ccolumn, int ccolumn_detail);
	void getTableColumnWidths(int ccolumn, int ccolumn_detail);

private:
    void deleteDok(int idDok);
	Ui::QKalkulacijaListaClass ui;
    QHeaderView *header;
	QHeaderView *header2;
	QString m_selectedText;
	float m_sumaIznosStavki;
	float m_sumaTrosoci;

	float m_sumaPoNabCena;
	float m_sumaPoProdazCena;


	float m_vkupen_nabaven_iznos_bez_ddv;
	float m_vkupen_vlezen_ddv;
	float m_vkupen_nabaven_iznos_so_ddv;
	float m_vkupna_marza_iznos;
	float m_vkupen_prodazen_iznos_bez_ddv;
	float m_vkupen_presmetan_ddv;
	float m_vkupen_prodazen_iznos_so_ddv;


	QString m_kalkulacija_id;
	QString m_kalkulacija_datum;
	QString m_komintent_naziv;
	QString m_iznos;
	QString m_iznos_ddv;
	QString m_iznos_1;
	QString m_iznos_2;
	QString m_iznos_3;
	QString m_iznos_4;
	QString m_iznos_5;
	QString m_iznos_6;
	QStringList m_listDataInfo;
	int colWidth[17];
	int colWidth_detail[17];
private slots:
	void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
	void calcSelectedItems();
	void copyToClipBoard();
	void procSectionResized(int a, int b, int c);
	void procSectionResized_detail(int a, int b, int c);

signals:
	void closeW();
    void procF2();
    void procF3();
    void procDel();
	void sFakturiToIzvod(QStringList& data );
};

#endif // QKalkulacijaLISTA_H
