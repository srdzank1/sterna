#ifndef QPorackiSmetkiLISTA_H
#define QPorackiSmetkiLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qPorackiSmetkilista.h"
#include <QStandardItemModel>
#include <QItemSelection>


class QPorackiSmetkiLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QPorackiSmetkiLista(QWidget *parent = 0);
    ~QPorackiSmetkiLista();
    void lista(const QString& nameSearch, QDateTime date1, QDateTime date2);
    void lista_detail(const QString& nameSearch);
    int getSelectedId(){return m_selectedText.toInt();}
    virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
    void setInitText(QString text, QDateTime &date1, QDateTime &date2);
	void setInitTextSmetki(QString text, QDateTime &date1, QDateTime &date2);

	void setRow(int mrow);
	int getRow();
	bool isButtonChecked();
	bool m_statKorekcija;

private:
    Ui::QPorackiSmetkiListaClass ui;
    void deleteDok(int idDok);
    QHeaderView *header;
    QHeaderView *header2;
    QString m_selectedText;
	int m_row;
    QString m_fakturaBr;
    QString m_fakturadatum;
    QString m_komintent_naziv;
    QString m_komintent_adresa;
    QString m_komintent_grad;
    QString m_rok;
	QStringList m_listDataInfo;
	QStringList artList;
	QString m_idid;

    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void lineEdit7Pressed(const QString & text);
		void calcSelectedItems();
		void on_pushButton_3_clicked();
		void on_pushButton_4_clicked();
		void on_pushButton_5_clicked();

signals:
        void closeW();
        void procF2();
        void procF3();
		void sSmetkiToIzvod(QStringList& listData);
};

#endif // QPorackiSmetkiLISTA_H
