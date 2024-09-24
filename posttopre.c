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

// Function to convert prefix to postfix
void prefixToPostfix(char* prefix, char* postfix) {
    Stack stack;
    initStack(&stack);

    int len = strlen(prefix);

    // Iterate through the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it onto the stack
        if (isOperand(c)) {
            char operand[2] = {c, '\0'};  // Create a string from the operand
            push(&stack, operand);
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            char* op1 = pop(&stack);
            char* op2 = pop(&stack);

            // Manually allocate space for the combined result
            // Space: op1 (strlen(op1)) + op2 (strlen(op2)) + operator (1) + null terminator (1)
            int resultSize = strlen(op1) + strlen(op2) + 2;  // Extra space for operator and null character
            char* result = (char*)malloc(resultSize * sizeof(char));

            // Manually concatenate the operands and the operator in postfix order
            result[0] = '\0';  // Initialize the result string

            // Concatenate op1, op2, and the operator
            strcat(result, op1);  // Add first operand
            strcat(result, op2);  // Add second operand
            result[strlen(result)] = c;  // Add the operator at the end
            result[strlen(result) + 1] = '\0';  // Ensure null termination

            // Push the combined result back onto the stack
            push(&stack, result);

            // Free dynamically allocated memory for operands
            free(op1);
            free(op2);
        }
    }

    // The final result will be in the stack
    strcpy(postfix, pop(&stack));
}

// Main function to test the conversion
int main() {
    char prefix[MAX], postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
