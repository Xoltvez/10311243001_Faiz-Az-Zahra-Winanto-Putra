#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int max = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan: " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++) {
        cout << "Masukan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}