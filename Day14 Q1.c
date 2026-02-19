// Question: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>

int main() {
    int n;

    // Read size of square matrix
    scanf("%d", &n);

    int A[n][n];

    // Read matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check identity condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j && A[i][j] != 1) {
                printf("Not an Identity Matrix");
                return 0;
            }

            if (i != j && A[i][j] != 0) {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    printf("Identity Matrix");

    return 0;
}
