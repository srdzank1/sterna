/********************************************************************************
** Form generated from reading UI file 'qbankikorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBANKIKOREKCIJA_H
#define UI_QBANKIKOREKCIJA_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QBankiKorekcijaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_16;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QBankiKorekcijaClass)
    {
        if (QBankiKorekcijaClass->objectName().isEmpty())
            QBankiKorekcijaClass->setObjectName(QString::fromUtf8("QBankiKorekcijaClass"));
        QBankiKorekcijaClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QBankiKorekcijaClass->setFont(font);
        layoutWidget = new QWidget(QBankiKorekcijaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 681, 85));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        gridLayout->addWidget(label_16, 0, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        QWidget::setTabOrder(lineEdit, pushButton);

        retranslateUi(QBankiKorekcijaClass);

        QMetaObject::connectSlotsByName(QBankiKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QBankiKorekcijaClass)
    {
        QBankiKorekcijaClass->setWindowTitle(QApplication::translate("QBankiKorekcijaClass", "QBankiKorekcija", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("QBankiKorekcijaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\221\320\260\320\275\320\272\320\270 - \320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\230\320\260 </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QBankiKorekcijaClass", "\320\235\320\260\320\267\320\270\320\262", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QBankiKorekcijaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QBankiKorekcijaClass", "\320\226\320\270\321\200\320\276 \321\201\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QBankiKorekcijaClass: public Ui_QBankiKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBANKIKOREKCIJA_H
