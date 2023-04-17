#include "ChainHashTable.h"



/*
    构造函数
*/
template<typename DataType>
HashTable<DataType>::HashTable()
{
    
    for(int i = 0; i < MaxSize; i++)
    {
        ht[i] = nullptr;
    }
}

/*
    析构函数
*/
template<typename DataType>
HashTable<DataType>::~HashTable()
{
    Node *p = nullptr;                 // p保存当前结点指针
    Node *q = nullptr;                 // q保存下一节点指针
    for(int i = 0; i < MaxSize; i++)
    {
        p = q = ht[i];
        while(p != nullptr)
        {   // 从头删到尾
            p = p->next;
            delete q;
            q = p;
        }
    }
}

/*
    哈希函数
*/
template<typename DataType>
int HashTable<DataType>::H(DataType k)
{
    return k % 11;
}

/*
    哈希表打印
*/
template<typename DataType>
void HashTable<DataType>::Print()
{
    Node *p = nullptr;
    for(int i = 0; i < MaxSize; i++)
    {   p = ht[i]; 
        std::cout<<"哈希数组索引"<<i<<"的值为：";
        while(p != nullptr)
        {
            std::cout<<p->data<<"   ";
            p = p->next;
        }
        std::cout<<std::endl;
    }
}

/*
    查找,返回找到的结点
*/
template<typename DataType>
Node* HashTable<DataType>::Search(DataType k)
{
    int index = H(k);               // 计算哈希地址
    Node *p = ht[index];

    while(p != nullptr)
    {
        if(p->data == k)
        {
            std::cout<<"找到元素，在第"<<index<<std::endl;
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    std::cout<<"没有找到"<<std::endl;
    return nullptr;
}





/*
    插入
*/
template<typename DataType>
int HashTable<DataType>::Insert(DataType k)
{
    int index = H(k);                       // 计算哈希地址
    // 寻找是否存在和k相同值的结点
    Node *p = Search(k);          
    // 如果插入的值已经存在，则退出
    if(p != nullptr) 
    {
        return -1; 
    }
    else
    {
        // 创建一个新结点
        p = new Node();
        p->data = k;
        // 对结点进行插入
        p->next = ht[index];
        ht[index] = p;

    }

}
