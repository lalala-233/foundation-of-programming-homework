// 链表排序
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t cmp(const void* left, const void* right) {
    return *(int32_t*)left - *(int32_t*)right;
}
int32_t main(void) {
    int32_t number;
    scanf("%" PRIi32, &number);

    int32_t* array = malloc(sizeof(int32_t) * number);

    for (int32_t i = 0; i < number; i++) {
        scanf("%" PRIi32, &array[i]);
    }
    qsort(array, number, sizeof(int32_t), cmp);

    scanf("%" PRIi32, &number);
    printf("%" PRIi32 "\n", array[number - 1]);

    free(array);
    return 0;
}
