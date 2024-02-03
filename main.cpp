// =========================================================
// File: main.cpp
// Authors:
//  Guillermo Esquivel Ortiz - A01625621
//  Jesus Castillo Cabello   - A01382000
// Date: 02/02/2024
// =========================================================

#include "TSP.h"
#include "EdmondsKarp.h"
#include "Prim.h"

int main() {
	
    int n, start, end;
    cin >> n >> start >> end;
	
    Graph Undirected_Graph(n, start, end);
	Graph Directed_Graph(n, start, end);

    cout << "-------------------------------------" << endl;
    cout << "Problem 1" << endl;
    Undirected_Graph.Prim();

    cout << "-------------------------------------" << endl;
    cout << "Problem 2" << endl;
    Undirected_Graph.TSP();

    cout << "-------------------------------------" << endl;
    cout << "Problem 3" << endl;
    Directed_Graph.edmondsKarp();

    cout << "-------------------------------------";

	return 0;
}