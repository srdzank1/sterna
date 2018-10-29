/********************************************************************************
** Form generated from reading UI file 'qfakturivlezni.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFAKTURIVLEZNI_H
#define UI_QFAKTURIVLEZNI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include "qmybasewidget.h"

QT_BEGIN_NAMESPACE

class Ui_QFakturiVlezni
{
public:

    void setupUi(QMyBaseWidget *QFakturiVlezni)
    {
        if (QFakturiVlezni->objectName().isEmpty())
            QFakturiVlezni->setObjectName(QString::fromUtf8("QFakturiVlezni"));
        QFakturiVlezni->resize(1049, 629);

        retranslateUi(QFakturiVlezni);

        QMetaObject::connectSlotsByName(QFakturiVlezni);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QFakturiVlezni)
    {
        QFakturiVlezni->setWindowTitle(QApplication::translate("QFakturiVlezni", "QFakturiVlezni", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QFakturiVlezni: public Ui_QFakturiVlezni {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFAKTURIVLEZNI_H
