#include <iostream>
using namespace std;

const int MaxDigit = 2;
const int Radix =  10;

typedef struct Node* PtrToNode;
struct Node{
    int key;
    PtrToNode next;
};


typedef struct HeadNode{
    PtrToNode  head ,tail;
} Bucket[Radix];


int GetDigit(int X, int D);
void LSDRadixSort(int A[], int N);
void GetInform(int A[], int N);

int main(void)
{
    int N, A[100000], result[51] = {0};
    cin >> N;
    GetInform(A, N);
    LSDRadixSort(A,N);

    for(int i = 0; i < N; i++){
        result[A[i]]++;
    }

    for(int j = 0; j < 51; j++){
        if(result[j] == 0) continue;
        else{
            cout << j << ":" << result[j] << endl;
        }
    }

    return 0;
}

void LSDRadixSort(int A[], int N)
{
    int D, Di, i;
    Bucket B;
    PtrToNode tmp, p ,List = NULL;

    for( i = 0; i < Radix; i++)
        B[i].head = B[i].tail = NULL;
    for(i = 0; i < N; i++){
        tmp = new Node;
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }

    // Starting sort
    for(D = 1; D < MaxDigit; D++){ //Addressing every term with loop;
        //Following is process for allocation;
        p = List;
        while (p){
            Di = GetDigit(p->key, D); // Getting current number for current element;
            /* Deletion current ele from List*/
            tmp = p; p = p -> next;
            /* Insertion tmp into Bucket B[Di]*/
            tmp->next = NULL;
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else{
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }
        //Following is process for collection;
        List = NULL;
        for(Di = Radix-1; Di >= 0; Di--){
            if(B[Di].head){//If the bucket is noEmpty
                //Full bucket inserts into List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL;
            }

        }
    }
    for(i = 0; i < N; i++){
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        delete tmp;
    }
}

int GetDigit(int X, int D)
{
    int d, i;

    for(i = 1; i < D; i++){
        d = X % Radix;
        X /= Radix;
    }

    return d;
}

void GetInform(int A[], int N)
{
    int value;
    for(int i = 0; i < N; i++){
        cin >> value;
        A[i] = value;
    }
}