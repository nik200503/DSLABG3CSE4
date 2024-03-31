#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLCA = lca(root->left, n1, n2);
    Node* rightLCA = lca(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
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

    int n1 = 4, n2 = 5;
    Node* lcaNode = lca(root, n1, n2);
    printf("LCA of %d and %d is %d\n", n1, n2, lcaNode->data);

    return 0;
}