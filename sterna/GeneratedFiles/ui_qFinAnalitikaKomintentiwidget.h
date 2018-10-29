/********************************************************************************
** Form generated from reading UI file 'qFinAnalitikaKomintentiwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFINANALITIKAKOMINTENTIWIDGET_H
#define UI_QFINANALITIKAKOMINTENTIWIDGET_H

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

class Ui_QFinAnalitKomintentiWidgetClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QTableView *tableView;
    QTableView *tableView_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;

    void setupUi(QMyBaseFormWidget *QFinAnalitKomintentiWidgetClass)
    {
        if (QFinAnalitKomintentiWidgetClass->objectName().isEmpty())
            QFinAnalitKomintentiWidgetClass->setObjectName(QString::fromUtf8("QFinAnalitKomintentiWidgetClass"));
        QFinAnalitKomintentiWidgetClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QFinAnalitKomintentiWidgetClass->setFont(font);
        layoutWidget = new QWidget(QFinAnalitKomintentiWidgetClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 791, 581));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 4, 0, 1, 4);

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

        gridLayout->addWidget(tableView, 2, 0, 1, 4);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView_2->setPalette(palette1);
        tableView_2->setFont(font);
        tableView_2->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView_2, 5, 0, 1, 4);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        QFont font2;
        font2.setPointSize(9);
        lineEdit_7->setFont(font2);
        lineEdit_7->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_7, 0, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font2);
        lineEdit_6->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_6, 0, 3, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 4, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font2);
        lineEdit_5->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_5, 0, 5, 1, 1);


        gridLayout->addLayout(gridLayout_2, 6, 0, 1, 4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font2);
        lineEdit_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font2);
        lineEdit_3->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_3, 0, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 4, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font2);
        lineEdit_4->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_4, 0, 5, 1, 1);


        gridLayout->addLayout(gridLayout_3, 3, 0, 1, 4);

        QWidget::setTabOrder(lineEdit, tableView);

        retranslateUi(QFinAnalitKomintentiWidgetClass);

        QMetaObject::connectSlotsByName(QFinAnalitKomintentiWidgetClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QFinAnalitKomintentiWidgetClass)
    {
        QFinAnalitKomintentiWidgetClass->setWindowTitle(QApplication::translate("QFinAnalitKomintentiWidgetClass", "QFinAnalitKomintentiWidget", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 \320\277\320\276 \320\275\320\260\320\267\320\270\320\262 \320\270\320\273\320\270 \321\210\320\270\321\204\321\200\320\260 \320\275\320\260 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\236\320\261\320\262\321\200\321\201\320\272\320\270 (</span><span style=\" font-size:10pt; font-weight:600; color:#0000ff;\">\320\244\320\270\320\275\320\260\320\275\321\201\320\276\320\262\320\260 \320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260 \320\275\320\260 \320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\224\320\276\320\273\320\266\320\270", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\237\320\276\320\261\320\260\321\200\321\203\320\262\320\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\241\320\260\320\273\320\264\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\224\320\276\320\273\320\266\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\237\320\276\320\261\320\260\321\200\321\203\320\262\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QFinAnalitKomintentiWidgetClass", "\320\241\320\260\320\273\320\264\320\276", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QFinAnalitKomintentiWidgetClass: public Ui_QFinAnalitKomintentiWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFINANALITIKAKOMINTENTIWIDGET_H
