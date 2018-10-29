/********************************************************************************
** Form generated from reading UI file 'qpovratnicavnes.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPOVRATNICAVNES_H
#define UI_QPOVRATNICAVNES_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QPovratnicaVnesClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QPushButton *pushButton_6;
    QTableView *tableView;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QTextEdit *textEdit;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QLabel *label_11;

    void setupUi(QMyBaseFormWidget *QPovratnicaVnesClass)
    {
        if (QPovratnicaVnesClass->objectName().isEmpty())
            QPovratnicaVnesClass->setObjectName(QString::fromUtf8("QPovratnicaVnesClass"));
        QPovratnicaVnesClass->resize(2400, 2400);
        layoutWidget = new QWidget(QPovratnicaVnesClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 851, 551));
        QFont font;
        font.setPointSize(10);
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 5, 4, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);

        gridLayout->addWidget(lineEdit_6, 6, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 2, 4, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 4, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 5, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 6, 4, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 8, 0, 1, 5);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFont(font);
        dateTimeEdit->setDate(QDate(2000, 3, 1));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 2, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(false);

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 7, 3, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 7, 2, 1, 1);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 3, 5, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 6, 3, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 6, 2, 1, 1);

        QWidget::setTabOrder(lineEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, tableView);
        QWidget::setTabOrder(tableView, textEdit);

        retranslateUi(QPovratnicaVnesClass);

        QMetaObject::connectSlotsByName(QPovratnicaVnesClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QPovratnicaVnesClass)
    {
        QPovratnicaVnesClass->setWindowTitle(QApplication::translate("QPovratnicaVnesClass", "QPovratnicaVnes", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QPovratnicaVnesClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QPovratnicaVnesClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\320\276\320\262\321\200\320\260\321\202\320\275\320\270\321\206\320\260 - \320\222\320\275\320\265\321\201</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QPovratnicaVnesClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QPovratnicaVnesClass", " \320\222\320\275\320\265\321\201\320\270 \320\277\320\276\320\262\321\200\320\260\321\202\320\275\320\270\321\206\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QPovratnicaVnesClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QPovratnicaVnesClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QPovratnicaVnesClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QPovratnicaVnesClass", "\320\246\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QPovratnicaVnesClass", "\320\232\320\276\320\273\320\270\321\207\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QPovratnicaVnesClass", "\320\240\320\260\320\261\320\260\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QPovratnicaVnesClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QPovratnicaVnesClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QPovratnicaVnesClass", "\320\240\320\276\320\272 \320\267\320\260 \320\277\320\273\320\260\320\272\320\260\321\232\320\265(\320\264\320\265\320\275\320\276\320\262\320\270)", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("QPovratnicaVnesClass", "8", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QPovratnicaVnesClass", "\320\222\320\272.\320\232\320\276\320\273.", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QPovratnicaVnesClass", "\320\227\320\260\320\261\320\265\320\273\320\265\321\210\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QPovratnicaVnesClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QPovratnicaVnesClass: public Ui_QPovratnicaVnesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPOVRATNICAVNES_H
