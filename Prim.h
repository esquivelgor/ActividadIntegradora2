#ifndef _Prim_H_
#define _Prim_H_

#include <iostream>
#include "Graph.h"
//Get the minimum weight for non visited nodes
int minKey(int weight[], bool visited[], int n)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (visited[v] == false && weight[v] < min)
			min = weight[v], min_index = v;

	return min_index;
}


void Graph::Prim(){
    //n ya esta definida
    //arbol es el arbol que vamos contruyendo. tiene los nodos padre los indices
    //weight es elarreglo del peso minimo para llegar a cada nodo
    //visited son los nodos ya visitados
    int arbol[n];
	int weight[n];
	bool visited[n];

	// Inicializamos los pesos weights como INFINITE
	for (int i = 0; i < n; i++){
		weight[i] = INT_MAX;
	    visited[i] = false;
	}

	//Iniciamos el arbol en el nodo 0 con peso 0
	weight[0] = 0;
	arbol[0] = -1;


    
	for (int count = 0; count < n - 1; count++) {
		
		//Escogemos el nodo con peso minimo que no ha sido visitado
		int u = minKey(weight, visited, n);

		//Se marca como vvisitado
		visited[u] = true;

        //Actualiza los pesos y el arbol de los vecinos del nodo visitado. 
		for (int v = 0; v < n; v++)

            //Si hay conexion y no ha sido visitado yy el peso es menor al registrado en weight
            //Actualiza el peso y arbol
			if (wt[u][v] > 0 && visited[v] == false && wt[u][v] < weight[v]){
				arbol[v] = u;
				weight[v] = wt[u][v];
			}
	}

    //imprime el arbol
    for (int i = 1; i < n; i++)
    cout << "(" <<  arbol[i] << ", " << i << ")" << endl;
}


#endif 