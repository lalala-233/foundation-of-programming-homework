// 新斐波那契
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int64_t new_fibonacci_tool(
    int32_t number,
    int64_t result_sub_3,
    int64_t result_sub_2,
    int64_t result_sub_1
) {
    if (number == 1) {
        return result_sub_3;
    } else {
        return new_fibonacci_tool(
            number - 1,
            result_sub_2,
            result_sub_1,
            2 * result_sub_1 + 3 * result_sub_2 + 5 * result_sub_3
        );
    }
}

int64_t new_fibonacci(int32_t number) {
    return new_fibonacci_tool(number, 1, 1, 1);
}

int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t number;
        scanf("%d", &number);

        printf("%" PRId64 "\n", new_fibonacci(number));
    }
    return 0;
}
