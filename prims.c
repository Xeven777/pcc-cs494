#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++){
		if (mstSet[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void printTree(int parent[], int graph[V][V]){
	printf("Edge\t Weight\n");
	for (int i = 1; i < V; i++){
		printf("%d - %d\t %d \n", parent[i], i, graph[i][parent[i]]);
	}
}

void primsAlgo(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	
	for (int i = 0; i < V; i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	for (int i = 0; i < V; i++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		
		for (int j = 0; j < V; j++){
			if (graph[i][j] && mstSet[j] == false && graph[i][j] < key[j]){
				parent[j] = i;
				key[j] = graph[i][j];
			}
		}
	}
	
	printTree(parent, graph);
}

int main(){
	int graph[V][V];
	printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
	
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	
	primsAlgo(graph);
	return 0;
}

// Lets have the user input as 

/*
0 2 0 6 0
2 0 3 8 5 
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
