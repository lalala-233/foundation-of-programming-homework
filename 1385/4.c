// 波浪数
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN (32 + 1)
bool is_wave_number(const char* s) {
    for (int32_t i = 0, len = strlen(s); i < len; i++) {
        if (i >= 2 && s[i] != s[i - 2] || s[i] == s[i - 1]) {
            return false;
        }
    }
    return true;
}
char* to_base(int32_t number, int32_t base) {
    char* s = malloc(sizeof(char) * LEN);
    int32_t len = 0;
    while (number != 0) {
        s[len] = number % base + '0'; // We don't care '9' + 1
        number /= base;
        len++;
    }
    s[len] = '\0';
    return s;
}
int32_t main(void) {
    int32_t min_base;
    scanf("%" PRIi32, &min_base);
    int32_t max_base;
    scanf("%" PRIi32, &max_base);
    int32_t min_number;
    scanf("%" PRIi32, &min_number);
    int32_t max_number;
    scanf("%" PRIi32, &max_number);

    bool find_solution = false;
    for (int32_t number = min_number; number <= max_number; number++) {
        int32_t wave_count = 0;
        for (int32_t base = min_base; base <= max_base; base++) {
            char* s = to_base(number, base);
            if (is_wave_number(s)) {
                wave_count++;
            }
            free(s);
            if (wave_count == 2) {
                find_solution = true;
                printf("%" PRIi32 "\n", number);
                break;
            }
        }
    }
    if (!find_solution) {
        printf("NULL\n");
    }
    return 0;
}
