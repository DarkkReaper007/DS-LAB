#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// Queue node for level-order traversal
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Stack functions for iterative traversal
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

int isEmpty(StackNode* top) {
    return top == NULL;
}

// Queue functions for level-order traversal
QueueNode* createQueueNode(TreeNode* treeNode) {
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
    queueNode->treeNode = treeNode;
    queueNode->next = NULL;
    return queueNode;
}

void enqueue(QueueNode** front, QueueNode** rear, TreeNode* treeNode) {
    QueueNode* newNode = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

TreeNode* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) return NULL;
    QueueNode* temp = *front;
    TreeNode* treeNode = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return treeNode;
}

// Iterative Preorder Traversal
void iterativePreorder(TreeNode* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        TreeNode* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

// Iterative Inorder Traversal
void iterativeInorder(TreeNode* root) {
    StackNode* stack = NULL;
    TreeNode* curr = root;

    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            push(&stack, curr);
            curr = curr->left;
        }
        curr = pop(&stack);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Iterative Postorder Traversal using single stack
void iterativePostorder(TreeNode* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while (curr != NULL || !isEmpty(stack)) {
        if (curr != NULL) {
            push(&stack, curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = stack->treeNode;
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                printf("%d ", peekNode->data);
                lastVisited = pop(&stack);
            }
        }
    }
}

// Level Order Traversal
void levelOrder(TreeNode* root) {
    if (root == NULL) return;
    QueueNode* front = NULL;
    QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        TreeNode* node = dequeue(&front, &rear);
        printf("%d ", node->data);

        if (node->left) enqueue(&front, &rear, node->left);
        if (node->right) enqueue(&front, &rear, node->right);
    }
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Display the elements using different traversal methods
    printf("Iterative Preorder traversal:\n");
    iterativePreorder(root);
    printf("\n");

    printf("Iterative Inorder traversal:\n");
    iterativeInorder(root);
    printf("\n");

    printf("Iterative Postorder traversal:\n");
    iterativePostorder(root);
    printf("\n");

    printf("Level Order traversal:\n");
    levelOrder(root);
    printf("\n");

    return 0;
}
