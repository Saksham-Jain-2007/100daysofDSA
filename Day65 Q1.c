// Using DFS and parent tracking, detect if undirected graph has a cycle.

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

// DFS function to detect cycle
int hasCycle(int v, int visited[], struct Node* adj[], int parent)
{
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        int adjVertex = temp->data;

        if(!visited[adjVertex])
        {
            if(hasCycle(adjVertex, visited, adj, v))
                return 1;
        }
        else if(adjVertex != parent)
        {
            return 1; // Cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int main()
{
    int n, m, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    for(i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u, v;

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int visited[n];
    for(i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    // Check all components
    for(i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(hasCycle(i, visited, adj, -1))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
