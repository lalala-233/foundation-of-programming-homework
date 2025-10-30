// 分数的前 n 项值
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

double calculate(double current, int32_t n) {
    return current + (n % 2 == 0 ? -1 : 1) * (double)n / (double)(2 + (double)(n * (n + 1)) / 2);
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
