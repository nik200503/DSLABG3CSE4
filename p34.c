#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node* root) {
    if (root == NULL)
        return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int heightOfRoot = height(root->left) + height(root->right) + 1;

    return max(heightOfRoot, max(leftDiameter, rightDiameter));
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 1;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = (Node*)malloc(sizeof(Node));
    root->left->right = (Node*)malloc(sizeof(Node));
    root->left->left->data = 4;
    root->left->right->data = 5;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    int treeDiameter = diameter(root);
    printf("Diameter of the binary tree: %d\n", treeDiameter);

    return 0;
}