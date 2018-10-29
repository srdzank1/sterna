#ifndef QProFakturiLista_H
#define QProFakturiLista_H

#include "qmybaseformwidget.h"
#include "ui_qprofakturalista.h"
#include <QStandardItemModel>
#include <QItemSelection>

class QProFakturiLista : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QProFakturiLista(QWidget *parent = 0);
	~QProFakturiLista();
	void lista(const QString& nameSearch);
	void lista_detail(const QString& nameSearch);
	int getSelectedId(){return m_selectedText.toInt();}
	virtual void pressEscape();
	QStandardItemModel *model;
	QStandardItemModel *model2;

private:
	Ui::QProFakturiListaClass ui;
    QHeaderView *header;
	QHeaderView *header2;
	QString m_selectedText;
	private slots:
		void selectionChanged(QModelIndex modelX, QModelIndex modelY );
signals:
	void closeW();
};

#endif // QISPRATNICILISTA_H
