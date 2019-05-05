#include "ProcessMonitor.h"
#include <stdio.h>
#include "QTableWidgetItem"
#include <qdebug.h>
#include <qevent.h>
#include <qjsonobject.h>
#include <qnetwork.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include "WindowCapture.h"
#include <qscreen.h>
#include <QPixmap>
#include <QDIR>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "util.h"

QT_CHARTS_USE_NAMESPACE

ProcessMonitor::ProcessMonitor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket();
	manager = new QNetworkAccessManager(this);
	connect(ui.monitor,SIGNAL(triggered()),this,SLOT(OnMonitor()));
	connect(socket,SIGNAL(readyRead()), this,SLOT(check_account()));
	connect(ui.regist_btn,SIGNAL(triggered()),this,SLOT(OnRegist()));
	connect(ui.sendToHost_btn,SIGNAL(triggered()),this,SLOT(OnSendToHost()));
	connect(ui.action_exit,SIGNAL(triggered()),this,SLOT(OnExit()));
	connect(ui.action_open,SIGNAL(triggered()),this,SLOT(OnOpen()));
	connect(&m_systray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
	SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));
	connect(ui.test_btn,SIGNAL(triggered()),this,SLOT(OnTest()));
	connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replayFinished(QNetworkReply*)));
	connect(ui.showOnBrowser,SIGNAL(triggered()),this,SLOT(ShowOnBrowser()));
	connect(ui.action_setup,SIGNAL(triggered()),this,SLOT(OnSetup()));
	connect(ui.logout_btn, SIGNAL(triggered()), this, SLOT(OnLogOut()));
	appManage = new AppManage(NULL);

    mycharts.display(ui,appManage);

	m_systray.setToolTip("Process Monitor");
    m_systray.setIcon(QIcon(":/ProcessMonitor/Resources/monitor.png"));

	QMenu* menu = new QMenu();
	menu->addAction(ui.action_open);
	menu->addSeparator();
	menu->addAction(ui.action_exit);

	m_systray.setContextMenu(menu);
	m_systray.show();

    timerId = startTimer(100);
	appManage->start();

	login_success = false;
	account = "";
	phone = "";
	verificationCode="";

	oldStep = -1;
	newStep = 0;
	index = 0;
	fw = new Fw();
	fw->show();

    this->setWindowTitle("IT snail");
    //jobInfo.show();

    baseIp = Util::getInstance()->getBaseIp();
}

int ProcessMonitor::step= 500;

void ProcessMonitor::OnLogin(int ret,QString account,QString password)
{

	if (ret == QDialog::Accepted)
	{
		//qDebug()<<dlg.account<<" "<<dlg.password;
        this->account = account;

		//构建Json对象
		QJsonObject obj;
        //obj.insert("source","client");
        obj.insert("account",account);
        obj.insert("password",password);
		qDebug()<<obj;
		//连接Http
		
		QJsonDocument document;
		document.setObject(obj);
		QByteArray dataArray = document.toJson(QJsonDocument::Compact);
        QUrl url(baseIp+"/login");
		QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
        request.setRawHeader("Authorization", "Bearer 49152bfddae0c5b5d492d3d9871f8c11");
        reply_login = manager->post(request, dataArray);
        qDebug()<<"send over";
	}
	else {

	}

}

