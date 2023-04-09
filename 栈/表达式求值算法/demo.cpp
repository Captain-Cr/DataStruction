#include <iostream>
using namespace std;


/*
    算法：表达式求值
    需求：设运算符有+、-、*、/、#和圆括号，其中#为表达式的定界符，对于任意给定的表达式进行求值运算，给出求值结果；（例如: (4 + 2) * 3 - 5)
    输出：该表达式的值
        1、将栈OPND(运算对象栈，用来保存数字)初始化空，将栈OPTR（运算符栈， 用来保存运算符）初始化为表达式的定界符#；
        2、从左到右扫描表达式的每一个字符，并执行以下操作：
            2.1、 若当前的字符是运算对象，则入栈OPND;
            2.2、 若当前字符是运算符且优先级比OPTR的栈顶运算符的优先级高，则入栈OPTR,处理下一个字符；
            2.3、 若当前是运算符且优先级比OPTR的栈顶运算符的优先级低， 则从栈OPND出栈两个对象，从栈OPTR中出栈一个运算符进行计算，并将计算结果入栈到OPND，继续处理当前字符；
            2.4、 若当前是运算符且优先级与OPTR的栈顶运算符的优先级相等，则将栈OPTR的栈顶运算符出栈，处理下一个字符；
        3、输出栈OPND中的栈顶元素，即表达式的结果。


*/
class Expression
{
    public:
        Expression(string srt);           // 构造函数
        ~Expression();          // 析构函数
        int Compute();          // 计算表达式str的值

    private:
        int Comp(char str1, char str2);         // 比较str1和str2的值
        string str;
};

Expression::Expression(string str)
{
    // 构造函数接收字符表达式
    this->str = str + "#";
    cout<<this->str<<endl;
}

Expression::~Expression()
{
    // 析构函数
}


int Expression::Comp(char str1, char str2)
{
    // 计算当前运算符和OPTR栈顶运算符的优先级：
    // str1: 当前运算符           str2： OPTR栈顶运算符
    // 1： 表示str1的优先级高；   0： 表示优先级相同；     -1： 表示str1的优先级低。
    switch(str1)
    {
        case '+':case '-': if(str2 == '(' || str2 == '#')  return 1;       // 如果输入str1是 +-， str2是 (# 则返回1；    +-的优先级比( # 高
        case '*':case '/': if(str2 == '*' || str2 == '/') return -1;       // 如果输入str1是 */,  str2是 */,  返回-1；（应该不存在这种输入）
                            else return 1;                      break;      // 如果输入str1是 */,  str2是其他，则返回 1；  因为在这里*/的优先级是最高的
        case '(': return 1; break;              // 如果输入str1是（
        case ')': if(str2 == '(') return 0; else return -1;     break;          // str1是（，  str2是），正好进行括号匹配， 返回0
        case '#': if(str2 == '#') return 0; else return -1;     break;
        default: break;
    }
}


int Expression::Compute()
{
    // 定义两个顺序栈， OPND(运算对象栈)， OPTR(运算操作符栈)
    char OPND[100];
    char OPTR[100];

    int top_nd=-1, top_tr=0;     // 两个栈的栈顶指针
    OPTR[0] = '#';          // OPTR栈顶位置初始化为#

    // 遍历输入的字符串表达式
    for(int i=0; str[i] != '\0';)
    {
        // 如果输入的字符是数字，则OPND入栈
        if(str[i] >= 48 && str[i] <= 57)            // 数字'0'到'9'的ASCII码值为48 ~ 57
        {
            OPND[++top_nd] = str[i++] - 48;                   // 将字符转换成数字压栈（入栈）
        }

        else
        {
            int k = Comp(str[i], OPTR[top_tr]);            // 计算当前运算符和OPTR的栈顶运算符的优先级
            if(k == 1)              // k=1，说明当前运算符的优先级大于栈顶运算符，要进行入栈操作
            {
                OPTR[++top_tr] = str[i++];          // 入栈
            }
            else if(k == -1)        // k==-1,说明当前运算符的优先级小于栈顶运算符，要在对象栈OPND取两个元素 + 运算符栈取一个元素进行运算，将得到的结果入栈到OPND
            {
                int x = OPND[top_nd--];  int y = OPND[top_nd--];        // 取两个元素出来
                int op = OPTR[top_tr--];                                // 取一个运算符出来, 因为入栈的是int类型，所以要用int类型接收运算符
                switch(op)
                {
                    case '+': x = x + y;    break;
                    case '-': x = y - x;    break;      // 因为x是第一个从栈取出来，y是第二个，所以y在表达式中是第一个数字， 因此是y-x
                    case '*': x = x * y;    break;
                    case '/': x = y / x;    break;
                    default: break;
                }
                OPND[++top_nd] = x;                 // 运算结果入运算符对象栈
            }
            else
            {
                // 运算符优先级同级, 将运算符从运算符栈中出栈
                top_tr--;
                i++;            // 匹配str[i],扫描下一个字符
            }
        }
    }
    cout<<OPND[top_nd];
    return OPND[top_nd];                // 运算对象栈的栈顶元素即为运算结果
}



int main()
{
    string str = "(4+2)*3-5";
    Expression e{str};
    int result = e.Compute();      // result保存计算结果
    cout<<"表达式的值为："<<result<<endl;
    return 0;
}













