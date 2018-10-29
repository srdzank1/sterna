#ifndef QAnalitikaKomintentiWIDGET_H
#define QAnalitikaKomintentiWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qAnalitikaKomintentiwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QAnalitikaKomintentiWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QAnalitikaKomintentiWidget(QWidget *parent = 0);
	~QAnalitikaKomintentiWidget();
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
	Ui::QAnalitikaKomintentiWidgetClass ui;

    QHeaderView * header;
	QHeaderView * header2;

	QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );

signals:
    void closeW();
    void sAnalitikaKomintentiToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QAnalitikaKomintentiWIDGET_H
