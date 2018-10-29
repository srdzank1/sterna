/********************************************************************************
** Form generated from reading UI file 'qpromenaceni.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPROMENACENI_H
#define UI_QPROMENACENI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <qmybasewidget.h>

QT_BEGIN_NAMESPACE

class Ui_QPromenaCeniClass
{
public:

    void setupUi(QMyBaseWidget *QPromenaCeniClass)
    {
        if (QPromenaCeniClass->objectName().isEmpty())
            QPromenaCeniClass->setObjectName(QString::fromUtf8("QPromenaCeniClass"));
        QPromenaCeniClass->setObjectName("QPromenaCeniClass");
        QPromenaCeniClass->resize(400, 300);

        retranslateUi(QPromenaCeniClass);

        QMetaObject::connectSlotsByName(QPromenaCeniClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QPromenaCeniClass)
    {
        QPromenaCeniClass->setWindowTitle(QApplication::translate("QPromenaCeniClass", "QPromenaCeni", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QPromenaCeniClass: public Ui_QPromenaCeniClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPROMENACENI_H
