/********************************************************************************
** Form generated from reading UI file 'qAnalitikaArtikliwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QANALITIKAARTIKLIWIDGET_H
#define UI_QANALITIKAARTIKLIWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QAnalitikaArtikliWidgetClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QTableView *tableView_2;

    void setupUi(QMyBaseFormWidget *QAnalitikaArtikliWidgetClass)
    {
        if (QAnalitikaArtikliWidgetClass->objectName().isEmpty())
            QAnalitikaArtikliWidgetClass->setObjectName(QString::fromUtf8("QAnalitikaArtikliWidgetClass"));
        QAnalitikaArtikliWidgetClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QAnalitikaArtikliWidgetClass->setFont(font);
        layoutWidget = new QWidget(QAnalitikaArtikliWidgetClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 791, 581));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette;
        QBrush brush(QColor(228, 228, 228, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView->setPalette(palette);
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 2, 0, 1, 2);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView_2->setPalette(palette1);
        tableView_2->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView_2, 3, 0, 1, 2);

        QWidget::setTabOrder(lineEdit, tableView);

        retranslateUi(QAnalitikaArtikliWidgetClass);

        QMetaObject::connectSlotsByName(QAnalitikaArtikliWidgetClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QAnalitikaArtikliWidgetClass)
    {
        QAnalitikaArtikliWidgetClass->setWindowTitle(QApplication::translate("QAnalitikaArtikliWidgetClass", "QAnalitikaArtikliWidget", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QAnalitikaArtikliWidgetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\234\320\260\321\202\320\265\321\200\320\270\321\230\320\260\320\273\320\275\320\260 \320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260 \320\277\320\276 \320\220\321\200\321\202\320\270\320\272\320\273\320\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QAnalitikaArtikliWidgetClass", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 \320\277\320\276 \320\275\320\260\320\267\320\270\320\262 \320\270\320\273\320\270 \321\210\320\270\321\204\321\200\320\260 \320\275\320\260 \320\260\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QAnalitikaArtikliWidgetClass: public Ui_QAnalitikaArtikliWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QANALITIKAARTIKLIWIDGET_H
