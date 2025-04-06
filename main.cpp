#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g("data/graf.txt");
    int opt;

    do {
        cout << "\n===== MENIU ALG. GRAFURI =====\n";
        cout << "1. Afiseaza lista de adiacenta\n";
        cout << "2. Verifica daca graful este tare conex\n";
        cout << "3. Ruleaza algoritmul Dijkstra (de la nodul 0)\n";
        cout << "4. Ruleaza algoritmul MST (Prim)\n";
        cout << "5. Verifica si afiseaza ciclu Eulerian\n";
        cout << "0. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> opt;

        switch (opt) {
            case 1:
                g.print();
                break;
            case 2:
                cout << (g.isSC() ? "Graful este tare conex.\n" : "Graful NU este tare conex.\n");
                break;
            case 3:
                g.dijkstra(0);
                break;
            case 4:
                g.MST();
                break;
            case 5:
                if (g.isEulerianCycle()) {
                    cout << "Graful are ciclu Eulerian.\n";
                    g.HierHolzer();
                } else {
                    cout << "Graful NU are ciclu Eulerian.\n";
                }
                break;
            case 0:
                cout << "Iesire din program.\n";
                break;
            default:
                cout << "Optiune invalida!\n";
        }

    } while (opt != 0);

    return 0;
}
