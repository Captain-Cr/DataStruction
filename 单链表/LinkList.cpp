#include <iostream>
#include "LinkList.h"
using namespace std;

// 无参构造 （单链表初始化，生成只有头结点的空单链表)
template<typename DataType>
LinkList<DataType>::LinkList()
{
    first=new Node<DataType>;   // 生成头结点(new在堆区开辟空间，并且返回地址)
    first->next=nullptr;        // 头结点的指针域置空

    cout<<"无参构造，生成头结点"<<endl;
}



// 判空操作，单链表的判空操作只需判断是否只有头结点，即判断first->next是否为空
template<typename DataType>
int LinkList<DataType>::Empty()
{
    if((first->next) == nullptr)
    {
        cout<<"单链表为空，返回0"<<endl;
        return 0;
    }
    else
    {
        cout<<"单链表不为空，返回1"<<endl;
        return 1;
    }
}

// 遍历操作，按序号依次输出各元素.可以通过设置一个工作指针p依次指向各结点，当指针p指向某结点时输出该结点的数据域；
template<typename DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType> *p=first->next;      // 工作指针p初始化，从first指针的next地址开始
    while(p != nullptr)
    {
        cout<<p->data<<"\t";    //同时输出数据域
        p = p->next;      // 让当前工作指针指向当前结点保存的下一个结点的地址
    }
    cout<<endl;

}

// 求单链表的长度
template<typename DataType>
int LinkList<DataType>::Length()
{
    Node<DataType> *p=first->next;      // 定义工作指针p初始化
    int count=0;                        // 统计结点的个数，从0开始统计
    while(p != nullptr)
    {
        p = p->next;                    // 让工作指针指向下一个结点
        count++;                        // 如果工作指针不为nullptr，则让结点数+1
    }
    cout<<"单链表的长度为："<<count<<endl;
    return count;
}

// 按位查找，查找第i个结点的元素值
template<typename DataType>
DataType LinkList<DataType>::Get(int i)
{
    Node<DataType> *p = first->next;      // 定义工作指针p初始化
    int count = 1;                  // 统计到第i个结点
    while((p != nullptr) && (count < i))  // 在p->next是nullptr和count == i 的时候不在向后移动
    {
        p = p->next;
        count++;
    }
    if(p->next == nullptr) throw"查找位置错误";
    else return p->data;
}

// 按值查找，查找值为x的元素序号
template<typename DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node<DataType> *p = first->next;
    int count = 1;
    while(p != nullptr)
    {
        if(p->data == x)
        {
            cout<<"找到了"<<x<<"的位置为："<<count<<endl;
            return count;     // 返回找到的序号
        }
        p = p->next;
        count++;
    }

}

// 插入操作，在第i个位置插入值为x的结点
template<typename DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
    Node<DataType> *p=first;        // 工作指针*p
    Node<DataType> *s=nullptr;      // 新结点s指针，指向创建的新结点

    int count=0;        // 统计到第i-1个结点用到
    while(p != nullptr && count<i-1)    // 查找第i-1个结点
    {
        p = p->next;    // 让工作指针p指向第i-1个结点
        count++;
    }
    if(p == nullptr) throw"插入位置错误";   // 没有找到第i-1个结点
    else
    {
        s=new Node<DataType>;    // 创建一个新的结点s，并让工作指针p指向该结点。原先指针p指向第i-1个结点，里面的p->next包含了第i个结点的地址
        s->data = x;    //申请结点s，数据域为x
        s->next = p->next;  // 将第i个结点的地址保存在新建立的s->next中
        p->next = s;        // 让第i-1个结点指向新建立的结点s中
        
    }
}


// 建立n个元素的单链表,给定的数据元素存放在数组a[n]中，建立单链表就是生成存储这n个数据元素的单链表
// 头插法，基本思想是每次将新申请的结点插在头结点的后面。
template<typename DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
    // 生成头结点
    first = new Node<DataType>;
    first->next = nullptr;

    for(int i=0;i<n;i++)
    {
        Node<DataType> *s = new Node<DataType>;     // 新建一个结点
        s->data = a[i];             // 将a[n]的数据存放在s结点中
        s->next = first->next;first->next = s;  //将结点s插入头结点，first->next保存的是每个新结点的地址;当i=0时，first->next=nullptr,这时s->next=nullptr,即创建了a[0]结点，同时first->next=a[0]的地址；当再插入a[1]结点时，s->next=a[0]的地址，即a[1]指向a[0],同时first->next=a[1]的地址，即头结点指向a[1]，这就完成头插法

    }

    /*
        尾插法：
            基本思想：每次将新申请的结点插在终端结点的后面，为此，需要设尾指针指向当前的终端结点（
            first=new Node<DataType>;   //生成头结点
            first->next=nullptr;
            Node<DataType> *r=first;  // 尾指针指向头结点
            Node<DataType> *s=nullptr;  // 新创建的结点s，用来插入

            for(int i=0;i<n;i++)
            {
                s = new Node<DataType>; s->data=a[i]; //新建一个结点s
                r->next = s;    // 让尾指针指向新结点s
                r = s;          // 将结点s插入到终端结点之后。

                // 原本r指向头结点first（即当前r就是first结点），然后新建结点s(a[0])，让r->next指向s（即是将first->next指向s），然后使r=s（即当前r就是新结点s(a[0))），完成a[0]的插入
                // 然后r(也就是a[0])->next指向新创建结点a[1]，再然后让r=s（即当前r就是新结点s(a[1]))
            }
            r->next=nullptr;    //单链表建立完成，将终端结点的指针域置空

    */

}


// 析构函数,单链表是动态存储分配，单链表的结点时在程序运行中动态申请的，因此，在单链表变量退出作用域之前，要释放单链表的存储空间。
template<typename DataType>
LinkList<DataType>::~LinkList()
{
    // 让结点p指向first结点，同时first结点后移，删除p(即是删除第一个first结点)，最后

    
    Node<DataType> *p=first;
    while(first != nullptr)     // 释放每一个结点的存储空间
    {
        first = first->next;    // first指向被释放结点的下一个结点
        delete p;
        p = first;  // 工作指针p后移

    }

}


// 删除操作，删除第i个结点.因为在单链表中结点ai的存储地址在其前驱结点a(i-1)的指针域中，所以必须先找到a(i-1)的存储地址，然后令p的next域指向ai的后继结点
// 即把结点ai从链上摘下，最后释放ai的存储空间。需要注意表尾的特殊情况，此时虽然被删结点不存在，但其前驱结点却存在。因此仅当被删结点的前驱结点p存在且p不是
// 终端结点时，才能确定被删结点存在。
template<typename DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node<DataType> *p=first;    // 工作指针初始化
    int count=0;    // 累加器初始化
    Node<DataType> *q=nullptr;  // 用来保存被删结点的信息
    DataType x;     // 返回被删的元素
    // 找到第i-1个结点
    while(p != nullptr && count<i-1)
    {
        p = p->next;
        count++;
    }
    // 结点p不存在或者p的后继结点不存在，报错
    if(p == nullptr || p->next == nullptr) throw"删除位置错误";
    else
    {
        q = p->next;    // 让q保存第i个结点的信息
        x = q->data;    // 获取被删结点的data数据
        p->next = q->next;  // 让第i个结点从链表上摘掉
        delete q;   // 释放第i个结点
        return x;
    }
}