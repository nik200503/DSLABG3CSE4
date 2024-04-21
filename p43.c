#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return (s->top == NULL);
}

void push(Stack *s, int item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        Node *temp = s->top;
        int item = temp->data;
        s->top = s->top->next;
        free(temp);
        return item;
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->top->data;
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack)); 
    printf("%d\n", peek(&stack));

    return 0;
}
