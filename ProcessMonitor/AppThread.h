#pragma once
#include <QThread>
#include <Windows.h>
class AppThread : public QThread
{
	Q_OBJECT

public:
	AppThread(QObject *parent,QString appName);
	~AppThread();
	QString name;
	QString displayName;
	bool isRunning;
	bool manualCtrl;
	int liveTime;
	DWORD appId;
	void setDisplayName(QString disName);
private:
	
	void run();
};
