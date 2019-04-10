#include "SetUp.h"
#include <qdebug.h>
SetUp::SetUp(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.ok_btn, SIGNAL(clicked()), this, SLOT(OnOk()));
    connect(ui.cancel_btn, SIGNAL(clicked()), this, SLOT(OnCancel()));

}

SetUp::~SetUp()
{
}

void SetUp::getAppManage(AppManage* ap)
{
    this->appManage = ap;
    //qDebug()<<ap->appNumber;

    //显示原有状态
    for (int i = 0;i < appManage->appNumber;i++)
    {
        if (appManage->AppTasks[i]->name == "QyClient.exe")
        {
            ui.soft_1->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "QQ.exe")
        {
            ui.soft_2->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "devenv.exe")
        {
            ui.soft_3->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "studio64.exe")
        {
            ui.soft_4->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "wampmanager.exe")
        {
            ui.soft_5->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "sublime_text.exe")
        {
            ui.soft_6->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "devcpp.exe")
        {
            ui.soft_7->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "eclipse.exe")
        {
            ui.soft_8->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "idea64.exe")
        {
            ui.soft_9->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "pycharm64.exe")
        {
            ui.soft_10->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "myeclipse.exe")
        {
            ui.soft_11->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "wechatdevtools.exe")
        {
            ui.soft_12->setChecked(true);
        }
        if (appManage->AppTasks[i]->name == "Photoshop.exe")
        {
            ui.soft_13->setChecked(true);
        }
    }
    softs = "";
}

void SetUp::OnOk()
{

    appManage->appNumber = 0;
    if (ui.soft_1->isChecked())
    {
        //appManage->addApp("QyClient.exe","爱奇艺");
        softs += "1,";
    }
    if (ui.soft_2->isChecked())
    {
        appManage->addApp("QQ.exe", "QQ");
        softs += "2,";
    }
    if (ui.soft_3->isChecked())
    {
        appManage->addApp("devenv.exe", "VS");
        softs += "3,";
    }
    if (ui.soft_4->isChecked())
    {
        appManage->addApp("studio64.exe", "Android Studio");
        softs += "4,";
    }
    if (ui.soft_5->isChecked())
    {
        appManage->addApp("wampmanager.exe", "Wamp");
        softs += "5,";
    }
    if (ui.soft_6->isChecked())
    {
        appManage->addApp("sublime_text.exe", "sublime_text");
        softs += "6,";
    }
    if (ui.soft_7->isChecked())
    {
        appManage->addApp("devcpp.exe", "Dev-C++");
        softs += "7,";
    }
    if (ui.soft_8->isChecked())
    {
        appManage->addApp("eclipse.exe", "eclipse");
        softs += "8,";
    }
    if (ui.soft_9->isChecked())
    {
        appManage->addApp("idea64.exe", "IntelliJ IDEA");
        softs += "9,";
    }
    if (ui.soft_10->isChecked())
    {
        appManage->addApp("pycharm64.exe", "PyCharm");
        softs += "10,";
    }
    if (ui.soft_11->isChecked())
    {
        appManage->addApp("myeclipse.exe", "myeclipse");
        softs += "11,";
    }
    if (ui.soft_12->isChecked())
    {
        //appManage->addApp("wechatdevtools.exe", "微信web开发者工具");
        softs += "12,";
    }
    if (ui.soft_13->isChecked())
    {
        appManage->addApp("Photoshop.exe", "Adobe Photoshop CS6");
        softs += "13,";
    }

    accept();

}

void SetUp::OnCancel()
{
    reject();
}
