#ifndef QKOMINTENTIVNES_H
#define QKOMINTENTIVNES_H

#include "qmybaseformwidget.h"
#include "ui_qkomintentivnes.h"
#include "chelperclass.h"

class QKomintentiVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKomintentiVnes(QWidget *parent = 0);
	~QKomintentiVnes();
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();
	void setInitValue(QString text);

private:
    bool eventFilter(QObject *object, QEvent *event);
	Ui::QKomintentiVnesClass ui;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QKOMINTENTIVNES_H
