#ifndef QMYARTIKLILISTA_H
#define QMYARTIKLILISTA_H

#include "qmybaseformwidget.h"
#include "ui_qmyartiklilista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "chelperclass.h"
#include <QMessageBox>
#include <QSqlError>

class QMyArtikliLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QMyArtikliLista(QWidget *parent = 0);
	~QMyArtikliLista();
	QStandardItemModel *model;
	void lista(const QString& nameSearch);
	QString getSelectedText(){return m_selectedText;}
	void setSelectedText(QString selectedText){m_selectedText = selectedText;}
	void setFocusSearchField();
	virtual void pressEscape();
	virtual void pressReturn();
	void setInitText(QString text);
	void setRow(int mrow);
	int getRow();
	QString getSearchStr();
	void setSearchText(QString text);


		
protected:

private:
	Ui::QMyArtikliListaClass ui;
	
	QHeaderView *header;
	QString m_selectedText;
	QString m_selectedTextName;
	int m_row;
	void setTableColumnWidths(int ccolumn);
	void getTableColumnWidths(int ccolumn);
	int colWidth[11];

private slots:
	void on_tableView_clicked(const QModelIndex &);
	void on_lineEdit_textChanged(const QString &);
	void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void copyToClipBoard();
	void procSectionResized(int a, int b, int c);
signals:
	void closeW();
	void sArtikalToPriemnica(QString& text, QString& textName);
    void procF2();
    void procF3();
};

#endif // QMYARTIKLILISTA_H
