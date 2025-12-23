#ifndef BST_H
#define BST_H

#include <string>

struct Node {
    std::string namaMember;
    float beratBadan;
    std::string tierMember;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    void inOrder(Node* cur) const;
    void printNodeDetail(const std::string& header, Node* n) const;

public:
    BST();

    bool isEmpty() const;
    void createTree();

    Node* newNode(const std::string& nama, float berat, const std::string& tier);
    void insertNode(const std::string& nama, float berat, const std::string& tier);

    void searchByBeratBadan(float beratCari) const;

    Node* mostLeft() const;
    Node* mostRight() const;

    void inOrder() const;
};

#endif
