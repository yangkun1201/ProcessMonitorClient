#include "jobinfo.h"
#include "ui_jobinfo.h"
#include <QMouseEvent>
#include <QBitmap>
#include <QPainter>
JobInfo::JobInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JobInfo)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::Tool);
    this->setGeometry(QRect(1070,400,300,300));
    this->setWindowTitle("蜗牛君提醒您 有工作喽");
    this->setWindowIcon(QIcon(":/ProcessMonitor/Resources/monitor.png"));
}

JobInfo::~JobInfo()
{
    delete ui;
}

void JobInfo::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        relativePos = this->pos() - event->globalPos();
    }
}

void JobInfo::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() + relativePos);
}
