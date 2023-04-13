#include "BST.h"
#include "BST.cpp"



int main(int argc, char* argv[])
{


    BSTree<int> b;
    b.insert(20);
    bool flag = b.insert(10);
    b.insert(4);
    b.insert(15);
  
    bool flag2 = b.find(20);
    bool flag3 = b.erase(15);
    b.Traverse(); 

    cout<<flag<<endl;
    cout<<flag2<<endl;
    cout<<flag3<<endl;
    cout<<"test"<<endl;
    return 0;
}