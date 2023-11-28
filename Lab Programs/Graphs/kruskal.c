#include <stdio.h>
#include <limits.h>
#define MAX 100

struct Graph
{
    int numVertices;
    int adjMatrix[MAX][MAX];
};

struct Edge
{
    int src, dest, weight;
};

int parent[MAX];

void initGraph(struct Graph *graph, int numVertices)
{
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices)
    {
        graph->adjMatrix[src][dest] = weight;
        graph->adjMatrix[dest][src] = weight;
    }
}

void printGraph(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Helper function for Kruskal's algorithm to find the set of a vertex
int find(int i)
{
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

// Helper function for Kruskal's algorithm to perform union of two sets
void unionSets(int i, int j)
{
    parent[i] = j;
}

// Kruskal's algorithm
void kruskalMST(struct Graph *graph, struct Edge edges[])
{
    int numEdges = graph->numVertices * (graph->numVertices - 1) / 2;
    int edgeCount = 0;

    // Sort edges in non-decreasing order of their weights
    for (int i = 0; i < numEdges - 1; i++)
    {
        for (int j = 0; j < numEdges - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                // Swap edges
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (int i = 0; i < graph->numVertices; i++)
    {
        parent[i] = -1;
    }

    printf("\nMinimum Spanning Tree (MST) Edges (Kruskal's Algorithm):\n");
    for (int i = 0; i < numEdges && edgeCount < graph->numVertices - 1; i++)
    {
        int set1 = find(edges[i].src);
        int set2 = find(edges[i].dest);

        if (set1 != set2)
        {
            printf("%d - %d : %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(set1, set2);
            edgeCount++;
        }
    }
}

int main()
{
    struct Graph graph;
    int n, Edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph(&graph, n);

    // Input edges
    struct Edge edges[MAX * (MAX - 1) / 2];
    int edgeIndex = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &Edges);

    for (int i = 0; i < Edges; i++)
    {
        int src, dest, weight;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);

        // Add edge to the graph
        addEdge(&graph, src, dest, weight);

        // Add edge to the edges array for Kruskal's algorithm
        edges[edgeIndex].src = src;
        edges[edgeIndex].dest = dest;
        edges[edgeIndex].weight = weight;

        edgeIndex++;
    }

    printGraph(&graph);
    // Perform Kruskal's algorithm
    kruskalMST(&graph, edges);

    return 0;
}
