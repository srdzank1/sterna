/********************************************************************************
** Form generated from reading UI file 'qkalkulacijalista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKALKULACIJALISTA_H
#define UI_QKALKULACIJALISTA_H

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

class Ui_QKalkulacijaListaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView_2;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_15;

    void setupUi(QMyBaseFormWidget *QKalkulacijaListaClass)
    {
        if (QKalkulacijaListaClass->objectName().isEmpty())
            QKalkulacijaListaClass->setObjectName(QString::fromUtf8("QKalkulacijaListaClass"));
        QKalkulacijaListaClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(9);
        QKalkulacijaListaClass->setFont(font);
        layoutWidget = new QWidget(QKalkulacijaListaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1056, 521));
        QFont font1;
        font1.setPointSize(10);
        layoutWidget->setFont(font1);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView_2 = new QTableView(layoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        QPalette palette;
        QBrush brush(QColor(215, 215, 215, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView_2->setPalette(palette);
        tableView_2->setFont(font1);
        tableView_2->setFrameShadow(QFrame::Plain);
        tableView_2->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView_2, 7, 0, 1, 4);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/key_f3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/sterna/Resources/key_f2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFont(font1);

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setFont(font1);

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 9, 0, 1, 4);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        tableView->setPalette(palette1);
        tableView->setFont(font1);
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 1, 0, 2, 4);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        gridLayout->addWidget(label_11, 3, 0, 1, 4);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_13->setFont(font2);

        gridLayout->addWidget(label_13, 4, 0, 1, 4);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        gridLayout->addWidget(label, 5, 0, 1, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 6, 0, 1, 4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_4, 1, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 3, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 0, 4, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 0, 5, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_6, 1, 2, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_7, 1, 3, 1, 1);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_8, 1, 4, 1, 1);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_9, 1, 5, 1, 1);

        lineEdit_10 = new QLineEdit(layoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(lineEdit_10, 1, 6, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 0, 6, 1, 1);


        gridLayout->addLayout(gridLayout_4, 8, 0, 1, 4);


        retranslateUi(QKalkulacijaListaClass);

        QMetaObject::connectSlotsByName(QKalkulacijaListaClass);
    } // setupUi

    void retranslateUi(QMyBaseFormWidget *QKalkulacijaListaClass)
    {
        QKalkulacijaListaClass->setWindowTitle(QApplication::translate("QKalkulacijaListaClass", "QKalkulacijaLista", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QKalkulacijaListaClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\270 - \320\232\320\260\320\273\320\272\321\203\320\273\320\260\321\206\320\270\320\270 - \320\233\320\270\321\201\321\202\320\260 \320\275\320\260 \320\264\320\276\320\261\320\260\320\262\321\203\320\262\320\260\321\207\320\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QKalkulacijaListaClass", "  \320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\275\320\265\321\201\320\270 \320\275\320\276\320\262\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QKalkulacijaListaClass", "\320\230\320\267\320\261\321\200\320\270\321\210\320\270\321\230\320\260 \321\230\320\260 \320\277\320\276\321\201\321\202\320\276\320\265\321\207\320\272\320\260\321\202\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QKalkulacijaListaClass", "Copy Table in Clipboard", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_13->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_7->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\235\320\260\320\261\320\260\320\262\320\265\320\275 \320\261\320\265\320\267 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\262\320\273\320\265\320\267\320\265\320\275 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\235\320\260\320\261\320\260\320\262\320\265\320\275 \321\201\320\276 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\274\320\260\321\200\320\266\320\260", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\277\321\200\320\276\320\264\320\260\320\266\320\265\320\275 \320\261\320\265\320\267 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\277\321\200\320\265\321\201\320\274\320\265\321\202\320\260\320\275 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QKalkulacijaListaClass", "\320\222\320\272. \320\277\321\200\320\276\320\264\320\260\320\266\320\265\320\275 \321\201\320\276 \320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKalkulacijaListaClass: public Ui_QKalkulacijaListaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKALKULACIJALISTA_H
