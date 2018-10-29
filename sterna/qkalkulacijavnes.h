#ifndef QKalkulacijaVNES_H
#define QKalkulacijaVNES_H

#include "qmybaseformwidget.h"
#include "ui_qKalkulacijavnes.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "qstablewidgetdelegate.h"
#include "qkalkulacijalagerlista.h"

class QKalkulacijaVnes : public QMyBaseFormWidget
{
	Q_OBJECT

public:
	QKalkulacijaVnes(QWidget *parent = 0);
	~QKalkulacijaVnes();
	virtual void pressEscape();
	void setKomintent(QString text, QString textName);
	void setFocusLine();
	void setArtikli(QString text, QString textName);
	void setFocusLine2();
	void pressReturn();
	void pressF9();
	void setPriemnicaID(QString text, QString textName);
	void getTableColumnWidths(int ccolumn);
	void setTableColumnWidths(int ccolumn);



private:
	bool eventFilter(QObject *object, QEvent *event);
    bool existDok(int idDok);
    Ui::QKalkulacijaVnesClass ui;
	QStandardItemModel *model;
	QHeaderView *header; 
    int selRow;
	int m_i;
    QString textId;
    QString komintentID;
	QString prevoznikID;
    int artikal_id;
    QString dokumentID;
    QSTableWidgetDelegate *pItemDelegate;
    QModelIndex indexPrev;
    bool editorOpen;
    void currentChanged ( const QModelIndex & current, const QModelIndex & previous );
	void lineEditPressReturn();
	bool validateKomintent();
	bool validateПревозник();
	float m_sumaIznosStavki;
	float m_sumaTrosoci;
	bool isKomintent;
	void calculateNabCenaSoDDVIznos();

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
		void on_pushButton1_clicked();
		void on_pushButton1_prevoznik();
		void selectionChanged(QModelIndex,QModelIndex);
        void on_plineEdit3_Pressed();
        void on_plineEdit4_Pressed();
        void on_plineEdit15_Pressed();
		void on_plineEdit17_Pressed();
		void on_plineEdit23_Pressed();
		void on_plineEdit23_TextChanged(const QString &);
		void on_plineEdit18_Pressed();
		void on_plineEdit19_Pressed();
		void on_plineEdit21_Pressed();
		void on_plineEdit21_TextChanged(const QString &);
		void on_plineEdit24_Pressed();
		void openEditor();
        void closeEditor();
		void callImportPriemnici();
		void updateModelData();
		void comboBoxChanged(const QString &);
		void on_pushButton14_clicked();
		void on_comboBox2_clicked();
		void on_dateTimeEdit2_clicked();
		void on_dateTimeEdit4_clicked();
		void on_lineEdit5_clicked();
		void on_lineEdit16_clicked();
		void procSectionResized(int a, int b, int c);
};

#endif // QKalkulacijaVNES_H
