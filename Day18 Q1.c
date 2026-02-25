// Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() 
{
    int n, k;

    // Read array size
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    int temp[n];

    // Rotate array
    for (int i = 0; i < n; i++) 
    {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
