#ifndef SRC_SMARTCALC_CALCULATOR_H_
#define SRC_SMARTCALC_CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

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
void push_func(struct Stack *stack, char *string, int *index);
void logic_actions(struct Stack *stack, char *output, int *index);
void set_in_output(struct Stack *stack, char *output, int *index);
void set_nums_output(char *string, int *i, char *output, int *index);

double get_num(double *stack, int *top);
double polish_notation(char *string, int is_graph, double xValue, int *error_flag);
double arithmetic_calculations(char *output, int is_graph, double xValue, int *error_flag);

char pop(struct Stack *stack);
char peek(struct Stack *stack);

int size(struct Stack *stack);
int is_empty(struct Stack *stack);
int set_num(double *stack, int *top, double num);
int get_nums_func(double *num_buffer, int *top, double *x, double *y);
int do_pop(struct Stack *stack, char *output, int *index, int variant);

double annuity_credit(double sum, int term, int type_of_term, double percent, double *month_pay, double *over_pay);
double differentiated_credit(double sum, int term, int type_of_term, double percent, double *first_payment, double *last_payment, double *over_pay);

double convert_to_days(int time_contrib, int type_of_time);
int check_period(int capitalization, int period, double *time_copy);
void is_capitalization(int n, double sum, double percent, double tax_rate, double time_copy, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res);
void is_not_capitalization(int n, double sum, double percent, double tax_rate, double time_copy, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res);
void deposit_calculator(double sum, int time_contrib, int type_of_time, double percent, double tax_rate, int period, int capitalization, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res);

#endif // SRC_SMARTCALC_CALCULATOR_H_
