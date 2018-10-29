/********************************************************************************
** Form generated from reading UI file 'qmyispratnici.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYISPRATNICI_H
#define UI_QMYISPRATNICI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyIspratniciClass
{
public:

    void setupUi(QMyBaseWidget *QMyIspratniciClass)
    {
        if (QMyIspratniciClass->objectName().isEmpty())
            QMyIspratniciClass->setObjectName(QString::fromUtf8("QMyIspratniciClass"));
        QMyIspratniciClass->resize(947, 591);

        retranslateUi(QMyIspratniciClass);

        QMetaObject::connectSlotsByName(QMyIspratniciClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMyIspratniciClass)
    {
        QMyIspratniciClass->setWindowTitle(QApplication::translate("QMyIspratniciClass", "QMyIspratnici", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyIspratniciClass: public Ui_QMyIspratniciClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYISPRATNICI_H
