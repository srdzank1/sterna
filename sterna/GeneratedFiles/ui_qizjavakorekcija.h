/********************************************************************************
** Form generated from reading UI file 'qizjavakorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIZJAVAKOREKCIJA_H
#define UI_QIZJAVAKOREKCIJA_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QIzjavaKorekcijaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *QIzjavaKorekcijaClass)
    {
        if (QIzjavaKorekcijaClass->objectName().isEmpty())
            QIzjavaKorekcijaClass->setObjectName(QString::fromUtf8("QIzjavaKorekcijaClass"));
        QIzjavaKorekcijaClass->resize(2400, 2400);
        layoutWidget = new QWidget(QIzjavaKorekcijaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 31, 751, 611));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QFont font;
        font.setPointSize(10);
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 2, 3, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(true);
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(false);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 2, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(false);

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 5, 1, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 6, 1, 1, 2);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font);

        gridLayout->addWidget(tableView, 8, 0, 1, 4);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 6, 3, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 7, 3, 1, 1);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFont(font);
        dateTimeEdit->setDate(QDate(2000, 3, 1));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        QWidget::setTabOrder(lineEdit_5, lineEdit);
        QWidget::setTabOrder(lineEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, tableView);

        retranslateUi(QIzjavaKorekcijaClass);

        QMetaObject::connectSlotsByName(QIzjavaKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QIzjavaKorekcijaClass)
    {
        QIzjavaKorekcijaClass->setWindowTitle(QApplication::translate("QIzjavaKorekcijaClass", "QIzjavaKorekcija", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("QIzjavaKorekcijaClass", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230 \320\230\320\267\321\230\320\260\320\262\320\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\221\321\200. \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\224\320\260\321\202\321\203\320\274", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\246\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\232\320\276\320\273\320\270\321\207\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\224\320\276\320\264\320\260\321\230 ", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("QIzjavaKorekcijaClass", "\320\221\321\200\320\270\321\210\320\270", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("QIzjavaKorekcijaClass", "d/M/yyyy", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QIzjavaKorekcijaClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\260 - \320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\230\320\260 \320\275\320\260 \320\260\321\200\321\202\320\270\320\272\320\273\320\270 (\320\276\320\264 \321\204\320\270\320\267\320\270\321\207\320\272\320\276 \320\273\320\270\321\206\320\265)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QIzjavaKorekcijaClass: public Ui_QIzjavaKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIZJAVAKOREKCIJA_H
