#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int spSet[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++){
		if (spSet[i] == 0 && dist[i] <= min) min = dist[i], min_index = i;
	}
	return min_index;
}

void djikstra(int graph[V][V], int src){
	int dist[V];
	int spSet[V];
	
	for (int i = 0; i < V; i++){
		spSet[i] = 0;
		dist[i] = INT_MAX;
	}
	
	dist[src] = 0;
	
	for (int i = 0; i < V-1; i++){
		int x = minDistance(dist, spSet);
		spSet[x] = 1;
		for (int j = 0; j < V; j++){
			if (!spSet[j] && graph[x][j] && dist[x] != INT_MAX && dist[x] + graph[x][j] < dist[j]) dist[j] = dist[x] + graph[x][j];
		}
	}
	
	for (int i = 0; i < V; i++) printf("Distance from source to %d: %d\n", i, dist[i]); 
}


int main(){
	int graph[V][V], n, u;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	printf("Enter the adjacency matrix of the graph: \n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	
	printf("Enter the starting node: ");
	scanf("%d", &u);
	
	djikstra(graph, u);
	
	return 0;
}
