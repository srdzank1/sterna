/********************************************************************************
** Form generated from reading UI file 'qmybaseformwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYBASEFORMWIDGET_H
#define UI_QMYBASEFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMyBaseFormWidgetClass
{
public:

    void setupUi(QWidget *QMyBaseFormWidgetClass)
    {
        if (QMyBaseFormWidgetClass->objectName().isEmpty())
            QMyBaseFormWidgetClass->setObjectName(QString::fromUtf8("QMyBaseFormWidgetClass"));
        QMyBaseFormWidgetClass->setObjectName("QMyBaseFormWidgetClass");
        QMyBaseFormWidgetClass->resize(400, 300);

        retranslateUi(QMyBaseFormWidgetClass);

        QMetaObject::connectSlotsByName(QMyBaseFormWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *QMyBaseFormWidgetClass)
    {
        QMyBaseFormWidgetClass->setWindowTitle(QApplication::translate("QMyBaseFormWidgetClass", "QMyBaseFormWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyBaseFormWidgetClass: public Ui_QMyBaseFormWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYBASEFORMWIDGET_H
