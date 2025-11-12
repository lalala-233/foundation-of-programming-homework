// 阶乘求和
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
const int32_t MOD = 1000000;

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        number = number > 30 ? 30 : number;
        int32_t factorial_mod = 1;
        int32_t factorial_sum_mod = 0;

        for (int i = 1; i <= number; i++) {
            factorial_mod = factorial_mod * i % MOD;
            factorial_sum_mod += factorial_mod;
            factorial_sum_mod %= MOD;
        }
        printf("%d\n", factorial_sum_mod);
    }
    return 0;
}
