#include "calculator.h"

int main() {
    double result = 0.0;
    result = polish_notation("(-3)+2*cos(0)-(-3)+2");
    printf("Result = %lf\n", result);
    return 0;
}
