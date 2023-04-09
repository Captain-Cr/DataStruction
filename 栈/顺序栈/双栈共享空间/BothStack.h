#ifndef BOTHSTACK_H
#define BOTHSTACK_H

#include<iostream>
using namespace std;


const int StackSize = 100;          // 顺序栈的空间大小
template<typename DataType>
class BothStack
{
    public:
        BothStack();                // 构造函数，将两个栈初始化
        ~BothStack();               // 析构函数
        void push(int i, DataType x);       // 入栈操作，将元素压入栈i
        DataType Pop(int i);        // 出栈操作，对栈i执行出栈操作
        DataType GetTop(int i);     // 取栈i的栈顶元素
        int Empty(int i);           // 判断栈i是否为空

    private:
        DataType data[StackSize];       // 存放两个栈的数组
        int top1, top2;                 // 两个栈的栈顶指针，分别为各自栈顶元素在数组中的下标
};




#endif