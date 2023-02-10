#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void polish_notation(char *string);
void push_func(struct Stack *stack, char *string, int *index);

double arithmetic_calculations(char *output);

struct Stack *createStack(int capacity);
int is_empty(struct Stack *stack);
int size(struct Stack *stack);
void delete_stack(struct Stack *stack);
void resize_stack(struct Stack *stack);
void push(struct Stack *stack, char item);
char peek(struct Stack *stack);
char pop(struct Stack *stack);

#endif // SRC_S21_SMARTCALC_H_
