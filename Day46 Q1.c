// Implement the solution for this problem.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    if (data == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

// Queue for BFS
struct Node* queue[100];
int front = 0, rear = -1;

// Enqueue
void enqueue(struct Node* node) {
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* curr = dequeue();

        printf("%d ", curr->data);

        if (curr->left != NULL)
            enqueue(curr->left);

        if (curr->right != NULL)
            enqueue(curr->right);
    }
}

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, 0, n);

    levelOrder(root);

    return 0;
}
