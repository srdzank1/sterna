#ifndef QIzvodKorekcija_H
#define QIzvodKorekcija_H

#include "qmybaseformwidget.h"
#include "ui_qIzvodKorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"
#include <map>
#include <vector>
#include "xx.h"



class QIzvodKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QIzvodKorekcija(QWidget *parent = 0);
	~QIzvodKorekcija();
	virtual void pressEscape();
	void setZiroSmetka(QString text, QString textName);
	void setFocusLine();
	void setFakturi(QStringList& listData);
	void setFocusLine2();
	void pressReturn();
	void pressF9();
	void setKomintent(QString text, QString textName);
	void init(QStringList info);
	void updatePlakanje();
private:
	typedef struct 
	{
		QString komintent_id;
		QString komintent_naziv;
		QString faktura_tip;
		QString faktura_id;
		QString datum;
		QString neplaten_iznos;
		QString plateno;
	} sostavInfo;

	typedef std::vector<sostavInfo> typeSostavVector;
	bool eventFilter(QObject *object, QEvent *event);
	bool existDok(int idDok);
	Ui::QIzvodKorekcijaClass ui;
	QStandardItemModel *model;
	QHeaderView *header; 
	QStandardItemModel *model2;
	QHeaderView *header2; 
	QString m_prilivItem;
	QString m_odlivItem;
	int selRow;
    QString textId;
    QString mAId;
	QString komintentID;
    int artikal_id;
	int m_user_id;
	QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	void lineEditPressReturn();
    void setEnabledFields(bool stat);
	QString m_komintent_id;
	QString m_komintent_name;
	QString m_randomId;

	void insertRowTable2(std::vector<sostavInfo> &rowData);
	void insertRowTable2Map(QStringList& rowData);

    QString m_ZiroSmetka;
	std::map<QString , std::vector<sostavInfo>> m_map;

signals:
	void closeW();
	void signBankiFromIzvod(QWidget*, QString);
	void scallKomintenti(QWidget*, QString);
	void signFakturiFromIzvod(QWidget*, QString, int);
	void editCell();
    void closeCell();

	private slots:
		void on_pushButton_4_clicked();
		void on_pushButton_5_clicked();
		void on_pushButton_6_clicked();
		void on_pushButton_3_clicked();
		void on_pushButton_2_clicked();
		void on_pushButton_clicked();
		void selectionChanged(QModelIndex,QModelIndex);
        void on_plineEdit7_Pressed();
        void on_plineEdit6_Pressed();
        void openEditor();
        void closeEditor();
        void on_pRadioButton_Pressed();
        void on_pRadioButton2_Pressed();
        void on_pRadioButton8_Pressed();
        void on_pDateTime_Pressed( QMouseEvent *);
		void callProcBanki();
		void callProcKomintenti();
		void callProcLineEdit3();
		void callProcLineEdit4();
};

#endif // QIzvodKorekcija_H
