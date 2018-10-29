/********************************************************************************
** Form generated from reading UI file 'qizjavalista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZJAVALISTA_H
#define UI_QIZJAVALISTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include "qmybaseformwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QIzjavaListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QTableView *tableView;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QTableView *tableView_2;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QLineEdit *lineEdit_13;
    QLabel *label_13;
    QLabel *label_15;
    QLineEdit *lineEdit_14;
    QLabel *label_14;
    QLineEdit *lineEdit_12;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMyBaseFormWidget *QIzjavaListaClass)
    {
        if (QIzjavaListaClass->objectName().isEmpty())
            QIzjavaListaClass->setObjectName(QString::fromUtf8("QIzjavaListaClass"));
        QIzjavaListaClass->resize(2400, 2400);
        layoutWidget = new QWidget(QIzjavaListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 921, 571));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setPointSize(10);
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 1, 5, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::StyledPanel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);

        gridLayout->addWidget(lineEdit_6, 6, 2, 1, 3);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 5, 2, 1, 3);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 3, 5, 1, 1);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);
        tableView->setAlternatingRowColors(false);

        gridLayout->addWidget(tableView, 1, 0, 12, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);
        lineEdit_4->setReadOnly(true);

        gridLayout->addWidget(lineEdit_4, 4, 2, 1, 3);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 1, 2, 1, 3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 2, 2, 1, 3);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 3, 2, 1, 3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/sterna/Resources/key_f3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout->addWidget(pushButton_2, 2, 5, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font);

        gridLayout->addWidget(lineEdit_7, 7, 2, 1, 3);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setFont(font);

        gridLayout->addWidget(lineEdit_8, 8, 2, 1, 3);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFont(font);

        gridLayout->addWidget(lineEdit_9, 9, 2, 1, 3);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setFont(font);

        gridLayout->addWidget(lineEdit_10, 10, 2, 1, 3);

        lineEdit_11 = new QLineEdit(layoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setFont(font);

        gridLayout->addWidget(lineEdit_11, 11, 2, 1, 3);

        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font);
        tableView_2->setFrameShadow(QFrame::Plain);
        tableView_2->setAlternatingRowColors(false);

        gridLayout->addWidget(tableView_2, 13, 0, 1, 6);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::StyledPanel);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 9, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 11, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 10, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 8, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 7, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEdit_13 = new QLineEdit(layoutWidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit_13->setFont(font1);
        lineEdit_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit_13, 15, 0, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 14, 0, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        gridLayout->addWidget(label_15, 17, 3, 1, 1);

        lineEdit_14 = new QLineEdit(layoutWidget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setFont(font1);
        lineEdit_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit_14, 17, 4, 1, 2);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 15, 3, 1, 1);

        lineEdit_12 = new QLineEdit(layoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setFont(font1);
        lineEdit_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit_12, 15, 4, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 14, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        QWidget::setTabOrder(tableView, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);

        retranslateUi(QIzjavaListaClass);

        QMetaObject::connectSlotsByName(QIzjavaListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QIzjavaListaClass)
    {
        QIzjavaListaClass->setWindowTitle(QApplication::translate("QIzjavaListaClass", "QIzjavaLista", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QIzjavaListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262\320\260 \320\230\320\267\321\230\320\260\320\262\320\260                ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QIzjavaListaClass", "\320\223\321\200\320\260\320\264", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzjavaListaClass", "\320\230\320\267\320\261\321\200\320\270\321\210\320\270\321\230\320\260 \321\230\320\260 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260\321\202\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzjavaListaClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\230\320\267\321\230\320\260\320\262\320\260 - (\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\270 - \320\233\320\270\321\201\321\202\320\260 \320\276\320\264 \321\204\320\270\320\267\320\270\321\207\320\272\320\270 \320\273\320\270\321\206\320\260)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QIzjavaListaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260           ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QIzjavaListaClass", "\320\220\320\264\321\200\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QIzjavaListaClass", "\320\226\320\270\321\200\320\276 \321\201\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QIzjavaListaClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QIzjavaListaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QIzjavaListaClass", "\320\234\320\276\320\261\320\270\320\273\320\265\320\275", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QIzjavaListaClass", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QIzjavaListaClass", "\320\221\320\260\320\275\320\272\320\260 \320\224\320\265\320\277\320\276\320\275\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QIzjavaListaClass", "\320\225\320\234\320\221\320\223", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QIzjavaListaClass", "\320\233\320\270\321\207\320\275\320\260 \320\272\320\260\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QIzjavaListaClass", "\320\230\320\267\321\230\320\260\320\262\320\260 \320\221\321\200\320\276\321\230", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QIzjavaListaClass", "\320\222\320\272\321\203\320\277\320\265\320\275 \320\230\320\267\320\275\320\276\321\201 \321\201\320\276 \320\224\320\224\320\222 ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QIzjavaListaClass", "\320\236\321\201\321\202\320\260\320\275\320\260\321\202\320\276 \320\267\320\260 \320\277\320\273\320\260\320\272\320\260\321\232\320\265", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QIzjavaListaClass", "\320\237\320\273\320\260\321\202\320\265\320\275 \320\230\320\267\320\275\320\276\321\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzjavaListaClass: public Ui_QIzjavaListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZJAVALISTA_H
