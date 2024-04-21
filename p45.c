#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int top;
} Stack;

void initStack(Stack *s, int size) {
    s->stack = (int*)malloc(size * sizeof(int));
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int item) {
    s->top++;
    s->stack[s->top] = item;
}

int pop(Stack *s) {
    int item = s->stack[s->top];
    s->top--;
    return item;
}

int* nextGreater(int *nums, int numsSize) {
    Stack stack;
    initStack(&stack, numsSize);
    int *result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        while (!isEmpty(&stack) && nums[i] > nums[stack.stack[stack.top]]) {
            result[stack.stack[stack.top]] = nums[i];
            pop(&stack);
        }
        push(&stack, i);
    }

    return result;
}

int main() {
    int nums[] = {4, 5, 2, 10};
    int *result = nextGreater(nums, sizeof(nums) / sizeof(nums[0]));

    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
