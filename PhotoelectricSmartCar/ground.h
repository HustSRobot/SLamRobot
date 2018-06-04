#pragma once
#include "opencv/cv.hpp"
#include"opencv2/opencv.hpp"
using namespace cv;

struct {
    enum{
        ANGULAR_0 = 1,
        ANGULAR_90,
        ANGULAR_180,
        ANGULAR_270
    };
    Point car_center;
    int car_direction;
    int car_grid;
}MyCar;



extern const int kLenthOfGround ;
extern const int kGainOfGround ;



void DrawGroundAndCar(Point center,int flag);

void Test();

void GoForward(int distances);

void TurnAround(int direction);

void InitGround(int car_gridnum,int blue_gridnum1, int blue_gridnum2, int red_gridnum1, int red_gridnum2);




extern Mat g_ground_img;

extern bool g_is_right;
