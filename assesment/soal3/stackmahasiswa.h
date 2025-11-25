#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void push(StackMahasiswa &S, Mahasiswa M);
void pop(StackMahasiswa &S);
void update(StackMahasiswa &S, int posisi, Mahasiswa M);
void view(StackMahasiswa &S);

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max); 

float HitungNilaiAkhir(Mahasiswa M);

#endif
