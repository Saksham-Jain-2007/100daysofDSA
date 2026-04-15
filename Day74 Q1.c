// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// PROGRAM:

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        char temp[NAME_LEN];
        scanf("%s", temp);

        int found = -1;

        // Check if name already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    char winner[NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            // lexicographically smaller
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}
