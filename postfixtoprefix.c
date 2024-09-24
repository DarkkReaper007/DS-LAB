#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure for strings
typedef struct {
    char* arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push a string onto the stack
void push(Stack* stack, char* str) {
    stack->arr[++(stack->top)] = strdup(str);  // Copy the string
}

// Pop a string from the stack
char* pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return NULL;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if a character is an operand (without using ctype.h)
int isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

// Function to convert postfix to prefix
void postfixToPrefix(char* postfix, char* prefix) {
    Stack stack;
    initStack(&stack);

    int len = strlen(postfix);

    // Iterate through the postfix expression from left to right
    for (int i = 0; i < len; i++) {
        char c = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isOperand(c)) {
            char operand[2] = {c, '\0'};  // Create a string from the operand
            push(&stack, operand);
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            char* op2 = pop(&stack);
            char* op1 = pop(&stack);

            // Manually allocate space for the combined result
            // Space: operator (1) + op1 (strlen(op1)) + op2 (strlen(op2)) + null terminator (1)
            int resultSize = strlen(op1) + strlen(op2) + 2;  // Extra space for operator and null character
            char* result = (char*)malloc(resultSize * sizeof(char));

            // Manually concatenate the operator and operands in prefix order
            result[0] = c;           // Place operator at the beginning
            result[1] = '\0';
            strcat(result, op1);     // Concatenate operand 1
            strcat(result, op2);     // Concatenate operand 2

            // Push the combined result back onto the stack
            push(&stack, result);

            // Free dynamically allocated memory for operands
            free(op1);
            free(op2);
        }
    }

    // The final result will be in the stack
    strcpy(prefix, pop(&stack));
}

// Main function to test the conversion
int main() {
    char postfix[MAX], prefix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToPrefix(postfix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
