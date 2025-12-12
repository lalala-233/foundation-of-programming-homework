// 队列
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#define OFFSET 10000
#define LEN (OFFSET * 2 + 1)
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    int32_t array[LEN] = {0};
    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%" PRIi32, &number);
        array[number + OFFSET] += 1;
    }
    bool have_print = false;
    for (int32_t i = 0; i < LEN; i++) {
        while (array[i] != 0) {
            if (have_print) {
                putchar(' ');
            }
            printf("%" PRIi32, i - OFFSET);
            have_print = true;
            array[i] -= 1;
        }
    }
    putchar('\n');
    return 0;
}
