#ifndef QIZLEZNIprofakturimasterKOREKCIJA_H
#define QIZLEZNIprofakturimasterKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qprofakturimasterkorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QIzlezniprofakturimasterKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzlezniprofakturimasterKorekcija(QWidget *parent = 0);
	~QIzlezniprofakturimasterKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
	virtual void pressF9();

    void setFocusLine();
    void setKomintent(QString text, QString textName);
    void setArtikli(QString text, QString textName, QString textKomintentId);
    void setSaldo(QString text);
	void setProdCena(QString text);
	void setNabCena(QString text);
    void setFocusLine2();
    void init(int id);

private:
	Ui::QIzlezniprofakturimasterKorekcijaClass ui;
    bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    QStandardItemModel *model;
    QHeaderView *header; 
    int selRow;
	int m_user_id;
    QString textId;
    int m_id;
    int komintent_id;
	QString m_staraCena;
	QString m_staraNabCena;
    int artikal_id;
	QString artikal_komintent_id;
    QString komintentID;
    QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	bool validateKomintent();
	void calculateIznosi();

signals:
    void closeW();
    void scallKomintenti(QWidget*, QString);
    void scallArtikli(QWidget*, QString);
	void scallprofakturimaster(QWidget*, QString);

    void editCell();
    void closeCell();
private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
	void on_pushButtonA_clicked();
    void selectionChanged(QModelIndex,QModelIndex);
    void on_plineEdit3_Pressed();
    void on_plineEdit4_Pressed();
	void on_plineEdit7_Pressed();
	void on_plineEdit8_Pressed();
    void openEditor();
    void closeEditor();

};

#endif // QIZLEZNIprofakturimasterKOREKCIJA_H
