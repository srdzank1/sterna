/********************************************************************************
** Form generated from reading UI file 'qfakturikorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFAKTURIKOREKCIJA_H
#define UI_QFAKTURIKOREKCIJA_H

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

QT_BEGIN_NAMESPACE

class Ui_QFakturiKorekcijaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QTableView *tableView;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButtonA;

    void setupUi(QWidget *QFakturiKorekcijaClass)
    {
        if (QFakturiKorekcijaClass->objectName().isEmpty())
            QFakturiKorekcijaClass->setObjectName(QString::fromUtf8("QFakturiKorekcijaClass"));
        QFakturiKorekcijaClass->resize(2400, 2400);
        layoutWidget = new QWidget(QFakturiKorekcijaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 851, 571));
        QFont font;
        font.setPointSize(10);
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 2, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(false);

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 5, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 6, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font);

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 8, 0, 1, 5);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFont(font);
        dateTimeEdit->setDate(QDate(2000, 3, 1));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);

        gridLayout->addWidget(lineEdit_6, 7, 3, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 7, 2, 1, 1);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 3, 5, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 5, 4, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 6, 4, 1, 1);

        pushButtonA = new QPushButton(layoutWidget);
        pushButtonA->setObjectName(QString::fromUtf8("pushButtonA"));

        gridLayout->addWidget(pushButtonA, 7, 4, 1, 1);


        retranslateUi(QFakturiKorekcijaClass);

        QMetaObject::connectSlotsByName(QFakturiKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QFakturiKorekcijaClass)
    {
        QFakturiKorekcijaClass->setWindowTitle(QApplication::translate("QFakturiKorekcijaClass", "QFakturiKorekcija", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\227\320\260\320\261\320\265\320\273\320\265\321\210\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QFakturiKorekcijaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\222\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202\321\203\321\200\320\270 - \320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\230\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\260 \320\230\320\264.", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QFakturiKorekcijaClass", " \320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\244\320\260\320\272\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("QFakturiKorekcijaClass", "<html><head/><body><p>\320\237\321\200\320\270\321\202\320\270\321\201\320\275\320\270 \320\225\320\235\320\242\320\225\320\240 \320\267\320\260 \320\264\320\260 \321\202\320\265 \320\276\320\264\320\275\320\265\321\201\320\265 \320\262\320\276 \320\273\320\270\321\201\321\202\320\260\321\202\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("QFakturiKorekcijaClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("QFakturiKorekcijaClass", "<html><head/><body><p>\320\237\321\200\320\270\321\202\320\270\321\201\320\275\320\270 \320\225\320\235\320\242\320\225\320\240 \320\267\320\260 \320\264\320\260 \321\202\320\265 \320\276\320\264\320\275\320\265\321\201\320\265 \320\262\320\276 \320\273\320\270\321\201\321\202\320\260\321\202\320\260</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\246\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\232\320\276\320\273\320\270\321\207\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\240\320\260\320\261\320\260\321\202", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QFakturiKorekcijaClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\241\320\260\320\273\320\264\320\276", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
        pushButtonA->setText(QApplication::translate("QFakturiKorekcijaClass", "\320\230\320\274\320\277\320\276\321\200\321\202 \320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QFakturiKorekcijaClass: public Ui_QFakturiKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFAKTURIKOREKCIJA_H
