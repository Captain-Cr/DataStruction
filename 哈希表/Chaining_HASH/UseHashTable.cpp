#include "ChainHashTable.h"
#include "ChainHashTable.cpp"





int main(int argc, char* argv[])
{
    std::cout<<"test"<<std::endl;
    // 测试数据用例7-5
    int i;
    int r[9] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
    HashTable<int> HT;
    for(i = 0; i < 9; i++)
    {
        HT.Insert(r[i]);
    }
    HT.Print();
    HT.Search(7);

}