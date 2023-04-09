#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <iostream>
using namespace std;

const int StackSize = 10;       // 定义栈的大小
template<typename DataType>         // 定义模板类SeqStack
class SeqStack
{
    public:
        SeqStack();                 // 构造函数，初始化一个空栈
        ~SeqStack();                // 析构函数
        void Push(DataType x);      // 入栈操作， 将元素x入栈
        DataType Pop();             // 出栈操作，将栈顶元素弹出
        DataType GetTop();          // 获取栈顶元素（并不删除）
        int Empty();                // 判断栈是否为空

    private:
        DataType data[StackSize];       //存放栈元素的数组
        int top;                        // 栈顶元素在数组的下标

};





#endif