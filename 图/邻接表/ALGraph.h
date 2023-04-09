/*
    在图的邻接表存储结构容易有下述基本操作：
    （1）对于无向图，顶点i的度等于顶点i的边表中的结点个数；对于有向图，顶点i的出度等于顶点i的出边表的结点个数；入度也是如此
    （2）判断从顶点i到顶点j是否存在边，只需测试顶点i的边表中是否存在邻接点域为j的结点；
    （3）查找顶点i的所有邻接点，只需遍历顶点i的边表，该边表中的所有结点都是顶点i的邻接点
*/

struct EdgeNode{                 // 定义边表结点
    int adjvex;                  // 邻接点域，存放该顶点的临界点在顶点表中的下标
    EdgeNode* next;             // 指针域，指向边表的下一个结点
};

template<typename DataType>
struct vertexNode{                 // 定义顶点表结点
    DataType vertex;              // 用来存放顶点数据
    EdgeNode* firstEdge;          // 指向边表的第一个结点
};



const int Maxsize = 10;             // 图的最多顶点数
template<typename DataType>
class ALGraph
{
    public:
        ALGraph(DataType a[], int n, int e);                  // 构造函数
        ~ALGraph();                 // 析构函数
        void DFTraverse(int v);         // 深度优先遍历图
        void BFTraverse(int v);         // 广度优先遍历图


    private:
        vertexNode<DataType> adjlist[Maxsize];          // 存放顶点表的数组
        int vertexNum, edgeNum;                         // 图的顶点数和边数


};