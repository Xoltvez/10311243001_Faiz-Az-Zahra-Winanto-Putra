#include <iostream>
#include "bstree.h"
using namespace std;

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert ke BST
void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Cari node
address findNode(infotype x, address root) {
    if (root == NULL)
        return NULL;
    else if (x == root->info)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

// Traversal InOrder
void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

// Menghitung jumlah node
int hitungJumlahNode(address root) {
    if (root == NULL)
        return 0;
    else
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Menghitung total seluruh nilai node
int hitungTotalInfo(address root) {
    if (root == NULL)
        return 0;
    else
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

// Menghitung kedalaman maksimum BST
int hitungKedalaman(address root, int start) {
    if (root == NULL)
        return start;
    
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}
