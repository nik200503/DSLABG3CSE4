#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* findMergeNode(Node* head1, Node* head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;

    while (curr1 != curr2) {
        curr1 = (curr1 == NULL) ? head2 : curr1->next;
        curr2 = (curr2 == NULL) ? head1 : curr2->next;
    }

    return curr1;
}

int main() {
    Node* head1 = (Node*)malloc(sizeof(Node));
    head1->data = 1;
    head1->next = (Node*)malloc(sizeof(Node));
    head1->next->data = 3;
    head1->next->next = (Node*)malloc(sizeof(Node));
    head1->next->next->data = 5;
    head1->next->next->next = (Node*)malloc(sizeof(Node));
    head1->next->next->next->data = 7;
    head1->next->next->next->next = NULL;

    Node* head2 = (Node*)malloc(sizeof(Node));
    head2->data = 2;
    head2->next = (Node*)malloc(sizeof(Node));
    head2->next->data = 4;
    head2->next->next = head1->next->next;

    Node* mergeNode = findMergeNode(head1, head2);
    printf("Merge node data: %d\n", mergeNode->data);

    return 0;
}