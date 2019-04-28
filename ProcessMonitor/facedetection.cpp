#include "facedetection.h"
#include "QDebug"
#include <qevent.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <QBuffer>

FaceDetection::FaceDetection(QObject* obj)
{
    manager = new QNetworkAccessManager(obj);
}

void FaceDetection::openFaceDlg(){
    VideoCapture capture(0);
    Mat frame;
    CascadeClassifier face_cascade;
    if (!face_cascade.load(face_cascade_name)){

          qDebug()<<"--(!)Error loading face cascade\n";
          return;
    };
    if (!capture.isOpened()) {

        qDebug()<<"--(!)Error opening video capture\n ";
        return;
    }
    while (capture.read(frame)){

        Mat oldFrame = frame;

        if (frame.empty()){

           qDebug()<<" --(!) No captured frame -- Break!";
           break;

        }

        Mat frame_gray;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);
        face_cascade.detectMultiScale(frame, faces, 3.05, 5);
        qDebug()<<faces.size();
        for (size_t i = 0; i < faces.size(); i++){
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
        }

        imshow("test", frame);
        waitKey(100);
        if(faces.size()>0){
            string data = mat2str(oldFrame);
            imwrite("E:\\image\\face.jpg",frame);
            std::vector<uint8_t> buffer;
            cv::imencode(".jpg", oldFrame, buffer);
            QByteArray byteArray = QByteArray::fromRawData((const char*)buffer.data(), buffer.size());
            QString base64Image(byteArray);
            //QString base64Image(byteArray.toBase64());
            //printf("%s",data.c_str());
            //verificationFaceId(readFile("E:\\image\\face.jpg").toBase64());
            verificationFaceId(QString::fromLocal8Bit(data.c_str()));
            //qDebug()<<QString(base64Image);

            break;
        }
    }
}

QByteArray FaceDetection::readFile(QString fileName){
    QFile file(fileName);
    QByteArray data;
    if(file.open(QIODevice::ReadOnly)){
        data = file.readAll();
    }
    file.close();
    return data;
}

void FaceDetection::verificationFaceId(QString data){
    QUrl url("http://127.0.0.1:8080/verificationFaceId");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
   // QUrlQuery params;
    //params.addQueryItem("faceId",data);
    //manager->post(request,"faceId="+data.toBase64()+"");
    qDebug()<<"send over";
    //printf("%s",QString(data.toBase64()).toStdString().c_str());

    QImage image("E:\\image\\face.jpg");
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf,"JPG",20);
    QByteArray hexed = ba.toBase64();
    buf.close();

    QFile file("E:\\image\\data.txt");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(NULL, "提示", "无法创建文件");
        return;
    }
    QTextStream out(&file);
    out<<hexed<<endl;
    out.flush();
    file.close();


}

void FaceDetection::StringReplace(string &strBase, string strSrc, string strDes)
{
    string::size_type pos = 0;
    string::size_type srcLen = strSrc.size();
    string::size_type desLen = strDes.size();
    pos=strBase.find(strSrc, pos);
    while ((pos != string::npos))
    {
        strBase.replace(pos, srcLen, strDes);
        pos=strBase.find(strSrc, (pos+desLen));
    }
}



std::string FaceDetection::base64_encode(uchar const* bytes_to_encode, unsigned int in_len)
{
    std::string ret;

    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--)
    {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i <4); i++)
            {
                ret += base64_chars[char_array_4[i]];
            }
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
        {
            char_array_3[j] = '\0';
        }

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
        {
            ret += base64_chars[char_array_4[j]];
        }
        while ((i++ < 3))
        {
            ret += '=';
        }
    }

    return ret;

}

std::string FaceDetection::base64_decode(std::string const& encoded_string) {

    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
    {
        char_array_4[i++] = encoded_string[in_]; in_++;

        if (i == 4)
        {
            for (i = 0; i < 4; i++)
            {
                char_array_4[i] = base64_chars.find(char_array_4[i]);
            }

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
            {
                ret += char_array_3[i];
            }

            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 4; j++)
        {
            char_array_4[j] = 0;
        }

        for (j = 0; j < 4; j++)
        {
            char_array_4[j] = base64_chars.find(char_array_4[j]);
        }

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++)
        {
            ret += char_array_3[j];
        }
    }

    return ret;
}

string FaceDetection::mat2str(const Mat& m)
{
    vector<uchar> buf;
    imencode(".jpg", m, buf);
    uchar *enc_msg = new uchar[buf.size()];
    for(int i=0; i < buf.size(); i++) enc_msg[i] = buf[i];
    return base64_encode(enc_msg, buf.size());

}



Mat FaceDetection::str2mat(const string& s)
{
    // Decode data
    string decoded_string = base64_decode(s);
    vector<uchar> data(decoded_string.begin(), decoded_string.end());

    cv::Mat img = imdecode(data, IMREAD_UNCHANGED);
    return img;
}

bool FaceDetection::is_base64( unsigned char c )
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}


