// Perform DFS starting from a given source vertex using recursion.

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

// DFS function
void DFS(int v, struct Node* adj[], int visited[])
{
    printf("%d ", v);
    visited[v] = 1;

    struct Node* temp = adj[v;

    while(temp != NULL)
    {
        int adjVertex = temp->data;

        if(!visited[adjVertex])
        {
            DFS(adjVertex, adj, visited);
        }
        temp = temp->next;
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

    printf("DFS Traversal: ");
    DFS(s, adj, visited);

    return 0;
}
