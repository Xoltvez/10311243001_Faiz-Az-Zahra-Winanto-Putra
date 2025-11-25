#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = M;
}

void pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    S.Top--;
}

void update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    int index = posisi - 1;
    if (index < 0 || index > S.Top) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    S.dataMahasiswa[index] = M;
}

void view(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Isi Stack:\n";
    for (int i = S.Top; i >= 0; i--) {
        Mahasiswa m = S.dataMahasiswa[i];
        cout << m.Nama << " | NIM: " << m.NIM
             << " | Tugas: " << m.NilaiTugas
             << " | UTS: " << m.NilaiUTS
             << " | UAS: " << m.NilaiUAS << endl;
    }
}

float HitungNilaiAkhir(Mahasiswa M) {
    return (0.2 * M.NilaiTugas) + (0.4 * M.NilaiUTS) + (0.4 * M.NilaiUAS);
}

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max) {
    cout << "Hasil Searching NilaiAkhir dalam rentang " << min << " - " << max << ":\n";

    for (int i = 0; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA >= min && NA <= max) {
            cout << "Posisi " << (i + 1) << ": " << S.dataMahasiswa[i].Nama
                 << " | Nilai Akhir = " << NA << endl;
        }
    }
}


//tambahan bagian bpada stackmahasiswa.cpp ProsedurMaxNilaiAkhir()
void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    float maxNA = -999;
    int posMax = -1;

    for (int i = 0; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA > maxNA) {
            maxNA = NA;
            posMax = i;
        }
    }

    cout << "Data dengan NilaiAkhir terbesar:\n";
    Mahasiswa m = S.dataMahasiswa[posMax];

    cout << "Posisi: " << posMax + 1 << endl;
    cout << m.Nama << " | NIM: " << m.NIM
         << " | Nilai Akhir: " << maxNA << endl;
}
