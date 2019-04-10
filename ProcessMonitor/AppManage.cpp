#include "AppManage.h"
#include "qdebug.h"
AppManage::AppManage(QObject *parent)
	: QThread(parent)
{
	this->appNumber = 0;
}

AppManage::~AppManage()
{
}

void AppManage::addApp(QString appName,QString disName)
{
	AppThread *p = new AppThread(NULL,appName);
	p->setDisplayName(disName);
	p->start();
	AppTasks[this->appNumber++] = p;
}

void AppManage::stopAll()
{
	for (int i = 0;i<this->appNumber;i++)
	{	
		AppTasks[i]->manualCtrl = false;
	}
}

void AppManage::startAll()
{
	for (int i = 0;i<this->appNumber;i++)
	{
		AppTasks[i]->manualCtrl = true;
	}
}

DWORD AppManage::getCurrentPID()
{
	HWND hWnd = GetForegroundWindow();
	LPDWORD lw = new DWORD();
	GetWindowThreadProcessId(hWnd, lw);
	DWORD temp = *lw;
	delete lw;
	return temp;
}

void AppManage::run()
{
	while (1)
	{
		HANDLE             hProcessSnap;
		HANDLE             hProcess;
		PROCESSENTRY32     pe32;
		int pos = 0;
		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE)
		{
			return;
		}
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (!Process32First(hProcessSnap, &pe32))
		{
			CloseHandle(hProcessSnap);
			return;
		}
        DWORD cPid;
        cPid = getCurrentPID();
		RunningApps.clear();
		do
		{
			wchar_t *s;
			s = pe32.szExeFile;
			QString appName = QString::fromWCharArray(s);
			RunningApps[appName] = true;
			for (int i = 0;i<this->appNumber;i++)
			{
                if (AppTasks[i]->name == appName&&AppTasks[i]->isRunning == false&&cPid==pe32.th32ProcessID) //扫描列表中已运行的应用
				{
					AppTasks[i]->isRunning = true;
					AppTasks[i]->appId = pe32.th32ProcessID;
				}
			}

		} while (Process32Next(hProcessSnap, &pe32));
		CloseHandle(hProcessSnap);
		for (int i = 0;i < this->appNumber;i++)
		{
            if (!RunningApps[AppTasks[i]->name]||cPid!=AppTasks[i]->appId)
			{
				AppTasks[i]->isRunning = false;
			}
		}
	}
}
