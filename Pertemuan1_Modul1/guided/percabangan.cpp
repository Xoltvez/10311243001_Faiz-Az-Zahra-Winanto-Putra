#include<iostream>
using namespace std;

int main() {

    int angka1, angka2;
    cout << "masukan angka1" << endl;
    cin >> angka1;
    cout << "masukan angka2:" << endl;
    cin >> angka2;

    if (angka1 < angka2)
    {
        cout << "angka1 lebih kecil dari angka2" << endl;
    } else
    {
        cout << "angka1 lebih besar dari angka2" << endl;
    }
    
    if (angka1 == angka2)
    {
        cout << "angka1 sama dengan angka2" << endl;
    } else if (angka1 != angka2){
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout <<"1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Masukan Pilihan" << endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan:" << angka1 + angka2 << endl;
        break;
        case 2 :
        cout << "pengurangan:" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan tidak ada" << endl;
    }

    return 0;
}