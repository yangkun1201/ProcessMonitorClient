#pragma once

#include <QDialog>
#include "ui_LoginDlg.h"

class LoginDlg : public QDialog
{
	Q_OBJECT

public:
	LoginDlg(QWidget *parent = Q_NULLPTR);
	~LoginDlg();
	QString account;
	QString password;

private:
	Ui::LoginDlg ui;

private slots:
	int OnBtnOK();
	int OnBtnCancel();
    void OnRegist();
};
