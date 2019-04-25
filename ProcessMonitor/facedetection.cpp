#include "facedetection.h"
#include "QDebug"
FaceDetection::FaceDetection()
{

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
    }
}
