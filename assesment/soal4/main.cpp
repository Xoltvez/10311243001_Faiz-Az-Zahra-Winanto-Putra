#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do {
        cout << "\n--- Komaniya Ekspres ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Selesai\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 4);

    return 0;
}
