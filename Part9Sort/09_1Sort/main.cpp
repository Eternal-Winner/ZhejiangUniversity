#include "Sort.h"

int main() {
    int data[100000] , num;
    cin >> num;
    for(int i = 0;i < num; i++)
        cin >> data[i];


//    Insertion_Sort(data,num);
//    Bubble_Sort(data,num);
//   Shell_sort(data,num);
//    Shell_Sort(data,num);
//    Merge_Sort(data,num);
//    MergeSort(data,num);

      HeapSort(data,num);
      print(data,num);
}
