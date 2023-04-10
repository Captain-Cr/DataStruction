/*
    顺序表类定义如下，其中成员变量实现顺序表的存储结构，成员函数实现线性表的基本操作。
    由于线性表的数据元素类型不确定，所以采用c++模板机制
*/
#ifndef SEQLIST_H
#define SEQLIST_H


extern const int MaxSize=100;   // 根据实际问题采用具体定义
template<typename Datatype>    // 定义模板类SeqList
class SeqList{
    // 成员变量
    private:
        int data[MaxSize];   // 存放数据元素的数组
        int length;        // 线性表的长度


    // 成员方法
    public:
        SeqList();                            // 空参构造
        SeqList(Datatype a[],int n);          // 建立长度为n的顺序表
        ~SeqList();                           // 析构函数
        int Length();                         // 求线性表的长度
        Datatype Get(int i );                 // 按位查找，查找第i个元素的值
        int Locate(Datatype x);               // 按值查找，查找值为x的元素序号
        void insert(int i,Datatype x);        // 插入操作，在第i个位置插入值为x的元素
        Datatype Delete(int i);               // 删除操作，删除第i个元素
        int empty();                          // 判断线性表是否为空
        void PringList();                     // 遍历操作，按序号以此输出各元素

};

#endif