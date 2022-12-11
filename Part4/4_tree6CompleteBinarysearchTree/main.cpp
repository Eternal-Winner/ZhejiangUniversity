#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

const int BASE = 2;
const int MAXSIZE = 1000;
int T[MAXSIZE];
int A[MAXSIZE];

int compare(const void*a, const void*b);
int GetLeftLength(int n);
void solve(int ALeft, int ARight,int TRoot);
int min(int a, int b);

int main()
{
    for(int i = 0; i < MAXSIZE; i++) A[i] = T[i] = 0;
    int N ;
    cin >> N;
    for(int i = 0;i < N;i ++){
        cin >> A[i];
    }
    qsort(&A[0],N,sizeof (int),compare);

    solve(0,N - 1,0);

    for(int i = 0;i < N;i ++){
        cout << T[i];
        if((i + 1) == N) break;
        cout << " ";
    }


}

void solve(int ALeft, int ARight,int TRoot)
{
    int RightTRoot, LeftTRoot, L, n;
    n = ARight - ALeft + 1;
    if(n == 0) return ;
    L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    LeftTRoot = TRoot * 2 + 1;
    RightTRoot = LeftTRoot + 1;
    solve(ALeft,ALeft + L - 1, LeftTRoot);
    solve(ALeft + L + 1,ARight, RightTRoot);
}

int compare(const void*a, const void*b) //void* can point to every pointer for every type;
{
    return *(int*)a - *(int*)b;
}

int GetLeftLength(int n)//For getting length of left tree for a complete binary with n node;
{
    int X, H, LNode;
    H = log(n)/log(BASE);

    X = n - (pow(2,H) - 1);

    X = min(X,pow(2,H-1));

    LNode = pow(2,H-1) - 1 + X;


    return LNode;
}

int min(int a, int b)
{
    return a<b ? a:b;
}

