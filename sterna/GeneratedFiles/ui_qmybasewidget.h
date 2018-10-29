/********************************************************************************
** Form generated from reading UI file 'qmybasewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYBASEWIDGET_H
#define UI_QMYBASEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMyBaseWidgetClass
{
public:

    void setupUi(QWidget *QMyBaseWidgetClass)
    {
        if (QMyBaseWidgetClass->objectName().isEmpty())
            QMyBaseWidgetClass->setObjectName(QString::fromUtf8("QMyBaseWidgetClass"));
        QMyBaseWidgetClass->resize(400, 300);
        QMyBaseWidgetClass->setAutoFillBackground(true);

        retranslateUi(QMyBaseWidgetClass);

        QMetaObject::connectSlotsByName(QMyBaseWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *QMyBaseWidgetClass)
    {
        QMyBaseWidgetClass->setWindowTitle(QApplication::translate("QMyBaseWidgetClass", "QMyBaseWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyBaseWidgetClass: public Ui_QMyBaseWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYBASEWIDGET_H
