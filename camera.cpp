#include "camera.h"
#include <QDebug>

Camera::Camera(QObject *parent) : QObject(parent)
{
    
    cap = new cv::VideoCapture (this->countCameras());
    cap->set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap->set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    //this->isAutoFocus = false;
    this->autoFocusCheck();

    double dWidth = cap->get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap->get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "Camera input :"<<dWidth<<" X "<<dHeight<<std::endl;


}

int Camera::countCameras(){
    cv::VideoCapture temp_camera;
    cv::Mat tem;
    int maxTested = 10;
    for (int i = 0 ; i < maxTested ; i++){
        cv::VideoCapture temp_camera(i);
        temp_camera.read(tem);
        bool res = (tem.data);

        temp_camera.release();
        if(res){
            this->deviceID = i;
            return i;
        }
    }
    tem.release();
    return maxTested;
}

void Camera::imgRequest(){
    cap->read(this->img);
    //this->autoFocusCheck();
    if(this->img.data){
        //cv::Mat send;
        cv::cvtColor(this->img,send,CV_BGR2RGB);
        emit sendImg(send);
    }else{
        qDebug ("Camera send img failed\n");
    }

}

void Camera::autofocus(int a){
    QProcess setAutoFocus;
    QStringList command;

    if(this->isAutoFocus){

        if(a == Qt::Checked){
            if(this->deviceID == 0){
                command << "v4l2-ctl -c "<< "focus_auto=0";
            }else{
                command << "v4l2-ctl -d /dev/video"<< QString::number(this->deviceID)<<" -c focus_auto=0";
            }


            QString cmd = command.join("");

            qDebug() << cmd;
            setAutoFocus.start(cmd);
            setAutoFocus.waitForFinished();
            this->isAutFocusDisable = true;

        }else if(a == Qt::Unchecked){
            if(this->deviceID == 0){
                command << "v4l2-ctl -c "<< "focus_auto=1";
            }else{
                command << "v4l2-ctl -d /dev/video"<< QString::number(this->deviceID)<<" -c focus_auto=1";
            }
            QString cmd = command.join("");
            qDebug() << cmd;
            setAutoFocus.start(cmd);
            setAutoFocus.waitForFinished();
            this->isAutFocusDisable = false;

        }
    }
}

void Camera::autoFocusCheck(){

    QProcess process;
    QStringList command;
    QByteArray buffer;
    QString cmd;
    this->isAutoFocus = false;
    bool status = false;
    
    if(this->deviceID==0){
        process.start("v4l2-ctl -l");
        cmd = QString("v4l2-ctl -l");
    }else{
        command << "v4l2-ctl -d /dev/video"<< QString::number(this->deviceID)<<" -l";
        cmd = command.join("");
        process.start(cmd);
    }

    while (process.waitForFinished());
        buffer.append(process.readAll());

    //qDebug() << "Buffer data" << buffer;
    qDebug() << "Cmd: " << cmd;

    for(int i =0;i < buffer.size() ; i++){

        if(buffer.at(i) == 'f' && buffer.at(i+1) == 'o' && buffer.at(i+2) == 'c' && buffer.at(i+3) == 'u' &&
                buffer.at(i+4) == 's' && buffer.at(i+5) == '_' && buffer.at(i+6) == 'a' && buffer.at(i+7) == 'u' &&
                buffer.at(i+8) == 't' && buffer.at(i+9) == 'o' ){


            this->isAutoFocus = true;
            status = true;
            
        }
    }

    emit cameraCheck(status);
}

void Camera::focusValue(int in){
    QProcess setFocusValue;
    if(this->isAutoFocus && this->isAutFocusDisable ){
        QStringList command;

        if(this->deviceID == 0){
            command << "v4l2-ctl -c "<<"focus_absolute="<<QString::number(in);
        }else{
            command << "v4l2-ctl -d /dev/video"<<QString::number(this->deviceID)<<" -c focus_absolute="<<QString::number(in);
        }

        QString cmd = command.join("");

        //qDebug() << "value: " <<in;
        qDebug() << cmd;
        setFocusValue.start(cmd);
        setFocusValue.waitForFinished();

    }
}

void Camera::sendID(){
    emit cameraID(this->deviceID);
}

