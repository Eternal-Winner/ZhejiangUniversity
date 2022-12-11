//
// Created by 方浩铭 on 2022/11/3.
//

#ifndef INC_07_GRAPH6_TRAVALPLAN_DJIKSTRA_H
#define INC_07_GRAPH6_TRAVALPLAN_DJIKSTRA_H

#endif //INC_07_GRAPH6_TRAVALPLAN_DJIKSTRA_H
#include "iostream"
using namespace std;

typedef int Vertex;

#define NOT_EXIST -1
#define INF 100000

struct Weight{
    int dis;    //distant
    int pri;    //price
};
const int MaxSize = 500;
bool collected[MaxSize];    //判断该点是否已经求出最短路
int dist[MaxSize];  //出发点s到图中每个城市的最短距离
int price[MaxSize];  //出发点s到图中每个城市的最短路费
Weight CityR[MaxSize][MaxSize]; //城市之间的距离和路费
int N,M;                //城市的数量
Vertex S,D;             //Start Destination

void Init();            //初始化需要使用的数据
void buildGraph();      //录入输入的信息
void Dijkstra(Vertex V);    //寻找最短路径
Vertex FindMinV();         //寻找距离当前集合最短的城市点
void Operation();           //完成所有操作


void Operation()
{
    Init();
    buildGraph();

    for(int i = 0; i < N; i++){
        if(CityR[S][i].dis != INF){
            dist[i] = CityR[S][i].dis;
            price[i] = CityR[S][i].pri;
        }
    }
    Dijkstra(S);
    cout << dist[D] << " " << price[D];
}


void Dijkstra(Vertex V)
{
    collected[V] = true;
    Vertex minDisV;
    int MIN = INF;

    while(1){
        minDisV = FindMinV();
        if(minDisV == NOT_EXIST)
            break;
        MIN = dist[minDisV];
        collected[minDisV] = true;
        for(int i = 0; i < N; i++)
//            if(!collected[i] && CityR[minDisV][i].dis != INF)
            if(!collected[i] && MIN + CityR[minDisV][i].dis < dist[i]){
                dist[i] = MIN + CityR[minDisV][i].dis;
                price[i] = price[minDisV] + CityR[minDisV][i].pri;
            } else if(!collected[i] && (MIN + CityR[minDisV][i].dis == dist[i])
            && (price[minDisV] + CityR[minDisV][i].pri < price[i]))
                //(price[V] + CityR[minDisV][i].pri < price[i]) 怨种找了两天
                price[i] = price[minDisV] + CityR[minDisV][i].pri;
    }
}

Vertex FindMinV()
{
    int minDistant = INF;
    Vertex minV;
    for(int i = 0; i < N; i++)
    {
        if(minDistant > dist[i] && !collected[i]){
            minDistant = dist[i];
            minV = i;
        }
    }
    if(minDistant == INF){
        return NOT_EXIST;
    } else{
        return minV;
    }
}

void Init()
{
    for(int i = 0;i < MaxSize; i++){
        collected[i] = false;
        dist[i] = INF;
        price[i] = INF;
        for (int j = 0; j < MaxSize; ++j) {
            if(i == j){
                CityR[i][j].dis = 0;
                CityR[i][j].pri = 0;
            } else {
                CityR[i][j].dis = INF;
                CityR[i][j].pri = INF;
            }
        }
    }
}

void buildGraph()
{
    cin >> N >> M >> S >> D;
    int distant, pri;
    Vertex V1,V2;
    for(int i = 0; i < M; i++) {
        cin >> V1 >> V2 >> distant >> pri;
        CityR[V1][V2].dis = CityR[V2][V1].dis = distant;
        CityR[V1][V2].pri = CityR[V2][V1].pri = pri;
    }
}