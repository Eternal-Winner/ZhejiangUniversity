In computer science, an AVL tree (Georgy Adelson-Velsky and Evgenii Landis' tree, named after the inventors) is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one. (Quoted from wikipedia)
For each given binary search tree, you are supposed to tell if it is an AVL tree.

Input Specification:
Each input file contains several test cases. The first line gives a positive integer K (≤10) which is the total number of cases. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary search tree. The second line gives the preorder traversal sequence of the tree with all the keys being distinct. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in a line "Yes" if the given tree is an AVL tree, or "No" if not.

Sample Input:
```
3
7
50 40 36 48 46 62 77
8
50 40 36 48 46 62 77 88
6
50 40 36 48 46 62
```
Sample Output:
```
Yes
No
No
```
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int factor;//用作标记最大平衡因子

typedef struct TreeNode* pNode;
typedef struct TreeNode AVLTree;
struct TreeNode{
    int weight,height;
    pNode Left;
    pNode Right;
};


pNode newNode(int weight){
    pNode nNode = new TreeNode;
    nNode->weight = weight;
    nNode->height = 1;
    nNode->Left = NULL;
    nNode->Right = NULL;
    
    return nNode;
}

int getHeight(pNode root){
    if (!root)
    {
       return 0;
    }
    return root->height;
}

int getBalanceFactor(pNode root)
{
    return getHeight(root->Left) - getHeight(root->Right);
}

void updateHeight(pNode root){
    root->height = max(getHeight(root->Right),getHeight(root->Left))+1;
}

void Insertion(pNode &root,int  weight)
{
    if(!root){//root == NULL
        root = newNode(weight);
    }else{
        if(weight > root->weight){
            Insertion(root->Right, weight);
            updateHeight(root);//!!Don't forget
        }else{
            Insertion(root->Left,  weight);
            updateHeight(root);//!!Don't forget
        }
    }
}

pNode creatTree(int num){
    pNode root = NULL;
    for(int i = 0; i < num; i++){
        int tmp;
//        cin >> tmp ;
        scanf("%d",&tmp);
        Insertion(root,tmp);
    }
    return root;
}

void Judge(pNode root){
    if(!root)
        return;
    int tmp = getBalanceFactor(root);
    factor = max(abs(tmp),factor);
    Judge(root->Left);
    Judge(root->Right);
    
}
         

int main(void)
{
    int casesCount,num,tag;
    cin >> casesCount;
    for(int i = 0; i < casesCount; i++){
        pNode root;
        cin >> num;
        factor = 0;
        root = creatTree(num);
        Judge(root);
        if(factor > 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    
    return 0;
}
```
