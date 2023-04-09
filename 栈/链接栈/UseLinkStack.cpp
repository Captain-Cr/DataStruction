#include "LinkStack.h"
#include "LinkStack.cpp"




int main(int argc, char* argv[])
{
    int x;
    LinkStack<int> S{};             // 定义链栈变量S
    cout<<"对15和10进行入栈操作"<<endl;
    S.push(15); S.push(10);
    cout<<"当前栈顶元素为："<<S.GetTop()<<endl;         // 输出栈顶元素10

    try
    {
        x = S.Pop();                // 出栈操作
        cout<<"执行一次出栈操作，删除元素："<<x<<endl;
    }
    catch(char *str){cout<<str<<endl;}

    try
    {
        cout<<"输入元素入栈"<<endl;
        x = 20;
        S.push(x);
    }
    catch(char *str){cout<<str<<endl;}

    if(S.Empty() == 1)  cout<<"栈为空"<<endl;
    else
    {
        cout<<"栈不为空"<<endl;
    }

    cout<<"当前栈顶元素为："<<S.GetTop()<<endl;         // 输出栈顶元素20
    return 0;
    
    


}