#include "calculator.h"

double polish_notation(char *string, int is_graph, double xValue) {
    struct Stack *stack = create_stack(SIZE);
    int index = 0;
    char output[255] = {'\0'};
    for (int i = 0; i < (int)strlen(string) + 1 && index < 255; i++) {
        set_nums_output(string, &i, output, &index);
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
                do_pop(stack, output, &index, 3);
                pop(stack);
                do_pop(stack, output, &index, 4);
                break;
            case '\0':
                do_pop(stack, output, &index, 2);
                break;
        }
    }
    delete_stack(stack);
    return arithmetic_calculations(output, is_graph, xValue);
}

double arithmetic_calculations(char *output, int is_graph, double xValue) {
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
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, y + x);
                    break;
                case '-':
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, y - x);
                    break;
                case '*':
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, y * x);
                    break;
                case '/':
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, y / x);
                    break;
                case '^':
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
                    set_num(num_buffer, &top, pow(y, x));
                    break;
                case 'm':
                    x = get_num(num_buffer, &top);
                    y = get_num(num_buffer, &top);
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
