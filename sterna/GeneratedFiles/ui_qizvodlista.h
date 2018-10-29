/********************************************************************************
** Form generated from reading UI file 'qizvodlista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZVODLISTA_H
#define UI_QIZVODLISTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QIzvodListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView_4;
    QTableView *tableView_3;
    QTableView *tableView_2;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMyBaseFormWidget *QIzvodListaClass)
    {
        if (QIzvodListaClass->objectName().isEmpty())
            QIzvodListaClass->setObjectName(QString::fromUtf8("QIzvodListaClass"));
        QIzvodListaClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QIzvodListaClass->setFont(font);
        layoutWidget = new QWidget(QIzvodListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 861, 561));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/key_f2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/sterna/Resources/key_f3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFont(font);

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 14, 0, 1, 5);

        tableView_4 = new QTableView(layoutWidget);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setFont(font);

        gridLayout->addWidget(tableView_4, 13, 0, 1, 5);

        tableView_3 = new QTableView(layoutWidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setFont(font);

        gridLayout->addWidget(tableView_3, 11, 0, 1, 5);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font);

        gridLayout->addWidget(tableView_2, 3, 0, 5, 5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 4, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 9, 0, 1, 5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 8, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 10, 0, 1, 3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 12, 0, 1, 3);


        retranslateUi(QIzvodListaClass);

        QMetaObject::connectSlotsByName(QIzvodListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QIzvodListaClass)
    {
        QIzvodListaClass->setWindowTitle(QApplication::translate("QIzvodListaClass", "QIzvodLista", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label->setText(QApplication::translate("QIzvodListaClass", "\320\221\320\260\320\275\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzvodListaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\230\320\267\320\262\320\276\320\264\320\270 - \320\233\320\270\321\201\321\202\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QIzvodListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262 \320\270\320\267\320\262\320\276\320\264", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QIzvodListaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\270\320\267\320\262\320\276\320\264 ", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzvodListaClass", "\320\230\320\267\320\261\321\200\320\270\321\210\320\270 \320\263\320\276 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\270\320\276\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QIzvodListaClass", "\320\230\320\267\320\262\320\276\320\264\320\270", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QIzvodListaClass", "\320\237\320\273\320\260\321\202\320\265\320\275\320\270 \320\276\320\261\320\262\321\200\321\201\320\272\320\270 \320\277\320\276 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270 (\320\272\321\203\320\277\321\203\320\262\320\260\321\207\320\270 \320\270 \320\264\320\276\320\261\320\260\320\262\321\203\320\262\320\260\321\207\320\270)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QIzvodListaClass", "\320\237\320\273\320\260\321\202\320\265\320\275\320\270 \320\276\320\261\320\262\321\200\321\201\320\272\320\270 \320\277\320\276 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzvodListaClass: public Ui_QIzvodListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZVODLISTA_H
