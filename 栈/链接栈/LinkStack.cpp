#include "LinkStack.h"


template<typename DataType>
LinkStack<DataType>::LinkStack()
{
    // 构造函数, 链栈不带头结点，所以初始化一个空链栈只需将栈顶指针top置空
    top = nullptr;     
}



template<typename DataType>
LinkStack<DataType>::~LinkStack()
{
    // 析构函数， 从栈顶元素开始删除
    while(top != nullptr)
    {
        Node<DataType> *p=nullptr;
        p = top;
        top = p->next;
        delete p;
        cout<<"析构完成"<<endl;
    }
}



template<typename DataType>
void LinkStack<DataType>::push(DataType x)
{
    // 入栈操作, top指针的next指针域指向入栈结点的地址
    Node<DataType> *s = new Node<DataType>;         // 新建一个结点
    s->data = x;                    // 给结点赋值
    s->next = top;   top = s;       // 将结点s插在栈顶

}



template<typename DataType>
DataType LinkStack<DataType>::Pop()
{
    // 出栈操作，只需处理栈顶情况
    Node<DataType> *p = nullptr;        // 用来暂存结点
    DataType x;                         // 用来接收栈顶元素
    if(top == nullptr)  throw"下溢";
    x = top->data;                      // 获取栈顶元素
    p = top;                            // 暂存栈顶元素
    top = p->next;                      // 将栈顶结点摘链，  让栈顶元素指向下一个
    delete p;
    return x;
}



template<typename DataType>
DataType LinkStack<DataType> :: GetTop()
{
    // 获取栈顶元素, 并不删除
    DataType x;
    if(top == nullptr) throw"下溢";
    x = top->data;
    return x;
}



template<typename DataType>
int LinkStack<DataType> :: Empty()
{
    // 判空操作， 如果为空返回1， 否则返回0
    if(top == nullptr)
    {
        cout<<"链栈为空"<<endl;
        return 1;
    }
    else
    {
        cout<<"链栈不为空"<<endl;
        return 0;
    }
}