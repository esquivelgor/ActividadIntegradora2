//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
//Graph is a adjacency list.
//PQ.exe<input.txt  Comand Prompt

//Priority queue of all the edges connected to the tree
#include <iostream>
#include <vector>
#include<queue>
#include<fstream>
#include <bits/stdc++.h>
 

using namespace std;
typedef pair<int, int> node;

void UpdateQ(priority_queue<node, vector<node>, greater<node>> &Q, int v, int newWeigth){
    priority_queue<node, vector<node>, greater<node>> tempQ;

    //search for node
    while (Q.top().second !=  v){
        tempQ.push(Q.top());
        Q.pop();
    }
    //Update node
    Q.pop();
    Q.push(make_pair(newWeigth, v));

    //Retur all nodes to Q
    while (!tempQ.empty())
    {
        Q.push(tempQ.top());
        tempQ.pop();
        
    }


}

int main(){
    int n, a, b, dummy;

    
    //cin >> n >> a >> b;
    n = 5;
    a = 0;
    b = 3;

    vector<vector<node>> Grafo1(n);
    vector<vector<node>> Grafo2(n); // adjacency list of the graph

    Grafo1[0].push_back(make_pair(0, 0));
    Grafo1[0].push_back(make_pair(16, 1));
    Grafo1[0].push_back(make_pair(45, 2));
    Grafo1[0].push_back(make_pair(32, 3));

    
    Grafo1[1].push_back(make_pair(16, 0));
    Grafo1[1].push_back(make_pair(0, 1));
    Grafo1[1].push_back(make_pair(18, 2));
    Grafo1[1].push_back(make_pair(21, 3));

    Grafo1[2].push_back(make_pair(45, 0));
    Grafo1[2].push_back(make_pair(18, 1));
    Grafo1[2].push_back(make_pair(0, 2));
    Grafo1[2].push_back(make_pair(7, 3));

    Grafo1[3].push_back(make_pair(32, 0));
    Grafo1[3].push_back(make_pair(21, 1));
    Grafo1[3].push_back(make_pair(7, 2));
    Grafo1[3].push_back(make_pair(0, 3));
    //testcase
    Grafo1[0].push_back(make_pair(-1, 4));
    Grafo1[1].push_back(make_pair(-1, 4));
    Grafo1[2].push_back(make_pair(-1, 4));
    Grafo1[3].push_back(make_pair(10, 4));
    
    
    Grafo1[4].push_back(make_pair(-1, 0));
    Grafo1[4].push_back(make_pair(-1, 1));
    Grafo1[4].push_back(make_pair(-1, 2));
    Grafo1[4].push_back(make_pair(10, 3));
    Grafo1[4].push_back(make_pair(0, 4));

    
    //MST-PRIM
    int parent[n];
    bool visited[n];
    //registra el peso minimo para esa conexion
    int key[n];

    for (int i = 0; i < n; i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        //v is in Q
        visited[i] = false;
    }
    

    key[0] = 0;

    priority_queue<node, vector<node>, greater<node>> Q;
    
    //Insert all nodes into Q
    for (int u = 0; u < n; u++){
        Q.push(make_pair(key[u], u));
    }
    
    while (!Q.empty())
    {
        int u = Q.top().second;
        //Para todos los nodos adyacentas a u
        for (int v = 0; v < n; v++)
        {
            //Si esta en Q via visited
            //Si tiene relacion
            //SI el peso de  la conexion es menor al peso en key
            if (!visited[v] && Grafo1[u][v].first > 0 && Grafo1[u][v].first < key[v]){
                parent[v]  = u;
                visited[v] = true;//???close
                key[v] = Grafo1[u][v].first;
                //Change key in Q
                //Decrease Key. El primer for vez corre bien, despues no puedo hacer que pare
                UpdateQ(Q, v, key[v]);
            }
            
        }
        Q.pop();
        

    }

    cout << "END";

    return 0;
}