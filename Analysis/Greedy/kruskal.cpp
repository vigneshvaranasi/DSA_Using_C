#include <iostream>
#include <climits>
#define MAX 100
using namespace std;

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

void initGraph(Graph *graph, int numVertices)
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

void addEdge(Graph *graph, int src, int dest, int weight)
{
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices)
    {
        graph->adjMatrix[src][dest] = weight;
        graph->adjMatrix[dest][src] = weight;
    }
}

void printGraph(Graph *graph)
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            cout << graph->adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int find(int i)
{
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

void unionSets(int i, int j)
{
    parent[i] = j;
}

void kruskalMST(Graph *graph, Edge edges[])
{
    int numEdges = graph->numVertices * (graph->numVertices - 1) / 2;
    int edgeCount = 0;

    for (int i = 0; i < numEdges - 1; i++)
    {
        for (int j = 0; j < numEdges - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        parent[i] = -1;
    }

    cout << "\nMinimum Spanning Tree (MST) Edges (Kruskal's Algorithm):\n";
    for (int i = 0; i < numEdges && edgeCount < graph->numVertices - 1; i++)
    {
        int set1 = find(edges[i].src);
        int set2 = find(edges[i].dest);

        if (set1 != set2)
        {
            cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
            unionSets(set1, set2);
            edgeCount++;
        }
    }
}

int main()
{
    Graph graph;
    int n, Edges;
    cout << "Enter the number of vertices: ";
    cin >> n;
    initGraph(&graph, n);

    Edge edges[MAX * (MAX - 1) / 2];
    int edgeIndex = 0;

    cout << "Enter the number of edges: ";
    cin >> Edges;

    for (int i = 0; i < Edges; i++)
    {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;

        addEdge(&graph, src, dest, weight);

        edges[edgeIndex].src = src;
        edges[edgeIndex].dest = dest;
        edges[edgeIndex].weight = weight;

        edgeIndex++;
    }

    printGraph(&graph);
    kruskalMST(&graph, edges);

    return 0;
}
