#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

struct Node; 

struct Edge {
    Node* to;
    Edge* next;
    explicit Edge(Node* dest);
};

struct Node {
    char name;
    Edge* firstEdge;
    Node* nextNode;

    bool lockdown;
    int visitMark;

    explicit Node(char c);
};

class Graph {
private:
    Node* head;
    int traversalToken;

    Node* findOrCreateNode(char name);
    void addDirectedEdge(Node* u, Node* v);

    int countActiveNodes() const;
    Node* getAnyActiveNode() const;
    void dfs(Node* u, int& reached);

    bool isCritical(Node* x);

public:
    Graph();
    ~Graph();

    void addUndirectedEdge(char a, char b);
    void printNetwork() const;
    void analyzeCriticalCities();
};

#endif
