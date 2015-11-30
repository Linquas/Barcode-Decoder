#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <QProcess>

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);
    int countCameras();
    int getCameraID();


signals:
    void sendImg(cv::Mat);
    void cameraCheck(bool);
    void cameraID(int);

public slots:
    void imgRequest();
    void autofocus(int);
    void focusValue(int);
    void autoFocusCheck();
    void sendID();

private:
    cv::Mat img,send;
    cv::VideoCapture *cap;

    bool isAutoFocus;
    bool isAutFocusDisable;
    int deviceID;
};

#endif // CAMERA_H
