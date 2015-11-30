#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<cv::Mat>("cv::Mat&");
    qRegisterMetaType<cv::Rect>("cv::Rect");
    qRegisterMetaType<cv::Rect>("cv::Rect&");


    MainWindow w;
    w.show();

    return a.exec();
}