void ProcessMonitor::replayFinished(QNetworkReply *reply)
{

	if (reply==reply_login)
	{
        /*
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
            if(statusCode.isValid())
                qDebug() << "status code=" << statusCode.toInt();

            QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
            if(reason.isValid())
                qDebug() << "reason=" << reason.toString();

            QNetworkReply::NetworkError err = reply->error();
            if(err != QNetworkReply::NoError) {
                qDebug() << "Failed: " << reply->errorString();
            }
            else {
                // 获取返回内容
                qDebug() << reply->readAll();
            }

        */

		QByteArray result = reply->readAll();
        qDebug() << result;
		QJsonParseError jsonError;
		QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
		QJsonObject obj = document.object();
		int resultCode = -1;
		QString username = "";
		if (obj.contains("code"))
		{
			QJsonValue value = obj.value("code");
			resultCode = value.toInt();
            //qDebug()<<value.toInt();
		}
		if (obj.contains("username"))
		{
			QJsonValue value = obj.value("usename");
			username = value.toString();
           //qDebug() << value.toString();
		}
		if (obj.contains("softs"))
		{
			QJsonValue value = obj.value("softs");
			ql = value.toString().split(",");
            //qDebug()<< "ql"<< ql;
		}

		if (obj.contains("phone"))
		{
			QJsonValue value = obj.value("phone");
			phone = value.toString();
            //qDebug() << value.toString();
		}

		if (resultCode == 0)
		{
			MessageBox(NULL, L"登录成功", L"", MB_OKCANCEL);
			//ui.username_label->setText(username);
            this->show();
            //getConfigFile();
            getConfigFromServer();
            Util::getInstance()->setAccount(this->account);

		}
        else if (resultCode == 2)
        {
            if(MessageBox(NULL, L"用户不存在，请先注册", L"", MB_OKCANCEL)==IDOK)
            {
                LoginDlg dlg;
                int ret = dlg.exec();
                this->OnLogin(ret,dlg.account,dlg.password);
            }

		}
        else if (resultCode == 1)
        {
			MessageBox(NULL, L"密码错误，请重试", L"", MB_OKCANCEL);
		}
	}
	else if (reply == reply_verification)
	{
		QByteArray result = reply->readAll();
		qDebug() << result;
		QJsonParseError jsonError;
		QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
		QJsonObject obj = document.object();
		if (obj.contains("verificationCode"))
		{
			QJsonValue value = obj.value("verificationCode");
			verificationCode = value.toString();
			qDebug()<< "verificationCode:"<<verificationCode;
		}
	}
    else if(reply == reply_uploadTimeInfo)
    {
        QByteArray result = reply->readAll();
        qDebug()<<result;
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
        QJsonObject obj = document.object();
        if (obj.contains("status"))
        {
            QJsonValue value = obj.value("status");
            QString data = value.toString();
            qDebug()<< "data:"<<data;
            if(data == "ok")
            {
                MessageBox(NULL, L"计时数据上传成功", L"", MB_OK | MB_ICONINFORMATION);
            }else{
                MessageBox(NULL, L"计时数据上传失败", L"", MB_OK | MB_ICONERROR);
            }
        }
    }
    else if(reply == reply_getAppConfigInfo)
    {
        QString val;
        val = reply->readAll();
        qDebug() << "getConfigFromServer: "<<val;
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(val.toUtf8(),&jsonError);
        if (!document.isNull() && (jsonError.error == QJsonParseError::NoError))
        {
            if (document.isArray())
            {
                QJsonArray array = document.array();
                int nSize = array.size();
                for (int i = 0;i<nSize;i++)
                {
                    QJsonValue value = array.at(i);
                    if (value.isObject())
                    {
                        int id;
                        QString processname = "";
                        QString disName = "";
                        QJsonObject object = value.toObject();
                        if (object.contains("name"))
                        {
                            QJsonValue va = object.value("name");
                            //qDebug()<<va.toString();
                            disName = va.toString();
                        }
                        if (object.contains("processName"))
                        {
                            QJsonValue va = object.value("processName");
                           //qDebug() << va.toString();
                            processname = va.toString();
                        }
                        if (object.contains("id"))
                        {
                            QJsonValue va = object.value("id");
                            //qDebug()<<va.toInt();
                            id = va.toInt();
                        }
                        if (processname != "")
                        {
                            softs[id] = processname;
                            softsName[id] = disName;
                        }
                    }
                }
            }
        }

        //添加被监控app信息
        OnMonitor();
        //绘制图表
        mycharts.display(ui,appManage);

    }
}

