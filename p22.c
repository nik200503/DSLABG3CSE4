#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* detectAndRemoveCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return head;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL;

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
    head->next->next->next->next->next = head->next->next;

    Node* result = detectAndRemoveCycle(head);

    printf("Linked list after cycle removal: ");
    Node* temp = result;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}