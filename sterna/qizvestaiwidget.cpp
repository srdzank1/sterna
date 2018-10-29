#include "qizvestaiwidget.h"
#include <QPainter>
#include <QDesktopWidget>
#include <QMouseevent>
#include "chelperclass.h"
#include <QSqlQuery>
#include <QDate>
#include <QScrollArea>
#include <QPaintDevice>




QIzvestaiWidget::QIzvestaiWidget(QWidget *parent)
	: QMyBaseFormWidget(parent)
	,ww(20)
	,imag(0)
{
	ui.setupUi(this);
    setGeometry(0, 0, qApp->desktop()->geometry().width() - 210 , qApp->desktop()->geometry().height() - 155);
	setGeometry(0, 0, 367 * ww , 1600);
	setMouseTracking(true);
	imag = new QImage(367 * ww , 1600, QImage::Format_ARGB32);
	QPainter p(imag);
	createTimeLine(p, ww);
	createSample(p);
	createRedLine(p,  ww);
}

QIzvestaiWidget::~QIzvestaiWidget()
{

}

void QIzvestaiWidget::pressEscape()
{
    emit closeW();
}

void QIzvestaiWidget::paintEvent(QPaintEvent *event)
{
	QPainter pMain;
	pMain.begin(this);
	pMain.drawImage(QPoint(0, 0), *imag);
	pMain.end();
}

void QIzvestaiWidget::mouseMoveEvent(QMouseEvent * event)
{
	QPoint p = event->pos();
	for (QVector<tdok_infoSRG>::iterator it = listItemsSrg.begin(); it != listItemsSrg.end(); it++ )
	{
		if ((*it).rectInfo.contains(p))
		{
			QString naziv = (*it).item.komintent_naziv;
			QString faktData = (*it).item.fakturaData.toString();
			QString Valuta = (*it).item.fakturaValuta.toString();

			float iznos = (*it).item.iznos;
			float plateno = (*it).item.plateno;
			float ostanato  = iznos - plateno;


			QString textString =  
				"<h3 style=\"margin-left: 20px\" style=\"margin-right: 20px\" >"
				+ naziv +
				"</h3>"
				"<p style=\"margin-left: 20px\" style=\"margin-right: 20px\">"
				+ trUtf8("Датум: ") + faktData +
				"</p>"
				"<p style=\"margin-left: 20px\" style=\"margin-right: 20px\">"
				+ trUtf8("Валута: ") + Valuta +
				"</p>"
				"<p style=\"margin-left: 20px\" style=\"margin-right: 20px\">"
				+ trUtf8("Вк.Износ: ") + QString::number( iznos, 'f', 2 ) +
				"</p>"
				"<p style=\"margin-left: 20px\" style=\"margin-right: 20px\">"
				+ trUtf8("Платено: ") + QString::number( plateno, 'f', 2 ) +
				"</p>"
				"<h3 style=\"margin-left: 20px\" style=\"margin-right: 20px\">"
				+ trUtf8("Останато: ") + QString::number( ostanato, 'f', 2 ) +
				"</h3>";

			
			setToolTip(textString);
			int stop = 0;
			//repaint();
		}
		else
		{
		}
		
	}
}


void QIzvestaiWidget::createLagerList()
{
	listBound.clear();
	QLocale loc;
	int r = 0;
	int c = 6;
	int fieldNo[6];
	QString country[6];
	int colWidth[] = {50, 250, 80, 100, 100, 100};
	QString colName[6] = {"id", "artikal", "edm", "sum(vkol)", "sum(ikol)", "sum(vkol)-sum(ikol)"};

	QString temp = 
		"select distinct artikal_id ,artikli.artikal, artikli.edm "
		"from magacin "
		"left join artikli on  magacin.artikal_id = artikli.id "
		"where artikli.artikal like '%' order by artikal_id limit 50";
	QSqlQuery query(temp);

	int row = 0;
	CHelperClass chc(this);
	float vkVlezKol = 0.f;
	float vkIzlezKol = 0.f;
	float vkSaldo = 0.f;
	QString textString = "";
	while (query.next()) 
	{
		for (int i = 0; i < c; i++)
		{
			QString temp = query.value(i).toString();

			if (i == 1)
			{
				textString = temp;
			}
			if (i == 3)
			{
				QString tip = "20";
				QString tip1 = "21";
				vkVlezKol = chc.getVkKolBetween(query.value(0).toString(), tip , tip1);
			}
			else if (i == 4)
			{
				QString tip = "40";
				vkIzlezKol = chc.getVkKol(query.value(0).toString(), tip);
				temp =  loc.toString(vkIzlezKol ,'f', 2);
			}
			else if (i == 5)
			{
				vkSaldo = vkVlezKol - vkIzlezKol;
				temp =  loc.toString(vkSaldo ,'f',2);
			}
			else
			{
			}
		}
		float ss = 0.f;
		if ((vkSaldo > 0.f) && (vkVlezKol != 0.f))
		{
			ss = (vkSaldo / vkVlezKol);
		}

		bound b = new tbound;
		b->r = QRect(190, 50 + row * 20, 380, 15);
		b->rt = QRect(10, 50 + row * 20, 170, 15);
		b->c = QColor(Qt::red);
		b->t = textString + " [" + QString::number((int)(ss * 100), 10) + " %]";
		b->tt = textString + 
		"<p style=\"margin-left: 20px\">"
		+ trUtf8("Влезна количина: ") + QString::number( vkVlezKol ) +
		"</p>"
		"<p style=\"margin-left: 20px\">"
		+ trUtf8("Излезна количина: ") + QString::number( vkIzlezKol ) +
		"</p>"
		"<p style=\"margin-left: 20px\">"
		+ trUtf8("Салдо: ") + QString::number( vkSaldo ) +
		"</p>";

		b->selected = false;

		listBound.push_back(b);

		bound b1 = new tbound;
		b1->r = QRect(190, 50 + row * 20, ss * 380 , 15);
		b1->c = QColor(Qt::green);
		listBound.push_back(b1);
		b1->tt = textString + " " + QString::number(int(ss * 100) , 10) + " % ";
		b->selected = false;
		if (row == 50)
		{
			break;
		}
		row++;

	} 
}

