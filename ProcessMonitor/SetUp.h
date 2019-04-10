#pragma once

#include <QDialog>
#include "ui_SetUp.h"
#include "AppManage.h"
class SetUp : public QDialog
{
	Q_OBJECT

public:
	SetUp(QWidget *parent = Q_NULLPTR);
	~SetUp();
	AppManage* appManage;
	void getAppManage(AppManage* ap);
	QString softs;
private slots:
	void OnOk();
	void OnCancel();
private:
	Ui::SetUp ui;
};
