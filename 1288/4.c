// 乘法表
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void print(int32_t number) {
    if (number == 0) {
        return;
    }
    print(number - 1);
    bool should_print_whitespace = false;
    for (int32_t i = 1; i <= number; i++) {
        if (should_print_whitespace) {
            printf(" ");
        }
        should_print_whitespace = true;

        printf("%d*%d=%d", number, i, number * i);
    }
    printf("\n");
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        print(number);
    }
    return 0;
}
