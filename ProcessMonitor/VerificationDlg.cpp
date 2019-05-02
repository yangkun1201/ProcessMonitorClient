#include "VerificationDlg.h"
#include "facedetection.h"
#include "qrdlg.h"

VerificationDlg::VerificationDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    connect(ui.ver_face, SIGNAL(clicked()), this, SLOT(verByFace()));
    connect(ui.ver_qr, SIGNAL(clicked()), this, SLOT(verByQr()));
}

VerificationDlg::~VerificationDlg()
{
}

void VerificationDlg::verByFace()
{
    //人脸识别
    FaceDetection faceDetection;
    faceDetection.openFaceDlg();
}

void VerificationDlg::verByQr()
{
    //二维码
    QrDlg qrDlg;
    qrDlg.exec();
}
