#include "bst.h"
#include <iostream>

using namespace std;

BST::BST() : root(nullptr) {}

bool BST::isEmpty() const {
    return root == nullptr;
}

void BST::createTree() {
    root = nullptr;
}

Node* BST::newNode(const string& nama, float berat, const string& tier) {
    Node* n = new Node;
    n->namaMember = nama;
    n->beratBadan = berat;
    n->tierMember = tier;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void BST::insertNode(const string& nama, float berat, const string& tier) {
    Node* n = newNode(nama, berat, tier);

    if (root == nullptr) {
        root = n;
        return;
    }

    Node* cur = root;
    Node* parent = nullptr;

    while (cur != nullptr) {
        parent = cur;

        if (berat < cur->beratBadan) {
            cur = cur->left;
        } else if (berat > cur->beratBadan) {
            cur = cur->right;
        } else {
            delete n;
            return;
        }
    }

    if (berat < parent->beratBadan) parent->left = n;
    else parent->right = n;
}

void BST::inOrder(Node* cur) const {
    if (!cur) return;
    inOrder(cur->left);
    cout << (int)cur->beratBadan << " - ";
    inOrder(cur->right);
}

void BST::inOrder() const {
    cout << "=== Traversal InOrder ===\n";
    inOrder(root);
    cout << "\n";
}

Node* BST::mostLeft() const {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->left != nullptr) cur = cur->left;
    return cur;
}

Node* BST::mostRight() const {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->right != nullptr) cur = cur->right;
    return cur;
}

void BST::printNodeDetail(const string& header, Node* n) const {
    cout << header << "\n";
    cout << "Nama Member : " << n->namaMember << "\n";
    cout << "Berat Badan : " << (int)n->beratBadan << "\n";
    cout << "Tier Member : " << n->tierMember << "\n";
}

void BST::searchByBeratBadan(float beratCari) const {
    if (root == nullptr) {
        cout << "Data tidak ditemukan didalam BST!\n";
        return;
    }

    Node* cur = root;
    Node* parent = nullptr;

    while (cur != nullptr && cur->beratBadan != beratCari) {
        parent = cur;
        if (beratCari < cur->beratBadan) cur = cur->left;
        else cur = cur->right;
    }

    if (cur == nullptr) {
        cout << "Data tidak ditemukan didalam BST!\n";
        return;
    }

    cout << "Data ditemukan didalam BST!\n";
    cout << "------------------------------\n";
    printNodeDetail("--- Data Node Yang Dicari ---", cur);
    cout << "------------------------------\n";

    if (parent != nullptr) {
        printNodeDetail("--- Data Parent ---", parent);
    } else {
        cout << "--- Data Parent ---\n";
        cout << "Node ini adalah ROOT (tidak punya parent)\n";
    }
    cout << "------------------------------\n";

    if (parent == nullptr) {
        cout << "Tidak Memiliki Sibling\n";
    } else {
        Node* sibling = (parent->left == cur) ? parent->right : parent->left;
        if (sibling == nullptr) {
            cout << "Tidak Memiliki Sibling\n";
        } else {
            printNodeDetail("--- Data Sibling ---", sibling);
        }
    }
    cout << "------------------------------\n";

    
    if (cur->left != nullptr) {
        printNodeDetail("--- Data Child Kiri ---", cur->left);
    } else {
        cout << "--- Data Child Kiri ---\n";
        cout << "Tidak Memiliki Child Kiri\n";
    }
    cout << "------------------------------\n";


    if (cur->right != nullptr) {
        printNodeDetail("--- Data Child Kanan ---", cur->right);
    } else {
        cout << "--- Data Child Kanan ---\n";
        cout << "Tidak Memiliki Child Kanan\n";
    }
    cout << "------------------------------\n";
}
