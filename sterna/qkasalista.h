#ifndef QKasaLISTA_H
#define QKasaLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qKasalista.h"
#include <QStandardItemModel>
#include <QItemSelection>


class QKasaLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
    QKasaLista(QWidget *parent = 0);
    ~QKasaLista();
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
    Ui::QKasaListaClass ui;
    void deleteDok(int idDok);
    QHeaderView *header;
    QHeaderView *header2;
    QString m_selectedText;
	int m_row;

    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
signals:
        void closeW();
        void procF2();
        void procF3();
		void sFakturiToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);
};

#endif // QKasaLISTA_H
