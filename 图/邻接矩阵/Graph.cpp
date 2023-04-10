#include "Graph.h"
#include <iostream>
using namespace std;

template <typename DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
    // 构造函数
    // 顶点的数据信息a[], 顶点个数n， 边的个数e
    this->vertexNum = n;           // 顶点个数
    this->edgeNum = e;              // 边的个数

    // 存储顶点
    for(int i = 0; i < vertexNum; i++){
        vertex[i] = a[i];
    } 

    // 初始化邻接矩阵
    for(int i = 0; i < vertexNum; i++){
        for(int j = 0; j < vertexNum; j++){
            edge[i][j] = 0;
        }
    }

    // 一次输入每一条边
    for(int k = 0; k < edgeNum; k++){
        int a, b;
        cin>>a>>b;      // 输入边依附的两个顶点的编号
        edge[a][b] = 1, edge[b][a] = 1;     // 无向图，且同向两个顶点最多有1个边
    }
}


template<typename DataType>
MGraph<DataType>::~MGraph()
{
    // 析构函数
}


template<typename DataType>
void MGraph<DataType>::DFTraverse(int v){
    // 深度优先遍历
    // 类似树的前序遍历，先输出v顶点，然后向左遍历到最底层，再向右遍历到最底层
    cout<< this->vertex[v];         // 输出顶点
    visited[v] = 1;                 // 遍历标志位，为1表示已经遍历过了
    for(int j = 0; j < vertexNum; j++){
        if(edge[v][j] == 1 && visited[j] == 0)      // 如果两个顶点之间存在边和标志位没有被访问，则进行递归遍历
            DFTraverse(j);
    }
    
}



template<typename DataType>
void MGraph<DataType>::BFTraverse(int v){
    // 广度优先遍历
    // 类似于树的层序遍历
    int w, j, Q[MaxSize];                // 采用顺序队列
    int front = -1, rear = -1;
    cout<<vertex[v];                     // 输出顶点
    visited[v] = 1;                      // 遍历标志位，为1表示已经遍历过了
    Q[++rear] = v;                       // 被访问顶点入队

    while(front != rear){                // 当队列不为空
        w = Q[++front];                 // 将队头元素出队并送到w中
        // 输出与该顶点所有有相接的顶点，并且是没有访问过的
        for(j = 0; j < vertexNum; j++)  // 遍历所有的顶点
        {
            if(edge[w][j] == 1 && visited[j] == 0){     // 如果顶点w有邻接边，并且访问标志位为0（未访问）的节点j
                cout<<vertex[j];                    // 输出该顶点j
                visited[j] = 1;                     // 表示已经遍历过了
                Q[++rear] = j;                      // 并将与之相邻的所有节点进行入队
            }
        }


   }
}