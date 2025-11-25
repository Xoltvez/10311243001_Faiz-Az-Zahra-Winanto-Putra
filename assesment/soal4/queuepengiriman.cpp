#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    cout << "Masukkan Kode Resi  : ";
    cin >> Q.dataPaket[Q.tail].KodeResi;
    cout << "Masukkan Nama Pengirim : ";
    cin >> Q.dataPaket[Q.tail].NamaPengirim;
    cout << "Masukkan Berat Barang  : ";
    cin >> Q.dataPaket[Q.tail].BeratBarang;
    cout << "Masukkan Tujuan        : ";
    cin >> Q.dataPaket[Q.tail].Tujuan;

    cout << "Data berhasil dimasukkan ke queue.\n\n";
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong, tidak bisa deQueue!\n";
        return;
    }

    cout << "Menghapus paket dengan resi: " << Q.dataPaket[Q.head].KodeResi << endl;

    for (int i = Q.head; i < Q.tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.tail--;

    if (Q.tail < Q.head) {
        Q.head = -1;
        Q.tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n=== Isi Queue Pengiriman ===\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << "Paket ke-" << i + 1 << endl;
        cout << "Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
        cout << "Nama Pengirim : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat Barang  : " << Q.dataPaket[i].BeratBarang << endl;
        cout << "Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-------------------------------\n";
    }
}
