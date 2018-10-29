/********************************************************************************
** Form generated from reading UI file 'qkarticawidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKARTICAWIDGET_H
#define UI_QKARTICAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <qmybaseformwidget.h>

QT_BEGIN_NAMESPACE

class Ui_QKarticaWidgetClass
{
public:

    void setupUi(QMyBaseFormWidget *QKarticaWidgetClass)
    {
        if (QKarticaWidgetClass->objectName().isEmpty())
            QKarticaWidgetClass->setObjectName(QString::fromUtf8("QKarticaWidgetClass"));
        QKarticaWidgetClass->setObjectName("QKarticaWidgetClass");
        QKarticaWidgetClass->resize(400, 300);

        retranslateUi(QKarticaWidgetClass);

        QMetaObject::connectSlotsByName(QKarticaWidgetClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QKarticaWidgetClass)
    {
        QKarticaWidgetClass->setWindowTitle(QApplication::translate("QKarticaWidgetClass", "QKarticaWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKarticaWidgetClass: public Ui_QKarticaWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKARTICAWIDGET_H
