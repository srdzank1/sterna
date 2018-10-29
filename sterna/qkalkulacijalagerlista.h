#ifndef QKALKULACIJALAGERLISTA_H
#define QKALKULACIJALAGERLISTA_H

#include <QDialog>
#include "ui_qkalkulacijalagerlista.h"
#include <QHeaderView>
#include "chelperclass.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QKeyEvent>


class QKalkulacijaLagerLista : public QDialog
{
	Q_OBJECT

public:
	QKalkulacijaLagerLista(QWidget *parent = 0);
	~QKalkulacijaLagerLista();
	void lista(const QString& nameSearch);
	QString m_selectedNabavCena;
	QString m_selectedProdCena;

private:
	QStandardItemModel *model;
	QHeaderView * header;
	Ui::QKalkulacijaLagerLista ui;
	virtual void keyPressEvent ( QKeyEvent * e );
private slots:
	void selectionChanged(QModelIndex modelX, QModelIndex modelY );
	void on_returnPressed();
	
};

#endif // QKALKULACIJALAGERLISTA_H
