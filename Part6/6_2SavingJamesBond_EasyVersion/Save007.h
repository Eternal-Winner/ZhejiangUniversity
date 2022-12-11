//
// Created by 方浩铭 on 2022/10/19.
//

#ifndef INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007_H
#define INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007_H

#endif //INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007_H

#include <math.h>
#include <iostream>
#include "vector"
using namespace std;


#define DIAMETER 15
typedef int WeightType;
bool Result = false; //To judge 007 if could reach to the land


typedef struct Crocodile* Vertex;
struct Crocodile{
    WeightType G[2];
};

typedef struct GraphNode* Graph;
struct GraphNode{
    int numVer;     //Number of Crocodiles
    int jumpDistant; // D, the maximum distance that James could jump
    bool *isVisited;
    Vertex crocodiles;
}*allCro;
void InitGraph(void );
void Save007(void);
bool FirstJump(int C);
void DFS(int C);
bool Jump(int C1,int C2);
bool IsSafe(int C);

void InitGraph(void)
{
    int numCro, jDist;
    int x, y;
    allCro = new GraphNode;
    cin >> numCro >> jDist;
    allCro->numVer = numCro;
    allCro->jumpDistant = jDist;
    allCro->isVisited = new bool[numCro];
    allCro->crocodiles = new Crocodile[numCro];
    for (int i = 0; i < numCro; ++i) {
        cin >> x >> y;
        allCro->crocodiles[i].G[0] = x;
        allCro->crocodiles[i].G[1] = x;
        allCro->isVisited[i] = false;
    }

}


void Save007(void )
{
    for(int i = 0; i < allCro->numVer; i++){
        if(!allCro->isVisited[i] && FirstJump(i)){
            DFS(i);
            if(Result)  break;
        }
    }
    if(Result)  cout << "Yes";
    else    cout << "No";
}

bool FirstJump(int C)
{
   double CPDistant = sqrt(pow(allCro->crocodiles[C].G[0],2) + pow(allCro->crocodiles[C].G[1],2));
   if(CPDistant >= DIAMETER + allCro->jumpDistant)
       return true;
   else return false;
}

void DFS(int C)
{
    allCro->isVisited[C] = true;
    if(IsSafe(C))   return;

    for (int i = 0; i < allCro->numVer; ++i) {
        if(!allCro->isVisited[i] && Jump(C,i)){
            DFS(i);
            if(Result)  return;
        }
    }
}

bool Jump(int C1,int C2)
{
    int disX = allCro->crocodiles[C1].G[0] - allCro->crocodiles[C2].G[0];
    int disY = allCro->crocodiles[C1].G[1] - allCro->crocodiles[C2].G[1];
    double dist = sqrt(pow(disX,2) + pow(disY,2));

    if(allCro->jumpDistant >= dist) return true;
    else    return false;
}

bool IsSafe(int C)
{
    int disX = 50 - abs(allCro->crocodiles[C].G[0]);
    int disY = 50 - abs(allCro->crocodiles[C].G[1]);

    if(allCro->jumpDistant >= disX || allCro->jumpDistant >= disY)  {
        Result = true;
        return true;
    } else return false;

}

