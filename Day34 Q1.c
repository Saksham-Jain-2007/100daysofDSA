// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node (linked list)
struct Node {
    int data;
    struct Node* next;
};

// Push
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Pop
struct Node* pop(struct Node* top, int* value) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    struct Node* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Evaluate postfix
int evaluate(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while (expr[i] != '\0') {

        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If digit
        if (isdigit(expr[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            stack = push(stack, num);
        }

        // Operator
        else {
            int val1, val2;

            stack = pop(stack, &val2);
            stack = pop(stack, &val1);

            int result;

            switch (expr[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            stack = push(stack, result);
            i++;
        }
    }

    int finalResult;
    stack = pop(stack, &finalResult);
    return finalResult;
}

int main() {
    char expr[100];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    printf("%d", evaluate(expr));

    return 0;
}
