#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure of a tree node
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Stack node to hold tree nodes
typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// Function to create a new tree node
TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Stack functions for tree nodes
StackNode* createStackNode(TreeNode* treeNode) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->treeNode = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode** top, TreeNode* treeNode) {
    StackNode* newNode = createStackNode(treeNode);
    newNode->next = *top;
    *top = newNode;
}

TreeNode* pop(StackNode** top) {
    if (*top == NULL) return NULL;
    StackNode* temp = *top;
    TreeNode* res = temp->treeNode;
    *top = (*top)->next;
    free(temp);
    return res;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct the expression tree from a postfix expression
TreeNode* constructExpressionTree(char postfix[]) {
    StackNode* stack = NULL;
    int i;

    // Traverse each character in the postfix expression
    for (i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        // If the character is an operand, create a node and push it to the stack
        if (isdigit(ch)) {
            push(&stack, createNode(ch));
        }
        // If the character is an operator, pop two nodes and make them children
        else if (isOperator(ch)) {
            TreeNode* node = createNode(ch);

            // The first popped item becomes the right child
            node->right = pop(&stack);
            // The second popped item becomes the left child
            node->left = pop(&stack);

            // Push the operator node back to the stack
            push(&stack, node);
        }
    }

    // The remaining node in the stack is the root of the expression tree
    return pop(&stack);
}

// Function to evaluate the expression tree
int evaluateExpressionTree(TreeNode* root) {
    // Base case: if the node is a leaf node (operand), return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';  // Convert char to int
    }

    // Evaluate the left and right subtrees
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);

    // Apply the operator at the root
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

// Function to print the expression tree in inorder (for verification)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

// Main function to test the expression tree creation and evaluation
int main() {
    char postfix[] = "53+82-*";

    // Construct the expression tree
    TreeNode* root = constructExpressionTree(postfix);

    // Display the tree in inorder traversal (optional)
    printf("Inorder traversal of the expression tree: ");
    inorderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);
    printf("Result of expression evaluation: %d\n", result);

    return 0;
}
