#include "graph.h"

using namespace std;

Edge::Edge(Node* dest) : to(dest), next(nullptr) {}

Node::Node(char c)
    : name(c),
      firstEdge(nullptr),
      nextNode(nullptr),
      lockdown(false),
      visitMark(0) {}

Graph::Graph() : head(nullptr), traversalToken(0) {}

Node* Graph::findOrCreateNode(char name) {
    Node* cur = head;
    while (cur) {
        if (cur->name == name) return cur;
        cur = cur->nextNode;
    }
    Node* n = new Node(name);
    n->nextNode = head;
    head = n;
    return n;
}

void Graph::addDirectedEdge(Node* u, Node* v) {
    Edge* e = new Edge(v);
    e->next = u->firstEdge;
    u->firstEdge = e;
}

void Graph::addUndirectedEdge(char a, char b) {
    Node* u = findOrCreateNode(a);
    Node* v = findOrCreateNode(b);
    addDirectedEdge(u, v);
    addDirectedEdge(v, u);
}

void Graph::printNetwork() const {
    cout << "Membangun Jaringan Distribusi Vaksin\n\n";
    Node* cur = head;
    while (cur) {
        cout << "Node " << cur->name << " terhubung ke: ";
        Edge* e = cur->firstEdge;
        while (e) {
            cout << e->to->name;
            if (e->next) cout << " ";
            e = e->next;
        }
        cout << "\n";
        cur = cur->nextNode;
    }
}

int Graph::countActiveNodes() const {
    int cnt = 0;
    Node* cur = head;
    while (cur) {
        if (!cur->lockdown) cnt++;
        cur = cur->nextNode;
    }
    return cnt;
}

Node* Graph::getAnyActiveNode() const {
    Node* cur = head;
    while (cur) {
        if (!cur->lockdown) return cur;
        cur = cur->nextNode;
    }
    return nullptr;
}

void Graph::dfs(Node* u, int& reached) {
    if (!u || u->lockdown) return;
    if (u->visitMark == traversalToken) return;

    u->visitMark = traversalToken;
    reached++;

    Edge* e = u->firstEdge;
    while (e) {
        Node* v = e->to;
        if (v && !v->lockdown && v->visitMark != traversalToken) {
            dfs(v, reached);
        }
        e = e->next;
    }
}

bool Graph::isCritical(Node* x) {
    if (!x) return false;

    
    x->lockdown = true;

    int totalActive = countActiveNodes();
    bool critical = false;

    if (totalActive <= 1) {
        critical = false;
    } else {
        Node* start = getAnyActiveNode();
        traversalToken++; 
        int reached = 0;
        dfs(start, reached);
        critical = (reached != totalActive);
    }

    x->lockdown = false;
    return critical;
}

void Graph::analyzeCriticalCities() {
    cout << "\n\nAnalisis Kota Kritis (Single Point of Failure)\n";

    Node* cur = head;
    while (cur) {
        bool crit = isCritical(cur);
        if (crit) {
            cout << "[PERINGATAN] Kota " << cur->name << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << cur->name << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << cur->name << " aman (redundansi oke).\n";
        }
        cur = cur->nextNode;
    }
}

Graph::~Graph() {
    Node* ncur = head;
    while (ncur) {
        Edge* ecur = ncur->firstEdge;
        while (ecur) {
            Edge* tmpE = ecur;
            ecur = ecur->next;
            delete tmpE;
        }
        ncur = ncur->nextNode;
    }
    ncur = head;
    while (ncur) {
        Node* tmpN = ncur;
        ncur = ncur->nextNode;
        delete tmpN;
    }
}
