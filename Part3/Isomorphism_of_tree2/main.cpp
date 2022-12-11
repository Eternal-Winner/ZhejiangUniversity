
#include <iostream>

using namespace std;

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
int check[10];


struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(TreeNode *T);
int Isomorphic(Tree R1,Tree R2);

int main() {
    Tree R1,R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

//
// Created by 方浩铭 on 2022/10/2.
//

Tree BuildTree(TreeNode *T)
{
    int N, i;
    Tree  Root = Null;  //初始化为空树
    char cr,cl;
    for(i = 0;i < MaxTree;i++) check[i] = 0;


    cin >> N;
    if(N){

        for(i = 0;i < N; i++){
            cin >> T[i].Element >> cl >> cr;
            if(cl != '-'){
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }
            else T[i].Left = Null;
            // /*对cr的对应处理*/
            if(cr != '-'){
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }
            else T[i].Right = Null;
        }
        for(i = 0;i < N; i++)
            if(!check[i]) break;
        Root = i;//T[i]中没有任何节点的left 和right(cr)指向它。只有一个
    }

    return Root;
}

int Isomorphic(Tree R1,Tree R2)
{
    if((R1 == Null)&&(R2 == Null))  //both empty
        return 1;
    if( ((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)) )
        return 0;                   //one of them is empty
    if(T1[R1].Element != T2[R2].Element) //root are different
        return 0;
    if((T1[R1].Left == Null) && (T2[R2].Left == Null))  //both have no left subtree
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if ((T1[R1].Right == Null) && (T2[R2].Right == Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if(((T1[R1].Left != Null)&&(T2[R2].Left != Null)) &&
       ((T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)))
//        no need to swap the left and the right
        return (Isomorphic(T1[R1].Left,T2[R2].Left) &&
                Isomorphic(T1[R1].Right,T2[R2].Right));
    else    //need to swap the left and the right
        return (Isomorphic(T1[R1].Left,T2[R2].Right) &&
                Isomorphic(T1[R1].Right,T2[R2].Left));

}


