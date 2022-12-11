//
// Created by 方浩铭 on 2022/9/30.
//

#ifndef Isomorphism_of_trees_DECLARATION_H
#define Isomorphism_of_trees_DECLARATION_H
#include "iostream"
using namespace std;

#endif //Isomorphism_of_trees_DECLARATION_H

typedef char Object;
typedef struct TreeNode *Tree;
struct TressNode{
    Object element;
    Tree firstChild;
    Tree nextChild;
};

Tree BuildTree();
void Attach(Tree *T,int fC, int nC);
Tree printTress(Tree T);
