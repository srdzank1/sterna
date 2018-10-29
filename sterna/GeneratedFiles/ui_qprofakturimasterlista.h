/********************************************************************************
** Form generated from reading UI file 'qprofakturimasterlista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPROFAKTURIMASTERLISTA_H
#define UI_QPROFAKTURIMASTERLISTA_H

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

class Ui_QIzlezniprofakturimasterListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_6;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QTableView *tableView_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_12;
    QLabel *label;

    void setupUi(QMyBaseFormWidget *QIzlezniprofakturimasterListaClass)
    {
        if (QIzlezniprofakturimasterListaClass->objectName().isEmpty())
            QIzlezniprofakturimasterListaClass->setObjectName(QString::fromUtf8("QIzlezniprofakturimasterListaClass"));
        QIzlezniprofakturimasterListaClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QIzlezniprofakturimasterListaClass->setFont(font);
        layoutWidget = new QWidget(QIzlezniprofakturimasterListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1032, 561));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_6->setFont(font1);
        lineEdit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_6->setReadOnly(true);

        gridLayout->addWidget(lineEdit_6, 10, 1, 1, 2);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 5, 0, 1, 7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font);
        tableView_2->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView_2, 9, 0, 1, 7);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 10, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 10, 3, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 10, 5, 1, 1);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setFont(font1);
        lineEdit_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_8->setReadOnly(true);

        gridLayout->addWidget(lineEdit_8, 10, 4, 1, 1);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFont(font1);
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_9->setReadOnly(true);

        gridLayout->addWidget(lineEdit_9, 10, 6, 1, 1);

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

        gridLayout->addWidget(tableView, 3, 0, 2, 7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font);

        gridLayout->addWidget(lineEdit_7, 2, 1, 1, 5);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label_13->setPalette(palette1);
        label_13->setFont(font1);

        gridLayout->addWidget(label_13, 7, 0, 1, 7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/key_f3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 11, 0, 1, 7);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 6, 1, 1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        gridLayout->addWidget(radioButton_2, 2, 6, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 6, 0, 1, 7);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        gridLayout->addWidget(label, 8, 0, 1, 7);


        retranslateUi(QIzlezniprofakturimasterListaClass);

        QMetaObject::connectSlotsByName(QIzlezniprofakturimasterListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QIzlezniprofakturimasterListaClass)
    {
        QIzlezniprofakturimasterListaClass->setWindowTitle(QApplication::translate("QIzlezniprofakturimasterListaClass", "QIzlezniprofakturimasterLista", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\321\200\320\276-\320\244\320\260\320\272\321\202\321\203\321\200\320\270 - \320\233\320\270\321\201\321\202\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 \321\201\320\276 \320\224\320\224\320\222 ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\237\320\273\320\260\321\202\320\265\320\275 \320\230\320\267\320\275\320\276\321\201", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\236\321\201\321\202\320\260\320\275\320\260\321\202\320\276 \320\267\320\260 \320\277\320\273\320\260\320\272\320\260\321\232\320\265", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 \320\277\320\276 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        pushButton->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262\320\260 \320\277\321\200\320\276-\321\204\320\260\320\272\321\202\321\203\321\200\320\260         ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260       ", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\237\320\265\321\207\320\260\321\202\320\270 \320\273\320\270\321\201\321\202\320\260 \320\275\320\260 \320\277\321\200\320\276-\321\204\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\237\320\265\321\207\320\260\321\202\320\270 \321\201\320\265\320\273\320\265\320\272\321\202\320\270\321\200\320\260\320\275\320\260 \320\277\321\200\320\276-\321\204\320\260\320\272\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QIzlezniprofakturimasterListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 ", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QIzlezniprofakturimasterListaClass: public Ui_QIzlezniprofakturimasterListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPROFAKTURIMASTERLISTA_H
