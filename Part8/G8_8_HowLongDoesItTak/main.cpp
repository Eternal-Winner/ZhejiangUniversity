/*
 * problem:
 * 1.Judging the scheduling is imposable
 * 2.How to judge the earliest time;
 *
 * 1.If all activity don's exits loop, it is possible.
 * 2.The biggest number is the earliest time;
 *
 * Judging if existing loop
 * 1.求出图中所有顶点的度，
 * 2.删除图中所有度<=1的顶点以及与该顶点相关的边，把与这些边相关的顶点的度减一
 * 3.如果还有度<=1的顶点重复步骤2.
 * 4.最后如果还存在未被删除的顶点，则表示有环；否则没有环
 * */

#include <iostream>
#include <queue>
using namespace std;
typedef int Vertex;
typedef int** Graph;

const int MaxSize = 100;

class Solve;


class Solve{
private:
    Graph ConnectSet;
    int Nv;/*N (≤100) ,The number of activity check points
        * (hence it is assumed that the check points are numbered from 0 to N−1),*/
    int Ne;/*M, the number of activities. */
    int *Indegree;  //The indegree of vertex;
    int *Earliest;
public:
    Solve();
    bool TopSort();
};

bool Solve::TopSort() {
    int cnt = 0;
    queue<Vertex> q;
    Vertex v;

    for(Vertex  v = 0; v < this->Nv; v++)
        if(!Indegree[v]){ //If indegree is 0 , pushing it into queue;
            q.push(v);
            this->Earliest[v] = 0;
        }

    while (!q.empty()){
        v = q.front();
        q.pop();
        cnt ++;
        for(Vertex w = 0; w < this->Nv; w++)
            if(this->ConnectSet[v][w] != -1){
                if(this->Earliest[w] < Earliest[v] + this->ConnectSet[v][w])
                    Earliest[w] = Earliest[v] + this->ConnectSet[v][w] ;
                if(--this->Indegree[w] == 0)
                    q.push(w);
            }
    }

    if(cnt != this->Nv)
        cout << "Impossible";
    else{
        //Maybe not alone one destination;
        int max = 0;
        for(Vertex v = 0; v < this->Nv; v++){
            if(max < Earliest[v])
                max = Earliest[v];
        }
        cout << max;
    }

}

Solve::Solve() {
    int i, value;
    Vertex x, y;
    cin >> this->Nv >> this->Ne;

    this->Indegree = new Vertex [this->Nv];
    this->Earliest = new Vertex  [this->Nv];
    this->ConnectSet = new Vertex *[this->Nv];

    for(i = 0; i < this->Nv ; i++){
        Indegree[i] = 0;
        this->Earliest[i] = -1;
        this->ConnectSet[i] = new Vertex [this->Nv];

        for(int j = 0; j < this->Nv; j++)
            this->ConnectSet[i][j] = -1;
    }

    for(i = 0; i < Ne; i++){
        cin >> x >> y >> value;
        this->ConnectSet[x][y] = value;
        this->Indegree[y]++;//Indegree ++
    }
}

int main() {
    Solve Sol = Solve();
    Sol.TopSort();

    return 0;
}






