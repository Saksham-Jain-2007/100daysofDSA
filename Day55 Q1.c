// Print the nodes visible when the binary tree is viewed from the right side.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue implementation
struct Node* queue[2000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 1999) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}

// Right View Traversal
void rightView(struct Node* root) {
    if (!root) return;

    struct Node* q[2000];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];

            // Print last node of this level
            if (i == size - 1) {
                printf("%d ", node->data);
            }

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    rightView(root);

    return 0;
}
