//
// Created by 方浩铭 on 2022/10/30.
//

#ifndef INC_05_TREE9_HUFFMAN_CODES_MINHEAP_H
#define INC_05_TREE9_HUFFMAN_CODES_MINHEAP_H

#endif //INC_05_TREE9_HUFFMAN_CODES_MINHEAP_H

//#include "Structure.h"


MinHeap creatHeap(void )
{
    MinHeap H = new HeapStruct;
    H->Size = 0;
    H->Element[0] = new TreeNode;
    H->Element[0]->Weight = INT16_MIN;
    H->Element[0]->Left = H->Element[0]->Right = nullptr;

    return H;
}

void Insert(MinHeap H,HuffmanTree T)
{
    int i;
    i = ++H->Size;  //Inserting i into the last element for H;
    for(;H->Element[i/2]->Weight > T->Weight ; i /= 2){
            H->Element[i] = H->Element[i/2];
    }
    H->Element[i] = T;
}

HuffmanTree Delete(MinHeap H)
{
    int Parent , Child;
    HuffmanTree MinItem, temp;
    if(!H) cout << "Empty";

    MinItem = H->Element[1];

    temp = H->Element[H->Size--];

    for(Parent = 1; Parent * 2 <= H->Size; Parent = Child){
        Child = Parent * 2;
        if((Child != H->Size) && (H->Element[Child]->Weight > H->Element[Child + 1]->Weight)) // wrong <
            Child++;
        if(temp->Weight <= H->Element[Child]->Weight) break; //wrong <
        else{
            H->Element[Parent] = H->Element[Child];
        }
    }
    H->Element[Parent] = temp;


    return MinItem;
}

int WPL(HuffmanTree T,int Depth)
{
    if(!T->Left && !T->Right)
        return (T->Weight * Depth);
    else //T has two child.
        return (WPL(T->Left,Depth + 1)  + WPL(T->Right,Depth+1));
}