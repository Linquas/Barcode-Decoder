#include "display.h"
#include "ui_display.h"
#include <iostream>
#include <QDebug>

Display::Display(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Display)
{
    isBarcodeLocated = false;
    isProgramRun = false;
    ui->setupUi(this);
    setFixedSize(640,480);

    this->painter = new QPainter(this);
    update();
}

void Display::loadImg(cv::Mat in){

    if(isProgramRun){
        in.copyTo(img);
        //cv::cvtColor(img,img,CV_BGR2RGB);
        if(isBarcodeLocated){
            cv::rectangle(img , this->barcadeLocation , cv::Scalar(255,0,0) );
        }

        update();
    }
}


void Display::slotGetBarcodeLocation(cv::Rect R){
    this->barcadeLocation = R;
}

void Display::slotIsBarcodeLocated(bool status){
    isBarcodeLocated = status;
}

void Display::updateScreen(){

    //img = cv::imread("barcode.jpg");
    update();
}


void Display::paintEvent(QPaintEvent *){

    painter->begin(this);
    QRect A(0,0,640,480);
    painter->eraseRect(A);

    if(img.data && isProgramRun){

        QPixmap out = QPixmap::fromImage(QImage ((uchar*)img.data , img.cols , img.rows , QImage::Format_RGB888));
        painter->drawPixmap(0,0,out);

    }

    painter->end();


}

void Display::cleanScrean(){

    isProgramRun = false;
    update();
    img.release();
    qDebug("clean screan");
}

void Display::startDisplay(){
    isProgramRun = true;
}

Display::~Display()
{
    delete ui;
    painter->end();
}
