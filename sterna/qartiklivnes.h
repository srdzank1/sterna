#ifndef QARTIKLIVNES_H
#define QARTIKLIVNES_H

#include "qmybaseformwidget.h"
#include "ui_qartiklivnes.h"

class QArtikliVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QArtikliVnes(QWidget *parent = 0);
	~QArtikliVnes();
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();
	void setInitValue(QString text);



private:
	Ui::QArtikliVnesClass ui;
	bool eventFilter(QObject *object, QEvent *event);


private slots:
	void on_pushButton_clicked();

signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QARTIKLIVNES_H
