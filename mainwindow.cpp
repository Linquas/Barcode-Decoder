#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <camera.h>
#include <process.h>
#include<mattoqimage.h>
#include <display.h>

#include <QPainter>
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Barcode Decoder");

    this->timer = new QTimer(this);
    //QPainter *painter = new QPainter(this);
    Camera *camera = new Camera();
    Process *process = new Process();




    process->moveToThread(&decodeThread);
    decodeThread.start();

    camera->moveToThread(&cameraThread);
    cameraThread.start();


    connect(timer , SIGNAL(timeout()) , camera , SLOT(imgRequest()) );
    connect(camera, SIGNAL(sendImg(cv::Mat)) , ui->play , SLOT(loadImg(cv::Mat)) );
    connect(camera, SIGNAL(sendImg(cv::Mat)) , process , SLOT(getImgAndProcess(cv::Mat)) );
    connect(process, SIGNAL(sendIsBarcaode(bool)) , ui->play , SLOT(slotIsBarcodeLocated(bool)) );
    connect(process, SIGNAL(sendLoc(cv::Rect)) , ui->play , SLOT(slotGetBarcodeLocation(cv::Rect)) );
    connect(process, SIGNAL(sendBarcodeImg(cv::Mat)) , this , SLOT(updateBarcodeImg(cv::Mat)) );
    connect(process, SIGNAL(sendBarcode(QString)) , this , SLOT(updateBarcode(QString)) );
    
    connect(ui->close, SIGNAL(pressed()) , ui->play, SLOT(cleanScrean()) );
    connect(ui->start, SIGNAL(pressed()) , ui->play, SLOT(startDisplay()) );
    //connect(ui->checkBox, SIGNAL(stateChanged(int)) , camera , SLOT(autofocus(int)) );
    connect(ui->focusValue, SIGNAL(sliderReleased()) , this , SLOT(getSliderValue()) );
    //connect(this , SIGNAL(focusNum(int)) , camera , SLOT(focusValue(int)) );
    connect(ui->checkBox , SIGNAL(clicked(bool)) , ui->focusValue, SLOT(setEnabled(bool)) );
    //connect(camera , SIGNAL(cameraCheck(bool)) , this , SLOT(slotCameraCheck(bool)) );
    //connect(ui->start, SIGNAL(pressed()) , camera , SLOT(autoFocusCheck()) );

    connect(ui->start, SIGNAL(pressed()) , camera , SLOT(sendID()) );
    connect(camera, SIGNAL(cameraID(int)) , this, SLOT(checkCamera(int)) );
    connect(this , SIGNAL(focusNum(int)) , this, SLOT(setCameraFocusValue(int)) );
    connect(ui->checkBox , SIGNAL(stateChanged(int)) , this , SLOT(setFocusStatus(int)) );



    //camera->autoFocusCheck();

    ui->close->setEnabled(false);
    ui->checkBox->setEnabled(false);
    ui->focusValue->setEnabled(false);

    this->cameraFocus = false;

    //this->timer->start(33);//using timer to trigger update

}

void MainWindow::updateBarcodeImg(const cv::Mat& bar){
    //cv::imshow("gray",bar);

    QImage a = MatToQImage(bar);

    if(a.width()>300 || a.height()>200){
        a = a.scaled(300,200,Qt::KeepAspectRatio);
    }

    // display on label
    ui->BarcodeImg->setPixmap(QPixmap::fromImage(a,Qt::AutoColor));
    // resize the label to fit the image
    ui->BarcodeImg->resize(ui->BarcodeImg->pixmap()->size());
}

void MainWindow::getSliderValue(){
    emit focusNum(ui->focusValue->value());

}



void MainWindow::updateBarcode(QString str){

    ui->code->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ui->code->setTextFormat(Qt::RichText);
    ui->code->setText(str);
    ui->code->setAlignment(Qt::AlignLeft);
}

