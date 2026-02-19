// Question: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>

int main() {
    int m, n, sum = 0;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Read matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Sum of primary diagonal
    for (int i = 0; i < m && i < n; i++) {
        sum += A[i][i];
    }

    // Print result
    printf("%d", sum);

    return 0;
}
