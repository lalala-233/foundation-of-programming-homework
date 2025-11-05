// 输出菱形
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print_n_times(char character, int32_t times) {
    for (int32_t i = 0; i < times; i++) {
        printf("%c", character);
    }
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        if (number % 2 == 0) {
            printf("error\n");
            continue;
        } else {
            printf("print\n");
        }

        for (int j = 0; j < number; j++) {
            int whitespace_count;
            if (j < number / 2) {
                whitespace_count = number / 2 - j;
            } else {
                whitespace_count = j - number / 2;
            }

            print_n_times(' ', whitespace_count);
            print_n_times('*', number - 2 * whitespace_count);

            printf("\n");
        }
    }
    return 0;
}
