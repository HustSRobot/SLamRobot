#include <stack>
#include <iostream>
#include"identification.h"
#include"ground.h"

using namespace std;
using namespace cv;

#define  NUM 16
#define MAX_PATH 250
struct NODE
{
    int key;
    int flag;
    NODE()
    {
        flag=0;
    }
};

class Graph
{
public:
    //stack<int> searchStack;
    int resultPath[MAX_PATH][NUM];
    int result[NUM+2];//将result设为NUM+1，主要是为了避免发生B->D->B的事情
    vector<vector<int>>finalPath;
    vector<int>bestPath;

    NODE headNode;//起始节点
    NODE endNode;//终止节点
    stack<NODE> tempStack;
    int pathNum;
    int nPos;
    bool Mark[NUM];

public:
    Graph();

    void Reset();

    void FindBestPath(int redlight_pt1,int redlight_pt2);

    void FindFinalPath(int car_pt,int bluelight_pt);

    /**
     * @brief GetBestPath
     * We can get the shortest path to approching the 1s. 2d. bluelight while avoid crashing to the 1s. 2d. redlight by this function.
     * @param car_pt
     * @param blue_pt1
     * @param blue_pt2
     * @param red_pt1
     * @param red_pt2
     * @return
     */
    vector<int> GetBestPath(int car_pt,int blue_pt1,int blue_pt2,int red_pt1,int red_pt2);

    void FindAllPath(int Matrix[NUM][NUM],NODE startNodeKey,NODE endNodeKey);

};

