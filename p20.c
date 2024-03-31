#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* reverseLL(Node* head, int left, int right) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 1;

    while (count < left) {
        curr = curr->next;
        count++;
    }

    Node* start = curr;

    while (count >= left && count <= right) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    start->next = curr;
    head->next = prev;

    return head;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    int left = 2, right = 4;
    Node* result = reverseLL(head, left, right);

    printf("Reversed linked list: ");
    Node* temp = result;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}