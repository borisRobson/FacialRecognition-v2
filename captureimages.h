#ifndef CAPTUREIMAGES_H
#define CAPTUREIMAGES_H

#include<QtCore>
#include <QTimer>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;

class captureImages : public QObject
{
    Q_OBJECT
public:
    captureImages();
    QTimer *timer;
    void startTimer(int interval, int duration, VideoCapture &capture, vector<Mat>& userFaces, bool ret);
    int count;

    bool done;


public slots:
    void captureImage();
    void endTimer();
};

#endif // CAPTUREIMAGES_H
