#include "graph.h"

int main() {
    Graph g;

    g.addUndirectedEdge('A', 'B');
    g.addUndirectedEdge('B', 'E');
    g.addUndirectedEdge('B', 'C');
    g.addUndirectedEdge('C', 'D');

    g.printNetwork();
    g.analyzeCriticalCities();

    return 0;
}
