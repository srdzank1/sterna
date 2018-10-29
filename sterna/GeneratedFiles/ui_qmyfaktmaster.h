/********************************************************************************
** Form generated from reading UI file 'qmyfaktmaster.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYFAKTMASTER_H
#define UI_QMYFAKTMASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyfaktmasterClass
{
public:

    void setupUi(QMyBaseWidget *QMyfaktmasterClass)
    {
        if (QMyfaktmasterClass->objectName().isEmpty())
            QMyfaktmasterClass->setObjectName(QString::fromUtf8("QMyfaktmasterClass"));
        QMyfaktmasterClass->resize(947, 591);

        retranslateUi(QMyfaktmasterClass);

        QMetaObject::connectSlotsByName(QMyfaktmasterClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMyfaktmasterClass)
    {
        QMyfaktmasterClass->setWindowTitle(QApplication::translate("QMyfaktmasterClass", "QMyfaktmaster", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyfaktmasterClass: public Ui_QMyfaktmasterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYFAKTMASTER_H
