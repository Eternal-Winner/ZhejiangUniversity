#include "Structure.h"

char C[MHSize];
int N[MHSize], nInteger;
int rightLength;

int main() {
    int nPeople = 0;
    cin >> nInteger;
    HuffmanTree Root;

    MinHeap H;  H = creatHeap();
    getInformation(nInteger,H);
    Root = buildHuffman(H);
    rightLength = WPL(Root,0);
    cin >> nPeople;

    for(int i = 0; i < nPeople; i++){
        if(Judge())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}
