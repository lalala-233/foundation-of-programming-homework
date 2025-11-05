// 解不等式
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t number;
    scanf("%d", &number);

    int32_t result = 1;
    for (uint32_t current_sum = 0;;) {
        current_sum += result * result;
        if (current_sum >= number) {
            break;
        } else {
            result++;
        }
    }
    result -= 1;
    printf("%d", result);
    return 0;
}
