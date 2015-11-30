#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <QObject>
#include <opencv2/opencv.hpp>
#include <barcode_locator.h>
#include <decode.h>
#include <QString>
#include <QTextStream>

using namespace std;

class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = 0);

signals:
    void sendLoc(cv::Rect);
    void sendIsBarcaode(bool);
    void sendBarcodeImg(cv::Mat);
    void sendBarcode(QString);

public slots:

    void getImgAndProcess(cv::Mat);
    void getLoc(cv::Rect );
    void getIsBarcode(bool);

private:
    Barcode_Locator Locator;
    bool isBarcodeLocated;
    int *Num;
    //int Num2[13];
    int code[13],newCode[13],codeBuffer[13];
    int same;

};

#endif // PROCESS_H
