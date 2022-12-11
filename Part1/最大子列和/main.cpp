#include <iostream>
using namespace std;

int maxSubseqSum1(int A[],int num);

int main(void)
{
    int num, numArray[100000],maxSubseq;
    cin >> num ;
    for(int i = 0;i < num;i++){
        cin >> numArray[i];
    }
    maxSubseq = maxSubseqSum1(numArray,num);
    cout << maxSubseq;

    return 0;
}

int maxSubseqSum1(int A[],int num)
{
    int ThisSum,MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i = 0; i < num; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}