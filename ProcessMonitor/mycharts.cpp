#include "mycharts.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

MyCharts::MyCharts()
{

}
void MyCharts::display(Ui::ProcessMonitorClass &ui,const AppManage *appManage)
{

    QBarSet *set0 = new QBarSet("监控软件");
    QStringList categories;
    for(int i=0;i<appManage->appNumber;i++)
    {
        *set0 << appManage->AppTasks[i]->liveTime;
        categories << appManage->AppTasks[i]->displayName;
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("软件当前用时");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui.widget->setChart(chart);
    ui.widget->setRenderHint(QPainter::Antialiasing);
}
