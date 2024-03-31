#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int maxLevel = 0;

void leftView(Node* root, int level) {
    if (root == NULL)
        return;

    if (maxLevel < level) {
        printf("%d ", root->data);
        maxLevel = level;
    }

    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
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

    printf("Left View: ");
    leftView(root, 1);

    return 0;
}