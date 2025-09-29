#include <iostream>
using namespace std;

int main() {
    
    float num1, num2;

   
    cout << "Masukkan bilangan pertama: ";
    cin >> num1;
    cout << "Masukkan bilangan kedua: ";
    cin >> num2;

    
    cout << "Hasil Penjumlahan: " << num1 + num2 << endl;
    cout << "Hasil Pengurangan: " << num1 - num2 << endl;
    cout << "Hasil Perkalian: " << num1 * num2 << endl;
    
    
    if (num2 != 0) {
        cout << "Hasil Pembagian: " << num1 / num2 << endl;
    } else {
        cout << "Pembagian dengan nol tidak diperbolehkan!" << endl;
    }

    return 0;
}
