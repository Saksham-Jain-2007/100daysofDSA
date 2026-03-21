// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Check if value exists in list
int exists(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

// Find intersection (value-based)
void findIntersection(struct Node* l1, struct Node* l2) {
    while (l1 != NULL) {
        if (exists(l2, l1->data)) {
            printf("%d", l1->data);
            return;
        }
        l1 = l1->next;
    }
    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }

    // Find intersection
    findIntersection(list1, list2);

    return 0;
}
