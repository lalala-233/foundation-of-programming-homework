// 打印柱状图
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    if (count < 1 || count > 10) {
        printf("Input Error\n");
        return 0;
    }
    int32_t* array = malloc(sizeof(int32_t) * count);
    int32_t max = 0;
    for (int32_t i = 0; i < count; i++) {
        scanf("%" PRIi32, &array[i]);
        if (array[i] < 0 || array[i] > 10) {
            printf("Input Error\n");
            return 0;
        }
        max = array[i] > max ? array[i] : max;
    }
    for (; max > 0; max--) {
        for (int32_t i = 0; i < count; i++) {
            if (array[i] >= max) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    free(array);
    return 0;
}
