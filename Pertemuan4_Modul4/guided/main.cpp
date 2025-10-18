#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Faiz ", "10311243001", 20);
    nodeB = alokasi("Juan", "14134331212", 19);
    nodeC = alokasi("Yossika", "24134141122", 20);
    nodeD = alokasi("Yunan", "123414131313", 19);
    nodeE = alokasi("Nanda", "12413134131", 20);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}