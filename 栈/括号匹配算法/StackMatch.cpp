/*
    算法： Match(str)
    输入：以字符串str存储的算术表达式；
    输出：匹配结果，0表示匹配； 1表示多左括号；-1表示多右括号；
        1. 栈s初始化；
        2. 循环变量i从0开始依次读取str[i],直到字符串str结束（以'\0'结尾）；
            2.1 如果str[i]等于 '(' ,则将 '(' 压入栈s；
            2.2 如果str[i]等于')', 且栈为空，则从栈s中弹出一个'(' 与 ')'匹配；
            如果栈s为空，则多右括号，输出-1；
            2.3 如果栈s为空，则左右括号匹配，输出0；否则说明多左括号，输出1。
*/

#include <iostream>
#include <stack>


using namespace std;


int main()
{
    string str = "(ab+cd))";   // 输入表达式
    char s[100];                // 定义顺序栈
    int top=-1;                 // 栈顶指针
    
    // 遍历字符串,如果是以'('则入栈
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ')')           // 当前扫描的字符是右括号
        {
            if(top > -1) top--;     // 判断栈是否为空,不为空则出栈(也就是将'('出栈)
        
            else
            {
                // 匹配右括号，没有匹配的'('，则返回-1，表示多右括号
                cout<<"-1(多右括号)"<<endl;
                return -1;
            }
        }

        else if(str[i] == '(')      // 当前扫描字符是左括号
        {
            s[++top] = str[i];      // 执行入栈操作,将'('压入栈里
        }
    }
    if(top == -1)
    {
        cout<<"0(匹配正确)"<<endl;       // 栈空则括号正确匹配
    }     
    else
    {
        cout<<"1(多左括号)"<<endl;
    }




}