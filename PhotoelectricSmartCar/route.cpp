#include"route.h"

using namespace std;

/**
 * @brief Graph::Graph
 */
Graph::Graph()
{
    //将矩阵中的元素置为空
    for (int i=0;i<NUM;i++)
    {
        for (int j=0;j<MAX_PATH;j++)
        {
            resultPath[i][j]=0;
        }
        result[i]=0;

        Mark[i]=false;
    }
    result[NUM]=0;
    pathNum=0;
    nPos=0;
}
/**
 * @brief Graph::FindFinalPath
 * @param car_pt
 * @param bluelight_pt
 */
void Graph::FindFinalPath(int car_pt,int bluelight_pt)
{
    int Matrix[NUM][NUM]={
        {0,1,0,0,
         1,0,0,0,
         0,0,0,0,
         0,0,0,0},//1
        {1,0,1,0,
         0,1,0,0,
         0,0,0,0,
         0,0,0,0},//2
        {0,1,0,1,
         0,0,1,0,
         0,0,0,0,
         0,0,0,0},//3
        {0,0,1,0,
         0,0,0,1,
         0,0,0,0,
         0,0,0,0},//4
        {1,0,0,0,
         0,1,0,0,
         1,0,0,0,
         0,0,0,0},//5
        {0,1,0,0,
         1,0,1,0,
         0,1,0,0,
         0,0,0,0},//6
        {0,0,1,0,
         0,1,0,1,
         0,0,1,0,
         0,0,0,0},//7
        {0,0,0,1,
         0,0,1,0,
         0,0,0,1,
         0,0,0,0},//8
        {0,0,0,0,
         1,0,0,0,
         0,1,0,0,
         1,0,0,0},//9
        {0,0,0,0,
         0,1,0,0,
         1,0,1,0,
         0,1,0,0},//10
        {0,0,0,0,
         0,0,1,0,
         0,1,0,1,
         0,0,1,0},//11
        {0,0,0,0,
         0,0,0,1,
         0,0,1,0,
         0,0,0,1},//12
        {0,0,0,0,
         0,0,0,0,
         1,0,0,0,
         0,1,0,0},//13
        {0,0,0,0,
         0,0,0,0,
         0,1,0,0,
         1,0,1,0},//14
        {0,0,0,0,
         0,0,0,0,
         0,0,1,0,
         0,1,0,1},//15
        {0,0,0,0,
         0,0,0,0,
         0,0,0,1,
         0,0,1,0},//16

    };
    //开始节点
    headNode.key=car_pt;
    headNode.flag=1;

    //结束节点
    endNode.key=bluelight_pt;

    FindAllPath(Matrix,headNode,endNode);
    //cout<<"路径数目为："<<pathNum<<endl;
    for (int i=0;i<pathNum;i++)
    {
        vector<int>pathTemp;
        //cout<<"第"<<i<<"条: ";
        for(int j=0;j<NUM;j++)
        {
            if (resultPath[i][j]<=0||resultPath[i][j]>16)
            {
                finalPath.push_back(pathTemp);
                pathTemp.clear();
                break;
            }
            pathTemp.push_back(resultPath[i][j]);
           // cout<<resultPath[i][j]<<"  ";
        }
       // cout<<endl;
    }
}

