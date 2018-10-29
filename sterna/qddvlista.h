#ifndef QDDVLISTA_H
#define QDDVLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qddvlista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include <QKeyEvent>

class QDdvLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QDdvLista(QWidget *parent = 0);
	~QDdvLista();
	void lista(const QString& nameSearch);
	QString getSelectedText(){return m_selectedText;}
	virtual void pressEscape();
	virtual void pressReturn();
private:
	Ui::QDdvListaClass ui;
	QStandardItemModel *model;
	QHeaderView *header;
	QString m_selectedText;
	QString m_selectedText_name;

private slots:
	void on_tableView_pressed(QModelIndex);
	
	void on_tableView_clicked(const QModelIndex &);
	void on_lineEdit_textChanged(const QString &);
	void selectionChanged(QModelIndex modelX, QModelIndex modelY);
signals:
	void closeW();
	void sKomintentToPriemnica(QString &, QString&);
};

#endif // QDDVLISTA_H
