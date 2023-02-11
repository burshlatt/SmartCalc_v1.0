#include "calculator.h"

struct Stack *create_stack(int capacity) {
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

void push(struct Stack *stack, char item) {
    stack->data[++stack->top] = item;
}

char peek(struct Stack *stack) {
    return stack->data[stack->top];
}

char pop(struct Stack *stack) {
    char return_value = '\0';
    return_value = stack->data[stack->top--];
    return return_value;
}

void delete_stack(struct Stack *stack) {
    if (stack) {
        if (stack->data) {
            free(stack->data);
        }
        free(stack);
    }
}

void set_num(double *stack, int *top, double num) {
    if (*top != SIZE - 1) {
        stack[++(*top)] = num;
    }
}

double get_num(double *stack, int *top) {
    double result = 0.0;
    if (*top != -1) {
        result = stack[(*top)--];
    }
    return result;
}

void set_nums_output(char *string, int *i, char *output, int *index) {
    if ((string[*i] == '-' && string[*i - 1] <= '(')) {
        *i += 1;
    }
    if ((string[*i] < '0' || string[*i] > '9')) {
        if (string[*i] != '(' && string[*i] != ')') {
            if (string[*i] != '.' && output[*index - 1] != ' ') {
                output[*index] = ' ';
                *index += 1;
            }
        }
    }
    if ((string[*i] >= '0' && string[*i] <= '9') || string[*i] == '.') {
        output[*index] = string[*i];
        *index += 1;
        if (string[*i - 1] == '-' && string[*i - 2] == '(') {
            output[*index] = '-';
            *index += 1;
        }
    }
}

int is_func(struct Stack *stack) {
    int func = 0;
    if (peek(stack) == 'c') {
        func = COS;
    } else if (peek(stack) == 's') {
        func = SIN;
    } else if (peek(stack) == 't') {
        func = TAN;
    } else if (peek(stack) == 'C') {
        func = ACOS;
    } else if (peek(stack) == 'S') {
        func = ASIN;
    } else if (peek(stack) == 'T') {
        func = ATAN;
    } else if (peek(stack) == '^') {
        func = POW;
    } else if (peek(stack) == 'm') {
        func = MOD;
    } else if (peek(stack) == '~') {
        func = SQRT;
    } else if (peek(stack) == 'L') {
        func = LOG;
    } else if (peek(stack) == 'l') {
        func = LN;
    }
    return func;
}

void push_func(struct Stack *stack, char *string, int *index) {
    if (string[*index] == 'c') {
        push(stack, 'c');
        *index += 3;
    } else if (string[*index] == 's') {
        if (string[*index + 1] == 'q') {
            push(stack, '~');
            *index += 4;
        } else {
            push(stack, 's');
            *index += 3;
        }
    } else if (string[*index] == 't') {
        push(stack, 't');
        *index += 3;
    } else if (string[*index] == 'a') {
        if (string[*index + 1] == 'c') {
            push(stack, 'C');
        } else if (string[*index + 1] == 's') {
            push(stack, 'S');
        } else if (string[*index + 1] == 't') {
            push(stack, 'T');
        }
        *index += 4;
    } else if (string[*index] == 'l') {
        if (string[*index + 1] == 'n') {
            push(stack, 'l');
            *index += 2;
        } else {
            push(stack, 'L');
            *index += 3;
        }
    } else if (string[*index] == 'm') {
        push(stack, 'm');
    } else if (string[*index] == '^') {
        push(stack, '^');
    }
    if (string[*index] == '(') {
        push(stack, '(');
    }
}

void set_space(char *output, int *index) {
    if (output[*index - 1] != ' ') {
        output[*index] = ' ';
        *index += 1;
    }
}

void set_in_output(struct Stack *stack, char *output, int *index) {
    output[*index] = pop(stack);
    *index += 1;
}

void do_pop(struct Stack *stack, char *output, int *index, int variant) {
    if (variant == 1) {
        while (!is_empty(stack) && peek(stack) != '(') {
            set_space(output, index);
            set_in_output(stack, output, index);
            set_space(output, index);
        }
    } else if (variant == 2) {
        while (!is_empty(stack) && peek(stack) != '-' && peek(stack) != '+' && peek(stack) != '(') {
            set_space(output, index);
            set_in_output(stack, output, index);
            set_space(output, index);
        }
    } else if (variant == 3) {
        while (peek(stack) != '(') {
            set_space(output, index);
            set_in_output(stack, output, index);
            set_space(output, index);
        }
    } else if (variant == 4) {
        while (is_func(stack)) {
            set_space(output, index);
            set_in_output(stack, output, index);
            set_space(output, index);
        }
    } else if (variant == 5) {
        while (!is_empty(stack)) {
            set_space(output, index);
            set_in_output(stack, output, index);
        }
    }
}