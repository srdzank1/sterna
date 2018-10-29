#ifndef QOdobrenieLISTA_H
#define QOdobrenieLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qOdobrenielista.h"
#include <QStandardItemModel>
#include <QItemSelection>


class QOdobrenieLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QOdobrenieLista(QWidget *parent = 0);
    ~QOdobrenieLista();
    void lista(const QString& nameSearch);
    void lista_detail(const QString& nameSearch);
    int getSelectedId(){return m_selectedText.toInt();}
    virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
    void setInitText(QString text);
	void setRow(int mrow);
	int getRow();


private:
    Ui::QOdobrenieListaClass ui;
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


    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void lineEdit7Pressed(const QString & text);
signals:
        void closeW();
        void procF2();
        void procF3();
		void sOdobrenieToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
};

#endif // QOdobrenieLISTA_H
