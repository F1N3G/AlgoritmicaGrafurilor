#include "Graph.h"

int main() {
    Graph g("data/Graph.txt");

    if (g.isEulerianCycle()) {
        cout << "Graful are ciclu Eulerian:\n";
        g.HierHolzer();
    } else {
        cout << "Graful NU are ciclu Eulerian.\n";
    }

    return 0;
}
