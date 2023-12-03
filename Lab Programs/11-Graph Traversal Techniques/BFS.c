#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize a queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return value;
    }
}

// Function to perform BFS on a graph
void BFS(int graph[MAX_SIZE][MAX_SIZE], int vertices, int startVertex) {
    struct Queue q;
    initializeQueue(&q);

    int visited[MAX_SIZE] = {0};
    printf("BFS traversal starting from vertex %d: ", startVertex);

    // Enqueue the starting vertex
    enqueue(&q, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&q)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                // Enqueue the adjacent vertex if not visited
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");

    // Input the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}
