/*
    拉链法实现哈希表，基本思想：将所有散列地址相同的记录，即所有关键码为同义词的记录存储在一个单链表当中，称为同义词子表，在散列表中存储的是所有同义词子表的头指针。
    @Method:
        1、插入
        2、删除
        3、查找
        4、打印
*/


#ifndef CHAIN_HASHTABLE_H
#define CHAIN_HASHTABLE_H

#include <iostream>
using namespace std;

const int MaxSize = 10;

struct Node
{
    int data;                  // 存储结点数据
    Node* next;                     // 指向的下一个结点
};


template<typename DataType>
class HashTable
{
public:
    HashTable();
    ~HashTable();

    int Insert(DataType k);           // 插入
    int Delete(DataType k);           // 删除
    void Print();                     // 打印哈希表

    //  查找
    Node* Search(DataType k);          // 查找

private:
    int H(DataType k);                  // 哈希函数
    Node *ht[MaxSize];        // 哈希同义词子表数组                      
};


#endif