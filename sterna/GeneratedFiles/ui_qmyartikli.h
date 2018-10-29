/********************************************************************************
** Form generated from reading UI file 'qmyartikli.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYARTIKLI_H
#define UI_QMYARTIKLI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyArtikliClass
{
public:

    void setupUi(QMyBaseWidget *QMyArtikliClass)
    {
        if (QMyArtikliClass->objectName().isEmpty())
            QMyArtikliClass->setObjectName(QString::fromUtf8("QMyArtikliClass"));
        QMyArtikliClass->resize(400, 300);
        QMyArtikliClass->setAutoFillBackground(true);

        retranslateUi(QMyArtikliClass);

        QMetaObject::connectSlotsByName(QMyArtikliClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QMyArtikliClass)
    {
        QMyArtikliClass->setWindowTitle(QApplication::translate("QMyArtikliClass", "QMyArtikli", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyArtikliClass: public Ui_QMyArtikliClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYARTIKLI_H