void ProcessMonitor::OnSendToHost()
{
	if (account == "")
	{
		MessageBox(NULL, L"未登录", L"", MB_OK | MB_ICONERROR);
		return;
	}
	QJsonObject obj;
	obj.insert("account", account);
	QJsonArray array;

	for (int i = 0;i<appManage->appNumber;i++)
	{
		//sendText += appManage->AppTasks[i]->name+",";
		//sendText += QString::number(appManage->AppTasks[i]->liveTime,10) + ";";
		QJsonObject ob;
        ob.insert("appName", appManage->AppTasks[i]->name);
        ob.insert("appTime", appManage->AppTasks[i]->liveTime);
		array.push_back(ob);
		appManage->AppTasks[i]->liveTime = 0;
	}
    obj.insert("appStatus",array);
    qDebug()<<obj;
	QJsonDocument document;
	document.setObject(obj);
	QByteArray dataArray = document.toJson(QJsonDocument::Compact);
    QUrl url(baseIp+"/uploadAppTimeInfo");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
	request.setRawHeader("Authorization", "Bearer 49152bfddae0c5b5d492d3d9871f8c11");
    reply_uploadTimeInfo = manager->post(request, dataArray);

}

void ProcessMonitor::OnRegist()
{
    //待修改
    QDesktopServices::openUrl(QUrl(baseIp+"/monitor_2.0/register_2.html"));
}

void ProcessMonitor::check_account()//socket 已弃用
{
	QByteArray buffer;
	buffer = socket->readAll();
	if (!buffer.isEmpty())
	{
		login_success = true;
		QString resultCode = ql[0];
		QString username = ql[1];
		if (resultCode == "0")
		{
			MessageBox(NULL, L"登录成功", L"", MB_OKCANCEL);
			//QMessageBox::information(NULL, "Process Monitor","登录成功", QMessageBox::Ok,QMessageBox::Cancel);
			//ui.username_label->setText(username);
		}
		else if (resultCode == "2") {
			MessageBox(NULL, L"用户不存在，请先注册", L"", MB_OKCANCEL);
			//QMessageBox::warning(NULL, "Process Monitor", "用户不存在，请先注册", QMessageBox::Ok, QMessageBox::Cancel);
		}
		else if (resultCode == "1") {
			MessageBox(NULL, L"密码错误，请重试", L"", MB_OKCANCEL);
			//QMessageBox::warning(NULL, "Process Monitor", "密码错误，请重试", QMessageBox::Ok, QMessageBox::Cancel);
		}
	}
	
}

void ProcessMonitor::OnMonitor()
{

	if (appManage->appNumber != 0)
	{
		return;
	}
	//MessageBox(NULL,L"MONITOR",L"",MB_OK);
	for (int i = 0;i < ql.length()-1;i++)
	{
        int id = ql[i].toInt();
        appManage->addApp(softs[id],softsName[id]);
        qDebug()<<"OnMonitor: "<<softs[id]<<" : "<<softsName[id];
	}
}
void ProcessMonitor::timerEvent(QTimerEvent *event)
{
	for (int i = 0;i < appManage->appNumber;i++)
	{ 
		if (appManage->AppTasks[i]->isRunning)
		{
			QString n;
			n = n.sprintf("%d", appManage->AppTasks[i]->liveTime);
			fw->setInformation(appManage->AppTasks[i]->displayName,n);
		}
		///qDebug()<< appManage->AppTasks[i]->name +":" <<(int)appManage->AppTasks[i]->appId;
	}


    //打印空闲时长
    qDebug()<<step;
    if (step > 500)
	{
        step = 500;
	}
    //长时间未操作，提问或短信验证
    step--;

    if (step==-100&&account!="")
	{
		//MessageBox(NULL, L"ok", L"", MB_OKCANCEL);
        //int flag = rand()%2;
        //qDebug()<<"flag: "<<flag;
        /*if(flag==0)
        {
            askQuestion();
        }else{

            sendMessage();
        }*/
        //askQuestion();

        //验证窗口
        openVerDlg();
    }
//
	d++;
    if (d == 10)
	{
        // mycharts.display(ui,appManage);
         d = 0;
    }

}

