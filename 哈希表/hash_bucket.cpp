/*
    描述：哈希桶的简单实现
    作者：陈荣演
    日期：2023年3月27
    版权（copyright）：2023-3-27
*/


#include <stdio.h>
#include <stdlib.h>
#include <string>



#define BUCKETCOUNT 10      // 哈希桶的最大数量

/*链表节点*/
typedef struct Node{
    char* key;              // 字符串指针
    char* val;
    struct Node *next;      // 链表下一节点
}node;

/*顺序哈希桶*/
typedef struct hashTable{
    node bucket[BUCKETCOUNT];   // 定义数组，数组里面存放的是链表节点
}table;

// 声明哈希桶相关操作函数
void initHashTable(table *t);                   // 初始化哈希桶
int hashFuction(const char* key);              // 哈希函数，根据生成哈希值
node* lookup(const char* key);                 // 根据key值查找相应的值
int insertnode(table *t, char *key, char* value);          // 将数据插入到哈希桶当中
const char* get(const char* key);               // 根据输入的key字符串，返回相应的value字符串
void display(table *t);                                 // 打印hash表






/*初始化哈希桶*/
void initHashTable(table *t)
{
    // 传入一个哈希桶
    if(!t)
    {
        return;
    }
    for(int i = 0; i < BUCKETCOUNT; ++i)
    {
        // 为哈希桶每个桶都初始化
        t->bucket[i].key = NULL;
        t->bucket[i].val =NULL;
        t->bucket[i].next = NULL;
    }
}


/*哈希函数，根据生成哈希值*/
int hashFunction(const char* key)
{
    // 传入一个key，返回相应的哈希值
    int hash = 0;
    for(;*key;++key)
    {
        hash = hash*33 + *key;
    }
    return hash % BUCKETCOUNT;
}


/*将数据插入到哈希桶当中*/
int insertnode(table *t, char* key, char* value)
{
    int index, vlen1, vlen2;
    node *e, *ep;

    if(t == NULL || key == NULL || value == NULL) return -1;

    index = hashFunction(key);      // 根据哈希函数求出哈希桶的索引位置
    // 如果index位置为空，则直接将其写入第一个桶节点
    if(!t->bucket[index].key)
    {
        // 如果该节点的key为NULL，则将key和val直接写入
        t->bucket[index].key = key;
        t->bucket[index].val = value;     // strdup(const *str):返回一字符串指针，该指针指向复制后的新字符串的地址
    }
    else
    {
        // 如果该节点已经有了桶节点
        e = ep = &(t->bucket[index]);           // e和ep指针都指向该桶节点,bucket[index]是一个链表，保存的是一个结点地址
        /*先从已经存在的找*/
        while(e)            // 如果当前结点不为NULL，则判断输入的插入key值和该当前结点的key是否重复，如果重复，则替换掉
        {
            /*如果key值重复，替换相应的值*/
            if(strcmp(e->key, key) == 0)
            {
                vlen1 = strlen(value);      // 插入字符串的长度
                vlen2 = strlen(e->val);     // 原节点中的字符串长度
                if(vlen1 > vlen2)
                {
                    free(e->val);           // 如果插入的字符串的长度比该节点字符串长度长，则释放该空间，并创建一个更大的空间
                    e->val = (char *)malloc(sizeof(vlen1 + 1));
                }
                memcpy(e->val, value, vlen1+1);     // 将插入的值复制到哈希桶中
                return index;                   // 插入完成
            }

            ep = e;
            e = e->next;            // 指向下一个结点
        }
        /*没有在当前桶中找到，创建新的节点加入，并加入桶链表*/
        e = (node *)malloc(sizeof(node));           // 新创建的结点，将其加入到链表中
        if(NULL != e)
        {
            e->key = key;
            e->val = value;
            e->next = NULL;
            ep->next = e;               // 将上一个节点的next指向新建的结点
        }

    }
    
    return index;
}




/*打印哈希表*/
void display(table *t)
{
    int i;              // 哈希表位置索引
    node* e;            // 哈希桶结点
    if(!t) return;

    for(int i = 0; i < BUCKETCOUNT; i++)
    {
        printf("bucket[%d]:",i);
        e = &(t->bucket[i]);
        while(e)
        {
            // 遍历哈希桶的整个链表
            printf("%s = %s \t\t",e->key, e->val);
            e = e->next;        // 往链表下面移动
        }
        printf("\n");
    }
}



int main(int argc, char* argv[])
{
    // 创建一个哈希表,并分配内存
    table *ht;
    ht = (table *)malloc(sizeof(table));
    // 初始化哈希表
    initHashTable(ht);
    // 创建key值
    char* key[]={"a","b","c","d","e","f","g","h","i","j",
                "k","l","m","n","o","p","q","r","s","t",
                "u","v","w","x","y","z"};
    // 创建value
    char* value[]={"apple","banana","china","doge","egg","fox",
                "goat","hello","ice","jeep","key","love",
                "mirror","net","orange","panda","quarter","rabbit",
                "shark","tea","unix","volley","wolf","x-ray","yard","zoo"};
    // 将key和value插入哈希表中
    for(int i = 0; i < 26; i++)
    {
        insertnode(ht, key[i], value[i]);
    }
    // 显示哈希表
    display(ht);
}



