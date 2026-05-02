#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node* next;
} Node;

void insertSorted(Node** head, float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL && curr->next->value < val) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->value;
            curr = curr->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    printf("\n");

    return 0;
}
