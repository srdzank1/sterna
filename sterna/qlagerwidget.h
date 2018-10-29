#ifndef QLAGERWIDGET_H
#define QLAGERWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qlagerwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QLagerWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QLagerWidget(QWidget *parent = 0);
	~QLagerWidget();
    virtual void pressEscape();
    void lista(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
	void refresh();
private:
	Ui::QLagerWidgetClass ui;

    QHeaderView * header;
    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
	QString m_selectedKomintentId;
	QString m_selectedProdCena;
	QString m_selectedNabCena;

private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void copyToClipBoard();

signals:
    void closeW();
    void sLagerToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId, QString& textProdCena, QString& textNabCena);	
};

#endif // QLAGERWIDGET_H
