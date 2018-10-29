/********************************************************************************
** Form generated from reading UI file 'qdnevenpromet.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDNEVENPROMET_H
#define UI_QDNEVENPROMET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <qmybasewidget.h>

QT_BEGIN_NAMESPACE

class Ui_QDnevenprometClass
{
public:

    void setupUi(QMyBaseWidget *QDnevenprometClass)
    {
        if (QDnevenprometClass->objectName().isEmpty())
            QDnevenprometClass->setObjectName(QString::fromUtf8("QDnevenprometClass"));
        QDnevenprometClass->setObjectName("QDnevenprometClass");
        QDnevenprometClass->resize(400, 300);

        retranslateUi(QDnevenprometClass);

        QMetaObject::connectSlotsByName(QDnevenprometClass);
    } // setupUi

    void retranslateUi(QMyBaseWidget *QDnevenprometClass)
    {
        QDnevenprometClass->setWindowTitle(QApplication::translate("QDnevenprometClass", "QDnevenpromet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QDnevenprometClass: public Ui_QDnevenprometClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDNEVENPROMET_H
