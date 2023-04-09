#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;


int main()
{
    LinkList<int> l;  // 无参构造
    l.Empty();  
    l.PrintList();      

    int r[5]={1,2,3,4,5};
    LinkList<int> l2(r,5);
    l2.Empty();  
    l2.Length();
    l2.PrintList();
    cout<<l2.Get(3)<<endl;
    cout<<l2.Locate(2)<<endl;  // 头插法
    l2.Insert(1,6);
    l2.Length();
    l2.PrintList();
    cout<<"被删的元素为："<<l2.Delete(1)<<endl;
    l2.PrintList();

}