void MainWindow::slotCameraCheck(bool a){
    if (a == true){
        ui->checkBox->setEnabled(true);
    }
    if(a == false){
       ui->checkBox->setEnabled(false);
    }
}

void MainWindow::on_close_clicked()
{
    this->timer->stop();
    ui->start->setEnabled(true);
    ui->close->setEnabled(false);

}

void MainWindow::on_start_clicked()
{
    this->timer->start(40);
    ui->start->setEnabled(false);
    ui->close->setEnabled(true);
}


MainWindow::~MainWindow()
{
    delete ui;

    decodeThread.quit();
    if(!decodeThread.wait(1000)) //Wait until it actually has terminated (max. 3 sec)
    {
        decodeThread.terminate(); //Thread didn't exit in time, probably deadlocked, terminate it!
        decodeThread.wait(); //We have to wait again here!
    }

    cameraThread.quit();
    if(!cameraThread.wait(3000))
    {
        cameraThread.terminate();
        cameraThread.wait();
    }

}

void MainWindow::setCameraFocusValue(int focus){
    QProcess setFocusValue;
    if(this->cameraFocus && ui->checkBox ){
        QStringList command;

        if(this->cameraID == 0){
            command << "v4l2-ctl -c "<<"focus_absolute="<<QString::number(focus);
        }else{
            command << "v4l2-ctl -d /dev/video"<<QString::number(this->cameraID)<<" -c focus_absolute="<<QString::number(focus);
        }

        QString cmd = command.join("");

        //qDebug() << "value: " <<in;
        qDebug() << cmd;
        setFocusValue.start(cmd);
        setFocusValue.waitForFinished();

    }
}

void MainWindow::checkCamera(int ID){
    this->cameraID = ID;
    QProcess process;
    QStringList command;
    QByteArray buffer;
    QString cmd;

    this->cameraFocus = false;

    bool status = false;

    if(this->cameraID==0){
        process.start("v4l2-ctl -l");
        cmd = QString("v4l2-ctl -l");
    }else{
        command << "v4l2-ctl -d /dev/video"<< QString::number(this->cameraID)<<" -l";
        cmd = command.join("");
        process.start(cmd);
    }

    while (process.waitForFinished());
        buffer.append(process.readAll());

    //qDebug() << "Buffer data" << buffer;
    qDebug() << cmd;

    for(int i =0;i < buffer.size() ; i++){

        if(buffer.at(i) == 'f' && buffer.at(i+1) == 'o' && buffer.at(i+2) == 'c' && buffer.at(i+3) == 'u' &&
                buffer.at(i+4) == 's' && buffer.at(i+5) == '_' && buffer.at(i+6) == 'a' && buffer.at(i+7) == 'u' &&
                buffer.at(i+8) == 't' && buffer.at(i+9) == 'o' ){


            this->cameraFocus = true;
            status = true;
            ui->checkBox->setEnabled(true);
        }
    }
}
void MainWindow::setFocusStatus(int a){
    QProcess setAutoFocus;
    QStringList command;

    if(this->cameraFocus){

        if(a == Qt::Checked){
            if(this->cameraID == 0){
                command << "v4l2-ctl -c "<< "focus_auto=0";
            }else{
                command << "v4l2-ctl -d /dev/video"<< QString::number(this->cameraID)<<" -c focus_auto=0";
            }


            QString cmd = command.join("");

            qDebug() << cmd;
            setAutoFocus.start(cmd);
            setAutoFocus.waitForFinished();
            this->isAutFocusDisable = true;

        }else if(a == Qt::Unchecked){
            if(this->cameraID == 0){
                command << "v4l2-ctl -c "<< "focus_auto=1";
            }else{
                command << "v4l2-ctl -d /dev/video"<< QString::number(this->cameraID)<<" -c focus_auto=1";
            }
            QString cmd = command.join("");
            qDebug() << cmd;
            setAutoFocus.start(cmd);
            setAutoFocus.waitForFinished();
            this->isAutFocusDisable = false;

        }
    }
}
