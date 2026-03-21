// Queue Using Array - Implement using linked list with dynamic memory allocation.

// PROGRAM:

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = value;
}

// Display
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Insert elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Output
    display();

    return 0;
}
