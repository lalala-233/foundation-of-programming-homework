// 换位置
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t merge_count(int32_t* array, int32_t len) {
    if (len == 1) {
        return 0;
    }
    int32_t middle = len / 2;
    int32_t* left = array;
    int32_t left_len = middle;
    int32_t* right = &array[middle];
    int32_t right_len = len - middle;

    int32_t* sorted_array = malloc(sizeof(int32_t) * len);
    int32_t count = 0;
    for (int32_t i = 0, j = 0; i != left_len || j != right_len;) {
        if (i < left_len && j < right_len) {
            if (left[i] <= right[j]) {
                sorted_array[i + j] = left[i];
                i++;
            } else {
                sorted_array[i + j] = right[j];
                count += left_len - i;
                j++;
            }
        } else if (i < left_len) {
            sorted_array[i + j] = left[i];
            i++;
        } else if (j < right_len) {
            sorted_array[i + j] = right[j];
            j++;
        }
    }
    for (int32_t i = 0; i < len; i++) {
        array[i] = sorted_array[i];
    }
    free(sorted_array);
    return count;
}
void merge_sort_count(int32_t* array, int32_t len, int32_t* count) {
    if (len <= 1) {
        return;
    }
    int32_t middle = len / 2;
    int32_t* left = array;
    int32_t left_len = middle;
    int32_t* right = &array[middle];
    int32_t right_len = len - middle;

    merge_sort_count(left, left_len, count);
    merge_sort_count(right, right_len, count);

    *count += merge_count(array, len);
}
int32_t main(void) {
    int32_t count;
    scanf("%" PRIi32, &count);
    int32_t* array = malloc(sizeof(int32_t) * count);
    for (int32_t i = 0; i < count; i++) {
        scanf("%" PRIi32, &array[i]);
    }

    int32_t swap_count = 0;
    // for (int32_t i = 0; i < count; i++) {
    //     for (int32_t j = i + 1; j < count; j++) {
    //         if (array[j] < array[i]) {
    //             swap_count++;
    //         }
    //     }
    // }
    // printf("%" PRIi32 "\n", swap_count);
    // swap_count = 0;
    merge_sort_count(array, count, &swap_count);
    printf("%" PRIi32 "\n", swap_count);
    free(array);
    return 0;
}
