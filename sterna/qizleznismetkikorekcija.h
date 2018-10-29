#ifndef QIZLEZNISmetkiKOREKCIJA_H
#define QIZLEZNISmetkiKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qizlezniSmetkikorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QIzlezniSmetkiKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzlezniSmetkiKorekcija(QWidget *parent = 0);
	~QIzlezniSmetkiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

    void setFocusLine();
    void setKomintent(QString text, QString textName);
    void setArtikli(QString text, QString textName, QString textKomintentId);
	void setProdCena(QString text);
	void setNabCena(QString text);
	void setSaldo(QString text);
    void setFocusLine2();
    void init(int id);

private:
	Ui::QIzlezniSmetkiKorekcijaClass ui;
    bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    QStandardItemModel *model;
    QHeaderView *header; 
    int selRow;
	QString m_staraCena;
	int m_user_id;
    QString textId;
    int m_id;
    int komintent_id;
    int artikal_id;
    QString komintentID;
    QString dokumentID;
	QString m_dok_id;
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
    void on_pushButton_clicked();
    void selectionChanged(QModelIndex,QModelIndex);
    void on_plineEdit3_Pressed();
    void on_plineEdit4_Pressed();
	void on_plineEdit7_Pressed();
    void openEditor();
    void closeEditor();

};

#endif // QIZLEZNISmetkiKOREKCIJA_H
