#ifndef QPRIEMNICAKOREKCIJA_H
#define QPRIEMNICAKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qpriemnicakorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"

class QPriemnicaKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPriemnicaKorekcija(QWidget *parent = 0);
	~QPriemnicaKorekcija();
	virtual void pressEscape();
	virtual void pressReturn();
	virtual void pressF9();

	void setFocusLine();
	void setKomintent(QString text, QString textName);
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void init(int id);



private:
	bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
	Ui::QPriemnicaKorekcijaClass ui;
	QStandardItemModel *model;
	QHeaderView *header; 
	int selRow;
	QString textId;
	int m_id;
	int komintent_id;
	int artikal_id;
	int m_user_id;

	QString komintentID;
    QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
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

#endif // QPRIEMNICAKOREKCIJA_H
