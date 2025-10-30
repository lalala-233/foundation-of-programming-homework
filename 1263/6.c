// 任意整数的各位数字之和
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t n;
    scanf("%d", &n);
    n = n > 0 ? n : -n;

    int32_t result = 0;
    for (int64_t i = 1; i <= n; i *= 10) {
        result += (n / i) % 10;
    }
    printf("%d\n", result);
    return 0;
}
