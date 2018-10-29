#ifndef QKalkulacijaKOREKCIJA_H
#define QKalkulacijaKOREKCIJA_H

#include "qmybaseformwidget.h"
#include "ui_qKalkulacijakorekcija.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"
#include "qkalkulacijalagerlista.h"

class QKalkulacijaKorekcija : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKalkulacijaKorekcija(QWidget *parent = 0);
	~QKalkulacijaKorekcija();
	virtual void pressEscape();
	virtual void pressReturn();
	virtual void pressF9();

	void setFocusLine();
	void setKomintent(QString text, QString textName);
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void init(int id);
	void setPriemnicaID(QString text, QString textName);
	void setTableColumnWidths(int ccolumn);
	void getTableColumnWidths(int ccolumn);



private:
	bool eventFilter(QObject *object, QEvent *event);

	Ui::QKalkulacijaKorekcijaClass ui;
	QStandardItemModel *model;
	QHeaderView *header;
	int selRow;
	QString textId;
	int m_id;
	int komintent_id;
	int artikal_id;
    QString komintentID;
	QString prevoznikID;
    QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	bool validateKomintent();
	float m_sumaIznosStavki;
	float m_sumaTrosoci;
	bool isKomintent;

	float mm_prodCenaSoDDV;
	float mm_marzaProcent;
	int colWidth[17];
signals:
	void closeW();
	void scallKomintenti(QWidget*, QString);
	void scallArtikli(QWidget*, QString);
	void scallPriemnici(QWidget*, QString);
    void editCell();
    void closeCell();

	private slots:
		void on_pushButton_4_clicked();
		void on_pushButton_5_clicked();
		void on_pushButton_6_clicked();
		void on_pushButton_3_clicked();
		void on_pushButton_2_clicked();
		void on_pushButton_clicked1();
		void on_pushButton1_prevoznik();
		void selectionChanged(QModelIndex,QModelIndex);
        void on_plineEdit3_Pressed();
        void on_plineEdit4_Pressed();
		void on_plineEdit5_Pressed();
		void on_plineEdit14_Pressed();
		void on_plineEdit15_Pressed();
		void on_plineEdit17_Pressed();
		void on_plineEdit23_Pressed();
		void on_plineEdit23_TextChanged(const QString &);
		void on_plineEdit18_Pressed();
		void on_plineEdit19_Pressed();
		void on_plineEdit21_Pressed();
		void on_plineEdit21_TextChanged(const QString &);
		void on_plineEdit24_Pressed();
		void on_plineEdit16_Pressed();
		void on_comboBox2_Pressed();
		void on_datetime2_Pressed();
		void on_datetime4_Pressed();

		void openEditor();
        void closeEditor();
		void callImportPriemnici();
		void comboBoxChanged(const QString & str);
		void updateModelData();
		void calculateNabCenaSoDDVIznos();
		void procSectionResized(int a, int b, int c);
};

#endif // QKalkulacijaKOREKCIJA_H
