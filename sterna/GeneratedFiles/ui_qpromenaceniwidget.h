/********************************************************************************
** Form generated from reading UI file 'qpromenaceniwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPROMENACENIWIDGET_H
#define UI_QPROMENACENIWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QPromenaCeniWidgetClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QMyBaseFormWidget *QPromenaCeniWidgetClass)
    {
        if (QPromenaCeniWidgetClass->objectName().isEmpty())
            QPromenaCeniWidgetClass->setObjectName(QString::fromUtf8("QPromenaCeniWidgetClass"));
        QPromenaCeniWidgetClass->resize(2400, 2400);
        layoutWidget = new QWidget(QPromenaCeniWidgetClass);
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

        gridLayout->addWidget(tableView, 1, 0, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(QPromenaCeniWidgetClass);

        QMetaObject::connectSlotsByName(QPromenaCeniWidgetClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QPromenaCeniWidgetClass)
    {
        QPromenaCeniWidgetClass->setWindowTitle(QApplication::translate("QPromenaCeniWidgetClass", "QPromenaCeniWidget", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QPromenaCeniWidgetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230 \320\267\320\260 \320\277\321\200\320\276\320\274\320\265\320\275\320\260 \320\275\320\260 \321\206\320\265\320\275\320\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QPromenaCeniWidgetClass", "Copy to Clipboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QPromenaCeniWidgetClass: public Ui_QPromenaCeniWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPROMENACENIWIDGET_H
