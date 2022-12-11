//
// Created by 方浩铭 on 2022/10/30.
//

#ifndef INC_05_TREE9_HUFFMAN_CODES_HAFUFMANTREE_H
#define INC_05_TREE9_HUFFMAN_CODES_HAFUFMANTREE_H

#endif //INC_05_TREE9_HUFFMAN_CODES_HAFUFMANTREE_H

//#include "Structure.h"

extern char C[MHSize];
extern int N[MHSize];
extern int nInteger;
extern int rightLength;

HuffmanTree creatHuffman()
{
    HuffmanTree T;
    T = new TreeNode;
    T->Weight = 0;
    T->Right = T->Left = nullptr;

    return T;
}

HuffmanTree buildHuffman(MinHeap H)
{
    int i; HuffmanTree T;
    int size = H->Size;
    for(i = 1; i < size; i++){
        T = creatHuffman(); //Miss this statement will deduce all node same;
        T->Left = Delete(H);

        T->Right = Delete(H);

        T->Weight = T->Right->Weight + T->Left->Weight;

        Insert(H,T);
    }

    T = Delete(H);

    return T;
}

HuffmanTree getInformation(int nInteger,MinHeap H)
{
    HuffmanTree T ;
    for(int i = 0;i < nInteger; i++){
        cin >> C[i] >> N[i];
        T = creatHuffman();
        T->Weight = N[i];
        Insert(H,T);
    }
    return T;
}

bool Judge(void)
{
    bool Tag = true;
    int frequency,length = 0, j;
    char c, str[MHSize];
//    HuffmanTree T = new TreeNode; every step following T->next;
    HuffmanTree headT = new TreeNode, curT;


    for(int i = 0; i < nInteger; i++){
//        if(strlen(str) >= nInteger) Tag = false;
        frequency = N[i];//
        cin >> c >> str;
        curT = headT;

        for(j = 0; c != C[j]; j++);
        frequency = N[i];

        for (j = 0; j < strlen(str); ++j) {
            if(str[j] == '0'){
                if(!curT->Left)//The left child-tree is empty
                    curT->Left = creatHuffman();
                curT = curT->Left;
            }
            else if(str[j] == '1') {//The right chile-tree is empty
                if(!curT->Right)
                    curT->Right = creatHuffman();
                curT = curT->Right;
            }

            if(curT->Weight) {
                Tag = false;
//                return Tag;
            }
        }
        if(curT->Left || curT->Right)  {
            Tag = false;
//            return Tag;
        }
        else
            curT->Weight = frequency;
        length += (strlen(str) * curT->Weight);
    }
    if(length != rightLength)
        Tag = false;

    return Tag;
}




