//
// Created by 方浩铭 on 2022/10/28.
//

#ifndef INC_03_3TREETRAVERSALSAGAIN_TREE_H
#define INC_03_3TREETRAVERSALSAGAIN_TREE_H

#endif //INC_03_3TREETRAVERSALSAGAIN_TREE_H


#include "stack.h"

const int maxSizeTree = 30;
int pre[31];
int in[31];
int post[31];

void postF(int preL,int inL, int post, int n);
void initTree(int numNode);

void initTree(int numNode){
    string str;
    int curNumI = 0;
    int curNumP = 0;
    class Stack S(maxSizeTree);

    for(int i = numNode* 2; i > 0; i--){
        cin >> str;
        if(str.length() == 4){
            cin >> str;
//            curNum = stoi(str);
            S.push(stoi(str));
            pre[curNumP++] = stoi(str);
        }
        else if(str.length() == 3){
            in[curNumI++] = S.pop();
        }

    }
}

void postF(int preL,int inL, int postL, int n)
{//传递进来先序，中序，后续遍历的初始位置和处理的长度n。
    int i,  L, R;
    int root;

    if(n == 0) return;
    if(n == 1) {
        post[postL] = pre[preL];
        return;
    }

    root = pre[preL];

    post[postL + n -1] = root;
    for(i = 0;i < n; i++)
        if(in[inL + i] == root) break;
    L = i;  R = n - L - 1;

    postF(preL+1,inL,postL,L);
    postF(preL + L + 1, inL + L + 1,postL + L,R);//Right

}

