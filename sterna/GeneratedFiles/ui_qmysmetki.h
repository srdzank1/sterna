/********************************************************************************
** Form generated from reading UI file 'qmysmetki.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYSMETKI_H
#define UI_QMYSMETKI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMySmetkiClass
{
public:

    void setupUi(QMyBaseWidget *QMySmetkiClass)
    {
        if (QMySmetkiClass->objectName().isEmpty())
            QMySmetkiClass->setObjectName(QString::fromUtf8("QMySmetkiClass"));
        QMySmetkiClass->resize(947, 591);

        retranslateUi(QMySmetkiClass);

        QMetaObject::connectSlotsByName(QMySmetkiClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMySmetkiClass)
    {
        QMySmetkiClass->setWindowTitle(QApplication::translate("QMySmetkiClass", "QMySmetki", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMySmetkiClass: public Ui_QMySmetkiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYSMETKI_H
