/********************************************************************************
** Form generated from reading UI file 'qmyartiklilista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYARTIKLILISTA_H
#define UI_QMYARTIKLILISTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QMyArtikliListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5;
    QTableView *tableView;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *lineEdit_12;
    QLabel *label_6;
    QLabel *label_13;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMyBaseFormWidget *QMyArtikliListaClass)
    {
        if (QMyArtikliListaClass->objectName().isEmpty())
            QMyArtikliListaClass->setObjectName(QString::fromUtf8("QMyArtikliListaClass"));
        QMyArtikliListaClass->resize(2400, 2400);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        QMyArtikliListaClass->setPalette(palette);
        QFont font;
        font.setPointSize(10);
        QMyArtikliListaClass->setFont(font);
        QMyArtikliListaClass->setAutoFillBackground(false);
        layoutWidget = new QWidget(QMyArtikliListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 987, 431));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 7, 1, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette1;
        QBrush brush4(QColor(228, 228, 228, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        tableView->setPalette(palette1);
        tableView->setFont(font);
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 1, 0, 3, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font);
        lineEdit_7->setReadOnly(true);

        gridLayout->addWidget(lineEdit_7, 9, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_12 = new QLineEdit(layoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setFont(font);
        lineEdit_12->setReadOnly(true);

        gridLayout->addWidget(lineEdit_12, 9, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 7, 2, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 9, 2, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);
        lineEdit_4->setReadOnly(true);

        gridLayout->addWidget(lineEdit_4, 6, 1, 1, 3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 2, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);
        lineEdit_6->setReadOnly(true);

        gridLayout->addWidget(lineEdit_6, 7, 3, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 4, 3, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

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
        pushButton_3->setEnabled(true);
        pushButton_3->setFont(font);

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 10, 0, 1, 4);

        QWidget::setTabOrder(lineEdit, tableView);
        QWidget::setTabOrder(tableView, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_5);

        retranslateUi(QMyArtikliListaClass);

        QMetaObject::connectSlotsByName(QMyArtikliListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QMyArtikliListaClass)
    {
        QMyArtikliListaClass->setWindowTitle(QApplication::translate("QMyArtikliListaClass", "QMyArtikliLista", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QMyArtikliListaClass", "\320\230\320\264.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QMyArtikliListaClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273 \320\235\320\260\320\267\320\270\320\262", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QMyArtikliListaClass", "\320\232\320\260\321\202\320\260\320\273\320\276\321\210\320\272\320\270 \320\261\321\200\320\276\321\230", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QMyArtikliListaClass", "\320\225\320\264\320\274.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QMyArtikliListaClass", "\320\237\321\200\320\265\320\261\320\260\321\200\321\203\320\262\320\260\321\232\320\265 \320\277\320\276 \320\275\320\260\320\267\320\270\320\262 \320\270\320\273\320\270 \321\210\320\270\321\204\321\200\320\260 \320\275\320\260 \320\260\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QMyArtikliListaClass", "\320\240\320\265\321\204\320\265\321\200\320\265\320\275\321\206\320\260", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QMyArtikliListaClass", "\320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QMyArtikliListaClass", "\320\250\320\270\321\204\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QMyArtikliListaClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\220\321\200\321\202\320\270\320\272\320\273\320\270 - \320\233\320\270\321\201\321\202\320\260 </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QMyArtikliListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262 \320\260\321\200\321\202\320\270\320\272\320\260\320\273      ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QMyArtikliListaClass", "  \320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QMyArtikliListaClass", "\320\230\320\267\320\261\321\200\320\270\321\210\320\270\320\263\320\276 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\270\320\276\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QMyArtikliListaClass", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMyArtikliListaClass: public Ui_QMyArtikliListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYARTIKLILISTA_H
