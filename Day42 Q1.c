// Given a queue of integers, reverse the queue using a stack.

// PROGRAM:

#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }

    // Output
    display();

    return 0;
}
