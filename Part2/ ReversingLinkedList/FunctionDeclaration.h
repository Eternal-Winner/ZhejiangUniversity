//
// Created by 方浩铭 on 2022/9/25.
//

#ifndef _REVERSINGLINKEDLIST_FUNCTIONDECLARATION_H
#define _REVERSINGLINKEDLIST_FUNCTIONDECLARATION_H

#endif //_REVERSINGLINKEDLIST_FUNCTIONDECLARATION_H
#include <iostream>
using namespace std;



typedef struct ListNode* LinkedList;   //
struct ListNode{
    char* Address;    //This is the position of the node;
    int Data;       //This is an integer.
    char* Next;       //This ia the position of the next node;
    LinkedList Link;
};
struct ListInfo{
    char firstAddress[10];
    int count;
    int distant;
};



LinkedList readList();
void Attach(LinkedList *rear,char* address,int data,char* next);
//void Attach(LinkedList rear,char* address,int data,char* next);
LinkedList ReveringList(LinkedList L);
void PrintList(LinkedList L);