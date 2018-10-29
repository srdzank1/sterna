#ifndef QPovratnicaKOREKCIJA_H
#define QPovratnicaKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qPovratnicakorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QPovratnicaKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPovratnicaKorekcija(QWidget *parent = 0);
	~QPovratnicaKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

    void setFocusLine();
    void setKomintent(QString text, QString textName);
    void setArtikli(QString text, QString textName);
    void setSaldo(QString text);
    void setFocusLine2();
	void setFocusLine3();
    void init(int id);
	void setFakturi(QStringList& listData);

private:
	Ui::QPovratnicaKorekcijaClass ui;
    bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
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
	QString m_faktura_id;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
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
	void on_pushButton_clickedFakturiIzlezni();

    void on_pushButton_clicked();
    void selectionChanged(QModelIndex,QModelIndex);
    void on_plineEdit3_Pressed();
    void on_plineEdit4_Pressed();
	void on_plineEdit7_Pressed();
    void openEditor();
    void closeEditor();

};

#endif // QPovratnicaKOREKCIJA_H
