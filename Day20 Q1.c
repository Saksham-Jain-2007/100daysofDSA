// Given an array of integers, count the number of subarrays whose sum is equal to zero.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (assuming range is manageable)
#define MAX 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Hash map (frequency array)
    int hash[2 * MAX + 1] = {0};

    // Offset to handle negative sums
    int offset = MAX;

    hash[offset] = 1; // prefix sum = 0

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
