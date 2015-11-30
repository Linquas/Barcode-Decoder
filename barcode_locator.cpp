#include "barcode_locator.h"
#include <omp.h>

Barcode_Locator::Barcode_Locator(QObject *parent) : QObject(parent)
{

}


cv::Mat Barcode_Locator::GetBarLoc(cv::Mat img_input){
    this->img = img_input;

    cv::Mat grad_x , grad_y;
    cv::Mat abs_grad_x , abs_grad_y;

    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

//---------------------------------Gradient Calculation------------------------------------
    cv::cvtColor(this->img,this->img_gray,CV_BGR2GRAY);
    cv::GaussianBlur( this->img_gray, this->img_gray, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );
#pragma omp parallel sections
{
    #pragma omp section
    {
            /// Gradient X
            cv::Sobel( this->img_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
            cv::convertScaleAbs(grad_x , abs_grad_x);
    }
    #pragma omp section

    {
            /// Gradient Y
            cv::Sobel( this->img_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
            cv::convertScaleAbs(grad_y , abs_grad_y);
    }
}
    //cv::imshow("grad_x",grad_x);
    //cv::imshow("grad_y",grad_y);
    //cv::imshow("abs_x",abs_grad_x);
    //cv::imshow("abs_y",abs_grad_y);

//--------------------------------Gradient difference between x and y-------------------
    cv::Mat grad_diff;
    grad_diff = cv::abs(abs_grad_x) - cv::abs(abs_grad_y);

    //cv::imshow("diff",grad_diff);    

    cv::blur(grad_diff,this->img_smooth,cv::Size(31,31),cv::Point(-1,-1));//region normalization
    //cv::imshow("smooth",this->img_smooth);

    //find the location of the max value
    double minval, maxval;
    cv::Point minloc, maxloc;
    cv::minMaxLoc(this->img_smooth, &minval, &maxval, &minloc, &maxloc);

    //cout << "Max value : " << maxval << endl;

    //cv::Mat Result1;
    cv::Mat Result;

    if(maxval > 130.0 && maxloc.x > 0 && maxloc.y > 0){
        // thresholding by OTSU method
        cv::Mat thres;
        cv::threshold(this->img_smooth,thres,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
        //cv::imshow("thres",thres);




        cv::Point MaxPoint;
        MaxPoint.x = maxloc.x;
        MaxPoint.y = maxloc.y;
        cv::Rect A = Crop( thres ,  MaxPoint );

        if(A.width >= 0 && A.height >= 0){

            emit sendBarcodeLocation(A);
            emit sendIsBarcodeLocated(true);

            //cv::rectangle(this->img , A , cv::Scalar(255,0,0) );
            //cv::imshow("REs",this->img);
            Result = this->img_gray(A);

            //cv::Mat Result;
            cv::resize(Result,Result,cv::Size(1.2*Result.cols,1.2*Result.rows));
            //cv::imshow("big",Result);

        }

    }else{
        emit sendIsBarcodeLocated(false);
    }

    return Result;
}

cv::Rect Barcode_Locator::Crop( cv::Mat thres_img, cv::Point MaxPoint){
    int x = MaxPoint.x;
    int y = MaxPoint.y;
    cv::Rect Location;

    int Left_loc = -1 , Right_loc = -1, Up_loc=-1 , Down_loc =-1;


    for( int i = x ; thres_img.ptr<uchar>(y)[i] != 0 && i > 0  ; i --){
        Left_loc = i;
    }
    for( int i = x ; thres_img.ptr<uchar>(y)[i] != 0 && i < thres_img.cols ; i ++){
        Right_loc = i;
    }
    for( int i = y ; thres_img.ptr<uchar>(i)[x] != 0 && i < thres_img.rows ; i ++){
        Down_loc = i;
    }
    for( int i = y ; thres_img.ptr<uchar>(i)[x] != 0 && i > 0 ; i--){
        Up_loc = i;
    }

    Location.x = Left_loc;
    Location.y = Up_loc;
    Location.width = Right_loc - Left_loc;
    Location.height = Down_loc - Up_loc  ;

    if(Location.x-5 >0 && Location.width+10 < thres_img.cols ){
        Location.x-=5;
        Location.width+=10;
    }


    return Location;
}

cv::Mat Barcode_Locator::DrawBarLoc(cv::Mat img_input){
    img_input.copyTo(this->img);

    cv::Mat grad_x , grad_y;
    cv::Mat abs_grad_x , abs_grad_y;

    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

//---------------------------------Gradient Calculation------------------------------------
    cv::cvtColor(this->img,this->img_gray,CV_BGR2GRAY);
    cv::GaussianBlur( this->img_gray, this->img_gray, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );

#pragma omp parallel sections
{
    #pragma omp section
    {
            /// Gradient X
            cv::Sobel( this->img_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
            cv::convertScaleAbs(grad_x , abs_grad_x);
    }
    #pragma omp section

    {
            /// Gradient Y
            cv::Sobel( this->img_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
            cv::convertScaleAbs(grad_y , abs_grad_y);
    }
}
//--------------------------------Gradient difference between x and y-------------------
    cv::Mat grad_diff;
    grad_diff = cv::abs(abs_grad_x) - cv::abs(abs_grad_y);
    //region normalization
    cv::blur(grad_diff,this->img_smooth,cv::Size(31,31),cv::Point(-1,-1));
    //find the location of the max value
    double minval, maxval;
    cv::Point minloc, maxloc;
    cv::minMaxLoc(this->img_smooth, &minval, &maxval, &minloc, &maxloc);


    cv::Mat Result;

    if(maxval > 130.0){
        // thresholding by OTSU method
        cv::Mat thres;
        cv::threshold(this->img_smooth,thres,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);

        cv::Point MaxPoint;
        MaxPoint.x = maxloc.x;
        MaxPoint.y = maxloc.y;
        cv::Rect A = Crop( thres ,  MaxPoint );

        this->img.copyTo(Result);
        cv::rectangle(Result , A , cv::Scalar(255,0,0) );
    }
    return Result;
}

