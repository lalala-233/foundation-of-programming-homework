// 数的表示
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
void print_power_of_2(int32_t number, int32_t current_power) {
    if (number / 2 != 0) {
        print_power_of_2(number / 2, current_power + 1);
        if (number % 2 == 1) {
            printf("+");
        }
    }
    if (number % 2 == 1) {
        printf("2^%d", current_power);
    }
}
int32_t main(void) {
    int32_t number;
    scanf("%d", &number);
    printf("%d=", number);
    print_power_of_2(number, 0);
    printf("\n");
    return 0;
}
