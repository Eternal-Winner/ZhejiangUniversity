#include "Structure.h"

int main() {
    int N,L;
    BinTree real,temp;
    cin >> N >> L;
    while(N){
        real = BuildTree(N);
        while (L > 0){
            temp = BuildTree(N);
            if(Judge(real,temp)) cout << "Yes";
            else cout <<"No";
            L -= 1;
            if(L > 0) cout << endl;
        }
        cin >> N >> L;
        if(N) cout << endl;
    }

}

//BinTree BuildTree(int N);
//BinTree Insert(BinTree BST, ElementType X);
//int Judge(BinTree real, BinTree temp);
