#include "s21_SmartCalc.h"

int main() {
    double result = 0.0;
    result = polish_notation("((2+(33-4))+cos(sin(tan(atan(acos(asin(sqrt(34^(92+32)))))))))-3-7+2mod3-10^2-cos(3)+atan(55)");
    // result = polish_notation("(1+(2+3+4))+4+5-3");
    printf("Result = %lf\n", result);
    return 0;
}
