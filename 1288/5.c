// 交换十进制整数的相邻奇偶位
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print(int32_t number, bool is_digits_even) {
    int32_t digit = number % 10;
    number /= 10;

    int32_t even_digit;
    if (is_digits_even) {
        even_digit = number % 10;
        number /= 10;
    }

    if (number != 0) {
        print(number, true);
    }
    if (number != 0 || digit != 0) {
        printf("%d", digit);
    }
    if (is_digits_even) {
        printf("%d", even_digit);
    }
}

int32_t get_digits(int32_t number) {
    int32_t digits = 0;
    while (number != 0) {
        number /= 10;
        digits++;
    }
    return digits;
}
int32_t main(void) {
    int32_t number;
    scanf("%d", &number);
    if (number < 0) {
        printf("-");
    }
    number = number < 0 ? -number : number;

    print(number, get_digits(number) % 2 == 0);
    printf("\n");
    return 0;
}
