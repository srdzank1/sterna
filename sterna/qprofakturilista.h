
#ifndef QFAKTURILISTA_H
#define QFAKTURILISTA_H

#include "qmybaseformwidget.h"
#include "ui_qprofakturalista.h"
#include <QStandardItemModel>
#include <QItemSelection>

class QVlezniProFakturiLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QVlezniProFakturiLista(QWidget *parent = 0);
	~QVlezniProFakturiLista();
	void lista(const QString& nameSearch);
	void lista_detail(const QString& nameSearch);
	int getSelectedId(){return m_selectedText.toInt();}
	virtual void pressEscape();

private:
	Ui::QProFakturiListaClass ui;
	QStandardItemModel *model;
	QHeaderView *header;
	QStandardItemModel *model2;
	QHeaderView *header2;
	QString m_selectedText;
	private slots:
		void selectionChanged(QModelIndex modelX, QModelIndex modelY );
signals:
		void closeW();
};

#endif // QVlezniProFakturiLISTA_H
