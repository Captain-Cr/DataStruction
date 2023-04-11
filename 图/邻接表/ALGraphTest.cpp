#include <iostream>
#include "ALGraph.h"
#include "ALGraph.cpp"

using namespace std;


int main(int argc, char* argv[])
{
    char ch[] = {'A','B','C','D','E'};
    int i;
    ALGraph<char> ALG{ch, 5,  6};               // 建立具有5个顶点6条边的有向图
    for(i = 0; i < Maxsize; i++)
    {
        visited[i] = 0;                         // 初始化visited数组
    }
    cout<<"深度优先遍历序列是：";
    ALG.DFTraverse(0);
    for(i = 0; i < Maxsize; i++)
    {
        visited[i] = 0;                         // 重置visited数组
    }
    cout<<"广度优先遍历序列是：";
    ALG.BFTraverse(0);
    cout<<"test"<<endl;



}

