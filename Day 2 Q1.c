// Question:  Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// PROGRAM:

#include <stdio.h>

int main() {
    int n, pos;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position (1-based)
    scanf("%d", &pos);

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array (n-1 elements)
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
