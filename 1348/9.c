// 秘密
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t main(void) {
    int32_t number;
    scanf("%" PRIi32, &number);
    for (int32_t i = 0;; i++) {
        if (6 * i * i * i + 2 * i * i - i == number) {
            printf("%" PRIi32 "\n", i);
            break;
        }
    }
    return 0;
}
