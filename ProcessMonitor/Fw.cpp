#include "Fw.h"
#include "util.h"

Fw::Fw(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setWindowFlags(Qt::Tool);
    this->setWindowOpacity(0.9);
	this->setGeometry(QRect(1000,60,120,60));
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::black);
    p.setBrush(Qt::black);
    p.setBackground(QColor(255, 160, 90));
    p.drawRoundedRect(bmp.rect(), 20, 20);
    setMask(bmp);

}

Fw::~Fw()
{
}

void Fw::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		relativePos = this->pos() - event->globalPos();
	}
}

void Fw::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() + relativePos);
}

void Fw::setInformation(QString name, QString time)
{
	this->name = name;
	this->time = time;
	ui.label_name->setText(name);
	ui.label_time->setText(time);
}
