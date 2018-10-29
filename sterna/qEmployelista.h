#ifndef QEmployeLISTA_H
#define QEmployeLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qEmployelista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include <QKeyEvent>

class QEmployeLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QEmployeLista(QWidget *parent = 0);
	~QEmployeLista();
	void lista(const QString& nameSearch);
	QString getSelectedText(){return m_selectedText;}
	virtual void pressEscape();
	virtual void pressReturn();
    QStandardItemModel *model;
	void setInitText(QString text);


private:
	Ui::QEmployeListaClass ui;
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
	void sKomintentToPriemnica(QString &, QString&);
    void procF2();
    void procF3();
};

#endif // QEmployeLISTA_H
