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

// a) Recursive function to create a copy of a binary tree
TreeNode* copyTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // Create a new node with the same data as root
    TreeNode* newRoot = createNode(root->data);

    // Recursively copy the left and right subtrees
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}

// b) Recursive function to test for equality of two binary trees
int areTreesEqual(TreeNode* root1, TreeNode* root2) {
    // Both trees are empty, so they are equal
    if (root1 == NULL && root2 == NULL) return 1;

    // One of the trees is empty and the other is not, so they are not equal
    if (root1 == NULL || root2 == NULL) return 0;

    // Check if the data at the root is the same, and recursively check for equality
    // of left and right subtrees
    return (root1->data == root2->data) &&
           areTreesEqual(root1->left, root2->left) &&
           areTreesEqual(root1->right, root2->right);
}

// Function to print the tree in inorder traversal (for testing purposes)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // a) Create a copy of the binary tree
    TreeNode* copyRoot = copyTree(root);

    // Display the original and copied trees using inorder traversal
    printf("Inorder traversal of the original tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the copied tree: ");
    inorderTraversal(copyRoot);
    printf("\n");

    // b) Check if the original and copied trees are equal
    if (areTreesEqual(root, copyRoot)) {
        printf("The original tree and the copied tree are equal.\n");
    } else {
        printf("The original tree and the copied tree are not equal.\n");
    }

    return 0;
}
