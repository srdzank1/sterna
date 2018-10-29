#ifndef QDDVKOREKCIJA_H
#define QDDVKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qddvkorekcija.h"

class QDdvKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QDdvKorekcija(QWidget *parent = 0);
	~QDdvKorekcija();
	void showData(const QString& id);
	virtual void pressEscape();

private:
	Ui::QDdvKorekcijaClass ui;
	int m_id;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QDDVKOREKCIJA_H
