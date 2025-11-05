// n 的阶乘末尾有几个零
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        int32_t result = 0;
        while (number != 0) {
            number /= 5;
            result += number;
        }
        printf("%d\n", result);
    }
    return 0;
}
