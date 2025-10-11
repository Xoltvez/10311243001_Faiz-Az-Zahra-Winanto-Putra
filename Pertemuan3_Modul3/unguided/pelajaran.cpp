#include "pelajaran.h"
#include <iostream>
using namespace std;

// Function to create pelajaran
pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namapel = namapel;
    pel.kodepel = kodepel;
    return pel;
}


void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodepel << endl;
}
