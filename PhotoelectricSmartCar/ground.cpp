#include"ground.h"

using namespace cv;
using namespace std;

const float kWidthOfCar = 31;
const float kLengthOfCar =21.5;
const float kSideOfGround = 0.5;
const int kLenthOfGround = 25;
const int kGainOfGround = 10;
const int kSizeOfLight = 3;
const Scalar kColorOfSide(0,0,0);
const Scalar kColorOfGround(255,255,255);
const Scalar kColorOfCar(106,32,240);
const Scalar kColorOfCenter(144,238,144);
const Scalar kColorOfHead(144,10,144);
const Scalar kColorOfRedLight(0,0,255);
const Scalar kColorOfBlueLight(255,0,0);
const char *kNameOfGroundWindow = "Ground";

Mat g_ground_img(4*kLenthOfGround*kGainOfGround,4*kLenthOfGround*kGainOfGround,CV_8UC3,kColorOfGround);

bool g_is_right = true;


/**
 * @brief DrawGround: draw the ground
 * @param Mat src : the input image
 */
void DrawGround(Mat src)
{
    Point begin_pt(0,0);
    Point end_pt(0,4*kLenthOfGround*kGainOfGround);

    for(int cols=0;cols<4;cols++)
    {
        line(src,begin_pt,end_pt, kColorOfSide, kSideOfGround);
        begin_pt.x+=kGainOfGround*kLenthOfGround;
        end_pt.x+=kGainOfGround*kLenthOfGround;
    }

    begin_pt.x=0;
    begin_pt.y=0;
    end_pt.x=4*kLenthOfGround*kGainOfGround;
    end_pt.y=0;
    for(int rows=0;rows<4;rows++)
    {
        line(src,begin_pt,end_pt, kColorOfSide, kSideOfGround);
        begin_pt.y+=kGainOfGround*kLenthOfGround;
        end_pt.y+=kGainOfGround*kLenthOfGround;
    }
}

/**
 * @brief DrawCar
 * @param src
 * @param car_center_pt
 * @param is_vertical_flag
 */
void DrawCar(Mat src,Point car_center_pt,int is_vertical_flag)
{
    Rect car_station,car_head;
    switch (is_vertical_flag) {
    case MyCar.ANGULAR_0:
    {
        car_station.x=car_center_pt.x-kGainOfGround*kWidthOfCar/2;
        car_station.y=car_center_pt.y-kGainOfGround*kLengthOfCar/2;
        car_station.width=kGainOfGround*kWidthOfCar;
        car_station.height=kGainOfGround*kLengthOfCar;

        rectangle(src,car_station,kColorOfCar,CV_FILLED);

        circle(src,car_center_pt,kSizeOfLight*kGainOfGround,kColorOfCenter,CV_FILLED);

        car_head.x=car_center_pt.x-kGainOfGround*kWidthOfCar*0.2;
        car_head.y=car_center_pt.y+kGainOfGround*kLengthOfCar*0.4;
        car_head.width=kGainOfGround*kWidthOfCar*0.4;
        car_head.height=kGainOfGround*kLengthOfCar*0.1;

        rectangle(src,car_head,kColorOfHead,CV_FILLED);
        break;
    }
    case MyCar.ANGULAR_90:
    {
        car_station.y=car_center_pt.y-kGainOfGround*kWidthOfCar/2;
        car_station.x=car_center_pt.x-kGainOfGround*kLengthOfCar/2;
        car_station.height=kGainOfGround*kWidthOfCar;
        car_station.width=kGainOfGround*kLengthOfCar;

        rectangle(src,car_station,kColorOfCar,CV_FILLED);

        circle(src,car_center_pt,kSizeOfLight*kGainOfGround,kColorOfCenter,CV_FILLED);

        car_head.y=car_center_pt.y-kGainOfGround*kWidthOfCar*0.2;
        car_head.x=car_center_pt.x+kGainOfGround*kLengthOfCar*0.4;
        car_head.height=kGainOfGround*kWidthOfCar*0.4;
        car_head.width=kGainOfGround*kLengthOfCar*0.1;

        rectangle(src,car_head,kColorOfHead,CV_FILLED);
        break;
    }
    case MyCar.ANGULAR_180:
    {
        car_station.x=car_center_pt.x-kGainOfGround*kWidthOfCar/2;
        car_station.y=car_center_pt.y-kGainOfGround*kLengthOfCar/2;
        car_station.width=kGainOfGround*kWidthOfCar;
        car_station.height=kGainOfGround*kLengthOfCar;

        rectangle(src,car_station,kColorOfCar,CV_FILLED);

        circle(src,car_center_pt,kSizeOfLight*kGainOfGround,kColorOfCenter,CV_FILLED);

        car_head.x=car_center_pt.x-kGainOfGround*kWidthOfCar*0.2;
        car_head.y=car_center_pt.y-kGainOfGround*kLengthOfCar*0.5;
        car_head.width=kGainOfGround*kWidthOfCar*0.4;
        car_head.height=kGainOfGround*kLengthOfCar*0.1;

        rectangle(src,car_head,kColorOfHead,CV_FILLED);
        break;
    }
    case MyCar.ANGULAR_270:
    {;
        car_station.y=car_center_pt.y-kGainOfGround*kWidthOfCar/2;
        car_station.x=car_center_pt.x-kGainOfGround*kLengthOfCar/2;
        car_station.height=kGainOfGround*kWidthOfCar;
        car_station.width=kGainOfGround*kLengthOfCar;

        rectangle(src,car_station,kColorOfCar,CV_FILLED);

        circle(src,car_center_pt,kSizeOfLight*kGainOfGround,kColorOfCenter,CV_FILLED);

        car_head.y=car_center_pt.y-kGainOfGround*kWidthOfCar*0.2;
        car_head.x=car_center_pt.x-kGainOfGround*kLengthOfCar*0.5;
        car_head.height=kGainOfGround*kWidthOfCar*0.4;
        car_head.width=kGainOfGround*kLengthOfCar*0.1;

        rectangle(src,car_head,kColorOfHead,CV_FILLED);
        break;
    }
    default:
        break;
    }
    if(car_head.x<-kGainOfGround*kWidthOfCar*0.15\
            ||car_head.y<-kGainOfGround*kWidthOfCar*0.15\
            ||car_station.x<-kGainOfGround*kWidthOfCar*0.15\
            ||car_station.y<-kGainOfGround*kWidthOfCar*0.15)
    {
        cout<<"the car is out of the ground!"<<endl;
        g_is_right=false;
    }
    else
    {
        g_is_right=true;
    }
}
/**
 * @brief PlaceRedLight
 * @param src
 * @param gridnum
 * *****************************
 * ****1******2******3*****4****
 * ****5******6******7*****8****
 * ****9*****10*****11****12****
 * ****13****14*****15****16****
 * *****************************
 */
