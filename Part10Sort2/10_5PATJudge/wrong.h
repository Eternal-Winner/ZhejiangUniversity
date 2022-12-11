//
// Created by 方浩铭 on 2022/11/19.
//

#ifndef INC_10_5PATJUDGE_WRONG_H
#define INC_10_5PATJUDGE_WRONG_H

#endif //INC_10_5PATJUDGE_WRONG_H


void Shell_Sort(Rank A[],int N)
{
    /* 希尔排序 - 用Sedgewick增量序列 */
    int Si, D, P, i, j, f1, f2;
    Rank Tmp;
    /* 这里只列出一小部分增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for ( Si=0; Sedgewick[Si]>=N; Si++ )
        ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

    for ( D=Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
        for ( P = D; P < N; P++ ) { /* 插入排序*/
            Tmp = A[P];
            for ( i = P; i >= D && A[i-D].total_score <= Tmp.total_score
            && A[i-D].rank > Tmp.total_score; i -= D ){
                f1 = f2 = 0;
                if(A[i-D].total_score = Tmp.total_score){
                    for(j = 1;j < M; j++){
                        if (A[i - D].s[j] == FullScore[j]) f1++;
                        if (A[i].s[j] == FullScore[j]) f2++;
                    }
                    if(f2 > f1){
                        A[i].rank = A[i - D].rank;
                        r[A[i].rank] = i;
                    }
                    else if(f2 = f1){
                        if(A[i].user_id > A[i].user_id) {
                            A[i].rank = A[i - D].rank;
                            r[A[i].rank] = i;
                        }
                    } else ;

                } else {// A[i-D].total_score < Tmp.total_score
                    A[i].rank = A[i - D].rank;
                    r[A[i].rank] = i;
                }
            }
            A[i].rank = Tmp.rank;
            r[A[i].rank] = i;
         }
}
