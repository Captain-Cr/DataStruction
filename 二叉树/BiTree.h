/*
    二叉链表(binary linked list)，思想：令二叉树的每个结点对应一个链表结点，链表结点除了存放二叉树结点数据外，还存放指示的左右孩子指针

*/
#ifndef _BITREE_H
#define _BITREE_H

#include <iostream>

using namespace std;

template<typename DataType>
struct BiNode
{
    DataType data;              // 该结点存放的数据
    BiNode<DataType> *lchild, *Rchild;           // 指示的左右孩子指针
};



template<typename DataType>
class BiTree
{
    public:
        BiTree()    { root = Creat();  }                       // 构造函数，建立一颗二叉树
        ~BiTree()   { Release(root);   }                     // 析构函数，释放各结点的存储空间
        void PreOrder(){ PreOrder(root); }               // 前序遍历二叉树     根 --> 左 --> 右
        void InOrder() { InOrder(root);  }                // 中序遍历二叉树，   左 --> 根 --> 右
        void PostOrder(){ PostOrder(root); }              // 后序遍历二叉树，   左 --> 右 --> 根
        void LevelOrder();             // 层序遍历

    private:
        BiNode<DataType> *Creat();           // 构造函数调用,  返回一个创建二叉树根结点的指针
        void Release(BiNode<DataType> *bt);          // 析构函数调用
        void PreOrder(BiNode<DataType> *bt);         // 前序遍历函数调用
        void InOrder(BiNode<DataType> *bt);          // 中序遍历函数调用
        void PostOrder(BiNode<DataType> *bt);        // 后序遍历函数调用
        
        BiNode<DataType> *root;                      // 指向根结点的头指针

};










#endif
