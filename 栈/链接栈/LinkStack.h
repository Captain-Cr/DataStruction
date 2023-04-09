#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>
using namespace std;


// 结点结构
template<typename DataType>
struct Node
{
    DataType data;          // 用来存放数据的数据域
    Node<DataType> *next;   // 下一个结点的指针
};





template<typename DataType>
class LinkStack
{
    public:
        LinkStack();                    // 构造函数，初始化一个空的链栈
        ~LinkStack();                   // 析构函数，释放链栈各结点的存储空间
        void push(DataType x);          // 入栈操作，将元素x入栈
        DataType Pop();                 // 出栈操作，将栈顶元素出栈
        DataType GetTop();              // 获取栈顶元素， 并不删除
        int Empty();                    // 判断栈是否为空

    private:
        Node<DataType> *top;             // 栈顶指针即链栈指针 

};




#endif