//
// Created by 方浩铭 on 2022/9/25.
//
#include "FunctionDeclaration.h"

extern ListInfo INFO_LIST;


LinkedList readList()
{
    LinkedList Front,Rear,temp;
    int data;
    char address[10], next[10];
    Front  = new ListNode; Front->Link = nullptr;
    Rear = Front;

    for(int i = 0;i < INFO_LIST.count; i++){
        cin >> address >> data >> next;
        Attach(&Rear,address,data,next); //Attach(Rear,address,data,next);////////////////////
    }

    temp = Front;
    Front = Front->Link;
    delete temp;

    return Front;
}

void Attach(LinkedList *rear,char* address,int data,char* next)
{
    LinkedList tempNode = new ListNode; tempNode->Link = nullptr;
    strcpy(tempNode->Address,address[10]);
    tempNode->Data = data;
    strcpy(tempNode->Next,next);
    (*rear)->Link = tempNode;   //rear->Link = tempNode;
    *rear = tempNode;      //rear = rear->Link;
}

LinkedList ReveringList(LinkedList L)
{

    return nullptr;
}

void PrintList(LinkedList L)
{
    while(L){
        cout << L->Address <<   L->Data << L->Next << endl;
        L = L->Link;
    }
}

