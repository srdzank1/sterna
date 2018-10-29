/********************************************************************************
** Form generated from reading UI file 'qsearchform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSEARCHFORM_H
#define UI_QSEARCHFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QSearchForm
{
public:
    QLineEdit *lineEdit;

    void setupUi(QDialog *QSearchForm)
    {
        if (QSearchForm->objectName().isEmpty())
            QSearchForm->setObjectName(QString::fromUtf8("QSearchForm"));
        QSearchForm->resize(371, 63);
        lineEdit = new QLineEdit(QSearchForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 20, 261, 20));

        retranslateUi(QSearchForm);

        QMetaObject::connectSlotsByName(QSearchForm);
    } // setupUi

    void retranslateUi(QDialog *QSearchForm)
    {
        QSearchForm->setWindowTitle(QApplication::translate("QSearchForm", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QSearchForm: public Ui_QSearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSEARCHFORM_H
