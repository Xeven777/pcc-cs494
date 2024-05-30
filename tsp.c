#include <stdio.h>
#include <limits.h>

#define NUM_CITIES 4

// Function to calculate the total distance of a given path
int calculateDistance(int graph[][NUM_CITIES], int path[])
{
    int distance = 0;
    for (int i = 0; i < NUM_CITIES - 1; i++)
    {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[NUM_CITIES - 1]][path[0]]; // Return to the starting city
    return distance;
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate all permutations of the cities
void generatePermutations(int graph[][NUM_CITIES], int path[], int l, int r, int *minDistance, int bestPath[])
{
    if (l == r)
    {
        int currentDistance = calculateDistance(graph, path);
        if (currentDistance < *minDistance)
        {
            *minDistance = currentDistance;
            for (int i = 0; i < NUM_CITIES; i++)
            {
                bestPath[i] = path[i];
            }
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(&path[l], &path[i]);
            generatePermutations(graph, path, l + 1, r, minDistance, bestPath);
            swap(&path[l], &path[i]); // Backtrack
        }
    }
}

int main()
{
    // Distance matrix
    int graph[NUM_CITIES][NUM_CITIES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int path[NUM_CITIES] = {0, 1, 2, 3};
    int bestPath[NUM_CITIES];
    int minDistance = INT_MAX;

    generatePermutations(graph, path, 0, NUM_CITIES - 1, &minDistance, bestPath);

    printf("Minimum distance: %d\n", minDistance);
    printf("Optimal path: ");
    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%d ", bestPath[i]);
    }
    printf("%d\n", bestPath[0]); // Return to the starting city

    return 0;
}
