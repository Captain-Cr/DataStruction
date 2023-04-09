#include "BiTree.h"


// 前序遍历    根 --> 左 --> 右
template<typename DataType>
void BiTree<DataType> :: PreOrder(BiNode<DataType> *bt)
{
    // 用递归的方式遍历
    if(bt == nullptr)  return;   // 终止条件，如果该节点为nullptr就返回

    else
    {
        cout<<bt->data<<"\t";       // 输出当前结点的data
        PreOrder(bt->lchild);       // 递归遍历左孩子结点
        PreOrder(bt->Rchild);       // 递归遍历右孩子结点
    }
}


// 中序遍历   左 --> 根 --> 右
template<typename DataType>
void BiTree<DataType> :: InOrder(BiNode<DataType>  *bt)
{
    // 用递归的方式遍历
    if(bt == nullptr) return;       // 递归调用的结束条件

    else
    {
        InOrder(bt->lchild);           
        cout<<bt->data<<"\t";
        InOrder(bt->Rchild);
    }
}

// 后序遍历    左 --> 右 --> 根
template<typename DataType>
void BiTree<DataType> :: PostOrder(BiNode<DataType> *bt)
{
    // 用递归的方法遍历
    if(bt == nullptr)  return;

    else
    {
        PostOrder(bt->lchild);
        PostOrder(bt->Rchild);
        cout<<bt->data<<"\t";
    }
}


// 层序遍历     
// 算法： 1、队列Q初始化；  2、如果二叉树非空，将指针入队；  
// 3.1 q=队列Q的队头元素出队； 3.2 访问结点q的数据域；  3.3 若结点q存在左孩子，则将左孩子指针入队； 3.4 若结点q存在右孩子，则将右孩子指针入队。
// 注意：队列Q的元素类型是指向二叉链表结点的指针。
template<typename DataType>
void BiTree<DataType>:: LevelOrder()
{
    BiNode<DataType> *Q[100], *q=nullptr;           // 采用顺序指针,   *Q[100]:指针数组
    int front = -1, rear = -1;                      // 队列初始化
    if(root == nullptr) return;                     // 二叉树为空，算法结束
    Q[++rear] = root;                               // 根指针入队
    while(front != rear)                            // front == rear 代表队列为空    （rear + 1）% size == front代表队列已满
    {
        q = Q[++front];                             // 出队
        cout<<q->data<<"\t";
        if(q->lchild != nullptr) Q[++rear] = q->lchild;         // 如果存在左孩子，将左孩子指针入队
        if(q->Rchild != nullptr) Q[++rear] = q->Rchild;         // 如果存在右孩子，将右孩子指针入队

    }
} 



// 构造函数 -- 创建二叉树
// 过程：首先输入根节点，若输入根节点是 # 字符，则表明该二叉树是空树，即root = nullprt； 
// 否则输入的字符应该赋给bt->data，之后依次递归建立它的左子树和右子树。
template<typename DataType> 
BiNode<DataType> *BiTree<DataType>::Creat()
{
    BiNode<DataType> *bt;           // 结点指针
    char ch;
    cin >> ch;                      // 从键盘输入字符.    AB#D##C##
    //ch = 'a';
    if( ch == '#')  bt = nullptr;       // 如果输入是 '#', 则表明该二叉树是空树
    else{
        bt = new BiNode<DataType>;      // 创建一个结点
        bt->data = ch;              // 将输入字符赋给该结点
        bt->lchild = Creat();            // 递归建立左子树
        bt->Rchild = Creat();            // 递归建立右子树
        
    }
    return bt;

}



// 析构函数  -- 销毁二叉树
// 二叉链表是动态存储分配，结点是在程序运行过程运行过程中动态申请的，在退出作用域前，要释放二叉链表存储空间。
// 可以对二叉树进行后序遍历，在访问结点进行释放处理
template<typename DataTypt>
void BiTree<DataTypt>::Release(BiNode<DataTypt> *bt)
{
    if(bt == nullptr)   return;
    else
    {
        Release(bt->lchild);        // 递归释放左子树
        Release(bt->Rchild);        // 递归释放右子树
        delete bt;
    }
}




