#ifndef QUSERFORM_H
#define QUSERFORM_H

#include <QDialog>
#include "ui_quserform.h"

class QUserForm : public QDialog
{
	Q_OBJECT

public:
	QUserForm(QWidget *parent = 0);
	~QUserForm();
	Ui::QUserForm ui;
};

#endif // QUSERFORM_H
