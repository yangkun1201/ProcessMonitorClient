#ifndef MYCHARTS_H
#define MYCHARTS_H
#include "ui_ProcessMonitor.h"
#include "AppManage.h"
QT_CHARTS_USE_NAMESPACE

class MyCharts
{
public:
    MyCharts();
    void display(Ui::ProcessMonitorClass &ui,const AppManage *appManage);
};

#endif // MYCHARTS_H
