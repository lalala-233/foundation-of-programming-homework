// 数组的距离
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void find_min_max(int32_t* min, int32_t* max) {
    *min = INT32_MAX;
    *max = INT32_MIN;
    int32_t count;
    scanf("%d", &count);

    int32_t number;
    for (int i = 0; i < count; i++) {
        scanf("%d", &number);
        *max = number > *max ? number : *max;
        *min = number < *min ? number : *min;
    }
}

int32_t main(void) {
    int a_min, a_max, b_min, b_max;
    find_min_max(&a_min, &a_max);
    find_min_max(&b_min, &b_max);
    int32_t result = b_max - a_min;
    result = a_max - b_min > result ? a_max - b_min : result;
    printf("%d\n", result);
    return 0;
}
