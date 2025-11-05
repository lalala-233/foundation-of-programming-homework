// 冰雹猜想
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t number;
    scanf("%d", &number);

    int32_t count = 0;
    for (; count <= 10 && number != 1; count++) {
        if (number % 2 == 0) {
            number /= 2;
        } else {
            number = number * 3 + 1;
        }
    }

    if (count > 10) {
        count = -1;
    }
    printf("%d", count);
    return 0;
}
