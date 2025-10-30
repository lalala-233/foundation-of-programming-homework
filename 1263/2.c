// 偶数分数加法
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

double calculate(double current, int32_t n) {
    return current + 1 / (double)n;
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t n;
        scanf("%d", &n);
        double result = 0;
        for (int32_t i = 2; i <= n; i += 2) {
            result = calculate(result, i);
        }
        printf("%.4f\n", result);
    }
    return 0;
}
