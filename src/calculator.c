#include "s21_SmartCalc.h"

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

void do_space() {

}

void polish_notation(char *string) {
    struct Stack *stack = createStack(2);
    int index = 0;
    char output[255] = {'\0'};
    for (int i = 0; i < (int)strlen(string) + 1 && index < 255; i++) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != '(' && string[i] != ')' && output[index - 1] != ' ') {
            output[index] = ' ';
            index++;
        }
        switch (string[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                output[index] = string[i];
                index++;
                break;
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
                while (peek(stack) != '-' || peek(stack) != '+') {
                    output[index] = ' ';
                    index++;
                    output[index] = pop(stack);
                    index++;
                }
                push(stack, '*');
                break;
            case '/':
                while (peek(stack) != '-' || peek(stack) != '+') {
                    output[index] = ' ';
                    index++;
                    output[index] = pop(stack);
                    index++;
                }
                push(stack, '/');
                break;
            case '+':
                while (!is_empty(stack) && peek(stack) != '(') {
                    if (output[index - 1] != ' ') {
                        output[index] = ' ';
                        index++;
                    }
                    output[index] = pop(stack);
                    index++;
                    output[index] = ' ';
                    index++;
                }
                push(stack, '+');
                break;
            case '-':
                while (!is_empty(stack) && peek(stack) != '(') {
                    if (output[index - 1] != ' ') {
                        output[index] = ' ';
                        index++;
                    }
                    output[index] = pop(stack);
                    index++;
                    output[index] = ' ';
                    index++;
                }
                push(stack, '-');
                break;
            case ')':
                while (peek(stack) != '(') {
                    output[index] = ' ';
                    index++;
                    output[index] = pop(stack);
                    index++;
                }
                pop(stack);
                while (is_func(stack)) {
                    output[index] = ' ';
                    index++;
                    output[index] = pop(stack);
                    index++;
                }
                break;
            case '\0':
                while (!is_empty(stack)) {
                    if (output[index - 1] != ' ') {
                        output[index] = ' ';
                        index++;
                    }
                    output[index] = pop(stack);
                    index++;
                }
                break;
        }
    }
    arithmetic_calculations(output);
    delete_stack(stack);
}

double arithmetic_calculations(char *output) {
    double result = 0.0;
    printf("Result: %s\n", output);
    // for (int i = 0; i < (int)strlen(output); i++) {
    //     if (output[i] == '') {

    //     }
    // }
    return result;
}
