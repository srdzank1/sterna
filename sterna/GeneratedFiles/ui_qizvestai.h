/********************************************************************************
** Form generated from reading UI file 'qizvestai.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZVESTAI_H
#define UI_QIZVESTAI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QIzvestaiClass
{
public:

    void setupUi(QMyBaseWidget *QIzvestaiClass)
    {
        if (QIzvestaiClass->objectName().isEmpty())
            QIzvestaiClass->setObjectName(QString::fromUtf8("QIzvestaiClass"));
        QIzvestaiClass->resize(6000, 377);

        retranslateUi(QIzvestaiClass);

        QMetaObject::connectSlotsByName(QIzvestaiClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QIzvestaiClass)
    {
        QIzvestaiClass->setWindowTitle(QApplication::translate("QIzvestaiClass", "QIzvestai", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzvestaiClass: public Ui_QIzvestaiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZVESTAI_H
