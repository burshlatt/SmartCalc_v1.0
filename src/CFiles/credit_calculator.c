#include "calculator.h"

double annuity_credit(double sum, int term, int type_of_term, double percent, double *month_pay, double *over_pay) {
    int result_time = 0;
    if (type_of_term == 1) {
        result_time = term;
    } else {
        result_time = term * 12;
    }
    double percent_month = percent / (100 * percent);
    *month_pay = sum * percent_month / (1 - pow(1 + percent_month, -result_time));
    *over_pay = *month_pay * result_time - sum;
    double all_sum = sum + *over_pay;
    return all_sum;
}

double differentiated_credit(double sum, int term, int type_of_term, double percent, double *first_payment, double *last_payment, double *over_pay) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int month = local->tm_mon;
    int result_time = 0;
    if (type_of_term == 1) {
        result_time = term;
    } else {
        result_time = term * 12;
    }
    double credit_body = sum / result_time;
    *over_pay = (sum * (percent / 100) * days[month]) / 365;
    *first_payment = *over_pay + credit_body;
    double sum_copy = sum;
    double percent_month = 0.0;
    for (int i = 0; i < result_time - 1; i++) {
        sum_copy -= credit_body;
        if (month == 11) {
            month = 0;
        } else {
            month++;
        }
        percent_month = (sum_copy * (percent / 100) * days[month]) / 365;
        *over_pay += percent_month;
        *last_payment = percent_month + credit_body;
    }
    double all_sum = sum + *over_pay;
    return all_sum;
}

int main() {
    double first_payment = 0.0;
    double last_payment = 0.0;
    double over_pay = 0.0;
    double result = differentiated_credit(120000, 1, 2, 15, &first_payment, &last_payment, &over_pay);
    printf("Первый взнос: %lf\n", first_payment);
    printf("Последний взнос: %lf\n", last_payment);
    printf("Переплата: %lf\n", over_pay);
    printf("Результат: %lf\n", result);
    return 0;
}