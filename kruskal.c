#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge
{
	int src, dest, weight;
};

// Function to compare two edges according to their weights (used in qsort)
int compareEdges(const void *a, const void *b)
{
	struct Edge *a1 = (struct Edge *)a;
	struct Edge *b1 = (struct Edge *)b;
	return a1->weight - b1->weight;
}

// Function to check if adding an edge creates a cycle
int createsCycle(int parent[], int src, int dest)
{
	while (parent[src] != -1)
	{
		src = parent[src];
	}
	while (parent[dest] != -1)
	{
		dest = parent[dest];
	}
	return src == dest;
}

// Function to apply union operation
void applyUnion(int parent[], int src, int dest)
{
	while (parent[src] != -1)
	{
		src = parent[src];
	}
	while (parent[dest] != -1)
	{
		dest = parent[dest];
	}
	parent[dest] = src;
}

// The main function to construct MST using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E)
{
	qsort(edges, E, sizeof(edges[0]), compareEdges);

	struct Edge result[V]; // To store the resultant MST
	int parent[V];		   // Array to store the parent of each vertex
	int e = 0;			   // Index for result[]
	int i = 0;			   // Index for sorted edges

	// Initialize all vertices as their own parent
	for (int v = 0; v < V; ++v)
	{
		parent[v] = -1;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1 && i < E)
	{
		// Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
		struct Edge next_edge = edges[i++];

		int src = next_edge.src;
		int dest = next_edge.dest;

		if (!createsCycle(parent, src, dest))
		{
			result[e++] = next_edge;
			applyUnion(parent, src, dest);
		}
	}

	// Print the contents of result[] to display the built MST
	printf("Edge \tWeight\n");
	int totalWeight = 0;
	for (i = 0; i < e; ++i)
	{
		printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
		totalWeight += result[i].weight;
	}
	printf("The minimum total weight of the MST is: %d\n", totalWeight);
}

int main()
{
	int V, E;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &V);
	printf("Enter the number of edges in the graph: ");
	scanf("%d", &E);

	struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));

	printf("Enter source, destination, and weight for each edge:\n");
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
	}

	kruskalMST(edges, V, E);

	free(edges);
	return 0;
}
