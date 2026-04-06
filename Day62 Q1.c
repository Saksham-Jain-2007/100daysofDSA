// Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Structure for node
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

int main()
{
    int n, m, i;
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Array of pointers (Adjacency List)
    struct Node* adj[n];

    // Initialize all lists as NULL
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

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected, add u to v's list
        if(choice == 2)
        {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        struct Node* temp = adj[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
