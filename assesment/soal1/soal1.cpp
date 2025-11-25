#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

void tambahNama(string arr[], int &n) {
    string nama;
    cout << "Masukkan nama: ";
    cin >> arr[n];
    n++;
}

void hapusNama(string arr[], int &n) {
    string nama;
    cout << "Masukkan nama yang akan dihapus: ";
    cin >> nama;
        for (int i = 0; i < n; i++) {
            if (arr[i] == nama) {
        for (int j = i; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--;
        i--;
      }
    }
}

void tampilkanNama(string arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
}

void namaGenap(string arr[], int n) {
    int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].length() % 2 == 0)
        count++;
        }
        cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    string arr[MAX];
    int n = 0; 

    int menu;
        do {
            cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
            cin >> menu;

    if (menu == 1) {
        tambahNama(arr, n);
    } else if (menu == 2) {
        hapusNama(arr, n);
    } else if (menu == 3) {
        tampilkanNama(arr, n);
    } else if (menu == 4) {
        namaGenap(arr, n);
    }

} while (menu != 0); 

return 0;
}