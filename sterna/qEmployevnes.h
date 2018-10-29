#ifndef QEmployeVNES_H
#define QEmployeVNES_H

#include "qmybaseformwidget.h"
#include "ui_qEmployeivnes.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "chelperclass.h"


class QEmployeVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QEmployeVnes(QWidget *parent = 0);
	~QEmployeVnes();
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

private:
    bool eventFilter(QObject *object, QEvent *event);
	Ui::QEmployeVnesClass ui;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QEmployeVNES_H
