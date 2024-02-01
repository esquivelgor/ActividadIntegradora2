// =========================================================
// File: main.cpp
// Authors:
//  Guillermo Esquivel Ortiz - A01625621
//   - A0
// Date: 02/02/2024
// =========================================================

#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

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
	
	// --------------- General Structures ---------------
    int n;
    int start, end;
    vector<vector<int>> wt;

	// --------------- General Methods ---------------
	void cout_Graph();

	// --------------- Structures for problem 1 -  ---------------

	// --------------- Methods for problem 1 -  ---------------

	// --------------- Structures for problem 2 - TSP Algorithm B&B ---------------
	int minCost = INT_MAX;
	vector<int> minCostPath;
	vector<int> curr_path;
    vector<bool> visited;

	// --------------- Methods for problem 2 - TSP Algorithm B&B ---------------
	void TSP();
	void TSPRec(int curr_bound, int curr_weight, int node);
	int firstMin(int i);
	int secondMin(int i);
    
	// --------------- Structures for problem 3 - Dinic's Algorithm ---------------

	// --------------- Methods for problem 3 -  ---------------
};

// --------------- Print function ---------------
void Graph::cout_Graph() {
    cout << "Matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << wt[i][j] << " ";
        }
        cout << endl;
    }
}

// Find the minimum edge cost having an end at the vertex i
int Graph::firstMin(int i) {
	int min = INT_MAX;
	for (int k=0; k<n; k++)
		if (wt[i][k]<min && i != k)
			min = wt[i][k];
	return min;
}

// Find the second minimum edge cost having an end at the vertex i
int Graph::secondMin(int i) {
	int first = INT_MAX, second = INT_MAX;
	for (int j=0; j<n; j++) {
		if (i == j)
			continue;
		if (wt[i][j] <= first) {
			second = first;
			first = wt[i][j];
		} else if (wt[i][j] <= second && wt[i][j] != first)
			second = wt[i][j];
	}
	return second;
}

void Graph::TSPRec(int curr_bound, int curr_weight, int node) {
	
	// We are in the last node
	if (node==n) {
		// check if there is an edge from last vertex in path back to the first vertex
		if (wt[curr_path[node-1]][curr_path[0]] != 0) {
			// curr_res has the total weight of the solution we got
			int curr_res = curr_weight + wt[curr_path[node-1]][curr_path[0]];
			if (curr_res < minCost) {
                for (int i=0; i<n; i++) {
	            	minCostPath[i] = curr_path[i];
	            }
                minCostPath[n] = curr_path[0];
				minCost = curr_res;
			}
		}
		return;
	}
	// else iterate for all vertices
	for (int i=0; i<n; i++) {
		// Consider next vertex if it is not same (diagonal entry in adjacency matrix and not visited already)
		if ((wt[curr_path[node-1]][i] != 0 && wt[curr_path[node-1]][i] != -1) && !visited[i]) {
			int temp = curr_bound;
			curr_weight += wt[curr_path[node-1]][i];
			// different computation of curr_bound for node 2 from the other nodes
			if (node==1) {
			    curr_bound -= ((firstMin(curr_path[node-1]) + firstMin(i))/2);
			} else {
			    curr_bound -= ((secondMin(curr_path[node-1]) + firstMin(i))/2);
            }
			
            // If the sum of the weights are lower than the minCost, then check that tree
			if (curr_bound + curr_weight < minCost) {
				curr_path[node] = i;
				visited[i] = true;
				TSPRec(curr_bound, curr_weight, node+1);
			}
			// Else we have to prune the node by resetting all changes to curr_weight and curr_bound
			curr_weight -= wt[curr_path[node-1]][i];
			curr_bound = temp;
			// And reset the visited array
            visited.assign(n, false);
			for (int j=0; j<=node-1; j++){ 
				visited[curr_path[j]] = true;
            }
		}
	}
}
	
void Graph::TSP() {

    	int curr_bound = start;
        curr_path.assign(n + 1, -1);
        visited.assign(n, 0);

    	// Compute initial bound
    	for (int i=0; i<n; i++) {
    		curr_bound += (firstMin(i) + secondMin(i));
        }

    	// Rounding off to an integer
    	curr_bound = (curr_bound&1)? curr_bound/2 + 1 : curr_bound/2;

    	// We start at vertex 1 so the first vertex in curr_path[] is 0
    	visited[0] = true;
    	curr_path[0] = 0;

    	// Call to TSPRec for curr_weight equal to 0 and node 1
    	TSPRec(curr_bound, 0, 1);
}

int main() {
	
    int n, start, end;
    cin >> n >> start >> end;
	
    Graph Undirected_Graph(n, start, end);
	Graph Directed_Graph(n, start, end);


    cout << "-------------------------------------" << endl;
    cout << "Problem 1" << endl;

    cout << "-------------------------------------" << endl;
    cout << "Problem 2" << endl;

    Undirected_Graph.TSP();
    cout << "Minimum cost: " << Undirected_Graph.minCost << endl;
	cout << "Path: ";
    for(int i : Undirected_Graph.minCostPath) cout << i << " ";
    cout << endl;

    cout << "-------------------------------------" << endl;
    cout << "Problem 3" << endl;

	return 0;
}
