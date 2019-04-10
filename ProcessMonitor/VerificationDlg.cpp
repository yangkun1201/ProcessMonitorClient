#include "VerificationDlg.h"

VerificationDlg::VerificationDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	verificationCode = "";
	connect(ui.ok_btn, SIGNAL(clicked()), this, SLOT(OnOk()));
	connect(ui.cancel_btn, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

VerificationDlg::~VerificationDlg()
{
}

void VerificationDlg::OnOk()
{
	verificationCode = ui.verificationCode_Edit->text();
	accept();
}

void VerificationDlg::OnCancel()
{
	reject();
}