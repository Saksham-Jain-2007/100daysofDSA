// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// PROGRAM:

#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int prefixSum[MAX];
    int index[MAX];
    
    // Initialize
    for (int i = 0; i < MAX; i++) {
        index[i] = -1;
    }

    int sum = 0, max_length = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is zero, update max_length
        if (sum == 0) {
            max_length = i + 1;
        }

        // Check if this sum has been seen before
        for (int j = 0; j < i; j++) {
            if (prefixSum[j] == sum) {
                if (i - j > max_length) {
                    max_length = i - j;
                }
            }
        }

        // Store prefix sum
        prefixSum[i] = sum;
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
