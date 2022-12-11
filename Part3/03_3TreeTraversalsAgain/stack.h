//
// Created by 方浩铭 on 2022/10/28.
//

#ifndef INC_03_3TREETRAVERSALSAGAIN_STACK_H
#define INC_03_3TREETRAVERSALSAGAIN_STACK_H

#endif //INC_03_3TREETRAVERSALSAGAIN_STACK_H

const int maxSSize = 30;

#include "iostream"
#include "string"
using namespace std;

class Stack{
private:
    int maxSizeStack;
    int Ele[maxSSize];
    int top;
public:
    Stack(int num);

    void push(int Ele);

    int pop();
};
Stack::Stack(int size){
    this->maxSizeStack = size;
    for(int i = 0;i < size; i++) Ele[i] = 0;
//    this->Ele = new int[maxSizeStack];
    this->top = -1;
}

void Stack::push(int Ele) {
    this->Ele[++top] = Ele;
}

int Stack::pop() {
    return Ele[top--];
}
