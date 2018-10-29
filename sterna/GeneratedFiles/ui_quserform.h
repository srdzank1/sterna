/********************************************************************************
** Form generated from reading UI file 'quserform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUSERFORM_H
#define UI_QUSERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QUserForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *QUserForm)
    {
        if (QUserForm->objectName().isEmpty())
            QUserForm->setObjectName(QString::fromUtf8("QUserForm"));
        QUserForm->resize(483, 94);
        layoutWidget = new QWidget(QUserForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 381, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        retranslateUi(QUserForm);
        QObject::connect(pushButton, SIGNAL(clicked()), QUserForm, SLOT(accept()));

        QMetaObject::connectSlotsByName(QUserForm);
    } // setupUi

    void retranslateUi(QDialog *QUserForm)
    {
        QUserForm->setWindowTitle(QApplication::translate("QUserForm", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QUserForm", "User Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QUserForm", "Password", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QUserForm", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QUserForm: public Ui_QUserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUSERFORM_H
