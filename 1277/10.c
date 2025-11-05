// 分数化小数
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t dividend, divisor, precision;
        scanf("%d %d %d", &dividend, &divisor, &precision);

        int32_t quotient = dividend / divisor;
        dividend -= divisor * quotient;
        dividend *= 10;

        printf("%d.", quotient);
        for (int32_t j = 0; j < precision; j++) {
            quotient = dividend / divisor;
            dividend -= divisor * quotient;
            dividend *= 10;
            printf("%d", quotient);
        }
        printf("\n");
    }
    return 0;
}
