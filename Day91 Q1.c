#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (current + boards[i] <= maxTime) {
            current += boards[i];
        } else {
            painters++;
            current = boards[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
