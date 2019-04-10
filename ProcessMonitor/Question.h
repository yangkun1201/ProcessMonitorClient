#pragma once

#include <QDialog>
#include "ui_Question.h"
#include <Windows.h>

class Question : public QDialog
{
	Q_OBJECT

public:
	Question(QWidget *parent = Q_NULLPTR);
	~Question();
	QString answer;
private:
	Ui::Question ui;

private slots:
	void OnOk();
	void OnCancel();
};
