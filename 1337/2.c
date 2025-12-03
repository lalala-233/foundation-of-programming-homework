// 合并有序数组
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t main(void) {
    int32_t m, n;
    scanf("%" PRIi32 " %" PRIi32, &m, &n);
    int32_t* array_1 = malloc(sizeof(int32_t) * m);
    int32_t* array_2 = malloc(sizeof(int32_t) * n);
    for (int32_t i = 0; i < m; i++) {
        scanf("%" PRIi32, &array_1[i]);
    }
    for (int32_t i = 0; i < n; i++) {
        scanf("%" PRIi32, &array_2[i]);
    }
    for (int32_t i = 0, j = 0; i != m || j != n;) {
        int32_t less;
        if (i == m) {
            less = array_2[j];
            j++;
        } else if (j == n) {
            less = array_1[i];
            i++;
        } else {
            if (array_1[i] < array_2[j]) {
                less = array_1[i];
                i++;
            } else {
                less = array_2[j];
                j++;
            }
        }
        printf("%" PRIi32, less);
        if (i + j == m + n) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    free(array_1);
    free(array_2);
    return 0;
}
