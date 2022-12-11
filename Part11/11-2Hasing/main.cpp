/*
 * Consideration minimum prime;
 * Don't store the status of output;
 * */

#include <iostream>
#include <math.h>
using namespace std;

#define WRONG -1 // Cannot to insert

typedef int Position;
typedef struct TblNode{
    int TableSize;
    int *Head;
} *HashTable;

HashTable creatTable(int N);
int getPrime(int N);
bool insert(HashTable H, int K);
Position Hash(int MSize, int key);
Position find(HashTable H, int Key);

int main() {
    int i, MSize, N , key;
    HashTable H;
    cin >> MSize >> N;
    H = creatTable(MSize);
    for(i = 0; i < N; i++){
        cin >> key;
        insert(H,key);
        if(i+1 == N)
            cout << endl;
        else
            cout << " ";
    }

}

int getPrime(int N)
{
    if(N == 1) return 2; //Minimum
    int i = (N % 2) ? N + 2 : N + 1, j;
    for(; true; i += 2){
        for(j = (int)sqrt(i);j > 2; j--)
            if(i%j == 0) break;
        if(j == 2) break;
    }
    return i;
}

HashTable creatTable(int N)
{
    HashTable H;
    int prime = getPrime(N);
    H = new TblNode;

    H->TableSize = prime;
    H->Head = new int[H->TableSize];
    for (int (i) = 0; (i) < H->TableSize; ++(i))
        H->Head[i] = 0;
    return H;
}
Position Hash(int MSize, int key)
{
    return (key % MSize);
}
Position find(HashTable H, int Key)
{
    Position curPos, newPos;
    int cNum = 0; // Recode clash times.

    newPos = curPos = Hash(H->TableSize,Key);
    while (H->Head[newPos] != 0 && H->Head[newPos] != Key){
        if(++cNum%2)//odd times clash
            newPos = (curPos + (cNum+1)*(cNum+1)/4) % H->TableSize; // Increment is +[(cNum+1)/2]^2

        if(cNum == H->TableSize) {
            newPos = WRONG;
            break;
        }
    }

    return newPos;
}
bool insert(HashTable H, int K)
{
    Position p = find(H,K);


    if(p == WRONG) {cout << "-";}
    else{
        H->Head[p] = K;
        cout << p;
    }
    return true;
}

