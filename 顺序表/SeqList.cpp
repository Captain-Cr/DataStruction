#include "SeqList.h"
#include <iostream>
using namespace std;


// 这个文件是实现SeqList声明的各种方法


// 无参构造函数
template <typename Datatype>
SeqList<Datatype>::SeqList()
{
    // data=[];
    length=0;

    cout<<"默认构造函数"<<endl;
}

// Length()方法求顺序表长度
template <typename Datatype>
int SeqList<Datatype>::Length()
{
    cout<<"返回顺序表长度，为："<<length<<endl;
    return length;
}

// 有参构造函数，并建立一个长为n的顺序表和将给定的数据元素传入顺序表中。如果传入的数据>长度n就报错。
template<typename Datatype>
SeqList<Datatype>::SeqList(Datatype a[],int n)
{
    if(n>MaxSize) throw "error,n>MaxSize";
    for(int i=0;i<n;i++)
    {
        data[i]=a[i];
    }
    length=n;

    cout<<"有参构造函数，长度为："<<length<<endl;

}

// 析构函数
template<typename Datatype>
SeqList<Datatype>::~SeqList()
{
    cout<<"析构函数"<<endl;
    // delete data; 报错，delete只能删除在堆区开辟的数据
}



// 判断是否为空
template<typename Datatype>
int SeqList<Datatype>::empty()
{
    if( length == 0)
    {
        cout<<"顺序表长度为0"<<endl;
       return 0;
    }
    else{
        cout<<"顺序表长度不为0,返回1"<<endl;
        return 1;
    }
    
}


// 按位查找，查找顺序表第i个元素的值
template<typename Datatype>
Datatype SeqList<Datatype>::Get(int i)
{
    if(i<1 || i>length) throw"查找位置非法";
    Datatype x=data[i-1];
    cout<<"按位查找，顺序表第i个元素为："<<x<<endl;
    return x;
}

// 按值查找，在顺序表中查找值为x的元素序号
template<typename Datatype>
int SeqList<Datatype>::Locate(Datatype x)
{
    for(int i=0;i<length;i++)
    {
        if(x == data[i])
        {
            cout<<"在顺序表找到了值为："<<x<<"的元素，位置在："<<i+1<<endl;
            return i+1;
        }
        else if(i == length-1)
        {
            cout<<"没有找到"<<endl;
        }
    }
}

 // 插入操作，在顺序表第i个位置插入值为x的元素
 template<typename Datatype>
 void SeqList<Datatype>::insert(int i,Datatype x)
 {
    if(length == MaxSize) throw "上溢";
    if(i<1 || i>length+1) throw"插入位置错误";
    for(int j=length;j>=i;j--)
    {
        data[j]=data[j-1];
    }
    data[i-1] = x;
    
    cout<<"插入后的数据为:";
    for(int k=0;k<length+1;k++)
    {
        if(k == length)
        {
            cout<<data[k]<<endl;
        }
        else
        {
            cout<<data[k]<<",";
        }      
    }
 }

 // 删除操作，删除顺序表的第i个元素
template<typename Datatype>
Datatype SeqList<Datatype>::Delete(int i)
{
    Datatype x = data[i-1];
    if(length == 0) throw"下溢";
    if(i<1 || i>length) throw"删除位置错误";
    for(int j=i-1;j<length;j++)
    {
        data[j] = data[j+1];
    }

    cout<<"删除后的数据为:";
    for(int k=0;k<length;k++)
    {
        if(k == length)
        {
            cout<<data[k]<<endl;
        }
        else
        {
            cout<<data[k]<<",";
        }      
    }
    
    cout<<"删除的数据为："<<x<<endl;
    return x;
}


