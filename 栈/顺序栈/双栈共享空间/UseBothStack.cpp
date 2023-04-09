#include "BothStack.h"
#include "BothStack.cpp"



int main()
{
    int x;
    BothStack<int> s;       // 定义两栈变量
    int empty = s.Empty(1); // 判空

    cout<<"对10和15入栈操作（栈1）"<<endl;
    s.push(1,10);
    s.push(1,15);
    cout<<"栈1的栈顶元素为："<<s.GetTop(1)<<endl;       // 栈顶为15
    cout<<"栈1出栈元素为："<<s.Pop(1)<<endl;
    cout<<"栈1的栈顶元素为："<<s.GetTop(1)<<endl;       // 栈顶为10


    cout<<"-----------------------------"<<endl;
    cout<<"对20和25入栈操作（栈2）"<<endl;
    s.push(2, 20);
    s.push(2, 25);
    cout<<"栈2的栈顶元素为："<<s.GetTop(2)<<endl;       // 栈顶为25
    cout<<"栈2出栈元素为："<<s.Pop(2)<<endl;
    cout<<"栈2的栈顶元素为："<<s.GetTop(2)<<endl;       // 栈顶为20


}