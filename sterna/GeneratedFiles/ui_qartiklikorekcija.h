/********************************************************************************
** Form generated from reading UI file 'qartiklikorekcija.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QARTIKLIKOREKCIJA_H
#define UI_QARTIKLIKOREKCIJA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QArtikliKorekcijaClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *QArtikliKorekcijaClass)
    {
        if (QArtikliKorekcijaClass->objectName().isEmpty())
            QArtikliKorekcijaClass->setObjectName(QString::fromUtf8("QArtikliKorekcijaClass"));
        QArtikliKorekcijaClass->resize(2400, 2400);
        QFont font;
        font.setPointSize(10);
        QArtikliKorekcijaClass->setFont(font);
        layoutWidget = new QWidget(QArtikliKorekcijaClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 831, 571));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font);

        gridLayout->addWidget(lineEdit_6, 6, 1, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font);

        gridLayout->addWidget(lineEdit_5, 5, 1, 1, 2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 7, 1, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font);

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/key_f9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pushButton, 2, 4, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 7, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setFont(font);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 9, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 9, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 9, 3, 1, 1);


        retranslateUi(QArtikliKorekcijaClass);

        QMetaObject::connectSlotsByName(QArtikliKorekcijaClass);
    } // setupUi

    void retranslateUi(QWidget *QArtikliKorekcijaClass)
    {
        QArtikliKorekcijaClass->setWindowTitle(QApplication::translate("QArtikliKorekcijaClass", "QArtikliKorekcija", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\250\320\270\321\204\321\200\320\260", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QArtikliKorekcijaClass", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QArtikliKorekcijaClass", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("QArtikliKorekcijaClass", "18", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QArtikliKorekcijaClass", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\320\220\321\200\321\202\320\270\320\272\320\273\320\270 - \320\232\320\276\321\200\320\265\320\263\320\270\321\200\320\260\321\230</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\235\320\260\320\267\320\270\320\262 \320\275\320\260 \320\220\321\200\321\202\320\270\320\272\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QArtikliKorekcijaClass", "E\320\264\320\274", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\240\320\265\321\204", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\232\320\260\321\202\320\260\320\273\320\276\321\210\320\272\320\270 \320\261\321\200\320\276\321\230", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QArtikliKorekcijaClass", "\320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QArtikliKorekcijaClass: public Ui_QArtikliKorekcijaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QARTIKLIKOREKCIJA_H
