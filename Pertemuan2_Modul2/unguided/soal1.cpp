#include <iostream>
using namespace std;

void jumlahMatriks(const int A[3][3], const int B[3][3], int C[3][3]) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void kurangMatriks(const int A[3][3], const int B[3][3], int C[3][3]) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void kaliMatriks(const int A[3][3], const int B[3][3], int C[3][3]) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            int sum = 0;
            for (int k=0;k<3;k++) sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }
}

void printMatrix(const char* title, const int M[3][3]) {
    cout << title << '\n';
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << M[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    
    int A[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int B[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    while (true) {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks (A - B)\n";
        cout << "3. Perkalian matriks (A x B)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu [1-4]: ";

        int pilih; 
        cin >> pilih;

        int C[3][3]; 

        switch (pilih) {
            case 1:
                printMatrix("Matriks A:", A);
                printMatrix("Matriks B:", B);
                jumlahMatriks(A, B, C);
                printMatrix("Hasil A + B:", C);
                break;
            case 2:
                printMatrix("Matriks A:", A);
                printMatrix("Matriks B:", B);
                kurangMatriks(A, B, C);
                printMatrix("Hasil A - B:", C);
                break;
            case 3:
                printMatrix("Matriks A:", A);
                printMatrix("Matriks B:", B);
                kaliMatriks(A, B, C);
                printMatrix("Hasil A x B:", C);
                break;
            case 4:
                cout << "Terima kasih!\n";
                return 0;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
}
