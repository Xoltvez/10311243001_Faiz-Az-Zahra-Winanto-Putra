#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
    string puluhanKata[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    
    if (angka == 0) {
        cout << "Nol" << endl;
    }
    else if (angka >= 1 && angka <= 9) {
        cout << satuan[angka] << endl;
    }
    else if (angka >= 10 && angka <= 19) {
        cout << puluhanKata[angka - 10] << endl;
    }
    else if (angka >= 20 && angka <= 99) {
        int puluh = angka / 10;
        int satu = angka % 10;
        if (satu == 0) {
            cout << puluhan[puluh] << endl;
        }
        else {
            cout << puluhan[puluh] << " " << satuan[satu] << endl;
        }
    }
    else if (angka == 100) {
        cout << "Seratus" << endl;
    }
    else {
        cout << "Angka yang dimasukkan tidak valid, harus antara 0 hingga 100." << endl;
    }

    return 0;
}
