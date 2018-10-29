#ifndef QEmployeKOREKCIJA_H
#define QEmployeKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qEmployekorekcija.h"
#include <QCryptographicHash>

class QEmployeKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QEmployeKorekcija(QWidget *parent = 0);
	~QEmployeKorekcija();
	void showData(const QString& id);
	virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

private:
    bool eventFilter(QObject *object, QEvent *event);
	Ui::QEmployeKorekcijaClass ui;
	int m_id;

private slots:
	void on_pushButton_clicked();
signals:
	void succesfulEntryData();
	void closeW();
};

#endif // QEmployeKOREKCIJA_H
