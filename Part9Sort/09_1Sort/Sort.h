//
// Created by 方浩铭 on 2022/11/9.
//

#ifndef INC_09_1SORT_SORT_H
#define INC_09_1SORT_SORT_H

#endif //INC_09_1SORT_SORT_H
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int ElementType;

void Swap(int *a,int *b);
void Merge_Sort( ElementType A[], int N );
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd );

void Bubble_Sort(int A[],int N)
{
    int P,i;
    int flag;
    for (P = N - 1; P >= 0 ; P--){
        flag = 0;
        for(i = 0; i < P; i++){
            if(A[i] > A[i + 1]){
                Swap(&A[i],&A[i+1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void Insertion_Sort(int A[],int N)
{
    int P,i;
    int Tmp;

    for(P = 1;P < N; P++){
        Tmp = A[P];
        for(i = P; i > 0 && A[i-1] > Tmp; i--)
            A[i] = A[i - 1];
        A[i] = Tmp;
    }
}

void Shell_sort( ElementType A[], int N )
{
    int D,P,i,Tmp;

    for ( D = N/2; D > 0; D /= 2 ) { /* 希尔增量序列 */
        for ( P = D; P < N; P++ ) { /* 插入排序 */
            Tmp = A[P];
            for ( i = P; i >= D && A[i-D] > Tmp; i -= D )
                A[i] = A[i-D];
            A[i] = Tmp;
        }
    }
}

void Shell_Sort( ElementType A[], int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
    int Si, D, P, i;
    ElementType Tmp;
    /* 这里只列出一小部分增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for ( Si=0; Sedgewick[Si]>=N; Si++ )
        ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

    for ( D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
        for ( P = D; P < N; P++ ) { /* 插入排序*/
            Tmp = A[P];
            for ( i=P; i >= D && A[i-D]>Tmp; i-=D )
                A[i] = A[i-D];
            A[i] = Tmp;
        }
}

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */

/* length = 当前有序子列的长度*/
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* 两两归并相邻有序子列 */
    int i, j;

    for ( i=0; i <= N-2*length; i += 2*length )
        Merge( A, TmpA, i, i+length, i+2*length-1 );
    if ( i+length < N ) /* 归并最后2个子列*/
        Merge( A, TmpA, i, i+length, N-1);
    else /* 最后只剩1个子列*/
        for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}

void Merge_Sort( ElementType A[], int N )
{
    int length;
    ElementType *TmpA;

    length = 1; /* 初始化子序列长度*/
    TmpA = (ElementType *)malloc( N * sizeof(ElementType) );
    if ( TmpA != NULL ) {
        while( length < N ) {
            Merge_pass( A, TmpA, N, length );
            length *= 2;
            Merge_pass( TmpA, A, N, length );
            length *= 2;
        }
        free( TmpA );
    }
    else printf( "空间不足" );
}

/* 归并排序 - 递归实现 */

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;

    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;

    while( L <= LeftEnd && R <= RightEnd ) {
        if ( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }

    while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* 核心递归排序函数 */
    int Center;

    if ( L < RightEnd ) {
        Center = (L+RightEnd) / 2;
        Msort( A, TmpA, L, Center );              /* 递归解决左边 */
        Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */
        Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */
    }
}

void MergeSort( ElementType A[], int N )
{ /* 归并排序 */
    ElementType *TmpA;
    TmpA = (ElementType *)malloc(N*sizeof(ElementType));

    if ( TmpA != NULL ) {
        Msort( A, TmpA, 0, N-1 );
        free( TmpA );
    }
    else printf( "空间不足" );
}


void PercDown( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort( ElementType A[], int N )
{ /* 堆排序 */
    int i;

    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
        PercDown( A, i, N );

    for ( i=N-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( &A[0], &A[i] ); /* 见代码7.1 */
        PercDown( A, 0, i );
    }
}

void Swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int A[],int N)
{
    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i + 1 < N)
            cout << " ";
    }
    cout << endl;
}




