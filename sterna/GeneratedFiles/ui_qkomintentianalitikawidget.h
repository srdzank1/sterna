/********************************************************************************
** Form generated from reading UI file 'qkomintentianalitikawidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKOMINTENTIANALITIKAWIDGET_H
#define UI_QKOMINTENTIANALITIKAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QKomintentiAnalitikaWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QTableView *tableView;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMyBaseFormWidget *QKomintentiAnalitikaWidget)
    {
        if (QKomintentiAnalitikaWidget->objectName().isEmpty())
            QKomintentiAnalitikaWidget->setObjectName(QString::fromUtf8("QKomintentiAnalitikaWidget"));
        QKomintentiAnalitikaWidget->resize(2400, 2400);
        layoutWidget = new QWidget(QKomintentiAnalitikaWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 791, 581));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 3, 0, 1, 6);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout->addWidget(tableView_2, 4, 0, 1, 6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 2, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setCheckable(true);

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCheckable(true);

        gridLayout_2->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setCheckable(true);

        gridLayout_2->addWidget(pushButton_5, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setCheckable(true);

        gridLayout_2->addWidget(pushButton_6, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setCheckable(true);

        gridLayout_2->addWidget(pushButton_7, 0, 4, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 4, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCheckable(true);

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);


        retranslateUi(QKomintentiAnalitikaWidget);

        QMetaObject::connectSlotsByName(QKomintentiAnalitikaWidget);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QKomintentiAnalitikaWidget)
    {
        QKomintentiAnalitikaWidget->setWindowTitle(QApplication::translate("QKomintentiAnalitikaWidget", "QKomintentiAnalitikaWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QKomintentiAnalitikaWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QKomintentiAnalitikaWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\230\320\267\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\222\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\230\321\201\320\277\321\200\320\260\321\202\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\241\320\260\320\273\320\264\320\276", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QKomintentiAnalitikaWidget", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKomintentiAnalitikaWidget: public Ui_QKomintentiAnalitikaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKOMINTENTIANALITIKAWIDGET_H
