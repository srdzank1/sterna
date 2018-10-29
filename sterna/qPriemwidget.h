#ifndef QPriemWIDGET_H
#define QPriemWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qPriemwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QPriemWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPriemWidget(QWidget *parent = 0);
	~QPriemWidget();
    virtual void pressEscape();
    void lista(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
private:
	Ui::QPriemWidgetClass ui;

    QHeaderView * header;
    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void copyToClipBoard();

signals:
    void closeW();
    void sPriemToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QPriemWIDGET_H
