#include "s21_calculator.h"

void deposit_calculator(double sum, int time_contrib, int type_of_time, double percent, double tax_rate, int period, int capitalization, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res) {
    double time_copy = convert_to_days(time_contrib, type_of_time);
    double time_copy_2 = time_copy;
    int n = check_period(capitalization, period, &time_copy);
    if (!capitalization) {
        *sum_res = sum;
        if (period == 7) {
            *res_percent = sum * (1 + ((percent / 100) * time_copy_2 / n));
        } else {
            *res_percent = (sum * (percent / 100) / n) * time_copy;
        }
    } else {
        *sum_res = sum * pow(1 + (percent / 100) / n, time_copy / 365 * n);
        *res_percent = *sum_res - sum;
    }
    *tax_rate_res = *res_percent - 1000000 * (7.5 / 100);
    if (*tax_rate_res > 0) {
        *tax_rate_res *= tax_rate / 100;
    } else {
        *tax_rate_res = 0;
    }
    *sum_with_tax = *res_percent - *tax_rate_res;
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

char *current_date() {
    char *date = malloc(10 * sizeof(char));
    int day, month, year;
    time_t now;
    time(&now); 
    struct tm *local = localtime(&now);
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
    sprintf(date, "%02d/%02d/%d", day, month, year);
    return date;
}

char *end_date(char *date, int time_contrib, int type_of_time) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count_days = convert_to_days(time_contrib, type_of_time);
    char *date_result = malloc(10 * sizeof(char));
    int date_arr[3] = {0, 0, 0};
    char *trash;
    int j = 0;
    for (int i = 0; date[i]; i++) {
        if (isdigit(date[i])) {
            date_arr[j] = strtod(&date[i], &trash);
            i = trash - date;
            j++;
        }
    }
    for (int i = 0; i < count_days; i++) {
        date_arr[0] += 1;
        if (date_arr[DAY] > days[date_arr[1] - 1]) {
            date_arr[DAY] = 1;
            date_arr[MONTH] += 1;
        }
        if (date_arr[MONTH] > 12) {
            date_arr[MONTH] = 1;
            date_arr[YEAR] += 1;
        }
    }
    sprintf(date_result, "%02d/%02d/%d", date_arr[0], date_arr[1], date_arr[2]);
    return date_result;
}

void do_correct_date(char *date_first, char *date_second) {
    for (int i = 0; i < 10; i++) {
        if (date_first[i] == '.') {
            date_first[i] = '/';
        }
        if (date_second[i] == '.') {
            date_second[i] = '/';
        }
    }
}

int days_in_month(int month, int year) {
    int days[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

int date_difference(char *date_first, char *date_second) {
    do_correct_date(date_first, date_second);
    int first_array[3] = {0, 0, 0};
    int second_array[3] = {0, 0, 0};
    sscanf(date_first, "%d/%d/%d", &first_array[DAY], &first_array[MONTH], &first_array[YEAR]);
    sscanf(date_second, "%d/%d/%d", &second_array[DAY], &second_array[MONTH], &second_array[YEAR]);
    int month_diff = (first_array[YEAR] - second_array[YEAR]) * 12 + first_array[MONTH] - second_array[MONTH];
    int day_diff = first_array[DAY] - second_array[DAY];
    if (day_diff < 0) {
        month_diff--;
        day_diff += days_in_month(second_array[MONTH], second_array[YEAR]);
    }
    return month_diff;
}

void free_array(char *date) {
    free(date);
}
