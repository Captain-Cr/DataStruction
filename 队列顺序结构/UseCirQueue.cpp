#include "CirQueue.h"
#include "CirQueue.cpp"

using namespace std;



int main(int argc, char* argv[])
{
    int x;
    CirQueue<int> Q;        // 定义一个循环队列对象
    cout<<"对5和8执行入队操作,"<<endl;
    Q.EnQueue(5);
    Q.EnQueue(8);
    cout<<"当前队头元素为："<<Q.GetHead()<<endl;   


    try
    {
        x = Q.DeQueue();            // 出队， 5出去了，还剩下8
        cout<<"执行一次出队操作，出队元素为： "<<x<<endl;
    }catch(char *str){cout<<str<<endl;}     // 捕获异常

    //try
    //{
    //    cout<<"请输入入队元素： ";
     //   cin>>x;
    //    Q.EnQueue(x);
    //}catch(char *str){cout<<str<<endl;}     // 如果上溢，就会抛出异常，并被捕获
    if(Q.Empty() == 1) cout<<"队列为空"<<endl;
    else cout<<"队列不为空"<<endl;
    return 0;



}