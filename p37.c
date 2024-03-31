#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int hd;
} Node;

void bottomView(Node* root) {
    if (root == NULL)
        return;

    int hd = 0;
    int minHd = 0, maxHd = 0;
    Node* queue[100];
    int front = 0, rear = 0;
    int map[100] = {0};

    queue[rear++] = root;
    root->hd = hd;

    while (front != rear) {
        Node* temp = queue[front++];

        if (temp->hd < minHd)
            minHd = temp->hd;
        else if (temp->hd > maxHd)
            maxHd = temp->hd;

        map[temp->hd] = temp->data;

        if (temp->left) {
            temp->left->hd = temp->hd - 1;
            queue[rear++] = temp->left;
        }

        if (temp->right) {
            temp->right->hd = temp->hd + 1;
            queue[rear++] = temp->right;
        }
    }

    for (int i = minHd; i <= maxHd; i++)
        printf("%d ", map[i]);
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

    printf("Bottom View: ");
    bottomView(root);

    return 0;
}