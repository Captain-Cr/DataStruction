#include "LinkQueue.h"
#include "LinkQueue.cpp"


int main(int argc, char* argv[])
{
    int x;
    LinkQueue<int> Q;               // 创建链接队列
    cout<<"对5和8进行入队操作"<<endl;
    Q.EnQueue(5); Q.EnQueue(8);
    cout<<"当前队头元素为："<<Q.GetHead()<<endl;

    try
    {
        x = Q.DeQueue();            // 出队操作
        cout<<"执行一次出队操作，出队元素是："<<x<<endl;
    }catch(char *str){cout<<str<<endl;}
    // try
    //{
    //    cout<<"请输入元素"<<endl;
    //  cin>> x;
    //    Q.DeQueue();
    //}catch(char *str){cout<<str<<endl;}
    if(Q.Empty()){cout<<"队列为空"<<endl;}
    else{cout<<"队列不为空"<<endl;}
    

    return 0;


}