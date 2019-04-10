#include "LoginDlg.h"
#include <QDesktopServices>
#include <QUrl>
LoginDlg::LoginDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.ok_btn,SIGNAL(clicked()),this,SLOT(OnBtnOK()));
	connect(ui.cancel_btn, SIGNAL(clicked()), this, SLOT(OnBtnCancel()));
    connect(ui.btn_regist,SIGNAL(clicked()),this,SLOT(OnRegist()));
}

LoginDlg::~LoginDlg()
{
}

int LoginDlg::OnBtnOK()
{
	account = ui.account_input->text();
	password = ui.password_input->text();
	accept();
	return 0;
}

int LoginDlg::OnBtnCancel()
{
	reject();
	return 0; 
}
void LoginDlg::OnRegist()
{
    QDesktopServices::openUrl(QUrl("http://localhost:8086/monitor_2.0/register_2.html"));
}