void QIzvestaiWidget::createRedLine(QPainter &painter, int ww)
{
	QDate d0, d;
	d0.setDate(2016, 1, 1);
	d = d.currentDate();
	painter.fillRect(QRect(ww * (d0.daysTo(d)+1) -1 , 10, 2, 1600),Qt::yellow );
}

void QIzvestaiWidget::createTimeLine(QPainter &painter, int ww)
{
	painter.drawRect(QRect(10, 10, 367 * ww, 1600));
	painter.fillRect(QRect(10, 23, 367 * ww, 13), Qt::transparent);

	QDate d1( 2016, 1, 1 );
	int dayOffset = 5;
	QPen b;
	for (int i = dayOffset; i < 368; i++)
	{
		if ((!(i % 7))||(!((i + 1) % 7)))
		{
			painter.fillRect(QRect(10 + ww * (i - dayOffset), 10, ww, 1600), Qt::lightGray);
		}
		QString textDay = "";
		int god;
		int mes;
		int den;

		switch (i % 7)
		{
		case 0: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 10), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("Н");
			b.setColor(Qt::red);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 1: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 10), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("П");
			b.setColor(Qt::darkGreen);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);

			painter.setPen(b);
			d1.getDate(&god, &mes, &den);
			b.setColor(Qt::darkBlue);
			painter.setPen(b);
			painter.drawText(QRect(13 + ww * (i - dayOffset), 10, 120, 30), QString::number(den) + "." + QDate::shortMonthName(mes) + "." + QString::number(god));
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 2: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 23), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("В");
			b.setColor(Qt::darkGreen);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 3: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 23), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("С");
			b.setColor(Qt::darkGreen);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 4: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 23), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("Ч");
			b.setColor(Qt::darkGreen);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 5: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 23), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("П");
			b.setColor(Qt::darkGreen);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		case 6: 
			painter.drawLine(QPoint(10 + ww * (i - dayOffset), 10), QPoint(10 + ww * (i - dayOffset), 1600));
			textDay = trUtf8("С");
			b.setColor(Qt::red);
			painter.setPen(b);
			painter.drawText(QRect(20 + ww * (i - dayOffset), 23, 40, 30), textDay);
			b.setColor(Qt::black);
			painter.setPen(b);

			break;
		}

		d1 = d1.addDays(1);
	}
	painter.drawLine(QPoint(10, 23), QPoint(367 * ww, 23));
	painter.drawLine(QPoint(10, 36), QPoint(367 * ww, 36));
	
//	QRect r(10, 10, 300, 20);
	//painter.drawText(r, Qt::AlignRight, trUtf8("Лагер Листа"));
}




void QIzvestaiWidget::createSample(QPainter &painter)
{
	
	Singleton *s = Singleton::Instance();
	Singleton::tListInfoFakturi itemListA = s->m_listFakturiS;
	Singleton::tinfoFakturi itemA;
	QDateTime d1 = QDateTime::fromString("01/01/2016", "dd/MM/yyyy");
	// dateTime is 1 January 1998 00:01:02
	for (int i = 0; i < itemListA.size(); i++)
	{
		itemA = itemListA.at(i);
		int dayCount = d1.daysTo(itemA.fakturaData);
		int dayCountValuta = d1.daysTo(itemA.fakturaValuta);
		QString komintentNaziv = itemA.komintent_naziv;
		int x = 20 * (dayCount + 1);
		int x2 = 20 * (dayCountValuta - dayCount);
		int y = 50 + (i % 25) * 20;
		QRect rItem = QRect(x, y, x2, 10);
	    tdok_infoSRG itemSrg7;
		itemSrg7.item = itemA;
		itemSrg7.rectInfo = rItem;
		listItemsSrg.push_back(itemSrg7);
	
		if ((itemA.iznos -itemA.plateno) == itemA.iznos)
		{
			painter.fillRect(QRect(x, y, x2, 15),Qt::red );
		}
		else if ((itemA.iznos -itemA.plateno) > 0.1f)
		{
			painter.fillRect(QRect(x, y, x2, 15),Qt::yellow );
		}
		else if ((itemA.iznos -itemA.plateno) < 0.1f)
		{
			painter.fillRect(QRect(x, y, x2, 15),Qt::green );
		}
		else if ((itemA.iznos -itemA.plateno) < 0.f)
		{
			painter.fillRect(QRect(x, y, x2, 15),Qt::white );
		}


		painter.drawRect(QRect(x, y, x2, 15) );
		painter.drawText(QRect(x + 5, y, x2, 15), komintentNaziv);
	}
}