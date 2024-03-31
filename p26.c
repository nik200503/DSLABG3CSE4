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

Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node* dummy = createNode(0);
    Node* tail = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
        tail->next = head1;
    if (head2 != NULL)
        tail->next = head2;

    return dummy->next;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    Node* mergedHead = mergeSortedLists(head1, head2);
    displayList(mergedHead);

    return 0;
}