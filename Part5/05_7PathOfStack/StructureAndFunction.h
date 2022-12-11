//
// Created by 方浩铭 on 2022/10/14.
//



#ifndef INC_05_7PATHOFSTACK_STRUCTUREANDFUNCTION_H
#define INC_05_7PATHOFSTACK_STRUCTUREANDFUNCTION_H


#endif //INC_05_7PATHOFSTACK_STRUCTUREANDFUNCTION_H

#include <iostream>
#include <stdint.h>

using namespace std;

#define ElementType int
#define MaxSize  1000

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
    ElementType* Element;
    int Size;
    int Capacity;
};


MinHeap CreatHeap(void);
bool Insert(MinHeap MH,ElementType Data);
void Output(MinHeap MH,int i);



MinHeap CreatHeap(void )
{//Creating empty MinHeap with  MaxSize Capacity
    MinHeap MH = new HeapStruct;
    MH->Element = new ElementType[MaxSize+1]; // ((MaxSize + 1) * sizeof (ElementType))
    MH->Size = 0;
    MH->Capacity = MaxSize;
    MH->Element[0] = INT16_MIN;
    //Defining guard that bigger than all element exist in MH->Element;

    return MH;
}

bool Insert(MinHeap MH,ElementType Data)
{
    int i;

    if(MH->Size >= MH->Capacity) {
        cout << "HeapIsFull";
        return false;
    }
    i = ++MH->Size;     //The i points out last member of stack;
    for(;MH->Element[i/2] > Data;i /= 2){
        MH->Element[i] = MH->Element[i/2];
    }
    MH->Element[i] = Data;

    return true;

}
void Output(MinHeap MH,int i)
{
    if(!i) return;
    else{
        for(;i > 0;i /= 2){
            cout << MH->Element[i];
            if(i/2 > 0) cout << " ";
        }
    }
}