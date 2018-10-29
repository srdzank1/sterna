#ifndef QARTIKLI_H
#define QARTIKLI_H

#include <QWidget>
//#include "ui_qartikli.h"

class QArtikli : public QWidget
{
	Q_OBJECT

public:
	QArtikli(QWidget *parent = 0);
	~QArtikli();

private:
	Ui::QArtikliClass ui;
};

#endif // QARTIKLI_H
