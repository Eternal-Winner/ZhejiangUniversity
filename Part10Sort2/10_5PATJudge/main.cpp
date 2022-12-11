#include <iostream>
#include <iomanip>
using namespace std;

//cout<<setw(3) << setfill('0') <<ID<<endl;

int N, K , M, FullScore[5] ,*r;

struct Rank{
    int total = 0;
    int Score[6];
    int prefect = 0;
};

Rank* Initial();
/*
 * 主要将信息读入，这个函数任务先做简单的初始化，比如未提交，用户存在但没分数的你做最后比较如何标记，
 * 你都可以在初始化帮他们设定，比如我，未曾回答设个值，如果回答了，直接将值跟新。还有你每次提交是不
 * 是要跟新这个值，最后为他们统计个总分，这全部都可以在initial函数实现
  */
void Shell_Sort(Rank A[],int N);
bool Compare(Rank *R,int S1, int S2);
/*
 * 给分数做排序有个关键是为总分排序，而不是为每道题目排序，因此这个compare函数是定义排序规则
 * ，在这里排序的规则是总分咯，设定一下
 * */
void Output(Rank A[], int *R);

int main() {
    cin >> N >> K >> M;
    Rank *R = Initial();
    Shell_Sort(R,N);
    Output(R,r);

    return 0;
}

Rank* Initial()
{
    int i,j, flag;
    int ID , PID , PScore;

    for(i = 0; i < K; i++) cin >> FullScore[i];

    r = new int[N];
    Rank *R = new Rank[N];
    for(i = 0; i < N; i++){
        r[i] = i; // r[i] = i; r[i] = 0;
        for(j = 0; j < 5; j++)
            R[i].Score[j] = -2;  //Don't have any import;
    }
    for(i = 0; i < M; i++){
        cin >> ID >> PID >> PScore;
        if(R[ID-1].Score[PID-1] < PScore)
            R[ID - 1].Score[PID - 1] = PScore;
    }
    for(i = 0; i < N; i++){
        flag = 1;
        for(j = 0; j < K; j++){
            if(R[i].Score[j] >= 0){
                flag = 0;
                R[i].total += R[i].Score[j];
                if(R[i].Score[j] == FullScore[j])
                    R[i].prefect++;
            }
        }
        if(flag)
            R[i].total = -1;
    }


    return R;
}

void Shell_Sort(Rank A[],int N)
{
    /* 希尔排序 - 用Sedgewick增量序列 */
    int Si, D, P, i ,Tmp;
    /* 这里只列出一小部分增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for ( Si=0; Sedgewick[Si]>=N; Si++ )
        ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

    for ( D=Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
        for ( P = D; P < N; P++ ) { /* 插入排序*/
            Tmp = r[P];
            for(i = P; i >= D && Compare(A,Tmp,r[i-D]); i -= D)
                r[i] = r[i-D];
            r[i] = Tmp;
         }
}

bool Compare(Rank *RC,int Tmp, int C)
{//Rank[C].total < Rank[Tmp] swap
    if(RC[Tmp].total > RC[C].total)
        return true;
    else if(RC[Tmp].total == RC[C].total){
        if (RC[Tmp].prefect > RC[C].prefect)
            return true;
        else if(RC[Tmp].prefect == RC[C].prefect){
            if(Tmp < C)
                return true;
            else
                return false;
        } else //R[Tmp].prefect < R[C].prefect
            return false;
    }
    else//R[Tmp].total < R[C].total;
        return false;
}

void Output(Rank A[], int *rO)
{
    int i, j, rank, tmp;
    for(i = 0,rank = 1, tmp = A[rO[0]].total; i < N; i++){
        if(A[rO[i]].total == -1) break;
        if(A[rO[i]].total != tmp) {
            rank = i + 1;
            tmp = A[rO[i]].total;
        }
        cout << rank << " " << setw(5) << setfill('0') << rO[i] + 1 << " " << A[rO[i]].total << " ";
        for(j = 0; j < K; j++){
            if(A[rO[i]].Score[j] == -2) cout << "-" ;
            else if(A[rO[i]].Score[j] == -1) cout << "0";
            else cout << A[rO[i]].Score[j];
            if(j+1 != K)
                cout <<" ";
            else cout << endl;
        }
    }
}



