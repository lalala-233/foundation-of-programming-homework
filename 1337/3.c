// 将 7 进制数转为 2 进制数输出
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int32_t convert_to_decimal(int32_t number) {
    int32_t number_in_decimal = 0;
    for (int32_t i = 1; number != 0; i *= 7, number /= 10) {
        int32_t digit = number % 10;
        if (digit >= 7) {
            return -1;
        }
        number_in_decimal += digit * i;
    }
    return number_in_decimal;
}
void print_as_binary(int32_t number) {
    if (number > 1) {
        print_as_binary(number / 2);
    }
    int32_t digits = number % 2;
    printf("%" PRIi32, digits);
    return;
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%" PRIi32, &number);
        int32_t number_in_decimal = convert_to_decimal(number);
        if (number_in_decimal == -1) {
            printf("ERROR\n");
            continue;
        }
        print_as_binary(number_in_decimal);
        printf("\n");
    }
    return 0;
}
