#include "s21_SmartCalc.h"

struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int is_empty(struct Stack *stack) {
    return stack->top == -1;
}

int size(struct Stack *stack) {
    return stack->top + 1;
}

void delete_stack(struct Stack *stack) {
    if (stack) {
        if (stack->data) {
            free(stack->data);
        }
        free(stack);
    }
}

void resize_stack(struct Stack *stack) {
    int newCapacity = stack->capacity * 2;
    char *newdata = (char*)realloc(stack->data, newCapacity * sizeof(char));
    if (newdata) {
        stack->data = newdata;
        stack->capacity = newCapacity;
    }
}

void push(struct Stack *stack, char item) {
    if (size(stack) == stack->capacity) {
        resize_stack(stack);
    }
    stack->data[++stack->top] = item;
}

char peek(struct Stack *stack) {
    if (is_empty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

char pop(struct Stack *stack) {
    char return_value = '\0';
    if (is_empty(stack)) {
        return_value = 'q';
    } else {
        return_value = stack->data[stack->top--];
    }
    return return_value;
}
