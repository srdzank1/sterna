#ifndef QAnalitikaArtikliWIDGET_H
#define QAnalitikaArtikliWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qAnalitikaArtikliwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QAnalitikaArtikliWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QAnalitikaArtikliWidget(QWidget *parent = 0);
	~QAnalitikaArtikliWidget();
    virtual void pressEscape();
    void lista(const QString& nameSearch);
    void lista_detail(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
    QStandardItemModel *model2;
    QString getSelectedText(){return m_selectedTextName;}
    QString getSelectedText2(){return m_selectedTextName2;}

private:
	Ui::QAnalitikaArtikliWidgetClass ui;

    QHeaderView * header;
    QHeaderView * header2;

    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextName2;
    QString m_selectedTextNameSaldo;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );

signals:
    void closeW();
    void sAnalitikaArtikliToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QAnalitikaArtikliWIDGET_H
