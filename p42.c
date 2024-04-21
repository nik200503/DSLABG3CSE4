#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int stack[100];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == 100 - 1);
}

void push(Stack *s, int item) {
    if (!isFull(s)) {
        s->top++;
        s->stack[s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        int item = s->stack[s->top];
        s->top--;
        return item;
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top];
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
