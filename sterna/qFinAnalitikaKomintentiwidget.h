#ifndef QFinAnalitKomintentiWIDGET_H
#define QFinAnalitKomintentiWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qFinAnalitikaKomintentiwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <vector>
#include <QDateTime>
#include "chelperclass.h"

typedef struct  
{
	int dok_id;
	int dok_tip;
	QDateTime datum;
	float dolzi;
	float pobaruva;
	QString vidDok;
	QString vidDok_Detail;
} tFinData;

class QFinAnalitKomintentiWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QFinAnalitKomintentiWidget(QWidget *parent = 0);
	~QFinAnalitKomintentiWidget();
    virtual void pressEscape();
    void lista(const QString& nameSearch);
	void lista_detail(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
	QStandardItemModel *model2;
	QString getSelectedText(){return m_selectedTextName;}


	
private:
	Ui::QFinAnalitKomintentiWidgetClass ui;

    QHeaderView * header;
	QHeaderView * header2;

	QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;

	std::vector<tFinData> listFinData;
	CHelperClass m_priemnici_helper;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );

signals:
    void closeW();
    void sFinAnalitKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QFinAnalitKomintentiWIDGET_H
