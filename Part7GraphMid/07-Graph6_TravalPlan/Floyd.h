//
// Created by 方浩铭 on 2022/11/3.
//

#ifndef INC_07_GRAPH6_TRAVALPLAN_FLOYD_H
#define INC_07_GRAPH6_TRAVALPLAN_FLOYD_H

#endif //INC_07_GRAPH6_TRAVALPLAN_FLOYD_H
#include "iostream"
using namespace std;

#define INF 100000
typedef int Vertex;

struct weight{
    int dist;
    int price;
};

const int MaxCity = 500;
weight CityDis[MaxCity][MaxCity];
int N, M;

void InitData();
void buildGraph();
void Floyd();
void BestOption(Vertex vStart, Vertex vEnd);
void Operation();

void Operation()
{
    int S, D;
    cin >> N >> M >> S >> D;
    InitData();
    buildGraph();
    Floyd();
    BestOption(S,D);
}

void Floyd() {
    Vertex k, i, j;

    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (CityDis[i][k].dist + CityDis[k][j].dist == CityDis[i][j].dist
                    && CityDis[i][k].price + CityDis[k][j].price < CityDis[i][j].price) {
                    CityDis[i][j].price = CityDis[i][k].price + CityDis[k][j].price;
                    //CityDis[i][j].price = CityDis[i][k].price + CityDis[i][k].price; 怨种找两天
                }else if(CityDis[i][k].dist + CityDis[k][j].dist < CityDis[i][j].dist){
                    CityDis[i][j].dist = CityDis[i][k].dist + CityDis[j][k].dist;
                    CityDis[i][j].price = CityDis[i][k].price + CityDis[k][j].price;
                    //CityDis[i][j].price = CityDis[i][k].price + CityDis[k][j].price; 怨种找两天
                }
}


void InitData()
{
    Vertex i, j;

    for(i = 0; i < MaxCity; i++)
        for(j = 0; j < MaxCity; j++){
            if(i == j){
                CityDis[i][j].dist = 0;
                CityDis[i][j].price = 0;
            }
            else{
                CityDis[i][j].dist = INF;
                CityDis[i][j].price = INF;
            }
        }
}

void buildGraph()
{
    Vertex m , n;
    int price, dist;

    for(int i = 0; i < M; i++){
        cin >> m >> n >>  dist >> price ;
        CityDis[m][n].dist =  CityDis[n][m].dist = dist;
        CityDis[m][n].price = CityDis[n][m].price = price;
    }
}


void BestOption(Vertex vStart, Vertex vEnd)
{

    cout << CityDis[vStart][vEnd].dist << " " << CityDis[vStart][vEnd].price;

}