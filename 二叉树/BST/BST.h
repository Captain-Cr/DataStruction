#ifndef _BST_H
#define _BST_H

#include <iostream>
using namespace std;

// 创建结点
// 模板1
namespace K{
    typedef struct BSTreeNode
    {
        int val;                        // 存储结点的值
        BSTreeNode* left ;        // 左子树
        BSTreeNode* right;       // 右子树
        BSTreeNode():val(0),left(nullptr),right(nullptr){}            // 默认构造函数
        BSTreeNode(int x):val(x),left(nullptr),right(nullptr){}
        BSTreeNode(int x, BSTreeNode* left, BSTreeNode *right){}

    }BSTreeNode;        // BSTreeNode是一个结构体类型，经过typedef后其代表这这个结构体类型，使用时必须先 BSTreeNode a;进行变量定义
}

// 模板2
namespace K2
{
    template<typename DataType>
    struct BSTreeNode
    {
        DataType val;
        BSTreeNode* left;
        BSTreeNode* right;       // 右子树
        BSTreeNode():val(0),left(nullptr),right(nullptr){}            // 默认构造函数
        BSTreeNode(DataType x):val(x),left(nullptr),right(nullptr){}
        BSTreeNode(DataType x, BSTreeNode* left, BSTreeNode *right){}

    };
}


// 创建搜索二叉树，包括构造析构、插入、寻找、删除以及遍历等功能
template<typename DataType>
class BSTree
{
    typedef K2::BSTreeNode<DataType>  Node;
    public:
        BSTree();           // 默认构造函数
        BSTree(const BSTree<DataType>& b);        // 拷贝构造
        ~BSTree();          // 析构函数
        Node* Create();                           // 创建搜索二叉树，并返回指向该二叉树的首地址
        bool insert(const DataType& key);        // 插入
        bool find(const DataType& key);          // 寻找
        bool erase(const DataType& key);         // 删除
        void traverse();


    private:
        Node* root = nullptr;           // 指向该二叉树的头指针
        
      
};



#endif