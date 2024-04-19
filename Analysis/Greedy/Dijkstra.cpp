#include <iostream>
#include <climits>
#define MAX_VERTICES 10
using namespace std;

int minDistance(int dist[], bool visited[], int n) {
    int minDist = INT_MAX, minIndex;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printDistances(int dist[], int n) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " \t\t\t" << dist[i] << endl;
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int n) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};
    
    for (int i = 1; i <= n; i++) {
        if (i != src)
            dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printDistances(dist, n);
}

int main() {
    int n, numEdges, src;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
    }

    cout << "Enter Source vertex: ";
    cin >> src;

    dijkstra(graph, src, n);

    return 0;
}
/* 
6
9
1 2 2
2 3 6
3 4 9
4 5 3
5 6 2
6 1 8
6 3 3
6 2 5
3 5 1
1
 */