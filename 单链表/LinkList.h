/*
    单链表（singly linked lis)是用一组任意的存储单元存放线性表的元素。
    包含数据元素的同时，也包含了后继元素所在的地址信息；这两个组成部分组成了数据元素的存储映像，称为结点（Node）
    其中，data为数据域，存放数据；next为指针域，存放该结点的后继结点地址。

    结点p由两个域组成：存放数据元素的数据域和存放后继结点地址的指针域，分别用（*p).data和（*p).next表示；
    或p->data,p->next表示。设指针p指向结点ai，则p->next指向结点a（i+1）

*/

#include <iostream>
using namespace std;

#ifndef __LINKLIST__H
#define __LINKLIST__H

// 结构体，Node结点
template<typename DataType>
struct Node
{
    DataType data;             // 数据域
    Node<DataType> *next;   // 指针域（下一个结点的指针，相当于Node *next）
};



// 将线性表的抽象数据类型定义在单链表存储结构下用类实现
template<typename DataType>
class LinkList
{
    public:
        LinkList();                         // 建立只有头结点的空链表
        LinkList(DataType a[],int n);       // 建立n个元素的单链表
        ~LinkList();                        // 析构函数
        int Length();                       // 求单链表的长度
        DataType Get(int i);                // 按位查找，查找第i个结点的元素值
        int Locate(DataType x);             // 按值查找，查找值为x的元素序号
        void Insert(int i,DataType x);      // 插入操作，在第i个位置插入值为x的结点
        DataType Delete(int i);             // 删除操作，删除第i个结点
        int Empty();                        // 判断是否为空
        void PrintList();                   // 遍历操作，按序号依次输出各元素

    private:
        Node<DataType> *first;              // 单链表的头指针
          
};

#endif