void ProcessMonitor::askQuestion()
{
    appManage->stopAll();
    Question qdlg(this);
    int ret = qdlg.exec();
    if (ret == QDialog::Accepted)
    {
        QMessageBox::information(NULL, "Process Monitor", qdlg.answer, QMessageBox::Ok);
        appManage->startAll();
    }
}

void ProcessMonitor::OnExit()
{
	QApplication::exit(0);
	return;
}

void ProcessMonitor::OnOpen()
{
	this->showNormal();
}

void ProcessMonitor::closeEvent(QCloseEvent *event)
{
	this->hide();
	event->ignore();
}

void ProcessMonitor::OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
	{
		this->showNormal();
	}
}

void ProcessMonitor::OnTest()
{
	//sendMessage();
	
	//getDeskTopAppNames();

	//HWND hWnd = FindWindowW(NULL,L"a.txt - 记事本");
	//PostMessage(hWnd, 0X0010, 0, 0);
	
    //刷新界面
    mycharts.display(ui,appManage);

    //getConfigFromServer();


    //OnMonitor();

    //人脸识别
    //faceDection->openFaceDlg();

    //二维码
    //QrDlg qrDlg;
    //qrDlg.exec();

    //验证窗口
    //VerificationDlg verDlg;
    //verDlg.exec();

}

void ProcessMonitor::getDeskTopAppNames()
{
	HWND pWnd;
	pWnd = first_window(EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);
	QScreen *screen = QGuiApplication::primaryScreen();
	QPixmap map = screen->grabWindow((WId)pWnd);
	map.save("capture\\aa1.jpg", "jpg");

	pWnd = next_window(pWnd, EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);
	map = screen->grabWindow((WId)pWnd);
	map.save("capture\\aa2.jpg", "jpg");


	map = screen->grabWindow(0);
	map.save("capture\\aa3.jpg", "jpg");

	pWnd = next_window(pWnd, EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);

	pWnd = next_window(pWnd, EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);

	pWnd = next_window(pWnd, EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);

	pWnd = next_window(pWnd, EXCLUDE_MINIMIZED);
	qDebug() << get_window_title(pWnd);
}

//待修改
void ProcessMonitor::sendMessage()
{
	//发送短信

	//构建Json对象
	QJsonObject obj;
	obj.insert("account", account);
	obj.insert("phone", phone);
	qDebug() << obj;
	//连接Http

	QJsonDocument document;
	document.setObject(obj);
	QByteArray dataArray = document.toJson(QJsonDocument::Compact);
    QUrl url(baseIp+"/monitor_2.0/SmsDemo.php");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
	request.setRawHeader("Authorization", "Bearer 49152bfddae0c5b5d492d3d9871f8c11");
	reply_verification = manager->post(request, dataArray);

    appManage->stopAll();
//	VerificationDlg vdlg;
//	int ret = vdlg.exec();
//	if (ret == QDialog::Accepted)
//	{
//		if (vdlg.verificationCode == this->verificationCode)
//		{
//			MessageBox(NULL, L"验证码正确", L"", MB_OK | MB_ICONINFORMATION);
//			appManage->startAll();
//		}
//		else {
//			MessageBox(NULL, L"验证码错误", L"", MB_OK | MB_ICONERROR);
//		}

//	}
}


void ProcessMonitor::ShowOnBrowser()
{
	if (account == "")
	{
		MessageBox(NULL, L"未登录", L"", MB_OK | MB_ICONERROR);
		return;
	}
    QString url = "http://39.108.95.162/index.html?account="+this->account;
	QDesktopServices::openUrl(QUrl(url));
}

