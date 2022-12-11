#include "StructureAndFunction.h"



int main() {
    MinHeap MH;
    int N, M, i;
    ElementType data;
    MH = CreatHeap();

    cin >> N >> M;

    while (N > 0){
        cin >> data;
        Insert(MH,data);

        N -= 1;
    }

    while (M > 0){
        cin >> i;
        Output(MH,i);
        M -= 1;
        if(M) cout <<endl;
    }
}


















//#include "StructureAndFunction.h"
//
//int main() {
//   MinHeap MH;
//   int N, M, i;
//   ElementType data;
//   CreatHeap(MH);
//
//   cin >> N;
//
//    while (N > 0){
//        cin >> data;
//        Insert(MH,data);
//
//        N -= 1;
//    }
//
//    while (M > 0){
//        cin >> i;
//        Output(i);
//
//        M -= 1;
//    }
//}
