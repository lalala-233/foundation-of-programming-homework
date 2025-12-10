// 移除数字
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t remove_number(int32_t number, int32_t remove, int32_t index) {
    int32_t new_number = 0;
    for (int32_t i = 1; number != 0;) {
        int32_t digit = number % 10;
        number /= 10;
        if (digit == remove) {
            index--;
            if (index == -1) {
                continue;
            }
        }
        new_number += digit * i;
        i *= 10;
    }

    if (index >= 0) {
        return -1;
    }
    return new_number;
}

int32_t main(void) {
    int32_t number;
    scanf("%" PRIi32, &number);
    int32_t remove;
    scanf("%" PRIi32, &remove);
    int32_t max = 0;
    for (int32_t i = 0;; i++) {
        int32_t new_number = remove_number(number, remove, i);
        max = max > new_number ? max : new_number;
        if (new_number == -1) {
            break;
        }
    }
    if (max == 0) {
        max = number;
    }

    printf("%" PRIi32 "\n", max);
    return 0;
}
