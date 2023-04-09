// 哈希表（hashmap, 也叫散列表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。
// 这个映射函数叫做散列函数，存放记录的数组叫做散列表。
// 对于不同的关键字可能得到同一散列地址，这种现象称为冲突（Conllision）。具有相同函数值的关键字对散列函数来说是同义词，
// 根据散列函数和处理冲突的方法将一组关键字映射到一个有限的连续的地址集（区间）上,并以关键字在地址集中的“像”作为记录在表中的存储位置，这种表便称为散列表，这一映射过程称为散列造表或散列，
// 所得的存储位置称为散列地址。
// 若对于关键字集合中的任一个关键字，经散列函数映象到地址集合中任何一个地址的概率是相等的，则称此类散列函数为均匀散列函数（Uniform Hash function），这就是使关键字经过散列函数得到一个“随机的地址”，从而减少冲突

#pragma one
#ifndef _SAMPLE_HASHMAP_H
#define _SAMPLE_HASHMAP_H

#include <iostream>
using namespace std;

// 模板结点
template<typename T>
struct Node{
    T val;                 // 保存结点的数据信息
    struct Node* next;      // 保存下一结点的地址信息
    Node(): next(nullptr),val(0){};  // 无参构造
    Node(T _val): next(nullptr),val(_val){};
    Node(T _val, Node* nxt): next(nxt),val(nxt){};
};


// 模板哈希表
template<typename T>
class HashTable{
public:
    HashTable();
    ~HashTable();
    int& operator[](int index) const;       // 重载[]运算符，哈希表暂时用不上
    void insert(T val);                     // 插入
    void erase(T val);                      // 删除
    bool find(T val);                       // 查找
    void expand();                          // 扩容
    void clear();                           // 清空并释放资源
    void print();                           // 打印检查

private:
    const static int init_buckets_size = 49;        // 桶的初始数量
    int buckets_size;       // 桶的数量
    int keys_count;          // key的数量
    vector<Node<T>>buckets;                     // 不定义成指针类型，免去初始化的步骤
    int hashfun(T val);     // 哈希函数
};


#endif




