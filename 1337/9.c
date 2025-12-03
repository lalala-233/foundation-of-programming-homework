// 矩阵的幂
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t* product(int32_t* matrix_a, const int32_t* matrix_b, int32_t n) {
    int32_t* result = calloc(n * n, sizeof(int32_t));
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < n; j++) {
            for (int32_t k = 0; k < n; k++) {
                result[i * n + j] += matrix_a[i * n + k] * matrix_b[k * n + j];
            }
        }
    }
    free(matrix_a);
    return result;
}
int32_t main(void) {
    int32_t n;
    scanf("%" PRIi32, &n);
    int32_t times;
    scanf("%" PRIi32, &times);
    times -= 1;
    int32_t* matrix = malloc(sizeof(int32_t) * n * n);
    int32_t* matrix_clone = malloc(sizeof(int32_t) * n * n);
    for (int32_t i = 0; i < n * n; i++) {
        scanf("%" PRIi32, &matrix[i]);
        matrix_clone[i] = matrix[i];
    }
    for (int32_t i = 0; i < times; i++) {
        matrix = product(matrix, matrix_clone, n);
    }
    for (int32_t i = 0; i < n * n; i++) {
        printf("%" PRIi32, matrix[i]);
        if ((i + 1) % n == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    free(matrix_clone);
    free(matrix);
}
