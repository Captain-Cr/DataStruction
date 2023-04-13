/*
    二叉搜索树实现

    相关概念：
        1、如果右子树不为空，那么右子树所有结点值大于根节点的值；
        2、如果左子树不为空，那么左子树所有结点值小于根节点的值；
        3、左右子树的每个结点均满足上述条件。
        4、对于二叉搜索树，可以通过中序遍历得到一个递增的有序序列；


    二叉搜索树相关实现：
        （1）构造、析构（结点构造、构造、拷贝构造、析构、赋值重载）
        （2）插入（非递归实现和递归实现）
        （3）查找（非递归和递归实现）
        （4）删除（非递归和递归实现）
        （5）遍历
*/
#include "BST.h"


/*
    构造函数，用于存放搜索二叉树的头指针
*/
template<typename DataType>
BSTree<DataType>::BSTree()
{

}

/*
    拷贝构造，使用前序遍历的方法，递归的将每个结点给拷贝复制一份。另外，由于构造函数的特殊性，无法返回值，所以要定义一个子函数进行递归
*/
template<typename DataType>
BSTree<DataType>::BSTree(const BSTree<DataType>& b)
{
    // 传入一个BSTree对象，对该对象进行复制
    _BSTree(root, b.root);
}

template<typename DataType>
void BSTree<DataType>::_BSTree(Node*& node1, Node* node2)
{
    // 递归结束条件就是该结点为nullptr
    if(node2 == nullptr) return;

    // 使用前序遍历进行复制
    node1 = new Node(node2->val);
    _BSTree(node1, node2->left);
    _BSTree(node1, node2->right);
}


/*
    析构函数：和构造函数反着来，采用后序遍历，首先删除左子树的所有结点，然后删除右子树的所有结点，最后删除根结点。由于析构函数的特殊性，所以也需要一个子函数进行操作
*/
template<typename DataType>
BSTree<DataType>::~BSTree()
{
    _delBSTree(root);
}

template<typename DataType>
void BSTree<DataType>::_delBSTree(Node*& node)
{
    // 递归终止条件
    if(node == nullptr) return;

    // 遍历左子树，并进行删除
    _delBSTree(node->left);
    // 遍历右子树
    _delBSTree(node->right);
    // 删除结点
    delete node;
    node = nullptr;
}


/*
    赋值重载，重载'='运算符，用来交换内部属性
*/
template<typename DataType>
BSTree<DataType>& BSTree<DataType>::operator=(BSTree<DataType> b)
{
    swap(b);                // 进行交换
    return *this;
}

template<typename DataType>
void BSTree<DataType>::swap(BSTree<DataType>& b)
{
    Node* temp = b.root;
    b.root = this->root;
    this->root = temp;
}



/*
    搜索二叉树数据插入，因为是搜索二叉树，所以对于插入一个数，首先判断其val值是否大于或小于当前结点值，如果大于则插入右子树，如果小于则插入左子树，如果遇到相同值则不插入。一直到空
*/
template<typename DataType>
bool BSTree<DataType>::insert(const DataType& k)
{
    // 插入递归实现
    return _insert(root, k);
}

template<typename DataType>
bool BSTree<DataType>::_insert(Node*& node, const DataType& k)
{
    // 递归终止条件,如果结点到空时，将结点值k进行插入
    if(node == nullptr)
    {
        node = new Node(k);
        return true;
    }

    // 插入判断，大于该结点值插入右子树，小于该结点插入左子树
    if(node->val > k) return _insert(node->left, k);
    else if(node->val < k) return _insert(node->right, k);
    else return false;      // 插入相同的返回失败
}

/*
    搜索二叉树查找，利用搜索二叉树的特性，相等的返回true，小于该结点值的往左子树查找，大于该结点值的往右子树查找
*/
template<typename DataType>
bool BSTree<DataType>::find(const DataType& k)
{
    // 使用递归的方式查找
    return _find(root, k);
}

