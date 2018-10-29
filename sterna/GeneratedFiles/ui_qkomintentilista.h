/********************************************************************************
** Form generated from reading UI file 'qkomintentilista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKOMINTENTILISTA_H
#define UI_QKOMINTENTILISTA_H

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

class Ui_QKomintentiListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_15;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_7;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_16;

    void setupUi(QMyBaseFormWidget *QKomintentiListaClass)
    {
        if (QKomintentiListaClass->objectName().isEmpty())
            QKomintentiListaClass->setObjectName(QString::fromUtf8("QKomintentiListaClass"));
        QKomintentiListaClass->resize(2400, 2400);
        layoutWidget = new QWidget(QKomintentiListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 801, 481));
        QFont font;
        font.setPointSize(10);
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        gridLayout->addWidget(tableView, 6, 0, 4, 6);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 16, 3, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 17, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 17, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 18, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 3, 2, 1, 3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 16, 0, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 19, 3, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 20, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 18, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 19, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 21, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 22, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 21, 3, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 20, 3, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 22, 3, 1, 1);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFont(font);
        lineEdit_9->setReadOnly(true);

        gridLayout->addWidget(lineEdit_9, 16, 4, 1, 2);

        lineEdit_11 = new QLineEdit(layoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setFont(font);
        lineEdit_11->setReadOnly(true);

        gridLayout->addWidget(lineEdit_11, 18, 4, 1, 2);

        lineEdit_12 = new QLineEdit(layoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setFont(font);
        lineEdit_12->setReadOnly(true);

        gridLayout->addWidget(lineEdit_12, 19, 4, 1, 2);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setFont(font);
        lineEdit_10->setReadOnly(true);

        gridLayout->addWidget(lineEdit_10, 17, 4, 1, 2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(255, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(255, 255, 191, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(127, 127, 63, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(170, 170, 84, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        lineEdit_2->setPalette(palette1);
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 16, 1, 1, 2);

        lineEdit_14 = new QLineEdit(layoutWidget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setFont(font);
        lineEdit_14->setReadOnly(true);

        gridLayout->addWidget(lineEdit_14, 21, 4, 1, 2);

        lineEdit_15 = new QLineEdit(layoutWidget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setFont(font);
        lineEdit_15->setReadOnly(true);

        gridLayout->addWidget(lineEdit_15, 22, 4, 1, 2);

        lineEdit_13 = new QLineEdit(layoutWidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setFont(font);
        lineEdit_13->setReadOnly(true);

        gridLayout->addWidget(lineEdit_13, 20, 4, 1, 2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 17, 1, 1, 2);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);
        lineEdit_4->setReadOnly(true);

        gridLayout->addWidget(lineEdit_4, 18, 1, 1, 2);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);
        lineEdit_6->setReadOnly(true);

        gridLayout->addWidget(lineEdit_6, 20, 1, 1, 2);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 19, 1, 1, 2);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setFont(font);
        lineEdit_8->setReadOnly(true);

        gridLayout->addWidget(lineEdit_8, 22, 1, 1, 2);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font);
        lineEdit_7->setReadOnly(true);

        gridLayout->addWidget(lineEdit_7, 21, 1, 1, 2);

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


        gridLayout->addLayout(gridLayout_2, 23, 0, 1, 6);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        gridLayout->addWidget(label_16, 3, 5, 1, 1);

        QWidget::setTabOrder(lineEdit, tableView);
        QWidget::setTabOrder(tableView, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, lineEdit_12);
        QWidget::setTabOrder(lineEdit_12, lineEdit_13);
        QWidget::setTabOrder(lineEdit_13, lineEdit_14);
        QWidget::setTabOrder(lineEdit_14, lineEdit_15);

        retranslateUi(QKomintentiListaClass);

        QMetaObject::connectSlotsByName(QKomintentiListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QKomintentiListaClass)
    {
        QKomintentiListaClass->setWindowTitle(QApplication::translate("QKomintentiListaClass", "QKomintentiLista", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QKomintentiListaClass", "\320\221\320\260\320\275\320\272\320\260 \320\224\320\265\320\277\320\276\320\275\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QKomintentiListaClass", "\320\250\320\270\321\204\321\200\320\260 \320\275\320\260 \320\264\320\265\321\230\320\275\320\276\321\201\321\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QKomintentiListaClass", "\320\235\320\260\320\267\320\270\320\262", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QKomintentiListaClass", "\320\220\320\264\321\200\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QKomintentiListaClass", "\320\237\321\200\320\265\320\261\320\260\321\200\320\260\321\230 \320\277\320\276 \320\275\320\260\320\267\320\270\320\262 \320\270\320\273\320\270 \321\210\320\270\321\204\321\200\320\260 \320\275\320\260 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QKomintentiListaClass", "\320\250\320\270\321\204\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QKomintentiListaClass", "\320\225\320\234\320\221\320\223  (\321\204\320\270\320\267\320\270\321\207\320\272\320\276 \320\273\320\270\321\206\320\265)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QKomintentiListaClass", "\320\234\320\276\320\261\320\270\320\273", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QKomintentiListaClass", "\320\234\320\260\321\202\320\270\321\207\320\265\320\275 \320\261\321\200\320\276\321\230.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QKomintentiListaClass", "\320\242\320\265\320\273.", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QKomintentiListaClass", "\320\226\320\270\321\200\320\276 \321\201\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QKomintentiListaClass", "\320\225\320\264\320\261.", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QKomintentiListaClass", "\320\240\320\260\320\261\320\260\321\202", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QKomintentiListaClass", "\320\233\320\270\321\207\320\275\320\260 \320\272\320\260\321\200\321\202\320\260 (\321\204\320\270\320\267\320\270\321\207\320\272\320\276 \320\273\320\270\321\206\320\265)", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QKomintentiListaClass", "\320\223\321\200\320\260\320\264", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QKomintentiListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262 \320\272\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QKomintentiListaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QKomintentiListaClass", "\320\230\320\267\320\261\321\200\320\270\321\210\320\270 \320\263\320\276 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\270\320\276\321\202", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("QKomintentiListaClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270 -\320\233\320\270\321\201\321\202\320\260 </span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKomintentiListaClass: public Ui_QKomintentiListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKOMINTENTILISTA_H
