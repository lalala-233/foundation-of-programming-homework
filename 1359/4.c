// 宝藏密码条
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);

    for (int32_t i = 0;;) {
        char current = getchar();
        if (isalnum(current)) {
            if (i != 0 && i % number_of_one_line == 0) {
                putchar('-');
            }
            putchar(toupper(current));
            i++;
        } else if (current == '\n') {
            while (i % number_of_one_line != 0) {
                putchar('=');
                i++;
            }
            break;
        }
    }
    printf("\n");
    return 0;
}
