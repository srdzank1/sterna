/********************************************************************************
** Form generated from reading UI file 'qprofakturakorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPROFAKTURAKOREKCIJA_H
#define UI_QPROFAKTURAKOREKCIJA_H

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

class Ui_QProFakturiKorekcijaClass
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QTableView *tableView;

    void setupUi(QWidget *QProFakturiKorekcijaClass)
    {
        if (QProFakturiKorekcijaClass->objectName().isEmpty())
            QProFakturiKorekcijaClass->setObjectName(QString::fromUtf8("QProFakturiKorekcijaClass"));
        QProFakturiKorekcijaClass->resize(859, 602);
        widget = new QWidget(QProFakturiKorekcijaClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 791, 521));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 3);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setDate(QDate(2000, 3, 1));

        gridLayout->addWidget(dateTimeEdit, 2, 1, 1, 2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 4, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 2);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 4, 1, 1, 2);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 5, 1, 1, 2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 2);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 6, 2, 1, 1);

        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 7, 0, 1, 5);

        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton_2);
        QWidget::setTabOrder(pushButton_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, tableView);

        retranslateUi(QProFakturiKorekcijaClass);

        QMetaObject::connectSlotsByName(QProFakturiKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QProFakturiKorekcijaClass)
    {
        QProFakturiKorekcijaClass->setWindowTitle(QApplication::translate("QProFakturiKorekcijaClass", "QProFakturiKorekcija", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QProFakturiKorekcijaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\321\200\320\276\321\204\320\260\320\272\321\202\321\203\321\200\320\260 - \320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\230\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\233\320\270\321\201\321\202\320\260 \320\275\320\260 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QProFakturiKorekcijaClass", "d/M/yyyy h:mm:ss AP", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QProFakturiKorekcijaClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\233\320\270\321\201\321\202\320\260 \320\275\320\260 \320\260\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\246\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\232\320\276\320\273\320\270\321\207\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QProFakturiKorekcijaClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QProFakturiKorekcijaClass: public Ui_QProFakturiKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPROFAKTURAKOREKCIJA_H
