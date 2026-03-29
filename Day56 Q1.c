// Check whether a given binary tree is symmetric around its center.

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

// Queue for building tree
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

// Check mirror
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Check symmetric
int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
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

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
