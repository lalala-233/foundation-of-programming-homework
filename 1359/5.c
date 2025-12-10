// 分割平衡字符串
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t difference = 0;
    int32_t count = 0;
    while (true) {
        char current = getchar();
        if (current == '\n') {
            break;
        } else if (current == 'L') {
            difference -= 1;
        } else {
            difference += 1;
        }
        if (difference == 0) {
            count++;
        }
    }
    printf("%" PRIi32 "\n", count);
    return 0;
}
