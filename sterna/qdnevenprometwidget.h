#ifndef QDnevenprometWIDGET_H
#define QDnevenprometWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qDnevenprometwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>

class QDnevenprometWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QDnevenprometWidget(QWidget *parent = 0);
	~QDnevenprometWidget();
    virtual void pressEscape();
	virtual void pressF9();

	void lista(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
	virtual void refresh();
	QString getDateAsString();

private:
	Ui::QDnevenprometWidgetClass ui;

    QHeaderView * header;
    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
	void funcEditingFinished();

signals:
    void closeW();
    void sDnevenprometToDokument(QString& text, QString& textName, QString& textNameSaldo);	
};

#endif // QDnevenprometWIDGET_H
