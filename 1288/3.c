// 分解质因数
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t find_factor(int32_t number) {
    int32_t root = sqrt(number);
    if (number % 2 == 0) {
        return 2;
    }
    for (int32_t i = 3; i <= root + 1; i += 2) {
        if (number % i == 0) {
            return i;
        }
    }
    return number;
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        if (number == 1) {
            printf("%d", number);
        }

        bool has_solution = false;
        while (number != 1) {
            if (has_solution) {
                printf("*");
            }
            int32_t factor = find_factor(number);
            number /= factor;
            has_solution = true;
            printf("%d", factor);
        }
        printf("\n");
    }
    return 0;
}
