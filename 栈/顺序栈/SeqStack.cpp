#include "SeqStack.h"



template<typename DataType>
SeqStack<DataType> :: SeqStack()
{
    // 顺序栈初始化，只需让栈顶为-1
    top = -1;
}


template<typename DataType>
SeqStack<DataType>:: ~SeqStack()
{
    // 析构函数
}


template<typename DataType>
void SeqStack<DataType>::Push(DataType x)
{
    // 入栈操作，让top指针加1，并添加相应元素x
    if(top ==  StackSize-1)  throw"上溢";
    data[++top] = x;
}


template<typename DataType>
DataType SeqStack<DataType>::Pop()
{
    // 出栈操作，取出栈顶元素， 让top减1
    DataType x;
    if(top == -1)  throw"下溢";
    x = data[top--];
    return x;
}


template<typename DataType>
DataType SeqStack<DataType>::GetTop()
{
    // 取栈顶元素， 并不删除
    if(top == -1) throw"下溢";
    DataType x;
    x = data[top];
    return x;
}


template<typename DataType>
int SeqStack<DataType>::Empty()
{
    // 判断是否为空
    if(top == -1)
    {
        cout<<"顺序栈为空"<<endl;
        return 1;
    }
    else
    {
        cout<<"顺序栈不为空"<<endl;
        return 0;
    }
}