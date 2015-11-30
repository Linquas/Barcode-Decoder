#ifndef BARCODE_LOCATOR_H
#define BARCODE_LOCATOR_H

#include <opencv2/opencv.hpp>
#include <QObject>


class Barcode_Locator : public QObject
{
    Q_OBJECT
public:
    Barcode_Locator(QObject *parent = 0);
    cv::Mat GetBarLoc(cv::Mat img_input );
    cv::Mat DrawBarLoc(cv::Mat img_input);

signals:
    void sendBarcodeLocation(cv::Rect);
    void sendIsBarcodeLocated(bool);

private:
    cv::Mat img , img_gray , img_smooth , img_thres;
    cv::Rect Crop(cv::Mat thres_img ,  cv::Point MaxPoint );
};

#endif // BARCODE_LOCATOR_H
