/*
    队列的链接存储结构。（linked queue），通常用单链表表示。

    为了使空队列和非空队列的操作一致，链队列也加上头结点。根据队列先入先出的特性，设置头指针front指向头结点， 队尾指针rear指向终端节点 nullptr

    链队列基本操作的实现本质上使单链表操作的简化，且时间复杂度均为O(1)

*/
#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include <iostream>
#include <vector>

using namespace std;


// 定义结点
template<typename DataType>
struct Node
{
    DataType data;          // 结点的值
    Node<DataType> *next = nullptr;   // 下一个结点的地址  
};





template<typename DataType>
class LinkQueue
{
    public:
        LinkQueue();                    // 初始化空的链队列
        ~LinkQueue();                   // 析构函数
        void EnQueue(DataType x);       // 入队操作， 将元素x入队
        DataType DeQueue();             // 出队操作，将队头元素出队
        DataType GetHead();             // 获取队头元素，但不改变队头
        int Empty();                    // 判断队头是否为空



    private:
        Node<DataType> *front, *rear;         // 队头和队尾指针 

};



#endif
