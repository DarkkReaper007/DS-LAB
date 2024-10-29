#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Iterative function to insert a new node in the binary tree
TreeNode* insertNode(TreeNode* root, int data) {
    TreeNode* newNode = createNode(data);

    // If tree is empty, the new node becomes the root
    if (root == NULL) {
        return newNode;
    }

    // Use a queue for level-order insertion
    TreeNode* queue[100];  // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        // Insert in the left child if it is empty
        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            queue[rear++] = current->left;
        }

        // Insert in the right child if it is empty
        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    return root;
}

// Recursive inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Recursive preorder traversal
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Recursive postorder traversal
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function to test the binary tree implementation
int main() {
    TreeNode* root = NULL;

    // Insert elements iteratively into the binary tree
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);

    // Display the tree elements in different traversal orders
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
