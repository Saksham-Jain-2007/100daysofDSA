// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// PROGRAM:

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1)
        return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Dequeue m times
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display result
    display();

    return 0;
}
