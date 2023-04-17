#include "hash_openAddressing.h"
#include <iostream>


/*
    构造函数，初始化哈希表
*/
template<typename DataType>
HashTable<DataType>::HashTable()
{
    for(int i = 0; i < MaxSize; i++)
    {
        ht[i] = 0;
    }
}


/*
    构建哈希函数
*/
template<typename DataType>
int HashTable<DataType>::H(DataType k)
{
    return k % 11;
}



/*
    插入
*/
template<typename DataType>
int HashTable<DataType>::Insert(DataType k)
{
    int i, j=H(k);          // 计算哈希值地址
    i = j;                  // 设置比较的起始位置
    while(ht[i] != 0)       // 当计算出的哈希值地址已经有元素了的时候，（1）有原有元素k，不能插入；（2）往后进行探测
    {
        if(ht[i] == k) 
        {
            std::cout<<"已有元素，不能插入"<<std::endl;
            return -1;       // 原有元素k，不能插入
        }
        else
        {
            std::cout<<"向后探测"<<std::endl;
            i = (i + 1) % MaxSize;      // 往后探测一个位置
        }
    }
    ht[i] = k;                  // 将数据插入
    return i;                   // 返回插入的位置

}


/*
    删除
*/
template<typename DataType>
int HashTable<DataType>::Delete(DataType k)
{
    // 根据哈希值找到k的哈希地址
    int index = H(k);
    int flag;               // 

    while(ht[index] != 0)
    {
        // 判断该哈希值是否为k，如果不为k，则往后探测查找
        if(ht[index] == k)
        {
            ht[index] = OCCUPY_FLAG;          // 将找到的k进行删除,标志位，表明这个位置曾经有元素，但被删除了
            return index;           // 返回k的哈希值地址
        }
        else
        {
            index = (index + 1) % MaxSize;      // 往后探测
        }
    }
    std::cout<<"没有找到,不能删除"<<std::endl;
    return -1;
}


/*
    打印哈希表
*/
template<typename DataType>
void HashTable<DataType>::Print()
{
    std::cout<<"打印哈希表：";
    for(int i = 0; i < MaxSize; i++)
    {
        std::cout<<ht[i]<<"  ";
    }
    std::cout<<std::endl;
}


/*
    查找
*/
template<typename DataType>
int HashTable<DataType>::Search(DataType k)
{
    // 根据哈希值找到k的哈希地址
    int index = H(k);

    while(ht[index] != 0)       // 哈希表中index地址有数据
    {
        if(ht[index] == k)
        {
            std::cout<<"找到元素， 在哈希表中第"<<index<<std::endl;
            return index;
        }
        else
        {
            index = (index + 1) % MaxSize;          // 向后探测
        }
    }
    std::cout<<"没有找到"<<std::endl;
    return index;
}