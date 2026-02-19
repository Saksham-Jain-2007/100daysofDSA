// Question: Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>

// Recursive power function
int power(int a, int b) {
    if (b == 0)
        return 1;          // Base case: a^0 = 1

    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Read input
    scanf("%d %d", &a, &b);

    // Print result
    printf("%d", power(a, b));

    return 0;
}
