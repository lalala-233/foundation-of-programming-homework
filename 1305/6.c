// 将数组中的 0 移到末尾
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print_zero(int32_t zero_count) {
    for (int32_t i = 0; i < zero_count; i++) {
        printf("%d", 0);
        if (i != zero_count - 1) {
            printf(" ");
        }
    }
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t n;
        scanf("%d", &n);
        int32_t zero_count = 0;

        for (int32_t j = 0; j < n; j++) {
            int32_t number;
            scanf("%d", &number);
            if (number == 0) {
                zero_count++;
                continue;
            }
            printf("%d", number);
            if (zero_count != 0 || j < n - 1) {
                printf(" ");
            }
        }
        print_zero(zero_count);
        printf("\n");
    }
    return 0;
}
