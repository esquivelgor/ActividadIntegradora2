// =========================================================
// File: EdmondsKarp.h
// Authors:
//  Guillermo Esquivel Ortiz - A01625621
//  Jesus Castillo Cabello   - A01382000
// Date: 02/02/2024
// =========================================================

#ifndef _EDMONDSKARP_H_
#define _EDMONDSKARP_H_

#include <queue>
#include "Graph.h"

// --------------- Methods for problem 3 - Edmonds-Karp Algorithm ---------------

inline int Graph::BFS(vector<int>& visited) {
    
    visited.assign(n, -1);
    visited[start] = -2;
    queue<pair<int, int>> q; // (node, flow)
    q.push({start, INT_MAX});

    while (!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;

        q.pop();

        int i = 0;
        for (int next : wt[current]) {
            
            // If connection existds and is not visited then
            if ((next > 0) && (visited[i] == -1)) {
                visited[i] = current;
                // calculate the new flow
                int new_flow = min(flow, wt[current][i]);
                // if we have reached the sink, then return our new flow
                if (i == end) {
                    return new_flow;
                }
                q.push({i, new_flow});
            }
            i++;
        }
    }
    return 0;
}

inline void Graph::edmondsKarp(){
    
    vector<int> visited(n);
    int newFlow;

    while((newFlow = BFS(visited))){
        maxFlow += newFlow;
        int current = end;
        // Trace back the augmenting path and update residual capacities
        while (current != start) {
            int prev = visited[current];
            wt[prev][current] -= newFlow;
            wt[current][prev] += newFlow;
            current = prev;
        }
    }
    cout << "Maximum flow from " << start << " to " << end << " is " << maxFlow << endl;
}

#endif // _EDMONDSKARP_H_