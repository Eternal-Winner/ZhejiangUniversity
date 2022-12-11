//
// Created by 方浩铭 on 2022/10/21.
//

#ifndef SIXDEGREESOFSPACE_SIXDEGREEOFSPACE2_H
#define SIXDEGREESOFSPACE_SIXDEGREEOFSPACE2_H

#endif //SIXDEGREESOFSPACE_SIXDEGREEOFSPACE2_H

#include "Queue.h"
#include "iomanip"
//#define MaxRelationship 33
#define MaxSize 1000
bool isVisited[MaxSize];
int level;


class SixDegreeOfSpace{
private:
    int numPeople;
//    int relationship[MaxSize][MaxSize];
    int **relationship;
    double *data;
public:
    SixDegreeOfSpace(int numPeople,int numEdge);

    void SDSpace(void);

    void BFS(int i);
};

SixDegreeOfSpace::SixDegreeOfSpace(int numPeo,int numEdge) {

    int p1, p2;

//    cin >> numPeople >> numEdge;
    this->numPeople = numPeo + 1;

    this->relationship = new int*[this->numPeople];
    for(int i = 0; i < this->numPeople; i++)
        this->relationship[i] = new int[this->numPeople];
    this->data = new double [this->numPeople];
    //初始化数组
    for(int i = 0; i < this->numPeople; i++){
        this->data[i] = 1;
        for(int j = 0; j <= this->numPeople; j++) this->relationship[i][j] = 0;
    }
    for(int i = 0; i < numEdge; i++){
        cin >> p1 >> p2;
        this->relationship[p1][p2] = 1;
        this->relationship[p2][p1] = 1;
    }
//    this->numPeople = numPeople;

}

void SixDegreeOfSpace::SDSpace() {
    cout << fixed << setprecision(2);
    for(int i = 1; i < this->numPeople; i++){
        level = 0;
        for(int i = 0; i  <= MaxSize; i++)   isVisited[i] = false;
        BFS(i);
        cout << i << ": " << (this->data[i] / (this->numPeople- 1))*100  << "%";
//        if (i + 1 == this->numPeople)   ; //////
//        else
            cout << endl;
    }
}

void SixDegreeOfSpace::BFS(int i) {
    int  last = i, tail, count = 1;
    int V  = i;
    Queue Que(this->numPeople);
    isVisited[V] = true;
    Que.enqueue(V);
    while (!Que.isEmpty()){
        V = Que.dequeue();
        for(int j = 1; j < this->numPeople; j++){
            if(!isVisited[j] && (this->relationship[V][j] || this->relationship[j][V])) {
                isVisited[j] = true;
                Que.enqueue(j);
//                this->data[i]++;
                count ++;
                tail =  j;
            }
        }
        if( V == last){
            level++;    last = tail;
        }
        if(level == 6) {break;}
    }
    this->data[i] = count;  ///////////////
}


