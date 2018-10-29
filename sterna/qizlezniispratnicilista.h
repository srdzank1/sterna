#ifndef QIZLEZNIIspratniciLISTA_H
#define QIZLEZNIIspratniciLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qizlezniIspratnicilista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "xx.h"


class QIzlezniIspratniciLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QIzlezniIspratniciLista(QWidget *parent = 0);
    ~QIzlezniIspratniciLista();
    void lista(const QString& nameSearch, QDateTime date1, QDateTime date2);
    void lista_detail(const QString& nameSearch);
    int getSelectedId(){return m_selectedText.toInt();}
    virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    QStandardItemModel *model2;
	QStandardItemModel *modelAll;
    QStringList geInfo();
    void setInitText(QString text, QDateTime &date1, QDateTime &date2);
	void setInitTextIspratnici(QString text, QDateTime &date1, QDateTime &date2);
	void addItemFromIspratnicainit(int id, int color1);
	void getTableColumnWidths(int ccolumn);
	void setTableColumnWidths(int ccolumn);
	void getTableColumnWidths_detail(int ccolumn);
	void setTableColumnWidths_detail(int ccolumn);	
	void setRow(int mrow);
	int getRow();
	bool isButtonChecked();
	bool getStat();
	bool getStatB(){return statB;}



private:
    Ui::QIzlezniIspratniciListaClass ui;
    void deleteDok(int idDok);
    QHeaderView *header;
    QHeaderView *header2;
    QString m_selectedText;
	int m_row;
	bool statA;
    bool statB;
	QString m_fakturaBr;
    QString m_fakturadatum;
    QString m_komintent_naziv;
    QString m_komintent_adresa;
    QString m_komintent_grad;
    QString m_rok;
	QString m_komintentIDAll;
	QStringList m_listDataInfo;
	int m_fakturaIspratnica;
	void vnesiFaktura();
	void updateIspratnicaFaktura(QStringList listA);
	int colWidth[17];
	int colWidth_detail[12];
    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
		void on_pushButton_3_clicked();
        void on_pushButton_4_clicked();
		void lineEdit7Pressed(const QString & text);
		void calcSelectedItems();
		void procSectionResized(int a, int b, int c);
		void procSectionResized_detail(int a, int b, int c);
signals:
        void closeW();
        void procF2();
        void procF3();
		void sIspratniciToIzvod(QStringList& listData);
		void callSearchForm();
};

#endif // QIZLEZNIIspratniciLISTA_H
