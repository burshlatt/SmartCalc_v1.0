#ifndef SRC_S21_CALCULATOR_H_
#define SRC_S21_CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 255

#define COS 1
#define SIN 2
#define TAN 3
#define ACOS 4
#define ASIN 5
#define ATAN 6
#define SQRT 7
#define LN 8
#define LOG 9
#define POW 10
#define MOD 11

struct Stack {
    int top;
    int capacity;
    char *data;
};

struct Stack *create_stack(int capacity);

void delete_stack(struct Stack *stack);
void set_space(char *output, int *index);
void push(struct Stack *stack, char item);
void set_num(double *stack, int *top, double num);
void push_func(struct Stack *stack, char *string, int *index);
void set_in_output(struct Stack *stack, char *output, int *index);
void set_nums_output(char *string, int *i, char *output, int *index);
void do_pop(struct Stack *stack, char *output, int *index, int variant);

double polish_notation(char *string);
double get_num(double *stack, int *top);
double arithmetic_calculations(char *output);

char pop(struct Stack *stack);
char peek(struct Stack *stack);

int size(struct Stack *stack);
int is_empty(struct Stack *stack);

#endif // SRC_S21_CALCULATOR_H_
