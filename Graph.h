// =========================================================
// File: Graph.h
// Authors:
//  Guillermo Esquivel Ortiz - A01625621
//  Jesus Castillo Cabello   - A01382000
// Date: 02/02/2024
// =========================================================

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Graph {

    Graph(int edges, int init, int end) : n(edges), start(init), end(end) {
        
        wt.resize(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> wt[i][j];
            }
        }
    }

    // --------------------------------- Structures/Variables ---------------------------------
    int n;
    int start, end;
    vector<vector<int>> wt;

    // --------------- Problem 2 - TSP Algorithm B&B ---------------
	int minCost = INT_MAX;
    vector<int> minCostPath;

    // --------------- Problem 3 - Edmonds-Karp Algorithm ---------------
    int maxFlow = 0;

	// --------------------------------- Methods ---------------------------------

	// --------------- Problem 1 - Prim Algorithm ---------------
    void Prim();

	// --------------- Problem 2 - TSP Algorithm B&B ---------------
	void TSP();
	void TSPRec(int curr_bound, int curr_weight, int node, vector<int>& curr_path, vector<bool>& visited);
	int firstMin(int i);
	int secondMin(int i);

	// --------------- Problem 3 - Edmonds-Karp Algorithm ---------------
    void edmondsKarp();
    int BFS(vector<int>& visited);
    
};

#endif // _GRAPH_H_