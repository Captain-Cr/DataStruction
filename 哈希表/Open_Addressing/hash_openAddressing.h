/*
    @Description: 使用开放地址法构建hash表，开放地址法处理冲突方法是：如果由关键码得到的散列地址产生了冲突，根据式子寻找下一个空的散列地址，  (H(key) + d) % m，其中d=1,2....m-1称为线性
    探测法；若d=1^2, -1^2, 2^2, -2^2....q^2, -q^2，且q<= 根号m, 则称为二次探测

    @Method:
        1、插入
        2、删除
        3、查找
*/

#ifndef _HASH_OPEN_H
#define _HASH_OPEN_H

#define OCCUPY_FLAG 25535;

const int MaxSize = 10;

template<typename DataType>
class HashTable
{
    public:
        HashTable();
        ~HashTable(){};
        
        int Insert(DataType k);              // 插入
        int Delete(DataType k);              // 删除
        int Search(DataType k);              // 查找
        void Print();                   // 打印哈希表

    private:
        int H(DataType k);                   // 散列函数，计算散列值
        DataType ht[MaxSize];                // 闭散列表
};

#endif