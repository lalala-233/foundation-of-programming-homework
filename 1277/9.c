// 最大公约数
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int32_t number_1, number_2;
        scanf("%d %d", &number_1, &number_2);

        if (number_1 <= number_2) {
            int32_t temp = number_2;
            number_2 = number_1;
            number_1 = temp;
        }

        int32_t remainder = number_2;
        while (remainder != 0) {
            remainder = number_1 % number_2;

            number_1 = number_2;
            number_2 = remainder;
        }

        printf("%d\n", number_1);
    }
    return 0;
}
