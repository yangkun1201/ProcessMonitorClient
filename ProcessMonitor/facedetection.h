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

class FaceDetection
{
public:
    FaceDetection(QObject* obj);
    void openFaceDlg();
    string base64_encode(uchar const* bytes_to_encode, unsigned int in_len);
    string base64_decode(std::string const& encoded_string);
    string mat2str(const Mat& m);
    Mat str2mat(const string& s);
    bool is_base64( unsigned char c );
    void StringReplace(string &strBase, string strSrc, string strDes);
    void verificationFaceId(QString data);
    QByteArray readFile(QString fileName);
private:
    String face_cascade_name = "F:\\opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml";
    vector<Rect> faces;
    const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
     QNetworkAccessManager * manager;

};

#endif // FACEDETECTION_H
