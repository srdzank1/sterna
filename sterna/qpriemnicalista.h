#ifndef QPRIEMNICALISTA_H
#define QPRIEMNICALISTA_H

#include "qmybaseformwidget.h"
#include "ui_qpriemnicalista.h"
#include <QStandardItemModel>
#include <QItemSelection>

class QPriemnicaLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPriemnicaLista(QWidget *parent = 0);
	~QPriemnicaLista();
	void lista(const QString& nameSearch);
	void lista_detail(const QString& nameSearch);
	int getSelectedId(){return m_selectedText.toInt();}
	virtual void pressEscape();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();

private:
    void deleteDok(int idDok);
	Ui::QPriemnicaListaClass ui;
    QHeaderView *header;
	QHeaderView *header2;
	QString m_selectedText;

    QString m_info; 
    QString m_info2;
    QString m_info3;
    QString m_info4;
    QString m_info5;

private slots:
	void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
	void closeW();
    void procF2();
    void procF3();
    void procDel();
};

#endif // QPRIEMNICALISTA_H
