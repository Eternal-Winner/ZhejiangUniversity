#include <iostream>
using namespace std;

int & maxSubseqSum1(int len,int A[]);


int main(void)
{
    int len, *numArray,*result = NULL;

    cin >> len;
    numArray = new int[len + 1];
    for(int i = 0; i < len; i++){
        cin >> numArray[i];
    }

    result = &maxSubseqSum1(len,numArray);


    cout << result[0] <<" "<< result[1] << " " << result[2];

    ;

    return 0;
}

int & maxSubseqSum1(int len,int A[])    //函数返回值引用类型
{
    int *result = new int[3]; //result分别记录最大子列及其第一项和最后一项。
    int thisSum, maxSum,tag = 0, *zero = NULL;
    thisSum = maxSum = 0;

    result[1] = result[2] = A[0];
    int *curFront = &A[0]; //用来记录临时的最大子列和表头

    for(int i = 0; i < len; i++)
    {
        thisSum += A[i];

        if(thisSum > maxSum){
            maxSum = thisSum;
            result[0] = maxSum;
            result[2] = A[i];
            if(*curFront > 0) result[1] = *curFront;
        }
        else if(A[i] == 0){//tag 为真，则0可能为最大子列和
            if(!tag) zero = &A[i];      //体现出指针指向的是地址，所有A[i]用&。
            tag += 1;
        }
        else if (thisSum < 0){
            thisSum = 0;
            if(i < len - 1)
                curFront = &A[i + 1]; //可能导致溢出，如果数列的合为负，那么重新计算最大数列的首个数值
        }
    }

    if(maxSum == 0 && !tag ){
        result[0] = 0;
        result[1] = A[0];
        result[2] = A[len-1];
    }
    if(maxSum == 0 && tag){
        result[0] = 0;
        result[1] = *zero;      //对取地址符进行解引，得到存储在zero的值。
        result[2] = *zero;  //其实根本不需要这个指针 不过该方式能体现出做题中的思路

    }

    return *result;
}
