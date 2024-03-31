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

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    int isPalindrom = isPalindrome(head);
    printf("Is palindrome? %s\n", isPalindrome ? "Yes" : "No");

    return 0;
}