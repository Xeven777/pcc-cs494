#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

void bellmanFord(int graph[][3], int E, int distance[], int S, int V){
	distance[S] = 0;
	for (int i = 1; i < V; i++){
		int i, u, v, w;
        	for (i = 0; i < E; i++){
            	u = graph[i][0];
            	v = graph[i][1];
            	w = graph[i][2];
            	if (distance[u] != INT_MAX && (distance[u] + w) < distance[v]) distance[v] = distance[u] + w;
        	}
    	}
    
    	printf("\nThe Shortest Distances from Source %d are : \n", S);
    	for (int i = 0; i < V; i++){
        	if (i == S) continue;
        	printf("Vertex: %d \t Distance: %d\n", i, distance[i]);
    	}
}

int main(){
	printf("Enter the no. of Vertices : ");
	int vertices, edges;
    	scanf("%d", &vertices);
    	int distance[vertices];
    	int source, i;
    	printf("Enter no. of Edges : ");
    	scanf("%d", &edges);
    	int graph[edges][3];
    	printf("Enter the Adjacency List (Source, Destination and Cost) : \n");
    	for (i = 0; i < edges; i++) scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    	for (i = 0; i < vertices; i++) distance[i] = INT_MAX;
    	printf("Enter the Source vertex : ");
    	scanf("%d", &source);
    	bellmanFord(graph, edges, distance, source, vertices);
    	return 0;
}
