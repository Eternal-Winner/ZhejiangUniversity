//
// Created by 方浩铭 on 2022/10/20.
//

#ifndef INC_6_2SAVINGJAMESBOND_EASYVERSION_Save007_H
#define INC_6_2SAVINGJAMESBOND_EASYVERSION_Save007_H

#endif //INC_6_2SAVINGJAMESBOND_EASYVERSION_Save007_H
#include "vector"
#include "iostream"
#include "math.h"
using namespace std;


class Crocodile{
private:
    int x; //   x的坐标
    int y; //   y的坐标
public:
    Crocodile(int x,int y){
        this->x = x;
        this->y = y;
    }
    int getX(){
        return this->x;
    };
    int getY(){
        return this->y;
    }

};

class Save007{
private:
    vector<Crocodile> crocodiles;
    int maxNum;
    int maxDistant;
    bool *isVisited;
    bool Result;
public:
    Save007(int maxNum,int maxDistant);

    void Save(void );

    bool FirstJump(int C);   //From land to others place;

    bool IsSafe(Crocodile C1);//Judging if 007 could jump island from current point ;


    bool Jump(int C1, int C2);    //Judging if surrounding crocodiles could be get for  007;

    void DFS(int C);
};
Save007::Save007(int maxNum, int maxDistant){//构造函数
    int x,y;
    this->maxNum = maxNum;
    this->maxDistant = maxDistant;
    this->isVisited = new bool[maxNum];
    this->Result = false;
    for (int i = 0; i < this->maxNum; ++i) {
        cin >> x >> y;
        Crocodile temp(x,y);
        crocodiles.push_back(temp);
        this->isVisited[i] = false;
    }
}

void Save007::Save() {
//    if(this->maxDistant >= this->CPDistant)  Result = true;
//    else{
        for(int i = 0; i < this->maxNum; i++){
            if(!this->isVisited[i] && FirstJump(i)){
                DFS(i);
                if(this->Result)    break;
            }
        }
//    }
    if(this->Result) cout << "Yes";
    else    cout << "No";
}

bool Save007::FirstJump(int C) {
//    this->isVisited[C] = true;
    double dist = sqrt(pow(this->crocodiles[C].getX(),2) + pow(this->crocodiles[C].getY(),2));
    double maxDist = 15 + this->maxDistant;
    if(dist > maxDist)  return false;
    else    return true;

}
bool Save007::IsSafe(Crocodile C1) {
    int distX = 50 - abs(C1.getX());
    int distY = 50 - abs(C1.getY());
    if(this->maxDistant >= distX || this->maxDistant >=  distY)  return true;
    else    return false;
}


bool Save007::Jump(int C1, int C2) {
    int distX = abs(this->crocodiles[C1].getX()) - abs(this->crocodiles[C2].getX());
    int distY = abs(this->crocodiles[C1].getY()) - abs(this->crocodiles[C2].getY());
    double dist = sqrt(pow(distX,2) + pow(distY,2));
    if(dist <= this->maxDistant) return true;
    else    return false;
}

void Save007::DFS(int C) {
    this->isVisited[C] = true;
    if(IsSafe(crocodiles[C])) {
        this->Result = true;
        return;
    } else{
        for(int i = 0;i < this->maxNum; i++){
            if(!this->isVisited[i] && Jump(C,i)){
                DFS(i);
                if(this->Result) break;
            }
        }
    }
}

/*

int main(void)
{
    int maxNum,maxDistant;
    cin >> maxNum >> maxDistant;
    Save007 One(maxNum,maxDistant);

    One.Save();
}*/
