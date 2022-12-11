//
// Created by 方浩铭 on 2022/10/12.
//

#ifndef IFASAMESEARCHBINTREE_STRUCTURE_H
#define IFASAMESEARCHBINTREE_STRUCTURE_H

#endif //IFASAMESEARCHBINTREE_STRUCTURE_H
//
// Created by 方浩铭 on 2022/10/12.
//
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;
struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(int N);
BinTree Insert(BinTree BST, ElementType X);
bool Judge(BinTree real, BinTree temp);


BinTree BuildTree(int N)
{
    int data;
    BinTree BST = nullptr;
    while(N > 0){
        cin >> data;
        BST = Insert(BST,data);
        N--;
    }

    return BST;
}

BinTree Insert(BinTree BST, ElementType X)
{
    if( !BST ){//If the tree is empty,creating and returning the root node of BinaryTree.
        BST = new TreeNode;
        BST->Data = X;
        BST->Right = BST->Left = nullptr;
    }
    else{
        if( X < BST->Data)
            BST->Left = Insert(BST->Left,X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right,X);
        else    ;
    }
    return BST;
}

bool Judge(BinTree real, BinTree temp)
{
    if((!real) && (!temp))
        return true; //Both real & temp is nullptr
    else if( ((real == nullptr) && (temp != nullptr)) || ((real != nullptr) && (temp == nullptr)) )
        return false;
    else{//((real != nullptr) && (temp != nullptr))
        if(real->Data == temp->Data)
            return (Judge(real->Right ,temp->Right) && Judge(real->Left,temp->Left));
        else
            return false;
    }
}