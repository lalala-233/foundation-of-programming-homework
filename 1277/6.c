// 计算级数和
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

double term(int32_t nth) {
    double result = 0;
    for (int32_t i = 1; i <= nth; i++) {
        result += 1 / (double)i;
    }
    if (nth % 2 == 0) {
        result = -result;
    }
    return result * 1 / (double)nth;
}

int32_t main(void) {
    int32_t number;
    scanf("%d", &number);

    double sum = 0;
    for (int i = 1; i <= number; i++) {
        sum += term(i);
    }

    printf("%.4f\n", sum);
    return 0;
}
