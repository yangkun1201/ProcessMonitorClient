#pragma once

#include <QDialog>
#include "ui_VerificationDlg.h"
#include "util.h"
#include "facedetection.h"
#include "qrdlg.h"

class VerificationDlg : public QDialog
{
	Q_OBJECT

public:
	VerificationDlg(QWidget *parent = Q_NULLPTR);
	~VerificationDlg();
    void timerEvent(QTimerEvent *event);
private slots:
    void verByFace();
    void verByQr();
private:
	Ui::VerificationDlg ui;
    QString message;
    int timerId;
    QrDlg *qrDlg;
    FaceDetection *faceDetection;
};
