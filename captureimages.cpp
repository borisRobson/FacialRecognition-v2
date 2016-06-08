#include "captureimages.h"

#include <QTimer>
#include <QtCore>
#include <iostream>
#include<stdio.h>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;

VideoCapture cap;
vector<Mat>faces;


captureImages::captureImages()
{
    timer = new QTimer(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(captureImage()));
}

void captureImages::startTimer(int interval,int duration,  VideoCapture& capture, vector<Mat>& userFaces, bool ret)
{
    if (!ret){
        count = 0;
        done = false;
        cap = capture;
        faces= userFaces;
        timer->start(interval);
        QTimer::singleShot(duration, this, SLOT(endTimer()));
    }else{
        userFaces = faces;
    }
}

void captureImages::captureImage()
{
    count++;
    Mat face;
    cap >> face;
    faces.push_back(face);
}

void captureImages::endTimer()
{
    if(timer->isActive()){
        timer->stop();
        done = true;
        cout << "timer stopped" << endl;
    }
}

