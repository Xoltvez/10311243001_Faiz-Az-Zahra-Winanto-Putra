#include<iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; 

    for (int i=0; i<5; ++i) {
        cout << "Elemen array ke-" << i+1 << " Menggunakan pointer: " << *(ptr+i) << endl;
    }

    cout << endl;

    for (int i=0; i<5; ++i) {
        cout << "Elemen array ke-" << i+1 << " Menggunakan index ke-" << arr[i] << endl;
    }
    
    return 0;
}