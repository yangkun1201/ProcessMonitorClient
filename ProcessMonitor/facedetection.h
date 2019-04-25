#ifndef FACEDETECTION_H
#define FACEDETECTION_H
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;

class FaceDetection
{
public:
    FaceDetection();
    void openFaceDlg();

private:
    String face_cascade_name = "F:\\opencv\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml";
    std::vector<Rect> faces;
};

#endif // FACEDETECTION_H
