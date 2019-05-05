#include "ProcessMonitor.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include "Hook.h"
#include "LoginDlg.h"
#include "util.h"

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

	QApplication a(argc, argv);
	ProcessMonitor w;
    //w.show();
    LoginDlg dlg;
    int ret = dlg.exec();
    w.OnLogin(ret,dlg.account,dlg.password);
    a.setStyleSheet(Util::getInstance()->readFile("style.css"));
    setHook();
	return a.exec();
}

