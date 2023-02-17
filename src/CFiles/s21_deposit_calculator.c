#include "s21_calculator.h"

void deposit_calculator(double sum, int time_contrib, int type_of_time, double percent, double tax_rate, int period, int capitalization, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res) {
    double time_copy = convert_to_days(time_contrib, type_of_time);
    int n = check_period(capitalization, period, &time_copy);
    if (!capitalization) {
        is_not_capitalization(n, sum, percent, tax_rate, time_copy, res_percent, tax_rate_res, sum_with_tax, sum_res);
    } else {
        is_capitalization(n, sum, percent, tax_rate, time_copy, res_percent, tax_rate_res, sum_with_tax, sum_res);
    }
}

int convert_to_months(int time_contrib, int type_of_time) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int month = local->tm_mon;
    double time_copy = 0;
    if (type_of_time == 1) {
        for (int i = 0; time_contrib >= days[month]; i++) {
            time_contrib -= days[month];
            if (month == 11) {
                month = 0;
            } else {
                month++;
            }
            time_copy++;
        }
    } else if (type_of_time == 2) {
        time_copy = time_contrib;
    } else if (type_of_time == 3) {
        time_copy = time_contrib * 12;
    }
    return time_copy;
}

double add_start_sum(double sum, int time, int type) {
    double sum_result = 0.0;
    if (type == 2) {
        time = (int)(time / 2);
    } else if (type == 3) {
        time = (int)(time / 3);
    } else if (type == 4) {
        time = (int)(time / 6);
    } else if (type == 5) {
        time = (int)(time / 12);
    }
    for (int i = 0; i < time; i++) {
        sum_result += sum;
    }
    return sum_result;
}

double convert_to_days(int time_contrib, int type_of_time) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int month = local->tm_mon;
    double time_copy = 0;
    if (type_of_time == 1) {
        time_copy = time_contrib;
    } else if (type_of_time == 3) {
        time_contrib *= 12;
    }
    if (type_of_time != 1) {
        for (int i = 0; i < time_contrib; i++) {
            time_copy += days[month];
            if (month == 11) {
                month = 0;
            } else {
                month++;
            }
        }
    }
    return time_copy;
}

int check_period(int capitalization, int period, double *time_copy) {
    int n = 0;
    if (!capitalization) {
        if (period == 1 || period == 7) {
            n = 365;
        } else if (period == 2) {
            n = 52;
            *time_copy = floor(*time_copy / 7);
        } else if (period == 3) {
            n = 12;
            *time_copy = floor(*time_copy / 30.5);
        } else if (period == 4) {
            n = 4;
            *time_copy = floor(*time_copy / 91.25);
        } else if (period == 5) {
            n = 2;
            *time_copy = floor(*time_copy / 182.5);
        } else if (period == 6) {
            n = 1;
            *time_copy = floor(*time_copy / 365);
        }
    } else {
        if (period == 1) {
            n = 365;
        } else if (period == 2) {
            n = 52;
        } else if (period == 3) {
            n = 12;
        } else if (period == 4) {
            n = 4;
        } else if (period == 5) {
            n = 2;
        } else if (period == 6 || period == 7) {
            n = 1;
        }
    }
    return n;
}

void is_not_capitalization(int n, double sum, double percent, double tax_rate, double time_copy, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res) {
    *res_percent = (percent / 100) * sum * (time_copy / n);
    *tax_rate_res = *res_percent - 1000000 * (7.5 / 100);
    if (*tax_rate_res > 0) {
        *tax_rate_res *= tax_rate / 100;
    } else {
        *tax_rate_res = 0;
    }
    *sum_with_tax = *res_percent - *tax_rate_res;
    *sum_res = sum;
}

void is_capitalization(int n, double sum, double percent, double tax_rate, double time_copy, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res) {
    *sum_res = sum * pow(1 + (percent / 100) / n, time_copy / 365 * n);
    *res_percent = *sum_res - sum;
    *tax_rate_res = *res_percent - 1000000 * (7.5 / 100);
    if (*tax_rate_res > 0) {
        *tax_rate_res *= tax_rate / 100;
    } else {
        *tax_rate_res = 0;
    }
    *sum_with_tax = *res_percent - *tax_rate_res;
}
