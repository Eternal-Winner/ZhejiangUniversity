#include "SixDegreeOfSpace2.h"


int main() {
    int numPeople, numEdge;
    cin >> numPeople >> numEdge;

    class SixDegreeOfSpace SDOS(numPeople,numEdge);

    SDOS.SDSpace();
}