//已弃用
void ProcessMonitor::OnSetup()
{
	//MessageBox(NULL, L"setup", L"", MB_OK | MB_ICONERROR);
	OnSendToHost();
	SetUp sdlg(this);
	sdlg.getAppManage(appManage);
	int ret = sdlg.exec();
	if (ret == QDialog::Accepted)
	{
		qDebug() << sdlg.softs;
		QJsonObject obj;
		obj.insert("account", account);
		obj.insert("softs",sdlg.softs);
		QJsonDocument document;
		document.setObject(obj);
		QByteArray dataArray = document.toJson(QJsonDocument::Compact);
        QUrl url(baseIp+"/monitor_2.0/updateSofts.php");
		QNetworkRequest request(url);
		request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
		request.setRawHeader("Authorization", "Bearer 49152bfddae0c5b5d492d3d9871f8c11");
		QNetworkReply* reply = manager->post(request, dataArray);
	}
	
}

QString ProcessMonitor::get_window_title(HWND hwnd)
{
	QString retStr;
	wchar_t *temp;
	int len;

	len = GetWindowTextLengthW(hwnd);
	if (!len)
		return retStr;

	temp = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (GetWindowTextW(hwnd, temp, len + 1))
	{
		retStr = QString::fromWCharArray(temp);
	}
	free(temp);
	return retStr;
}

QString ProcessMonitor::get_window_class(HWND hwnd)
{
	QString retStr;
	wchar_t temp[256];

	temp[0] = 0;
	if (GetClassNameW(hwnd, temp, sizeof(temp) / sizeof(wchar_t)))
	{
		retStr = QString::fromWCharArray(temp);
	}
	return retStr;
}

void ProcessMonitor::getConfigFile()
{

    //qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    //qDebug()<<"current currentPath: "<<QDir::currentPath();
	QString val;
	QFile file;
    file.setFileName("../config/softs.json");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	val = file.readAll();
	file.close();
   //qWarning() << "getConfigFile: "<<val;
	QJsonParseError jsonError;
	QJsonDocument doucment = QJsonDocument::fromJson(val.toUtf8(),&jsonError);
	if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
		if (doucment.isObject())
		{
			QJsonObject objs = doucment.object();
			if (objs.contains("softs"))
			{
				QJsonValue values = objs.value("softs");
				if (values.isArray())
				{
					QJsonArray array = values.toArray();
					int nSize = array.size();
					for (int i = 0;i<nSize;i++)
					{
						QJsonValue value = array.at(i);
						if (value.isObject())
						{	
                            int id;
							QString processname = "";
							QString disName = "";
							QJsonObject object = value.toObject();
							if (object.contains("name"))
							{
								QJsonValue va = object.value("name");
                                //qDebug()<<va.toString();
								disName = va.toString();
							}
							if (object.contains("processname"))
							{
								QJsonValue va = object.value("processname");
                                //qDebug() << va.toString();
								processname = va.toString();
							}
							if (object.contains("id"))
							{
								QJsonValue va = object.value("id");
                                //qDebug()<<va.toInt();
                                id = va.toInt();
							}
							if (processname != "")
							{
								softs[id] = processname;
								softsName[id] = disName;
							}
						}
					}
				}
			}
		
		}
	}
}

void ProcessMonitor::getConfigFromServer()
{
    QUrl url(baseIp+"/getAppConfigInfo");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    request.setRawHeader("Authorization", "Bearer 49152bfddae0c5b5d492d3d9871f8c11");
    reply_getAppConfigInfo = manager->get(request);
    qDebug()<<"send over";
}


void ProcessMonitor::OnLogOut()
{
	this->account = "";
    this->appManage->appNumber = 0;
    LoginDlg dlg;
    int ret = dlg.exec();
    OnLogin(ret,dlg.account,dlg.password);
}

void ProcessMonitor::openVerDlg()
{
    appManage->stopAll();
    VerificationDlg verDlg;
    verDlg.exec();
    if(verDlg.verSuccess)
    {
        appManage->startAll();
    }

}
