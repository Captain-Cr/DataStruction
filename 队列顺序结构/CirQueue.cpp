#include "CirQueue.h"

template<typename DataType>
CirQueue<DataType>::CirQueue()
{
    // 初始化一个空的循环队列只需将队头front和队尾rear同时指向某一位置，一般是数组的高端，即front=rear=QueueSize - 1
    front = QueueSize - 1;
    rear = QueueSize - 1;  
}

template <typename DataType>
CirQueue<DataType>::~CirQueue()
{
    // 析构函数，静态存储分配，在循环队列变量退出作用域时自动释放所占单元内存，因此，循环队列不用销毁，析构函数为空
} 


// 入队操作
template<typename DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
    // 入队，只需队尾 rear + 1， 并且把数据插入到 data[rear + 1]中
    if((rear + 1) % QueueSize == front) throw"上溢";      // （rear + 1) % QueueSize == front 代表队列已经满了
    rear = (rear + 1) % QueueSize;                      // 队尾指针在循环意义下加1
    data[rear] = x;

}


// 出队操作
template<typename DataType>
DataType CirQueue<DataType> :: DeQueue()
{
    // 出队， 只需队头 front + 1（在循环意义下）， 取出data[front + 1]
    if(front == rear) throw"下溢";          // front == rear 代表队列为空
    front = (front + 1) % QueueSize;
    DataType x = data[front];
    return x;

}


// 取队头元素
template<typename DataType>
DataType CirQueue<DataType>::GetHead()
{
    // 直接返回 front + 1的元素
    if(front == rear) throw"下溢";          // front == rear 代表队列为空
    return data[(front + 1) % QueueSize];       // 注意不修改队头指针
} 


// 判空操作
template<typename DataType>
int CirQueue<DataType>::Empty()
{
    // 只需判断 front 是否等于 rear
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}