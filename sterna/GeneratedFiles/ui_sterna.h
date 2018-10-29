/********************************************************************************
** Form generated from reading UI file 'sterna.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STERNA_H
#define UI_STERNA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sternaClass
{
public:
    QAction *action_KomintentiLista;
    QAction *action_MyArtikli;
    QAction *actionMyIspratnici;
    QAction *actionMyPriemnici;
    QAction *actionMyPovratnica;
    QAction *actionMyFakturi;
    QAction *actionBanki;
    QAction *actionProFaktura;
    QAction *actionKasi;
    QAction *actionDDV;
    QAction *actionLager;
    QAction *actionIzvestai;
    QAction *actionIzvodi;
    QAction *actionPrinter;
    QAction *actionMyFakturiVlezni;
    QAction *actionAnalitikaKomintent;
    QAction *actionIzjava;
    QAction *actionDnevenPromet;
    QAction *actionClose;
    QAction *actionPreview;
    QAction *actionAnalitikaArtikli;
    QAction *action_n;
    QAction *actionSearch;
    QAction *actionPeriodicenIzvestaj;
    QAction *actionFinansova_Kartica;
    QAction *actionMyOdobrenie;
    QAction *actionVraboteni;
    QAction *actionSmetki;
    QAction *actionKalkulacii;
    QAction *actionIzvestaPromenaCeni;
    QAction *actionFakturiMaster;
    QAction *actionPopis;
    QAction *actionDnevnoFiskalnoZatvaranje;
    QAction *actionPorackiSmetki;
    QAction *actionKontrolenIzvestaj;
    QAction *actionDetalenIzvestajPoPeriod;
    QAction *actionPodesuvanjeDatumCas;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_4;
    QMenu *menu_3;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *sternaClass)
    {
        if (sternaClass->objectName().isEmpty())
            sternaClass->setObjectName(QString::fromUtf8("sternaClass"));
        sternaClass->resize(1284, 728);
        QFont font;
        font.setPointSize(8);
        sternaClass->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sterna/Resources/imagesCA93H0U6.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        sternaClass->setWindowIcon(icon);
        action_KomintentiLista = new QAction(sternaClass);
        action_KomintentiLista->setObjectName(QString::fromUtf8("action_KomintentiLista"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/sterna/Resources/imagesCADR5ZAI.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_KomintentiLista->setIcon(icon1);
        action_MyArtikli = new QAction(sternaClass);
        action_MyArtikli->setObjectName(QString::fromUtf8("action_MyArtikli"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/sterna/Resources/isimple_system_lnx-Icons-32X32-paste_png-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_MyArtikli->setIcon(icon2);
        actionMyIspratnici = new QAction(sternaClass);
        actionMyIspratnici->setObjectName(QString::fromUtf8("actionMyIspratnici"));
        actionMyIspratnici->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/sterna/Resources/add-file-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMyIspratnici->setIcon(icon3);
        actionMyIspratnici->setVisible(true);
        actionMyPriemnici = new QAction(sternaClass);
        actionMyPriemnici->setObjectName(QString::fromUtf8("actionMyPriemnici"));
        actionMyPriemnici->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/sterna/Resources/delete-file-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMyPriemnici->setIcon(icon4);
        actionMyPriemnici->setVisible(false);
        actionMyPovratnica = new QAction(sternaClass);
        actionMyPovratnica->setObjectName(QString::fromUtf8("actionMyPovratnica"));
        actionMyPovratnica->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/sterna/Resources/Pastel_Icons-folder_open_ico-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMyPovratnica->setIcon(icon5);
        actionMyPovratnica->setVisible(true);
        actionMyFakturi = new QAction(sternaClass);
        actionMyFakturi->setObjectName(QString::fromUtf8("actionMyFakturi"));
        actionMyFakturi->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/sterna/Resources/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMyFakturi->setIcon(icon6);
        actionMyFakturi->setVisible(false);
        actionBanki = new QAction(sternaClass);
        actionBanki->setObjectName(QString::fromUtf8("actionBanki"));
        actionBanki->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/sterna/Resources/bank.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBanki->setIcon(icon7);
        actionBanki->setVisible(true);
        actionProFaktura = new QAction(sternaClass);
        actionProFaktura->setObjectName(QString::fromUtf8("actionProFaktura"));
        actionProFaktura->setEnabled(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/sterna/Resources/pro_invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProFaktura->setIcon(icon8);
        actionProFaktura->setVisible(true);
        actionKasi = new QAction(sternaClass);
        actionKasi->setObjectName(QString::fromUtf8("actionKasi"));
        actionKasi->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/sterna/Resources/kasa1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKasi->setIcon(icon9);
        actionKasi->setVisible(false);
        actionDDV = new QAction(sternaClass);
        actionDDV->setObjectName(QString::fromUtf8("actionDDV"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/sterna/Resources/ddv.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDDV->setIcon(icon10);
        actionDDV->setVisible(false);
        actionLager = new QAction(sternaClass);
        actionLager->setObjectName(QString::fromUtf8("actionLager"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/sterna/Resources/lager.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLager->setIcon(icon11);
        actionIzvestai = new QAction(sternaClass);
        actionIzvestai->setObjectName(QString::fromUtf8("actionIzvestai"));
        actionIzvestai->setEnabled(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/sterna/Resources/reports.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIzvestai->setIcon(icon12);
        actionIzvestai->setVisible(true);
        actionIzvodi = new QAction(sternaClass);
        actionIzvodi->setObjectName(QString::fromUtf8("actionIzvodi"));
        actionIzvodi->setEnabled(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/sterna/Resources/isimple_system_lnx-Icons-32X32-file_new_png-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIzvodi->setIcon(icon13);
        actionIzvodi->setVisible(true);
        actionPrinter = new QAction(sternaClass);
        actionPrinter->setObjectName(QString::fromUtf8("actionPrinter"));
        actionPrinter->setEnabled(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/sterna/Resources/Printer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrinter->setIcon(icon14);
        actionPrinter->setVisible(true);
        actionPrinter->setIconVisibleInMenu(true);
        actionMyFakturiVlezni = new QAction(sternaClass);
        actionMyFakturiVlezni->setObjectName(QString::fromUtf8("actionMyFakturiVlezni"));
        actionMyFakturiVlezni->setIcon(icon12);
        actionMyFakturiVlezni->setVisible(false);
        actionAnalitikaKomintent = new QAction(sternaClass);
        actionAnalitikaKomintent->setObjectName(QString::fromUtf8("actionAnalitikaKomintent"));
        actionAnalitikaKomintent->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/sterna/Resources/k-color-edit-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalitikaKomintent->setIcon(icon15);
        actionAnalitikaKomintent->setVisible(false);
        actionIzjava = new QAction(sternaClass);
        actionIzjava->setObjectName(QString::fromUtf8("actionIzjava"));
        actionIzjava->setEnabled(false);
        actionIzjava->setIcon(icon8);
        actionIzjava->setVisible(false);
        actionDnevenPromet = new QAction(sternaClass);
        actionDnevenPromet->setObjectName(QString::fromUtf8("actionDnevenPromet"));
        actionDnevenPromet->setEnabled(false);
        actionDnevenPromet->setIcon(icon7);
        actionDnevenPromet->setVisible(false);
        actionClose = new QAction(sternaClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/sterna/Resources/close-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon16);
        actionPreview = new QAction(sternaClass);
        actionPreview->setObjectName(QString::fromUtf8("actionPreview"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/sterna/Resources/Preview-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreview->setIcon(icon17);
        actionAnalitikaArtikli = new QAction(sternaClass);
        actionAnalitikaArtikli->setObjectName(QString::fromUtf8("actionAnalitikaArtikli"));
        actionAnalitikaArtikli->setIcon(icon2);
        action_n = new QAction(sternaClass);
        action_n->setObjectName(QString::fromUtf8("action_n"));
        action_n->setIcon(icon5);
        action_n->setVisible(false);
        actionSearch = new QAction(sternaClass);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        actionSearch->setEnabled(true);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/sterna/Resources/zoom-in-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon18);
        actionSearch->setVisible(true);
        actionPeriodicenIzvestaj = new QAction(sternaClass);
        actionPeriodicenIzvestaj->setObjectName(QString::fromUtf8("actionPeriodicenIzvestaj"));
        actionPeriodicenIzvestaj->setEnabled(true);
        actionPeriodicenIzvestaj->setIcon(icon7);
        actionPeriodicenIzvestaj->setVisible(true);
        actionFinansova_Kartica = new QAction(sternaClass);
        actionFinansova_Kartica->setObjectName(QString::fromUtf8("actionFinansova_Kartica"));
        actionFinansova_Kartica->setIcon(icon9);
        actionMyOdobrenie = new QAction(sternaClass);
        actionMyOdobrenie->setObjectName(QString::fromUtf8("actionMyOdobrenie"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/sterna/Resources/grid1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMyOdobrenie->setIcon(icon19);
        actionMyOdobrenie->setVisible(false);
        actionVraboteni = new QAction(sternaClass);
        actionVraboteni->setObjectName(QString::fromUtf8("actionVraboteni"));
        actionVraboteni->setIcon(icon1);
        actionSmetki = new QAction(sternaClass);
        actionSmetki->setObjectName(QString::fromUtf8("actionSmetki"));
        actionSmetki->setEnabled(true);
        actionSmetki->setIcon(icon9);
        actionSmetki->setVisible(true);
        actionKalkulacii = new QAction(sternaClass);
        actionKalkulacii->setObjectName(QString::fromUtf8("actionKalkulacii"));
        actionKalkulacii->setIcon(icon9);
        actionKalkulacii->setVisible(true);
        actionIzvestaPromenaCeni = new QAction(sternaClass);
        actionIzvestaPromenaCeni->setObjectName(QString::fromUtf8("actionIzvestaPromenaCeni"));
        actionIzvestaPromenaCeni->setIcon(icon19);
        actionFakturiMaster = new QAction(sternaClass);
        actionFakturiMaster->setObjectName(QString::fromUtf8("actionFakturiMaster"));
        actionFakturiMaster->setIcon(icon8);
        actionPopis = new QAction(sternaClass);
        actionPopis->setObjectName(QString::fromUtf8("actionPopis"));
        actionPopis->setEnabled(false);
        actionPopis->setIcon(icon5);
        actionPopis->setVisible(false);
        actionDnevnoFiskalnoZatvaranje = new QAction(sternaClass);
        actionDnevnoFiskalnoZatvaranje->setObjectName(QString::fromUtf8("actionDnevnoFiskalnoZatvaranje"));
        actionPorackiSmetki = new QAction(sternaClass);
        actionPorackiSmetki->setObjectName(QString::fromUtf8("actionPorackiSmetki"));
        actionPorackiSmetki->setEnabled(false);
        actionPorackiSmetki->setIcon(icon2);
        actionPorackiSmetki->setVisible(false);
        actionKontrolenIzvestaj = new QAction(sternaClass);
        actionKontrolenIzvestaj->setObjectName(QString::fromUtf8("actionKontrolenIzvestaj"));
        actionDetalenIzvestajPoPeriod = new QAction(sternaClass);
        actionDetalenIzvestajPoPeriod->setObjectName(QString::fromUtf8("actionDetalenIzvestajPoPeriod"));
        actionPodesuvanjeDatumCas = new QAction(sternaClass);
        actionPodesuvanjeDatumCas->setObjectName(QString::fromUtf8("actionPodesuvanjeDatumCas"));
        centralWidget = new QWidget(sternaClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sternaClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sternaClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1284, 21));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        sternaClass->setMenuBar(menuBar);
        toolBar = new QToolBar(sternaClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        sternaClass->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(sternaClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sternaClass->setStatusBar(statusBar);
        toolBar_2 = new QToolBar(sternaClass);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setOrientation(Qt::Horizontal);
        toolBar_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        sternaClass->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(sternaClass);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        toolBar_3->setEnabled(true);
        toolBar_3->setOrientation(Qt::Horizontal);
        toolBar_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        sternaClass->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(sternaClass);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        toolBar_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        sternaClass->addToolBar(Qt::TopToolBarArea, toolBar_4);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_4->addAction(actionLager);
        menu_4->addAction(actionIzvestai);
        menu_4->addAction(actionDnevenPromet);
        menu_4->addSeparator();
        menu_4->addAction(actionAnalitikaKomintent);
        menu_4->addAction(actionAnalitikaArtikli);
        menu_4->addSeparator();
        menu_4->addAction(actionFinansova_Kartica);
        menu_3->addAction(actionMyFakturiVlezni);
        menu_3->addAction(actionKalkulacii);
        menu_3->addAction(actionMyFakturi);
        menu_3->addAction(actionProFaktura);
        menu_3->addSeparator();
        menu_3->addAction(actionIzvodi);
        menu->addAction(action_MyArtikli);
        menu->addAction(actionDDV);
        menu->addAction(actionBanki);
        menu->addAction(actionKasi);
        menu->addAction(action_KomintentiLista);
        menu->addSeparator();
        menu->addAction(actionPreview);
        menu->addAction(actionPrinter);
        menu->addAction(actionClose);
        menu->addAction(actionVraboteni);
        menu_2->addAction(actionDnevnoFiskalnoZatvaranje);
        menu_2->addAction(actionKontrolenIzvestaj);
        menu_2->addAction(actionDetalenIzvestajPoPeriod);
        menu_2->addAction(actionPodesuvanjeDatumCas);
        toolBar->addAction(action_MyArtikli);
        toolBar->addAction(action_KomintentiLista);
        toolBar->addAction(actionIzjava);
        toolBar->addAction(actionMyPriemnici);
        toolBar->addAction(action_n);
        toolBar->addAction(actionKasi);
        toolBar_2->addAction(actionKalkulacii);
        toolBar_2->addAction(actionMyFakturiVlezni);
        toolBar_2->addAction(actionMyIspratnici);
        toolBar_2->addAction(actionMyFakturi);
        toolBar_2->addAction(actionMyPovratnica);
        toolBar_2->addAction(actionProFaktura);
        toolBar_2->addAction(actionFakturiMaster);
        toolBar_2->addAction(actionSmetki);
        toolBar_2->addAction(actionPorackiSmetki);
        toolBar_2->addAction(actionIzvodi);
        toolBar_2->addAction(actionMyOdobrenie);
        toolBar_3->addAction(actionLager);
        toolBar_3->addAction(actionAnalitikaKomintent);
        toolBar_3->addAction(actionAnalitikaArtikli);
        toolBar_3->addAction(actionFinansova_Kartica);
        toolBar_3->addAction(actionPopis);
        toolBar_4->addAction(actionSearch);
        toolBar_4->addAction(actionPreview);
        toolBar_4->addAction(actionIzvestaPromenaCeni);
        toolBar_4->addAction(actionDnevenPromet);
        toolBar_4->addAction(actionPeriodicenIzvestaj);
        toolBar_4->addAction(actionIzvestai);
        toolBar_4->addAction(actionClose);

        retranslateUi(sternaClass);

        QMetaObject::connectSlotsByName(sternaClass);
    } // setupUi

    void retranslateUi(QMainWindow *sternaClass)
    {
        sternaClass->setWindowTitle(QApplication::translate("sternaClass", "Sterna", 0, QApplication::UnicodeUTF8));
        action_KomintentiLista->setText(QApplication::translate("sternaClass", "\320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        action_KomintentiLista->setShortcut(QApplication::translate("sternaClass", "Alt+K", 0, QApplication::UnicodeUTF8));
        action_MyArtikli->setText(QApplication::translate("sternaClass", "\320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
        action_MyArtikli->setShortcut(QApplication::translate("sternaClass", "Alt+A", 0, QApplication::UnicodeUTF8));
        actionMyIspratnici->setText(QApplication::translate("sternaClass", "\320\230\321\201\320\277\321\200\320\260\321\202\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
        actionMyIspratnici->setShortcut(QApplication::translate("sternaClass", "Alt+I", 0, QApplication::UnicodeUTF8));
        actionMyPriemnici->setText(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
        actionMyPriemnici->setShortcut(QApplication::translate("sternaClass", "Alt+P", 0, QApplication::UnicodeUTF8));
        actionMyPovratnica->setText(QApplication::translate("sternaClass", "\320\237\320\276\320\262\321\200\320\260\321\202\320\275\320\270\321\206\320\270", 0, QApplication::UnicodeUTF8));
        actionMyPovratnica->setShortcut(QApplication::translate("sternaClass", "Alt+O", 0, QApplication::UnicodeUTF8));
        actionMyFakturi->setText(QApplication::translate("sternaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        actionMyFakturi->setIconText(QApplication::translate("sternaClass", "\320\230\321\201\320\277\321\200\320\260\321\202\320\275\320\270\321\206\320\270\n"
"\320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        actionMyFakturi->setShortcut(QApplication::translate("sternaClass", "Alt+F", 0, QApplication::UnicodeUTF8));
        actionBanki->setText(QApplication::translate("sternaClass", "\320\221\320\260\320\275\320\272\320\270", 0, QApplication::UnicodeUTF8));
        actionProFaktura->setText(QApplication::translate("sternaClass", "\320\237\321\200\320\276\320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        actionKasi->setText(QApplication::translate("sternaClass", "\320\232\320\260\321\201\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionKasi->setToolTip(QApplication::translate("sternaClass", "\320\232\320\260\321\201\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDDV->setText(QApplication::translate("sternaClass", "\320\224\320\224\320\222", 0, QApplication::UnicodeUTF8));
        actionLager->setText(QApplication::translate("sternaClass", "\320\233\320\260\320\263\320\265\321\200 \320\233\320\270\321\201\321\202\320\260", 0, QApplication::UnicodeUTF8));
        actionLager->setShortcut(QApplication::translate("sternaClass", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionIzvestai->setText(QApplication::translate("sternaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\270 Gantt Chart", 0, QApplication::UnicodeUTF8));
        actionIzvestai->setIconText(QApplication::translate("sternaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\270\n"
" Gantt Chart", 0, QApplication::UnicodeUTF8));
        actionIzvodi->setText(QApplication::translate("sternaClass", "\320\230\320\267\320\262\320\276\320\264\320\270", 0, QApplication::UnicodeUTF8));
        actionIzvodi->setShortcut(QApplication::translate("sternaClass", "Alt+I", 0, QApplication::UnicodeUTF8));
        actionPrinter->setText(QApplication::translate("sternaClass", "Print", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPrinter->setToolTip(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\275\321\202\320\265\321\200 (Ctrl+P)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPrinter->setShortcut(QApplication::translate("sternaClass", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionMyFakturiVlezni->setText(QApplication::translate("sternaClass", "\320\222\320\273\320\265\320\267\320\275\320\270 \320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        actionMyFakturiVlezni->setIconText(QApplication::translate("sternaClass", "\320\222\320\273\320\265\320\267\320\275\320\270\n"
" \320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
        actionAnalitikaKomintent->setText(QApplication::translate("sternaClass", "\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260 \320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionAnalitikaKomintent->setIconText(QApplication::translate("sternaClass", "\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260\n"
" \320\232\320\276\320\274\320\270\320\275\321\202\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        actionAnalitikaKomintent->setShortcut(QApplication::translate("sternaClass", "Ctrl+Shift+K", 0, QApplication::UnicodeUTF8));
        actionIzjava->setText(QApplication::translate("sternaClass", "\320\230\320\267\321\230\320\260\320\262\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionIzjava->setToolTip(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\260 \320\276\320\264 \321\204\320\270\320\267\320\270\321\207\320\272\320\276 \320\273\320\270\321\206\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionIzjava->setShortcut(QApplication::translate("sternaClass", "Alt+J", 0, QApplication::UnicodeUTF8));
        actionDnevenPromet->setText(QApplication::translate("sternaClass", "\320\224\320\275\320\265\320\262\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
        actionDnevenPromet->setIconText(QApplication::translate("sternaClass", "\320\224\320\275\320\265\320\262\320\265\320\275\n"
"\320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDnevenPromet->setToolTip(QApplication::translate("sternaClass", "\320\224\320\275\320\265\320\262\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionClose->setText(QApplication::translate("sternaClass", "Close", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("sternaClass", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionPreview->setText(QApplication::translate("sternaClass", "Preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPreview->setToolTip(QApplication::translate("sternaClass", "Preview (Ctrl+W)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPreview->setShortcut(QApplication::translate("sternaClass", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionAnalitikaArtikli->setText(QApplication::translate("sternaClass", "\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260 \320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
        actionAnalitikaArtikli->setIconText(QApplication::translate("sternaClass", "\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260\n"
" \320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAnalitikaArtikli->setToolTip(QApplication::translate("sternaClass", "\320\220\320\275\320\260\320\273\320\270\321\202\320\270\320\272\320\260 \320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAnalitikaArtikli->setShortcut(QApplication::translate("sternaClass", "Ctrl+Shift+A", 0, QApplication::UnicodeUTF8));
        action_n->setText(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274 \320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
        action_n->setIconText(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274\n"
"\320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_n->setToolTip(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274 \320\220\321\200\321\202\320\270\320\272\320\273\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSearch->setText(QApplication::translate("sternaClass", "Search", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSearch->setToolTip(QApplication::translate("sternaClass", "Search", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSearch->setShortcut(QApplication::translate("sternaClass", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionPeriodicenIzvestaj->setText(QApplication::translate("sternaClass", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
        actionPeriodicenIzvestaj->setIconText(QApplication::translate("sternaClass", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\320\275\n"
" \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPeriodicenIzvestaj->setToolTip(QApplication::translate("sternaClass", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFinansova_Kartica->setText(QApplication::translate("sternaClass", "\320\236\320\261\320\262\321\200\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
        actionFinansova_Kartica->setIconText(QApplication::translate("sternaClass", "\320\236\320\261\320\262\321\200\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFinansova_Kartica->setToolTip(QApplication::translate("sternaClass", "\320\244\320\270\320\275\320\260\321\201\320\276\320\262\320\260 \320\232\320\260\321\200\321\202\320\270\321\206\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFinansova_Kartica->setShortcut(QApplication::translate("sternaClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionMyOdobrenie->setText(QApplication::translate("sternaClass", "\320\232\320\275\320\270\320\266\320\275\320\276 \320\236\320\264\320\276\320\261\321\200\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        actionMyOdobrenie->setIconText(QApplication::translate("sternaClass", "\320\232\320\275\320\270\320\266\320\275\320\276\n"
"\320\236\320\264\320\276\320\261\321\200\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionMyOdobrenie->setToolTip(QApplication::translate("sternaClass", "\320\236\320\264\320\276\320\261\321\200\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionVraboteni->setText(QApplication::translate("sternaClass", "\320\222\321\200\320\260\320\261\320\276\321\202\320\265\320\275\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionVraboteni->setToolTip(QApplication::translate("sternaClass", "\320\222\321\200\320\260\320\261\320\276\321\202\320\265\320\275\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionVraboteni->setShortcut(QApplication::translate("sternaClass", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionSmetki->setText(QApplication::translate("sternaClass", "\320\241\320\274\320\265\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSmetki->setToolTip(QApplication::translate("sternaClass", "\320\241\320\274\320\265\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSmetki->setShortcut(QApplication::translate("sternaClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionKalkulacii->setText(QApplication::translate("sternaClass", " \320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\260 -\320\232\320\260\320\273\320\272\321\203\320\273\320\260\321\206\320\270\321\230\320\260", 0, QApplication::UnicodeUTF8));
        actionKalkulacii->setIconText(QApplication::translate("sternaClass", "\320\237\321\200\320\270\320\265\320\274\320\275\320\270\321\206\320\260\n"
"\320\232\320\260\320\273\320\272\321\203\320\273\320\260\321\206\320\270\321\230\320\260", 0, QApplication::UnicodeUTF8));
        actionKalkulacii->setShortcut(QApplication::translate("sternaClass", "Alt+K", 0, QApplication::UnicodeUTF8));
        actionIzvestaPromenaCeni->setText(QApplication::translate("sternaClass", "IzvestaPromenaCeni", 0, QApplication::UnicodeUTF8));
        actionIzvestaPromenaCeni->setIconText(QApplication::translate("sternaClass", "\320\237\321\200\320\276\320\274\320\265\320\275\320\260 \320\275\320\260\n"
"\321\206\320\265\320\275\320\270", 0, QApplication::UnicodeUTF8));
        actionIzvestaPromenaCeni->setShortcut(QApplication::translate("sternaClass", "Ctrl+P, Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionFakturiMaster->setText(QApplication::translate("sternaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionFakturiMaster->setToolTip(QApplication::translate("sternaClass", "\320\244\320\260\320\272\321\202\321\203\321\200\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPopis->setText(QApplication::translate("sternaClass", "Popis", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPopis->setToolTip(QApplication::translate("sternaClass", "\320\237\320\276\320\277\320\270\321\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDnevnoFiskalnoZatvaranje->setText(QApplication::translate("sternaClass", "\320\224\320\275\320\265\320\262\320\275\320\276 \320\244\320\270\321\201\320\272\320\260\320\273\320\275\320\276 \320\227\320\260\321\202\320\262\320\260\321\200\320\260\321\232\320\265", 0, QApplication::UnicodeUTF8));
        actionPorackiSmetki->setText(QApplication::translate("sternaClass", "\320\237\320\276\321\200\320\260\321\207\320\272\320\260 \320\241\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        actionPorackiSmetki->setIconText(QApplication::translate("sternaClass", "\320\237\320\276\321\200\320\260\321\207\320\272\320\260\n"
"\320\241\320\274\320\265\321\202\320\272\320\260", 0, QApplication::UnicodeUTF8));
        actionKontrolenIzvestaj->setText(QApplication::translate("sternaClass", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230", 0, QApplication::UnicodeUTF8));
        actionDetalenIzvestajPoPeriod->setText(QApplication::translate("sternaClass", "\320\224\320\265\321\202\320\260\320\273\320\265\320\275 \320\230\320\267\320\262\320\265\321\210\321\202\320\260\321\230 \320\277\320\276 \320\277\320\265\321\200\320\270\320\276\320\264", 0, QApplication::UnicodeUTF8));
        actionPodesuvanjeDatumCas->setText(QApplication::translate("sternaClass", "\320\237\320\276\320\264\320\265\321\201\321\203\320\262\320\260\321\232\320\265 \320\224\320\260\321\202\321\203\320\274 \320\247\320\260\321\201", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("sternaClass", "\320\230\320\267\320\262\320\265\321\210\321\202\320\260\320\270", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("sternaClass", "\320\234\320\260\321\202\320\265\321\200\320\270\321\230\320\260\320\273\320\275\320\276-\320\244\320\270\320\275\320\260\320\275\321\201\320\276\320\262\320\276", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("sternaClass", "\320\224\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("sternaClass", "\320\244\320\270\321\201\320\272\320\260\320\273\320\275\320\270 \320\241\320\274\320\265\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("sternaClass", "\320\234\320\260\321\202\320\265\321\200\320\270\321\230\320\260\320\273\320\275\320\276", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("sternaClass", "\320\244\320\270\320\275\320\260\320\275\321\201\320\276\320\262\320\276", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("sternaClass", "\320\230\320\267\320\262\320\265\321\210\321\202\320\260\320\270", 0, QApplication::UnicodeUTF8));
        toolBar_4->setWindowTitle(QApplication::translate("sternaClass", "\320\220\320\273\320\260\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sternaClass: public Ui_sternaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STERNA_H
