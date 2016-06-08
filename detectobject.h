#ifndef DETECTFACE_H
#define DETECTFACE_H

#include <QObject>
#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;

class detectObject : public QObject
{
    Q_OBJECT
public:
    detectObject();
    ~detectObject();

    void detectLargestObject();
    void initCascades(CascadeClassifier& faceCascade, CascadeClassifier& eyeCascade, CascadeClassifier& eyeGlassesCascade);
    void equalizeLeftAndRightHalves(Mat &faceImg);

    Rect findObject(Mat &image, CascadeClassifier &cascade, int scaledWidth = 320);
    Mat detectEyes(Mat& face, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2, Point &leftEye, Point &rightEye);
    Mat processImage(Mat &img, CascadeClassifier& faceCascade, CascadeClassifier& eyeCascade, CascadeClassifier& eyeGlassCascade);
    Mat emitSignal(Mat& img);



};

#endif // DETECTFACE_H
