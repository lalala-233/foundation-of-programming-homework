// 交换四位数的百位和个位
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int32_t number;
    scanf("%d", &number);

    if (number < 1000 || number > 9999) {
        printf("illegal\n");
        return 0;
    }
    int32_t hundreds_digit = (number / 100) % 10;
    int32_t thousands_digit = (number / 1000) % 10;
    int32_t tens_digit = (number / 10) % 10;
    int32_t ones_digit = number % 10;

    printf("%d%d%d%d\n", thousands_digit, ones_digit, tens_digit, hundreds_digit);
    return 0;
}