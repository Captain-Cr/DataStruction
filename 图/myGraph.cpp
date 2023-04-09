#include "Graph.h"
#include <iostream>
#include "Graph.cpp"

using namespace std;

int main()
{
    int i;
    char ch[] = {'A','B','C','D','E'};        
    MGraph<char> MG{ch, 5, 6};          // 建立具有5个结点6条边的无向图

    for(int i = 0; i < 10; i++){
        visited[i] = 0;                 // 初始化遍历标志位
    }

    cout<<"深度优先遍历的序列是：";
    MG.DFTraverse(0);                   // 从顶点0出发进行深度优先遍历
    for(int i = 0; i < 10; i++)
    {
        visited[i] = 0;                    // 清除标志位
    }

    cout<<"广度优先遍历的序列是：";
    MG.BFTraverse(0);                   // 从顶点0出发进行广度优先遍历
    
    return 0;
}