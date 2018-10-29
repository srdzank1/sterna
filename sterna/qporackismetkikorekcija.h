#ifndef QPorackiSmetkiKOREKCIJA_H
#define QPorackiSmetkiKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qPorackiSmetkikorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QPorackiSmetkiKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPorackiSmetkiKorekcija(QWidget *parent = 0);
	~QPorackiSmetkiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

    void setFocusLine();
    void setKomintent(QString text, QString textName);
    void setArtikli(QString text, QString textName);
	void setProdCena(QString text);
	void setNabCena(QString text);
	void setSaldo(QString text);
    void setFocusLine2();
    void init(int id);

private:
	Ui::QPorackiSmetkiKorekcijaClass ui;
    bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    QStandardItemModel *model;
	QStandardItemModel *model2;
    QHeaderView *header; 
	QHeaderView *header2; 
    int selRow;
	QString m_staraCena;
	int m_user_id;
    QString textId;
    int m_id;
	QString textIdPlakanje;
	int artikal_id_plakanje;
    int komintent_id;
    int artikal_id;
    QString komintentID;
    QString dokumentID;
	QString m_dok_id;
	int stat_artikal_call;
	QString artikal_komintent_id;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
	QString m_staraNabCena;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	bool validateKomintent();
	void calculateIznosi();

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
	void on_pushButton_7_clicked();
	void on_pushButton_9_clicked();
	void on_pushButton_10_clicked();

    void on_pushButton_clicked();
    void selectionChanged(QModelIndex,QModelIndex);
    void on_plineEdit3_Pressed();
    void on_plineEdit4_Pressed();
	void on_plineEdit7_Pressed();
    void openEditor();
    void closeEditor();
};

#endif // QPorackiSmetkiKOREKCIJA_H
