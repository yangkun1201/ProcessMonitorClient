#include "facedetection.h"
#include "QDebug"
#include <qevent.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <QBuffer>
#include "util.h"

FaceDetection::FaceDetection()
{
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replayFinished(QNetworkReply*)));
    waitTime = 0;
    baseIp = Util::getInstance()->getBaseIp();

}

void FaceDetection::openFaceDlg(){
    //开启定时器
    timerId = startTimer(1000);
    //开启摄像头
    VideoCapture capture(0);
    Mat frame;
    CascadeClassifier face_cascade;
    status = 0;
    if (!face_cascade.load(face_cascade_name)){

          qDebug()<<"--(!)Error loading face cascade\n";
          return;
    };
    if (!capture.isOpened()) {

        qDebug()<<"--(!)Error opening video capture\n ";
        return;
    }
    while (status==0||status==1){

        capture.read(frame);
        Mat oldFrame = frame;

        if (frame.empty()){

           qDebug()<<" --(!) No captured frame -- Break!";
           break;

        }

        Mat frame_gray;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);
        face_cascade.detectMultiScale(frame, faces, 3.05, 5);
        //qDebug()<<faces.size();
        for (size_t i = 0; i < faces.size(); i++){
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
        }

        imshow("faceDetection", frame);
        waitKey(100);
        if(faces.size()>0){
            imwrite("face.jpg",oldFrame);
            if(status==0){
                verificationFaceId();
                status = 1;
            }

        }

    }
}

void FaceDetection::verificationFaceId(){
    QUrl url(baseIp+"/verificationFaceId");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
   // QUrlQuery params;
    //params.addQueryItem("faceId",data);
    //manager->post(request,"faceId="+data.toBase64()+"");

    QImage image("face.jpg");
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf,"JPG",20);
    QByteArray hexed = ba.toBase64();
    buf.close();

    QFile file("faceData.txt");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(NULL, "提示", "无法创建文件");
        return;
    }
    QTextStream out(&file);
    out<<hexed<<endl;
    out.flush();
    file.close();

    reply_faceid = manager->post(request,"faceId="+hexed+"");
    qDebug()<<"send over";
}

void FaceDetection::replayFinished(QNetworkReply *reply)
{
    if(reply==reply_faceid){
        qDebug()<<"faceid result";
        QByteArray result = reply->readAll();
        qDebug()<<result;
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(result, &jsonError);
        QJsonObject obj = document.object();
        if (obj.contains("status"))
        {
            QJsonValue value = obj.value("status");
            QString data = value.toString();
            if(data == "ok"){
                status = 2;
                if(obj.contains("account")){
                    QJsonValue accountValue = obj.value("account");
                    account = accountValue.toString();
                }
                if(obj.contains("name")){
                    QJsonValue nameValue = obj.value("name");
                    name = nameValue.toString();
                }
            }else{
                status = 3;
            }
        }
    }
}

void FaceDetection::timerEvent(QTimerEvent *event){
    //qDebug()<<"waitTime"<<waitTime;
    qDebug()<<"status"<<status;
    //检测超时
    if(waitTime==30){
        qDebug()<<"wait over";
        waitTime = 0;
        status = 3;
        killTimer(timerId);
    }

    //验证成功,停止计时器
    if(status==2){
        waitTime = 0;
        killTimer(timerId);
    }

    waitTime++;

    //显示验证结果
    if(status==2){
        QMessageBox(QMessageBox::Information,"验证结果","验证成功\n账号:"+account+"\n用户名:"+name);
        qDebug()<<"验证结果"<<"验证成功\n账号:"+account+"\n用户:"+name;
    }
    if(status==3){
        QMessageBox(QMessageBox::Critical,"验证结果","验证失败");
        qDebug()<<"验证结果"<<"验证失败";
    }

}



