#include "ProcessMonitor.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qtextcodec.h>
#include "Hook.h"
#include "LoginDlg.h"
QString readFile(QString filename)
{
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray bytes = file.readAll();
		QTextCodec *codec = QTextCodec::codecForName("GBK");
		if (codec)
		{
			return codec->toUnicode(bytes);
		}
	}
    return " ";
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProcessMonitor w;
    //w.show();
    LoginDlg dlg;
    int ret = dlg.exec();
    w.OnLogin(ret,dlg.account,dlg.password);
	a.setStyleSheet(readFile("style.css"));
    setHook();
	return a.exec();
}

