#include <iostream>
#include <climits>
#define MAX 10
using namespace std;

struct Graph
{
    int numVertices;
    int adjMatrix[MAX][MAX];
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

void primMST(Graph *graph)
{
    int key[MAX];
    for (int i = 0; i < graph->numVertices; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;
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
        key[u] = -1;
        for (int v = 0; v < graph->numVertices; v++)
        {
            if (graph->adjMatrix[u][v] && key[v] != -1 && graph->adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    cout << "\nMinimum Spanning Tree (MST) Edges:" << endl;
    for (int i = 1; i < graph->numVertices; i++)
    {
        cout << parent[i] << " - " << i << " : " << graph->adjMatrix[i][parent[i]] << endl;
    }
}

int main()
{
    Graph graph;
    int n, Edges;
    cout << "Enter the number of vertices: ";
    cin >> n;
    initGraph(&graph, n);
    cout << "Enter the number of edges: ";
    cin >> Edges;
    for (int i = 0; i < Edges; i++)
    {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        addEdge(&graph, src, dest, weight);
    }
    printGraph(&graph);
    primMST(&graph);
    return 0;
}
