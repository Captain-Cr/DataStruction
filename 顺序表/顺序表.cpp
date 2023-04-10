/*
    -线性表的顺序存储结构称为顺序表（Sequential List），基本思想是用一段地址连续的存储单元依次存储线性表的数据元素
    -设顺序表的每个元素占用c个存储单元，则第i个元素的存储地址为：Loc（ai）=Loc（a1）+（i-1）*c
    -顺序表中数据元素的存储地址是其序号的线性函数，只要确定了存储顺序表的起始地址（即基地址），计算任意一个元素的存储地址的时间都是相等的，具有这一特点的存储结构称为随机存取（random access）结构
    -c++数组下标是从0开始的，而线性表中元素序号是从1开始的。
    -数组需要分配固定长度的数组空间，因此，必须确定存放线性表的数组空间的长度。因为在线性表中可以进行插入操作，则数组的长度就要大于当前线性表的长度。
*/

#include <iostream>
#include "SeqList.h"
#include "SeqList.cpp"
using namespace std;

int main()
{
    int r[5]={1,2,3,4,5};
    SeqList<int> l(r,5);  // 因为定义的是模板类，所以在定义对象时要输入数据类型<int>
    l.Length();
    int a=l.empty();
    int x=l.Get(2);
    l.Locate(5); 
    l.insert(3,10);
    l.Delete(3);
 


}