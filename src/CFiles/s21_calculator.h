#ifndef SRC_SMARTCALC_CALCULATOR_H_
#define SRC_SMARTCALC_CALCULATOR_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY 0
#define MONTH 1
#define YEAR 2

#define LN 1
#define LOG 2
#define COS 3
#define SIN 4
#define TAN 5
#define POW 6
#define MOD 7
#define ACOS 8
#define ASIN 9
#define ATAN 10
#define SQRT 11

#define SIZE 255

struct Stack {
  int top;
  int capacity;
  char *data;
};

struct Stack *create_stack(int capacity);

char *current_date();
char pop(struct Stack *stack);
char peek(struct Stack *stack);
char *end_date(char *date, int time_contrib, int type_of_time);

int size(struct Stack *stack);
int is_empty(struct Stack *stack);
int days_in_month(int month, int year);
int set_num(double *stack, int *top, double num);
int date_difference(char *date_first, char *date_second);
int convert_to_months(int time_contrib, int type_of_time);
int check_period(int capitalization, int period, double *time_copy);
int get_nums_func(double *num_buffer, int *top, double *x, double *y);
int do_pop(struct Stack *stack, char *output, int *index, int variant);

double get_num(double *stack, int *top);
double add_start_sum(double sum, int time, int type);
double convert_to_days(int time_contrib, int type_of_time);
double polish_notation(char *string, int is_graph, double xValue,
                       int *error_flag);
double arithmetic_calculations(char *output, int is_graph, double xValue,
                               int *error_flag);
double annuity_credit(double sum, int term, int type_of_term, double percent,
                      double *month_pay, double *over_pay);
double differentiated_credit(double sum, int term, int type_of_term,
                             double percent, double *first_payment,
                             double *last_payment, double *over_pay);

void free_array(char *date);
void delete_stack(struct Stack *stack);
void set_space(char *output, int *index);
void push(struct Stack *stack, char item);
void do_correct_date(char *date_first, char *date_second);
void push_func(struct Stack *stack, char *string, int *index);
void logic_actions(struct Stack *stack, char *output, int *index);
void set_in_output(struct Stack *stack, char *output, int *index);
void set_nums_output(char *string, int *i, char *output, int *index);
void deposit_calculator(double sum, int time_contrib, int type_of_time,
                        double percent, double tax_rate, int period,
                        int capitalization, double *res_percent,
                        double *tax_rate_res, double *sum_with_tax,
                        double *sum_res);

#endif // SRC_SMARTCALC_CALCULATOR_H_
