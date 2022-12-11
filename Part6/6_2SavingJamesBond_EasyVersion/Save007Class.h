//
// Created by 方浩铭 on 2022/10/20.
//

#ifndef INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007CLASS_H
#define INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007CLASS_H


#include "Crocodile.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#endif //INC_6_2SAVINGJAMESBOND_EASYVERSION_SAVE007CLASS_H

//
// Created by 方浩铭 on 2022/10/20.
//



class Save007Class{
private:
    vector<Crocodile> crocodiles;
    int* isVisited;
    int MaxdDistance;
    int Maxnum;
public:
    Save007Class(int maxnum,int jumpDistance){
        this->Maxnum = maxnum;
        this->isVisited = new int[maxnum];
        this->MaxdDistance = jumpDistance;
        for ( int i = 0 ; i < this->Maxnum ; i++){
            int x,y;
            cin>>x>>y;
            Crocodile tmp(x,y);
            this->crocodiles.push_back(tmp);
            this->isVisited[i] = 0;
        }
    }
    //判断该鳄鱼是否能让007跳上岸
    int Judge(Crocodile crocodile)
    {
        int distX = 50 - abs(crocodile.getX());
        int distY = 50 - abs(crocodile.getY());
        if ( distX <= this->MaxdDistance || distY <= this->MaxdDistance){
            return 1;
        }else{
            return 0;
        }
    }
    //计算007是否能跳到这只鳄鱼上
    int Caculate(Crocodile crocodile1,Crocodile crocodile2,double jump_distance){
        int distX = crocodile1.getX() - crocodile2.getX();
        int distY = crocodile1.getY() - crocodile2.getY();
        double dist = sqrt(pow(distX,2)+ pow(distY,2));
        if (dist <= jump_distance){
            return 1;
        }else{
            return 0;
        }
    }
    //DFS遍历
    void DFS(int start)
    {
        this->isVisited[start] = 1;
        if (this->Judge(this->crocodiles[start])){
            cout<<"Yes";
            exit(0);
        }else{
            for ( int i = 0 ; i < this->Maxnum ; i++){
                int judge = this->Caculate(this->crocodiles[start],this->crocodiles[i],this->MaxdDistance);
                if ( !this->isVisited[i] && judge){
                    DFS(i);
                }
            }
        }
    }
    void Save()
    {
        vector<int> first_jump;
        //第一跳单独拿出来
        for ( int i = 0 ; i < this->Maxnum ; i++){
            Crocodile tmp(0,0);
            if (this->Caculate(this->crocodiles[i], tmp ,this->MaxdDistance+7.5)){
                first_jump.push_back(i);
            }
        }
        if ( first_jump.empty()){
            cout<<"No";
            return;
        }else{
            for (int i = 0 ; i < first_jump.size() ; i++){
                DFS(first_jump[i]);
            }
            cout<<"No";
            return;
        }
    }
};