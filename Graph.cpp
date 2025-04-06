#include "Graph.h"

Graph::Graph(const char* file) {
    ifstream fin(file);
    fin >> V;
    adj = new list<pair<int, int>>[V];
    adjSimple = new list<int>[V];
    inDeg = new int[V]();

    while (!fin.eof()) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
        adjSimple[u].push_back(v);
        inDeg[v]++;
    }
    fin.close();
}

Graph::~Graph() {
    delete[] adj;
    delete[] adjSimple;
    delete[] inDeg;
}

void Graph::print() {
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto& edge : adj[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

// ======= Conexitate =======
bool Graph::isSC() {
    bool* visited = new bool[V]();
    DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
        if (!visited[i]) return false;

    Graph gt = getTranspose();
    fill(visited, visited + V, false);
    gt.DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
        if (!visited[i]) return false;

    delete[] visited;
    return true;
}

void Graph::DFSUtil(int src, bool* visited) {
    visited[src] = true;
    for (int v : adjSimple[src])
        if (!visited[v]) DFSUtil(v, visited);
}

Graph Graph::getTranspose() {
    Graph gt(*this);
    delete[] gt.adj;
    delete[] gt.adjSimple;
    gt.adjSimple = new list<int>[V];
    for (int i = 0; i < V; i++)
        for (int j : adjSimple[i])
            gt.adjSimple[j].push_back(i);
    return gt;
}

// ======= Dijkstra =======
void Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX), parent(V);
    for (int i = 0; i < V; ++i) parent[i] = i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Distanta pana la " << i << ": " << dist[i] << " | Drum: ";
        vector<int> path;
        for (int v = i; v != parent[v]; v = parent[v]) path.push_back(v);
        path.push_back(src);
        for (int j = path.size() - 1; j >= 0; j--) cout << path[j] << (j ? " -> " : "\n");
    }
}

// ======= MST (Prim) =======
void Graph::MST() {
    vector<int> dist(V, INT_MAX), parent(V);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& [v, w] : adj[u]) {
            if (!inMST[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    printMST(parent);
}

void Graph::printMST(vector<int>& parent) {
    for (int i = 1; i < V; i++)
        cout << "(" << parent[i] << " - " << i << ")\n";
}

// ======= Eulerian Cycle =======
bool Graph::isEulerianCycle() {
    if (!isSC()) return false;
    for (int i = 0; i < V; i++)
        if (adjSimple[i].size() != inDeg[i]) return false;
    return true;
}

void Graph::HierHolzer() {
    vector<int> edge_count(V);
    for (int i = 0; i < V; i++)
        edge_count[i] = adjSimple[i].size();

    stack<int> curr_path;
    vector<int> circuit;
    curr_path.push(0);
    int curr_v = 0;

    while (!curr_path.empty()) {
        if (edge_count[curr_v]) {
            curr_path.push(curr_v);
            int next_v = adjSimple[curr_v].back();
            edge_count[curr_v]--;
            adjSimple[curr_v].pop_back();
            curr_v = next_v;
        } else {
            circuit.push_back(curr_v);
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    cout << "Ciclu Eulerian: ";
    for (auto it = circuit.rbegin(); it != circuit.rend(); ++it)
        cout << *it << (it + 1 != circuit.rend() ? " -> " : "\n");
}