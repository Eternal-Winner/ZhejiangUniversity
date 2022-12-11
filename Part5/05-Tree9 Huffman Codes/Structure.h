//
// Created by 方浩铭 on 2022/10/30.
//

#ifndef INC_05_TREE9_HUFFMAN_CODES_STRUCTURE_H
#define INC_05_TREE9_HUFFMAN_CODES_STRUCTURE_H

#endif //INC_05_TREE9_HUFFMAN_CODES_STRUCTURE_H

#include "iostream"
#include "string.h"
using namespace std;
const int MHSize = 64;

typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left;
    HuffmanTree Right;
};


typedef struct HeapStruct* MinHeap;
struct HeapStruct{
    HuffmanTree Element[MHSize];
    int Size;
};

MinHeap creatHeap(void );
void Insert(MinHeap H,HuffmanTree T);
HuffmanTree Delete(MinHeap H);
HuffmanTree creatHuffman();
int WPL(HuffmanTree T,int Depth);
HuffmanTree getInformation(int nInteger,MinHeap H);
bool Judge(void);
HuffmanTree buildHuffman(MinHeap H);

#include "MinHeap.h"
#include "HuffmanTree.h"