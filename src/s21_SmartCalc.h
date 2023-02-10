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

struct Stack {
    int top;
    int capacity;
    char *data;
};

double polish_notation(char *string);
void is_func(struct Stack *stack, char *string, int *index);

#endif // SRC_S21_SMARTCALC_H_
