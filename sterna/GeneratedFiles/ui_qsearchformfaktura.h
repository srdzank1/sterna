/********************************************************************************
** Form generated from reading UI file 'qsearchformfaktura.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSEARCHFORMFAKTURA_H
#define UI_QSEARCHFORMFAKTURA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QSearchFormFaktura
{
public:
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;

    void setupUi(QDialog *QSearchFormFaktura)
    {
        if (QSearchFormFaktura->objectName().isEmpty())
            QSearchFormFaktura->setObjectName(QString::fromUtf8("QSearchFormFaktura"));
        QSearchFormFaktura->resize(408, 91);
        lineEdit = new QLineEdit(QSearchFormFaktura);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 371, 20));
        dateTimeEdit = new QDateTimeEdit(QSearchFormFaktura);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 50, 181, 22));
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit_2 = new QDateTimeEdit(QSearchFormFaktura);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(210, 50, 181, 22));
        dateTimeEdit_2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateTimeEdit_2->setCalendarPopup(true);

        retranslateUi(QSearchFormFaktura);

        QMetaObject::connectSlotsByName(QSearchFormFaktura);
    } // setupUi

    void retranslateUi(QDialog *QSearchFormFaktura)
    {
        QSearchFormFaktura->setWindowTitle(QApplication::translate("QSearchFormFaktura", "Search", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QSearchFormFaktura", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        dateTimeEdit_2->setDisplayFormat(QApplication::translate("QSearchFormFaktura", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QSearchFormFaktura: public Ui_QSearchFormFaktura {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSEARCHFORMFAKTURA_H
