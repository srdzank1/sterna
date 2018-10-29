/********************************************************************************
** Form generated from reading UI file 'qmykasa.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYKASA_H
#define UI_QMYKASA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyKasaClass
{
public:

    void setupUi(QMyBaseWidget *QMyKasaClass)
    {
        if (QMyKasaClass->objectName().isEmpty())
            QMyKasaClass->setObjectName(QString::fromUtf8("QMyKasaClass"));
        QMyKasaClass->resize(947, 591);

        retranslateUi(QMyKasaClass);

        QMetaObject::connectSlotsByName(QMyKasaClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMyKasaClass)
    {
        QMyKasaClass->setWindowTitle(QApplication::translate("QMyKasaClass", "QMyKasa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyKasaClass: public Ui_QMyKasaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYKASA_H
