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

char *current_date() {
    // int hours, minutes, seconds;
    char *date = malloc(10 * sizeof(char));
    int day, month, year;
    time_t now;
    time(&now); 
    struct tm *local = localtime(&now);
    // hours = local->tm_hour;
    // minutes = local->tm_min;
    // seconds = local->tm_sec;
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
        if (date_arr[0] > days[date_arr[1] - 1]) {
            date_arr[0] = 1;
            date_arr[1] += 1;
        }
        if (date_arr[1] > 12) {
            date_arr[1] = 1;
            date_arr[2] += 1;
        }
    }
    sprintf(date_result, "%02d/%02d/%d", date_arr[0], date_arr[1], date_arr[2]);
    return date_result;
}

int date_difference(char *date_first, char *date_second) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int date_differ[3];
    int first_array[3] = {0, 0, 0};
    char *trash_1;
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (isdigit(date_first[i])) {
            first_array[j] = strtod(&date_first[i], &trash_1);
            i = trash_1 - date_first;
            j++;
        }
    }
    int second_array[3] = {0, 0, 0};
    char *trash_2;
    int k = 0;
    for (int i = 0; i < 10; i++) {
        if (isdigit(date_second[i])) {
            second_array[k] = strtod(&date_second[i], &trash_2);
            i = trash_2 - date_second;
            k++;
        }
    }
    int result_days = days[second_array[1] - 1] - second_array[0] + first_array[0];
    date_differ[0] = first_array[0] - second_array[0];
    date_differ[1] = first_array[1] - second_array[1];
    date_differ[2] = first_array[2] - second_array[2];
    if (date_differ[1] <= 0) {
        date_differ[2] -= 1;
        date_differ[1] = 12 + date_differ[1];
    }
    if (date_differ[0] <= 0) {
        date_differ[1] -= 1;
        date_differ[0] = result_days;
    }
    printf("%d\n", date_differ[0]);
    printf("%d\n", date_differ[1]);
    printf("%d\n", date_differ[2]);
    return 0;
}

void free_array(char *date) {
    free(date);
}

// int main() {
//     date_difference("5/09/2027", "13/12/2015");
//     return 0;
// }
