#include "process.h"



Process::Process(QObject *parent) : QObject(parent)
{
    isBarcodeLocated = false;
    connect(&Locator,SIGNAL(sendBarcodeLocation(cv::Rect)) , this , SLOT(getLoc(cv::Rect)) );
    connect(&Locator,SIGNAL(sendIsBarcodeLocated(bool)) , this , SLOT(getIsBarcode(bool)) );
}

void Process::getLoc(cv::Rect A){
    emit sendLoc(A);
}

void Process::getIsBarcode(bool A){
    isBarcodeLocated = A;
    emit sendIsBarcaode(A);
}

void Process::getImgAndProcess(cv::Mat input){
    cv::Mat img,barcode,sharpen;
    input.copyTo(img);
    //cv::cvtColor(img,img,CV_BGR2RGB);

    barcode = this->Locator.GetBarLoc(img);


    if(isBarcodeLocated){
        //cv::imshow("barcode",barcode);
        cv::GaussianBlur(barcode,sharpen,cv::Size(3,3),3);
        cv::addWeighted(barcode,1.5,sharpen,-0.5,0,sharpen);
        //cv::imshow("sharpen",sharpen);
        cv::Mat canny;

        //Edge detect
        cv::Canny(sharpen,canny,50,100);
        cv::imshow("can1",canny);
        //Reverse black and white
        cv::threshold(canny,canny,128,255,CV_THRESH_BINARY_INV);
        cv::imshow("can",canny);
        //decode(frame);
        int shift = canny.rows/4;
        //decode(canny,shift);
        decode(canny,shift,&newCode[0]);

        if((newCode[0]>-1)&&(newCode[0]<10)){
            same=1;
            for(int i = 0 ; i < 13 ; i ++){
                if(codeBuffer[i]!=newCode[i]){same=0;}
            }
            if(same){//when same
                for(int i = 0 ; i < 13 ; i ++){
                    code[i] = codeBuffer[i];
                }
            }else{
                for(int i = 0 ; i < 13 ; i ++){
                    codeBuffer[i] = newCode[i];
                }
            }
            cout<<"code is :"<<endl;
            cout<<code[0]<<" "
                <<code[1]<<" "<<code[2]<<" "<<code[3]<<" "<<code[4]<<" "<<code[5]<<" "<<code[6]<<" "
                <<code[7]<<" "<<code[8]<<" "<<code[9]<<" "<<code[10]<<" "<<code[11]<<" "<<code[12]<<endl;

            QString print;
            QTextStream A(&print);
            A << "<big>code: "<<code[0] <<code[1]<<code[2]<<code[3]<<code[4]
              <<code[5]<<code[6]<<code[7]<<code[8]<<code[9]<<code[10]<<code[11]<<code[12]<<"</big>";

            emit sendBarcode(print);
            emit sendBarcodeImg(barcode);
        }


    }

}
