#include "SeqStack.h"
#include "SeqStack.cpp"


int main(int argc, char* argv[])
{
    int x;
    SeqStack<int> s;        // 定义顺序栈s
    cout<<"对15和10执行入栈操作"<<endl;
    s.Push(15);   s.Push(10);
    cout<<"当前栈顶元素为："<<s.GetTop()<<endl;         // 输出栈顶元素10

    try
    {
        x = s.Pop();        // 出栈操作
        cout<<"执行一次出栈操作，删除元素"<<x<<endl;        // 输出出栈元素10
    }
    catch(char *str){cout<<str<<endl;}
   

   try
   {
       cout<<"请输入待入栈元素："<<endl;
       x = 20;              // 入栈20
       s.Push(x);
   }
   catch(char *str){cout<<str<<endl;} 
   

   if(s.Empty()==1){cout<<"顺序栈为空"<<endl;}
    

    return 0;

}