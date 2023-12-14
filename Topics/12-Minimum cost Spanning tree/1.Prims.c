#include <stdio.h>
#include <limits.h>
#define MAX 10
struct Graph
{
    int numVertices;
    int adjMatrix[MAX][MAX];
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

void primMST(struct Graph *graph)
{
    int key[MAX]; // Key values used to pick minimum weight edge in cut
    for (int i = 0; i < graph->numVertices; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0; // Make key 0 so that this vertex is picked as the first vertex
    for (int count = 0; count < graph->numVertices - 1; count++)
    {
        int u = -1;
        for (int v = 0; v < graph->numVertices; v++)
        {
            if (key[v] != -1 && (u == -1 || key[v] < key[u]))
            {
                u = v;
            }
        }
        key[u] = -1; // Mark vertex u as processed
        for (int v = 0; v < graph->numVertices; v++)
        {
            if (graph->adjMatrix[u][v] && key[v] != -1 && graph->adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("\nMinimum Spanning Tree (MST) Edges:\n");
    for (int i = 1; i < graph->numVertices; i++)
    {
        printf("%d - %d : %d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
    }
}

int main()
{
    struct Graph graph;
    int n, Edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph(&graph, n);
    printf("Enter the number of edges: ");
    scanf("%d", &Edges);
    for (int i = 0; i < Edges; i++)
    {
        int src, dest, weight;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }
    printGraph(&graph);
    primMST(&graph);
    return 0;
}