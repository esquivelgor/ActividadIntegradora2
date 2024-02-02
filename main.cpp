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
#include "TSP.h"
#include "EdmondsKarp.h"

using namespace std;

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
    Directed_Graph.edmondsKarp();
    cout << "Maximum flow from " << start << " to " << end << " is " << Directed_Graph.maxFlow << endl;
    cout << "-------------------------------------" << endl;

	return 0;
}