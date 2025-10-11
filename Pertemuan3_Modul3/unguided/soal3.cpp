#include <iostream>
using namespace std;


void tampilkanArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void tukarPosisiArray2D(int arr1[3][3], int arr2[3][3], int x1, int y1, int x2, int y2) {
    int temp = arr1[x1][y1];
    arr1[x1][y1] = arr2[x2][y2];
    arr2[x2][y2] = temp;
}


void tukarNilaiPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    
    cout << "Array 1 sebelum ditukar:" << endl;
    tampilkanArray2D(array1);
    cout << "Array 2 sebelum ditukar:" << endl;
    tampilkanArray2D(array2);
    
    
    tukarPosisiArray2D(array1, array2, 0, 0, 2, 2);
    
   
    cout << "\nArray 1 setelah ditukar:" << endl;
    tampilkanArray2D(array1);
    cout << "Array 2 setelah ditukar:" << endl;
    tampilkanArray2D(array2);

   
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

   
    cout << "\nNilai sebelum ditukar: a = " << a << ", b = " << b << endl;
    
    
    tukarNilaiPointer(ptr1, ptr2);

 
    cout << "Nilai setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
