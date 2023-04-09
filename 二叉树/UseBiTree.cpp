/*
    二叉链表的使用
*/

#include <iostream>
#include "BiTree.h"
#include "BiTree.cpp"

using namespace std;



int main(int argc, char* argv[])
{
	BiTree<char> T{};           // 定义对象变量T
	cout << "该二叉树的前序遍历序列是：" << endl;
	T.PreOrder();               // 前序遍历

	cout << "该二叉树的中序遍历序列是：" << endl;
	T.InOrder();

	cout << "该二叉树的后序遍历序列是：" << endl;
	T.PostOrder();

	cout << "该二叉树的层序遍历是：" << endl;
	T.LevelOrder();
	system("pause 0");
	return 0;

}