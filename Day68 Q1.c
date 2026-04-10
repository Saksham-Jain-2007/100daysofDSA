// Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// Check if empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

// Dequeue
int dequeue(Queue *q) {
    return q->items[q->front++];
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    // Step 1: Calculate in-degree of each node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0;
    int topo[MAX];

    // Step 3: Process queue
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        topo[count++] = u;

        // Reduce indegree of adjacent nodes
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Step 5: Print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int n = 6;

    // Adjacency matrix
    int adj[MAX][MAX] = {0};

    // Example graph
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(n, adj);

    return 0;
}