/************************************************************************
 函数功能：找到图中两个节点之间的所有路径
参数说明：1、Matrix   初始矩阵，将路径矩阵的形式存储，本程序对应的是一个无向图。
         2、headNode 初始节点
         3、endNode  结束节点

主要的思想  利用深度优先遍历的算法
1、利用result来存放每次从栈中出栈的数据，里面很可能就是要找的路径，为什么要单独提取出来，因为包含了多条路径
2、通过设置 访问是否的变量来避免回路
************************************************************************/
void Graph::FindAllPath(int Matrix[NUM][NUM],NODE startNodeKey,NODE endNodeKey)
{
    result[nPos]=startNodeKey.key;  //将当前元素放入结果集中
    Mark[startNodeKey.key-1]=true;  //将访问标记为已访问
    nPos++;  //结果集索引加1
    while(nPos!=0)
    {
        int tempVal=result[nPos-1];//获取到最前面的元素
        if (tempVal==endNodeKey.key)  //若当前元素为目标节点
        {
            for (int j=0;j<nPos;j++)
            {
                resultPath[pathNum][j]=result[j];  //将结果集复制于最后的路径矩阵中
            }
            nPos--;  //回溯至上一个节点
            result[nPos]=0;  //结果集对应索引置为空
            pathNum++;  //路径数目加1
            Mark[endNodeKey.key-1]=false;
            break;
        }
        while(startNodeKey.flag<NUM)//利用flag来指示每次的元素的索引
        {
            if (Matrix[tempVal-1][startNodeKey.flag]==1)
            {
                if (Mark[startNodeKey.flag]==false)//利用Mark来判断是否已经访问过该节点
                {
                    NODE tempNode;
                    tempNode.key=startNodeKey.flag+1;
                    FindAllPath(Matrix,tempNode,endNodeKey);//深度优先遍历算法，
                }
            }
            startNodeKey.flag++;//索引值相应的加一
        }

        if (startNodeKey.flag==NUM)//如果已经是到最后的邻居，说明访问结束，
        {                           //将对应的值置为空
            nPos--;  //再次向上回溯
            startNodeKey.flag=0;  //将节点的索引置为空
            result[nPos]=0;  //将结果集中对应的索引置为空
            Mark[startNodeKey.key-1]=false;  //访问之后标记为未访问。因为下面的元素已经访问结束，便于下次的访问
            break;
        }
    }
}
/**
 * @brief Graph::FindBestPath
 * @param redlight_pt1
 * @param redlight_pt2
 */
void Graph::FindBestPath(int redlight_pt1,int redlight_pt2)
{
    int index = 0;
    unsigned int leastPath = 150;
    int is_crash = 0;
    for(unsigned i=0;i<finalPath.size();i++)
    {
        for(unsigned j=0;j<(finalPath[i]).size();j++)
        {
            if((finalPath[i][j]==redlight_pt1)||(finalPath[i][j]==redlight_pt2))
            {
                is_crash=1;
                break;
            }
            is_crash=0;
        }
        if(((finalPath[i]).size()<leastPath) && (is_crash==0))
        {
            leastPath = (finalPath[i]).size();
            index=i;
        }
    }
    bestPath = finalPath[index];
}
/**
 * @brief Graph::Reset
 */
void Graph::Reset()
{
    for (int i=0;i<NUM;i++)
    {
        for (int j=0;j<MAX_PATH;j++)
        {
            resultPath[i][j]=0;
        }
        result[i]=0;

        Mark[i]=false;
    }
    result[NUM]=0;
    pathNum=0;
    nPos=0;
    finalPath.clear();
    bestPath.clear();
}
/**
 * @brief Graph::GetBestPath
 * @param car_pt
 * @param blue_pt1
 * @param blue_pt2
 * @param red_pt1
 * @param red_pt2
 * @return
 */
vector<int> Graph::GetBestPath(int car_pt,int blue_pt1,int blue_pt2,int red_pt1,int red_pt2)
{
    vector<int>path1,path2,path3;

    FindFinalPath(car_pt,blue_pt1);
    FindBestPath(red_pt1,red_pt2);
    path1=bestPath;
    Reset();

    FindFinalPath(car_pt,blue_pt2);
    FindBestPath(red_pt1,red_pt2);
    path2=bestPath;
    Reset();

    if(path1.size()<=path2.size())
    {
        FindFinalPath(blue_pt1,blue_pt2);
        FindBestPath(red_pt1,red_pt2);
        path3=bestPath;
        Reset();
        path1.insert(path1.end(),path3.begin()+1,path3.end());
        cout<<"Final Path is:";
        for(unsigned int i=0;i<path1.size();i++)
        {
            cout<<path1[i]<<',';
        }
        cout<<endl;
        return path1;
    }

    else
    {
        FindFinalPath(blue_pt2,blue_pt1);
        FindBestPath(red_pt1,red_pt2);
        path3=bestPath;
        Reset();
        path2.insert(path2.end(),path3.begin()+1,path3.end());
        cout<<"Final Path is:";
        for(unsigned int i=0;i<path2.size();i++)
        {
            cout<<path2[i]<<',';
        }
        cout<<endl;
        return path2;
    }

}

