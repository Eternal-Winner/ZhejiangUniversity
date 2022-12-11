/*
 * Created by 方浩铭 on 2022/9/25.
 *
 * */
  //Using to store the information of Linked List.


#include "FunctionDeclaration.h"

ListInfo INFO_LIST;

int main() {
    cin >> INFO_LIST.firstAddress >> INFO_LIST.count >> INFO_LIST.distant;


    LinkedList L;
    L = readList();
    PrintList(L);

}
