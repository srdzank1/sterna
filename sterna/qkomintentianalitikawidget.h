#ifndef QKOMINTENTIANALITIKAWIDGET_H
#define QKOMINTENTIANALITIKAWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qkomintentianalitikawidget.h"
#include <QStandardItemModel>
#include <QHeaderView>

class QKomintentiAnalitikaWidget : public QMyBaseFormWidget
{
    Q_OBJECT

public:
    QKomintentiAnalitikaWidget(QWidget *parent = 0);
    ~QKomintentiAnalitikaWidget();
    virtual void pressEscape();
    void listaKomintenti(const QString& nameSearch);
	void listaArtikli(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
	QStandardItemModel *model2;
	
private:
    Ui::QKomintentiAnalitikaWidget ui;
	enum Izbor {
		ART_IZLFKT = 0,
		ART_VLZFKT,
		ART_ISP,
		ART_PRM,
		ART_SLD,
		KOM_IZLFKT,
		KOM_VLZFKT,
		KOM_ISP,
		KOM_PRM,
		KOM_SLD
	};
	Izbor m_currState;
    QHeaderView * header;
    QHeaderView * header2;
	QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
	void funcART_IZLFKT();
	void funcART_VLZFKT();
	void funcART_ISP();
	void funcART_PRM();
	void funcART_SLD();
	void funcKOM_IZLFKT();
	void funcKOM_VLZFKT();
	void funcKOM_ISP();
	void funcKOM_PRM();
	void funcKOM_SLD();
	void showTable2();
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
	void buttonClicked();
	void button2Clicked();
	void button3Clicked();
	void button4Clicked();
	void button5Clicked();
	void button6Clicked();
	void button7Clicked();

signals:
    void closeW();
    void sLagerToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QKOMINTENTIANALITIKAWIDGET_H
