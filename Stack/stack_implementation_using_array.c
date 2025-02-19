#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

// Create the stack
void create(struct Stack *st) {
    printf("Enter Stack Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
    if (!st->S) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Display stack elements
void display(const struct Stack *st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = st->top; i >= 0; i--)
        printf("%d ", st->S[i]);
    printf("\n");
}

// Push an element onto the stack
void push(struct Stack *st, int x) {
    if (st->top == st->size - 1) {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    st->S[++st->top] = x;
}

// Pop an element from the stack
int pop(struct Stack *st) {
    if (st->top == -1) {
        fprintf(stderr, "Stack Underflow\n");
        return -1;
    }
    return st->S[st->top--];
}

// Peek at a specific position from the top
int peek(const struct Stack *st, int index) {
    int pos = st->top - index + 1;
    if (pos < 0 || pos > st->top) {
        fprintf(stderr, "Invalid Index\n");
        return -1;
    }
    return st->S[pos];
}

// Check if the stack is empty
int isEmpty(const struct Stack *st) {
    return st->top == -1;
}

// Check if the stack is full
int isFull(const struct Stack *st) {
    return st->top == st->size - 1;
}

// Get the top element of the stack
int stackTop(const struct Stack *st) {
    return isEmpty(st) ? -1 : st->S[st->top];
}

// Free allocated memory
void destroy(struct Stack *st) {
    free(st->S);
    st->S = NULL;
    st->size = st->top = 0;
}

int main() {
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("Peek at index 2: %d\n", peek(&st, 2));
    
    display(&st);

    destroy(&st);  // Free allocated memory

    return 0;
}
