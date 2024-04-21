#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *stack;
    int top;
} Stack;

void initStack(Stack *s, int size) {
    s->stack = (char*)malloc(size * sizeof(char));
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char item) {
    s->top++;
    s->stack[s->top] = item;
}

char pop(Stack *s) {
    char item = s->stack[s->top];
    s->top--;
    return item;
}

int isValid(char *s) {
    Stack stack;
    initStack(&stack, strlen(s));

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((s[i] == ')' && top != '(') ||
                (s[i] == ']' && top != '[') ||
                (s[i] == '}' && top != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    printf("%d\n", isValid("(){}[]")); 
    printf("%d\n", isValid("([)]"));    

    return 0;
}
