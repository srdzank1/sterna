/********************************************************************************
** Form generated from reading UI file 'qkalkulacijalagerlista.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QKALKULACIJALAGERLISTA_H
#define UI_QKALKULACIJALAGERLISTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QKalkulacijaLagerLista
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *QKalkulacijaLagerLista)
    {
        if (QKalkulacijaLagerLista->objectName().isEmpty())
            QKalkulacijaLagerLista->setObjectName(QString::fromUtf8("QKalkulacijaLagerLista"));
        QKalkulacijaLagerLista->resize(842, 338);
        QFont font;
        font.setPointSize(9);
        QKalkulacijaLagerLista->setFont(font);
        layoutWidget = new QWidget(QKalkulacijaLagerLista);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 821, 321));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font1;
        font1.setPointSize(10);
        tableView->setFont(font1);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(QKalkulacijaLagerLista);

        QMetaObject::connectSlotsByName(QKalkulacijaLagerLista);
    } // setupUi

    void retranslateUi(QWidget *QKalkulacijaLagerLista)
    {
        QKalkulacijaLagerLista->setWindowTitle(QApplication::translate("QKalkulacijaLagerLista", "\320\233\320\260\320\263\320\265\321\200 \320\233\320\270\321\201\321\202\320\260 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QKalkulacijaLagerLista: public Ui_QKalkulacijaLagerLista {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QKALKULACIJALAGERLISTA_H
