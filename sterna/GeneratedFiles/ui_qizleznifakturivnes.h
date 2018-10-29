/********************************************************************************
** Form generated from reading UI file 'qizleznifakturivnes.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZLEZNIFAKTURIVNES_H
#define UI_QIZLEZNIFAKTURIVNES_H

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

class Ui_QIzlezniFakturiVnesClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLabel *label_8;
    QPushButton *pushButton_6;
    QTableView *tableView;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_2;
    QDateTimeEdit *dateTimeEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QLabel *label_14;
    QLineEdit *lineEdit_10;
    QLabel *label_15;
    QLineEdit *lineEdit_11;

    void setupUi(QMyBaseFormWidget *QIzlezniFakturiVnesClass)
    {
        if (QIzlezniFakturiVnesClass->objectName().isEmpty())
            QIzlezniFakturiVnesClass->setObjectName(QString::fromUtf8("QIzlezniFakturiVnesClass"));
        QIzlezniFakturiVnesClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QIzlezniFakturiVnesClass->setFont(font);
        layoutWidget = new QWidget(QIzlezniFakturiVnesClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 920, 551));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 2, 2, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

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

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(false);

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        dateTimeEdit_2 = new QDateTimeEdit(layoutWidget);
        dateTimeEdit_2->setObjectName(QString::fromUtf8("dateTimeEdit_2"));
        dateTimeEdit_2->setFont(font);
        dateTimeEdit_2->setDate(QDate(2000, 3, 1));
        dateTimeEdit_2->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit_2, 2, 3, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 3);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 2, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 3, 3, 1, 1);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 4, 3, 4, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 5, 1, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_9, 0, 1, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_10, 0, 3, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 0, 4, 1, 1);

        lineEdit_11 = new QLineEdit(layoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_11, 0, 5, 1, 1);


        gridLayout->addLayout(gridLayout_2, 9, 0, 1, 5);

        QWidget::setTabOrder(lineEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, dateTimeEdit_2);
        QWidget::setTabOrder(dateTimeEdit_2, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, textEdit);
        QWidget::setTabOrder(textEdit, tableView);
        QWidget::setTabOrder(tableView, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_6);

        retranslateUi(QIzlezniFakturiVnesClass);

        QMetaObject::connectSlotsByName(QIzlezniFakturiVnesClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QIzlezniFakturiVnesClass)
    {
        QIzlezniFakturiVnesClass->setWindowTitle(QApplication::translate("QIzlezniFakturiVnesClass", "QIzlezniFakturiVnes", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\222\320\260\320\273\321\203\321\202\320\260", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\240\320\276\320\272 \320\267\320\260 \320\277\320\273\320\260\320\272\320\260\321\232\320\265(\320\264\320\265\320\275\320\276\320\262\320\270)", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzlezniFakturiVnesClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\230\321\201\320\277\321\200\320\260\321\202\320\275\320\270\321\206\320\270-</span><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\244\320\260\320\272\321\202\321\203\321\200\320\270 - \320\222\320\275\320\265\321\201</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QIzlezniFakturiVnesClass", " \320\222\320\275\320\265\321\201\320\270", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QIzlezniFakturiVnesClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\240\320\260\320\261\320\260\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QIzlezniFakturiVnesClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("QIzlezniFakturiVnesClass", "8", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("QIzlezniFakturiVnesClass", "<html><head/><body><p>\320\237\321\200\320\270\321\202\320\270\321\201\320\275\320\270 \320\225\320\235\320\242\320\225\320\240 \320\267\320\260 \320\264\320\260 \321\202\320\265 \320\276\320\264\320\275\320\265\321\201\320\265 \320\262\320\276 \320\273\320\270\321\201\321\202\320\260\321\202\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        dateTimeEdit_2->setDisplayFormat(QApplication::translate("QIzlezniFakturiVnesClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("QIzlezniFakturiVnesClass", "<html><head/><body><p>\320\237\321\200\320\270\321\202\320\270\321\201\320\275\320\270 \320\225\320\235\320\242\320\225\320\240 \320\267\320\260 \320\264\320\260 \321\202\320\265 \320\276\320\264\320\275\320\265\321\201\320\265 \320\262\320\276 \320\273\320\270\321\201\321\202\320\260\321\202\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\227\320\260\320\261\320\265\320\273\320\265\321\210\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\227\320\260\320\273\320\270\321\205\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\246\320\265\320\275\320\260 \321\201\320\276 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\232\320\276\320\273\320\270\321\207\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\270\320\267\320\275\320\276\321\201 \320\261\320\265\320\267 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\224\320\224\320\222 \320\230\320\267\320\275\320\276\321\201", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QIzlezniFakturiVnesClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 \321\201\320\276 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzlezniFakturiVnesClass: public Ui_QIzlezniFakturiVnesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZLEZNIFAKTURIVNES_H
