// 整数分数的加法
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

double calculate(double current, int32_t n) {
    return current + (double)n / (double)(n + 1);
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t n;
        scanf("%d", &n);

        double result = 0;
        for (int32_t i = 1; i <= n; i++) {
            result = calculate(result, i);
        }
        printf("%.4f\n", result);
    }
    return 0;
}
