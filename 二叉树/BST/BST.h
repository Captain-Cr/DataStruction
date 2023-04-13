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
    typedef K2::BSTreeNode<DataType> Node;
    public:
        BSTree();                                // 默认构造函数
        BSTree(const BSTree<DataType>& b);        // 拷贝构造
        ~BSTree();                                // 析构函数
        bool insert(const DataType& key);        // 插入, 通过插入构建二叉搜索树
        bool find(const DataType& key);          // 寻找
        bool erase(const DataType& key);         // 删除
        void Traverse();               // 遍历，直接使用中序遍历
        BSTree& operator=(BSTree<DataType> b);      // 重载'='运算符
        void swap(BSTree<DataType>& b);             // 用来内部交换属性函数


    private:
        Node* root = nullptr;           // 指向该二叉树的头指针
        // 拷贝构造函数递归
        void _BSTree(Node*& node1, Node* node2);        // *&：表示引用传入的实参指针
        // 析构函数辅助函数
        void _delBSTree(Node*& node);
        // 插入递归实现
        bool _insert(Node*& node, const DataType& k);
        // 查找递归实现
        bool _find(Node* node, const DataType& k);
        // 中序递归遍历
        void _order(Node* node);
        // 递归删除某个结点
        bool _erase(Node*& node, const DataType& k);
    
};



#endif