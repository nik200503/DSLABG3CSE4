#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* findNthFromEnd(Node* head, int n) {
    if (head == NULL)
        return NULL;

    Node* main = head;
    Node* ref = head;

    int count = 0;
    while (count < n) {
        if (ref == NULL)
            return NULL;
        ref = ref->next;
        count++;
    }

    while (ref != NULL) {
        main = main->next;
        ref = ref->next;
    }

    return main;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2;
    Node* nthNode = findNthFromEnd(head, n);
    if (nthNode != NULL)
        printf("The %dth node from the end is %d\n", n, nthNode->data);
    else
        printf("Invalid input\n");

    return 0;
}