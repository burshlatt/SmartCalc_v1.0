#include "s21_calculator.h"

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
    if (string[*i] == 'P') {
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

double polish_notation(char *string, int is_graph, double xValue, int *error_flag) {
    struct Stack *stack = create_stack(SIZE);
    int index = 0;
    double result = 0.0;
    int count_of_left_bracket = 0;
    int count_of_right_bracket = 0;
    char output[255] = {'\0'};
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') {
            count_of_left_bracket++;
        }
        if (string[i] == ')') {
            count_of_right_bracket++;
        }
    }
    for (int i = 0; i < (int)strlen(string) + 1 && index < 255; i++) {
        set_nums_output(string, &i, output, &index);
        if (*error_flag == 0) {
            switch (string[i]) {
                case '^':
                case 'c':
                case 's':
                case 't':
                case 'a':
                case 'l':
                case 'm':
                case '(':
                    push_func(stack, string, &i);
                    break;
                case '*':
                    do_pop(stack, output, &index, 5);
                    push(stack, '*');
                    break;
                case '/':
                    do_pop(stack, output, &index, 5);
                    push(stack, '/');
                    break;
                case '+':
                    do_pop(stack, output, &index, 1);
                    push(stack, '+');
                    break;
                case '-':
                    if (string[i - 1] != '(') {
                        do_pop(stack, output, &index, 1);
                        push(stack, '-');
                    }
                    break;
                case ')':
                    *error_flag = do_pop(stack, output, &index, 3);
                    if (*error_flag == 0) {
                        pop(stack);
                        do_pop(stack, output, &index, 4);
                    }
                    break;
                case '\0':
                    do_pop(stack, output, &index, 2);
                    break;
            }
        }
    }
    delete_stack(stack);
    if (count_of_left_bracket != count_of_right_bracket) {
        *error_flag = 1;
    }
    if (!(*error_flag)) {
        result = arithmetic_calculations(output, is_graph, xValue, error_flag);
    }
    return !(*error_flag) ? result : 0;
}

double arithmetic_calculations(char *output, int is_graph, double xValue, int *error_flag) {
    char *trash;
    int top = -1;
    int n_num = 0;
    double x = 0.0;
    double y = 0.0;
    double num = 0.0;
    double num_buffer[SIZE];
    for (int i = 0; output[i]; i++) {
        while (output[i] == '-' && (output[i + 1] == '-' || isdigit(output[i + 1]))) {
            n_num++;
            i++;
        }
        if (isdigit(output[i]) || output[i] == '.' || output[i] == 'x') {
            num = strtod(&output[i], &trash);
            if (output[i] == 'x') {
                num = xValue;
            }
            if (trash[0] == '-') {
                n_num++;
                if (n_num % 2 != 0) {
                    num = -num;
                }
                n_num = 0;
            }
            i = trash - output;
            set_num(num_buffer, &top, num);
        } else {
            switch (output[i]) {
                case '+':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    set_num(num_buffer, &top, y + x);
                    break;
                case '-':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    set_num(num_buffer, &top, y - x);
                    break;
                case '*':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    set_num(num_buffer, &top, y * x);
                    break;
                case '/':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    if (x == 0.0) {
                        *error_flag = 2;
                    }
                    set_num(num_buffer, &top, y / x);
                    break;
                case '^':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    set_num(num_buffer, &top, pow(y, x));
                    break;
                case 'm':
                    *error_flag = get_nums_func(num_buffer, &top, &x, &y);
                    set_num(num_buffer, &top, fmod(y, x));
                    break;
                case 'c':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, cos(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, cos(x));
                    }
                    break;
                case 's':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, sin(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, sin(x));
                    }
                    break;
                case 't':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, tan(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, tan(x));
                    }
                    break;
                case 'C':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, acos(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, acos(x));
                    }
                    break;
                case 'S':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, asin(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, asin(x));
                    }
                    break;
                case 'T':
                    x = get_num(num_buffer, &top);
                    if (!is_graph) {
                        set_num(num_buffer, &top, atan(x * M_PI / 180));
                    } else {
                        set_num(num_buffer, &top, atan(x));
                    }
                    break;
                case '~':
                    x = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, sqrt(x));
                    break;
                case '|':
                    x = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, fabs(x));
                    break;
                case 'l':
                    x = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, log(x));
                    break;
                case 'L':
                    x = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, log10(x));
                    break;
            }
        }
    }
    return get_num(num_buffer, &top);
}
