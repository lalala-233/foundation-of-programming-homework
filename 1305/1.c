// 判断完全数
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t sum_of_factor(int32_t number) {
    int32_t sum = 0;
    int32_t root = sqrt(number);
    for (int32_t i = 1; i <= root; i++) {
        if (number % i == 0) {
            sum += i;
            if (number / i != i) {
                sum += number / i;
            }
        }
        if (sum > 2 * number) {
            return sum;
        }
    }
    return sum;
}
int32_t main(void) {
    int32_t number;
    scanf("%d", &number);
    int32_t result = (int32_t)(sum_of_factor(number) == 2 * number);
    printf("%d\n", result);
    return 0;
}
