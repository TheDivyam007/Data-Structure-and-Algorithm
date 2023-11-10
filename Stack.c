//main file
#include "stack.h"
int main() {
    struct Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    // Check if the stack is empty
    printf("Is the stack empty? %s\n", is_empty(&stack) ? "Yes" : "No");

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
}

//stack.h file
#define MAX_SIZE 100
// Define the stack data structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};
// Function to initialize the stack
void initialize(struct Stack *stack);
// Function to check if the stack is empty
int is_empty(struct Stack *stack);
// Function to check if the stack is full
int is_full(struct Stack *stack);
// Function to push an element onto the stack
void push(struct Stack *stack, int item);
// Function to pop an element from the stack
int pop(struct Stack *stack);

//stack.c file
#include "stack.h"
#include <stdio.h>
// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}
// Function to check if the stack is empty
int is_empty(struct Stack *stack) {
    return stack->top == -1;
}
// Function to check if the stack is full
int is_full(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = item;
    }
}
// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    } else {
        return -1; // Return -1 as an error indicator
    }
}