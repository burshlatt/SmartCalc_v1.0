#include "calculator.h"

// int main() {
//     float deposit, interest_rate, tax_rate, total_interest = 0, total_tax = 0, total_deposit;
//     int deposit_period, payment_period, num_deposits = 0, num_withdrawals = 0, i, j;
//     int deposits[100], withdrawals[100]; // предполагаем, что может быть до 100 операций
//     int capitalization, capitalized_periods, current_period = 0;
//     // ввод данных
//     printf("Введите сумму вклада: ");
//     scanf("%f", &deposit);
//     printf("Введите срок размещения в месяцах: ");
//     scanf("%d", &deposit_period);
//     printf("Введите процентную ставку: ");
//     scanf("%f", &interest_rate);
//     printf("Введите налоговую ставку: ");
//     scanf("%f", &tax_rate);
//     printf("Введите периодичность выплат процентов в месяцах: ");
//     scanf("%d", &payment_period);
//     printf("Введите капитализацию процентов (0 - нет капитализации, 1 - ежемесячно): ");
//     scanf("%d", &capitalization);
//     if (capitalization) {
//         capitalized_periods = deposit_period / payment_period;
//     }
//     // ввод списка пополнений
//     printf("Введите количество операций пополнения: ");
//     scanf("%d", &num_deposits);
//     printf("Введите сумму и месяц (начиная с месяца 1) для каждой операции пополнения:\n");
//     for (i = 0; i < num_deposits; i++) {
//         scanf("%d %f", &deposits[i], &deposit);
//     }
//     // ввод списка частичных снятий
//     printf("Введите количество операций снятия: ");
//     scanf("%d", &num_withdrawals);
//     printf("Введите сумму и месяц (начиная с месяца 1) для каждой операции снятия:\n");
//     for (i = 0; i < num_withdrawals; i++) {
//         scanf("%d %f", &withdrawals[i], &deposit);
//     }
//     // расчет процентов и налога
//     for (i = 1; i <= deposit_period; i++) {
//         if (capitalization && (i % payment_period == 0)) {
//             current_period++;
//             total_interest += deposit * interest_rate / 100;
//             deposit += deposit * interest_rate / 100;
//         } else {
//             total_interest += deposit * interest_rate / 100 / 12;
//             deposit += deposit * interest_rate / 100 / 12;
//         }
//         // пополнение вклада
//         for (j = 0; j < num_deposits; j++) {
//             if (deposits[j] == i) {
//                 deposit += deposit;
//                 break;
//             }
//         }
//         // частичное снятие вклада
//         for (j = 0; j < num_withdrawals; j++) {
//             if (withdrawals[j] == i) {
//                 deposit -= deposit;
//                 break;
//             }
//         }
//         // расчет налога
//         if (total_interest > 0) {
//             float current_tax = total_interest * tax_rate / 100;
//             total_tax += current_tax;
//             total_interest -= current_tax;
//         }
//     }
//     total_deposit = deposit;
//     // вывод результатов
//     printf("Начисленные проценты: %.2f\n", total_interest);
//     printf("Сумма налога: %.2f\n", total_tax);
//     printf("Сумма на вкладе к концу срока: %.2f\n", total_deposit);
//     return 0;
// }

void deposit_calculator(double sum, int time_contrib, int type_of_time, double percent, double tax_rate, int period, int capitalization, double *res_percent, double *tax_rate_res, double *sum_with_tax, double *sum_res) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int month = local->tm_mon;
    int time_copy = 0;
    if (type_of_time == 1) {
        time_copy = time_contrib;
    } else if (type_of_time == 3) {
        time_contrib *= 12;
    }
    if (type_of_time != 1) {
        for (int i = 0; i < time_contrib; i++) {
            if (month == 11) {
                month = 0;
            } else {
                month++;
            }
            time_copy += days[month];
        }
    }
    // if (period == 1) {

    // }
    if (capitalization) {
        *res_percent = (sum * percent * time_copy / 365) / 100;
        *tax_rate_res = *res_percent - 1000000 * (7.5 / 100);
        if (*tax_rate_res > 0) {
            *tax_rate_res *= tax_rate / 100;
        } else {
            *tax_rate_res = 0;
        }
        *sum_with_tax = *res_percent - *tax_rate_res;
        *sum_res = sum + *res_percent;
    } else {
        *sum_res = sum;
    }
}

int main() {
    double sum = 0.0;
    double tax_rate = 0.0;
    double res_perc = 0.0;
    double sum_with_tax = 0.0;
    deposit_calculator(1000000, 1, 3, 10, 13,  0, 1, &res_perc, &tax_rate, &sum_with_tax, &sum);
    printf("\nНачисленные проценты = %lf\n", res_perc);
    printf("Налог = %lf\n", tax_rate);
    printf("Доход за вычетом налогов = %lf\n", sum_with_tax);
    printf("Сумма на вкладе к концу срока = %lf\n\n", sum);
    return 0;
}