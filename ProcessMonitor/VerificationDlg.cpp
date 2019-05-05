#include "VerificationDlg.h"

VerificationDlg::VerificationDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    connect(ui.ver_face, SIGNAL(clicked()), this, SLOT(verByFace()));
    connect(ui.ver_qr, SIGNAL(clicked()), this, SLOT(verByQr()));
    timerId = startTimer(500);
    faceDetection = new FaceDetection();
    qrDlg = new QrDlg();
}

VerificationDlg::~VerificationDlg()
{
    delete faceDetection;
    delete qrDlg;
}

void VerificationDlg::showEvent(QShowEvent *)
{
    verSuccess = false;
}

void VerificationDlg::verByFace()
{
    //人脸识别
    faceDetection->openFaceDlg();
    if(faceDetection->account==""){
        message = "验证失败";
    }else if(faceDetection->account==Util::getInstance()->getAccount()){
        message = "验证成功\n账号:"+faceDetection->account+"\n"+"用户:"+faceDetection->name;
        verSuccess = true;
    }else{
        message = "验证失败";
    }

    ui.message->setText(message);
}

void VerificationDlg::verByQr()
{
    //二维码
    qrDlg->exec();
    if(qrDlg->account==""){
        message = "验证失败";
    }else if(qrDlg->account==Util::getInstance()->getAccount()){
        message = "验证成功\n账号:"+qrDlg->account;
        verSuccess = true;
    }else{
       message = "验证失败";
    }
    ui.message->setText(message);
}

void VerificationDlg::timerEvent(QTimerEvent *event)
{
    if(qrDlg->scanSuccess)
    {
        qrDlg->accept();
    }

    if(faceDetection->status==2 || faceDetection->status==3)
    {
        faceDetection->closeWindow();
    }

}
