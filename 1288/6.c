// 递归实现 n!
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int64_t factorial_tool(int32_t number, int64_t result) {
    if (number == 0) {
        return result;
    } else {
        return factorial_tool(number - 1, number * result);
    }
}

int64_t factorial(int32_t number) {
    return factorial_tool(number, 1);
}

int32_t main(void) {
    int32_t number;
    while (scanf("%d", &number) != EOF) {
        printf("%" PRId64 "\n", factorial(number));
    }
    return 0;
}
