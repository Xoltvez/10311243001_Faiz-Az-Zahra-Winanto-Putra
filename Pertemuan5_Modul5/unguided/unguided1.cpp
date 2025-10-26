#include <iostream>
#include <iomanip>
using namespace std;

// Definisi node
struct Node {
    int data;       
    Node* next;     
};


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};  // Membuat node baru
    
    if (!head) {
        // Jika linked list kosong, node baru menjadi head
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        // Hubungkan node terakhir dengan node baru
        temp->next = newNode;
    }
}


void visualizeList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* current = head;
    
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}


Node* binarySearch(Node* head, int key) {
    
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    
    if (size == 0) {
        cout << "Linked list kosong!" << endl;
        return nullptr;
    }
    
    cout << "\nProses Pencarian:" << endl;
    
    
    int left = 0;          
    int right = size - 1;   
    int iterasi = 1;        
    
    // Binary Search Algorithm
    while (left <= right) {
        
        int mid = left + (right - left) / 2;
        
       
        Node* midNode = head;
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        
        cout << "Iterasi " << iterasi << ": Mid = " << mid 
             << " (indeks tengah)";
        
        
        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key 
                 << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            
            // Tampilkan node berikutnya
            if (midNode->next != nullptr) {
                cout << "Node berikutnya: " << midNode->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL (ini adalah node terakhir)" << endl;
            }
            
            return midNode;
        }
        // Jika key lebih kecil dari midNode, cari di bagian kiri
        else if (key < midNode->data) {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
        // Jika key lebih besar dari midNode, cari di bagian kanan
        else {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        }
        
        iterasi++;
    }
    
   
    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key 
         << " TIDAK DITEMUKAN dalam linked list!" << endl;
    
    return nullptr;
}


void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;  
    
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    
    
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
  
    visualizeList(head);
    
    //  Mencari nilai yang ada (40)
    cout << "Mencari nilai: 40" << endl;
    Node* result1 = binarySearch(head, 40);
    
    cout << "\n" << string(60, '=') << endl;
    
    // Mencari nilai yang tidak ada (25)
    cout << "\nMencari nilai: 25" << endl;
    Node* result2 = binarySearch(head, 25);
    
    
    deleteList(head);
    
    return 0;
}