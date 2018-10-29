#ifndef QKOMINTENTIKOREKCIJA_H
#define QKOMINTENTIKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qkomintentikorekcija.h"

class QKomintentiKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKomintentiKorekcija(QWidget *parent = 0);
	~QKomintentiKorekcija();
	void showData(const QString& id);
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

private:
    bool eventFilter(QObject *object, QEvent *event);
	Ui::QKomintentiKorekcijaClass ui;
	int m_id;
	QString m_initSifraKomintent;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QKOMINTENTIKOREKCIJA_H
