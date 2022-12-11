#include "tree.h"

int main() {
    int  N;
    cin >> N;
    initTree(N);

//    for(int i = 0; i < N; i++){
//        cout << in[i];
//    }

    postF(0,0,0,N);

//    int i;
    for(int i = 0; i < N; i++){
        cout << post[i];
        if(i+1 != N) cout << " ";
    }

    return 0;
}


