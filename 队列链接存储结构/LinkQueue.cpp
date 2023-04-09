#include "LinkQueue.h"




// 构造函数
template<typename DataType>
LinkQueue<DataType>::LinkQueue()
{
    // 头指针front指向空结点， 尾指针也指向头结点。
    Node<DataType> *s;
    s = new Node<DataType>;      // 创建一个头结点
    s->next = nullptr;         // 头结点初始化
    front = rear = s;                                // 将队头指针和队尾指针都指向头结点
}


// 析构函数
template<typename DataType>
LinkQueue<DataType>::~LinkQueue()
{
    // 链队列是动态存储分配，需要释放链队列的所有结点的存储空间。和单链表类的析构函数类似。
    Node<DataType> *p = front;
    while(front != rear)
    {
        front = front -> next;          // 指向下一个结点
        delete p;                       // 删除当前结点
        p = front;                      // 工作指针后移
    }
}


// 入队操作
template<typename DataType>
void LinkQueue<DataType>::EnQueue(DataType x)
{
    // 链队列的插入操作只考虑在链表的尾部进行，由于链队列带头结点，空链队列和非空链队列的插入操作一致
    Node<DataType> *s = nullptr;
    s = new Node<DataType>;         // 申请一个新节点  s
    s->data = x;    s->next=nullptr;                // 给申请的结点s赋值
    rear->next = s;                                 // 让rear结点（也就是头结点）的next指向新申请的s
    rear = s;
}


// 出队操作
template<typename DataType>
DataType LinkQueue<DataType>::DeQueue()
{
    // 链队列的删除操作只考虑在链表的头部进行，注意队列长度等于1的特殊情况
    DataType x;                                 // 用于返回出队的元素
    Node<DataType> *p1=nullptr;              // 工作指针p
    // 判断队列是否只有头结点
    if(front == rear) throw"下溢";
    p1 = front->next;                            // 工作指针指向头结点后的队列第一个结点
    x = p1->data;                                // 暂存队头元素
    cout<<x<<endl;
    front->next = p1->next;                      // 将队头元素所在结点摘链
    if(p1->next == nullptr) rear = front;        // 出队前队列长度为1
    delete p1;
    return x;        
}


// 取头元素
template<typename DataType>
DataType LinkQueue<DataType>::GetHead()
{
    //DataType x;                     // 用来返回第一个元素的值
    //Node<DataType> *p=nullptr;
    //p = front->next;                // 指向头结点后的第一个结点
    //x = p->data;                    // 获取该结点的值
    //delete p;
    return front->next->data;
}



// 判空操作
template<typename DataType>
int LinkQueue<DataType>:: Empty()
{
    // 判空操作，只需判断front是否等于rear
    if(front == rear) return 1;
    else 
    {
        return 0;
    }
}