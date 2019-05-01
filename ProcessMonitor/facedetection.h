#ifndef FACEDETECTION_H
#define FACEDETECTION_H
#include<opencv2\opencv.hpp>
#include <qmessagebox.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

using namespace std;
using namespace cv;

class FaceDetection:QObject
{
    Q_OBJECT
public:
    FaceDetection();
    void openFaceDlg();
    void verificationFaceId();
    QNetworkReply* reply_faceid;
    int status; //0 未检测，1 正在检测， 2 验证成功， 3 验证失败
    QString account;
    QString name;
public slots:
    void replayFinished(QNetworkReply *reply);
private:
    String face_cascade_name = "haarcascade_frontalface_default.xml";
    vector<Rect> faces;
    QNetworkAccessManager * manager;
    void timerEvent(QTimerEvent *event);
    int timerId;
    int waitTime;

};

#endif // FACEDETECTION_H
