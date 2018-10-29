#ifndef QBANKILISTA_H
#define QBANKILISTA_H

#include "qmybaseformwidget.h"
#include "ui_qbankilista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include <QKeyEvent>

class QBankiLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QBankiLista(QWidget *parent = 0);
	~QBankiLista();
	void lista(const QString& nameSearch);
	QString getSelectedText(){return m_selectedText;}
	virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
    void setInitText(QString text);

private:
	Ui::QBankiListaClass ui;
	QHeaderView *header;
	QString m_selectedText;
	QString m_selectedText_name;

private slots:
	void on_tableView_pressed(QModelIndex);
	
	void on_tableView_clicked(const QModelIndex &);
	void on_lineEdit_textChanged(const QString &);
	void selectionChanged(QModelIndex modelX, QModelIndex modelY);
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

signals:
	void closeW();
	void sBankiToIzvod(QString &, QString&);
	void procF2();
	void procF3();
};



#endif // QBANKILISTA_H
