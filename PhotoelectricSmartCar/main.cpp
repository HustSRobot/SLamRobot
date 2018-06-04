#include"iostream"
#include"ground.h"
#include"route.h"
#include"action.h"

using namespace std;
using namespace cv;

int main()
{
    MyCar.car_direction=MyCar.ANGULAR_90;
    MyCar.car_grid=16;
    Graph graph;
    vector<int>path;
    InitGround(MyCar.car_grid,g_blue_pt1,g_blue_pt2,g_red_pt1,g_red_pt2);
    path=graph.GetBestPath(MyCar.car_grid,g_blue_pt1,g_blue_pt2,g_red_pt1,g_red_pt2);
    GoAlongBestPath(path);
    waitKey(0);

    return 0;
}
