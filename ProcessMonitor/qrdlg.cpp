#include "qrdlg.h"
#include "ui_qrdlg.h"
#include "util.h"
#include "Windows.h"

QrDlg::QrDlg(QWidget *parent) :QDialog(parent)
{
    ui.setupUi(this);
    baseIp = Util::getInstance()->getBaseIp();
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replayFinished(QNetworkReply*)));
    //getQrCodeFromServer();
    ui.qrImg->installEventFilter(this);

}

QrDlg::~QrDlg()
{
}

void QrDlg::showEvent(QShowEvent *event)
{
    uuid = "";
    scanSuccess = false;
    timerId = startTimer(500);//开启定时器
    account = "";
    getQrCodeFromServer();
}

void QrDlg::getQrCodeFromServer()
{
    QUrl url(baseIp+"/getQrCodeImageBase64");
    QNetworkRequest request(url);
    reply_qrCode = manager->get(request);
    //qDebug()<<"send over";
}

void QrDlg::replayFinished(QNetworkReply *reply)
{
    //qDebug()<<reply->readAll();
    if(reply == reply_qrCode){
        QByteArray result = reply->readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
        QJsonObject obj = document.object();
        if (obj.contains("qrCodeInBase64"))
        {
            QJsonValue value = obj.value("qrCodeInBase64");
            QString qrCodeInBase64 = value.toString();
            showBase64Image(qrCodeInBase64);
        }
        if(obj.contains("uuid"))
        {
            QJsonValue value = obj.value("uuid");
            uuid = value.toString();
            qDebug()<<"uuid : "<<uuid;
        }
    }
    if(reply == reply_pollingResult)
    {
        QByteArray result = reply->readAll();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
        QJsonObject obj = document.object();
        qDebug()<<result;
        if (obj.contains("scanStatus"))
        {
            QJsonValue value = obj.value("scanStatus");
            int scanStatus = value.toInt();
            if(scanStatus==0)
            {
                scanSuccess = true;
                if(obj.contains("account"))
                {
                    QJsonValue value = obj.value("account");
                    account = value.toString();
                }

            }

        }
    }
}

void QrDlg::showBase64Image(QString base64Code)
{
    QByteArray code = QByteArray::fromBase64(base64Code.toLocal8Bit());
    QBuffer buffer(&code);
    buffer.open(QIODevice::WriteOnly);
    QPixmap image;
    image.loadFromData(code);
    ui.qrImg->setPixmap(image);
    ui.qrImg->setScaledContents(true);
    buffer.close();
}


bool QrDlg::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui.qrImg)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            getQrCodeFromServer();
            return true;
        }else{
            return false;
        }
    }
}

void QrDlg::pollingQrCodeStatus(QString uuid)
{
    //qDebug()<<"polling";
    QUrl url(baseIp+"/queryQrCodeScanStatus?uuid="+uuid);
    QNetworkRequest request(url);
    reply_pollingResult = manager->get(request);
}

void QrDlg::timerEvent(QTimerEvent *event)
{
    if(uuid != "" && !scanSuccess)
    {
        pollingQrCodeStatus(uuid);
    }

}
