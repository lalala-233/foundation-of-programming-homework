// 希望的田野
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int32_t sum_of(
    const int32_t* prefix_sum,
    int32_t i_1,
    int32_t j_1,
    int32_t i_2,
    int32_t j_2,
    int32_t number_of_one_line
) {
    int32_t i_min = i_1 < i_2 ? i_1 : i_2;
    int32_t i_max = i_1 > i_2 ? i_1 : i_2;
    int32_t j_min = j_1 < j_2 ? j_1 : j_2;
    int32_t j_max = j_1 > j_2 ? j_1 : j_2;
    int32_t index = i_max * number_of_one_line + j_max;
    int32_t sum = prefix_sum[index];
    if (j_min > 0) {
        index = i_max * number_of_one_line + (j_min - 1);
        sum -= prefix_sum[index];
    }
    if (i_min > 0) {
        index = (i_min - 1) * number_of_one_line + j_max;
        sum -= prefix_sum[index];
    }
    if (i_min > 0 && j_min > 0) {
        index = (i_min - 1) * number_of_one_line + (j_min - 1);
        sum += prefix_sum[index];
    }
    return sum;
}
int32_t main(void) {
    int32_t line;
    scanf("%" PRIi32, &line);
    int32_t number_of_one_line;
    scanf("%" PRIi32, &number_of_one_line);
    int32_t count;
    scanf("%" PRIi32, &count);
    int32_t* prefix_sum = malloc(sizeof(int32_t) * line * number_of_one_line);
    for (int32_t i = 0; i < line; i++) {
        for (int32_t j = 0; j < number_of_one_line; j++) {
            int32_t index = i * number_of_one_line + j;
            scanf("%" PRIi32, &prefix_sum[index]);
            if (i > 0) {
                prefix_sum[index] += prefix_sum[index - number_of_one_line];
            }
            if (j > 0) {
                prefix_sum[index] += prefix_sum[index - 1];
            }
            if (i > 0 && j > 0) {
                prefix_sum[index] -= prefix_sum[index - number_of_one_line - 1];
            }
        }
    }
    for (int32_t i = 0; i < count; i++) {
        int32_t i_1, j_1, i_2, j_2;
        scanf("%" PRIi32, &i_1);
        scanf("%" PRIi32, &j_1);
        scanf("%" PRIi32, &i_2);
        scanf("%" PRIi32, &j_2);
        i_1 -= 1;
        j_1 -= 1;
        i_2 -= 1;
        j_2 -= 1;
        printf("%" PRIi32 "\n", sum_of(prefix_sum, i_1, j_1, i_2, j_2, number_of_one_line));
    }
    return 0;
}
