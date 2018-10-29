/********************************************************************************
** Form generated from reading UI file 'qizvodkorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZVODKOREKCIJA_H
#define UI_QIZVODKOREKCIJA_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QIzvodKorekcijaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_11;
    QPushButton *pushButton_2;
    QTableView *tableView_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QLineEdit *lineEdit_5;
    QLabel *label_12;

    void setupUi(QWidget *QIzvodKorekcijaClass)
    {
        if (QIzvodKorekcijaClass->objectName().isEmpty())
            QIzvodKorekcijaClass->setObjectName(QString::fromUtf8("QIzvodKorekcijaClass"));
        QIzvodKorekcijaClass->resize(2417, 2400);
        QFont font;
        font.setPointSize(10);
        QIzvodKorekcijaClass->setFont(font);
        layoutWidget = new QWidget(QIzvodKorekcijaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 1011, 651));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 4, 5, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 8, 6, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 4, 2, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 4, 3, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        lineEdit_8->setFont(font);

        gridLayout->addWidget(lineEdit_8, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFont(font);
        dateTimeEdit->setDate(QDate(2000, 3, 1));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 2, 3, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);

        gridLayout->addWidget(pushButton_4, 0, 7, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 7, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 4, 7, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 4, 4, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 8, 7, 1, 1);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font);

        gridLayout->addWidget(tableView_2, 9, 0, 1, 8);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 8, 0, 1, 6);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 4, 6, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 3);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 5, 0, 3, 8);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 5, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 2, 4, 1, 1);


        retranslateUi(QIzvodKorekcijaClass);

        QMetaObject::connectSlotsByName(QIzvodKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QIzvodKorekcijaClass)
    {
        QIzvodKorekcijaClass->setWindowTitle(QApplication::translate("QIzvodKorekcijaClass", "QIzvodKorekcija", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\230\320\267\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzvodKorekcijaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\230\320\267\320\262\320\276\320\264 - \320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\230\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\236\320\264\320\261\320\265\321\200\320\270 \320\221\320\260\320\275\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\237\321\200\320\270\320\273\320\270\320\262", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\221\321\200\320\276\321\230 \320\275\320\260 \320\230\320\267\320\262\320\276\320\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QIzvodKorekcijaClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\230\320\267\320\262\320\276\320\264", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QIzvodKorekcijaClass", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\236\320\264\320\273\320\270\320\262", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\222\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\233\320\270\321\201\321\202\320\260 \320\275\320\260 \320\262\320\273\320\265\320\267\320\275\320\276 \320\270\320\267\320\273\320\265\320\267\320\275\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270 \320\267\320\260 \320\272\320\276\320\270 \321\201\320\265 \320\276\320\264\320\275\320\265\321\201\321\203\320\262\320\260 \320\277\320\273\320\260\320\272\320\260\321\232\320\265\321\202\320\276.", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QIzvodKorekcijaClass", "\320\230\320\267\320\262\320\276\320\264-\320\240\320\265\321\204\320\265\321\200\320\265\320\275\321\206\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzvodKorekcijaClass: public Ui_QIzvodKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZVODKOREKCIJA_H
