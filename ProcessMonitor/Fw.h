#pragma once

#include <QWidget>
#include "ui_Fw.h"
#include <QMouseEvent>
#include <QPoint>
#include <qbitmap.h>
#include <qpainter.h>
class Fw : public QWidget
{
	Q_OBJECT

public:
	Fw(QWidget *parent = Q_NULLPTR);
	~Fw();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QPoint relativePos;
	void setInformation(QString name,QString time);
private:
	Ui::Fw ui;
	QString name;
	QString time;
};
