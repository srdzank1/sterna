#ifndef QPovratnicaVNES_H
#define QPovratnicaVNES_H

#include "qmybaseformwidget.h"
#include "ui_qPovratnicavnes.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QPovratnicaVnes : public QMyBaseFormWidget
{
	Q_OBJECT
private:
    Ui::QPovratnicaVnesClass ui;

public:
	QPovratnicaVnes(QWidget *parent = 0);
	~QPovratnicaVnes();

    virtual void pressEscape();
    void setKomintent(QString text, QString textName);
    void setFocusLine();
    void setArtikli(QString text, QString textName);
    void setSaldo(QString text);
    void setFocusLine2();
	void setFocusLine3();

    void pressReturn();
	void pressF9();
	void setFakturi(QStringList& listData);
private:
    bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    QStandardItemModel *model;
    QHeaderView *header; 
    int selRow;
    QString textId;
    QString komintentID;
    int artikal_id;
    QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
	QString m_faktura_id;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
    void lineEditPressReturn();
	bool validateKomintent();
	

signals:
    void closeW();
    void scallKomintenti(QWidget*, QString);
    void scallArtikli(QWidget*, QString);
	void scallFakturi(QWidget*, QString);

	void editCell();
    void closeCell();


    private slots:
        void on_pushButton_4_clicked();
        void on_pushButton_5_clicked();
        void on_pushButton_6_clicked();
        void on_pushButton_3_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_clicked();
		void on_pushButton_clickedFakturiIzlezni();
        void selectionChanged(QModelIndex,QModelIndex);
        void on_plineEdit3_Pressed();
        void on_plineEdit4_Pressed();
        void on_plineEdit6_Pressed();
		void openEditor();
        void closeEditor();
};

#endif // QPovratnicaVNES_H
