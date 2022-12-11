#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

#define KEYLENGTH 11
#define MAXD 5
#define MAXSIZE 100000

typedef char ElemType[KEYLENGTH+1];
typedef int Index;

typedef struct LNode *PtrToNode;
struct LNode{
    ElemType Data;
    PtrToNode Next;
    int Count;
};
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct TblNode{
    int TableSize;
    List Heads;
} *HashTable;

HashTable CreatTable(int N);
bool Insert(HashTable H, ElemType key);
void ScanAndOutput(HashTable H);
void DestroyTable( HashTable H );
int NextPrime(int N);
int Hash(int N1,int N2);

int main() {


    int N ,i;
    ElemType key;
    HashTable H;

    cin >> N;
    H = CreatTable(N * 2);
    for(i = 0; i < N; i++){
        cin >> key; Insert(H, key);
        cin >> key; Insert(H, key);
    }
    ScanAndOutput( H );
    DestroyTable( H );

    return 0;
}

int NextPrime(int N)
{//Return a number (N < number < MAXSIZE) that is prime
    int i, p = (N%2)? N+2 : N+1;
    while (p <= MAXSIZE){
        for(i = (int)sqrt(p); i > 2; i--)
            if( !(p%i) ) break; //p is not a prime
        if(i == 2) break; // loop break natural, the p is a prime
        else p += 2; //probe next odd number
    }

    return p;
}

HashTable CreatTable(int N)
{
    HashTable H;
    int i;
    H = new TblNode;
    H->TableSize  = NextPrime(N*2);
    H->Heads = new LNode[H->TableSize];
    for(i = 0; i < H->TableSize; i++){
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = nullptr;
        H->Heads[i].Count = 0;
    }

    return H;
}

Position Find(HashTable H, ElemType Key)
{
    Position P;
    Index Pos;

    //Original HashTable position
    Pos = Hash(atoi(Key+KEYLENGTH-MAXD),H->TableSize);

    P = H->Heads[Pos].Next; // Starting finds from the first node;
    // When unreach the rear of list and not find Key;
    while(P && strcmp(P->Data, Key))
        P = P->Next;

    return P; //The pinter point the has been found point or NULL;
}

bool Insert(HashTable H, ElemType key)
{
    Position P, NewCell;
    Index Pos;

    P = Find(H, key);
    if( !P ){//The key not exists in H, e
        NewCell = new LNode;
        strcpy(NewCell->Data,key);
        NewCell->Count = 1;
        Pos = Hash(atoi(key+KEYLENGTH-MAXD),H->TableSize);
        //Based on head-insert to insert NewCell to first node of H.
        NewCell->Next = H->Heads[Pos].Next;
        H->Heads[Pos].Next = NewCell;
        return true;
    }else{ // The key has  existed;
        P->Count++;
        return false;
    }
}
void ScanAndOutput(HashTable H)
{
    int i, MaxCnt = 0 ,PCnt = 0;
    ElemType MinPhone;

    List Ptr;
    MinPhone[0] = '\0';

    for(i = 0; i < H->TableSize; i++){//Scan LinkList
        Ptr = H->Heads[i].Next;
        while (Ptr){
            if(Ptr->Count > MaxCnt){//Update times of max call
                MaxCnt = Ptr->Count;
                strcpy(MinPhone,Ptr->Data);
                PCnt = 1;
            } else if(Ptr->Count == MaxCnt){
                PCnt++; //The number of crazing man adds onr;
                if(strcmp(MinPhone,Ptr->Data)>0)// MinPhone > Ptr->Data
                    strcpy(MinPhone,Ptr->Data);
            }
            Ptr = Ptr->Next;
        }
    }
    cout << MinPhone << " " << MaxCnt;
    if (PCnt > 1) cout << " " << PCnt ;
    cout << endl;

}

int Hash(int key,int p)
{
    return key%p;
}

void DestroyTable( HashTable H )
{
    int i;
    Position P, Tmp;

    /* 释放每个链表的结点 */
    for( i=0; i<H->TableSize; i++ ) {
        P = H->Heads[i].Next;
        while( P ) {
            Tmp = P->Next;
            free( P );
            P = Tmp;
        }
    }
    delete H->Heads; /* 释放头结点数组 */
    delete H ;        /* 释放散列表结点 */
}