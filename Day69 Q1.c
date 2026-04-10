// Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode heap[MAX];
    int size;
} MinHeap;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap* h, int i) {
    while (i && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap* h, int v, int dist) {
    h->heap[h->size].vertex = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract min
HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Check empty
int isEmpty(MinHeap* h) {
    return h->size == 0;
}

// Dijkstra Algorithm
void dijkstra(Node* adj[], int n, int src) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (!isEmpty(&h)) {
        HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Driver code
int main() {
    int n = 5;
    Node* adj[MAX] = {NULL};

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);

    dijkstra(adj, n, 0);

    return 0;
}
