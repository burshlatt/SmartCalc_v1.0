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

int set_num(double *stack, int *top, double num) {
    int error_status = 0;
    if (*top != SIZE - 1) {
        stack[++(*top)] = num;
    }
    return error_status;
}

double get_num(double *stack, int *top) {
    double result = 0.0;
    if (*top != -1) {
        result = stack[(*top)--];
    } else {
        result = NAN;
    }
    return result;
}

int get_nums_func(double *num_buffer, int *top, double *x, double *y) {
    int error_status = 0;
    *x = get_num(num_buffer, top);
    *y = get_num(num_buffer, top);
    if (*x == NAN || *y == NAN) {
        error_status = 1;
    }
    return error_status;
}

void set_nums_output(char *string, int *i, char *output, int *index) {
    int is_negative = 0;
    char pi_chars[] = "3.141592";
    if ((string[*i] == '-' && string[*i - 1] <= '(')) {
        *i += 1;
        is_negative = 1;
    }
    while ((string[*i] >= '0' && string[*i] <= '9') || string[*i] == '.' || string[*i] == 'x') {
        output[*index] = string[*i];
        *index += 1;
        *i += 1;
    }
    if (string[*i] >= 'P') {
        for (int k = 0; k < 8; k++) {
            output[*index] = pi_chars[k];
            *index += 1;
        }
        *i += 2;
    }
    if (is_negative) {
        output[*index] = '-';
        *index += 1;
    }
    if ((string[*i] < '0' || string[*i] > '9') && string[*i] != 'x') {
        if (string[*i] != '(' && string[*i] != ')') {
            if (string[*i] != '.' && output[*index - 1] != ' ') {
                output[*index] = ' ';
                *index += 1;
            }
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
            *index += 4;
        } else if (string[*index + 1] == 's') {
            push(stack, 'S');
            *index += 4;
        } else if (string[*index + 1] == 't') {
            push(stack, 'T');
            *index += 4;
        } else if (string[*index + 1] == 'b') {
            push(stack, '|');
            *index += 3;
        }
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

void logic_actions(struct Stack *stack, char *output, int *index) {
    set_space(output, index);
    set_in_output(stack, output, index);
    set_space(output, index);
}

int do_pop(struct Stack *stack, char *output, int *index, int variant) {
    int error_status = 0;
    if (variant == 1) {
        while (!is_empty(stack) && peek(stack) != '(') {
            logic_actions(stack, output, index);
        }
    } else if (variant == 2) {
        while (!is_empty(stack)) {
            logic_actions(stack, output, index);
        }
    } else if (variant == 3) {
        while (peek(stack) != '(') {
            if (is_empty(stack)) {
                error_status = 1;
                break;
            }
            logic_actions(stack, output, index);
        }
    } else if (variant == 4) {
        while (is_func(stack)) {
            logic_actions(stack, output, index);
        }
    } else if (variant == 5) {
        while (!is_empty(stack) && peek(stack) != '-' && peek(stack) != '+' && peek(stack) != '(') {
            logic_actions(stack, output, index);
        }
    }
    return error_status;
}
