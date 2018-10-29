#ifndef QIzjavaLISTA_H
#define QIzjavaLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qizjavalista.h"
#include <QStandardItemModel>
#include <QItemSelection>

class QIzjavaLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzjavaLista(QWidget *parent = 0);
	~QIzjavaLista();
	void lista(const QString& nameSearch);
	void lista_detail(const QString& nameSearch);
	int getSelectedId(){return m_selectedText.toInt();}
	virtual void pressEscape();
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStringList geInfo();
	int getSelectedRow();
	void setRowIndex(int mIndex);
	void pressReturn();
	void setInitText(QString text);

private:
    void deleteDok(int idDok);
	Ui::QIzjavaListaClass ui;
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
    void procDel();
	void sIzjavaToIzvod(QString& text6, QString& text8, QString& text9, QString& textName);

};

#endif // QIzjavaLISTA_H
