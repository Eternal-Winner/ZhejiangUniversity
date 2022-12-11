#include "Srtucture&Definition.h"

int main(void)
{
    MGraph MG = BuildGraph();

    ListComponents_DFS(MG);
    ListComponents_BFS(MG);


    return 0;
}