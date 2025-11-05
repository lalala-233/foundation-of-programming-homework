// 统计 7 进制数中的数字
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t number, check_number;
    scanf("%d %d", &number, &check_number);

    int32_t result = 0;
    while (number != 0) {
        if (number % 7 == check_number) {
            result++;
        }
        number /= 7;
    }

    printf("%d", result);
    return 0;
}
