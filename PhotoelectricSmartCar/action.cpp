#include"action.h"

using namespace std;
using namespace cv;

/**
 * @brief NodeToNode
 * You can drive your car from one node to another node by this function.
 * @param grid_num1 begin node
 * @param grid_num2 end node
 */
void NodeToNode(int grid_num1,int grid_num2)
{
    if((grid_num1-grid_num2)==-4)
        TurnAround(MyCar.ANGULAR_0);
    if((grid_num1-grid_num2)==-1)
        TurnAround(MyCar.ANGULAR_90);
    if((grid_num1-grid_num2)==4)
        TurnAround(MyCar.ANGULAR_180);
    if((grid_num1-grid_num2)==1)
        TurnAround(MyCar.ANGULAR_270);
    waitKey(100);
    GoForward(kLenthOfGround*kGainOfGround);
}

/**
 * @brief GoAlongBestPath
 * You can drive your car along one path by this function.
 * @param path : the path that you have got from the route.cpp
 */
void GoAlongBestPath(vector<int>path)
{
    for(unsigned int i=1;i<path.size();i++)
    {
        NodeToNode(path[i-1],path[i]);
        waitKey(100);

    }
}
