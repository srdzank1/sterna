#ifndef QIZLEZNIfaktmasterLISTA_H
#define QIZLEZNIfaktmasterLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qizleznifaktmasterlista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "xx.h"


class QIzleznifaktmasterLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QIzleznifaktmasterLista(QWidget *parent = 0);
    ~QIzleznifaktmasterLista();
    void lista(const QString& nameSearch, QDateTime date1, QDateTime date2);
    void lista_detail(const QString& nameSearch);
    int getSelectedId(){return m_selectedText.toInt();}
    virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
    void setInitText(QString text, QDateTime &date1, QDateTime &date2);
	void setInitTextfaktmaster(QString text, QDateTime &date1, QDateTime &date2);

	void setRow(int mrow);
	int getRow();
	bool isButtonChecked();
	void setTableColumnWidths(int ccolumn);
	void getTableColumnWidths(int ccolumn);
	void setTableColumnWidths_detail(int ccolumn);
	void getTableColumnWidths_detail(int ccolumn);


private:
    Ui::QIzleznifaktmasterListaClass ui;
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
	int colWidth[16];
	int colWidth_detail[14];


    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void lineEdit7Pressed(const QString & text);
		void calcSelectedItems();
		void procSectionResized(int a, int b, int c);
		void procSectionResized_detail(int a, int b, int c);

signals:
        void closeW();
        void procF2();
        void procF3();
		void sfaktmasterToIzvod(QStringList& listData);
};

#endif // QIZLEZNIfaktmasterLISTA_H
