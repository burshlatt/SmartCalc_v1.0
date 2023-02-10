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
    if (is_empty(stack)) {
        return -1;
    }
    return stack->data[stack->top--];
}

void is_func(struct Stack *stack, char *string, int *index) {
    if (string[*index] == 'c') {
        if (string[*index + 1] == 'o') {
            if (string[*index + 2] == 's') {
                if (string[*index + 3] == '(') {
                    push(stack, 'c');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == 's') {
        if (string[*index + 1] == 'i') {
            if (string[*index + 2] == 'n') {
                if (string[*index + 3] == '(') {
                    push(stack, 's');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == 't') {
        if (string[*index + 1] == 'a') {
            if (string[*index + 2] == 'n') {
                if (string[*index + 3] == '(') {
                    push(stack, 't');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == 'a') {
        if (string[*index + 1] == 'c') {
            if (string[*index + 2] == 'o') {
                if (string[*index + 3] == 's') {
                    if (string[*index + 4] == '(') {
                        push(stack, 'a');
                        // *index += 4;
                    }
                }
            }
        }
    }
    if (string[*index] == 'a') {
        if (string[*index + 1] == 's') {
            if (string[*index + 2] == 'i') {
                if (string[*index + 3] == 'n') {
                    if (string[*index + 4] == '(') {
                        push(stack, 'a');
                        // *index += 4;
                    }
                }
            }
        }
    }
    if (string[*index] == 'a') {
        if (string[*index + 1] == 't') {
            if (string[*index + 2] == 'a') {
                if (string[*index + 3] == 'n') {
                    if (string[*index + 4] == '(') {
                        push(stack, 'a');
                        // *index += 4;
                    }
                }
            }
        }
    }
    if (string[*index] == 's') {
        if (string[*index + 1] == 'q') {
            if (string[*index + 2] == 'r') {
                if (string[*index + 3] == 't') {
                    if (string[*index + 4] == '(') {
                        push(stack, '~');
                        // *index += 4;
                    }
                }
            }
        }
    }
    if (string[*index] == 'l') {
        if (string[*index + 1] == 'n') {
            if (string[*index + 2] == '(') {
                push(stack, 'l');
                // *index += 2;
            }
        }
    }
    if (string[*index] == 'l') {
        if (string[*index + 1] == 'o') {
            if (string[*index + 2] == 'g') {
                if (string[*index + 3] == '(') {
                    push(stack, '!');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == 'p') {
        if (string[*index + 1] == 'o') {
            if (string[*index + 2] == 'w') {
                if (string[*index + 3] == '(') {
                    push(stack, 'p');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == 'm') {
        if (string[*index + 1] == 'o') {
            if (string[*index + 2] == 'd') {
                if (string[*index + 3] == '(') {
                    push(stack, 'm');
                    // *index += 3;
                }
            }
        }
    }
    if (string[*index] == '(') {
        push(stack, '(');
    }
}

double polish_notation(char *string) {
    struct Stack *stack = createStack(2);
    int index = 0;
    double result = 0.0;
    char output[255] = {'\0'};
    for (int i = 0; i < strlen(string) + 1; i++) {
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
            case 'c':
            case 's':
            case 't':
            case 'a':
            case 'l':
            case 'p':
            case 'm':
            case '(':
                is_func(stack, string, &i);
                break;
            case ',':
                while (peek(stack) != '(') {
                    output[index] = pop(stack);
                    index++;
                }
                break;
            case '*':
                while (peek(stack) != '-' || peek(stack) != '+') {
                    output[index] = pop(stack);
                    index++;
                }
                push(stack, '*');
                break;
            case '/':
                while (peek(stack) != '-' || peek(stack) != '+') {
                    output[index] = pop(stack);
                    index++;
                }
                push(stack, '/');
                break;
            case '+':
                push(stack, '+');
                break;
            case '-':
                push(stack, '-');
                break;
            case ')':
                while (peek(stack) != '(') {
                    output[index] = pop(stack);
                    index++;
                }
                pop(stack);
                while (peek(stack) == 'c' || peek(stack) == 's' || peek(stack) == 't' || peek(stack) == 'a' || peek(stack) == 'p' || peek(stack) == 'm' || peek(stack) == '~' || peek(stack) == '!' || peek(stack) == 'l') {
                    output[index] = pop(stack);
                    index++;
                }
                break;
            case '\0':
                while (!is_empty(stack)) {
                    output[index] = pop(stack);
                    index++;
                }
                break;
        }
    }
    printf("Result - %s\n", output);
    delete_stack(stack);
    return result;
}

int main() {
    polish_notation("2+(3-4)+3-7+pow(10, 2)");
    return 0;
}