template<typename DataType>
bool BSTree<DataType>::_find(Node* node, const DataType& k)
{
    // 递归终止条件
    if(node == nullptr) return false;

    // 查找判断，大于该结点值的往右子树查找，小于该节点数的往左子树查找，相等的直接返回true
    if(node->val > k) return _find(node->left, k);
    else if(node->val < k) return _find(node->right, k);
    else return true;
}



/*
    遍历，直接使用中序遍历（左-->中-->右）
*/
template<typename DataType>
void BSTree<DataType>::Traverse()
{
    _order(root);
}

template<typename DataType>
void BSTree<DataType>::_order(Node* node)
{
    // 递归终止条件
    if(node == nullptr) return;

    // 中序遍历
    _order(node->left);
    cout<<node->val<<endl;
    _order(node->right);
}


/*
    删除某个结点，有两种情况：输入的删除结点如果大于根结点则往右子树寻找，小于根结点往左子树进行查找。等找到相等的结点就进行删除，其中删除包括包括两种情况：
    （1）删除结点有少于2个孩子结点的就直接删除，并让孩子结点与删除结点的父结点进行继承（删除结点是其父结点的什么子树，就进行什么继承，例如删除结点是其父结点的左子树，则让删除结点的孩子结点进行左继承）；
    （2）删除结点有2个孩子结点，这种情况也分成两种情况，
        （2.1）找删除结点左子树最大值（或右子树最小值）替代该删除结点，且如果替换结点（左子树最小值或右子树最大值）是其父结点的右子树（或左子树），并且替换结点的左孩子结点存在，则该左孩子结点继承替换结点父结点的右继承（替换结点的右孩子结点存在，则该右孩子结点继承替换结点的父结点的左继承）。
        （2.2）找删除结点左子树的最大值（或右子树的最小值）替换该删除结点，且如果左子树最大值为删除结点的左孩子结点，并且为其父结点（删除结点）的左子树时，直接将其子结点继承在其父结点的左子树；（右子树的最小值为替换结点的右孩子结点，且为其父的右子树时，直接将其子结点继承在其父结点的右子树）。
*/
template<typename DataType>
bool BSTree<DataType>::erase(const DataType &k)
{
    return _erase(root, k);
}

template<typename DataType>
bool BSTree<DataType>::_erase(Node*& node, const DataType& k)
{
    // 先找到删除点
    // 递归终止条件
    if(node == nullptr) return false;           // 没有找到删除点，无法进行删除

    // 找到删除点，小于该结点值的往左子树搜索，大于该结点值的往右子树搜索
    if(node->val > k) _erase(node->left, k);
    else if(node->val < k) _erase(node->right, k);
    else
    {
        Node* tmp = node;                        // 记录当前结点值为k的指针
        // 找到了，进行删除操作
        // 第一种情况，存在一个孩子或者没有孩子
        if(node->left == nullptr)
        {
            node = node->right;                 // 没有左孩子，直接让右孩子进行继承
        }
        else if(node->right == nullptr)
        {
            node = node->left;                  // 没有右孩子，直接让左孩子进行继承
        }
        else
        {
            // 第二种情况，两个孩子都存在
            // 找出删除结点的左子树最大值（或右子树最小值）
            Node* Maxc = node->left;
            // 左子树最大值在左子树的最右边
            while(Maxc->right)
            {
                Maxc = Maxc->right;
            }
            node->val = Maxc->val;
            // 交换值之后，不再进行复杂的分析如何接后面的情况，继续递归给别人，将此交换点干掉就好了         // 递归找到替换最大值的那个结点，让tmp等于找到的那个结点，然后判断该结点的左、右子树是否存在，然后删除该结点
            return _erase(node->left, Maxc->val);                   // 必须从左树开始找，不能直接传maxc，否则只是修改了形参里的值，传回了释放的空间就成了野指针。  
        }
        delete tmp;
        return true;

    }
}
