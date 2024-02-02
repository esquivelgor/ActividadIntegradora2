#ifndef _EDMONDSKARP_H_
#define _EDMONDSKARP_H_

#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include "Graph.h"

inline int Graph::BFS(vector<int>& parent) {
    
    parent.assign(n, -1);
    parent[start] = -2;
    queue<pair<int, int>> q; // (current_vertex, current_flow)
    q.push({start, INT_MAX});

    while (!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;

        q.pop();

        int i = 0;
        for (int next : wt[current]) {
            
            if ((next > 0) && (parent[i] == -1)) {
                parent[i] = current;
                int new_flow = min(flow, wt[current][i]);
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
    
    vector<int> parent(n);
    int newFlow;

    while((newFlow = BFS(parent))){
        maxFlow += newFlow;
        int current = end;
        while (current != start) {
            int prev = parent[current];
            wt[prev][current] -= newFlow;
            wt[current][prev] += newFlow;
            current = prev;
        }
    }
}




#endif // _EDMONDSKARP_H_