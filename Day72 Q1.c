// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// PROGRAM:

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    // Input string
    scanf("%s", s);

    // Traverse string
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        freq[index]++;

        // If character appears second time
        if (freq[index] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If no repeated character
    printf("-1\n");

    return 0;
}
