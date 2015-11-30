#ifndef DECODE_H
#define DECODE_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
void decode(cv::Mat frame,int shift,int* Num);
int* decode2(cv::Mat Frame,int shift);
int findMax(int* num,int numsOfThing);
#endif // DECODE_H
