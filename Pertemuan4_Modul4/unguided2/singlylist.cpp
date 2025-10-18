#include "Singlylist.h"


void createList(List &L) {
    L.first = nullptr;
}


address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}


void dealokasi(address &P) {
    delete P;
    P = nullptr;
}


void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.first;
        L.first = P;
    }
}


void printInfo(List L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}


void deleteFirst(List &L, address &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}


void deleteLast(List &L, address &P) {
    if (L.first != nullptr) {
        address Q = L.first;
        if (Q->next == nullptr) { 
            P = Q;
            L.first = nullptr;
        } else {
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = nullptr;
        }
    }
}


void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}


int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}


void deleteList(List &L) {
    address P;
    while (L.first != nullptr) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
