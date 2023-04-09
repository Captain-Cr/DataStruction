#include "BothStack.h"

template<typename DataType>
BothStack<DataType>::BothStack()
{
    // 构造函数, 让一个栈的栈顶位于数组始端， 另一个栈的栈底位于数组末端
    top1 = -1;
    top2 = StackSize;
}


template<typename DataType>
BothStack<DataType>::~BothStack()
{

}


template<typename DataType>
void BothStack<DataType>::push(int i, DataType x)
{
    // 入栈操作，将元素x压入栈i
    if(top1 == top2 -1) throw"上溢";            // 判断是否栈满
    if(i == 1)  data[++top1] = x;               // 在栈1插入
    if(i == 2)  data[--top2] = x;               // 在栈2插入
}


template<typename DataType>
DataType BothStack<DataType>::Pop(int i)
{
    // 出栈操作
    if(i == 1)
    {
        // 在栈1进行出栈
        if(top1 == -1)  throw"下溢";        // 判断是否栈空      
        return data[top1--];                 // 出栈
    }

    if(i == 2)
    {
        // 在栈2进行出栈
        if(top1 == StackSize)  throw"下溢";        // 判断是否栈空      
        return data[top2++];                 // 出栈
    }
}



template<typename DataType>
DataType BothStack<DataType>::GetTop(int i)
{
    // 获取栈顶元素
    if(i == 1)
    {
        return data[top1];
    }

    if(i == 2)
    {
        return data[top2];
    }
}


template<typename DataType>
int BothStack<DataType>::Empty(int i)
{
    // 判断栈是否为空
    if(i==1)
    {
        if(top1 == -1)
        {
            cout<<"栈1为空"<<endl;
            return 1;
        }
        else
        {
            cout<<"栈1不为空"<<endl;
            return 0;
        }
    }

    if(i==2)
    {
        if(top1 == StackSize)
        {
            cout<<"栈2为空"<<endl;
             return 1;
        }
        else
        {
            cout<<"栈2不为空"<<endl;
            return 0;
        }
    }
}