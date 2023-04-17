#pragma once
#include <iostream>
using namespace std;


const int MaxSize = 10;         // 图中最多顶点个数
int visited[MaxSize] = {0};     // 全局变量visited初始化

/*
    邻接矩阵使用顺序表，不用链接表
*/
template <typename DataType>
class MGraph
{
    public:
        MGraph(DataType a[], int n, int e);     // 构造函数
        ~MGraph();                              // 析构函数
        void DFTraverse(int v);                 // 深度优先遍历图
        void BFTraverse(int v);                 // 广度优先遍历图

    private:
        DataType vertex[MaxSize];          // 存放顶点的数组
        DataType edge[MaxSize][MaxSize];    // 存放图中边的邻接矩阵
        int vertexNum, edgeNum;            // 图的顶点数和边数

};
