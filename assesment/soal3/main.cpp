#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    Mahasiswa M;

    M = {"Venti", "11111", 75.7, 82.1, 65.5};
    push(S, M);

    M = {"Xiao", "22222", 87.4, 88.9, 81.9};
    push(S, M);

    M = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    push(S, M);

    M = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    push(S, M);

    M = {"Lynette", "55555", 77.7, 65.4, 79.9};
    push(S, M);

    M = {"Chasca", "66666", 99.9, 93.6, 87.3};
    push(S, M);

    
    cout << "\n=== Stack Setelah Input ===\n";
    view(S);

    
    pop(S);

    
    cout << "\n=== Stack Setelah 1x Pop ===\n";
    view(S);

    
    Mahasiswa newData = {"Heizou", "77777", 99.9, 88.8, 77.7};
    update(S, 3, newData);

    cout << "\n=== Stack Setelah Update Posisi 3 ===\n";
    view(S);

    
    cout << "\n=== Searching NilaiAkhir 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    return 0;
}
