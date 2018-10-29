/********************************************************************************
** Form generated from reading UI file 'qkartici.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKARTICI_H
#define UI_QKARTICI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QKarticiClass
{
public:

    void setupUi(QWidget *QKarticiClass)
    {
        if (QKarticiClass->objectName().isEmpty())
            QKarticiClass->setObjectName(QString::fromUtf8("QKarticiClass"));
        QKarticiClass->setObjectName("QKarticiClass");
        QKarticiClass->resize(400, 300);

        retranslateUi(QKarticiClass);

        QMetaObject::connectSlotsByName(QKarticiClass);
    } // setupUi

    void retranslateUi(QWidget *QKarticiClass)
    {
        QKarticiClass->setWindowTitle(QApplication::translate("QKarticiClass", "QKartici", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKarticiClass: public Ui_QKarticiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKARTICI_H
