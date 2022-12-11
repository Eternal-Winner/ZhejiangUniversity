#include <iostream>
using namespace std;

int indegree[1001];
int cntSet[1001][1001];

typedef struct TblNode{
    int Size;
    int *Data;
}*HashTable;

int Hash(int x, int N);
HashTable initData(int N);

int main()
{
    int N,i; //Size of hash table ,tag
    cin >> N;
    HashTable Table = creatHash(N);


    return 0;
}

HashTable initData(int N)
{
    HashTable H = new TblNode;
    H->Size = N;
    H->Data = new int[H->Size];
    for(int i = 0; i < H->Size; i++)
        cin >> H->Data[i];

    return H;
}

int Hash(int x, int N)
{
    return (x%N);
}

int find()
{

}