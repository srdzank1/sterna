#ifndef QIZLEZNIpopismasterLISTA_H
#define QIZLEZNIpopismasterLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qizleznipopismasterlista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "xx.h"


class QIzleznipopismasterLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QIzleznipopismasterLista(QWidget *parent = 0);
    ~QIzleznipopismasterLista();
    void lista(const QString& nameSearch, QDateTime date1, QDateTime date2);
    void lista_detail(const QString& nameSearch);
    int getSelectedId(){return m_selectedText.toInt();}
    virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
    void setInitText(QString text, QDateTime &date1, QDateTime &date2);
	void setInitTextpopismaster(QString text, QDateTime &date1, QDateTime &date2);

	void setRow(int mrow);
	int getRow();
	bool isButtonChecked();


private:
    Ui::QIzleznipopismasterListaClass ui;
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

    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void lineEdit7Pressed(const QString & text);
		void calcSelectedItems();
signals:
        void closeW();
        void procF2();
        void procF3();
		void spopismasterToIzvod(QStringList& listData);
};

#endif // QIZLEZNIpopismasterLISTA_H
