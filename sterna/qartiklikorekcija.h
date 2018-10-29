#ifndef QARTIKLIKOREKCIJA_H
#define QARTIKLIKOREKCIJA_H


#include "ui_qartiklikorekcija.h"
#include "qmybaseformwidget.h"

class QArtikliKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QArtikliKorekcija(QWidget *parent = 0);
	~QArtikliKorekcija();
	void showData(const QString& id);
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();
private:
	bool eventFilter(QObject *object, QEvent *event);
	Ui::QArtikliKorekcijaClass ui;
	int m_id;
	QString m_initSifraArtikal;

private slots:
	void on_pushButton_clicked();

signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QARTIKLIKOREKCIJA_H
