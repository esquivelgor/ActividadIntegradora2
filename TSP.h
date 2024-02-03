// =========================================================
// File: TSP.h
// Authors:
//  Guillermo Esquivel Ortiz - A01625621
//  Jesus Castillo Cabello   - A01382000
// Date: 02/02/2024
// =========================================================

#ifndef _TSP_H_
#define _TSP_H_

#include "Graph.h"

// --------------- Methods for problem 2 - TSP Algorithm B&B ---------------

// Find the minimum edge cost having an end at the vertex i
inline int Graph::firstMin(int i) {
	int min = INT_MAX;
	for (int k=0; k<n; k++)
		if (wt[i][k]<min && i != k)
			min = wt[i][k];
	return min;
}

// Find the second minimum edge cost having an end at the vertex i
inline int Graph::secondMin(int i) {
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

inline void Graph::TSPRec(int curr_bound, int curr_weight, int node, vector<int>& curr_path, vector<bool>& visited) {
	
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
				TSPRec(curr_bound, curr_weight, node+1, curr_path, visited);
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
	
inline void Graph::TSP() {

	vector<int> curr_path(n+1);
    vector<bool> visited(n);
	int curr_bound = start;

	minCostPath.resize(n+1, int(n));
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
    TSPRec(curr_bound, 0, 1, curr_path, visited);

	cout << "Minimum cost: " << minCost << endl;
	cout << "Path: ";
    for(int i : minCostPath) cout << i << " ";
	cout << endl;
}

#endif // _TSP_H_