#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProcessMonitor.h"
#include "AppManage.h"
#include <Windows.h>
#include "LoginDlg.h"
#include <QTcpSocket>
#include <qdesktopservices.h>
#include <qurl.h>
#include <map>
#include <qsystemtrayicon.h>
#include "Question.h"
#include <qmessagebox.h>
#include <qnetwork.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "SetUp.h"
#include "Fw.h"
#include <QWidget>
#include <QtCharts>
#include "MyCharts.h"
#include "jobinfo.h"
QT_CHARTS_USE_NAMESPACE

using namespace std;

class ProcessMonitor : public QMainWindow
{
	Q_OBJECT

public:
	ProcessMonitor(QWidget *parent = Q_NULLPTR);
	void timerEvent(QTimerEvent *event);
	void sendMessage();
	QString get_window_title(HWND hwnd);
	QString get_window_class(HWND hwnd);
	void getDeskTopAppNames();
	void getConfigFile();
    void OnLogin(int ret,QString account,QString password);
    void askQuestion();
	static int step;
	int oldStep;
	int newStep;
	int index;
	int d = 0;
	Fw *fw;
    MyCharts mycharts;
    JobInfo jobInfo;
public slots:
	void OnMonitor();
	void check_account();
	void OnRegist();
	void OnSendToHost();
	void OnOpen();
	void OnExit();
	void OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason);
	void OnTest();
	void replayFinished(QNetworkReply *reply);
	void ShowOnBrowser();
	void OnSetup();
	void OnLogOut();
private:
	Ui::ProcessMonitorClass ui;

	AppManage *appManage;
	QTcpSocket *socket;
	bool login_success;
	QStringList ql;
	map<QString,QString> softs;
	map<QString, QString> softsName;
	QString account;
	QString phone;
	QString verificationCode;
	QSystemTrayIcon  m_systray;
	void closeEvent(QCloseEvent *event);
	QNetworkAccessManager *manager;
	QNetworkReply* reply_verification;
	QNetworkReply* reply_login;
    QNetworkReply* reply_uploadTimeInfo;
};
