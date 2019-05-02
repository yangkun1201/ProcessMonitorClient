#pragma once

#include <QDialog>
#include "ui_VerificationDlg.h"

class VerificationDlg : public QDialog
{
	Q_OBJECT

public:
	VerificationDlg(QWidget *parent = Q_NULLPTR);
	~VerificationDlg();
private slots:
    void verByFace();
    void verByQr();
private:
	Ui::VerificationDlg ui;
};
