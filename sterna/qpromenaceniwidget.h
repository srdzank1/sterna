#ifndef QPromenaCeniWIDGET_H
#define QPromenaCeniWIDGET_H

#include "qmybaseformwidget.h"
#include "ui_qPromenaCeniwidget.h"
#include <QStandardItemModel>
#include <QHeaderView>


class QPromenaCeniWidget : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QPromenaCeniWidget(QWidget *parent = 0);
	~QPromenaCeniWidget();
    virtual void pressEscape();
    void lista(const QString& nameSearch);
    void setInitText(QString text);
    virtual void pressReturn();
    void setFocusSearchField();
	QStandardItemModel *model;
private:
	Ui::QPromenaCeniWidgetClass ui;

    QHeaderView * header;
    QString m_selectedText;
    QString m_selectedTextName;
    QString m_selectedTextNameSaldo;
	QString m_selectedKomintentId;
	QString m_selectedProdCena;
private slots:
    void on_tableView_clicked(const QModelIndex &);
    void on_lineEdit_textChanged(const QString &);
    void selectionChanged(QModelIndex modelX, QModelIndex modelY );
    void copyToClipBoard();

signals:
    void closeW();
    void sPromenaCeniToDokument(QString& text, QString& textName, QString& textNameSaldo, QString& textKomintentId, QString& textProdCena);	
};

#endif // QPromenaCeniWIDGET_H
