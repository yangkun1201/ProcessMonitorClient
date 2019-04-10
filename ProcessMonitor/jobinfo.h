#ifndef JOBINFO_H
#define JOBINFO_H

#include <QWidget>
#include <QPoint>

namespace Ui {
class JobInfo;
}

class JobInfo : public QWidget
{
    Q_OBJECT

public:
    explicit JobInfo(QWidget *parent = 0);
    ~JobInfo();
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   QPoint relativePos;
private:
    Ui::JobInfo *ui;
};

#endif // JOBINFO_H
