#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack Temp;
    createStack(Temp);

    while (S.top >= 0) {
        push(Temp, pop(S));
    }

    while (Temp.top >= 0) {
        push(S, pop(Temp));
    }
}

// ===============================
// pushAscending
// ===============================
void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    createStack(Temp);

    // pindahkan elemen ke temp selama nilai > x
    while (S.top >= 0 && S.info[S.top] > x) {
        push(Temp, pop(S));
    }

    // taruh x di posisi seharusnya
    push(S, x);

    // kembalikan elemen yang tadi dipindahkan
    while (Temp.top >= 0) {
        push(S, pop(Temp));
    }
}
