#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int meetings[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i][0], &meetings[i][1]);
    }

    qsort(meetings, n, sizeof(meetings[0]), compare);

    int heap[n];
    int size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (size > 0 && heap[0] <= meetings[i][0]) {
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(heap, size, 0);
        }

        heap[size] = meetings[i][1];
        heapifyUp(heap, size);
        size++;

        if (size > maxRooms)
            maxRooms = size;
    }

    printf("%d\n", maxRooms);

    return 0;
}
