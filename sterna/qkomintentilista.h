#ifndef QKOMINTENTILISTA_H
#define QKOMINTENTILISTA_H

#include "qmybaseformwidget.h"
#include "ui_qkomintentilista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include <QKeyEvent>
#include "chelperclass.h"
#include <QMessageBox>
#include <QSqlError>


class QKomintentiLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKomintentiLista(QWidget *parent = 0);
	~QKomintentiLista();
	void lista(const QString& nameSearch);
	QString getSelectedText(){return m_selectedText;}
	virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
	void setInitText(QString text);
	void setSearchText(QString text);
	QString getSearchStr();
	void getTableColumnWidths(int ccolumn);
	void setTableColumnWidths(int ccolumn);

private:
	Ui::QKomintentiListaClass ui;
	QHeaderView *header;
	QString m_selectedText;
	QString m_selectedText_name;
	int colWidth[15];

private slots:
	void on_tableView_pressed(QModelIndex);
	
	void on_tableView_clicked(const QModelIndex &);
	void on_lineEdit_textChanged(const QString &);
	void selectionChanged(QModelIndex modelX, QModelIndex modelY);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void procSectionResized(int a, int b, int c);
signals:
	void closeW();
	void sKomintentToPriemnica(QString &, QString&);
    void procF2();
    void procF3();
};

#endif // QKOMINTENTILISTA_H
