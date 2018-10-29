/********************************************************************************
** Form generated from reading UI file 'qmypovratnica.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYPOVRATNICA_H
#define UI_QMYPOVRATNICA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyPovratnicaClass
{
public:

    void setupUi(QMyBaseWidget *QMyPovratnicaClass)
    {
        if (QMyPovratnicaClass->objectName().isEmpty())
            QMyPovratnicaClass->setObjectName(QString::fromUtf8("QMyPovratnicaClass"));
        QMyPovratnicaClass->resize(947, 591);

        retranslateUi(QMyPovratnicaClass);

        QMetaObject::connectSlotsByName(QMyPovratnicaClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMyPovratnicaClass)
    {
        QMyPovratnicaClass->setWindowTitle(QApplication::translate("QMyPovratnicaClass", "QMyPovratnica", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyPovratnicaClass: public Ui_QMyPovratnicaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYPOVRATNICA_H
