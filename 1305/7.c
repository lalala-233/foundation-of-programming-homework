// 分类排序
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t group(int32_t array[], int32_t n) {
    int even_count = 0;
    for (int32_t i = 0; i < n; i++) {
        int32_t number;
        scanf("%d", &number);
        if (number % 2 == 0) {
            array[n - 1 - even_count] = number;
            even_count++;
        } else {
            array[i - even_count] = number;
        }
    }
    return n - even_count;
}
int32_t compare(const void* left, const void* right) {
    return *(int32_t*)left - *(int32_t*)right;
}
int32_t main(void) {
    int32_t count;
    scanf("%d", &count);

    for (int32_t i = 0; i < count; i++) {
        int32_t n;
        scanf("%d", &n);
        int32_t array[n];
        int32_t even_start = group(array, n);
        qsort(array, even_start, sizeof(int32_t), compare);
        qsort(&array[even_start], n - even_start, sizeof(int32_t), compare);
        for (int32_t j = 0; j < n; j++) {
            printf("%d", array[j]);
            if (j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
