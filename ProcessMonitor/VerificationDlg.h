#pragma once

#include <QDialog>
#include "ui_VerificationDlg.h"

class VerificationDlg : public QDialog
{
	Q_OBJECT

public:
	VerificationDlg(QWidget *parent = Q_NULLPTR);
	~VerificationDlg();
	QString verificationCode;
private slots:
	void OnOk();
	void OnCancel();
private:
	Ui::VerificationDlg ui;
};
