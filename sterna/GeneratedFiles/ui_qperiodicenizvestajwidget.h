/********************************************************************************
** Form generated from reading UI file 'qperiodicenizvestajwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPERIODICENIZVESTAJWIDGET_H
#define UI_QPERIODICENIZVESTAJWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QPeriodicenIzvestajWidgetClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMyBaseFormWidget *QPeriodicenIzvestajWidgetClass)
    {
        if (QPeriodicenIzvestajWidgetClass->objectName().isEmpty())
            QPeriodicenIzvestajWidgetClass->setObjectName(QString::fromUtf8("QPeriodicenIzvestajWidgetClass"));
        QPeriodicenIzvestajWidgetClass->resize(2400, 2400);
        layoutWidget = new QWidget(QPeriodicenIzvestajWidgetClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 791, 581));
        QFont font;
        font.setPointSize(10);
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        dateEdit_2 = new QDateEdit(layoutWidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        gridLayout->addWidget(dateEdit_2, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette;
        QBrush brush(QColor(228, 228, 228, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView->setPalette(palette);
        tableView->setFont(font);
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 3, 0, 1, 4);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 3, 1, 1);

        QWidget::setTabOrder(lineEdit, tableView);

        retranslateUi(QPeriodicenIzvestajWidgetClass);

        QMetaObject::connectSlotsByName(QPeriodicenIzvestajWidgetClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QPeriodicenIzvestajWidgetClass)
    {
        QPeriodicenIzvestajWidgetClass->setWindowTitle(QApplication::translate("QPeriodicenIzvestajWidgetClass", "QPeriodicenIzvestajWidget", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QPeriodicenIzvestajWidgetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\320\275 - \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QPeriodicenIzvestajWidgetClass", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 \320\277\320\276 \320\275\320\260\320\267\320\270\320\262 \320\275\320\260 \320\260\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QPeriodicenIzvestajWidgetClass", "\320\232\321\200\320\265\320\270\321\200\320\260\321\230 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QPeriodicenIzvestajWidgetClass", "Copy To Clipboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QPeriodicenIzvestajWidgetClass: public Ui_QPeriodicenIzvestajWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPERIODICENIZVESTAJWIDGET_H
