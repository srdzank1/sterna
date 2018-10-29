#ifndef QPRIEMNICAVNES_H
#define QPRIEMNICAVNES_H

#include "qmybaseformwidget.h"
#include "ui_qpriemnicavnes.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"
#include "xx.h"

class QPriemnicaVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPriemnicaVnes(QWidget *parent = 0);
	~QPriemnicaVnes();
	virtual void pressEscape();
	void setKomintent(QString text, QString textName);
	void setFocusLine();
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void pressReturn();
	void pressF9();



private:
	bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    Ui::QPriemnicaVnesClass ui;
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
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	void lineEditPressReturn();
	bool validateKomintent();


signals:
	void closeW();
	void scallKomintenti(QWidget*, QString);
	void scallArtikli(QWidget*, QString);
    void editCell();
    void closeCell();

	private slots:
		void on_pushButton_4_clicked();
		void on_pushButton_5_clicked();
		void on_pushButton_6_clicked();
		void on_pushButton_3_clicked();
		void on_pushButton_2_clicked();
		void on_pushButton_clicked();
		void selectionChanged(QModelIndex,QModelIndex);
        void on_plineEdit3_Pressed();
        void on_plineEdit4_Pressed();
        void openEditor();
        void closeEditor();

};

#endif // QPRIEMNICAVNES_H
