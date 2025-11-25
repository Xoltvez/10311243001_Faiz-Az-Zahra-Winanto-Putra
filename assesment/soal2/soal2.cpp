#include <iostream>
using namespace std;

const int MAX = 100; 
int arr[MAX];
int n = 0; 

void insertEnd(int value) {
    if (n < MAX) {
        arr[n] = value;
        n++;
    } else {
        cout << "Array penuh!" << endl;
    }
}

void deleteLast() {
    if (n > 0) {
        n--;
    } else {
        cout << "Array kosong!" << endl;
    }
}

void view() {
    if (n == 0) {
        cout << "List kosong!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseAndView() {
    if (n == 0) {
        cout << "List kosong!" << endl;
        return;
    }
    cout << "List setelah di-reverse: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int menu, value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), ";
        cout << "4 reverse & view (depan), 0 exit" << endl;
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertEnd(value);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                view();
                break;

            case 4:
                reverseAndView();
                break;

            case 0:
                cout << "Keluar program..." << endl;
                break;

            default:
                cout << "Menu tidak valid!" << endl;
        }

    } while (menu != 0);

    return 0;
}
