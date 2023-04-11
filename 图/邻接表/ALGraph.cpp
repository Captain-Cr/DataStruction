#include "ALGraph.h"
#include <iostream>

/*
    邻接表（adjacency list)是一种顺序存储和链接存储相结合的存储方法，类似于树的孩子表示法。

*/


/*
    1、图的构建（例子为书本图6-13的图）
    输入：顶点的数据信息a[]，顶点的个数，边的个数
    输出：图的邻接表
        1.1 存储图的顶点个数和边个数
        1.2 将顶点信息存储在顶点表中，将该顶点边表的头指针初始化为NULL
        1.3 依次输入边的信息并存储在边表中
            1.3.1 输入边表所依附的两个顶点的编号i和j
            1.3.2 生成边表结点s，其邻接点的编号为j
            1.3.3 将结点s插入到第i个边表的表头
*/
template<typename DataType>
ALGraph<DataType>::ALGraph(DataType *a, int n, int e)
{
     // 无向图输入边的数量是有相图边长的两倍的2倍（下面是关于有向图的构建）
     vertexNum = n; edgeNum = e;
     int i, j, k;        // i是顶点表中的顶点；j是边表中的顶点；k是边的数量
     // 将顶点信息写入到顶点表当中，并让顶点表的firstedge为nullptr初始化
    for(i = 0; i < vertexNum; i++)
    {
        adjlist[i].vertex = a[i];
        adjlist[i].firstEdge = nullptr;
    }

    // 创建边表指针
    EdgeNode* s = nullptr;
    // 遍历每条边，并将边表插入到顶点表的firstEdge中
    for(k = 0; k < edgeNum; k++)
    {
        std::cout<<"请输入一条边的两个顶点i和j"<<std::endl;
        std::cin>>i>>j;             // i是顶点表的顶点索引，j是边表中的顶点索引
        s = new EdgeNode();     // 创建边表结点指针
        s->adjvex = j;
        s->next = adjlist[i].firstEdge;
        adjlist[i].firstEdge = s;       // 让顶点表结点的firstEdge指向创建的边表    
    }

}


/*
    析构函数
    在图的邻接表中，边表结点是程序运行过程中申请的，因此需要释放所有边表结点的存储空间。
*/
 template<typename DataType>
 ALGraph<DataType>::~ALGraph()
 {
    // 创建两个指针，指向边表
    EdgeNode *p = nullptr;
    EdgeNode *q = nullptr;

    // 遍历所有顶点
    for(int i = 0; i < vertexNum; i++)
    {
        // 首先让p和q指向都指向第一个边表结点
        p = q = adjlist[i].firstEdge;
        // 当边表存在时，让p指针指向下一个结点，q指针指向当前结点
        while(p != nullptr)
        {
            p = p->next;
            //删除当前结点
            delete q;
            q = p;
        }
    }     

}

/*
    深度优先遍历
    根据邻接表获取每个顶点的邻接点，然后使用递归遍历
*/
template<typename DataType>
void ALGraph<DataType>::DFTraverse(int v)
{
    // 访问顶点的数据
    std::cout<<adjlist[v].vertex<<std::endl;
    visited[v] = 1;         // 表示该顶点已经访问过了

    EdgeNode* p = nullptr;
    // 遍历第v个顶点，获取与v顶点的边表
    p = adjlist[v].firstEdge;
    // 当顶点v的边表存在，则用递归访问深度顶点
    while(p != nullptr)
    {
        int index = p->adjvex;      // 边表顶点的索引
        if(visited[v] == 0)
        {
            DFTraverse(index);
        }
        p = p->next;
    }
    
}

/*
    广度优先遍历
    采用顺序队列，基本流程，访问顶点，将顶点入队；顶点出队，访问邻接点，将邻接点入队。
*/
template<typename DataType>
void ALGraph<DataType>::BFTraverse(int v)
{
    int j,w,Q[Maxsize];                     // 顺序队列
    int front = -1, rear = -1;          // 队列指针

    // 访问顶点
    std::cout<<adjlist[v].vertex<<std::endl;
    visited[v] = 1;
    // 将顶点入队
    Q[++rear] = v;
    // 创建边表指针
    EdgeNode* p = nullptr;
    while(front != rear)
    {
        w = Q[++front];             // 将顶点索引保存到w，并进行出队
        // 同时访问该顶点的邻接点
        p = adjlist[w].firstEdge;
        while(p != nullptr)
        {
            j = p->adjvex;      // p->adjvex是邻接点的索引
            // 如果邻接点未被访问
            if(visited[j] == 0)
            {
                // 访问邻接点
                std::cout<<adjlist[j].vertex<<std::endl;
                visited[j] = 1;
                // 将邻接点入队
                Q[++rear] = j;
            }
            // 访问下一个邻接点
            p = p->next;
        }
    }
}