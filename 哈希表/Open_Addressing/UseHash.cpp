#include "hash_openAddressing.h"
#include "hash_OpenAddressing.cpp"


int main(int argc, char* argv[])
{
    HashTable<int> h1;
    
    h1.Insert('c');
    h1.Insert(3);
    h1.Insert(2);
    h1.Insert(4);
    h1.Insert(5);
    h1.Insert(6);
    h1.Insert(7);
    h1.Insert(9);
    h1.Print();

    h1.Delete(5);               // 删除
    h1.Print();

    h1.Insert(48);
    h1.Print();

    h1.Search(6);               // 查找

}