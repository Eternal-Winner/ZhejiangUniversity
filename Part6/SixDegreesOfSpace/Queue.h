//
// Created by 方浩铭 on 2022/10/21.
//

#ifndef SIXDEGREESOFSPACE_QUEUE_H
#define SIXDEGREESOFSPACE_QUEUE_H

#endif //SIXDEGREESOFSPACE_QUEUE_H

#include "iostream"
using namespace std;

typedef int ElementQueue;

class Queue{
private:
    ElementQueue *Que;
    int maxSize;
    int front;
    int tail;
public:
    Queue(int numQue);

    bool enqueue(ElementQueue e);

    ElementQueue dequeue(void);

    bool isEmpty();
};

Queue::Queue(int numQue) {
//    this->maxSize = numQue/2 + 1;
    this->maxSize = numQue;
    this->Que = new ElementQueue [this->maxSize];
    this->front = this->tail = -1;
}

bool Queue::enqueue(ElementQueue e) {
    if((this->tail + 1) % this->maxSize == this->front)   return false;//The queue is full
    else{
        this->tail = (this->tail + 1) % this->maxSize ;
        this->Que[this->tail] = e;
    }
    return true;
}
ElementQueue Queue::dequeue() {
    if (this->front == this->tail)  return false;
    else{
        this->front = (this->front + 1) % maxSize;
        return this->Que[this->front];
    }
}

bool Queue::isEmpty() {
    if (this->front == this->tail)
        return true;
    else    return false;
}

