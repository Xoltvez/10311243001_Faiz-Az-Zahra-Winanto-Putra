#include <iostream>
using namespace std;

int main() {
    
    int panjang = 10, lebar = 5, luas;

    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;


    luas = (*ptrPanjang) * (*ptrLebar);
    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << *ptrPanjang << endl;
    cout << "Lebar: " << *ptrLebar << endl;
    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << 2 * (*ptrPanjang + *ptrLebar) << endl;

    
    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << (*ptrPanjang) * (*ptrLebar) << endl;
    cout << "Keliling Baru: " << 2 * (*ptrPanjang + *ptrLebar) << endl;

    return 0;
}
