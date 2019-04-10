#include "AppThread.h"

AppThread::AppThread(QObject *parent,QString appName)
	: QThread(parent)
{
	this->name = appName;
	this->isRunning = false;
	this->liveTime = 0;
	this->manualCtrl = true;
	this->appId = NULL;
}

AppThread::~AppThread()
{
}

void AppThread::run()
{
	while (1)
	{
		msleep(1000);
		if (this->isRunning&&this->manualCtrl)
		{
			this->liveTime++;
		}
	}
}

void AppThread::setDisplayName(QString disName)
{
	this->displayName = disName;
}