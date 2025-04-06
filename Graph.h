#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <fstream>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    list<pair<int, int>>* adj; // lista de adiacenta cu ponderi
    list<int>* adjSimple;      // lista de adiacenta fara ponderi (pentru Eulerian, SC)
    int* inDeg;

public:
    Graph(const char* file);
    ~Graph();

    void print();

    // Conexitate
    bool isSC();
    void DFSUtil(int src, bool* visited);
    Graph getTranspose();

    // Drumuri minime
    void dijkstra(int src);

    // Arbore de acoperire minim
    void MST();
    void printMST(vector<int>& parent);

    // Ciclu Eulerian
    bool isEulerianCycle();
    void HierHolzer();
};
