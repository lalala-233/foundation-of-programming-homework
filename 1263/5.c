// 二进制包含几个 1
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t n;
        scanf("%d", &n);

        int32_t result = 0;
        for (int32_t i = 1; i <= n; i *= 2) {
            result += (int32_t)((n & i) == i);
        }
        printf("%d\n", result);
    }
    return 0;
}
