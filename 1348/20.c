// 方程
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
const int32_t MOD = 998244353;
int64_t fast_pow_mod(int64_t a, int64_t b) {
    int64_t result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}
int32_t main(void) {
    int32_t m;
    scanf("%" PRIi32, &m);

    int64_t* factorial_mod = malloc(sizeof(int64_t) * (m + 1));
    factorial_mod[0] = 1;
    for (int32_t i = 1; i <= m; i++) {
        factorial_mod[i] = (factorial_mod[i - 1] * i) % MOD;
    }

    int64_t* inverse_mod = malloc(sizeof(int64_t) * (m + 1));
    inverse_mod[m] = fast_pow_mod(factorial_mod[m], MOD - 2);
    for (int32_t i = m - 1; i >= 0; i--) {
        inverse_mod[i] = (inverse_mod[i + 1] * (i + 1)) % MOD;
    }
    for (int64_t i = 0; i <= m; i++) {
        int64_t combination_mod = (inverse_mod[i] * inverse_mod[m - i]) % MOD;
        combination_mod = (combination_mod * factorial_mod[m]) % MOD;
        printf("%" PRIi64, combination_mod);
        if (i != m) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    free(factorial_mod);
    free(inverse_mod);
    return 0;
}
