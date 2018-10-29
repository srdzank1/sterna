/********************************************************************************
** Form generated from reading UI file 'qPriem.ui'
**
** Created: Tue 19. Feb 21:04:06 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPriem_H
#define UI_QPriem_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <qmybasewidget.h>

QT_BEGIN_NAMESPACE

class Ui_QPriemClass
{
public:

    void setupUi(QMyBaseWidget *QPriemClass)
    {
        if (QPriemClass->objectName().isEmpty())
            QPriemClass->setObjectName(QString::fromUtf8("QPriemClass"));
        QPriemClass->setObjectName("QPriemClass");
        QPriemClass->resize(400, 300);

        retranslateUi(QPriemClass);

        QMetaObject::connectSlotsByName(QPriemClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QPriemClass)
    {
        QPriemClass->setWindowTitle(QApplication::translate("QPriemClass", "QPriem", 0, 0));
    } // retranslateUi

};

namespace Ui {
    class QPriemClass: public Ui_QPriemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPriem_H
