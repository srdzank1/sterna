#ifndef QIZLEZNIIspratniciKOREKCIJA_H
#define QIZLEZNIIspratniciKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qizlezniIspratnicikorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"


class QIzlezniIspratniciKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzlezniIspratniciKorekcija(QWidget *parent = 0);
	~QIzlezniIspratniciKorekcija();
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
	void getTableColumnWidths(int ccolumn);
	void setTableColumnWidths(int ccolumn);

private:
	Ui::QIzlezniIspratniciKorekcijaClass ui;
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
	int colWidth[15];

signals:
    void closeW();
    void scallKomintenti(QWidget*, QString);
    void scallArtikli(QWidget*, QString);
	void scallIspratnici(QWidget*, QString);

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
	void procSectionResized(int a, int b, int c);

};

#endif // QIZLEZNIIspratniciKOREKCIJA_H
