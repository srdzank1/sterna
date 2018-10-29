#ifndef QPeriodicenIzvestajWIDGET_H
#define QPeriodicenIzvestajWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qPeriodicenIzvestajwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QPeriodicenIzvestajWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPeriodicenIzvestajWidget(QWidget *parent = 0);
	~QPeriodicenIzvestajWidget();
    virtual void pressEscape();
	void lista(const QString& nameSearch, QDate &date1, QDate &date2 );
	QString getDateRange();
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
private:
	Ui::QPeriodicenIzvestajWidgetClass ui;

    QHeaderView * header;
    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void copyToClipBoard();
	void dateChanged();

signals:
    void closeW();
    void sPeriodicenIzvestajToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QPeriodicenIzvestajWIDGET_H
