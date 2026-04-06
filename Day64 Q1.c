// Perform BFS from a given source using queue.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Queue implementation using array
int queue[100], front = -1, rear = -1;

void enqueue(int x)
{
    if(rear == 99)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if(front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void BFS(int s, struct Node* adj[], int visited[])
{
    enqueue(s);
    visited[s] = 1;

    while(front <= rear)
    {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];

        while(temp != NULL)
        {
            int adjVertex = temp->data;

            if(!visited[adjVertex])
            {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m, i;
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    for(i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed, 2 for Undirected: ");
    scanf("%d", &choice);

    int u, v;

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        if(choice == 2)
        {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    int visited[n];
    for(i = 0; i < n; i++)
        visited[i] = 0;

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(s, adj, visited);

    return 0;
}
