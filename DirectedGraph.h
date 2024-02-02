#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Edge {
    int v; // Direction
    int flow; // Flow of data
    int C; // Capacity
    int rev; // To store index of reverse
};

class DirectedGraph {
    int n; // Number of vertex
    int* level; // Stores the level of the node
    vector<Edge>* adj; // Graph


public:
    DirectedGraph(int n) {
        adj = new vector<Edge>[n];
        this->n = n;
        level = new int[n];
    }

    void addEdge(int v, int w, int C) {
        Edge a{w, 0, C, (int)adj[w].size()};
        Edge b{v, 0, 0, (int)adj[v].size()};

        adj[v].push_back(a);
        adj[w].push_back(b);
    }

    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxFlow(int s, int t);
};


#endif // _GRAPH_H_