/*
    队列顺序存储结构--循环队列实现
    入队和出队的时间性能为O(1),因为没有移动任何元素，但是队列的队头和队尾都是活动的，因此，要设置队头、队尾两个位置变量front和rear。
    入队时rear加1， 出队时front加1， 并且约定：front指向队头元素的前一个位置， rear指向队尾元素的位置。

    设存储队列的数组长度为QueueSize,操作语句为:rear = (rear + 1) % QueueSize.  (循环队列)

    判断队空的条件是：
        front == rear(执行出队操作，则队头位置在循环意义下加 1 后与队尾位置相等)
    判断队满的条件是：
        (rear + 1) % QueueSize == front  (可以浪费一个数组元素控件， 在队满时队尾位置和队头位置正好差1)

*/
#ifndef CIRQUEUE_H
#define CIRQUEUE_H

#include <iostream>
#include <vector>

using namespace std;



const int QueueSize = 100;      // 队列的长度

template<typename DataType>         // 定义模板类CirQueue
class CirQueue
{
    public:
        CirQueue();         // 构造方法，初始化为空队列
        ~CirQueue();        // 析构， 因为用的是静态存储分配，所以循环队列变量退出作用域时自动释放内存单元
        void EnQueue(DataType x);           // 入队操作，将元素x入队
        DataType DeQueue();                 // 出队操作，将队头元素出队
        DataType GetHead();                 // 取队头元素（并不删除）
        int Empty();                        // 判断队头是否为空

    private:
        DataType data[QueueSize];            // 存放队列元素的数组
        int front, rear;                    // 游标， 队头和队尾指针

};











#endif


