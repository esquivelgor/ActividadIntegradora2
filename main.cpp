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

    int n;
    int start, end;
    int minCost = INT_MAX;
    vector<vector<int>> wt;
    vector<int> final_path_minCost;
    vector<bool> visited;

    Graph(int edges, int init, int end) : n(edges), start(init), end(end) {
        
        wt.resize(n, vector<int>(n));
        final_path_minCost.resize(n + 1, int(n));
        visited.resize(n, bool(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> wt[i][j];
            }
        }
    }

    // --------------- Print function ---------------
    void cout_Graph() const {
        cout << "Matriz:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << wt[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // --------------- Problem 2 - TSP ---------------
 
    // Find the minimum edge cost having an end at the vertex i
    int firstMin(vector<vector<int>> adj, int i) {
    	int min = INT_MAX;
    	for (int k=0; k<n; k++)
    		if (adj[i][k]<min && i != k)
    			min = adj[i][k];
    	return min;
    }

    // Find the second minimum edge cost having an end at the vertex i
    int secondMin(vector<vector<int>> adj, int i) {
    	int first = INT_MAX, second = INT_MAX;
    	for (int j=0; j<n; j++) {
    		if (i == j)
    			continue;

    		if (adj[i][j] <= first) {
    			second = first;
    			first = adj[i][j];
    		} else if (adj[i][j] <= second && adj[i][j] != first)
    			second = adj[i][j];
    	}
    	return second;
    }

    void TSPRec(vector<vector<int>> adj, int curr_bound, int curr_weight, int level, vector<int> curr_path) {
    	// if we reached level N it means we have covered all the nodes once
    	if (level==n) {
    		// check if there is an edge from last vertex in path back to the first vertex
    		if (adj[curr_path[level-1]][curr_path[0]] != 0) {
    			// curr_res has the total weight of the solution we got
    			int curr_res = curr_weight + adj[curr_path[level-1]][curr_path[0]];

    			if (curr_res < minCost) {
                    for (int i=0; i<n; i++) {
    	            	final_path_minCost[i] = curr_path[i];
    	            }
                    final_path_minCost[n] = curr_path[0];
    				minCost = curr_res;
    			}
    		}
    		return;
    	}

    	// else iterate for all vertices
    	for (int i=0; i<n; i++) {
    		// Consider next vertex if it is not same (diagonal entry in adjacency matrix and not visited already)
    		if (adj[curr_path[level-1]][i] != 0 && visited[i] == false) {
    			int temp = curr_bound;
    			curr_weight += adj[curr_path[level-1]][i];

    			// different computation of curr_bound for level 2 from the other levels
    			if (level==1) {
    			    curr_bound -= ((firstMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
    			} else {
    			    curr_bound -= ((secondMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
                }
    			
                // If the sum of the weights are lower than the minCost, then check that tree
    			if (curr_bound + curr_weight < minCost) {
    				curr_path[level] = i;
    				visited[i] = true;

    				TSPRec(adj, curr_bound, curr_weight, level+1, curr_path);
    			}

    			// Else we have to prune the node by resetting all changes to curr_weight and curr_bound
    			curr_weight -= adj[curr_path[level-1]][i];
    			curr_bound = temp;

    			// And reset the visited array
                visited.assign(n, false);
    			for (int j=0; j<=level-1; j++){ 
    				visited[curr_path[j]] = true;
                }
    		}
    	}
    }
    
    void TSP() {

        vector<int> curr_path;
        curr_path.resize(n+1, int(n));

    	// Calculate initial lower bound for the root node and initialize the curr_path and visited array
    	int curr_bound = start;
        curr_path.assign(n, -1);
        visited.assign(n, 0);

    	// Compute initial bound
    	for (int i=0; i<n; i++) {
    		curr_bound += (firstMin(wt, i) + secondMin(wt, i));
        }

    	// Rounding off the lower bound to an integer
    	curr_bound = (curr_bound&1)? curr_bound/2 + 1 : curr_bound/2;

    	// We start at vertex 1 so the first vertex in curr_path[] is 0
    	visited[0] = true;
    	curr_path[0] = 0;

    	// Call to TSPRec for curr_weight equal to 0 and level 1
    	TSPRec(wt, curr_bound, 0, 1, curr_path);
    }
};

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
    for(int i : Undirected_Graph.final_path_minCost) cout << i << " ";
    cout << endl;

    cout << "-------------------------------------" << endl;
    cout << "Problem 3" << endl;

	return 0;
}
