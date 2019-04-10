#pragma once

#include <QThread>
#include <vector>
#include <map>
#include <windows.h>
#include <tlhelp32.h>
#include "AppThread.h"
using namespace std;

class AppManage : public QThread
{
	Q_OBJECT

public:
	AppManage(QObject *parent);
	~AppManage();
	AppThread* AppTasks[50];
	void addApp(QString appName, QString disName);
	int appNumber;
	void stopAll();
	void startAll();
private:
	map<QString, bool> RunningApps;
	void run();
	DWORD getCurrentPID();
};
 