void PlaceRedLight(Mat src,int gridnum)
{
    Point pt;
    pt.x=(gridnum-1)%4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    pt.y=(gridnum-1)/4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    circle(src,pt,kSizeOfLight*kGainOfGround,kColorOfRedLight,CV_FILLED);
}

/**
 * @brief PlaceRedLight
 * @param src
 * @param gridnum
 * *****************************
 * ****1******2******3*****4****
 * ****5******6******7*****8****
 * ****9*****10*****11****12****
 * ****13****14*****15****16****
 * *****************************
 */
void PlaceBlueLight(Mat src,int gridnum)
{
    Point pt;
    pt.x=(gridnum-1)%4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    pt.y=(gridnum-1)/4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    circle(src,pt,kSizeOfLight*kGainOfGround,kColorOfBlueLight,CV_FILLED);
}

/**
 * @brief InitGround
 * @param red_gridnum1
 * @param red_gridnum2
 * @param blue_gridnum1
 * @param blue_gridnum2
 */
void InitGround(int car_gridnum,int blue_gridnum1,int blue_gridnum2,int red_gridnum1,int red_gridnum2)
{
   // Mat ground_img;
   //namedWindow(kNameOfGroundWindow);
    DrawGround(g_ground_img);
    //g_ground_img.copyTo(ground_img);
    PlaceRedLight(g_ground_img,red_gridnum1);
    PlaceRedLight(g_ground_img,red_gridnum2);
    PlaceBlueLight(g_ground_img,blue_gridnum1);
    PlaceBlueLight(g_ground_img,blue_gridnum2);


    MyCar.car_center.x =(car_gridnum-1)%4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    MyCar.car_center.y =(car_gridnum-1)/4 * kLenthOfGround*kGainOfGround+kLenthOfGround*kGainOfGround/2;
    //imshow(kNameOfGroundWindow,g_ground_img);
}


/**
 * @brief MoveCar
 */
void MoveCar(const Point pt=MyCar.car_center,int direction = MyCar.car_direction)
{
    Mat ground_car_img;
    namedWindow(kNameOfGroundWindow);
    g_ground_img.copyTo(ground_car_img);
    MyCar.car_center=pt;
    DrawCar(ground_car_img,pt,direction);
    imshow(kNameOfGroundWindow,ground_car_img);
}
/**
 * @brief GoForward
 * @param distances
 */
void GoForward(int distances)
{
    switch (MyCar.car_direction) {
    case MyCar.ANGULAR_0:
        MyCar.car_center.y+=distances;
        break;
    case MyCar.ANGULAR_90:
        MyCar.car_center.x+=distances;
        break;
    case MyCar.ANGULAR_180:
        MyCar.car_center.y-=distances;
        break;
    case MyCar.ANGULAR_270:
        MyCar.car_center.x-=distances;
        break;
    default:
        break;
    }
    MoveCar();
}

/**
 * @brief TurnAround
 * @param direction
 */
void TurnAround(int direction)
{
    MyCar.car_direction=direction;
    MoveCar();
}



void Test()
{
    InitGround(8,3,5,10,2);
    MyCar.car_center.x =200;
    MyCar.car_center.y =200;
    MyCar.car_direction=MyCar.ANGULAR_0;MoveCar();
    for(int times=1;times<=4;times++)
    {
        waitKey(0);
        TurnAround(times);
        MoveCar();

    }waitKey(0);
}


