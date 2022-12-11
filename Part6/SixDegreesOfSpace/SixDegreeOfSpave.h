//
// Created by 方浩铭 on 2022/10/21.
//

#ifndef SIXDEGREESOFSPACE_SIXDEGREEOFSPAVE_H
#define SIXDEGREESOFSPACE_SIXDEGREEOFSPAVE_H

#endif //SIXDEGREESOFSPACE_SIXDEGREEOFSPAVE_H

#include "Queue.h"
#define size 2;

typedef struct relationNode* rela;
struct relationNode{
    int o;
    int t;
};

class SixDegreeSpace{
private:
    int numP;   //The number of test people.
    int numM;   //The number of social relationship.
    rela aM; //All relationship between two point;
    int *rData;   //The data for number of every people's relationship;
public:
    SixDegreeSpace(void);

    void SDSpace(void);

    void BFS(int P);
};
SixDegreeSpace::SixDegreeSpace() {
    int nP, nM;
    int one, two;
    cin >> nP >> nM;
    this->numP = nP;    this->numM = nM;
    this->aM = new relationNode[this->numM];
    this->rData = new int[numP];
    for(int i = 0; i < nM; i++){
        cin >> one >> two;
        this->aM[i].o = one;
        this->aM[i].t = two;
    }
    while (nP--){
        this->rData[nP-1] = 0;
    }
}

void SixDegreeSpace::SDSpace() {
    for(int i = 0; i < numP; i++){

    }
}

void SixDegreeSpace::BFS(int P) {

}


