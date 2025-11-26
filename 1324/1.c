// 回文数
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        int32_t len = strlen("2147483647");
        int32_t digits[len];
        int32_t digit_count = 0;
        while (number > 0) {
            digits[digit_count] = number % 10;
            number /= 10;
            digit_count++;
        }
        bool is_palindromes = true;
        for (int32_t j = 0; j < digit_count; j++) {
            is_palindromes = is_palindromes && (digits[j] == digits[digit_count - 1 - j]);
        }
        if (is_palindromes) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
