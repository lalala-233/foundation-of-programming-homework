// 一元一次方程
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
void process() {
    char variable_name;
    char current = getchar();
    double divisor = 0.0;
    int32_t temp_number = 0;
    int32_t divident = 0;
    bool is_positive = true;
    bool before_equal = true;
    while (true) {
        if (isdigit(current)) {
            temp_number *= 10;
            temp_number += current - '0';
        } else if (isalpha(current)) {
            if (temp_number == 0) {
                temp_number = 1;
            }
            if ((before_equal && !is_positive) || (!before_equal && is_positive)) {
                temp_number = -temp_number;
            }
            divisor += temp_number;
            variable_name = current;
            temp_number = 0;
        } else {
            if ((before_equal && is_positive) || (!before_equal && !is_positive)) {
                temp_number = -temp_number;
            }
            divident += temp_number;
            temp_number = 0;
        }

        if (current == '-') {
            is_positive = false;
        } else if (current == '+') {
            is_positive = true;
        } else if (current == '=') {
            before_equal = false;
            is_positive = true;
        } else if (current == '\n') {
            break;
        }
        current = getchar();
    }
    if (divisor == 0.0) {
        divisor = 1.0;
    }
    printf("%c=%.6f\n", variable_name, divident / divisor);
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    char _new_line = getchar();
    for (int32_t i = 0; i < count; i++) {
        process();
    }
    return 0;
}
