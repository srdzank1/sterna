/********************************************************************************
** Form generated from reading UI file 'qizleznismetkilista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZLEZNISMETKILISTA_H
#define UI_QIZLEZNISMETKILISTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QIzlezniSmetkiListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QTableView *tableView_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_11;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTableView *tableView;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;

    void setupUi(QMyBaseFormWidget *QIzlezniSmetkiListaClass)
    {
        if (QIzlezniSmetkiListaClass->objectName().isEmpty())
            QIzlezniSmetkiListaClass->setObjectName(QString::fromUtf8("QIzlezniSmetkiListaClass"));
        QIzlezniSmetkiListaClass->resize(2399, 2400);
        layoutWidget = new QWidget(QIzlezniSmetkiListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 669, 524));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font);
        tableView_2->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView_2, 6, 0, 1, 7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 4, 0, 1, 6);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 4, 6, 1, 1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        gridLayout->addWidget(radioButton_2, 5, 6, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette;
        QBrush brush(QColor(234, 234, 234, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView->setPalette(palette);
        tableView->setFont(font);
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 2, 0, 2, 7);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_6->setFont(font1);
        lineEdit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit_6, 7, 6, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 7, 5, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/key_f3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);

        gridLayout_2->addWidget(pushButton_5, 0, 4, 1, 1);


        gridLayout->addLayout(gridLayout_2, 8, 0, 1, 7);


        retranslateUi(QIzlezniSmetkiListaClass);

        QMetaObject::connectSlotsByName(QIzlezniSmetkiListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QIzlezniSmetkiListaClass)
    {
        QIzlezniSmetkiListaClass->setWindowTitle(QApplication::translate("QIzlezniSmetkiListaClass", "QIzlezniSmetkiLista", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzlezniSmetkiListaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\241\320\274\320\265\321\202\320\272\320\270 - </span><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\233\320\270\321\201\321\202\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 ", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\237\320\265\321\207\320\260\321\202\320\270 \320\273\320\270\321\201\321\202\320\260 \320\275\320\260 \321\201\320\274\320\265\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\237\320\265\321\207\320\260\321\202\320\270 \321\201\320\265\320\273\320\265\320\272\321\202\320\270\321\200\320\260\320\275\320\260 \321\201\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 \321\201\320\276 \320\224\320\224\320\222 ", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\221\321\200\320\270\321\210\320\270 \320\241\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\237\320\265\321\207\320\260\321\202\320\270 \320\244\320\270\321\201\320\272\320\260\320\273\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262\320\260 \321\201\320\274\320\265\321\202\320\272\320\270         ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260       ", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QIzlezniSmetkiListaClass", "\320\241\321\202\320\276\321\200\320\275\320\270\321\200\320\260\321\230 \320\244\320\270\321\201\320\272\320\260\320\273\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzlezniSmetkiListaClass: public Ui_QIzlezniSmetkiListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZLEZNISMETKILISTA_H
