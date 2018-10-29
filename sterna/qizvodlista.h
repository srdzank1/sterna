#ifndef QIZVODLISTA_H
#define QIZVODLISTA_H

#include "qmybaseformwidget.h"
#include "ui_qizvodlista.h"
#include <QStandardItemModel>
#include <QItemSelection>
#include "qstablewidgetdelegate.h"

class QIzvodLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzvodLista(QWidget *parent = 0);
	~QIzvodLista();
	void lista(const QString& nameSearch);
	QString getSelectedBankaId(){return m_selectedText;}
	QString getSelectedIzvodId(){return m_selectedText2;}
	virtual void pressEscape();
	QStandardItemModel *model;
	QStandardItemModel *model2;
	QStandardItemModel *model3;
	QStandardItemModel *model4;

	QStringList geInfo();
	void setZiroSmetka(QString text, QString textName);
	void setFocusLine();
	void listaBanki(const QString& nameSearch);
	void listaDetail(const QString& nameSearch, const QString& nameSearch2);
	void deleteStavka(const QString& nameSearch, const QString& nameSearch2);
	void listaDetailPlakanje(const QString& nameSearch, const QString& nameSearch2, const QString& nameSearch3, const QString& nameSearch4);
	QStringList getIndexTable();
	void setIzvodiTable(QStringList &info);

private:
	void deleteDok(int idDok);
	Ui::QIzvodListaClass ui;
	QHeaderView *header;
	QHeaderView *header2;
	QHeaderView *header3;
	QHeaderView *header4;

	QString m_selectedText;
	QString m_selectedText2;
	QString m_selectedText3;
	QString m_selectedText4;

    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;

    private slots:
        void selectionChanged(QModelIndex modelX, QModelIndex modelY );
        void selectionChanged2(QModelIndex modelX, QModelIndex modelY);
		void selectionChanged3(QModelIndex modelX, QModelIndex modelY);
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
        void openEditor();
        void closeEditor();
		void on_lineEdit_textChanged(const QString &);
signals:
		void closeW();
        void procF2();
        void procF3();
        void signBankiFromIzvod(QWidget*, QString);
};

#endif // QIZVODLISTA_H
