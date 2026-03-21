// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// PROGRAM:

#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Push front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

// Pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

// Front element
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Back element
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Size
void getSize() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }

    int size = (rear - front + MAX) % MAX + 1;
    printf("%d\n", size);
}

// Display deque
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            getFront();
        }
        else if (strcmp(op, "back") == 0) {
            getBack();
        }
        else if (strcmp(op, "size") == 0) {
            getSize();
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}
