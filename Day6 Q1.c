// Question: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>

int main() {
    int n;

    // Read size
    scanf("%d", &n);

    int arr[n];

    // Read sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: if array has elements
    if (n > 0) {
        int j = 0;  // Pointer for unique elements

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[j]) {
                arr[++j] = arr[i];
            }
        }

        // Print unique elements
        for (int i = 0; i <= j; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
