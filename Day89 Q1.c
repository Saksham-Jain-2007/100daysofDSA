#include <stdio.h>

int canAllocate(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages)
            return 0;

        if (pages + books[i] <= maxPages) {
            pages += books[i];
        } else {
            students++;
            pages = books[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        if (books[i] > low)
            low = books[i];
        high += books[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
