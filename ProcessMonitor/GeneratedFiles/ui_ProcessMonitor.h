/********************************************************************************
** Form generated from reading UI file 'ProcessMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSMONITOR_H
#define UI_PROCESSMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_ProcessMonitorClass
{
public:
    QAction *action_open;
    QAction *action_exit;
    QAction *test_btn;
    QAction *monitor;
    QAction *regist_btn;
    QAction *login_btn;
    QAction *showOnBrowser;
    QAction *sendToHost_btn;
    QAction *test_btn_2;
    QAction *action_setup;
    QAction *logout_btn;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QtCharts::QChartView *widget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *ProcessMonitorClass)
    {
        if (ProcessMonitorClass->objectName().isEmpty())
            ProcessMonitorClass->setObjectName(QStringLiteral("ProcessMonitorClass"));
        ProcessMonitorClass->resize(597, 381);
        action_open = new QAction(ProcessMonitorClass);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_exit = new QAction(ProcessMonitorClass);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        test_btn = new QAction(ProcessMonitorClass);
        test_btn->setObjectName(QStringLiteral("test_btn"));
        monitor = new QAction(ProcessMonitorClass);
        monitor->setObjectName(QStringLiteral("monitor"));
        regist_btn = new QAction(ProcessMonitorClass);
        regist_btn->setObjectName(QStringLiteral("regist_btn"));
        login_btn = new QAction(ProcessMonitorClass);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        showOnBrowser = new QAction(ProcessMonitorClass);
        showOnBrowser->setObjectName(QStringLiteral("showOnBrowser"));
        sendToHost_btn = new QAction(ProcessMonitorClass);
        sendToHost_btn->setObjectName(QStringLiteral("sendToHost_btn"));
        test_btn_2 = new QAction(ProcessMonitorClass);
        test_btn_2->setObjectName(QStringLiteral("test_btn_2"));
        action_setup = new QAction(ProcessMonitorClass);
        action_setup->setObjectName(QStringLiteral("action_setup"));
        logout_btn = new QAction(ProcessMonitorClass);
        logout_btn->setObjectName(QStringLiteral("logout_btn"));
        centralWidget = new QWidget(ProcessMonitorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QtCharts::QChartView(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);

        ProcessMonitorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProcessMonitorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProcessMonitorClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(ProcessMonitorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        ProcessMonitorClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(showOnBrowser);
        menu->addSeparator();
        menu->addAction(sendToHost_btn);
        menu->addSeparator();
        menu->addAction(logout_btn);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_2->addAction(test_btn);
        menu_2->addSeparator();

        retranslateUi(ProcessMonitorClass);

        QMetaObject::connectSlotsByName(ProcessMonitorClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProcessMonitorClass)
    {
        ProcessMonitorClass->setWindowTitle(QApplication::translate("ProcessMonitorClass", "ProcessMonitor", nullptr));
        action_open->setText(QApplication::translate("ProcessMonitorClass", "\346\211\223\345\274\200", nullptr));
        action_exit->setText(QApplication::translate("ProcessMonitorClass", "\351\200\200\345\207\272", nullptr));
        test_btn->setText(QApplication::translate("ProcessMonitorClass", "\345\210\267\346\226\260", nullptr));
        monitor->setText(QApplication::translate("ProcessMonitorClass", "\347\233\221\346\216\247", nullptr));
        regist_btn->setText(QApplication::translate("ProcessMonitorClass", "\346\263\250\345\206\214", nullptr));
        login_btn->setText(QApplication::translate("ProcessMonitorClass", "\347\231\273\345\275\225", nullptr));
        showOnBrowser->setText(QApplication::translate("ProcessMonitorClass", "\346\237\245\347\234\213\347\224\250\346\227\266", nullptr));
        sendToHost_btn->setText(QApplication::translate("ProcessMonitorClass", "\345\217\221\351\200\201\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
        test_btn_2->setText(QApplication::translate("ProcessMonitorClass", "\346\265\213\350\257\225", nullptr));
        action_setup->setText(QApplication::translate("ProcessMonitorClass", "\344\277\256\346\224\271\347\233\221\346\216\247\350\275\257\344\273\266", nullptr));
        logout_btn->setText(QApplication::translate("ProcessMonitorClass", "\346\263\250\351\224\200", nullptr));
        menu->setTitle(QApplication::translate("ProcessMonitorClass", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QApplication::translate("ProcessMonitorClass", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessMonitorClass: public Ui_ProcessMonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSMONITOR_H
