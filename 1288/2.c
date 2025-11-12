// 分解偶数
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_prime(int32_t number) {
    int32_t root = sqrt(number);
    for (int32_t i = 3; i <= root + 1; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int32_t main(void) {
    int32_t number;
    scanf("%d", &number);

    bool has_solution = false;
    for (int i = 3; i <= number / 2; i += 2) {
        if (is_prime(i) && is_prime(number - i)) {
            printf("%d %d\n", i, number - i);
            has_solution = true;
        }
    }

    if (!has_solution) {
        printf("ERROR\n");
    }
    return 0;
}
