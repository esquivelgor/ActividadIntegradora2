#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Graph {

    Graph(int edges, int init, int end) : n(edges), start(init), end(end) {
        
        wt.resize(n, vector<int>(n));
		curr_path.resize(n+1, int(n));
        minCostPath.resize(n + 1, int(n));
        visited.resize(n, bool(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> wt[i][j];
            }
        }
    }

    // --------------------------------- Structures ---------------------------------
    int n;
    int start, end;
    vector<vector<int>> wt;
    
    // --------------- Problem 1 -  ---------------

    // --------------- Problem 2 - TSP Algorithm B&B ---------------
	int minCost = INT_MAX;
	vector<int> minCostPath;
	vector<int> curr_path;
    vector<bool> visited;

    // --------------- Problem 3 - Edmonds-Karp Algorithm ---------------
    int maxFlow = 0;

	// --------------------------------- Methods ---------------------------------
	void cout_Graph();

	// --------------- Problem 1 -  ---------------

	// --------------- Problem 2 - TSP Algorithm B&B ---------------
	void TSP();
	void TSPRec(int curr_bound, int curr_weight, int node);
	int firstMin(int i);
	int secondMin(int i);

	// --------------- Problem 3 - Edmonds-Karp Algorithm ---------------
    void edmondsKarp();
    int BFS(vector<int>& parent);
    
};

// --------------- Print function ---------------
inline void Graph::cout_Graph() {
    cout << "Matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << wt[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // _GRAPH_H_